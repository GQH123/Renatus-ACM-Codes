#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define ll long long int 
#define pb push_back
#define pc putchar
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn 600020
#define maxm
#define maxs
#define maxb
#define M 
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++) 
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}
int _num[20];
template <class T> void write(T x, char sep = '\n'){	
	if (!x) {putchar('0'), putchar(sep); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar(sep);
}

int n, m, deg[maxn];
vector<int> g[maxn];
void Add_Edge(int x, int y){
	g[x].pb(y), g[y].pb(x), deg[x]++, deg[y]++;
} 

namespace Build_Frame{
	#define inf 2000000020 
	int d1[maxn], d2[maxn], bfs[maxn], head = 0, tail = 0;  
	void BFS(int s, int* d){
		head = tail = 0;
		rep(i, 1, n) d[i] = inf;
		bfs[++head] = s, d[s] = 0;
		while (head != tail){
			int x = bfs[++tail];
			srep(i, 0, deg[x]) {
				int op = g[x][i];
				if (d[op] == inf) {
					d[op] = d[x] + 1;
					bfs[++head] = op;
				}
			}
		}
	} 
	struct ele{
		int x, y, z;
		ele(int x, int y, int z) : x(x), y(y), z(z){}
		ele(){}
		bool operator < (const ele b) const{
			return x == b.x ? y == b.y ? z < b.z : y < b.y : x < b.x;
		}
	}ans[maxn]; int cs = 0;
	int idx[maxn], p[maxn], num[maxn], tim = 0;
	bool extend(){
		head = tail = 0;
		rep(i, 1, n) if (idx[i]) bfs[++head] = i;  
		while (head != tail){
			int x = bfs[++tail];
			bool f = 0, f2 = 0;
			srep(i, 0, deg[x]) {
				int op = g[x][i];
				if (!idx[op]) {
					if (f) return false; f = 1;
					idx[op] = idx[x] + 1; p[op] = p[x];
					bfs[++head] = op;
				}
				else {
					if (idx[op] > idx[x]) return false;
					if (idx[op] < idx[x]) {
						if (idx[op] != idx[x] - 1) return false;
						else {
							if (f2) return false; f2 = 1;
						}
					}
				}
			}
		}
		return true;
	} 
	set<int> lisp[maxn];
	bool cmp_s(set<int>& a, set<int>& b){
		if (a.size() != b.size()) return false; 
		for (set<int> :: iterator it = a.begin(), it2 = b.begin(); it != a.end(); it++, it2++){
			if (*it != *it2) return false;
		}
		return true;
	}
	set<int> sop;
	extern void recover(); 
	int play(int x, int y, bool cal_ans = 0) {
		recover(); 
		BFS(x, d1), BFS(y, d2);  
		rep(i, 1, n) {
			if (d1[i] < d2[i]) idx[i] = 1, p[i] = ++tim;
		}
		if (!extend()) return -1; 
		rep(i, 1, n) if (!idx[i]) return -1;
		int mx = -1;
		rep(i, 1, n) mx = max(mx, idx[i]);
		rep(i, 1, mx) num[i] = 0;
		rep(i, 1, n) num[idx[i]]++; 
		rep(i, 1, mx) if (num[i] != num[1]) return -1; 
		rep(i, 1, tim) lisp[i].clear();
		rep(i, 1, n) {
			if (idx[i] == 1) {
				srep(j, 0, deg[i]) {
					int op = g[i][j];
					if (idx[op] == 1) lisp[p[i]].insert(p[op]); 
				}
			}
		}
		rep(i, 1, n) {
			int id = idx[i];
			sop.clear();
			srep(j, 0, deg[i]) {
				int op = g[i][j];
				if (idx[op] == id) {
					sop.insert(p[op]);
				}
			}
			if (!cmp_s(lisp[p[i]], sop)) return -1;
		} 
		if (cal_ans) {
			rep(i, 1, n) ans[++cs] = ele(idx[i], p[i], i);
			sort(ans + 1, ans + 1 + cs);
		}
		return mx;
	}
	void recover(){ 
		tim = cs = 0; rep(i, 1, n) idx[i] = p[i] = 0;
	} 
}

int main(){ 
	int x, y;
	read(n), read(m);
	rep(i, 1, m) read(x), read(y), Add_Edge(x, y); 
	int mideg = m + 1, S = 0;
	rep(i, 1, n) if (deg[i] < mideg) mideg = deg[i], S = i; 
	int mx = 1, mxu = -1;
	srep(i, 0, deg[S]) {
		int y = g[S][i], d = Build_Frame :: play(S, y);  
		if (d > mx) mx = d, mxu = y;
	}
	if (mx > 1) {
		int s = n / mx;
		write(mx, ' '), write(s);
		Build_Frame :: play(S, mxu, 1); 
		if (Build_Frame :: cs != n) assert(false);
		int cnt = 0;
		rep(i, 1, n) {
			if (cnt == s) cnt = 0, puts("");
			write(Build_Frame :: ans[i].z, ' '); cnt++; 
		}
	}
	else {
		write(1, ' '), write(n);
		printf("%d", 1); rep(i, 2, n) printf(" %d", i);
	}
	return 0;
}


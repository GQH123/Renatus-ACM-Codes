#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define pii pair<int, int>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define ll long long int 
#define pb push_back
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn 200020
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
template <class T> void write(T x){	
	if (!x) {putchar('0'), putchar('\n'); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar('\n');
}

int n, m, k;
struct edge{
	int next, to;
	edge(int next, int to) : next(next), to(to){}
	edge(){}
}e[maxn << 1];
int cnt = 1, h[maxn], in[maxn], out[maxn];
void Add_Edge(int x, int y){
	e[++cnt] = edge(h[x], y);
	h[x] = cnt;
	in[y]++, out[x]++;
} 

int d[maxn];
int DP(int x){
	if (!out[x]) return d[x] = 1;
	if (d[x]) return d[x];
	erep(i, x){
		int op = e[i].to;
		d[x] = DP(op) + 1;
	}
	return d[x];
}

struct ele{
	int d, id;
	ele(int d, int id) : d(d), id(id){}
	ele(){}
	bool operator < (const ele b) const{
		return d < b.d;
	}
};
priority_queue<ele> pq;

int tmp[maxn], ct = 0;

void recover(){	
	rep(i, 1, n) h[i] = in[i] = out[i] = d[i] = 0;
	cnt = 1;
}

int main(){
	
		freopen("C.in", "r", stdin);
	int T, x, y;
	read(T);
	while (T--){
		read(n), read(m), read(k);
		rep(i, 1, m) read(x), read(y), Add_Edge(x, y);
		rep(i, 1, n) DP(i);
		rep(i, 1, n) if (!in[i]) pq.push(ele(d[i], i));
		int ans = 0;
		while (!pq.empty()){
			ans++;
			rep(i, 1, k){ 
				if (pq.empty()) break;
				ele op = pq.top(); pq.pop();
				x = op.id;
				erep(j, x){
					y = e[j].to;
					in[y]--;
					if (!in[y]) tmp[++ct] = y;
				}
			}
			rep(i, 1, ct) pq.push(ele(d[tmp[i]], tmp[i]));
			ct = 0;
		} 
		printf("%d\n", ans);
		recover();
	}
	//ios :: sync_with_stdio(false), cin.tie(0);
		
	return 0;
}


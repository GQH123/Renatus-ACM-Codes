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
#define maxn 2020
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

int n, a[maxn];
int num[maxn];
bool vis[maxn];
int ans[maxn], cs = 0; 

set<int> pos[maxn];


void update(int idx, int& mex){ 
	ans[++cs] = idx;
	pos[a[idx]].erase(idx);
	num[a[idx]]--;
	a[idx] = mex;
	num[a[idx]]++; 
	pos[a[idx]].insert(idx);
	rep(i, 0, n) if (!num[i]) {mex = i; break;}
}


int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		scanf("%d", &n);
		rep(i, 0, n) pos[i].clear(), vis[i] = num[i] = 0; cs = 0;  
		rep(i, 1, n) scanf("%d", &a[i]), pos[a[i]].insert(i), num[a[i]]++;
		int mex = 0;
		rep(i, 0, n) if (!num[i]) {mex = i; break;}
		rep(i, 1, n){
			if (vis[a[i]]) update(i, mex);
			else vis[a[i]] = 1;
		}
		rep(i, 1, n){
			bool ok = 1;
			srep(j, 1, n) if (a[j] > a[j + 1]) {ok = 0; break;}
			if (ok) break;
			if (a[i] == i - 1) continue;
			if (!pos[i - 1].empty()){
				for (set<int> :: iterator it = pos[i - 1].begin(); it != pos[i - 1].end();){
					int x = *it; it++; 
					update(x, mex);
				}
			} 
			assert(mex == i - 1);
			update(i, mex);
		}
		printf("%d\n", cs);
		rep(i, 1, cs) printf("%d ", ans[i]); printf("\n"); 
	} 
	return 0;
}


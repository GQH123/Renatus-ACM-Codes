#include <bits/stdc++.h>
#define maxr 100000
#define ll long long int 
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define ms(a, b) memset(a, b, sizeof(a))
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}

int n;
struct edge{
	int next, to, len;
	edge(int next, int to, int len) : next(next), to(to), len(len){}
	edge(){}
}e[maxn << 1];
int cnt = 1, h[maxn];
void Add_Edge(int x, int y, int z){
	e[++cnt] = edge(h[x], y, z);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x, z);
	h[y] = cnt;
}

int d[maxn], fa[maxn];
void DFS(int x){
	erep(i, x){
		int op = e[i].to;
		if (op == fa[x]) continue;
		fa[op] = x;
		d[op] = d[x] + e[i].len;
		DFS(op, x);
	}
}
int DP(int x, int fa){	
	int dp = 0;
	erep(i, x){
		int op = e[i].to;
		if (op == fa[x] || vis[op]) continue;
		fa[op] = x;
		dp = max(dp, DP(op, x) + e[i].len);
	}
	return dp;
}
int lis[maxn], cs = 0, far[maxn];
int main(){
	int inf = 1000000000;
	#ifndef ONLINE_JUDGE
		freopen("K.in", "r", stdin);
	#endif
	int T;
	read(T);
	while (T--){
		read(n);
		srep(i, 1, n) read(x), read(y), read(z), Add_Edge(x, y, z);
		DFS(1, 1);
		int mxd = 0, mxp = -1;
		rep(i, 1, n) if (d[i] > mxd) mxd = d[i], mxp = i; 
		ms(d, 0);
		int root = mxp;
		DFS(mxp, mxp);
		mxd = 0, mxp = -1;
		rep(i, 1, n) if (d[i] > mxd) mxd = d[i], mxp = i;
		int now = mxp;
		while (now != root) vis[now] = 1, lis[++cs] = now, now = fa[now];
		vis[now] = 1, lis[++cs] = now;
		int tot = mxd;
		ms(d, 0);
		rep(i, 1, cs) far[i] = DP(lis[i], lis[i]);
		int ans1 = inf, ans2 = inf;
		rep(i, 1, cs - 1){
			
		}//i, i + 1, ????????????
	}
	return 0;
}

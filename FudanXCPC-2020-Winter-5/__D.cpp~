#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define maxn 200020
#define tm TM
using namespace std;

int n, k;
struct edge{
	int next, to;
	edge(int next, int to) : next(next), to(to){}
	edge(){}
}e[maxn << 1];
int cnt = 1, h[maxn];
void Add_Edge(int x, int y){
	e[++cnt] = edge(h[x], y);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x);
	h[y] = cnt;
}
int fa[maxn], d[maxn], mxd[maxn], son[maxn], top[maxn], dfs[maxn], idfs[maxn];
int tm = 0;
void DFS(int x){
	mxd[x] = d[x];
	erep(i, x){
		int op = e[i].to;
		if (op == fa[x]) continue;
		d[op] = d[x] + 1;
		DFS(op);
		if (mxd[op] > mxd[son[x]]) son[x] = op;
		mxd[x] = max(mxd[x], mxd[op]);
	}
}
int lis[maxn];
int cs = 0;
void DFS(int x, int tp){
	dfs[x] = ++tm;
	idfs[tm] = x;
	top[x] = tp;
	bool f = 1;
	if (son[x]) f = 0, DFS(son[x], tp);
	erep(i, x){
		int op = e[i].to;
		if (op == fa[x] || op == son[x]) continue;
		f = 0;
		DFS(op, op);
	}
	if (f) lis[++cs] = dfs[x] - dfs[top[x]] + 1;
}

int main(){
	freopen("D.in", "r", stdin);
	scanf("%d%d", &n, &k);
	rep(i, 2, n) scanf("%d", &fa[i]), Add_Edge(i, fa[i]);
	DFS(1), DFS(1, 1);
	sort(lis + 1, lis + 1 + cs);
	int ans = 0;
	per(i, cs, 1){
		if (!k) break;
		ans += lis[i];
		k--;
	}
	printf("%d", ans);
	return 0;
}

#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
#define maxr 100000
#define maxn 20020
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

int n, q;
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
int fa[maxn], dfs[maxn], idfs[maxn], son[maxn], siz[maxn], d[maxn], top[maxn];
int t = 0;
void DFS(int x){
	siz[x] = 1, son[x] = 0;
	erep(i, x) {
		int op = e[i].to;
		if (op == fa[x]) continue;
		d[op] = d[x] + 1, fa[op] = x;
		DFS(op);
		siz[x] += siz[op];
		if (siz[op] > siz[son[x]]) son[x] = op;
	}
}
void DFS2(int x, int tp){
	top[x] = tp;
	dfs[x] = ++t, idfs[t] = x;
	if (son[x]) DFS2(son[x], tp);
	erep(i, x){
		int op = e[i].to;
		if (op == fa[x] || op == son[x]) continue;
		DFS2(op, op);
	}
}


int tag[maxn << 2], sum[maxn << 2];
int qx, qy, qd;
inline void pu(int o){
	sum[o] = sum[o << 1] + sum[o << 1 | 1];
}
inline void pd(int l, int r, int o){
	if (tag[o] != -1 && l != r){
		tag[o << 1 | 1] = tag[o << 1] = tag[o], tag[o] = -1;
		int mid = ((r - l) >> 1) + l;
		sum[o << 1] = (mid + 1 - l) * tag[o << 1];
		sum[o << 1 | 1] = (r - mid) * tag[o << 1 | 1];
	}
}
void Tag(int l, int r, int o){
	pd(l, r, o);
	if (qx <= l && r <= qy){
		tag[o] = qd, sum[o] = qd * (r - l + 1);
		return;
	}
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) Tag(l, mid, o << 1);
	if (qy > mid) Tag(mid + 1, r, o << 1 | 1);
	pu(o);
}
void init(int l, int r, int o){
	tag[o] = -1, sum[o] = 0;
	if (l == r) return;
	int mid = ((r - l) >> 1) + l;
	init(l, mid, o << 1);
	init(mid + 1, r, o << 1 | 1);
}
void init(){
	DFS(1), DFS2(1, 1), init(1, n, 1);
}
pii lis[maxn];
int cs = 0;
void operate(int x, int y){
	cs = 0;
	int f1 = top[x], f2 = top[y];
	while (f1 != f2){
		if (d[f1] > d[f2]){
			lis[++cs] = pii(dfs[f1], dfs[x]);
			x = fa[f1], f1 = top[x];
		}
		else {
			lis[++cs] = pii(dfs[f2], dfs[y]);
			y = fa[f2], f2 = top[y];
		}
	}
	lis[++cs] = pii(min(dfs[x], dfs[y]), max(dfs[x], dfs[y]));
	sort(lis + 1, lis + 1 + cs);
	lis[0] = pii(0, 0);
	lis[cs + 1] = pii(n + 1, n + 1);
	rep(i, 1, cs + 1){
		qx = lis[i - 1].se + 1, qy = lis[i].fi - 1, qd = 0;
		if (qx <= qy) Tag(1, n, 1);
	}
}
void restart(){
	qx = 1, qy = n, qd = 1;
	Tag(1, n, 1);
}
void recover(){
	rep(i, 1, n) h[i] = 0;
	cnt = 1, t = 0;
}

int main(){
	
		#ifndef ONLINE_JUDGE
			freopen("F.in", "r", stdin);
		#endif
	
	int T, x, y, k;
	scanf("%d", &T);
	rep(TT, 1, T){
		printf("Case %d:\n", TT);
		recover();
		scanf("%d", &n);
		srep(i, 1, n){
			scanf("%d%d", &x, &y);
			Add_Edge(x, y);
		}
		init();
		scanf("%d", &q);
		rep(i, 1, q){
			restart();
			scanf("%d", &k);
			rep(j, 1, k){
				scanf("%d%d", &x, &y);
				operate(x, y);
			}
			printf("%d\n", sum[1]);
		}
	}
	return 0;
}

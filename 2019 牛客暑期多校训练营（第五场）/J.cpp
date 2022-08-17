#include <bits/stdc++.h>
#define maxr 100000
#define maxn 300015
#define maxb 20
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
#define lowbit(x) (x & -x)
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
//#define DEBUG
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) +  fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') ch = gc(), f = 0;
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}

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

int fa[maxn][maxb];
int d1[maxn], d2[maxn], d3[maxn], m1[maxn], m2[maxn], m3[maxn];
void update(int x, int op){
	if (d1[op] + 1 >= d1[x]) 
		d3[x] = d2[x], m3[x] = m2[x], d2[x] = d1[x], m2[x] = m1[x], d1[x] = d1[op] + 1, m1[x] = m1[op];
	else if (d1[op] + 1 >= d2[x]) 
		d3[x] = d2[x], m3[x] = m2[x], d2[x] = d1[op] + 1, m2[x] = m1[op];
	else if (d1[op] + 1 > d3[x]) 
		d3[x] = d1[op] + 1, m3[x] = m1[op];
}
void update2(int x, int op){
	if (d2[op] + 1 >= d1[x]) 
		d3[x] = d2[x], m3[x] = m2[x], d2[x] = d1[x], m2[x] = m1[x], d1[x] = d2[op] + 1, m1[x] = m2[op];
	else if (d2[op] + 1 >= d2[x]) 
		d3[x] = d2[x], m3[x] = m2[x], d2[x] = d2[op] + 1, m2[x] = m2[op];
	else if (d2[op] + 1 > d3[x]) 
		d3[x] = d2[op] + 1, m3[x] = m2[op];
}
int dfs[maxn], siz[maxn], d[maxn], t = 0;
void DFS(int x){
	dfs[x] = ++t, siz[x] = 1;
	srep(i, 1, maxb) fa[x][i] = fa[fa[x][i - 1]][i - 1];
	erep(i, x){
		int op = e[i].to;
		if (op == fa[x][0]) continue;
		fa[op][0] = x;
		d[op] = d[x] + 1;
		DFS(op);
		siz[x] += siz[op];
		update(x, op);
	}
	if (!d1[x]) m1[x] = x;
	if (!d2[x]) m2[x] = x;
	if (!d3[x]) m3[x] = x;
}
void DP(int x){
	erep(i, x){
		int op = e[i].to;
		if (op == fa[x][0]) continue;
		if (m1[x] == m1[op]) update2(op, x);
		else update(op, x); 
		DP(op);
	}
}
int getlca(int x, int y){
	if (x == y) return x;
	if (d[x] < d[y]) swap(x, y);
	int di = d[x] - d[y], now = 0;
	while (di){
		if (di & 1) x = fa[x][now];
		now++, di >>= 1;
	}
	if (x == y) return x;
	per(i, maxb - 1, 0) if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}
int jumpp(int x, int y){
	int now = 0;
	while (y){
		if (y & 1) x = fa[x][now];
		now++, y >>= 1;
	}
	return x;
}

struct ele{
	int type, d1, d2, d3, m1, m2, m3, id;
	ele(int type, int d1, int d2, int d3, int m1, int m2, int m3, int id) : type(type), d1(d1), d2(d2), d3(d3), m1(m1), m2(m2), m3(m3), id(id){}
	ele(){}
	bool operator < (const ele b) const{
		if (d1 == b.d1){
			if (type == b.type){
				if (d2 == b.d2){
					return d3 > b.d3;
				}
				return d2 > b.d2;
			}
			return type < b.type;
		}
		return d1 > b.d1;
	}
}eee[maxn << 1];

pii c[maxn];
int get(int x){
	int d = -1, id = -1;
	while (x <= n){
		if (c[x].se == -1) {x += lowbit(x); continue;}
		if (c[x].fi >= d) d = c[x].fi, id = c[x].se;
		x += lowbit(x);
	}
	return id;
}
void upd(int x, int d, int m){
	while (x){
		if (c[x].se == -1) c[x].fi = d, c[x].se = m;
		else if (d >= c[x].fi) c[x].fi = d, c[x].se = m;
		x -= lowbit(x);
	}
}
bool insubtree(int x, int op){
	return dfs[x] <= dfs[op] && dfs[op] < dfs[x] + siz[x];
}

int ans[maxn];
int ans2[maxn][3];
int main(){
	#ifndef ONLINE_JUDGE
		freopen("J.in", "r", stdin);
	#endif
	int x, y, z, s;
	read(n);
	srep(i, 1, n) read(x), read(y), x++, y++, Add_Edge(x, y);
	DFS(1), DP(1);
	int ct = 0;
	rep(i, 1, n) eee[++ct] = ele(0, d1[i], d2[i], d3[i], m1[i], m2[i], m3[i], i); 
	#ifdef DEBUG
		rep(i, 1, n) printf("%d: %d %d %d %d %d %d\n", i, d1[i], d2[i], d3[i], m1[i], m2[i], m3[i]); 
	#endif
	rep(i, 1, n) c[i].se = -1;
	read(q);
	rep(i, 1, q){
		read(x), read(y), read(z);
		if ((x + y + z) & 1) ans[i] = -1;
		else {
			s = (x + y + z) / 2;
			if (s < x || s < y || s < z) ans[i] = -1;
			else {
				eee[++ct] = ele(1, 0, 0, 0, 2, 1, 0, i);
				if (x > y) swap(x, y), swap(eee[ct].m1, eee[ct].m2);
				if (x > z) swap(x, z), swap(eee[ct].m1, eee[ct].m3);
				if (y > z) swap(y, z), swap(eee[ct].m2, eee[ct].m3);
				eee[ct].d1 = s - x, eee[ct].d2 = s - y, eee[ct].d3 = s - z;
				//assert(x <= y && y <= z);
				#ifdef DEBUG
					printf("%d: %d %d %d\n", i, s - x, s - y, s - z);
				#endif
			}
		}
	}
	sort(eee + 1, eee + 1 + ct);
	#ifdef DEBUG
		rep(i, 1, ct){
			ele op = eee[i];
			printf("%d: %d %d %d %d %d %d %d %d\n", i, op.type, op.d1, op.d2, op.d3, op.m1, op.m2, op.m3, op.id);
		}
	#endif
	rep(i, 1, ct){
		ele op = eee[i];
		if (!op.type){
			upd(op.d2 + 1, op.d3, op.id);
		}
		else {
			int m = get(op.d2 + 1);
			if (m == -1) ans[op.id] = -1;
			else {
				//assert(d1[m] >= op.d1 && d2[m] >= op.d3);
				if (d1[m] >= op.d1 && d2[m] >= op.d2 && d3[m] >= op.d3){
					if (insubtree(m, m1[m])) ans2[op.id][op.m1] = jumpp(m1[m], d[m] - op.d1); 
					else {	
						int lca = getlca(m, m1[m]);
						if (d[m] - d[lca] >= op.d1) ans2[op.id][op.m1] = jumpp(m, op.d1);
						else ans2[op.id][op.m1] = jumpp(m1[m], d1[m] - op.d1);
					}
					if (insubtree(m, m2[m])) ans2[op.id][op.m2] = jumpp(m2[m], d2[m] - op.d2); 
					else {	
						int lca = getlca(m, m2[m]);
						if (d[m] - d[lca] >= op.d2) ans2[op.id][op.m2] = jumpp(m, op.d2);
						else ans2[op.id][op.m2] = jumpp(m2[m], d2[m] - op.d2);
					}
					if (insubtree(m, m3[m])) ans2[op.id][op.m3] = jumpp(m3[m], d3[m] - op.d3); 
					else {	
						int lca = getlca(m, m3[m]);
						if (d[m] - d[lca] >= op.d3) ans2[op.id][op.m3] = jumpp(m, op.d3);
						else ans2[op.id][op.m3] = jumpp(m3[m], d3[m] - op.d3);
					}
				}
				else ans[op.id] = -1;
			}
		}
	}
	rep(i, 1, q) {
		if (ans[i] == -1) printf("-1");
		else rep(j, 0, 2) printf("%d ", ans2[i][j] - 1); 
		printf("\n");
	}
	return 0;
}

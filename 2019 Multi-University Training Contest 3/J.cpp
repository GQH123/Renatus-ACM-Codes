#include <bits/stdc++.h>
#define maxr 100000
#define maxn 200005
#define maxb 20
#define ll long long int 
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define M 1000000007
#define mo(x) x = (x >= M) ? (x - M) : x
#define lowbit(x) (x & -x)
#define ms(a, b) memset(a, b, sizeof(b))
//#define DEBUG
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}

int n, m;
int f[maxn], g[maxn];
struct edge{
	int next, to;
	edge(int next, int to) : next(next), to(to){}
	edge(){}
}e[maxn << 1];
int cnt = 1, h[maxn], d[maxn];
void Add_Edge(int x, int y){
	e[++cnt] = edge(h[x], y);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x);
	h[y] = cnt;
}
int fa[maxn][maxb];
int temc[maxn], sumg[maxn];
int dfs[maxn], siz[maxn], idfs[maxn];
int t = 0;
int temd[maxn], temd2[maxn];


/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
int c[maxn];
int getsumf(int x){ //请传入点编号，而非dfs序
	int ans = 0;
	x = dfs[x];
	while (x){
		ans += c[x], mo(ans);
		x -= lowbit(x);
	}
	return ans;
}
void addsumf(int x, int v){ // 请传入dfs序，以及正参数
	mo(v);
	if (!x) return;
	while (x <= n){
		c[x] += v, mo(c[x]);
		x += lowbit(x);
	}
}

int c2[maxn];
int getdown(int x){ //请传入点编号，而非dfs序
	int ans = 0;
	x = dfs[x];
	while (x){
		ans += c2[x], mo(ans);
		x -= lowbit(x);
	}
	return ans;
}
void adddown(int x, int v){ // 请传入dfs序，以及正参数
	mo(v);
	if (!x) return;
	while (x <= n){
		c2[x] += v, mo(c2[x]);
		x += lowbit(x);
	}
}

int c3[maxn];
int getdown2(int x){ //请传入点编号，而非dfs序
	int ans = 0;
	x = dfs[x];
	while (x){
		ans += c3[x], mo(ans);
		x -= lowbit(x);
	}
	return ans;
}
void adddown2(int x, int v){ // 请传入dfs序，以及正参数
	mo(v);
	if (!x) return;
	while (x <= n){
		c3[x] += v, mo(c3[x]);
		x += lowbit(x);
	}
}
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/


void DFS(int x){
	int ffa = fa[x][0];

	dfs[x] = ++t, idfs[t] = x, siz[x] = 1;
	
	//up[x] = M + up[ffa] - (ll)g[x] * getsumf(ffa) % M, mo(up[x]);
	
	//down[x] = M + down[ffa] - (ll)gg * f[x] % M, mo(down[x]), gg += g[x], mo(gg);
	temd[x] = M + temd[ffa] - (ll)sumg[ffa] * f[x] % M, mo(temd[x]), adddown(dfs[x], M + temd[x] - temd[idfs[dfs[x] - 1]]);
	
	//sumf[x] = sumf[fa[x][0]] + f[x], mo(sumf[x]);
	temc[x] = temc[ffa] + f[x], mo(temc[x]), addsumf(dfs[x], M + temc[x] - temc[idfs[dfs[x] - 1]]);
	
	sumg[x] = sumg[ffa] + g[x], mo(sumg[x]);
	
	temd2[x] = M + temd2[ffa] - (ll)sumg[x] * f[x] % M, mo(temd2[x]), adddown2(dfs[x], M + temd2[x] - temd2[idfs[dfs[x] - 1]]);
	
	srep(i, 1, maxb) fa[x][i] = fa[fa[x][i - 1]][i - 1];
	
	erep(i, x){
		int op = e[i].to;
		if (op == ffa) continue;
		fa[op][0] = x;
		d[op] = d[x] + 1;
		DFS(op);
		siz[x] += siz[op];
	}
}

int getlca(int x, int y){
	if (x == y) return x;
	if (d[x] < d[y]) swap(x, y);
	int di = d[x] - d[y];
	int now = 0;
	while (di){
		if (di & 1) x = fa[x][now];
		di >>= 1, now++;
	}
	if (x == y) return x;
	per(i, maxb - 1, 0) if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}

int get(int x, int y, int z){
	mo(z);
	int lca = getlca(x, y), _lca = fa[lca][0];
	ll ans = M + (ll)z * (getsumf(x) + getsumf(y) - getsumf(lca) - getsumf(_lca)) % M; ans %= M;
	//int ans1 = M + up[x] - (M + up[_lca] - (ll)(sumg[x] - sumg[_lca]) * getsumf(_lca) % M) % M, mo(ans1);
	ll ans1 = M - (ll)(M + getdown2(x) - getdown2(_lca)) % M + M - (ll)sumg[x] % M * (M + getsumf(x) - getsumf(_lca)) % M; ans1 %= M;
	ll ans2 = M + (ll)(M + getdown(y) - getdown(lca)) % M - (ll)(M + sumg[x] - sumg[_lca] - sumg[lca]) * (M + getsumf(y) - getsumf(lca)) % M; ans2 %= M;
	//printf("%d\n%d\n%d\n", ans, ans1, ans2);
	//printf("%d\n%d\n", (M + getdown(y) - getdown(lca)) % M, (ll)(M + sumg[x] - sumg[_lca] - sumg[lca]) * (M + getsumf(y) - getsumf(lca)) % M);
	return ((ll)ans + ans1 + ans2) % M;
}
void modify(int x, int v){
	mo(v);
	int o = (M + getsumf(x) - getsumf(fa[x][0])); mo(o);
	int qx = dfs[x], qy = dfs[x] + siz[x];
	int add = v - o + M; mo(add);
	addsumf(qx, add), addsumf(qy, M - add);
	add = M - (ll)sumg[fa[x][0]] * (M + v - o) % M, mo(add);
	adddown(qx, add), adddown(qy, M - add);
	add = M - (ll)sumg[x] * (M + v - o) % M, mo(add);
	adddown2(qx, add), adddown2(qy, M - add);
}
inline void recover(){
	cnt = 1, t = 0;
	rep(i, 1, n) h[i] = c[i] = c2[i] = c3[i] = 0;
}
int main(){
	#ifndef ONLINE_JUDGE
		freopen("J.in", "r", stdin);
	#endif
	int T;
	read(T);
	while (T--){
		int x, y, z;
		read(n);
		rep(i, 1, n) read(f[i]), mo(f[i]);
		rep(i, 1, n) read(g[i]);
		srep(i, 1, n) read(x), read(y), Add_Edge(x, y);
		DFS(1);
		#ifdef DEBUG
			rep(i, 1, n) printf("%d: %d %d %d %d %d %d\n", i, sumg[i], fa[i][0], d[i], dfs[i], getsumf(i), getdown(i));
		#endif
		read(m);
		rep(i, 1, m) {
			read(x);
			if (x == 1) read(x), read(y), read(z), printf("%d\n", get(x, y, z));
			else if (x == 2) read(x), read(y), modify(x, y); 
		} 
		recover();
	}
	return 0;
}

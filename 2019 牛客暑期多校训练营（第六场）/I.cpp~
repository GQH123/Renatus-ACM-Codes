#include <bits/stdc++.h>
#define maxr 100000
#define maxn 300105
#define maxb 20
#define M 998244353
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define mo(x) x = (x >= M) ? (x - M) : x
#define ll long long int 
#define DEBUG(x) {\
printf("%s:", #x); rep(i, 1, n) printf(" %d", x[i]); printf("\n");\
}
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
int n, m;
struct edge{
	int next, to, a, b;
	edge(int next, int to, int a, int b) : next(next), to(to), a(a), b(b){}
	edge(){}
}e[maxn << 1];
int cnt = 1, h[maxn];
void Add_Edge(int x, int y, int u, int v){
	e[++cnt] = edge(h[x], y, u, v);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x, u, v);
	h[y] = cnt;
}
bool vis[maxn << 1];
int dfs[maxn], t = 0, fa[maxn][maxb], vf[maxn][maxb];
int tag[maxn], low[maxn], up[maxn], v[maxn], d[maxn];
int power(int x, int y){
	int ans = 1, con = x;
	while (y){
		if (y & 1) ans = (ll)ans * con % M;
		con = (ll)con * con % M;
		y >>= 1;
	}
	return ans;
}
int get_inv(int x){
	return power(x, M - 2);
}
void jump_and_tag(int i, int val, int loww, int upp, int x, int ffa){
	while (x != ffa) tag[x] = i, v[x] = val, low[x] = loww, up[x] = upp, x = fa[x][0];
}
void DFS(int x){
	srep(i, 1, maxb) fa[x][i] = fa[fa[x][i - 1]][i - 1], vf[x][i] = (ll)vf[x][i - 1] * vf[fa[x][i - 1]][i - 1] % M;
	dfs[x] = ++t;
	erep(i, x){
		int op = e[i].to;
		if (op == fa[x][0]) continue;
		if (!dfs[op]) vis[i] = 1, fa[op][0] = x, vf[op][0] = (ll)e[i].a * get_inv(e[i].b) % M, d[op] = d[x] + 1, DFS(op); 
		else if (dfs[op] > dfs[x]) jump_and_tag(i, (ll)e[i].a * get_inv(e[i].b) % M, op, x, op, x); 
	}
}
int jump(int x, int y){
	int now = 0, ans = 1;
	while (y){
		if (y & 1) ans = (ll)ans * vf[x][now] % M, x = fa[x][now];
		y >>= 1, now++;
	}
	return ans;
}
int ans;
int dp[maxn];
void DP(int x){
	if (x == 1) dp[x] = 1;
	else {
		if (tag[x]){	
			int p1 = M + 1 - jump(x, d[x] - d[up[x]]); mo(p1);
			int p2 = M + 1 - (ll)jump(low[x], d[low[x]] - d[x]) * v[x] % M; mo(p2);
			p2 = M + 1 - (ll)p1 * p2 % M, mo(p2);
			dp[x] = (ll)dp[up[x]] * p2 % M;
		}
		else dp[x] = (ll)dp[fa[x][0]] * jump(x, 1) % M;
	}
	ans += dp[x], mo(ans);
	erep(i, x) if (vis[i]) DP(e[i].to);  
}

void recover(){
	rep(i, 1, cnt) vis[i] = 0;
	cnt = 1, ans = t = 0;
	rep(i, 1, n) tag[i] = dfs[i] = h[i] = 0;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("I.in", "r", stdin);
	#endif
	int T, x, y, u, v;
	read(T);
	rep(TT, 1, T){
		printf("Case #%d: ", TT);
		read(n), read(m);
		rep(i, 1, m) read(x), read(y), read(u), read(v), Add_Edge(x, y, u, v);
		DFS(1);
		//DEBUG(fa); DEBUG(dfs); DEBUG(low); DEBUG(up); DEBUG(f);
		DP(1);
		printf("%d\n", ans);
		recover();
	}
	return 0;
}

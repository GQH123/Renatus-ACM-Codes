#include <bits/stdc++.h>
#define maxr 100000
#define maxn 615
#define maxm 1000105
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define M 998244353
#define pb push_back
#define ll long long int 
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
int l[maxn];
int r[maxn];
int a[maxm];
vector<int> s[maxn];

struct edge{
	int next, to, part;
	edge(int next, int to, int part) : next(next), to(to), part(part){}
	edge(){}
}e[maxn << 1];
int h[maxn], cnt = 0;
void Add_Edge(int x, int y, int part){
	e[++cnt] = edge(h[x], y, part);
	h[x] = cnt;
}

bool build(int le, int ri, int o, int part){
	if (le > ri) return true;
	rep(i, le, ri){
		int x = a[i];
		if (i != l[x] || r[x] > ri) return false;
		int _n = s[x].size() - 1, id = 0;
		srep(j, 0, _n) if (!build(s[x][j] + 1, s[x][j + 1] - 1, x, ++id)) return false; 
		if (o > x) return false;
		Add_Edge(o, x, part);
		i = r[x];
	}
	return true;
}

int ans[maxn];
int b[maxn];
int ct = 0;
int dp[maxn][maxn];
bool vis[maxn][maxn];
int DP(int l, int r){
	if (l == r) return ans[b[l]];
	if (l > r) return 1;
	if (vis[l][r]) return dp[l][r];
	vis[l][r] = 1;
	int& ans2 = dp[l][r];
	int le = 0, ri = 0;
	int mi = n + 1, mip = -1;
	rep(i, l, r) if (mi > b[i]) mi = b[i], mip = i;
	srep(i, l - 1, mip) le += (ll)DP(l, i) * DP(i + 1, mip - 1) % M, le %= M;
	sper(i, r + 1, mip) ri += (ll)DP(i, r) * DP(mip + 1, i - 1) % M, ri %= M;
	return ans2 = (ll)le * ri % M * ans[mi] % M;
}

void GETANS(int x){
	erep(i, x){
		int op = e[i].to;
		GETANS(op);
	}
	ans[x] = 1;
	int i = h[x];
	while (i){	
		int op = e[i].to, p = e[i].part;
		while (i && e[i].part == p) b[++ct] = e[i].to, i = e[i].next;
		ans[x] = (ll)ans[x] * DP(1, ct) % M;
		rep(k, 1, ct) rep(j, 1, ct) dp[k][j] = vis[k][j] = 0;
		ct = 0;
	}
}

void debug(int x){
	int i = h[x];
	printf("node:%d\n", x);
	while (i){
		int op = e[i].to, p = e[i].part;
		printf("part%d: ", p); while (i && e[i].part == p) printf("%d ", e[i].to), i = e[i].next; printf("\n");
	}
	erep(i, x){
		int op = e[i].to;
		debug(op);
	}
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("G.in", "r", stdin);
	#endif
	read(n), read(m);
	rep(i, 1, m) read(a[i]), s[a[i]].pb(i);
	rep(i, 1, m) r[a[i]] = i;
	per(i, m, 1) l[a[i]] = i;
	if (!build(1, m, 0, 1)) {printf("0"); return 0;}
	GETANS(0);
	//debug(0);
	printf("%d", ans[0]);
	return 0;
}

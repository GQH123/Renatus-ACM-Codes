#pragma GCC optimize("Ofast,no-stack-protector")
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
#define maxn 6020 
#define maxr 2000000
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template<class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}

const int inf = 2147483647;

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

int n, c, k, m, v[maxn];
int vis[maxn], idx;
int dp[maxn][2];
void DP(int x, int fa){
	vis[x] = idx;
	dp[x][0] = v[x];
	dp[x][1] = 0;
	erep(i, x){
		int op = e[i].to;
		if (op == fa) continue;
		DP(op, x);
		dp[x][0] += dp[op][1];
		dp[x][1] += dp[op][0];
	}
	dp[x][0] = max(dp[x][0], dp[x][1]);
}

struct info{
	int x, c;
	info(int x, int c) : x(x), c(c){}
	info(){}
	bool operator < (const info b) const{
		return x < b.x;
	}
}city[maxn];

bool DP(){
	idx++; int ans = 0;
	rep(i, 1, c) if (vis[i] != idx) {
		DP(i, 0), ans += dp[i][0]; 
		if (ans >= k) return true;
	}
	return false;
}
int num[maxn], cnum = 0;

int main(){
	int T, x, y; read(T);
	rep(TT, 1, T){
		printf("Case #%d: ", TT);
		read(n), read(c), read(k), read(m);
		rep(i, 1, c) num[i] = 0;
		rep(i, 1, n) read(city[i].x), read(city[i].c);
		rep(i, 1, m) read(x), read(y), Add_Edge(x, y);  
		sort(city + 1, city + 1 + n);
		int ptr = 1, res = inf; bool f = 0;
		rep(l, 1, n){ 
			while (ptr <= n && !f) {
				if (!num[city[ptr].c]) v[city[ptr].c] = 1, cnum++, f = (cnum >= k) ? DP() : 0;
				num[city[ptr].c]++;
				ptr++;
			}
			if (f) res = min(res, city[ptr - 1].x - city[l].x);
			else break;
			num[city[l].c]--;
			if (!num[city[l].c]) v[city[l].c] = 0, cnum--, f = (cnum >= k) ? DP() : 0;
		}
		if (res == inf) printf("-1\n");
		else printf("%d\n", res);
		rep(i, 1, c) h[i] = v[i] = 0; cnt = 1;
	}
	return 0;
}

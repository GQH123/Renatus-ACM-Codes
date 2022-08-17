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
#define maxn 220
#define maxm
using namespace std;

const int inf = 2000000000;

int n;
int a[maxn], b[maxn];
struct edge{
	int next, to;
	edge(int next, int to) : next(next), to(to){}
	edge(){}
}e[maxn << 1];
int cnt = 1, h[maxn], deg[maxn];
void Add_Edge(int x, int y){
	e[++cnt] = edge(h[x], y);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x);
	h[y] = cnt;
	deg[x]++, deg[y]++;
}
int tim = 0;
int vis[maxn][6];
int dp[maxn][6];
int DP(int x, int fa, int op){
	if (vis[x][op] == tim) return dp[x][op];
	vis[x][op] = tim;
	int& ans = dp[x][op]; ans = inf;
	// Choose an army
	if (!op) return ans = min(DP(x, fa, 3) + (a[x] >> 1), DP(x, fa, 4) + (b[x] >> 1)); 
	if (op == 1){
		ans = 0;
		erep(i, x){
			int u = e[i].to;
			if (u == fa) continue;
			ans += min(DP(u, x, 1) + (a[u] >> 1), DP(u, x, 0));
		}
		return ans;
	}
	if (op == 2){
		ans = 0;
		erep(i, x){
			int u = e[i].to;
			if (u == fa) continue;
			ans += min(DP(u, x, 2) + (b[u] >> 1), DP(u, x, 0));
		}
		return ans;
	}
	if (op == 3){
		if (x != 1 && deg[x] == 1) return ans = DP(x, fa, 1) + a[x] - (a[x] >> 1); 
		else {
			int mi = inf;
			ans = 0;
			erep(i, x){
				int u = e[i].to;
				if (u == fa) continue;
				ans += min(DP(u, x, 1) + (a[u] >> 1), DP(u, x, 0));
				mi = min(mi, (DP(u, x, 3) + (a[u] >> 1)) - min(DP(u, x, 1) + (a[u] >> 1), DP(u, x, 0)));
			}
			ans += mi;
			return ans = min(ans, DP(x, fa, 1) + a[x] - (a[x] >> 1));
		} 
	}
	if (op == 4){
		if (x != 1 && deg[x] == 1) return ans = DP(x, fa, 2) + b[x] - (b[x] >> 1); 
		else {
			int mi = inf;
			ans = 0;
			erep(i, x){
				int u = e[i].to;
				if (u == fa) continue;
				ans += min(DP(u, x, 2) + (b[u] >> 1), DP(u, x, 0));
				mi = min(mi, (DP(u, x, 4) + (b[u] >> 1)) - min(DP(u, x, 2) + (b[u] >> 1), DP(u, x, 0)));
			}
			ans += mi;
			return ans = min(ans, DP(x, fa, 2) + b[x] - (b[x] >> 1));
		} 
	}
}
int main(){
	int x, y;
	while (scanf("%d", &n) == 1){
		tim++;
		rep(i, 1, n) scanf("%d", a + i);
		rep(i, 1, n) scanf("%d", b + i);
		rep(i, 2, n) scanf("%d%d", &x, &y), Add_Edge(x, y);
		if (n == 1){
			printf("%d\n", min(a[1], b[1]));
			continue;
		}
		printf("%d\n", DP(1, -1, 0));
		rep(i, 1, n) deg[i] = h[i] = 0; cnt = 1;
	} 
	return 0;
}

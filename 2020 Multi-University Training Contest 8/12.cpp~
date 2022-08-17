#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define maxn 2020 
using namespace std;

const int inf = 2000000000;

int n, l[maxn], r[maxn], lis[maxn << 1], cs = 0;
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

int dp[maxn][maxn << 1], vis[maxn], idx = 0;
void DP(int x, int fa){
	if (vis[x] == idx) return;
	vis[x] = idx;
	rep(i, 1, cs) dp[x][i] = 0;
	erep(i, x){
		int op = e[i].to;
		if (op == fa) continue;
		DP(op, x);
		rep(j, l[x], r[x]) dp[x][j] += dp[op][j];
	}
	int mi = inf, idmi = -1;
	rep(i, l[x], r[x]) if (dp[x][i] < mi) mi = dp[x][i], idmi = i; 
	srep(i, 1, l[x]) dp[x][i] = mi + 1;
	rep(i, r[x] + 1, cs) dp[x][i] = mi + 1;
	rep(i, l[x], r[x]){
		if (i == idmi) continue;
		dp[x][i] = min(dp[x][i], mi + 1);
	}
	return;
}

void recover(){
	cnt = 1; rep(i, 1, n) h[i] = 0; cs = 0;
}

int main(){
	int T, x, y; scanf("%d", &T);
	while (T--){
		idx++;
		scanf("%d", &n);
		rep(i, 2, n){
			scanf("%d%d", &x, &y);
			Add_Edge(x, y);
		}
		rep(i, 1, n) scanf("%d%d", l + i, r + i);
		lis[++cs] = 0;
		rep(i, 1, n) lis[++cs] = l[i], lis[++cs] = r[i];
		sort(lis + 1, lis + 1 + cs);
		cs = unique(lis + 1, lis + 1 + cs) - lis - 1;
		rep(i, 1, n) l[i] = lower_bound(lis + 1, lis + 1 + cs, l[i]) - lis;
		rep(i, 1, n) r[i] = lower_bound(lis + 1, lis + 1 + cs, r[i]) - lis;
		int zero = lower_bound(lis + 1, lis + 1 + cs, 0) - lis;
		DP(1, 0);
		printf("%d\n", dp[1][zero]); 
		recover();
	}
	return 0;
}

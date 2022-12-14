#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 20
#define ll long long int 
using namespace std;

const int inf = 2000000020;

int n;
int v[maxn][2];

bool vis[1 << maxn][maxn];
int dp[1 << maxn][maxn];
int DP(int op, int last){
	if (op == ((1 << n) - 1)) return 0;
	if (vis[op][last]) return dp[op][last];
	vis[op][last] = 1;
	int& ans = dp[op][last];
	ans = inf;
	int now = 0, sum = 0;
	rep(i, 1, n) if (op & (1 << (i - 1))) sum++;
	per(i, n, 1){
		if (op & (1 << (i - 1))) {now++; continue;}
		if (v[i][((sum + 1) & 1) ^ (i & 1)] < v[last][(sum & 1) ^ (last & 1)]) continue;
		ans = min(ans, DP(op | (1 << (i - 1)), i) + now);
	} 
	return ans;
} 
int main(){
	
		//freopen("D.in", "r", stdin);
	
	cin >> n;
	rep(i, 1, n) cin >> v[i][0];
	rep(i, 1, n) cin >> v[i][1];
	
	int ans = DP(0, 0);
	if (ans == inf) printf("-1");
	else printf("%d", ans);
	return 0;
}

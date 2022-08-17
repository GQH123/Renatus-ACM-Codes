#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define maxn 2020
using namespace std;

int ti;
int m, n, a[maxn], b[maxn], w[maxn];
/*
int vis[2][maxn][maxn];
int dp[2][maxn][maxn];
int DP(bool get, int pos, int rest){
	if (!rest || pos > n) return 0;
	if (vis[get][pos][rest] == ti) return dp[get][pos][rest];
	vis[get][pos][rest] = ti;
	int& ans = dp[get][pos][rest];
	ans = 0;
	if (get){
		if (rest >= w[pos]) ans = max(ans, DP(1, pos, rest - w[pos]) + a[pos]);
		ans = max(ans, DP(0, pos + 1, rest));
	}
	else {
		if (rest >= w[pos]) ans = max(ans, DP(1, pos, rest - w[pos]) + a[pos] + b[pos]);
		ans = max(ans, DP(0, pos + 1, rest));
	}
	return ans;
}
*/

int dp[2][maxn][maxn];
inline int DP(bool get, int pos, int rest){
	return (pos > n) ? 0 : dp[get][pos][rest];
}
void DP(){
	
	per(pos, n, 1){
		per(get, 1, 0){
			dp[get][pos][0] = 0;
			rep(rest, 1, m){
				int& ans = dp[get][pos][rest];
				ans = 0;
				if (get){
					if (rest >= w[pos]) ans = max(ans, DP(1, pos, rest - w[pos]) + a[pos]);
					ans = max(ans, DP(0, pos + 1, rest));
				}
				else {
					if (rest >= w[pos]) ans = max(ans, DP(1, pos, rest - w[pos]) + a[pos] + b[pos]);
					ans = max(ans, DP(0, pos + 1, rest));
				}
			}
		}
	}
	printf("%d\n", DP(0, 1, m));
}

int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		ti++;
		scanf("%d%d", &m, &n);
		rep(i, 1, n) scanf("%d%d%d", w + i, a + i, b + i);
		DP();
	}
	return 0;
}

#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 119
using namespace std;

const int inf = 2000000020;

int n;
int a[maxn << 1];

int gcd(int x, int y){
	return (!y) ? x : gcd(y, x % y);
}

int v[maxn << 1][maxn << 1];
int dp[maxn << 1][maxn << 1];
inline int DP(){
	rep(len, 3, (n << 1)){
		rep(l, 1, (n << 1)){
			int r = l + len - 1, mi = inf;
			if (r > (n << 1)) continue;
			rep(k, l + 1, r - 1) mi = min(mi, dp[l][k] + dp[k][r]);
			dp[l][r] = mi + v[l][r];
		}
	}
}

int main(){
	//#ifndef ONLINE_JUDGE
	//	freopen("F.in", "r", stdin);
	//#endif
	while (1){
		scanf("%d", &n);
		if (!n) return 0;
		rep(i, 1, n) scanf("%d", &a[i]);
		rep(i, 1, n) a[n + i] = a[i];
		rep(i, 1, (n << 1)) rep(j, 1, (n << 1)) v[i][j] = gcd(a[i], a[j]);
		int ans = inf;
		DP();
		rep(i, 1, n) rep(j, i + 1, n) ans = min(ans, v[i][j] + dp[i][j] + dp[j][n + i]); 
		printf("%d\n", ans);
	}
	return 0;
}

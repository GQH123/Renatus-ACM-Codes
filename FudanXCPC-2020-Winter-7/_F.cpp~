#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 6020
#define M 1000000007
#define mo(x) (x = (x >= M) ? (x - M) : x)
#define ll long long int
using namespace std;

/*
	bool vis[maxn][maxn];
	int dp[maxn][maxn];
	int DP(int base, int blo){
		if (!blo) return 1;
		if (blo < 0) return 0;
		if (vis[base][blo]) return dp[base][blo];
		int& ans = dp[base][blo];
		vis[base][blo] = 1;
		rep(k, 1, base) ans += (base - k + 1) * (ll)DP(k, blo - k) % M, mo(ans);
		return ans;
	}
*/

bool vis[maxn][maxn][2];
int dp[maxn][maxn][2];
int DP(int base, int blo, bool op){
	if (!blo) return 1; if (blo < 0) return 0;
	if (vis[base][blo][op]) return dp[base][blo][op];
	int& ans = dp[base][blo][op];
	vis[base][blo][op] = 1;
	if (!op){
		ans = ans + DP(base, blo, 1), mo(ans);
		if (base > 1) ans = ans + DP(base - 1, blo, 0), mo(ans);
	}
	else {
		if (base > 1) ans = ans + DP(base - 1, blo, 1), mo(ans);
		ans = ans + DP(base, blo - base, 0), mo(ans);
	}
	return ans;
}

int main(){
	
		freopen("F.in", "r", stdin);
	
	int n, m;
	scanf("%d%d", &n, &m);	
	printf("%d\n", DP(n, m - n, 0));
	return 0;
}

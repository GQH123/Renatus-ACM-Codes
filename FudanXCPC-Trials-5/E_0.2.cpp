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
#define maxm
using namespace std;

int n; 
/*
int dp[maxn][maxn][1 << maxn];
bool vis[maxn][maxn][1 << maxn];
*/
map<pii, int> dp;
int dfs(int x, int s){
	if (s + 1 == (1 << n)) return 1;
	if (dp.count(pii(x, s))) return dp[pii(x, s)];
	int ans = 0;
	rep(i, 1, n) {
		if (!(s & (1 << (i - 1)))) {
			if ((x << 1) <= i || (i << 1) <= x) {
				ans += dfs(i, s ^ (1 << (i - 1)));
			}
		}
	}
	dp[pii(x, s)] = ans;
	return ans;
}
int main(){
	//bc[0] = 0; srep(i, 1, (1 << 27)) bc[i] = bc[i >> 1] + (i & 1);
	cin >> n; 
	int res = 0;
	rep(i, 1, n) res += dfs(i, 1 << (i - 1));
	cout << n << " : " << res << endl;
	return 0;
}

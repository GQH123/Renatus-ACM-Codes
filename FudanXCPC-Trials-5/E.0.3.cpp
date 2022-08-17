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
#define maxn 24
using namespace std;

int bc[1 << maxn];
int n;  
int dp[maxn][1 << maxn];
bool vis[maxn][1 << maxn];
int dfs(int x, int s){
	if (bc[s] == n) return 1;
	if (vis[x][s]) return dp[x][s];
	vis[x][s] = 1; int& ans = dp[x][s]; ans = 0;
	
	s ^= (1 << (x - 1));
	int now = 0, suf = n - bc[s];
	rep(i, 1, n) { 
		if (!(i & 1)) now += ((s & (1 << ((i >> 1) - 1))) ? 0 : 1);
		if (!(s & (1 << (i - 1)))) if (!now && !suf) return 0; 
		if ((i << 1) <= n && !(s & (1 << ((i << 1) - 1)))) suf--;
		if ((i << 1 | 1) <= n && !(s & (1 << (i << 1)))) suf--;
	}
	s ^= (1 << (x - 1));
	
	rep(i, 1, n) {
		if (!(s & (1 << (i - 1)))) {
			if ((x << 1) <= i || (i << 1) <= x) {
				ans += dfs(i, s ^ (1 << (i - 1)));
			}
		}
	}
	return ans;
}
int main(){
	bc[0] = 0; srep(i, 1, (1 << maxn)) bc[i] = bc[i >> 1] + (i & 1);
	cin >> n; 
	int res = 0;
	rep(i, 1, n) res += dfs(i, 1 << (i - 1));
	cout << n << " : " << res << endl;
	return 0;
}

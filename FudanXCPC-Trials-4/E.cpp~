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
#define maxn 1520 
#define maxt 4
using namespace std;

int x, y, z, t, n, idx = 0;
ll dp[maxn][maxn][maxt];
int vis[maxn][maxn][maxt];
ll DP(int nb, int ng, int nowt){
	if (nb + ng == 0) return 0;
	if (vis[nb][ng][nowt] == idx) return dp[nb][ng][nowt];
	vis[nb][ng][nowt] = idx;
	ll& ans = dp[nb][ng][nowt]; ans = 0;
	if (nb) ans = max(ans, DP(nb - 1, ng, nowt) + (nowt + 1ll * (nb - 1) * z) * 1ll * ng * y);
	if (ng) ans = max(ans, DP(nb, ng - 1, nowt) + (nowt + 1ll * nb * z) * 1ll * (ng - 1) * y);
	return ans;
}

int main(){ 
	int T; scanf("%d", &T);
	rep(TT, 1, T){
		printf("Case #%d: ", TT);
		idx++;
		scanf("%d%d%d%d%d", &n, &x, &y, &z, &t);
		ll res = 0;
		rep(ng, 0, n) {
			rep(nb, 0, n - ng){	
				res = max(res, DP(nb, ng, t) + (t + 1ll * nb * z) * 1ll * x * (n - ng - nb) + 1ll * ng * y * (n - ng - nb) * (t + 1ll * nb * z));
			}
		}
		printf("%lld\n", res);
	}
	return 0;
}

#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define maxn 3020
#define maxm 
#define M 
#define ll long long int 
#define ld long double
#define pb push_back
#define pc putchar
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define lowbit(x) (x & -x)
using namespace std;

int n, a[maxn], b[maxn];
int tim = 0;
ll dp[maxn][maxn];
int vis[maxn][maxn];
ll DP(int pos, int rest){
	if (pos == 1){
		if (rest) return -1;
		else return 0;
	}
	if (vis[pos][rest] == tim) return dp[pos][rest];
	vis[pos][rest] = tim;
	ll& ans = dp[pos][rest]; ans = -1;
	if (DP(pos - 1, rest) != -1 && DP(pos - 1, rest) + b[pos - 1] >= a[pos - 1]) {
		ans = max(ans, DP(pos - 1, rest) + b[pos - 1] - a[pos - 1]);
	}
	if (rest && DP(pos - 1, rest - 1) != -1) {
		ans = max(ans, DP(pos - 1, rest - 1) + b[pos - 1]);
	}
	return ans;
}
int main(){
	int T; scanf("%d", &T);
	while (T--){
		++tim;
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", a + i);
		rep(i, 1, n) scanf("%d", b + i);
		int res = 0;
		rep(i, 0, n) {
			if (DP(n + 1, i) != -1) {
				res = n - i;
				break;
			}
		}
		printf("%d\n", res);
	} 
	return 0;
}

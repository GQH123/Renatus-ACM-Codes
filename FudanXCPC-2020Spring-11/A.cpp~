#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 200020 
#define ll long long int 
#define M 998244353
#define mo(x) (x = (x >= M) ? (x - M) : x)
using namespace std; 

ll fac[maxn], ifac[maxn], inv[maxn];
void init(){
	fac[0] = ifac[0] = inv[1] = 1;
	srep(i, 1, maxn) fac[i] = fac[i - 1] * i % M;
	srep(i, 2, maxn) inv[i] = M - M / i * inv[M % i] % M;
	srep(i, 1, maxn) ifac[i] = ifac[i - 1] * inv[i] % M;
}
ll get(int m, int n){
	if (m < n) return 0;
	return fac[m] * ifac[n] % M * ifac[m - n] % M;
}

int power(int x, int y){
	int ans = 1, con = x;
	while (y){
		if (y & 1) ans = (ll)ans * con % M;
		con = (ll)con * con % M;
		y >>= 1;
	}
	return ans;
}

int ti;
int num[12], ssum[12];
int dp[12][2049];
int vis[12][2049];
int DP(int pos, int rest){
	if (pos == 12){
		if (rest) return 0;
		else return 1;
	}
	if (vis[pos][rest] == ti) return dp[pos][rest];
	vis[pos][rest] = ti;
	int& ans = dp[pos][rest];
	ans = 0;
	int v = (1 << pos);
	int sum = ssum[pos];
	rep(i, 0, num[pos]){
		if ((ll)rest < (ll)i * v) {
			ans += (ll)sum * DP(pos + 1, 0) % M; 
			mo(ans);
			break;
		}
		else {
			int eff = get(num[pos], i);
			sum = sum + M - eff;
			mo(sum);
			ans += (ll)eff * DP(pos + 1, max(rest - v * i, 0)) % M;
			mo(ans);
		}
	}
	return ans;
}



int n;

int main(){ 
	init();
	int T = 0, x;
	while (scanf("%d", &n), n){	
		int rest = 0;
		ti++;
		printf("Case #%d: ", ++T);
		rep(j, 0, 11) num[j] = 0;
		rep(i, 1, n) {
			scanf("%d", &x);
			bool f = 0;
			rep(j, 0, 11) {
				if (x == (1 << j)) {
					f = 1;
					num[j]++;
					break;
				}
			}
			if (!f) rest++;
		}
		rep(j, 0, 11) ssum[j] = power(2, num[j]);
		int ans = DP(0, 2048);
		ans = (ll) ans * power(2, rest) % M;
		printf("%d\n", ans);
	}
	return 0;
}

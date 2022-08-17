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
#define maxn 20 
using namespace std;

int bc[1 << 10];
void init(){
	bc[0] = 0; srep(i, 1, (1 << 10)) bc[i] = bc[i >> 1] + (i & 1);
}
bool vis[maxn][1 << 10][11][2];
ll dp[maxn][1 << 10][11][2];
inline int upd(int s, int x){
	rep(i, x, 9) if (s & (1 << i)) {s ^= (1 << i); break;}
	s ^= (1 << x);
	return s;
}
ll DP(int len, int s, int k, bool f){
	if (bc[s] > k) return 0;
	if (!len) return f && bc[s] == k;
	if (vis[len][s][k][f]) return dp[len][s][k][f];
	vis[len][s][k][f] = 1;
	ll& ans = dp[len][s][k][f]; ans = 0;
	if (f) rep(i, 0, 9) ans += DP(len - 1, upd(s, i), k, 1); 
	else {	
		rep(i, 1, 9) ans += DP(len - 1, upd(s, i), k, 1);
		ans += DP(len - 1, s, k, 0);
	}
	return ans;
}
int num[maxn], cn = 0;
inline void dep(ll x){
	cn = 0; while (x) num[++cn] = x % 10, x /= 10; 
}
ll cal(ll x, int k){
	dep(x);
	int s = 0; ll ans = 0;
	per(i, cn, 1){
		srep(j, 0, num[i]) {
			bool f = !(i == cn && j == 0);
			ans += DP(i - 1, (f) ? upd(s, j) : s, k, f);
		}
		s = upd(s, num[i]);
	}
	ans += DP(0, s, k, 1);
	return ans;
}

int main(){
	init();
	int T; scanf("%d", &T);
	ll x, y; int k;
	rep(TT, 1, T){
		printf("Case #%d: ", TT);
		scanf("%lld%lld%d", &x, &y, &k);
		printf("%lld\n", cal(y, k) - cal(x - 1, k));
	}
	return 0;
}

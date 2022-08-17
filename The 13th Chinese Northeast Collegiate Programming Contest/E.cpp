#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define maxn 300020
#define pb push_back 
#define pll pair<ll, ll>
#define fi first
#define se second
#define ll long long int 
using namespace std;  

const int inf = 2000000000;

ll mi[maxn], sum[maxn], num[maxn];
int main(){	  
	int T, n;
	ll x, y, z;
	scanf("%d", &T);
	while (T--){ 
		scanf("%d", &n); 
		rep(i, 1, n) mi[i] = inf, sum[i] = 0, num[i] = 0;
		rep(i, 2, n){
			scanf("%lld%lld%lld", &x, &y, &z);
			mi[x] = min(mi[x], z);
			mi[y] = min(mi[y], z);
			sum[x] += z;
			sum[y] += z;
			num[x]++;
			num[y]++;
		}
		ll ans = 0;
		rep(i, 1, n) ans += (ll)(num[i] - 2) * mi[i] + sum[i];
		printf("%lld\n", ans);
	}
	return 0;
}

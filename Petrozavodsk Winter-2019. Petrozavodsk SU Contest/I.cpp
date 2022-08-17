#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define ll long long int 
#define M 1000000007
using namespace std;

ll power(ll a, ll b){
	ll ans = 1,	con = a;
	while (b){
		if (b & 1) ans = ans * con % M;
		con = con * con % M;
		b >>= 1;
	}
	return ans;
}

ll n, m;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("I.in", "r", stdin);
	#endif
	int T;
	scanf("%d", &T);
	while (T--){
		scanf("%lld%lld", &n, &m);
		if (n == 4 && m % 2 == 0) printf("%lld", 2 * power(m, n * n - 2 * n) % M);
		else printf("%lld", power(m, n * n - 2 * n));
		printf("\n");
	}
	return 0;
}

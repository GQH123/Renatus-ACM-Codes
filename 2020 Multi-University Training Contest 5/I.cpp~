#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define ll long long int 
#define M 998244353
using namespace std;

ll power(ll x, ll y){
	ll ans = 1, con = x;
	while (y){
		if (y & 1) ans = ans * con % M;
		con = con * con % M;
		y >>= 1;
	}
	return ans;
}
ll getinv(ll x){
	return power(x, M - 2);
}

int main(){
	int T; ll n; scanf("%d", &T);
	while (T--){
		scanf("%lld", &n);
		/*
		if (n == 0) printf("4\n");
		else if (n == 1) printf("6\n");
		else { 
			ll res = (9ll * power(2, n - 2) % M * (power(4, n) - power(2, n + 1) + M) % M * getinv(power(4, n)) % M + 6) % M;
			printf("%lld\n", res);
		} 
		*/
		printf("%lld\n", (power(2, n) + 1ll + power(3, n) % M * getinv(power(2, n)) % M * 2ll % M) % M);
	}
	return 0;
}

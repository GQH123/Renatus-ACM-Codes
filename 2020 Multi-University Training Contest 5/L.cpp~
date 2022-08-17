#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define ll long long int 
#define M 998244353
#define maxn 6000020
using namespace std;

ll fac[maxn], fac2[maxn], fac22[maxn];
void init(){
	fac[0] = 1, fac2[0] = 1, fac2[2] = 1;
	srep(i, 1, maxn) fac[i] = fac[i - 1] * i % M;
	for (register int i = 4; i < maxn; i += 2) {
		fac2[i] = fac2[i - 2] * (i - 1) % M;
	}
	fac22[0] = 1, fac22[2] = 2;
	for (register int i = 4; i < maxn; i += 2) {
		fac22[i] = fac22[i - 2] * i % M;
	}
}

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
	init();
	int T, n; scanf("%d", &T);
	while (T--){
		scanf("%d", &n);
		int num = (n >> 1);
		rep(i, 1, num) printf("0 ");
		ll invv = getinv(fac22[n - 1]);
		rep(i, num + 1, n){
			if (i != n) printf("%lld ", fac[i - 1] * getinv(fac[i - (n - i) - 1]) % M * fac2[2 * i - n - 1] % M * invv % M);
			else printf("%lld", fac[i - 1] * getinv(fac[i - (n - i) - 1]) % M * fac2[2 * i - n - 1] % M * invv % M);
		}
		printf("\n");
	}
	return 0;
}

#include <bits/stdc++.h>
#define rep(i, l, r) for (register ll i = l; i <= r; i++)
#define per(i, r, l) for (register ll i = r; i >= l; i--)
#define srep(i, l, r) for (register ll i = l; i < r; i++)
#define sper(i, r, l) for (register ll i = r; i > l; i--)
#define maxn 200020
#define ll long long int
#define M     1000000009ll
#define sqrt5 383008016ll
#define inv2  500000005ll
#define mo(x) (x = (x >= M) ? (x - M) : x)
using namespace std;

ll get_inv5(){
	rep(i, 0, M - 1){
		if (1ll * i * i % M == 5) {
			return i;
		}
	}
	assert(false);
}
ll power(ll x, ll y){	
	ll ans = 1, con = x % M;
	y %= (M - 1);
	while (y){
		if (y & 1) ans = 1ll * ans * con % M;
		con = 1ll * con * con % M;
		y >>= 1;
	}
	return ans;
}
ll getinv(ll x){
	if (!x) 
	return power(x, M - 2);
}
ll fac[maxn], ifac[maxn], inv[maxn];
void init(){
	fac[0] = ifac[0] = inv[1] = 1;
	srep(i, 1, maxn) fac[i] = 1ll * fac[i - 1] * i % M;
	srep(i, 2, maxn) inv[i]  = M - 1ll * M / i * inv[M % i] % M;
	srep(i, 1, maxn) ifac[i] = 1ll * ifac[i - 1] * inv[i] % M;
}
inline ll get(ll n, ll m){
	if (n < m) return 0;
	return 1ll * fac[n] * ifac[m] % M * ifac[n - m] % M;
}


int main(){
	//ll inv5 = get_inv5();
	//cerr << inv5 << endl;
	init();
	const ll invsqrt5 = getinv(sqrt5);
	ll T;
	ll n, c, k;
	scanf("%lld", &T);
	while (T--){	
		scanf("%lld%lld%lld", &n, &c, &k);
		ll res = 0;
		ll ph = power((1 - sqrt5 + M) * 1ll * inv2 % M, 1ll * c % (M - 1) * k % (M - 1));
		ll inc = 1ll * power((sqrt5 + 1) * 1ll * inv2 % M, c % (M - 1)) * getinv(power((1 - sqrt5 + M) * 1ll * inv2 % M, c % (M - 1))) % M;
		ll d = (k & 1) ? (M - 1) : 1;
		rep(j, 0, k){
			if (ph == 1) res += 1ll * get(k, j) * d % M * ((n + 1) % M) % M;
			else res += 1ll * get(k, j) * d % M * (power(ph, (n + 1) % (M - 1)) + M - 1) % M * getinv((1ll * ph + M - 1) % M) % M;
			mo(res);
			d = M - d;
			ph = 1ll * ph * inc % M;
		}
		printf("%lld\n", 1ll * res * power(invsqrt5, k) % M);
	} 
	return 0;
}

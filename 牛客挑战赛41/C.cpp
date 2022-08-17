#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define maxn 2000020
#define M 998244353
#define ll long long int 
#define ld lond double
#define pii pair<int, int>
#define fi first
#define se second
#define lowbit(x) (x & -x)
#define mo(x) (x = (x >= M) ? (x - M) : x)
using namespace std;

ll fac[maxn], ifac[maxn], inv[maxn];
void init(){
	fac[0] = ifac[0] = inv[1] = 1;
	srep(i, 1, maxn) fac[i] = fac[i - 1] * i % M;
	srep(i, 2, maxn) inv[i] = M - M / i * inv[M % i] % M;
	srep(i, 1, maxn) ifac[i] = ifac[i - 1] * inv[i] % M;
}
ll getC(int m, int n){
	if (m < n) return 0;
	return fac[m] * ifac[m - n] % M * ifac[n] % M;
}
ll getA(int m, int n){
	return getC(m, n) * fac[n] % M;
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
int n;
char s[maxn];
int main(){
	//cerr << 7 * getinv(3) % M << endl;
	init();
	scanf("%d%s", &n, s + 1);
	int ct2 = 0;
	ll eff = 1, ans = 0;
	rep(i, 1, n){
		if (s[i] == '2') {
			ct2++;
			ans += eff * getA(n - ct2, i - ct2) % M * i % M * getinv(getA(n, i - 1)) % M, mo(ans);
			//cerr << ans << endl;
			eff = eff * (i - ct2) % M;
		}
		if (i == n) ans += eff * getA(n - ct2, n - ct2) % M * n % M * getinv(getA(n, n)) % M, mo(ans);
	}
	
	printf("%lld", ans);
	return 0;
}

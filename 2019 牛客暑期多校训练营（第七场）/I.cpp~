#include <bits/stdc++.h>
#define maxr 100000
#define maxn 5019
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define mo(x) x = (x >= M) ? (x - M) : x
#define M 998244353
#define ll long long int 
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}

int fac[maxn];
int ifac[maxn];
int inv[maxn];
void init(){
	fac[0] = ifac[0] = inv[1] = 1;
	srep(i, 1, maxn) fac[i] = (ll)fac[i - 1] * i % M;
	srep(i, 2, maxn) inv[i] = M - M / i * (ll)inv[M % i] % M;
	srep(i, 1, maxn) ifac[i] = (ll)ifac[i - 1] * inv[i] % M;
}
int C(int n, int m){
	if (n < m) return 0;
	return (ll)fac[n] * ifac[m] % M * ifac[n - m] % M;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("I.in", "r", stdin);
	#endif
	init();
	int T;
	read(T);
	while (T--){
		ll ans = 0;
		int n, m;
		read(n), read(m);
		int bound = n / m;
		rep(k, 1, bound){
			int bound2 = n - m * k, _k = (k << 1) - 1;
			rep(A, 0, bound2){
				ans += C(A + _k, _k), mo(ans);
				ans += (M - C(A + k - 1, _k)), mo(ans);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}

#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int
#define maxn 400020
#define maxm 
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define M 998244353
using namespace std;

int n, p, q;
int a[maxn];

ll power(ll x, ll y){
	ll ans = 1, con = x;
	while (y){
		if (y & 1) ans = ans * con % M;
		con = con * con % M;
		y >>= 1;
	}
	return ans;
}
ll get_inv(ll x){
	return power(x, M - 2);
}
ll P, Q, inv;

int main(){
	freopen("J.in", "r", stdin);
	scanf("%d%d%d", &n, &p, &q);
	inv = get_inv(1000000);
	P = p * inv % M;
	Q = q * inv % M;
	rep(i, 1, n) scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n);
	ll ans = 0;
	rep(i, 1, n){
	 	ll d = 1;
		if (i > 1 && a[i - 1] == a[i] - 1) d = d * (1 + M - Q), d %= M;
		if (i < n && a[i + 1] == a[i] + 1) d = d * (1 + M - P), d %= M;
		d = d * (P + Q), d %= M;
		ans += (1 + M - d) % M, ans %= M;
	}
	printf("%lld", ans);
	return 0;
}


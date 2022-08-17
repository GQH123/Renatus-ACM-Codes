#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 300020
#define M 1000000007
#define ll long long int 
#define mo(x) (x = (x >= M) ? (x - M) : x)
using namespace std;

ll power(ll x, ll y){
	ll ans = 1, con = x;
	while (y) {	
		if (y & 1) ans = ans * con % M;
		con = con * con % M;
		y >>= 1;
	}
	return ans;
}
ll getinv(ll x){
	return power(x, M - 2);
}

int p[maxn], cp = 0;
bool vis[maxn];

int mu[maxn], f[maxn], poww[maxn], S[maxn], F[maxn], pre[maxn];

void init(int t, int x){
	mu[1] = 1;
	srep(i, 2, maxn) {
		if (!vis[i]) p[++cp] = i, mu[i] = -1;
		rep(j, 1, cp) {
			if (i * p[j] >= maxn) break;
			vis[i * p[j]] = 1;
			if (i % p[j] == 0) {
				mu[i * p[j]] = 0;
				break;
			}
			mu[i * p[j]] = -mu[i];
		}
	}
	srep(i, 1, maxn) f[i] = abs(mu[i]), mu[i] += M, mo(mu[i]);
	srep(i, 1, maxn) poww[i] = power(i, 1ll * t * x % (M - 1));
	srep(i, 1, maxn) {
		for (register int j = i; j < maxn; j += i) {	
			F[j] += 1ll * f[i] * i % M * mu[j / i] % M;
			mo(F[j]);
		}
	}
	srep(i, 1, maxn) pre[i] = pre[i - 1] + 1ll * poww[i] * F[i] % M, mo(pre[i]);
	srep(i, 1, maxn) S[i] = S[i - 1] + power(i, t), mo(S[i]);
	srep(i, 1, maxn) S[i] = power(S[i], x);
}

void play(int n){	
	ll res = 0;
	rep(i, 1, n){
		int nxt = min(n, (n / (n / i)));
		res += 1ll * (1ll * pre[nxt] - pre[i - 1] + M) % M * S[n / i] % M;
		mo(res);
		i = nxt;
	}
	printf("%lld\n", res);
}

int t, x;
int main(){
	int T, n; scanf("%d%d%d", &T, &t, &x); 
	init(t, x);
	while (T--) scanf("%d", &n), play(n);
	return 0;
}

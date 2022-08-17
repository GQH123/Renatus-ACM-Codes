#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define maxn 600020
#define maxm
#define pii pair<int, int>
#define M 998244353
#define ll long long int 
#define mo(x) (x = (x >= M) ? (x - M) : x)
using namespace std;

int n, a[maxn];
int main(){
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", a + i);
	sort(a + 1, a + 1 + n);
	ll ans = 0;
	rep(i, 1, n >> 1) ans += a[i], ans %= M;
	rep(i, (n >> 1) + 1, n) ans = ans * a[i] % M;
	printf("%lld", ans);
	return 0;
}

#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define maxn 200020
#define maxm 
#define M 
#define ll unsigned long long int 
#define ld long double
#define pb push_back
#define pc putchar
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define lowbit(x) (x & -x)
using namespace std;

int n, a[maxn];
int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		scanf("%d", &n); rep(i, 1, n) scanf("%d", a + i);
		sort(a + 1, a + 1 + n);
		ll sum = 0;
		rep(i, 1, n) sum += a[i];
		ll res = 0;
		rep(i, 1, n){
			sum -= a[i];
			res += sum - 1ll * (n - i) * a[i];
		}
		printf("%llu\n", res);
	} 
	return 0;
}

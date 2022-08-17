#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
#define maxn 3020
#define maxm
#define M 1000000007
#define mo(x) (x = (x >= M) ? (x - M) : x)
using namespace std;

int n, w[maxn], a[maxn];
ll num[maxn], fac[maxn];
bool vis[maxn];
int main(){	
	fac[0] = 1;
	srep(i, 1, maxn) fac[i] = fac[i - 1] * i % M;
	int T; scanf("%d", &T);
	rep(TT, 1, T){
		printf("Case #%d: ", TT);
		scanf("%d", &n);
		rep(i, 1, n) vis[i] = num[i] = 0;
		rep(i, 1, n) scanf("%d", w + i);
		rep(i, 1, n) scanf("%d", a + i); 
		ll sufs = 0;
		rep(i, 1, n){ 
			rep(j, a[i], n){
				num[j]++, sufs++;
			}
		}
		ll now = 0; ll ans = 0;
		rep(i, 0, n){ 
			//ans += 1ll * fac[n - i] * now % M, mo(ans);
			/*
			rep(j, 1, w[i + 1]) {	
				if (vis[j]) continue;
				sufs -= (j >= a[i + 1]); 
				num[j] -= (j >= a[i + 1]); 
			}
			*/
			rep(j, a[i + 1], n) if (!vis[j]) sufs -= (j >= a[i + 1]), num[j] -= (j >= a[i + 1]);
			rep(j, w[i + 1] + 1, n){
				if (vis[j]) continue;
				if (n - i - 2 >= 0) {
					ans += (now + (j >= a[i + 1])) * fac[n - i - 1] % M, mo(ans);
					ans += (sufs - num[j]) * fac[n - i - 2] % M, mo(ans);	
				}
				else {
					ans += (now + (j >= a[i + 1])) * fac[n - i - 1] % M, mo(ans);
					ans += (sufs - num[j]) % M, mo(ans);	
				}
			}
			//ans += 1ll * fac[n - i - 1] * sufs % M, mo(ans); 
			now += (w[i + 1] >= a[i + 1]);
			/*
			rep(j, w[i + 1] + 1, n) {
				if (vis[j]) continue;
				sufs -= (j >= a[i + 1]);
			}
			*/
			vis[w[i + 1]] = 1;
			sufs -= num[w[i + 1]];
		}
		printf("%lld\n", ans);
	} 
	return 0;
}

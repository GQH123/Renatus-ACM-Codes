#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define maxn 6020
#define maxm 
#define M 
#define ll long long int 
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

int m, n; char s[maxn];
int a[maxn];

int main(){
	int T; scanf("%d", &T);
	while (T--){
		scanf("%d", &m);
		scanf("%s", s + 1);
		n = strlen(s + 1);
		int res = 0;
		rep(i, 1, n) {
			rep(j, i, n) a[j] = abs((int)s[j] - (int)s[n + i - j]);
			//j, n + i - j
			int r = i, now = 0; //not conform [l, r)
			rep(l, i, n){
				if (l >= n + i - l) break;
				while (r < n + i - r && now <= m) now += a[r], r++;
				if (now > m) res = max(res, r - l - 1);
				else res = max(res, r - l);
				now -= a[l];
			}
		}
		reverse(s + 1, s + 1 + n);
		rep(i, 1, n) {
			rep(j, i, n) a[j] = abs((int)s[j] - (int)s[n + i - j]);
			//j, n + i - j
			int r = i, now = 0; //not conform [l, r)
			rep(l, i, n){
				if (l >= n + i - l) break;
				while (r < n + i - r && now <= m) now += a[r], r++;
				if (now > m) res = max(res, r - l - 1);
				else res = max(res, r - l);
				now -= a[l];
			}
		}
		printf("%d\n", res); 
	} 
	return 0;
}

#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 64
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int num[maxn];
int cn = 0;
ll suf[maxn];

int main(){

		freopen("E.in", "r", stdin);
		
	int T;
	ll k, n;
	scanf("%d", &T);
	while (T--){
		scanf("%lld%lld", &n, &k);
		cn = 0;
		while (n) {
			num[++cn] = n & 1;
			n >>= 1;
		}
		rep(i, 1, cn) suf[i] = suf[i - 1] + ((ll)num[i] << (i - 1));
		ll mx = 0, now = 0;
		per(i, cn, 1){
			if (num[i] == 0){
				now = (now << 1) + num[i];
				if (suf[i - 1] + 1 + ((1ll << i) - 2) >= k) mx = max(mx, now);
				if ((1ll << (i - 1)) + ((1ll << (i - 1)) - 1) >= k) mx = max(mx, now - 1);
				if ((1ll << i) + ((1ll << i) - 2) >= k) mx = max(mx, now - 2);
			}
			else {
				now = (now << 1);
				if (suf[i - 1] + 1 + (1ll << (i - 1)) + ((1ll << i) - 2) >= k) mx = max(mx, now);
				if ((1ll << (i - 1)) + ((1ll << (i - 1)) - 1) >= k) mx = max(mx, now - 1);
				if ((1ll << i) + ((1ll << i) - 2) >= k) mx = max(mx, now - 2);
				now++;
				if (suf[i - 1] + 1 + ((1ll << (i - 1)) - 1) >= k) mx = max(mx, now);
			}
		}
		printf("%lld\n", mx);
	}
	return 0;
}

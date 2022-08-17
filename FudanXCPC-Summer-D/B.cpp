#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 300020
#define maxm 
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define pc putchar
#define ll long long int 
#define ld long double 
#define lowbit(x) (x & -x)
#define M 
#define mo(x) (x = (x >= M) ? (x - M) : x)
using namespace std;

ll k, m, n, p;
ll a[maxn], v[maxn];
int main(){
	while (scanf("%lld%lld%lld%lld", &k, &m, &n, &p) == 4){
		rep(i, 1, k) scanf("%lld", a + i);
		sort(a + 1, a + 1 + k);
		ll nownum = n, ptr = 1;
		__int128 res = 0;
		per(j, m - 1, 1){
			rep(i, 1, nownum){
				v[ptr] = ((__int128)a[ptr] + v[(ptr - 1) / n]) % p;
				res += v[ptr], res %= p;
				ptr++;
			}
			nownum *= n;
		}
		printf("%lld\n", (ll)res);
	}
	return 0;
}

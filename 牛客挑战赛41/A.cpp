#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define maxn
#define ll long long int 
#define ld lond double
#define pii pair<int, int>
#define fi first
#define se second
#define lowbit(x) (x & -x)
#define mo(x) (x = (x >= M) ? (x - M) : x)
using namespace std;

int main(){
	int T;
	ll n, m, k;
	scanf("%d", &T);
	while (T--){	
		scanf("%lld%lld%lld", &n, &m, &k);
		if (!(k & 1)){
			printf("%lld\n", (n + 2 * m - 1) / k);
		}
		else {
			ll each = k / 2;
			ll num = (m - 1) / each; 
			if (n < num){
				printf("%lld\n", num);
			}
			else {
				printf("%lld\n", (n + 2 * m - 1) / k);
			}
		}
		
	}

	return 0;
}

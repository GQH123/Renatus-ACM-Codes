#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define maxn 300020
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

int n, a[maxn], ran[maxn];
pii lis[maxn];
int b[maxn], cb = 0;
int main(){
	int T; scanf("%d", &T);
	while (T--){
		scanf("%d", &n); rep(i, 1, n) scanf("%d", a + i), lis[i] = pii(a[i], i);
		sort(lis + 1, lis + 1 + n);
		rep(i, 1, n) ran[lis[i].se] = i;
		bool first = 1;
		rep(i, 2, n) {
			cb = 0;
			for (register int j = i; j <= n; j += i) b[++cb] = ran[j];
			sort(b + 1, b + 1 + cb);
			int ptr = n;
			per(j, cb, 1){
				if (b[j] == ptr) ptr--;
				else {
					if (first) first = 0;
					else printf(" ");
					printf("%d", lis[ptr].fi);
					goto done; 
				}
			}
			if (first) first = 0;
			else printf(" ");
			printf("%d", lis[ptr].fi);
			done:;
		}
		printf("\n");
	}
	return 0;
}

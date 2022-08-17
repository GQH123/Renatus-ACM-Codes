#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define pii pair<int, int>
#define maxn 220
#define fi first
#define se second
using namespace std;

pii a[maxn];
int n, m, k;

int main(){
	int T, x; scanf("%d", &T);
	while (T--){
		scanf("%d%d%d", &n, &m, &k);
		rep(i, 1, n) scanf("%d", &x), a[i] = pii(-x, i);
		if (k == 0) {
			rep(i, 1, n) {if (i != 1) printf(" "); printf("%d", i);}
			printf("\n");
			continue;
		} 
		sort(a + 1, a + 1 + n);
		rep(i, 1, n) {if (i != 1) printf(" "); printf("%d", a[i].se);}
		printf("\n");
	}
	return 0;
}

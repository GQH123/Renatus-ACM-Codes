#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
#define maxn 300020
using namespace std;

int n, k, a[2][maxn];

int main(){ 
	scanf("%d%d", &n, &k);
	rep(i, 1, n) scanf("%d", a[0] + i);
	int d = 0;
	while (k--){ 
		rep(i, 1, n) a[d ^ 1][i] = 0;
		rep(i, 1, n){
			a[d ^ 1][max(i - a[d][i], 1)]++;
			a[d ^ 1][min(n + 1, i + a[d][i] + 1)]--;
		}
		d ^= 1;
		rep(i, 1, n) a[d][i] += a[d][i - 1];	
		bool f = 1;
		rep(i, 1, n) if (a[d][i] != a[d ^ 1][i]) {f = 0; break;}
		if (f) break;
	}
	rep(i, 1, n) printf("%d ", a[d][i]);
	return 0;
}



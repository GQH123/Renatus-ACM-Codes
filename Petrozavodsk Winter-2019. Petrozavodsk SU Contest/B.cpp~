#include <bits/stdc++.h>
#define maxn 1019
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
using namespace std;
int n;
int a[maxn];
int ans[maxn][maxn];

int main(){
	#ifndef ONLINE_JUDGE
		freopen("B.in", "r", stdin);
	#endif
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]);
	int m = (n << 1) - 1;
	rep(i, 1, n) ans[1][i] = a[i];
	rep(i, n + 1, m) ans[1][i] = a[i - n];
	rep(i, 2, m){
		rep(j, 1, n){
			if (j + 1 <= n) ans[i][j] = ans[i - 1][j + 1];
			else ans[i][j] = ans[i - 1][1];
		}
		rep(j, n, m){	
			if (j + 1 <= m) ans[i][j] = ans[i - 1][j + 1];
			else ans[i][j] = ans[i - 1][n];
		}
	}
	printf("%d\n", m);
	rep(i, 1, m) {rep(j, 1, m) printf("%d ", ans[i][j]); printf("\n");}
	return 0;
}

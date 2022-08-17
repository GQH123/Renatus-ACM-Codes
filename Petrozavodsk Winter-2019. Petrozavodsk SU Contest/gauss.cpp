#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 2019
#define eps 1e-7
using namespace std;

double mat[maxn][maxn];

int gauss(int n){
	int now = 1;
	rep(j, 1, n){
		rep(i, now, n){
			bool f = 0;
			if (mat[i][j] > eps || mat[i][j] < -eps) swap(mat[i], mat[now]), f = 1;
			if (!f) continue;
			rep(i, now + 1, n){
				if (mat[i][j]) {
					double d = mat[i][j] / mat[now][j];
					rep(k, 1, n) mat[i][k] -= mat[now][k] * d;
				}
			}
			now++;
		}
	}
	return now - 1;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("gauss.in", "r", stdin);
	#endif
	int k;
	scanf("%d", &k);
	rep(n, 1, k){
		int m = n * n;
		rep(i, 1, n - 1) {
			rep(k, n * (i - 1) + 1, n * i) mat[i][k] = 1;
		}
		rep(i, 1, n){
			for (register int k = i; k <= m; k += n){
				mat[i + n][k] = 1;
			}
		}
		rep(i, 1, n) mat[2 * n + 1][(i - 1) * n + i] = 1;
		rep(i, 1, n) mat[2 * n + 2][i * n - (i - 1)] = 1;
		printf("%d %d\n", n, gauss(m));
		rep(i, 1, m + 10) rep(j, 1, m + 10) mat[i][j] = 0;
	}
	return 0;
}

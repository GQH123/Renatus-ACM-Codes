#include <bits/stdc++.h>
#define maxn 2048
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
using namespace std;

int mat[maxn][maxn];

void solve(int n){
	if (n == 2){
		mat[1][1] = 1;
		mat[1][2] = 1;
		mat[2][1] = 1;
		mat[2][2] = -1;
		return;
	}
	solve(n >> 1);
	int x = n >> 1;
	rep(i, 1, x) rep(j, 1, x) mat[i][j + x] = -mat[i][j];
	rep(i, 1, x) rep(j, 1, x) mat[i + x][j] = -mat[i][j];
	rep(i, 1, x) rep(j, 1, x) mat[i + x][j + x] = -mat[i][j];
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("C.in", "r", stdin);
	#endif
	int n;
	scanf("%d", &n);
	solve(n);
	rep(i, 1, n){ {rep(j, 1, n) printf("%d ", mat[i][j]);} printf("\n");}
	return 0;
}

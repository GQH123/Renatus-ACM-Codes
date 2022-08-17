#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
using namespace std;

int n, m, q;
int w[maxn][maxn];
int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		scanf("%d%d%d", &n, &m, &q);
		rep(i, 1, n) rep(j, 1, m) scanf("%d", &w[i][j]);
		
	}
	return 0;
}

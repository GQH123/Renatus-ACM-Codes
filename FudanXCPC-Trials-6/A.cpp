#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
#define maxn 1020
#define maxm
#define lowbit(x) (x & -x)
using namespace std;

int n, a[maxn][maxn], l[maxn][maxn], r[maxn][maxn], u[maxn][maxn], d[maxn][maxn];

ll c[maxn][maxn];
void add(int x, int y, int v){
	int _y = y;
	while (x <= n) {
		while (y <= n) {
			c[x][y] += v;
			y += lowbit(y);
		}
		x += lowbit(x);
		y = _y;
	}
}
int get(int x, int y){
	int ans = 0, _y = y;
	while (x){
		while (y){
			ans += c[x][y];
			y -= lowbit(y);
		}
		x -= lowbit(x);
		y = _y;
	}
	return ans;
}

int main(){
	int T; scanf("%d", &T);
	rep(TT, 1, T){
		printf("Case %d: ", TT);
		scanf("%d", &n);
		rep(i, 1, n) rep(j, 1, n) scanf("%d", &a[i][j]);
		rep(i, 1, n) rep(j, 1, n) {
			l[i][j] = (a[i][j] && j > 1) ? l[i][j - 1] + 1 : a[i][j];
			u[i][j] = (a[i][j] && i > 1) ? u[i - 1][j] + 1 : a[i][j];
		}
		per(i, n, 1) per(j, n, 1){
			r[i][j] = (a[i][j] && j < n) ? r[i][j + 1] + 1 : a[i][j];
			d[i][j] = (a[i][j] && i < n) ? d[i + 1][j] + 1 : a[i][j];
		}
		ll res = 0;
		rep(dd, -n + 1, n - 1){ 
			ll _res = res;
			per(i, n, 1){
				if (i + dd < 1 || i + dd > n) continue;
				if (!a[i][i + dd]) continue;
				int j = i + dd;
				int v = min(u[i][j], l[i][j]);
				add(i - v + 1, i, 1);
				int _v = min(d[i][j], r[i][j]);
				res += get(i, i + _v - 1);
			}
			per(i, n, 1){
				if (i + dd < 1 || i + dd > n) continue;
				if (!a[i][i + dd]) continue;
				int j = i + dd;
				int v = min(u[i][j], l[i][j]);
				add(i - v + 1, i, -1); 
			}
			//cout << res - _res << endl;
		}
		printf("%lld\n", res);
	}
	return 0;
}

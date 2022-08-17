#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 105
#define maxm 20020
#define M 998244353
#define mo(x) (x = (x >= M) ? (x - M) : x) 
#define ll long long int 
using namespace std;

ll power(ll x, ll y){
	ll ans = 1, con = x;
	while (y) {	
		if (y & 1) ans = ans * con % M;
		con = con * con % M;
		y >>= 1;
	}
	return ans;
}
ll getinv(ll x){
	return power(x, M - 2);
}

int n, m;
struct edge{
	int x, y, w;
	edge(int x, int y, int w) : x(x), y(y), w(w){}
	edge(){}
}e[maxm << 1];

int g[maxn][maxn];

ll cal(){
	int now = 1;
	int f = 1;
	ll res = 1;
	rep(j, 1, n - 1){	
		int flag = -1;
		rep(i, now, n - 1) if (g[i][j]) {flag = i; break;} 
		if (flag == -1) continue;
		if (flag != now) f = -f, swap(g[flag], g[now]);
		rep(i, 1, n - 1) {
			if (i == now) continue;
			ll d = 1ll * g[i][j] * getinv(g[now][j]) % M;
			rep(k, j, n - 1) {
				g[i][k] += M - d * g[now][k] % M;
				mo(g[i][k]);
			}
		}
		now++;
	}
	rep(i, 1, n - 1) res = res * g[i][i] % M;
	return (M + f * res) % M;
}

int main(){
	int T, x, y, w; scanf("%d", &T);
	while (T--){
		scanf("%d%d", &n, &m);
		int mx = 0;
		ll all = 0;
		rep(i, 1, n) rep(j, 1, n) g[i][j] = 0;
		rep(i, 1, m) {
			scanf("%d%d%d", &x, &y, &w), mx = max(mx, w);
			e[i] = edge(x, y, w);
			g[x][y]++, g[y][x]++;
			g[x][x] += M - 1, mo(g[x][x]);
			g[y][y] += M - 1, mo(g[y][y]);
		}
		all = cal();
		ll invall = getinv(all);
		
		int s = 0;
		while (mx) mx >>= 1, s++;
		ll res = 0;
		srep(bit, 0, s){
			ll hav = 0;
			rep(i, 1, n) rep(j, 1, n) g[i][j] = 0;
			rep(i, 1, m) {
				if (!(e[i].w & (1ll << bit))) continue;
				x = e[i].x, y = e[i].y;
				g[x][y]++, g[y][x]++;
				g[x][x] += M - 1, mo(g[x][x]);
				g[y][y] += M - 1, mo(g[y][y]);
			}
			hav = cal();
			res += hav * (1ll << bit) % M, mo(res);
		}
		
		printf("%lld\n", res * invall % M);
	}
	return 0;
}

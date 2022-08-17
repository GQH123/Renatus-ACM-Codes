#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 3020
#define ll long long int 
using namespace std;

int n, m = 0;
int x[maxn], y[maxn];
bool vis[maxn];

struct edge{
	int x, y; ll d;
	edge(int x, int y, ll d) : x(x), y(y), d(d){}
	edge(){}
	bool operator < (const edge b) const{
		return d > b.d;
	}
}e[maxn * maxn];

int main(){
	int T; scanf("%d", &T);
	while (T--){
		m = 0;
		scanf("%d", &n);
		rep(i, 1, n) vis[i] = 0;
		rep(i, 1, n) scanf("%d%d", x + i, y + i);
		rep(i, 1, n){
			rep(j, i + 1, n){
				e[++m] = edge(i, j, 1ll * (x[i] - x[j]) * (x[i] - x[j]) + 1ll * (y[i] - y[j]) * (y[i] - y[j]));
			}
		}
		sort(e + 1, e + 1 + m);
		rep(i, 1, m){
			int x = e[i].x, y = e[i].y;
			if (vis[x] || vis[y]) continue;
			vis[x] = vis[y] = 1;
			if (x == 1 || y == 1){
				printf("YES\n");
				goto done;
			}
		} 
		printf("NO\n");
		done:;
	}
	return 0;
}

#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 2020
#define ll long long int 
using namespace std;

bool vis[maxn];

struct edge{
	int x, y, w;
	edge(int x, int y, int w) : x(x), y(y), w(w){}
	edge(){}
	bool operator < (const edge b) const{
		return w > b.w;
	}
}p[maxn * maxn];

int main(){
	int n;
	scanf("%d", &n); 
	int m = n * (n - 1) / 2; 
	rep(i, 1, m) scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].w);
	sort(p + 1, p + 1 + m);
	ll ans = 0;
	rep(i, 1, m){
		int x = p[i].x, y = p[i].y, w = p[i].w;
		int ct = 0;
		if (!vis[x]) vis[x] = 1, ct++;
		else vis[x] = 0;
		if (!vis[y]) vis[y] = 1, ct++;
		else vis[y] = 0;
		ans += (ll)ct * w;
	}
	printf("%lld", ans);
	return 0;
}

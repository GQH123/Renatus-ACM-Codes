#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define maxn 200020
#define pb push_back 
#define pll pair<ll, ll>
#define fi first
#define se second
#define ll long long int 
#define lowbit(x) (x & -x)
#define maxm 
using namespace std;   


int n, m, l[maxn];
vector<ll> obj[maxn];

ll c[maxn];
void add(int x, ll v){	
	while (x <= n){
		c[x] += v;
		x += lowbit(x);
	}
}
ll get(int x){
	ll ans = 0;
	while (x){
		ans += c[x];
		x -= lowbit(x);
	}
	return ans;
}

ll gcd(ll x, ll y){
	if (!y) return x;
	return gcd(y, x % y);
}

int main(){	  
	int T, x, y;
	scanf("%d", &T);
	while (T--){ 
		scanf("%d%d", &n, &m);
		rep(i, 1, m) scanf("%d", l + i);
		rep(i, 1, n){
			scanf("%d%d", &x, &y);
			obj[y].pb(x);
		}
		rep(i, 1, m){
			if (obj[i].empty()) continue;
			sort(obj[i].begin(), obj[i].end());
			int si = obj[i].size();
			ll sum = 0;
			per(j, si - 1, 0){
				sum += obj[i][j];
				if (si - j < l[i]) continue;
				if (si - j == l[i]){
					add(si - j, sum); 
				}
				else {
					add(si - j, obj[i][j]); 
				}
			}
			obj[i].clear();
		}
		ll ansx = 0, ansy = 0;
		ll resx = -1, resy = -1;
		rep(i, 1, n){
			ansy = i;
			ansx = get(i);
			if (resy == -1) resx = ansx, resy = ansy;
			else {
				if (resy * ansx > resx * ansy) resx = ansx, resy = ansy;
			}
		}
		
		rep(i, 1, n) c[i] = 0;
		if (resy == -1){
			printf("0/1\n");
			continue;
		}
		else {
			ll d = gcd(resx, resy);
			printf("%lld/%lld\n", resx / d, resy / d);
		}
	}
	return 0;
}

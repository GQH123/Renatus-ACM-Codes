#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define ll long long int 
#define pll pair<ll, ll>
using namespace std;

ll self = 0, sum = 0;
ll stx, sty;
set<pll> vis;
ll gcd(ll x, ll y){
	return (!y) ? x : gcd(y, x % y);
}
inline bool ok(ll x, ll y){
	return 0 <= x && 0 <= y;
}
bool dfs(ll x, ll y){
	if (x == y) return false;
	vis.insert(pll(x, y));
	rep(i, -1, 1){
		rep(j, -1, 1){
			if (ok(x + i, y + j) && gcd(x + i, y + j) > 1) {
				sum++;
				if (stx == x + i && sty == y + j) self++;
			}
		}
	}
	rep(i, -1, 1){
		rep(j, -1, 1){
			if (!i && !j) continue;
			if (ok(x + i, y + j) && gcd(x + i, y + j) > 1 && !vis.count(pll(x + i, y + j))) {
				if (!dfs(x + i, y + j)) return false;
			}
		}
	}
	return true;
}

int main(){
	int T; scanf("%d", &T);
	while (T--){
		self = sum = 0; vis.clear();
		scanf("%lld%lld", &stx, &sty);
		if (!dfs(stx, sty)) printf("0/1\n");
		else {
			ll d = gcd(self, sum);
			self /= d, sum /= d;
			printf("%lld/%lld\n", self, sum);
		} 
	}
	return 0;
}

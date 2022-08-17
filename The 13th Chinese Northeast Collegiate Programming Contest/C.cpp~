#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define maxn 300020
#define pb push_back 
#define pll pair<ll, ll>
#define fi first
#define se second
#define ll long long int 
using namespace std; 

ll gcd(ll x, ll y){
	if (!y) return x;
	return gcd(y, x % y);
}

struct line{
	ll x, y, r;
	line(ll x, ll y, ll r) : x(x), y(y), r(r){}
	line(){}
	bool operator < (const line b) const{
		return (x == b.x) ? ((y == b.y) ? (r < b.r) : (y < b.y)) : x < b.x;
	}
};
map<pll, int> ss;
map<line, int> s;
int main(){	 
	int T, n;
	ll x, y, a, b, ans = 0;
	scanf("%d", &T);
	while (T--){
		ans = 0;
		s.clear(), ss.clear();
		scanf("%d", &n);
		rep(i, 1, n) {
			scanf("%lld%lld%lld%lld", &x, &y, &a, &b);
			ll _x = x - a, _y = y - b;
			ll d = gcd(abs(_x), abs(_y));
			_x /= d, _y /= d;
			if (_x < 0) _x = -_x, _y = -_y;
			if (_x == 0) {
				if (_y < 0) _y = -_y;
			}
			
			line op = line(_x, _y, _y * a - _x * b);
			ans += i - 1 - (ss[pll(_x, _y)] - s[op]);
			s[op]++, ss[pll(_x, _y)]++;
		}
		printf("%lld\n", ans);
	}
	return 0;
}

#include <bits/stdc++.h>
#define maxr 100000
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define ll long long int 
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}

ll gcd(ll x, ll y){
	return (!y) ? x : gcd(y, x % y);
}
void exgcd(ll& x, ll& y, ll a, ll b, ll p){
	if (!b) {x = p / a, y = 0; return;}
	exgcd(y, x, b, a % b, p);
	y -= a / b * x;
	return;
}
int main(){
	#ifndef ONLINE_JUDGE
		freopen("C.in", "r", stdin);
	#endif
	ll n, p, w, d;
	read(n), read(p), read(w), read(d);
	ll _d = gcd(w, d);
	if (_d && p % _d != 0) {
		printf("-1");
		return 0;
	}
	if (_d) w /= _d, d /= _d, p /= _d;
	if (n * w < p && n * d < p) {
		printf("-1");
		return 0;
	}
	ll x = 0, y = 0;
	exgcd(x, y, w, d, p);
	if (x < 0 || y < 0 || x + y > n){	
		
		ll __x = x, __y = y;
	
		ll _x = x / d * d;
		x %= d;
		y = y + _x / d * w;
		if (x + y <= n){
			printf("%lld %lld %lld", x, y, n - x - y);
			return 0;
		}
		x = __x, y = __y;
		
		ll _y = y / w * w;
		y %= w;
		x = x + _y / w * d;
		if (x + y <= n){
			printf("%lld %lld %lld", x, y, n - x - y);
			return 0;
		}
	}
	else {
		printf("%lld %lld %lld", x, y, n - x - y);
		return 0;
	}
	printf("-1");
	return 0;
}

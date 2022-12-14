#include <bits/stdc++.h>
#define maxr 100000
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define ll long long int 
#define pll pair<ll, ll>
#define mo(x, M) x = (x >= M) ? (x - M) : x
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}
ll p, x;
ll gcd(ll x, ll y){
	return (!y) ? x : gcd(y, x % y);
}
pll getans(ll a, ll b, ll c, ll d){
	ll t = a / b, t1 = c / d - ((c % d) ? 0 : 1);
	if (t1 > t){
		return pll(a / b + 1, 1);
	}
	else if (a == t * b){
		return pll(1 + t + d / (c - d * t) * t, d / (c - d * t) + 1);
	}
	else {
		//pll op = getans(b, a - t * b, d, c - t * d);
		pll op = getans(d, c - t * d, b, a - t * b);
		return pll(op.second + t * op.first, op.first);
	}
}

ll fast_mult(ll a, ll b, ll p){
	ll ans = 0, con = a;
	while (b){
		if (b & 1) ans = ans + con, mo(ans, p);
		con = con + con, mo(con, p);
		b >>= 1;
	}
	return ans;
}
	
int main(){
	#ifndef ONLINE_JUDGE
		freopen("A.in", "r", stdin);
	#endif
	int T;
	read(T);
	while (T--){
		read(p), read(x);
		pll ans = getans(p, x, p, x - 1);
		ll d = gcd(ans.first, ans.second);
		ans.first /= d, ans.second /= d;
		ll b = ans.first;
		ll a = fast_mult(b, x, p);
		d = gcd(a, b);
		printf("%lld/%lld\n", a / d, b / d);
	}
	return 0;
}

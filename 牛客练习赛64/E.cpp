#include <bits/stdc++.h>
#define maxn 2000020
#define maxm
#define maxb
#define maxr 200000
#define maxs 
#define ll long long int
#define lowbit(x) x & -x
#define fi first
#define se second
#define pb push_back
#define next NEXT
#define hash HASH
#define ls ch[x][0]
#define rs ch[x][1]
#define pi 3.141592653589793
#define ei 2.718281828459045
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
//#define ONLINE_JUDGE
//#define DEBUG
using namespace std;

char *p1, *p2, buffer[maxr];
template <class T> void read(T& x){
    char ch = gc(); x = 0; bool f = 1;
    while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
    if (ch == '-') f = 0, ch = gc();
    while ('0' <= ch && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = gc();
    x = f ? x : -x;
}

ll n, m, d, sx, sy, ex, ey, a, b, c;

ll gcd(ll x, ll y){
	if (!y) return x;
	return gcd(y, x % y);
}

ll p[maxn], vp[maxn], cp = 0;
void init(){
	srep(i, 2, maxn) {
		if (!vp[i]) p[++cp] = i;
		rep(j, 1, cp){
			if (i * p[j] >= maxn) break;
			vp[i * p[j]] = 1;
			if (i % p[j] == 0) break;
		}
	}
}

ll getphi(ll x){
	ll ans = 1;
	rep(i, 1, cp){	
		if (p[i] * p[i] > x) break;
		if (x % p[i] == 0) {
			ans *= (p[i] - 1);
			x /= p[i];
			while (x % p[i] == 0) {
				ans *= p[i];
				x /= p[i];
			}
		}
	}
	if (x > 1) ans *= (x - 1);
	return ans;
}

ll power(ll x, ll y, ll M){
	ll ans = 1, con = x;
	while (y){
		if (y & 1) ans = (ll)ans * con % M;
		y >>= 1;
		con = (ll)con * con % M;
	}
	return ans;
}

ll getinv(ll x, ll y){
	return power(x, getphi(y) - 1, y);
}

ll exCRT(ll c1, ll m1, ll c2, ll m2){
	ll _m = gcd(m1, m2);
	if (abs(c2 - c1) % _m != 0) return -1;
	ll _v = (c2 - c1) / _m;
	ll _m1 = m1 / _m, _m2 = m2 / _m;
	_v = ((_v % _m2) + _m2) % _m2;
	ll k = (ll)getinv(_m1, _m2) * _v % _m2;
	ll _mm = (ll)m1 * m2 / _m;
	return (c1 + (ll)m1 * k % _mm) % _mm;
}

int main(){
	init();
	ll T;
	scanf("%lld", &T);
	while (T--){
		scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld", &n, &m, &d, &sx, &sy, &ex, &ey, &a, &b, &c);
		ll g = gcd(n, m);
		ll vs = ((sx - sy) % g + g) % g;
		ll ve = ((ex - ey) % g + g) % g;
		
		ll _g = gcd(d, g);
		ll _v1 = (vs - ve + g) % g;
		ll _v2 = (ve - vs + g) % g;
		if (_v1 % _g != 0) {	
			printf("-1\n");
			continue;
		}
		ll inv = getinv(d / _g, g / _g);
		ll ans = min((ll)b * ((ll)inv * _v2 % (g / _g)), (ll)c * ((ll)inv * _v1 % (g / _g)));
		ll ans2 = a;
		
		ll _nd = gcd(n, d);
		ll _md = gcd(m, d);
		ll _vx = ((ex - sx) % n + n) % n;
		ll _vy = ((ey - sy) % m + m) % m;
		if (_vx % _nd != 0 || _vy % _md != 0) {
			printf("%lld\n", ans + ans2);
			continue;
		}
		ll vv = exCRT(getinv(d, n) * _vx % n, n, getinv(d, m) * _vy % m, m);
		if (vv == -1){
			printf("%lld\n", ans + ans2);
			continue;
		}
		else {
			ans2 = min(ans2, vv * (b + c));
			printf("%lld\n", ans + ans2);
		}
	}
    return 0;
}

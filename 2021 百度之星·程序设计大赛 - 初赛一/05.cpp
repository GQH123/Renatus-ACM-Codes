#include <bits/stdc++.h>
#define rep(i, l, r) for (ll i = l; i <= r; i++)
#define per(i, r, l) for (ll i = r; i >= l; i--)
#define srep(i, l, r) for (ll i = l; i < r; i++)
#define sper(i, r, l) for (ll i = r; i > l; i--)
#define erep(i, x) for (ll i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (ll& i = cur[x]; i; i = e[i].next)
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define ui unsigned ll
#define ld long double
#define pb push_back
#define pc putchar
#define lowbit(x) (x & -x)
#define maxbuf 2000020
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxbuf, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

#define ll long long int 

namespace Fast_Read{
    char buffer[maxbuf], *p1, *p2;
    template<class T> void read_signed(T& x){
        char ch = gc(); x = 0; bool f = 1;
        while (!isdigit(ch) && ch != '-') ch = gc();
        if (ch == '-') f = 0, ch = gc();
        while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
        x = (f) ? x : -x;
    }
    template<class T, class... Args> void read_signed(T& x, Args&... args){
        read_signed(x), read_signed(args...);
    }
    template<class T> void read_unsigned(T& x){
        char ch = gc(); x = 0;
        while (!isdigit(ch)) ch = gc(); 
        while (isdigit(ch)) x = (x << 1) + (x << 3) + ch - '0', ch = gc(); 
    }
    template<class T, class... Args> void read_unsigned(T& x, Args&... args){
        read_unsigned(x), read_unsigned(args...);
    }
    #define isletter(ch) ('a' <= ch && ch <= 'z')
    ll read_string(char* s){
        char ch = gc(); ll l = 0;
        while (!isletter(ch)) ch = gc();
        while (isletter(ch)) s[l++] = ch, ch = gc();
        s[l] = '\0'; return l;
    }
}using namespace Fast_Read; 

ll _num[20];
template <class T> void write(T x, char sep = '\n'){	
	if (!x) {putchar('0'), putchar(sep); return;}
	if (x < 0) putchar('-'), x = -x;
	ll c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar(sep);
}

#define read read_signed
#define reads read_string 
#define writes puts

#define maxn 3000021
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 1000000007

#define mo(x) (x = x >= M ? x - M : x)

ll inv[maxn], pre[maxn], ppre[maxn];
void init(){
	inv[1] = 1;
	srep(i, 2, maxn) inv[i] = M - 1ll * M / i * inv[M % i] % M;
	pre[0] = 0; srep(i, 1, maxn) pre[i] = inv[i] + pre[i - 1], mo(pre[i]);
	ppre[0] = 0; srep(i, 1, maxn) ppre[i] = pre[i] + ppre[i - 1], mo(ppre[i]);
}

ll power2(ll x, ll y) {
	ll ans = 1, con = x;
	while (y) {
		if (y & 1) ans = 1ll * ans * con % M;
		con = 1ll * con * con % M;
		y >>= 1;
	}
	return ans;
}
ll getinv(ll x) { return power2(x, M - 2); }

signed main(){
	init();
	ll T; 
	read(T);
	while (T--) {
		ll n, x, y;
		read(n, x, y);
		if (n == 1 || x == y) {
			puts("0");
			continue;
		}
		ll le = y - 1, ri = n - y;
		if (le == 0) {
			printf("%lld\n", pre[x - 1]);
			continue;
		}
		if (ri == 0) {
			printf("%lld\n", pre[n - x]);
			continue;
		}
		ll f1a = M - 1, f1b = 1ll * ri * inv[ri + 1] % M, f1c = 1 + 1ll * inv[ri + 1] * (ppre[n - 1] + M - 1ll * (ri - 1) * pre[le + 1] % M + M - ppre[le + 1]) % M;
		ll f2a = 1ll * le * inv[le + 1] % M, f2b = M - 1, f2c = 1 + 1ll * inv[le + 1] * (ppre[n - 1] + M - 1ll * (le - 1) * pre[ri + 1] % M + M - ppre[ri + 1]) % M;
		
		ll d = M - f2a; f1a = 1ll * f1a * d % M, f1b = 1ll * f1b * d % M, f1c = 1ll * f1c * d % M;
		f1a += M - f2a, mo(f1a);
		assert(!f1a);
		f1b += M - f2b, mo(f1b);
		f1c += M - f2c, mo(f1c);
		
		ll b = 1ll * (M - f1c) * getinv(f1b) % M;
		ll a = 1ll * ((M - f2c) + (M - 1ll * f2b * b % M)) * getinv(f2a) % M;
		
		printf("%lld\n", x < y ? ((1ll * a + pre[ri + y - x] + M - pre[ri + 1]) % M) : ((1ll * b + pre[le + x - y] + M - pre[le + 1]) % M));
	}
	return 0;
}


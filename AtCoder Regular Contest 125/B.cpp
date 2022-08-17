#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, r, l) for (int i = r; i >= l; i--)
#define srep(i, l, r) for (int i = l; i < r; i++)
#define sper(i, r, l) for (int i = r; i > l; i--)
#define erep(i, x) for (int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (int& i = cur[x]; i; i = e[i].next)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define pb push_back
#define pc putchar
#define lowbit(x) (x & -x)
#define maxbuf 2000020
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxbuf, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

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
    int read_string(char* s){
        char ch = gc(); int l = 0;
        while (!isletter(ch)) ch = gc();
        while (isletter(ch)) s[l++] = ch, ch = gc();
        s[l] = '\0'; return l;
    }
}using namespace Fast_Read; 

int _num[20];
template <class T> void write(T x, char sep = '\n'){	
	if (!x) {putchar('0'), putchar(sep); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar(sep);
}

#define read read_signed
#define reads read_string 
#define writes puts

#define maxn
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 998244353
#define mo(x) (x = x >= M ? x - M : x)
#define ll __int128

ll n;


ll ceil_sqrt(ll n) {
	ll l = ceil(sqrt(n)) - 3, r = ceil(sqrt(n)) + 3;
	if (l < 0) l = 0;
	for (ll i = l; i <= r; i++) {
		if (i * i >= n) return i;
	}
}


ll cal(ll x){	
	//return x - ceil(sqrt(x * x - (long double)n));
	return x - ceil_sqrt(x * x - n);
}
/*
ll solve_lower(ll l, ll r, ll res) {
	while (l < r){
		ll mid = ((r - l) >> 1) + l;
		ll rres = cal(mid);
		if (rres == res) {
			r = mid;
		}
		else if (rres > res) {
			l = mid + 1;
		}
		else {
			r = mid;
		}
	}
	return l;
}
*/
ll solve_upper(ll l, ll r, ll res) {
	ll _l = l;
	while (l < r){
		ll mid = ((r - l + 1) >> 1) + l;
		ll rres = cal(mid);
		if (rres == res) {
			l = mid;
		}
		else if (rres > res) {
			l = mid;
		}
		else {
			r = mid - 1;
		}
	}
	
	/*
	if (l > _l && cal(l) != res) {
		printf("%lld, %lld, %lld", (long long)l, (long long)cal(l), (long long)res);
		fflush(stdout);
		assert(false);
	}
	*/
	
	//assert(cal(l) == res);
	return l;
}

int main(){ 
	read(n); 
	//printf("%lld\n", n);
	
	ll bound = floor(sqrt(n));
	ll ans = 1ll * bound * (bound + 1) / 2 % M;
	
	/*
	for (ll i = bound + 1; i <= n; i++) {
		if (cal(i) < cal(i + 1)) {
			printf("i = %lld, cal(i) = %lld, cal(i + 1) = %lld", (long long)i, (long long)cal(i), (long long)cal(i + 1));
			fflush(stdout);
			assert(false);
		}
		//assert(cal(i) >= cal(i + 1));
	}
	*/
	
	
	ll upper = cal(bound + 1);
	ll last = bound;
	per(res, upper, 1) {
		ll _last = solve_upper(last, n, res);
		ans += (ll)res * ((_last - last) % M) % M;
		
		//printf("res = %lld, upper = %lld, lower = %lld\n", (long long)res, (long long)_last, (long long)last);
		
		last = _last;
		mo(ans);
		
	} 
	printf("%lld\n", (long long)ans);
	return 0;
}


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
#define M 
#define ll __int128

ll cal1(int x) {
	return (ll)x * x * x;
}
ll cal2(int x) {
	return (ll)x * x * x * x * x - x;
}
ll cal3(int x) {
	return (ll)x * x * x * x * x * x * x - (ll)x * x * x;
}

int my_lower_bound1(int l, int r, ll bd) {
	while (l < r) {
		int mid = ((r - l + 1) >> 1) + l;
		if (cal1(mid) <= bd) l = mid;
		else r = mid - 1;
	}
	return l;
}
int my_lower_bound2(int l, int r, ll bd) {
	while (l < r) {
		int mid = ((r - l + 1) >> 1) + l;
		if (cal2(mid) <= bd) l = mid;
		else r = mid - 1;
	}
	return l;
}
int my_lower_bound3(int l, int r, ll bd) {
	while (l < r) {
		int mid = ((r - l + 1) >> 1) + l;
		if (cal3(mid) <= bd) l = mid;
		else r = mid - 1;
	}
	return l;
}

ll work(ll n, ll bd) {
	ll ans = 1; // (1, 1)
	rep(i, 2, n) {
		ll a = i, b = i * i * i;
		if (b > bd) break;
		while (b <= bd) {
			ans++;
			ll c = b; b = i * i * b - a;
			a = c;
		}
	}
	return ans;
}


int main(){
	int T; read(T);
	while (T--){
		ll n; read(n);
		ll ans = work(min(100ll, (long long)n), n);
		if (n > 100) {
			ans += my_lower_bound1(100, min(1000000ll, (long long)n), n) - 100;
			ans += my_lower_bound2(100, min(10000ll, (long long)n), n) - 100;
			ans += my_lower_bound3(100, min(1000ll, (long long)n), n) - 100;
		}
		printf("%lld\n", (long long)ans);
	}
	return 0;
} 

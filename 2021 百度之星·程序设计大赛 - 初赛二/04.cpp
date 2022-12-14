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

#define maxn 200021
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 
#define pll pair<ll, ll>

int n, a[maxn]; ll m;
pll lis[maxn]; int cs = 0;

ll ceil(ll a, ll b) {
	return (a - 1) / b + 1;
}

ll play(ll x, bool work = false) {
	ll _x = x;
	rep(i, 1, n) {
		x += a[i];
		if (x >= m) {
			return -1;
		}
		x = max(0ll, x);
		if (work) { if (!cs || x - _x > max(0ll, lis[cs].fi)) lis[++cs] = pll(x - _x, i); } //XXX
	}
	return x;
}

void work(){
	read(n, m);
	rep(i, 1, n) read(a[i]);
	
	ll fin1 = play(0); if (fin1 == -1) { puts("1"); return; }
	ll fin2 = play(fin1); if (fin2 == -1) { puts("2"); return; }
	ll fin3 = play(fin2, true); if (fin3 == -1) { puts("3"); return; }
	//ll fin4 = play(fin3); if (fin4 == -1) { puts("4"); return; }
	
	//rep(i, 1, cs) cerr << lis[i].fi << ' ' << lis[i].se << endl;
	
	//cerr << fin1 << ' ' << fin2 << ' ' << fin3 << ' ' << fin4 << endl;
	
	if (fin3 == fin2) { puts("-1"); return; }
	
	ll add = fin3 - fin2; 
	
	//cerr << add << endl; 
	
	printf("%lld\n", ceil(m - lis[cs].fi - fin2, add) + 1 + 2); 
}
int main(){
	int T; read(T);
	while (T--) {
		work();
		cs = 0;
	}
	return 0;
}


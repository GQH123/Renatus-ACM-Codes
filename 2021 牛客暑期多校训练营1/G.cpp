#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
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
#define maxr 2000020
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

namespace Fast_Read{
    char buffer[maxr], *p1, *p2;
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

#define maxn 600020
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

int n, k, a[maxn], b[maxn];
pii lis[maxn << 1]; int cs = 0;

int main(){
	scanf("%d%d", &n, &k);
	rep(i, 1, n) scanf("%d", a + i);
	rep(i, 1, n) scanf("%d", b + i);
	
	if (n == 2) {
		if (k & 1) {
			printf("%d\n", abs(a[2] - b[1]) + abs(a[1] - b[2]));
		}
		else {
			printf("%d\n", abs(a[1] - b[1]) + abs(a[2] - b[2]));
		}
		return 0;
	}
	
	rep(i, 1, n) {
		if (a[i] >= b[i]) lis[++cs] = pii(a[i], 1), lis[++cs] = pii(b[i], -1);
		else lis[++cs] = pii(a[i], -1), lis[++cs] = pii(b[i], 1);
	}
	sort(lis + 1, lis + 1 + cs);
	//rep(i, 1, cs) lis[i].se = -lis[i].se;
	ll ans = 0;
	rep(i, 1, cs) ans += lis[i].fi * lis[i].se;
	
	int l = 1, r = cs;
	while (l <= n && r > n && k) {
		while (l <= n && lis[l].se == -1) l++;
		while (r > n && lis[r].se == 1) r--;
		
		if (l < r) {
			assert(lis[l].se == 1 && lis[r].se == -1 && l <= n && r > n);
		
			ans += 2ll * (lis[r].fi - lis[l].fi);
			lis[l].se = -lis[l].se, lis[r].se = -lis[r].se;
			k--;
		}
	}
	
	/*
	if (k & 1) {
		ans -= 2ll * (lis[n + 1].fi - lis[n].fi);
	}
	*/
	
	printf("%lld\n", ans);
	
	return 0;
}


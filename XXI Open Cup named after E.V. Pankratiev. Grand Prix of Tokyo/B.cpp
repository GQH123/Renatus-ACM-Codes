#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
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

#define maxn 2000020
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 998244353
#define ll long long int 

int n, a[maxn];

int fac[maxn], dfac[maxn], ifac[maxn], inv[maxn];
void init(){
    fac[0] = ifac[0] = inv[1] = dfac[0] = 1;
    srep(i, 1, maxn) fac[i] = 1ll * fac[i - 1] * i % M;
    srep(i, 1, maxn) dfac[i] = 1ll * dfac[i - 1] * (2 * i - 1) % M;
    srep(i, 2, maxn) inv[i] = M - 1ll * M / i * inv[M % i] % M;
    srep(i, 1, maxn) ifac[i] = 1ll * ifac[i - 1] * inv[i] % M;
}
int C(int m, int n) {
    if (m < n) return 0;
    return 1ll * fac[m] * ifac[n] % M * ifac[m - n] % M;
}
int cal(int x, int y) {
    return 1ll * dfac[x] * dfac[y] % M * C(x + y, x) % M;
}
#define mo(x) (x = (x >= M) ? (x - M) : x)

int main(){
    init();
    read(n);
    rep(i, 1, n) read(a[i]);
    int ans = 0;
    rep(i, 1, n) {
        if (a[i] == 1) ans += cal(i - 1, n - i), mo(ans);
    }
    printf("%d\n", ans);
	return 0;
}


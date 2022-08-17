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

#define maxn 3021
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 1000000007
#define mo(x) (x = (x >= M) ? x - M : x)
#define ll long long int 

int fac[maxn], ifac[maxn], inv[maxn];
int init(){
	fac[0] = ifac[0] = inv[1] = 1;
	srep(i, 1, maxn) fac[i] = 1ll * i * fac[i - 1] % M;
	srep(i, 2, maxn) inv[i] = M - 1ll * M / i * inv[M % i] % M;
	srep(i, 1, maxn) ifac[i] = 1ll * inv[i] * ifac[i - 1] % M;
}
int cal(int n, int m) {
	if (n < m) return 0;
	return 1ll * fac[n] * ifac[n - m] % M * ifac[m] % M;
}

int a[maxn], b[maxn];


int dp[maxn][maxn];
bool vis[maxn][maxn];
int DP(int pos, int rest) {
	if (pos == 1) return 1; 
	if (vis[pos][rest]) return dp[pos][rest];
	vis[pos][rest] = 1;
	int& ans = dp[pos][rest];
	ans = 0;
	srep(i, 1, rest) {	
		ans += 1ll * DP(pos - 1, rest - i) * cal(rest, i) % M, mo(ans);
	}
	return ans;
}

/*
int eff[maxn], deg = 0;
void work(){
	eff[0] = 1, deg = 0;
	rep(i, 1, min(n, m)) {
		rep(j, 0, deg) {
			eff[j + 
		}
	}
}
*/

int main(){
	init();
	int n, m;
	/*
	rep(i, 1, 10) {
		cerr << DP(i, 10) << ' ';
	}cerr << endl;
	*/
	int T; read(T);
	while (T--) {
		read(n, m);
		
		rep(i, 1, n) a[i] = DP(i, n); //cerr << a[i] << ' '; cerr << endl;
		rep(i, 1, m) b[i] = DP(i, m); //cerr << b[i] << ' '; cerr << endl;
		ll ans = 0;
		rep(i, 1, min(n, m)) {
			ans += 2ll * a[i] * b[i] % M; mo(ans);
			ans += 1ll * a[i] * b[i + 1] % M; mo(ans);
			ans += 1ll * a[i + 1] * b[i] % M; mo(ans); 
		}
		printf("%lld\n", ans);
		rep(i, 1, n) a[i] = 0;
		
		rep(i, 1, m) b[i] = 0;
		
	}
	return 0;
}


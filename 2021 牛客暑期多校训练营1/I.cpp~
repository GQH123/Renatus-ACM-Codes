#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, r, l) for (int i = r; i >= l; i--)
#define srep(i, l, r) for (int i = l; i < r; i++)
#define sper(i, r, l) for (int i = r; i > l; i--)
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

#define maxn 5021
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 998244353
#define ll long long int 
#define mo(x) (x = (x >= M) ? (x - M) : x)

// int dp[2][maxn][maxn];
int n, p[maxn];

int inv[maxn];
int downn[maxn][maxn], downv[maxn][maxn];
int rightn[maxn][maxn], rightv[maxn][maxn];
void solve(){
	// rep(lastx, 1, n) rep(lasty, n, n) rep(op, 1, 1) dp[op][lastx][lasty] = 0;
	// rep(lastx, n, n) rep(lasty, 1, n) rep(op, 0, 0) dp[op][lastx][lasty] = 0;
	
	/*
	rep(op, 0, 1) {
		per(lastx, n, 1) {
			per(lasty, n, 1) {
				int& ans = dp[op][lastx][lasty];
				if (!op && lastx == n) {ans = 0; continue;}
				if (op && lasty == n) {ans = 0; continue;}
				
				if (!op) {
					
				}
				else {
				}
			}
		}
	}
	*/
	
	per(l, 2 * n - 1, 1) {
		srep(x, 1, l) {
			int y = l - x;
			if (!(1 <= x && x <= n && 1 <= y && y <= n)) continue;
			if (x == y) {
				downn[x][y] = downn[x][y + 1];
				downv[x][y] = downv[x][y + 1];
				rightn[x][y] = rightn[x + 1][y];
				rightv[x][y] = rightv[x + 1][y];
				
				continue;
			}
			if (p[x] > p[y]) {  // go right.
				if (y == n) {
					int myn = 1, myv = 0;
					
					downn[x][y] = 0;
					downv[x][y] = 0;
					rightn[x][y] = rightn[x + 1][y] + myn, mo(rightn[x][y]);
					rightv[x][y] = rightv[x + 1][y] + myv, mo(rightv[x][y]);
					
					continue;
				}
				int ansn = downn[x][y + 1];
				int ansv = downv[x][y + 1];
				
				int myn = 1, myv = !ansn ? 0 : 1 + 1ll * ansv * inv[ansn] % M;
				
				downn[x][y] = downn[x][y + 1];
				downv[x][y] = downv[x][y + 1];
				rightn[x][y] = rightn[x + 1][y] + myn, mo(rightn[x][y]);
				rightv[x][y] = rightv[x + 1][y] + myv, mo(rightv[x][y]);
			}
			else { // go down.
				if (x == n) {
					int myn = 1, myv = 0;
					
					rightn[x][y] = 0;
					rightv[x][y] = 0;
					downn[x][y]  = downn[x][y + 1] + myn, mo(downn[x][y]);
					downv[x][y]  = downv[x][y + 1] + myv, mo(downv[x][y]);
					
					continue;
				}
				int ansn = rightn[x + 1][y];
				int ansv = rightv[x + 1][y];
				
				int myn = 1, myv = !ansn ? 0 : 1 + 1ll * ansv * inv[ansn] % M;
				
				rightn[x][y] = rightn[x + 1][y];
				rightv[x][y] = rightv[x + 1][y];
				downn[x][y]  = downn[x][y + 1] + myn, mo(downn[x][y]);
				downv[x][y]  = downv[x][y + 1] + myv, mo(downv[x][y]);
			}
		}
	}
}

int main(){
	scanf("%d", &n);
	
	inv[1] = 1; srep(i, 2, maxn) inv[i] = M - 1ll * M / i * inv[M % i] % M;
	
	rep(i, 1, n) scanf("%d", p + i);
	solve();
	int resn = n, resv = n;
	rep(x, 1, n) {
		int ansn = downn[x][1];
		int ansv = downv[x][1]; 
		resv += !ansn ? 0 : 1 + 1ll * ansv * inv[ansn] % M, mo(resv);
	}
	printf("%lld\n", 1ll * resv * inv[resn] % M);
	return 0;
}


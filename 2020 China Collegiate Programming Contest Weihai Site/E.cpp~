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
#define ll long long int 
#define pb push_back
#define pc putchar
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn 16
#define maxm 120
#define maxs
#define maxb
#define M 
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}
int _num[20];
template <class T> void write(T x, char sep = '\n'){	
	if (!x) {putchar('0'), putchar(sep); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar(sep);
}

int n, m, a[maxn], bc[1 << maxn], sa[1 << maxn], lo[1 << maxn];

namespace DP_P{
	#define type long double
	#define DP(x, y) dp[x][y]
	type fac[maxm];
	void init(){
		fac[0] = 1; rep(i, 1, m) fac[i] = fac[i - 1] * i;
	}
	type C(int m, int n){
		if (n > m) return 0;
		return fac[m] / fac[n] / fac[m - n];
	}
	type dp[1 << maxn][maxm]; 
	void solve(){
		init();
		DP(0, 0) = 1;
		rep(pos, 1, m) {
			srep(S, 0, (1 << n)) {
				type& ans = dp[S][pos];
				if (S < (1 << n) - 1) ans = DP(S, pos - 1) / (n - bc[S]);
				else ans = 0;
				srep(i, 0, n) {
					if (S & (1 << i)) {
						ans += DP(S ^ (1 << i), pos - 1) / (n - bc[S] + 1) * C(pos - 1 - sa[S ^ (1 << i)], a[i] - 1);
					}
				}
			}
		}
		/*
		type res = 0;
		srep(i, 0, (1 << n)) {
			res += DP(i, m);
		}
		printf("%.10Lf\n", res);
		cerr << DP((1 << n) - 1, m) << endl;
		*/
	}
}
namespace DP_C{
	#define lowbit(x) (x & -x)
	#define type long double
	#define DP(x, y) dp[x][y]
	type fac[maxm];
	void init(){
		fac[0] = 1; rep(i, 1, m) fac[i] = fac[i - 1] * i;
	}
	type C(int m, int n){
		if (n > m) return 0;
		return fac[m] / fac[n] / fac[m - n];
	}
	type dp[1 << maxn][maxm];
	void solve(){
		init(); 
		srep(S, 0, (1 << n)) DP(S, 0) = 1;
		rep(rest, 1, m) {
			srep(S, 1, (1 << n)) {
				type& ans = dp[S][rest]; ans = 0;
				int id = lowbit(S);
				rep(i, 0, min(rest, a[lo[id]] - 1)) ans += DP(S ^ id, rest - i) * C(rest, i); 
			}
		}
	}
}

int main(){
	read(n), read(m); srep(i, 0, n) read(a[i]);
	srep(i, 2, (1 << n)) lo[i] = lo[i >> 1] + 1;
	srep(i, 1, (1 << n)) bc[i] = bc[i >> 1] + (i & 1), sa[i] = sa[i ^ lowbit(i)] + a[lo[lowbit(i)]];
	DP_P :: solve(), DP_C :: solve();
	long double ans = 0;
	srep(S, 0, (1 << n)) if (m >= sa[S]) ans += bc[S] * DP_P :: dp[S][m] * DP_C :: dp[(1 << n) - 1 - S][m - sa[S]]; 
	printf("%.10Lf\n", ans);
	return 0;
}


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

#define maxn 23
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 
#define ld long double 

int n, a[maxn];
ld sum[1 << maxn];
ld prod[1 << maxn];
int bc[1 << maxn];
bool vis[1 << maxn];
ld dp[1 << maxn];
ld DP(int S){	
	if (bc[S] == 1) return sum[S];
	if (vis[S]) return dp[S];
	vis[S] = 1;
	ld& ans = dp[S]; ans = 0;
	bool first = 1; int vfirst = -1;
	rep(i, 1, n) {
		if (S & (1 << (i - 1))) {
			if (first) {
				ans += 1.0 * a[i] / sum[S] * (a[i] + DP(S ^ (1 << (i - 1))));
				vfirst = a[i];
				first = 0;
			}
			else {
				ans += 1.0 * a[i] / sum[S] * (sum[S] - vfirst);
			}
		}
	}
	return ans;
}
int main(){
	read(n); rep(i, 1, n) read(a[i]);
	srep(i, 0, (1 << n)) {
		prod[i] = 1;
		rep(j, 1, n) {
			if (i & (1 << (j - 1))) {
				sum[i] += a[j];
				prod[i] *= a[j];
			}
		}
		//cerr << sum[i] << ' ' << bc[i] << endl;
	}
	srep(i, 1, 1 << n) bc[i] = bc[i >> 1] + (i & 1);
	printf("%.20Lf\n", sum[(1 << n) - 1] - DP((1 << n) - 1));
	return 0;
}


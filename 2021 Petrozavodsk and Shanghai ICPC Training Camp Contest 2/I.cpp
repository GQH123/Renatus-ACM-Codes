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

#define maxn 100020
#define maxm
#define maxs 2020
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

int S, n;
pii a[maxn]; //(p, c);


int dp[2][maxs];

/*
bool vis[maxn][maxs];
int DP(int pos, int num) {
	if (!num) return 0;
	if (pos == n + 1) return -1;
	if (vis[pos][num]) return dp[pos][num];
	vis[pos][num] = 1;
	int& ans = dp[pos][num]; ans = 0;
	int d1 = DP(pos + 1, num), d2 = DP(pos + 1, num - 1); ll ef = a[pos].se + (num - 1) * a[pos].fi, rs = -1;
	if (d1 != -1) {
		rs = d1;
	}
	if (d2 != -1) {
		rs = (rs == -1) ? d2 + ef : min(rs, d2 + ef);
	}
	if (rs > S) rs = -1;
	return ans = rs;
}
*/

/*
#define DP(i, j) dp[i][j]
void solve(){
	int bound = min(n + 1, min((int)pow(7ll * S, 1.0 / 3) + 10, maxs));
	//cerr << bound << ' ' << n;
	per(pos, n + 1, 1) {
		srep(num, 0, bound) {
			int& ans = dp[pos][num]; ans = 0;
			if (!num) continue;
			if (pos == n + 1) {ans = -1; continue;}
			
			//if (vis[pos][num]) return dp[pos][num];
			//vis[pos][num] = 1;
			
			int d1 = DP(pos + 1, num), d2 = DP(pos + 1, num - 1); ll ef = a[pos].se + (num - 1) * a[pos].fi, rs = -1;
			if (d1 != -1) {
				rs = d1;
			}
			if (d2 != -1) {
				rs = (rs == -1) ? d2 + ef : min(rs, d2 + ef);
			}
			if (rs > S) rs = -1;
			ans = rs;
		}
	}
}
*/

#define DP(i, j) dp[i][j]
int solve(){
	int bound = min(n + 1, min((int)pow(7ll * S, 1.0 / 3) + 10, maxs));
	//cerr << bound << ' ' << n;
	int d = 0;
	per(pos, n + 1, 1) {
		d ^= 1;
		srep(num, 0, bound) {
			int& ans = dp[d][num]; ans = 0;
			if (!num) continue;
			if (pos == n + 1) {ans = -1; continue;}
			
			//if (vis[pos][num]) return dp[pos][num];
			//vis[pos][num] = 1;
			
			int d1 = DP(d ^ 1, num), d2 = DP(d ^ 1, num - 1); ll ef = a[pos].se + (num - 1) * a[pos].fi, rs = -1;
			if (d1 != -1) {
				rs = d1;
			}
			if (d2 != -1) {
				rs = (rs == -1) ? d2 + ef : min(rs, d2 + ef);
			}
			if (rs > S) rs = -1;
			ans = rs;
		}
	}
	return d;
}


int main(){
	read(n, S);
	rep(i, 1, n) read(a[i].se);
	rep(i, 1, n) read(a[i].fi);
	sort(a + 1, a + 1 + n);
	int k = solve();
	rep(i, 0, n) {
		if (DP(k, i) == -1) {
			printf("%d\n", i - 1);
			return 0;
		}
	}
	printf("%d\n", n);
	return 0;
}


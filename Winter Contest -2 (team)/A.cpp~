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

#define read read_unsigned
#define reads read_string 
#define writes puts

#define maxn 120
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

int n, m;
int peo[maxn], pro[maxn], sco[maxn];

/*
bool vis[1 << 11][maxn][maxn];
int dp[1 << 11][maxn][maxn];
int DP(int a, int b, int c) {
	if (!a || b == m + 1) return 0;
	if (vis[a][b][c]) return dp[a][b][c];
	vis[a][b][c] = 1;
	int& ans = dp[a][b][c];
	ans = 0;
	ans = max(ans, DP(a, b + 1, c));
	srep(i, 0, n) {
		if (a & (1 << i)) {
			ans = max(ans, DP(a ^ (1 << i), b, peo[i + 1]));
		}
	}
	if (c >= pro[b]) {
		ans = max(ans, sco[b] + DP(a, b + 1, c - pro[b]));
	}
	return ans;
}
*/

int dp[1 << 11][maxn][maxn];
#define DP(a, b, c) dp[a][b][c]
void solve(){
	srep(a, 0, (1 << n)) {
		per(b, m, 1) {
			rep(c, 0, 100) {
				int& ans = dp[a][b][c];
				ans = 0;
				ans = max(ans, DP(a, b + 1, c));
				srep(i, 0, n) {
					if (a & (1 << i)) {
						ans = max(ans, DP(a ^ (1 << i), b, peo[i + 1]));
					}
				}
				if (c >= pro[b]) {
					ans = max(ans, sco[b] + DP(a, b + 1, c - pro[b]));
				}
			}
		}
	}
}



int main(){
	read(n, m);
	rep(i, 1, n) read(peo[i]);
	rep(i, 1, m) read(pro[i]);
	rep(i, 1, m) read(sco[i]);
	solve();
	int mx = 0, a = (1 << n) - 1;
	srep(i, 0, n) {
		mx = max(mx, DP(a ^ (1 << i), 1, peo[i + 1]));
	}
	printf("%d\n", mx);
	return 0;
}


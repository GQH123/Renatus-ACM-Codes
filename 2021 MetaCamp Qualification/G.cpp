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

#define maxn 520
#define maxm
#define maxs
#define maxb
#define inf 1000000020
#define eps
#define M 998244353
#define mo(x) (x = (x >= M) ? (x - M) : x)
#define ll long long int 



int n, a[maxn], v[maxn];

namespace DP1{
    int dp[maxn][maxn];
    int vis[maxn][maxn], idx;
    int DP(int pos, int last) {
        if (pos == n + 1) return 0;
        if (vis[pos][last] == idx) return dp[pos][last];
        vis[pos][last] = idx;
        int& ans = dp[pos][last]; ans = 0;
        
        if (v[pos] > v[last]) ans = max(ans, DP(pos + 1, pos) + 1);
        ans = max(ans, DP(pos + 1, last));
        
        return ans;
    }
}

namespace DP2{
    int dp[maxn][maxn];
    int vis[maxn][maxn], idx;
    int DP(int pos, int last) {
        if (pos == n + 1) return 0;
        if (vis[pos][last] == idx) return dp[pos][last];
        vis[pos][last] = idx;
        int& ans = dp[pos][last]; ans = 0;
        
        int aref = DP1 :: dp[pos][last];
        
        if (v[pos] > v[last]) {
            int ref = DP1 :: dp[pos + 1][pos];
            if (ref + 1 == aref) {
                ans += 1ll * DP(pos + 1, pos) * a[pos] % M;
                mo(ans);
            }
        }
        
        int ref = DP1 :: dp[pos + 1][last];
        if (ref == aref) {
            ans += DP(pos + 1, last);
            mo(ans);
        }
        
        return ans;
    }
}


int main(){
    while (scanf("%d", &n) == 1) {  
        DP1 :: idx++;
        DP2 :: idx++;
        a[0] = 1; rep(i, 1, n) scanf("%d", a + i);
        v[0] = 0;
        rep(i, 1, n) {
            if (a[i] > 0) v[i] = v[i - 1] + 1;
            else v[i] = v[i - 1] - 1;
            a[i] = abs(a[i]);
        }
        v[0] = -inf;
        
        DP1 :: DP(1, 0);
        printf("%d %d\n", DP1 :: DP(1, 0), DP2 :: DP(1, 0));
        
    }
	return 0;
}


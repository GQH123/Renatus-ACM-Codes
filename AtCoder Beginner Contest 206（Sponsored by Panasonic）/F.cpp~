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

#define maxn 105
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

int n;
pii p[maxn];

vector<pii> seg[maxn][maxn];

int vis[maxn][maxn], dp[maxn][maxn], idx = 0;

set<int> ss;
int DP(int l, int r){
    if (l == r) return 0;
    if (vis[l][r] == idx) return dp[l][r];
    vis[l][r] = idx;
    int& ans = dp[l][r]; ans = 0;
    
    
    for (auto it: seg[l][r]) {
        DP(l, it.fi);
        DP(it.se, r);
    }
    ss.clear();
    for (auto it: seg[l][r]) {
        ss.insert(DP(l, it.fi) ^ DP(it.se, r));
    }
    int ptr = 0;
    for (auto it: ss) {
        if (it != ptr) return ans = ptr;
        ptr++;
    }
    return ans = ptr;
}

pii lis[maxn << 1]; int cs = 0;

int main(){
    int T; read(T);
    while (T--){
        idx++;
        rep(i, 1, 100) rep(j, 1, 100) seg[i][j].clear();
        read(n);
        rep(i, 1, n) read(p[i].fi, p[i].se), seg[p[i].fi][p[i].se].pb(p[i]);
        rep(len, 1, 100) {
            rep(l, 1, 101 - len) {
                int r = l + len - 1;
                for (auto it: seg[l][r - 1]) lis[++cs] = it;
                for (auto it: seg[l + 1][r]) lis[++cs] = it;
                sort(lis + 1, lis + 1 + cs);
                cs = unique(lis + 1, lis + 1 + cs) - lis - 1;
                rep(i, 1, cs) seg[l][r].pb(lis[i]); 
                cs = 0;
            }
        }
        puts(DP(1, 100) ? "Alice" : "Bob");
    }
	return 0;
}


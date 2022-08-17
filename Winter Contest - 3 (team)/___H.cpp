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

#define maxn 220
#define maxm 520
#define maxb
#define inf  2000000020
#define eps
#define M 
#define ll long long int 

int n, m, S, T, all, a[maxn];
struct edge{
	int next, to, flow, cost;
	edge(int next, int to, int flow, int cost) : next(next), to(to), flow(flow), cost(cost){}
	edge(){}
}e[maxm << 1];
int cnt = 1, h[maxn];
void Add_Edge(int x, int y, int z, int w) {
	e[++cnt] = edge(h[x], y, z, w);
	h[x] = cnt;
}

int dp[maxn][maxm][maxn];
bool vis[maxn][maxm][maxn];
int DP(int pos, int ei, int rest) {
	if (!ei) {
		if (rest) return -inf;
		return 0;
	}
	if (pos == n) return rest * a[n];
	if (vis[pos][ei][rest]) return dp[pos][ei][rest];
	vis[pos][ei][rest] = 1;
	int& ans = dp[pos][ei][rest];
	ans = -inf;
	rep(i, 0, min(rest, e[ei].flow)) {
		int ddp = DP(e[ei].to, e[ei].next, rest - i);
		if (ddp != -inf) {
			ans = max(ans, ddp + i * a[e[ei].to]);
		}
	}
	return ans;
}

int main(){
	read(n, m);
	rep(i, 1, n) read(a[i]);
	int x, y, z;
	rep(i, 1, m) read(x, y, z), Add_Edge(x, y, z, 0); 
	int sum = 0;
	erep(i, 1) {
		sum += e[i].flow;
	}
	int res = 0;
	rep(i, 0, sum) {
		int ddp = DP(1, h[1], i);
		if (ddp != -inf) {
			res = max(res, ddp + i * a[1]);
		}
	}
	printf("%d\n", res);
	return 0;
}

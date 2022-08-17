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

#define maxn 400020
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

int n, a[maxn];
struct  edge{
	int next, to;
	edge(int next, int to) : next(next), to(to){}
	edge(){}
}e[maxn << 1];
int cnt = 1, h[maxn];
void Add_Edge(int x, int y) {
	e[++cnt] = edge(h[x], y);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x);
	h[y] = cnt;
} 
int dp[maxn][4], vis[maxn][4], idx;
int DP(int x, int fa, int up){
	if (vis[x][up == -1 ? 3 : up] == idx) return dp[x][up == -1 ? 3 : up];
	vis[x][up == -1 ? 3 : up] = idx; int& ans = dp[x][up == -1 ? 3 : up]; ans = 0;
	ans = n + 1;
	if (a[x] == 0 || a[x] == 1) {
		bool leaf = 1;
		erep(i, x) {
			int op = e[i].to;
			if (op == fa) continue;
			int offset = up != 1;
			ans = min(ans, offset + DP(op, x, 1));
			leaf = 0;
		}
		if (leaf) ans = min(ans, up != 1 ? 1 : 0);
	}
	if (a[x] == 0 || a[x] == 2) {
		bool leaf = 1;
		erep(i, x) {
			int op = e[i].to;
			if (op == fa) continue;
			int offset = up != 2;
			ans = min(ans, offset + DP(op, x, 2));
			leaf = 0;
		}
		if (leaf) ans = min(ans, up != 2 ? 1 : 0);
	} 
	return ans;
}
void recover(){
	rep(i, 1, n) h[i] = 0; cnt = 1; 
}
int main(){
	int T, x, y; read(T);
	while (T--){
		idx++;
		read(n); rep(i, 1, n) read(a[i]);
		rep(i, 2, n) {
			read(x, y);
			Add_Edge(x, y);
		}
		write(DP(1, -1, -1));
	}
	return 0;
}


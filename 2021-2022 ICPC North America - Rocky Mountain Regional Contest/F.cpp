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

#define maxn 322
#define maxm
#define maxs
#define maxb
#define eps
#define M 
#define ll long long int 
#define inf 1000000021

int n, m;
int w[maxn], v[maxn];

struct dpp{
	int ks[maxn]; //knapsack
	dpp(){ks[0] = 0; srep(i, 1, maxn) ks[i] = -inf;}
	void operator = (const dpp b) {	
		srep(i, 0, maxn) ks[i] = b.ks[i];
	}
}dp[2][maxn];
// 1 -> select root, 0 -> not select root


dpp max(const dpp a, const dpp b) {
	dpp c;
	srep(i, 0, maxn) {
		c.ks[i] = max(a.ks[i], b.ks[i]);
	}
	return c;
}

struct edge{
	int next, to;
	edge(int next, int to) : next(next), to(to){}
	edge(){}
}e[maxn << 2];
int cnt = 1, h[maxn];
void Add_Edge(int x, int y) {
	e[++cnt] = edge(h[x], y);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x);
	h[y] = cnt;
}

void merge(dpp& a, dpp& b) { // a will be changed 
	dpp c; 
	rep(i, 0, m) rep(j, 0, m - i) {
		if (a.ks[i] >= 0 && b.ks[j] >= 0) {
			c.ks[i + j] = max(c.ks[i + j], a.ks[i] + b.ks[j]);
		}
	}
	a = c;
}

void DP(int x, int fa) {	
	erep(i, x) {
		int op = e[i].to;
		if (op == fa) continue;
		DP(op, x);
	}
	
	erep(i, x) {
		int op = e[i].to;
		if (op == fa) continue;
		dpp __tmp = max(dp[0][op], dp[1][op]);
		merge(dp[0][x], __tmp);
	}
	
	dp[1][x].ks[w[x]] = v[x];
	erep(i, x) {
		int op = e[i].to;
		if (op == fa) continue;
		merge(dp[1][x], dp[0][op]);
	}
}

int main(){
	read(n, m);
	rep(i, 1, n) read(w[i], v[i]);
	int x, y;
	rep(i, 2, n) read(x, y), Add_Edge(x, y);
	DP(1, 1);
	
	int mx = 0;
	rep(i, 0, m) {	
		mx = max(mx, max(dp[0][1].ks[i], dp[1][1].ks[i]));
	}
	printf("%d\n", mx);
	return 0;
}


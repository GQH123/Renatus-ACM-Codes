#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define pii pair<ll, int>
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
#define maxm 2000020
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

int n, m, xs, ys, xt, yt;
ll a[maxn][maxn], b[maxn][maxn], c[maxn][maxn], w[maxn][maxn];

struct edge{
	int next, to, len;
	edge(int next, int to, ll len) : next(next), to(to), len(len){}
	edge(){}
}e[maxm << 1];
int cnt = 1, h[maxn * maxn];
void Add_Edge(int x, int y, ll z){ 
	e[++cnt] = edge(h[x], y, z);
	h[x] = cnt;
}
priority_queue<pii> pq;
ll d[maxn * maxn]; bool vis[maxn * maxn];
ll Dij(int s, int t){ 
	rep(i, 1, n * m) d[i] = -1;
	d[s] = 0; pq.push(pii(0, s));
	while (!pq.empty()) {
		pii uu = pq.top();
		pq.pop();
		int x = uu.se;
		if (vis[x]) continue;
		vis[x] = 1;
		ll ti = d[x];
		
		int _x = (x - 1) / m + 1, _y = (x - 1) % m + 1;
		ll T = a[_x][_y] + b[_x][_y];
		erep(i, x) {
			int op = e[i].to;
			if (vis[op]) continue;
			
			if (op == x - 1) {
				ll _ti = ti + ((ti % T < a[_x][_y]) ? a[_x][_y] - ti % T : 0);
				if (d[op] == -1 || d[op] > _ti + e[i].len) {	
					d[op] = _ti + e[i].len;
					pq.push(pii(-d[op], op));
				}
			}
			if (op == x + 1) {
				ll _ti = ti + ((ti % T < a[_x][_y]) ? a[_x][_y] - ti % T : 0);
				if (d[op] == -1 || d[op] > _ti + e[i].len) {	
					d[op] = _ti + e[i].len;
					pq.push(pii(-d[op], op));
				}
			}
			if (op == x - m) {
				ll _ti = ti + ((ti % T >= a[_x][_y]) ? T - ti % T : 0);
				if (d[op] == -1 || d[op] > _ti + e[i].len) {	
					d[op] = _ti + e[i].len;
					pq.push(pii(-d[op], op));
				}
			}
			if (op == x + m) {
				ll _ti = ti + ((ti % T >= a[_x][_y]) ? T - ti % T : 0);
				if (d[op] == -1 || d[op] > _ti + e[i].len) {	
					d[op] = _ti + e[i].len;
					pq.push(pii(-d[op], op));
				}
			}
		}
	}
	return d[t];
}

int main(){
	read(n, m, xs, ys, xt, yt);
	int S = (xs - 1) * m + ys;
	int T = (xt - 1) * m + yt;
	rep(i, 1, n) rep(j, 1, m) read(a[i][j]);
	rep(i, 1, n) rep(j, 1, m) read(b[i][j]);
	rep(i, 1, n) rep(j, 1, m - 1) read(c[i][j]);
	rep(i, 1, n - 1) rep(j, 1, m) read(w[i][j]);
	int ct = 0;
	rep(i, 1, n) rep(j, 1, m) {
		++ct;
		if (j > 1) Add_Edge(ct, ct - 1, c[i][j - 1]);
		if (j < m) Add_Edge(ct, ct + 1, c[i][j]);
		if (i > 1) Add_Edge(ct, ct - m, w[i - 1][j]);
		if (i < n) Add_Edge(ct, ct + m, w[i][j]);
	}
	printf("%lld\n", Dij(S, T));
	return 0;
}


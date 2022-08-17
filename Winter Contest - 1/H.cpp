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

#define maxn 2000020
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

int n, m, lis[maxn];
struct edge{
	int next, to;
	edge(int next, int to) :  next(next), to(to){}
	edge(){}
}e[maxn << 1];
int cnt = 1, h[maxn];
void Add_Edge(int x, int y){
	e[++cnt] = edge(h[x], y);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x);
	h[y] = cnt;
}
int tim[maxn], siz[maxn], ti = 0;
void dfs(int x, int fa){
	tim[x] = ++ti;
	siz[x] = 1;
	erep(i, x){
		int op = e[i].to;
		if (op == fa) continue;
		dfs(op, x);
		siz[x] += siz[op];
	}
}

int mx[maxn << 2];
int qx, qy, qd;
int getmx(int l, int r, int o) {
	if (qx <= l && r <= qy) return mx[o];
	int mid = ((r - l) >> 1) + l, ans = 0;
	if (qx <= mid) ans = max(ans, getmx(l, mid, o << 1));
	if (qy > mid) ans = max(ans, getmx(mid + 1, r, o << 1 | 1));
	return ans;
}
void mod(int l, int r, int o) {
	if (l == r) {mx[o] = max(mx[o], qd); return;}
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) mod(l, mid, o << 1);
	else mod(mid + 1, r, o << 1 | 1);
	mx[o] = max(mx[o << 1], mx[o << 1 | 1]);
}

int main(){
	read(n, m); int x;
	rep(i, 2, n) read(x), Add_Edge(x, i);
	rep(i, 1, m) read(lis[i]);
	dfs(1, -1);
	int res = 0;
	per(i, m, 1) {
		int x = lis[i], dp = 0;
		qx = tim[x] + 1, qy = tim[x] + siz[x] - 1;
		if (qx <= qy) dp = getmx(1, n, 1);
		else dp = 0;
		qx = tim[x], qd = dp + 1;
		mod(1, n, 1);
		res = max(res, dp + 1);
	}
	write(res);
	return 0;
}


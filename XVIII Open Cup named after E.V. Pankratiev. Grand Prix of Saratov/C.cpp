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

#define maxn 200020
#define maxm
#define maxs
#define maxb 20
#define inf 
#define eps
#define M 
#define ll long long int 


int n, m;
struct edge{
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
int fa[maxb][maxn];
int d[maxn], si[maxn], dfs[maxn], ti = 0;
void DFS(int x) {
    dfs[x] = ++ti;
    si[x] = 1;
    srep(i, 1, maxb) fa[i][x] = fa[i - 1][fa[i - 1][x]];
    erep(i, x) {
        int op = e[i].to;
        if (op == fa[0][x]) continue;
        fa[0][op] = x;
        d[op] = d[x] + 1;
        DFS(op);
        si[x] += si[op];
    }
}
int lca(int x, int y) {
    if (x == y) return x;
    if (d[x] < d[y]) swap(x, y);
    int k = d[x] - d[y], now = 0;
    while (k) {
        if (k & 1) x = fa[now][x];
        k >>= 1;
        now++;
    }
    if (x == y) return x;
    per(i, maxb - 1, 0) {
        if (fa[i][x] != fa[i][y]) x = fa[i][x], y = fa[i][y];
    }
    return fa[0][x];
}
struct path{
    int x, y, lca;
    path(int x, int y, int lca) : x(x), y(y), lca(lca){}
    path(){}
    bool operator < (const path b) const{ 
        return d[lca] > d[b.lca];
    }
}p[maxn];

int c[maxn];
int get(int x) {
    int ans = 0;
    while (x) {
        ans += c[x];
        x -= lowbit(x);
    }
    return ans;
}
void add(int x, int v) {
    while (x <= n) {
        c[x] += v;
        x += lowbit(x);
    }
}

int getp(int a) {
    return get(dfs[a]);
}
int getnum(int a, int b, int lca) {
    return getp(a) + getp(b) - getp(lca) - (fa[0][lca] ? getp(fa[0][lca]) : 0);
}
void mod(int x) {
    add(dfs[x], 1);
    add(dfs[x] + si[x], -1);
}
int res, ans[maxn];
int main(){
    int x, y;
    read(n);
    rep(i, 2, n) read(x, y), Add_Edge(x, y);
    DFS(1);
    read(m);
    rep(i, 1, m) {
        read(x, y);
        p[i] = path(x, y, lca(x, y));
    }
    sort(p + 1, p + 1 + m);
    rep(i, 1, m) {
        if (!getnum(p[i].x, p[i].y, p[i].lca)) {
            ans[++res] = p[i].lca;
            mod(p[i].lca);
        }
    }
    printf("%d\n", res);
    rep(i, 1, res) printf("%d ", ans[i]);
	return 0;
}


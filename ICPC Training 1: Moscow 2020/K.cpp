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


int n;
struct edge{
	int next, to, id;
	edge(int next, int to, int id) : next(next), to(to), id(id){}
	edge(){}
}e[maxn << 1];
int cnt = 1, h[maxn];
void Add_Edge(int x, int y, int id){
	e[++cnt] = edge(h[x], y, id);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x, id);
	h[y] = cnt;
}
int d[maxn], fa[maxn];
void dfs(int x) {
	erep(i, x) {
		int op = e[i].to;
		if (op == fa[x]) continue;
		d[op] = d[x] + 1;
		fa[op] = x;
		dfs(op); 
	}
}

int res[maxn], ffmxd2, root;
void dfs2(int x) {
	erep(i, x) {
		int op = e[i].to;
		if (op == fa[x]) continue;
		if (op == ffmxd2 && x == root) res[root] = e[i].id;
		res[op] = e[i].id;
		d[op] = d[x] + 1;
		fa[op] = x;
		dfs2(op); 
	}
}
int main(){
	int x, y;
	read(n);
	rep(i, 2, n) read(x, y), Add_Edge(x, y, i - 1);
	fa[1] = -1, d[1] = 0; dfs(1);
	int mxd = -1, mxd2 = -1;
	rep(i, 1, n) if (d[i] > mxd) mxd = d[i], mxd2 = i; 
	fa[mxd2] = -1, d[mxd2] = 0; dfs(mxd2);
	mxd = -1, mxd2 = -1;
	rep(i, 1, n) if (d[i] > mxd) mxd = d[i], mxd2 = i; 
	
	int len = mxd;
	printf("%d\n", len >> 1);
	int step = len >> 1;
	while (step--) mxd2 = fa[mxd2];
	root = mxd2;
	if (len & 1) ffmxd2 = fa[mxd2];
	else ffmxd2 = -1, res[mxd2] = -1;
	fa[mxd2] = -1, d[mxd2] = 0; dfs2(mxd2); 
	rep(i, 1, n) {
		if (i == 1) printf("%d", res[i]);
		else printf(" %d", res[i]);
	}
	return 0;
}


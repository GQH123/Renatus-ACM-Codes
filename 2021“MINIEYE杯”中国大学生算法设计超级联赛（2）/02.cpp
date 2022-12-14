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

#define maxn 200021
#define maxm
#define maxs
#define maxb
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
void Add_Edge(int x, int y){
	e[++cnt] = edge(h[x], y);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x);
	h[y] = cnt;
}
int fa[maxn], top[maxn], dfs[maxn], idfs[maxn], siz[maxn], d[maxn], son[maxn], idx = 0;
void fdfs(int x) {
	siz[x] = 1;
	son[x] = 0;
	erep(i, x) {
		int op = e[i].to;
		if (op == fa[x]) continue;
		fa[op] = x;
		d[op] = d[x] + 1;
		fdfs(op);
		siz[x] += siz[op];
		if (siz[op] > siz[son[x]]) son[x] = op;
	}
}
void fdfs(int x, int tp) {
	top[x] = tp;
	dfs[x] = ++idx;
	idfs[idx] = x;
	if (son[x]) fdfs(son[x], tp); 
	erep(i, x) {
		int op = e[i].to;
		if (op == fa[x] || op == son[x]) continue;
		fdfs(op, op);
	}
}

ll add[3][maxn << 2], qd[3];
int qx, qy;
inline ll cal(ll v2, ll v1, ll v0, int x) {
	return v2 * x * x + v1 * x + v0;
	//return v2 * n * (n + 1) * (2 * n + 1) / 6 + v1 * n * (n + 1) / 2 + v0 * n;
}
void init(int l, int r, int o) {
	add[0][o] = add[1][o] = add[2][o] = 0;
	if (l == r) return;
	int mid = ((r - l) >> 1) + l;
	init(l, mid, o << 1), init(mid + 1, r, o << 1 | 1);
}
inline void pd(int l, int r, int o) {
	if (l == r) return;
	if (add[0][o] || add[1][o] || add[2][o]) {
		int mid = ((r - l) >> 1) + l;
		rep(i, 0, 2) {
			add[i][o << 1] += add[i][o];
			add[i][o << 1 | 1] += add[i][o]; 
			add[i][o] = 0;
		}
	}
}
ll get(int l, int r, int o) {
	pd(l, r, o);
	if (l == r) return cal(add[2][o], add[1][o], add[0][o], l);
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) return get(l, mid, o << 1);
	else return get(mid + 1, r, o << 1 | 1);
}
void mod(int l, int r, int o) {
	pd(l, r, o);
	if (qx <= l && r <= qy) {
		add[0][o] += qd[0],
		add[1][o] += qd[1],
		add[2][o] += qd[2];
		return;
	}
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) mod(l, mid, o << 1);
	if (qy > mid) mod(mid + 1, r, o << 1 | 1); 
}
void init(){
	d[1] = fa[1] = 0; fdfs(1), fdfs(1, 1), init(1, n, 1);
}
ll tget(int x){
	qx = dfs[x];
	return get(1, n, 1);
}
int getlca(int x, int y) {
	int tx = top[x], ty = top[y];
	while (tx != ty) {
		if (d[tx] > d[ty]) x = fa[tx], tx = top[x];
		else y = fa[ty], ty = top[y];
	}
	return d[x] > d[y] ? y : x;
}
void tmod(int x, int y) {
	int lca = getlca(x, y), len = d[x] - d[lca] + d[y] - d[lca] + 1;
	int tx = top[x], ty = top[y], head = 1, tail = len;
	while (tx != ty) {
		if (d[tx] > d[ty]) {
			qx = dfs[tx], qy = dfs[x];
			head += qy - qx;
			qd[2] = 1, qd[1] = 2ll * (-head - qx), qd[0] = 1ll * (head + qx) * (head + qx);
			mod(1, n, 1); 
			x = fa[tx], tx = top[x];
			head++; //XXX
		}
		else {
			qx = dfs[ty], qy = dfs[y];
			tail -= qy - qx;
			qd[2] = 1, qd[1] = 2ll * (tail - qx), qd[0] = 1ll * (tail - qx) * (tail - qx);
			mod(1, n, 1);
			y = fa[ty], ty = top[y];
			tail--; //XXX
		}
	}
	if (d[x] > d[y]) {
		qx = dfs[y], qy = dfs[x];
		head += qy - qx;
		qd[2] = 1, qd[1] = 2ll * (-head - qx), qd[0] = 1ll * (head + qx) * (head + qx);
		mod(1, n, 1);  
	}
	else {
		qx = dfs[x], qy = dfs[y];
		tail -= qy - qx;
		qd[2] = 1, qd[1] = 2ll * (tail - qx), qd[0] = 1ll * (tail - qx) * (tail - qx);
		mod(1, n, 1);
	}
	assert(head == tail);
}
void work(){
	int x, y, op;
	read(n);
	rep(i, 2, n) read(x, y), Add_Edge(x, y);
	init();
	read(m);
	rep(i, 1, m) {
		read(op);
		if (op == 1) read(x, y), tmod(x, y);
		else if (op == 2) read(x), printf("%lld\n", tget(x));
	} 
}
void clear(){
	rep(i, 1, n) h[i] = 0; cnt = 1; idx = 0;
}
int main(){
	int T; T = 1;
	while (T--) work(); //clear();
	return 0;
}


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
#define ll long long int 
#define pb push_back
#define pc putchar
#define lowbit(x) (x & -x)
#define maxr 500000
#define maxn 262144
#define maxm 262144
#define maxs 140000000
#define maxb
#define M 
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}
int _num[20];
template <class T> void write(T x){	
	if (!x) {putchar('0'), putchar('\n'); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar('\n');
}
void readupper(char& ch){
	ch = gc();
	while (!('A' <= ch && ch <= 'Z')) ch = gc();
}

int n = 1, m;
struct edge{
	int next, to, v;
	edge(int next, int to, int v) : next(next), to(to), v(v){}
	edge(){}
}e[maxn << 1];
int cnt = 1, h[maxn];
void Add_Edge(int x, int y, int z){
	e[++cnt] = edge(h[x], y, z);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x, z);
	h[y] = cnt;
}
int dfs[maxn], ct = 0, s[maxn], v[maxn];
void DFS(int x, int fa){
	dfs[x] = ++ct, s[x] = 1;
	erep(i, x){
		int op = e[i].to;
		if (op == fa) continue;
		v[op] = v[x] ^ e[i].v;
		DFS(op, x);
		s[x] += s[op];
	}
}

struct ele{
	int type, x, y;
	ele(int type, int x, int y) : type(type), x(x), y(y){}
	ele(){}
}q[maxm];

int hh[maxn << 2], qx, qy;
int ch[maxs][2], num[31];
void add(int& x, int d) {
	if (!x) x = ++ct; if (d != -1) add(ch[x][num[d]], d - 1);
}
int getmx(int x, int d) {
	if (d == -1) return 0;
	if (ch[x][num[d] ^ 1]) return getmx(ch[x][num[d] ^ 1], d - 1) ^ (1 << d);
	else return getmx(ch[x][num[d]], d - 1);
}
void add(int l, int r, int o) {
	add(hh[o], 30);
	if (l == r) return;
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) add(l, mid, o << 1);
	else add(mid + 1, r, o << 1 | 1);
}
int getmx(int l, int r, int o) {
	if (qx <= l && r <= qy) return (hh[o]) ? getmx(hh[o], 30) : 0;
	int mid = ((r - l) >> 1) + l, ans = 0;
	if (qx <= mid) ans = max(ans, getmx(l, mid, o << 1));
	if (qy > mid) ans = max(ans, getmx(mid + 1, r, o << 1 | 1));
	return ans;
}

void dep(int x) {
	rep(i, 0, 30) num[i] = x & 1, x >>= 1; 
}

int main(){
	read(m);
	char ch; int type, x, y;
	rep(i, 1, m) {
		readupper(ch), read(x), read(y);
		if (ch == 'A') ++n, Add_Edge(n, x, y), q[i] = ele(0, n, n); //XXX
		else q[i] = ele(1, x, y);
	}
	DFS(1, 0); ct = 0;
	qx = 1, dep(v[1]);
	add(1, n, 1); //XXX
	rep(i, 1, m) {	
		type = q[i].type, x = q[i].x, y = q[i].y;
		if (!type) {
			qx = dfs[y], dep(v[y]); //XXX
			add(1, n, 1);
		}
		else {
			qx = dfs[y], qy = dfs[y] + s[y] - 1, dep(v[x]);
			printf("%d\n", getmx(1, n, 1));
		}
	}
	return 0;
}


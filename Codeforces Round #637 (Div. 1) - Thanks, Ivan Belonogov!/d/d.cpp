#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define pii pair<int, int>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define ll long long int 
#define pb push_back
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn 200020
#define maxm
#define maxs
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

int n;
struct edge{
	int next, to;
	edge(int next, int to) : next(next), to(to){}
	edge(){}
}e[maxn << 1];
int h[maxn], cnt = 1, deg[maxn];
void Add_Edge(int x, int y){
	e[++cnt] = edge(h[x], y);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x);
	h[y] = cnt;
	deg[x]++, deg[y]++;
}
pii ans[maxn << 3];
int cs = 0;
void dfs(int x, int d, int fa){ //d  d - 1
	int k = d - 1, num = max(0, deg[x] - 1 - k), cn = 1, ca = 1;
	ans[++cs] = pii(x, d); 
	if (deg[x] == 1) {ans[++cs] = pii(x, d - 1); return;} 
	if (!num) ans[++cs] = pii(x, 0);
	erep(i, x){
		int op = e[i].to;
		if (op == fa) continue;
		if (num > 0) {
			dfs(op, d + cn, x), ans[++cs] = pii(x, d + cn), cn++, num--;
			if (!num) ans[++cs] = pii(x, 0);
		} 
		else dfs(op, ca, x), ans[++cs] = pii(x, ca), ca++;
	}
}

int main(){
	
		//freopen("d.in", "r", stdin);
	
	int x, y;
	read(n);
	srep(i, 1, n) read(x), read(y), Add_Edge(x, y);
	int ct = 1;
	ans[++cs] = pii(1, 0);
	erep(i, 1){
		int op = e[i].to;
		dfs(op, ct, 1), ans[++cs] = pii(1, ct);
		ct++;
	}
	printf("%d\n", cs);
	rep(i, 1, cs) printf("%d %d\n", ans[i].fi, ans[i].se);
	return 0;
}


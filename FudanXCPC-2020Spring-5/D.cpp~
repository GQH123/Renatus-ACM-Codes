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
#define maxn 400020
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

int n, m;
struct edge{
	int next, to;
	char c;
	edge(int next, int to, char c) : next(next), to(to), c(c){}
	edge(){}
}e[maxn << 1];
int cnt = 1, h[maxn];
void Add_Edge(int x, int y, char c){
	e[++cnt] = edge(h[x], y, c);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x, c);
	h[y] = cnt;
}

bool vis[maxn];
int d[maxn];
int bfs[maxn], he, ta;
void BFS(){
	bfs[++he] = n;
	d[n] = 0;
	vis[n] = 1;
	while (ta < he){
		int x = bfs[++ta];
		erep(i, x){
			int op = e[i].to;
			if (!vis[op]){
				vis[op] = 1;
				d[op] = d[x] + 1;
				bfs[++he] = op;
			}
		} 
	}
}

int sol[maxn], p[maxn];
char ans[maxn];

void find_path(int x){
	if (!p[x]) printf("%d ", x);
	else find_path(p[x]), printf("%d ", x);
}
void get(){
	rep(i, 1, n) vis[i] = 0;
	int st = 0; 
	he = ta = 0;
	sol[++he] = 1;
	vis[1] = 1;
	while (st < d[1]){
		int _ta = ta;
		char mi = 'z';
		while (he > ta){ 
			int x = sol[++ta]; 
			erep(i, x){
				int op = e[i].to;
				if (d[op] != d[x] - 1) continue;
				mi = min(mi, e[i].c);
			} 
		}
		ta = _ta;
		int _he = he;
		while (_he > ta){ 
			int x = sol[++ta]; 
			erep(i, x){
				int op = e[i].to;
				if (d[op] != d[x] - 1) continue;
				if (e[i].c == mi && !vis[op]) vis[op] = 1, sol[++he] = op, p[op] = x;
			} 
		} 
		ans[st++] = mi;
	}
	ans[st++] = '\0';
	printf("%d\n", d[1]);
	find_path(n); printf("\n");
	printf("%s", ans);
	
}

int main(){
	
		freopen("D.in", "r", stdin);
		
	//ios :: sync_with_stdio(false), cin.tie(0); 
	read(n), read(m);
	int x, y;
	char ch;
	rep(i, 1, m) {
		read(x), read(y);
		ch = gc();
		while (ch < 'a' || 'z' < ch) ch = gc();
		Add_Edge(x, y, ch);
	}
	BFS(), get();
	return 0;
}


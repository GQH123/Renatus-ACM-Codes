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
#define ll __int128
#define pb push_back
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn 500020
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
int _num[100];
template <class T> void write(T x){	
	if (!x) {putchar('0'), putchar('\n'); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar('\n');
}

int n, v[maxn];
struct edge{
	int next, to, c;
	edge(int next, int to, int c) : next(next), to(to), c(c){}
	edge(){}
}e[maxn << 1];
int cnt = 1, h[maxn];
void Add_Edge(int x, int y, int c){
	e[++cnt] = edge(h[x], y, c);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x, c);
	h[y] = cnt;
}

bool vis[maxn];
int ns, s[maxn], g = 0;
void DFS(int x, int fa){
	s[x] = 1;
	bool f = 1;
	erep(i, x){
		int op = e[i].to;
		if (op == fa || vis[op]) continue;
		DFS(op, x);
		s[x] += s[op];
		if (s[op] > (ns >> 1)) f = 0;
	}
	if (ns - s[x] > (ns >> 1)) f = 0;
	if (f) g = x;
}

int num_path = 0;
int num[maxn];
ll val_path = 0;
ll val[maxn]; 
ll ans = 0;

void DFS(int x, int fa, int nowc, int d, int cc, ll sumv){
	sumv += v[x];
	num_path += d, num[cc] += d, val_path += d * sumv, val[cc] += d * sumv;
	erep(i, x){
		int op = e[i].to;
		if (op == fa || vis[op] || e[i].c == nowc) continue;
		DFS(op, x, e[i].c, d, cc, sumv);
	}
}

void DFS(int x, int fa, int nowc, int cc, ll sumv){
	sumv += v[x];
	ans += (num_path - num[cc]) * sumv + val_path - val[cc]; 
	erep(i, x){
		int op = e[i].to;
		if (op == fa || vis[op] || e[i].c == nowc) continue;
		DFS(op, x, e[i].c, cc, sumv);
	}
}


void solve(int x){
	DFS(x, -1);
	x = g;
	vis[x] = 1; 
	num_path = 1, val_path = v[x];
	erep(i, x){
		int op = e[i].to;
		if (vis[op]) continue;
		DFS(op, x, e[i].c, e[i].c, 0);
		DFS(op, x, e[i].c, 1, e[i].c, v[x]);
	}
	erep(i, x){
		int op = e[i].to;
		if (vis[op]) continue;
		DFS(op, x, e[i].c, -1, e[i].c, v[x]);
	}
	int _ns = ns;
	num_path = 0, val_path = 0;
	erep(i, x){
		int op = e[i].to;
		if (vis[op]) continue;
		if (s[op] > s[x]) ns = _ns - s[x], solve(op);
		else ns = s[op], solve(op); 
	}
}

void recover(){
	ans = 0; cnt = 1;
	rep(i, 1, n) vis[i] = h[i] = 0; 
}
  
int main(){
	
		//freopen("C.in", "r", stdin);
		
	int x, y, z;
	while (scanf("%d", &n) == 1){
		rep(i, 1, n) scanf("%d", v + i);
		srep(i, 1, n) scanf("%d%d%d", &x, &y, &z), Add_Edge(x, y, z); 
		ns = n; solve(1); 
		write(ans);
		recover();
	}
	return 0;
}


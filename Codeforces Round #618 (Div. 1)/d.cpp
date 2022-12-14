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
#define maxm 200020
#define maxs
#define maxb
#define M 1000000007
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
	int next, to, w;
	edge(int next, int to, int w) : next(next), to(to), w(w){}
	edge(){}
}e[maxm << 1];
int cnt = 1, h[maxn];
void Add_Edge(int x, int y, int z){
	e[++cnt] = edge(h[x], y, z);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x, z);
	h[y] = cnt;
}
struct lb{
	bool zero = 0;
	int num[5];
	void insert(int x){	
		per(i, 4, 0){
			if (x ^ (1 << i)) {
				if (num[i]) x ^= num[i]; 
			}
		} 
		if (x){
			int now = 0, _x = x;
			while (x) now++, x >>= 1; 
			assert(!num[now - 1]);
			num[now - 1] = x;
		}
		else zero = 1;
	}
}loop[maxn];
struct ele{
	int id, root1, root2, v;
	ele(int id, int root1, int root2, int v) : id(id), root1(root1), root2(root2), v(v){}
	ele(){}
}lis[maxn];
int v[maxn], dfs[maxn], s[maxn], ti = 0;
bool vis[maxn]; 
int cs = 0;
void DFS(int x, int fa){
	vis[x] = 1;
	s[x] = 1, dfs[x] = ++ti;
	bool f = 1;
	erep(i, x){
		int op = e[i].to;
		if (op == fa && f) {f = 0; continue;}
		if (vis[op]) { 
			if (op == 1) lis[cs].root2 = x, lis[cs].v = v[x] ^ v[op] ^ e[i].w; 
			else loop[op].insert(v[x] ^ v[op] ^ e[i].w);
		} 
		else {
			if (x == 1) cs++, lis[cs] = ele(cs, op, -1, 0); 
			v[op] = v[x] ^ e[i].w, DFS(op, x), s[x] += s[op]; 
		}
	}
}


int main(){
	
		//freopen(".in", "r", stdin);
		
	ios :: sync_with_stdio(false), cin.tie(0);
	
	int x, y, z;
	scanf("%d%d", &n, &m);
	rep(i, 1, m) scanf("%d%d", &x, &y, &z), Add_Edge(x, y, z);
	DFS(1, -1);
	rep(i, 1, n){
		
	}
	return 0;
}


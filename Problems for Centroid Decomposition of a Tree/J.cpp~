#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define maxn 200020
#define maxm
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n; 
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
int g, ns, s[maxn];
bool vis[maxn];
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
int d[maxn];
void solve(int x, int fa){	 
	DFS(x, x);
	x = g;
	vis[x] = 1;
	int _ns = ns;
	d[x] = d[fa] + 1;
	erep(i, x){
		int op = e[i].to;
		if (vis[op]) continue;
		ns = (s[op] > s[x]) ? (_ns - s[x]) : s[op];
		solve(op, x);
	} 
}

int main(){
	
		freopen("J.in", "r", stdin);
		
	int x, y;
	scanf("%d", &n);
	srep(i, 1, n) scanf("%d%d", &x, &y), Add_Edge(x, y);
	ns = n;
	d[0] = -1;
	solve(1, 0);
	rep(i, 1, n) printf("%c ", 'A' + d[i]); 
	return 0;
}

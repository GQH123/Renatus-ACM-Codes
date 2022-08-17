#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define maxn 20020
#define maxm 200020
using namespace std;

int n, m;
struct edge{
	int next, to;
	edge(int next, int to) : next(next), to(to){}
	edge(){}
}e[maxm << 1];
int cnt = 1, h[maxn];
void Add_Edge(int x, int y){
	//e[++cnt] = edge(h[x], y);
	//h[x] = cnt; 
	e[++cnt] = edge(h[y], x);
	h[y] = cnt; 
}  
bitset<maxn> p[maxn];
bool vis[maxn];
int ans = 0;
void DFS(int x){
	if (vis[x]) return;
	vis[x] = 1;
	erep(i, x){
		int op = e[i].to;
		DFS(op);
		p[x] |= p[op];
	}
	erep(i, x){
		int op = e[i].to;
		if (p[x][op]) ans++;
		p[x][op] = 1;
	}
}

int main(){
	int T, x, y;
	scanf("%d", &T);
	while (T--){
		scanf("%d%d", &n, &m);
		rep(i, 1, n) vis[i] = h[i] = 0, p[i].reset(); cnt = 1, ans = 0;
		rep(i, 1, m) scanf("%d%d", &x, &y), Add_Edge(x, y); 
		rep(i, 1, n) DFS(i);
		printf("%d\n", ans);
	}
	return 0;
}

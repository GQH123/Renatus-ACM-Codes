#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define maxn 200020
#define maxb 22
#define maxm
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n;
int a[maxn];
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
int num[maxb][2];
ll ans = 0; 
void dep_add(int x, int v){ 
	srep(i, 0, maxb) {
		if (x & 1) num[i][1] += v;
		else num[i][0] += v; 
		x >>= 1;
	}
}
void dep_ans(int x){
	srep(i, 0, maxb) {
		if (x & 1) ans += (ll)num[i][0] * (1 << i);
		else ans += (ll)num[i][1] * (1 << i);
		x >>= 1;
	}
}
void DFS(int x, int fa, int d){
	d ^= a[x];
	dep_ans(d);
	erep(i, x){
		int op = e[i].to;
		if (op == fa || vis[op]) continue;
		DFS(op, x, d);
	}
}
void DFS(int x, int fa, int d, int v){
	d ^= a[x];
	dep_add(d, v);
	erep(i, x){
		int op = e[i].to;
		if (op == fa || vis[op]) continue;
		DFS(op, x, d, v);
	}
}
void solve(int x){
	DFS(x, x);	
	x = g;
	vis[x] = 1;
	ans += a[x];
	dep_add(a[x], 1);
	erep(i, x){
		int op = e[i].to;
		if (vis[op]) continue;
		DFS(op, x, 0);
		DFS(op, x, a[x], 1);
	}
	dep_add(a[x], -1);
	erep(i, x){
		int op = e[i].to;
		if (vis[op]) continue; 
		DFS(op, x, a[x], -1);
	}
	int _ns = ns;
	erep(i, x){
		int op = e[i].to;
		if (vis[op]) continue; 
		ns = (s[op] > s[x]) ? (_ns - s[x]) : s[op];
		solve(op);
	}
}

int main(){
	
		freopen("K.in", "r", stdin);
		
	int x, y;
	scanf("%d", &n), ns = n;
	rep(i, 1, n) scanf("%d", a + i);
	srep(i, 1, n) scanf("%d%d", &x, &y), Add_Edge(x, y);
	solve(1);
	printf("%lld", ans);
	return 0;
}

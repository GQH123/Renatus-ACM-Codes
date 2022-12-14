#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define maxe 10000020
#define maxp 600020
#define maxM 600020
#define maxall 4000020
using namespace std;

int n, p, M, m;
struct sta{
	int l, r; 
	sta(){}
}s[maxp];
struct edge{
	int next, to;
	edge(int next, int to) : next(next), to(to){}
	edge(){}
}e[maxe];
int h[maxall], cnt = 1;
inline void Add_Edge(int x, int y){
	e[++cnt] = edge(h[x], y);
	h[x] = cnt;
}
bool vis[maxall];
int low[maxall], dfs[maxall], st[maxall], scc[maxall];
int tim = 0, head = 0, css = 0;
int Tarjan(int x){
	dfs[x] = low[x] = ++tim;
	st[++head] = x;
	vis[x] = 1;
	erep(i, x){
		int op = e[i].to;
		if (!vis[op]) low[x] = min(low[x], Tarjan(op));
		else if (!scc[op]) low[x] = min(low[x], low[op]);
	}
	if (dfs[x] == low[x]) {
		css++; 
		int op = st[head--];
		while (op != x){
			scc[op] = css;
			op = st[head--];
		}
		scc[x] = css;
	}
	return low[x];
}
int in[maxall], bfs[maxall], topo[maxall], ans[maxp];
int he = 0, ta = 0, ord = 0, cs = 0;
bool solve(){	
	int all = p + p + M + M;
	rep(i, 1, all) if (!dfs[i]) Tarjan(i); 
	rep(i, 1, p) if (scc[i] == scc[i + p]) return false; 
	rep(x, 1, all) {
		erep(i, x){
			int op = e[i].to;
			if (scc[op] != scc[x]) Add_Edge(all + scc[x], all + scc[op]), in[scc[op]]++;
		}
	}
	rep(i, 1, css) if (!in[i]) bfs[++he] = i; 
	while (he > ta){
		int x = bfs[++ta];
		topo[x] = ++ord;
		erep(i, x + all){
			int op = e[i].to;
			in[op - all]--;
			if (!in[op - all]) bfs[++he] = op - all;
		}
	}
	rep(i, 1, p) if (topo[scc[i]] > topo[scc[i + p]]) ans[++cs] = i;
	return true;
}
int dd[maxM + 5];
int main(){

		freopen("I.in", "r", stdin);
	
	scanf("%d%d%d%d", &n, &p, &M, &m);
	int x, y;
	rep(i, 1, n){
		scanf("%d%d", &x, &y);
		Add_Edge(x + p, y);
		Add_Edge(y + p, x);
	}
	rep(i, 1, p){
		scanf("%d%d", &s[i].l, &s[i].r);
		if (s[i].r < M) Add_Edge(i, p + p + s[i].r + 1);
		if (s[i].l > 1) Add_Edge(i, s[i].l - 1 + M + p + p);
		if (s[i].l > 1) Add_Edge(p + p + s[i].l, i + p);
		if (s[i].r < M) Add_Edge(s[i].r + M + p + p, i + p);
	}
	srep(i, 1, M) Add_Edge(p + p + i, p + p + i + 1);
	sper(i, M, 1) Add_Edge(p + p + M + i, p + p + M + i - 1);
	rep(i, 1, m){
		scanf("%d%d", &x, &y);
		Add_Edge(x, y + p);
		Add_Edge(y, x + p);
	}
	if (!solve()) {printf("-1"); return 0;}
	rep(i, 1, cs){
		x = ans[i];
		dd[s[x].l]++, dd[s[x].r + 1]--;
	}
	int f = -1;
	rep(i, 1, M){
		dd[i] += dd[i - 1];
		if (dd[i] == cs){
			f = i;
			break;
		}
	}
	printf("%d %d\n", cs, f);
	rep(i, 1, cs) printf("%d ", ans[i]);
	return 0;
}

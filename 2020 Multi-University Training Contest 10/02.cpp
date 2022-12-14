#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 2020
#define maxm 4020
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

const int inf = 2000000000;

struct graph{ 
	#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
	#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
	int S, T;
	struct edge{
		int next, to, flow;
		edge(int next, int to, int flow) : next(next), to(to), flow(flow){}
		edge(){}
	}e[maxm << 2];
	int cnt = 1, h[maxn];
	void Add_Edge(int x, int y, int z){
		e[++cnt] = edge(h[x], y, z);
		h[x] = cnt;
		e[++cnt] = edge(h[y], x, 0);
		h[y] = cnt;
	}
	int bfs[maxn], d[maxn], cur[maxn], he = 0, ta = 0;
	bool BFS(){
		he = ta = 0;
		rep(i, 1, T) d[i] = -1, cur[i] = h[i];
		d[S] = 0;
		bfs[++he] = S;
		while (he != ta){
			int x = bfs[++ta];
			erep(i, x){
				if (!e[i].flow || d[e[i].to] != -1) continue;
				int op = e[i].to;
				bfs[++he] = op;
				d[op] = d[x] + 1;
			}
		}
		return d[T] != -1;
	}
	int DFS(int x, int flow){
		if (x == T) return flow;
		int rest = flow;
		erep2(i, x){
			if (!e[i].flow || d[e[i].to] != d[x] + 1) continue;
			int op = e[i].to, k = DFS(op, min(e[i].flow, rest));
			e[i].flow -= k, e[i ^ 1].flow += k, rest -= k;
			if (!rest) return flow;
		}
		return flow - rest;
	}
	void Dinic(int& maxflow){ while (BFS()) maxflow += DFS(S, inf); }
	void recover(){
		cnt = 1; rep(i, 1, T) h[i] = 0;
	}
}G0, G;

int n, m;

void recover(){
	rep(i, 1, n) G.h[i] = G0.h[i]; G.cnt = G0.cnt;
	rep(i, 1, G0.cnt) G.e[i] = G0.e[i];
}
pii e[maxn];

int main(){
	int T, x, y; scanf("%d", &T);
	while (T--){
		scanf("%d%d", &n, &m);
		rep(i, 1, m) scanf("%d%d", &x, &y), G0.Add_Edge(x, y, 1), G0.Add_Edge(y, x, 1), e[i] = pii(x, y);
		int ans = 0;
		G.S = G.T = 0, G0.T = n;
		rep(i, 1, m){
			recover();
			G.S = n + 1, G.T = n + 2;
			G.h[G.S] = G.h[G.T] = 0;
			G.Add_Edge(G.S, e[i].fi, inf), G.Add_Edge(e[i].se, G.T, inf);
			int maxflow = 0;
			G.Dinic(maxflow);
			ans = max(ans, maxflow);
		}
		printf("%d\n", ans);
		G.recover(), G0.recover();
	}
	return 0;
}

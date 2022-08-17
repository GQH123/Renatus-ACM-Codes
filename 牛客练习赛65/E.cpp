#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define maxn 20020
#define maxm 200020
#define pii pair<int, int>
#define ll long long int 
using namespace std;

const int inf = 2000000020;

int n, m, q, S, T;
int a[maxn], b[maxn], c[maxm], dd[maxm];

struct edge{
	int next, to, flow;
	ll cost;
	edge(int next, int to, int flow, ll cost) : next(next), to(to), flow(flow), cost(cost){}
	edge(){}
}e[maxm << 1];
int cnt = 1, h[maxn];
void Add_Edge(int x, int y, int f, ll c){
	e[++cnt] = edge(h[x], y, f, c);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x, 0, -c);
	h[y] = cnt;
}
int spfa[maxn], head = 0, tail = 0;
int p[maxn];
ll d[maxn];
bool vis[maxn];
bool SPFA(){
	head = tail = 0;
	rep(i, S, T) d[i] = (ll)inf * inf;
	d[S] = 0;
	spfa[++head] = S;
	vis[S] = 1;
	while (head != tail){
		int x = spfa[++tail];
		if (tail == maxn - 1) tail = 0;
		erep(i, x){
			if (!e[i].flow) continue;
			int op = e[i].to;
			if (d[op] > d[x] + e[i].cost){
				d[op] = d[x] + e[i].cost;
				p[op] = i;
				if (!vis[op]){
					vis[op] = 1;
					spfa[++head] = op;
					if (head == maxn - 1) head = 0;
				}
			}
		}
		vis[x] = 0;
	}
	return d[T] != (ll)inf * inf;
}
void Augment(int& maxflow, ll& mincost){
	int flow = inf, now = T;
	while (now != S){
		int k = p[now];
		flow = min(flow, e[k].flow);
		now = e[k ^ 1].to;
	}
	now = T;
	while (now != S){
		int k = p[now];
		e[k].flow -= flow, e[k ^ 1].flow += flow;
		now = e[k ^ 1].to;
	}
	maxflow += flow, mincost += (ll)flow * (d[T] - d[S]);
}
void MCMF(int& maxflow, ll& mincost){
	while (SPFA()) Augment(maxflow, mincost);
}

int main(){
	int x, y;
	scanf("%d%d%d", &n, &m, &q);
	rep(i, 1, n) scanf("%d%d", a + i, b + i);
	rep(i, 1, m) scanf("%d%d", c + i, dd + i);
	S = 1, T = 2 + 2 * n;
	rep(i, 1, n){
		rep(j, 1, q){
			Add_Edge(i << 1, i << 1 | 1, 1, a[i] + (j - 1) * b[i]);
		}
	}
	rep(i, 1, m){
		Add_Edge(c[i] << 1 | 1, dd[i] << 1, inf, 0);
		Add_Edge(dd[i] << 1 | 1, c[i] << 1, inf, 0);
	}
	rep(i, 1, q){
		scanf("%d", &x);
		Add_Edge(S, x << 1, 1, 0);
	}
	rep(i, 1, q){
		scanf("%d", &x);
		Add_Edge(x << 1 | 1, T, 1, 0);
	}
	int maxflow = 0;
	ll mincost = 0;
	MCMF(maxflow, mincost);
	printf("%lld", mincost);
	//printf("\n%d", maxflow);
	return 0;
}

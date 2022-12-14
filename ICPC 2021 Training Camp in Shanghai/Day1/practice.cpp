#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int 
#define maxn 10020
#define maxm 200020
#define pii pair<int, int>
#define fi first
#define se second
#define inf 2000000020
using namespace std;

int n, m;
struct edge{
    int next, to, flow, cost;
    edge(int next, int to, int flow, int cost) : next(next), to(to), flow(flow), cost(cost){}
    edge(){}
}e[maxm << 1];
int cnt = 1, h[maxn], S, T, all;
void Add_Edge(int x, int y, int w, int z) {
    e[++cnt] = edge(h[x], y, w, z);
    h[x] = cnt;
    e[++cnt] = edge(h[y], x, 0, -z);
    h[y] = cnt;
}
int d[maxn]; bool vis[maxn];
int spfa[maxn << 1], p[maxn];
int head, tail = 0;
bool SPFA(int s, int t){
    tail = head = 0;
    rep(i, 1, all) d[i] = -1, vis[i] = 0;
    d[s] = 0; spfa[++head] = s;
    vis[s] = 1;
    while (tail < head) {
    	int x = spfa[++tail];
    	tail = (tail == maxn - 1) ? 0 : tail;
    	erep(i, x) {
    		if (!e[i].flow) continue;
    		int op = e[i].to;
    		if (d[op] == -1 || d[op] > d[x] + e[i].cost) {
    			p[op] = i;
    			d[op] = d[x] + e[i].cost;
    			if (!vis[op]) {
    				vis[op] = 1, spfa[++head] = op;
    				head = (head == maxn - 1) ? 0 : head;
    			}
    		}
    	}
    	vis[x] = 0;
    }
    return d[t] != -1;
}
void Augment(int& maxflow, int& mincost) {
	int flow = inf, now = T;
	while (now != S) {
		int k = p[now];
		flow = min(flow, e[k].flow);
		now = e[k ^ 1].to;
	}
	now = T;
	while (now != S) {
		int k = p[now];
		e[k].flow -= flow, e[k ^ 1].flow += flow;
		now = e[k ^ 1].to;
	}
	maxflow += flow, mincost += flow * (d[T] - d[S]);
}
void MCMF(int& maxflow, int& mincost) {
    while (SPFA(S, T)) Augment(maxflow, mincost);
}

int main(){
	scanf("%d%d%d%d", &n, &m, &S, &T); all = n;
	int x, y, z, w;
	rep(i, 1, m) {
		scanf("%d%d%d%d", &x, &y, &z, &w);
		Add_Edge(x, y, z, w);
	}
	int maxflow = 0, mincost = 0;
	MCMF(maxflow, mincost);
	printf("%d %d\n", maxflow, mincost);
    return 0;
}


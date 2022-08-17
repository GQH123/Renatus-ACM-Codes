#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int
#define maxn 320
#define maxm 30020
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define eps 1e-4
#define tm TM
using namespace std;

const int inf = 2000000020;

int n, s, t;
struct edge{
	int next, to, flow;
	double cost;
	edge(int next, int to, int flow, double cost) : next(next), to(to), flow(flow), cost(cost){}
	edge(){}
}e[maxm << 1];
int h[maxn], cnt = 1;
void Add_Edge(int x, int y, int z, double w){
	e[++cnt] = edge(h[x], y, z, w);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x, 0, -w);
	h[y] = cnt;
}

bool vis[maxn];
double d[maxn];
int spfa[maxn];
int tims[maxn];
int p[maxn];
int tm = 0;
int head = 0, tail = 0;
bool SPFA(){
	tims[s] = ++tm;
	head = tail = 0;
	spfa[++head] = s;
	d[s] = 0, vis[s] = 1;
	
	while (head != tail){
		int x = spfa[++tail];
		tail = (tail == maxn - 1) ? 0 : tail;
		erep(i, x){
			if (!e[i].flow) continue;
			int op = e[i].to;
			if (d[op] > d[x] + e[i].cost || tims[op] != tm){
				tims[op] = tm;
				d[op] = d[x] + e[i].cost;
				p[op] = i;
				if (!vis[op]) {
					vis[op] = 1;
					spfa[++head] = op;
					head = (head == maxn - 1) ?  0 : head;
				}
			}
		}
		vis[x] = 0;
	}
	return tims[t] == tm;
}
void Augment(int& maxflow, double& mincost){
	int flow = inf, now = t;
	while (now != s){
		int k = p[now];
		flow = min(flow, e[k].flow);
		now = e[k ^ 1].to;
	}
	now = t;
	while (now != s){
		int k =	p[now];
		e[k].flow -= flow, e[k ^ 1].flow += flow;
		now = e[k ^ 1].to;
	}
	maxflow += flow, mincost += (d[t] - d[s]) * flow;
}
void MCMF(int& maxflow, double& mincost){	
	while (SPFA()) Augment(maxflow, mincost);
}

int ans[maxn];
int main(){
	freopen("G.in", "r", stdin);
	int x;
	scanf("%d", &n);
	s = 0, t = 2 * n + 1;
	rep(i, 1, n) Add_Edge(s, i, 1, 0), Add_Edge(i + n, t, 1, 0);
	rep(i, 1, n) rep(j, 1, n) scanf("%d", &x), Add_Edge(i, j + n, 1, -log(x));
	int maxflow = 0; double mincost;
	MCMF(maxflow, mincost);
	assert(maxflow == n);
	rep(x, 1 + n, 2 * n){
		erep(i, x){
			if (1 <= e[i].to && e[i].to <= n && e[i].flow == 1){
				ans[x - n] = e[i].to;
				break;
			}
		}
	}
	rep(i, 1, n) printf("%d ", ans[i]);
	return 0;
}


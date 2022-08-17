#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define maxn 220
#define ll long long int 
#define inf -1
using namespace std;


int n, S, T; ll m;
struct edge{
	int next, to, flow; ll cost;
	edge(int next, int to, int flow, ll cost) : next(next), to(to), flow(flow), cost(cost){}
	edge(){}
}e[500 * maxn];
int cnt = 1, h[500 * maxn];
void Add_Edge(int x, int y, int z, ll w){
	e[++cnt] = edge(h[x], y, z, w);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x, 0, -w);
	h[y] = cnt;
}
int p[500 * maxn];
ll d[500 * maxn];
bool vis[500 * maxn];
int head, tail, spfa[500 * maxn];
bool mod[500 * maxn];
bool SPFA(){
	rep(i, S, T) vis[i] = 0, p[i] = -1, mod[i] = 0;
	vis[S] = 1, d[S] = 0;
	head = tail = 0;
	spfa[++head] = S;
	while (head != tail){
		int x = spfa[++tail];
		erep(i, x){
			if (!e[i].flow) continue;
			int y = e[i].to;
			if (!mod[y] || d[y] > d[x] + e[i].cost){
				mod[y] = 1;
				d[y] = d[x] + e[i].cost;
				p[y] = i;
				if (!vis[y]) spfa[++head] = y, vis[y] = 1;
			}
		}
		vis[x] = 0;
	}
	return mod[T];
}

void Augment(int& maxflow, ll& mincost){
	int flow = n + 5, now = T;
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
	maxflow += flow, mincost += flow * (d[T] - d[S]);
}

void MCMF(int& maxflow, ll& mincost){
	while (SPFA()) Augment(maxflow, mincost);
}

inline ll cal(ll a, ll b, ll c, ll x){
	return a * x * x + b * x + c;
}

ll lis[500 * maxn], cs = 0;
ll x[maxn], y[maxn], z[maxn];

void recover(){
	cs = 0; cnt = 1;
	rep(i, S, T) h[i] = 0;
}

int main(){
	int TT; scanf("%d", &TT); 
	while (TT--){
		S = 1; // 2, 2 + (1 ~ n), 2 + n + (1 ~ cs), T = 2 + n + cs + 1
		scanf("%d%lld", &n, &m);
		rep(j, 1, n) {
			scanf("%lld%lld%lld", x + j, y + j, z + j);
			ll mid = (-y[j] / (x[j] << 1));
			if (mid < 1) {
				for (ll i = 1; i <= min(100ll, m); i++) lis[++cs] = i; 
			}
			else if (mid > m) {
				for (ll i = m; i >= max(1ll, m - 99); i--) lis[++cs] = i;
			}
			else {
				for (ll i = max(1ll, mid - 50); i <= min(m, mid + 50); i++) lis[++cs] = i;
			}
		}
		sort(lis + 1, lis + 1 + cs);
		cs = unique(lis + 1, lis + 1 + cs) - lis -  1;
		T = 2 + n + cs + 1;  
		rep(i, 1, cs) Add_Edge(2 + n + i, T, 1, 0);
		rep(i, 1, n) Add_Edge(S + 1, 2 + i, 1, 0);
		rep(i, 1, n) { 
			ll mid = (-y[i] / (x[i] << 1));
			if (mid < 1) {
				for (ll j = 1; j <= min(100ll, m); j++) {
					Add_Edge(2 + i, 2 + n + lower_bound(lis + 1, lis + 1 + cs, j) - lis, 1, cal(x[i], y[i], z[i], j));
				}
			}
			else if (mid > m) {
				for (ll j = m; j >= max(1ll, m - 99); j--) {
					Add_Edge(2 + i, 2 + n + lower_bound(lis + 1, lis + 1 + cs, j) - lis, 1, cal(x[i], y[i], z[i], j));
				}
			}
			else {
				for (ll j = max(1ll, mid - 50); j <= min(m, mid + 50); j++) {
					Add_Edge(2 + i, 2 + n + lower_bound(lis + 1, lis + 1 + cs, j) - lis, 1, cal(x[i], y[i], z[i], j));
				}
			}
		}
		
		int maxflow = 0; ll mincost = 0;
		rep(i, 1, n){
			Add_Edge(S, S + 1, 1, 0);
			MCMF(maxflow, mincost);
			//cerr << maxflow << ' ' << mincost << endl;
			if (i != 1) printf(" %lld", mincost);
			else printf("%lld", mincost);
		}
		printf("\n");
		recover(); 
	}
	return 0;
}

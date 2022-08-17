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
#define maxr 100000
#define maxn 2020
#define maxm 20020
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

int const inf = 2000000020;

int n, m, p, s, t;
struct edge{
	int next, to, flow;
	edge(int next, int to, int flow) : next(next), to(to), flow(flow){}
	edge(){}
}e[maxm << 1];
int cnt = 1, h[maxn];
void Add_Edge(int x, int y, int z){
	e[++cnt] = edge(h[x], y, z);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x, 0);
	h[y] = cnt;
}

int d[maxn];
int cur[maxn];
int bfs[maxn];
int head = 0, tail = 0;
bool BFS(){
	head = tail = 0;
	bfs[++head] = s;
	rep(i, s, t) d[i] = -1, cur[i] = h[i];
	d[s] = 0;
	while (head != tail){
		int x = bfs[++tail];
		erep(i, x){
			if (!e[i].flow) continue;
			int op = e[i].to;
			if (d[op] != -1) continue;
			d[op] = d[x] + 1;
			bfs[++head] = op;
		}
	}
	if (d[t] == -1) return false;
	return true;
}
int DFS(int x, int flow){
	if (x == t) return flow;
	int rest = flow;
	for (register int& i = cur[x]; i; i = e[i].next){
		if (!e[i].flow) continue;
		int op = e[i].to;
		if (d[op] != d[x] + 1) continue;
		int k = DFS(op, min(flow, e[i].flow));
		e[i].flow -= k, e[i ^ 1].flow += k, rest -= k;
		if (!rest) return flow;
	}
	return flow - rest;
}
int Dinic(){
	int maxflow = 0;
	while (BFS()) maxflow += DFS(s, inf);
	return maxflow;
}

int main(){
	
		#ifndef ONLINE_JUDGE
			freopen("I.in", "r", stdin);
		#endif
	int x, k;
	scanf("%d%d%d", &n, &m, &p);
	s = 0, t = n + m + p + 1;
	rep(i, 1, n) Add_Edge(s, i, 1);
	rep(i, 1, n) {
		scanf("%d", &k);
		rep(i, 1, k) scanf("%d", &x), Add_Edge(i, n + x, 1);
	}
	
	rep(i, 1, p){
		scanf("%d", &k);
		rep(i, 1, k) scanf("%d", &x), Add_Edge(n + x, n + m + i, 1);
		scanf("%d", &k);
		Add_Edge(n + m + i, t, k);
	}
	//int maxflow = Dinic();
	printf("%d", Dinic());
	return 0;
}

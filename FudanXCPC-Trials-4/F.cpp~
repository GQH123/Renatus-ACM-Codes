#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
#define maxn 520
#define maxm 20020
using namespace std;

const int inf = 2000000000;

int n, m, S, T;
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
int d[maxn], he = 0, ta = 0, bfs[maxn], cur[maxn];
bool BFS(){
	he = ta = 0;
	rep(i, S, T) d[i] = -1, cur[i] = h[i];
	d[S] = 0, bfs[++he] = S;
	while (he != ta){
		int x = bfs[++ta];
		erep(i, x){	
			if (!e[i].flow || d[e[i].to] != -1) continue;
			int op = e[i].to;
			d[op] = d[x] + 1, bfs[++he] = op;
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
void Dinic(int& maxflow) {
	maxflow = 0;
	while (BFS()) maxflow += DFS(S, inf);
}

int sumD[maxn][2];

void recover(){
	rep(i, S, T) sumD[i][0] = sumD[i][1] = h[i] = 0;
	cnt = 1;
}

int main(){
	int t, x, y, D, B; scanf("%d", &t);
	rep(TT, 1, t){
		printf("Case #%d: ", TT);
		scanf("%d%d", &n, &m);
		int allD = 0;
		S = 1, T = n + 2;
		rep(i, 1, m) {
			scanf("%d%d%d%d", &x, &y, &D, &B), allD += D;
			Add_Edge(x + 1, y + 1, B);
			sumD[x][0] += D, sumD[y][1] += D; 
		}
		rep(x, 1, n) {
			if (sumD[x][0]) Add_Edge(x + 1, T, sumD[x][0]);
			if (sumD[x][1]) Add_Edge(S, x + 1, sumD[x][1]);
		}
		int maxflow = 0; Dinic(maxflow);
		if (maxflow < allD) printf("unhappy\n");
		else printf("happy\n");
		recover();
	}
	return 0;
}

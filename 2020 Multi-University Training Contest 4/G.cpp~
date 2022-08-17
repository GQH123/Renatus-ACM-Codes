#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define maxn 400020
#define maxm 600020
using namespace std;

int n, m, S, T;

struct edge{
	int next, to, flow;
	edge(int next, int to, int flow) : next(next), to(to), flow(flow){}
	edge(){}
}e[maxm << 1];
int cnt = 1, h[maxn], cur[maxn];
void Add_Edge(int x, int y, int z){
	e[++cnt] = edge(h[x], y, z);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x, 0);
	h[y] = cnt;
}
int bfs[maxn], head = 0, tail = 0;
int d[maxn];
bool BFS(){
	head = tail = 0;
	rep(i, S, T) d[i] = -1, cur[i] = h[i];
	d[S] = 0;
	bfs[++head] = S;
	while (head != tail){
		int x = bfs[++tail];
		erep(i, x){
			if (!e[i].flow) continue;
			int op = e[i].to;
			if (d[op] == -1) d[op] = d[x] + 1, bfs[++head] = op;
		}
	}
	return d[T] != -1;
}
int DFS(int x, int flow){
	if (x == T) return flow;
	int rest = flow;
	erep2(i, x){
		if (!e[i].flow || d[e[i].to] != d[x] + 1) continue;
		int op = e[i].to;
		int k = DFS(op, min(rest, e[i].flow));
		e[i].flow -= k, e[i ^ 1].flow += k, rest -= k;
		if (!rest) return flow;
	}
	return flow - rest;
}
int Dinic(){
	int maxflow = 0;
	while (BFS()) maxflow += DFS(S, n + 5);
	return maxflow;
}
int lisx[maxn], lisy[maxn], cx = 0, cy = 0;
int t[maxn], x[maxn];
void recover(){
	rep(i, S, T) h[i] = 0;
	cnt = 1;
	cx = cy = 0;
}


int main(){
	int TT, xx, y; scanf("%d", &TT);
	while (TT--){
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d%d", t + i, x + i), lisx[i] = x[i] - t[i], lisy[i] = x[i] + t[i];
		sort(lisx + 1, lisx + 1 + n);
		cx = unique(lisx + 1, lisx + 1 + n) - lisx - 1;
		sort(lisy + 1, lisy + 1 + n);
		cy = unique(lisy + 1, lisy + 1 + n) - lisy - 1;
		S = 1, T = 1 + cx + cy + 1; //1, 1 + (1 ~ cx), 1 + cx + (1 ~ cy), 1 + cx + cy + 1
		rep(i, 1, cx) Add_Edge(S, 1 + i, 1);
		rep(i, 1, cy) Add_Edge(1 + cx + i, T, 1);
		rep(i, 1, n) {
			xx = lower_bound(lisx + 1, lisx + 1 + cx, x[i] - t[i]) - lisx;
			y = lower_bound(lisy + 1, lisy + 1 + cy, x[i] + t[i]) - lisy;
			Add_Edge(1 + xx, 1 + cx + y, 1);
		}
		printf("%d\n", Dinic());
		recover();
	}
	return 0;
}

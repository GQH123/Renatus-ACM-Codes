#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define maxn 200020
using namespace std;

int n, m;
struct edge{
	int next, to;
	edge(int next, int to) : next(next), to(to){}
	edge(){}
}e[maxn << 1];
int cnt = 1, h[maxn], out[maxn];
void Add_Edge(int x, int y){
	//e[++cnt] = edge(h[x], y);
	//h[x] = cnt;
	e[++cnt] = edge(h[y], x);
	h[y] = cnt;
	out[x]++;
} 
int ti[maxn], bfs[maxn];
int head = 0, tail = 0;
void topo_sort(){
	head = tail = 0; 
	rep(i, 1, n) if (!out[i]) bfs[++head] = i, ti[i] = 1;
	while (head > tail){
		int x = bfs[++tail];
		erep(i, x){
			int op = e[i].to;
			out[op]--;
			if (!out[op]) ti[op] = ti[x] + 1, bfs[++head] = op;
		}
	}
	int ans = 0;
	rep(x, 1, n){	
		erep(i, x){
			int op = e[i].to;
			if (ti[op] > ti[x] + 1) ans++;
		}
		//printf("%d ", ti[x]);
	}
	printf("%d\n", ans);
}

int main(){
	int T, x, y;
	scanf("%d", &T);
	while (T--){
		scanf("%d%d", &n, &m);
		rep(i, 1, n) out[i] = h[i] = 0; cnt = 1;
		rep(i, 1, m) scanf("%d%d", &x, &y), Add_Edge(x, y);
		topo_sort();
	}
	return 0;
}

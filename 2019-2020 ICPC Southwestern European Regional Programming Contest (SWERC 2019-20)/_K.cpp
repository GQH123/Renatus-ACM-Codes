#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define maxn 200020
#define maxm 200020
using namespace std;

int n, m, T;
struct edge{
	int next, to;
	edge(int next, int to) : next(next), to(to){}
	edge(){}
}e[maxm << 1];
int cnt = 1, h[maxn];
void Add_Edge(int x, int y){
	e[++cnt] = edge(h[x], y);
	h[x] = cnt;
	//e[++cnt] = edge(h[y], x);
	//h[y] = cnt;
}

int tag[maxn];

void DFS(int x, int id){
	if (x == T || tag[x] == id || tag[x] == -1) return;
	if (!tag[x]) tag[x] = id;
	else tag[x] = -1;
	erep(i, x){
		int op = e[i].to;
		DFS(op, id);
	}
}

int ans[maxn], cs = 0;

int main(){
	int x, y;
	scanf("%d%d%d", &n, &m, &T), T++;
	rep(i, 1, m) scanf("%d%d", &x, &y), x++, y++, Add_Edge(y, x);
	erep(i, T){
		int op = e[i].to;
		DFS(op, op);
	}
	erep(i, T){	
		int op = e[i].to;
		if (tag[op] != 0 && tag[op] != -1) ans[++cs] = op;
	}
	/*
	rep(i, 1, n){
		//cerr << tag[i] << ' ';
		if (tag[i] != 0 && tag[i] != -1){
			ans[++cs] = i;
		}
	}
	//cerr << endl;
	*/
	sort(ans + 1, ans + 1 + cs);
	printf("%d\n", cs);
	rep(i, 1, cs){
		printf("%d\n", ans[i] - 1);
	}
	return 0;
}

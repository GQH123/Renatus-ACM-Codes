#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define maxn 3020
#define maxm 60020
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, m;
struct edge{
	int next, to;
	edge(int next, int to) : next(next), to(to){}
	edge(){}
}e[maxm];
int cnt = 1, h[maxn], in[maxn];
void Add_Edge(int x, int y){
	e[++cnt] = edge(h[x], y);
	h[x] = cnt;
	in[y]++;
}
int bfs[maxn];
int tim[maxn];
int ord = 0;
int he = 0, ta = 0;
void topo_sort(){
	ord = he = ta = 0;
	rep(i, 1, n) if (!in[i]) bfs[++he] = i;
	while (he != ta){
		int x = bfs[++ta];
		tim[x] = ++ord;
		erep(i, x){
			int op = e[i].to;
			in[op]--;
			if (!in[op]) bfs[++he] = op;
		}	
	}
}

bool cmp(const int i, const int j){
	return tim[i] < tim[j];
}
bool vis[maxn];
int nod[maxn];
int cn = 0;
void DFS(int x){
	vis[x] = 1;
	erep(i, x){
		int op = e[i].to;
		if (vis[op]) continue;
		DFS(op);
	}
}

void recover(){
	cnt = 1;
	rep(i, 1, n) h[i] = in[i] = 0;
}



int main(){

		freopen("C.in", "r", stdin);
	
	int T, x, y;
	scanf("%d", &T);
	while (T--){
		scanf("%d%d", &n, &m);
		rep(i, 1, m) scanf("%d%d", &x, &y), Add_Edge(x, y);
		topo_sort();
		int ans = 0;
		rep(x, 1, n){
			cn = 0;
			erep(i, x) nod[++cn] = e[i].to;
			sort(nod + 1, nod + 1 + cn, cmp);
			rep(i, 1, cn){
				int y = nod[i];
				if (vis[y]) ans++;
				else DFS(y);
			}
			rep(i, 1, n) vis[i] = 0;
		}
		printf("%d\n", ans);
		recover();
	}
	return 0;
}

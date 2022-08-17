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
#define lowbit(x) (x & -x) 
#define maxn 60020
#define maxm 300020
using namespace std;

int n, m;
struct edge{
	int next, to, id;
	edge(int next, int to, int id) : next(next), to(to), id(id){}
	edge(){}
}e[maxm];
int h[maxn], cnt = 1, in[maxn];
void Add_Edge(int x, int y, int id){
	e[++cnt] = edge(h[x], y, id);
	h[x] = cnt; 
	in[y]++;
}
int bfs[maxn], ord[maxn], lis[maxn], he = 0, ta = 0, ti = 0;
char ans[maxm];
inline int get_small(int x){
	return (ord[x] - 1) / 42 + 1;
}
inline int get_big(int x){
	return (ord[x] - 1) / 1764 + 1;
}
void work(){
	rep(i, 1, n) if (!in[i]) bfs[++he] = i; 
	while (he != ta){
		int x = bfs[++ta];
		ord[x] = ++ti;
		lis[ti] = x;
		erep(i, x){
			int op = e[i].to;
			in[op]--;
			if (!in[op]) bfs[++he] = op;
		}
	}
	rep(x, 1, n){
		erep(i, x){
			int op = e[i].to;
			if (get_small(op) == get_small(x)) ans[e[i].id] = 'R';
			else if (get_big(op) == get_big(x)) ans[e[i].id] = 'G';
			else ans[e[i].id] = 'B';
		}
	}
}

int main(){
	
		freopen("D.in", "r", stdin);
		
	int x, y;
	scanf("%d%d", &n, &m);
	rep(i, 1, m) scanf("%d%d", &x, &y), Add_Edge(x, y, i);
	work();
	//rep(i, 1, n) printf("%d ", ord[i]);
	rep(i, 1, m) printf("%c\n", ans[i]);
	return 0;
}

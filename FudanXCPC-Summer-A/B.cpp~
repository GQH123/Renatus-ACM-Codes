#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define maxn 10020
#define maxm 10020
#define M 
#define ll long long int 
#define ld long double
#define pb push_back
#define pc putchar
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define lowbit(x) (x & -x)
using namespace std;

int n, m; pii ee[maxm];
struct edge{
	int next, to;
	edge(int next, int to) : next(next), to(to){}
	edge(){}
}e[maxm << 1];
int cnt = 1, h[maxn], deg[maxn];
void Add_Edge(int x, int y){
	e[++cnt] = edge(h[x], y);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x);
	h[y] = cnt;
	deg[x]++, deg[y]++;
}
int t = 0, dfs[maxn], low[maxn], is_u[maxn];
void clear_graph(){
	cnt = 1; t = 0;
	rep(i, 1, n) deg[i] = is_u[i] = h[i] = dfs[i] = low[i] = 0;
}
int Tarjan(int x, int fa){ 
	dfs[x] = low[x] = ++t;
	erep(i, x){
		int op = e[i].to; 
		if (!dfs[op]) {
			int dd = Tarjan(op, x);
			low[x] = min(low[x], dd);
			if (dfs[x] <= dd) is_u[x]++;
		}
		else low[x] = min(dfs[op], low[x]);
	} 
	return low[x];
}

int main(){
	int x, y;
	while (scanf("%d%d", &n, &m) == 2){ 
		rep(i, 1, m){
			scanf("%d%d", &x, &y), x++, y++;
			ee[i] = pii(x, y);
		}
		int res = 1;
		rep(S, 1, n){
			clear_graph();
			rep(i, 1, m){
				int x = ee[i].fi, y = ee[i].se;
				if (x == S || y == S) continue;
				Add_Edge(x, y);
			}
			int ans = 0;
			
			rep(i, 1, n){
				if (i == S || dfs[i]) continue;
				ans++;
				Tarjan(i, -1);
				is_u[i]--;
			}
			//cerr << S << ":" << ans << endl;
			int mx = -1;
			rep(i, 1, n){
				if (i == S) continue;
				mx = max(mx, is_u[i]);
			}
			res = max(res, ans + mx);
			//if (res == 3) cerr << S << endl;
		}
		printf("%d\n", res); 
	} 
	return 0;
}

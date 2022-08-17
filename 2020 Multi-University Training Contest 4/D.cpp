#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int 
#define maxn 200020
#define maxm 400020
using namespace std;

const ll inf = 0x3f3f3f3f3f3f3f3fll;

int n, m, s, t, xx, a[maxn];
struct edge{
	int next, to, len;
	edge(int next, int to, int len) : next(next), to(to), len(len){}
	edge(){}
}e[maxm << 1];
int h[maxn], cnt = 1;
void Add_Edge(int x, int y, int z){
	e[++cnt] = edge(h[x], y, z);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x, z);
	h[y] = cnt;
}

/*
int tim = 0;
int vis[maxn][2];
ll dp[maxn][2];
ll DP(int pos, int op){
	if (pos == s) return 0;
	if (vis[pos][op] < 0) return inf;
	if (vis[pos][op] == tim) return dp[pos][op];
	vis[pos][op] = -tim;
	ll& ans = dp[pos][op]; ans = inf;
	erep(i, pos){
		int v = e[i].to, eff = 0;
		if (a[v] != -1 && a[v] != op) eff = xx;
		ans = min(ans, DP(v, (eff) ? (op ^ 1) : op) + e[i].len + eff);
	}
	vis[pos][op] = tim;
	return ans;
}
*/

ll d[maxn][2];
bool vis[maxn][2];
struct ele{
	int x, op; ll d;
	ele(int x, int op, ll d) : x(x), op(op), d(d){}
	ele(){}
	bool operator < (const ele b) const{
		return d > b.d;
	}
};
priority_queue<ele> pq;
void Dij(){ 
	rep(i, 1, n) d[i][0] = d[i][1] = inf, vis[i][0] = vis[i][1] = 0;
	if (a[s] == -1) pq.push(ele(s, 0, 0)), pq.push(ele(s, 1, 0)), d[s][0] = d[s][1] = 0;
	else pq.push(ele(s, a[s], 0)), d[s][a[s]] = 0;
	while (!pq.empty()) {
		ele op = pq.top(); pq.pop();
		if (vis[op.x][op.op] || op.d != d[op.x][op.op]) continue;
		vis[op.x][op.op] = 1;
		int x = op.x; ll dd = op.d;
		erep(i, x){ 
			int u = e[i].to, eff = 0, _op = op.op;
			if (a[u] != -1 && a[u] != op.op) eff = xx, _op = a[u];
			if (dd + e[i].len + eff < d[u][_op]) {
				d[u][_op] = dd + e[i].len + eff;
				pq.push(ele(u, _op, d[u][_op]));
			}
		}
	}
	if (a[t] == -1) printf("%lld\n", min(d[t][0], d[t][1]));
	else printf("%lld\n", d[t][a[t]]);
}

void recover(){
	cnt = 1;
	rep(i, 1, n) h[i] = 0;
}

char ss[maxn];
int main(){
	int T, x, y, z; scanf("%d", &T);
	while (T--){
		//++tim;
		scanf("%d%d%d%d%d", &n, &m, &s, &t, &xx);
		scanf("%s", ss + 1);
		rep(i, 1, n) a[i] = -1;
		rep(i, 1, n) {
			if (ss[i] == 'L') a[i] = 0;
			else if (ss[i] == 'R') a[i] = 1; 
		}
		rep(i, 1, m) {
			scanf("%d%d%d", &x, &y, &z);
			Add_Edge(x, y, z);
		}
		Dij();
		/*
		if (a[t] == -1) printf("%lld\n", min(DP(t, 0), DP(t, 1)));
		else printf("%lld\n", DP(t, a[t]));
		*/
		recover();
	}
	return 0;
}

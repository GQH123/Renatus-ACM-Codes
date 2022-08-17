#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define maxn 50020
#define maxm
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n;
struct edge{
	int next, to;
	edge(int next, int to) : next(next), to(to){}
	edge(){}
}e[maxn << 1];
int h[maxn], cnt = 1;
void Add_Edge(int x, int y){
	e[++cnt] = edge(h[x], y);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x);
	h[y] = cnt;
}
int cp = 0;
int p[maxn];
bool vp[maxn];
void init(){
	srep(i, 2, maxn) {
		if (!vp[i]) p[++cp] = i;
		rep(j, 1, cp){
			if (i * p[j] >= maxn) break;
			vp[i * p[j]] = 1;
			if (i % p[j] == 0) break;
		}
	}
}
int ns;
int s[maxn];
int g;
bool vis[maxn];
void DFS(int x, int fa){	
	s[x] = 1;
	bool f = 1;
	erep(i, x){
		int op = e[i].to;
		if (op == fa || vis[op]) continue;
		DFS(op, x);
		s[x] += s[op];
		if (s[op] > (ns >> 1)) f = 0; 
	}
	if (ns - s[x] > (ns >> 1)) f = 0;
	if (f) g = x;
}
int d[maxn];
ll num[maxn];
int mx = 0;
void DFS(int x, int fa, ll& ans){
	rep(i, 1, cp){
		if (p[i] < d[x]) continue;
		if (p[i] - d[x] > mx) break;
		ans += num[p[i] - d[x]];
		//if (num[p[i] - d[x]]) printf("%d\n", p[i]);
	}
	erep(i, x){
		int op = e[i].to;
		if (vis[op] || op == fa) continue;
		d[op] = d[x] + 1;
		DFS(op, x, ans);
	}
}
void DFS(int x, int fa, int dd){
	num[d[x]] += dd;
	mx = max(mx, d[x]);
	erep(i, x){
		int op = e[i].to;
		if (vis[op] || op == fa) continue;
		DFS(op, x, dd);
	}
}
ll solve(int x){
	DFS(x, x);
	x = g;
	vis[x] = 1; 
	ll ans = 0;
	d[x] = 0;
	mx = 0;
	num[0]++;
	erep(i, x){
		int op = e[i].to;
		if (vis[op]) continue;
		d[op] = d[x] + 1;
		DFS(op, x, ans);
		DFS(op, x, 1);
	}
	num[0]--;
	erep(i, x){
		int op = e[i].to;
		if (vis[op]) continue; 
		DFS(op, x, -1);
	}
	int _ns = ns;
	erep(i, x){
		int op = e[i].to;
		if (vis[op]) continue;
		ns = (s[op] > s[x]) ? (ns - s[x]) : s[op];
		ans += solve(op);
		ns = _ns;
	}
	return ans;
}

int main(){
	
		freopen("A.in", "r", stdin);
		
	init();
	int x, y;
	scanf("%d", &n);
	srep(i, 1, n) scanf("%d%d", &x, &y), Add_Edge(x, y);
	ns = n;
	//printf("%lld", solve(1));
	printf("%lf", (double)solve(1) / ((ll)n * (n - 1) >> 1));
	return 0;
}

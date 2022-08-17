#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define maxn 300020
#define maxm
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define div DIV
using namespace std;


int p[maxn], son[maxn], mu[maxn], cp = 0;
bool vp[maxn];
void get_prime(int mx){	
	mu[1] = 1;
	rep(i, 2, mx) {
		if (!vp[i]) p[++cp] = i, mu[i] = -1;
		rep(j, 1, cp){
			if (p[j] * i > mx) break;
			vp[i * p[j]] = 1;
			if (i % p[j] == 0) {
				mu[i * p[j]] = 0;
				break;
			}
			mu[i * p[j]] = -mu[i];
		}
	}
}
vector<int> div[maxn];
inline void get_div(int mx){
	rep(i, 1, mx) for (register int j = i; j <= mx; j += i) div[j].pb(i); 
}
int gcd(int x, int y){
	return (!y) ? x : gcd(y, x % y);
}

int n;
int a[maxn];
struct edge{
	int next, to;
	edge(int next, int to) : next(next), to(to){}
	edge(){}
}e[maxn << 1];
int cnt = 1, h[maxn];
void Add_Edge(int x, int y){	
	e[++cnt] = edge(h[x], y);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x);
	h[y] = cnt;
}
int ns, g, s[maxn];
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
ll fg[maxn], f[maxn];
int num[maxn];
void DFS(int x, int fa, int d){
	d = gcd(a[x], d);
	int ss = div[d].size();
	srep(i, 0, ss) fg[div[d][i]] += num[div[d][i]]; 
	erep(i, x){
		int op = e[i].to;
		if (op == fa || vis[op]) continue;
		DFS(op, x, d);
	}
}
void DFS(int x, int fa, int d, int v){
	d = gcd(a[x], d);
	int ss = div[d].size();
	srep(i, 0, ss) num[div[d][i]] += v;  
	erep(i, x){
		int op = e[i].to;
		if (op == fa || vis[op]) continue;
		DFS(op, x, d, v);
	}
}
void solve(int x){
	DFS(x, x);
	x = g;
	vis[x] = 1;
	int ss = div[a[x]].size();
	srep(i, 0, ss){
		num[div[a[x]][i]]++;
		fg[div[a[x]][i]]++;
	}
	erep(i, x){
		int op = e[i].to;
		if (vis[op]) continue;
		DFS(op, x, a[x]);
		DFS(op, x, a[x], 1);
	}
	ss = div[a[x]].size();
	srep(i, 0, ss) num[div[a[x]][i]]--;  
	erep(i, x){
		int op = e[i].to;
		if (vis[op]) continue;
		DFS(op, x, a[x], -1);
	}
	int _ns = ns;
	erep(i, x){
		int op = e[i].to;
		if (vis[op]) continue;
		ns = (s[op] > s[x]) ? (_ns - s[x]) : s[op];
		solve(op);
	}
}

int main(){
	
		freopen("I.in", "r", stdin);
	
	int x, y, mx = 0;
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]), mx = max(mx, a[i]);
	get_prime(mx), get_div(mx);
	srep(i, 1, n) scanf("%d%d", &x, &y), Add_Edge(x, y);
	ns = n;
	solve(1);
	rep(i, 1, mx) for (register int j = i; j <= mx; j += i) f[i] += fg[j] * mu[j / i]; 
	rep(i, 1, mx) if (f[i]) printf("%d %lld\n", i, f[i]); 
	return 0;
}

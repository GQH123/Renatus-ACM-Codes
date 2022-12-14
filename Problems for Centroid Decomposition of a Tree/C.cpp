#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define maxn 400020
#define maxn2 800020
#define maxa 2000020
#define maxm
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
#define offset (n + 1)
#define lowbit(x) (x & -x)
using namespace std;

bool ugly[maxa];

int n;
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
int g, ns, s[maxn];
bool vis[maxn], good[maxn];
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
ll ans = 0;
int c1[maxn2];
ll c2[maxn2];
inline void add1(int x, int v){
	while (x){
		c1[x] += v;
		x -= lowbit(x);
	}
}
inline int get1(int x){
	int ans = 0;
	while (x < maxn2){
		ans += c1[x];
		x += lowbit(x);
	}
	return ans;
}
inline void add2(int x, int v){
	while (x){
		c2[x] += v;
		x -= lowbit(x);
	}
}
inline ll get2(int x){
	ll ans = 0;
	while (x < maxn2){
		ans += c2[x];
		x += lowbit(x);
	}
	return ans;
}
void DFS(int x, int fa, int d, int dis){
	d += (good[x]) ? 1 : -1;
	ans += get2(2 * offset - d) + (ll)dis * get1(2 * offset - d);
	erep(i, x){	
		int op = e[i].to;
		if (vis[op] || op == fa) continue;
		DFS(op, x, d, dis + 1);
	}
}
void DFS(int x, int fa, int d, int dis, int dd){
	d += (good[x]) ? 1 : -1;
	add1(d, 1 * dd), add2(d, dis * dd);
	erep(i, x){	
		int op = e[i].to;
		if (vis[op] || op == fa) continue;
		DFS(op, x, d, dis + 1, dd);
	}
}
void solve(int x){
	DFS(x, x);
	x = g;
	vis[x] = 1;
	int d = (good[x]) ? 1 : -1;
	add1(d + offset, 1), add2(d + offset, 1);
	if (d > 0) ans++;
	erep(i, x){	
		int op = e[i].to;
		if (vis[op]) continue;
		DFS(op, x, offset, 1);
		DFS(op, x, d + offset, 2, 1);
	}
	add1(d + offset, -1), add2(d + offset, -1);
	erep(i, x){	
		int op = e[i].to;
		if (vis[op]) continue; 
		DFS(op, x, d + offset, 2, -1);
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
		
	int x, y;
	for (register int i = 3; i < maxa; i += 2) for (register int j = i; j < maxa; j += i) ugly[j] ^= 1; 
	scanf("%d", &n);
	srep(i, 1, n) scanf("%d%d", &x, &y), Add_Edge(x, y);
	rep(i, 1, n) scanf("%d", &x), good[i] = ugly[x] ^ 1;
	ns = n; //////////////////////////////////////////////////////
	solve(1);
	printf("%lld", ans);
	return 0;
}

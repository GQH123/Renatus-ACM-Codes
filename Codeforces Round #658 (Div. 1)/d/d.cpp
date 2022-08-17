#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define ll long long int 
#define pb push_back
#define pc putchar
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn 200020
#define maxm
#define maxs
#define maxb
#define M 
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std; 

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
int d[maxn], fa[maxn];
void dfs(int x){
	erep(i, x){
		int op = e[i].to;
		if (op == fa[x]) continue;
		d[op] = d[x] + 1;
		fa[op] = x;
		dfs(op);
	}
}
set<int> path;
void upd(int x){
	
}
int getlen(int x, int y){
	int len = 0;
	fa[1] = -1;
	dfs(1); 
	path.insert(x), path.insert(y);
	if (d[x] < d[y]) swap(x, y);
	upd(x);
	while (d[x] != d[y]){
		len++;
		x = fa[x];
		path.insert(x);
	}
	while (x != y){
		len += 2;
		x = fa[x], y = fa[y];
		path.insert(x), path.insert(y);
	}
	return len;
}
int len;
int mxd[maxn];
void dfs2(int x, int fa, bool& ok){
	mxd[x] = d[x];
	int sum = 0;
	erep(i, x){
		int op = e[i].to;
		if (op == fa) continue;
		d[op] = d[x] + 1;
		dfs2(op, x, ok);
		mxd[x] = max(mxd[x], mxd[op]);
		if (mxd[op] - d[x] >= len) sum++;
		if (sum == 2) ok = true;
	}
}
bool play(int x){
	d[x] = 0;
	bool ok = false;
	dfs2(x, -1, ok);
	return ok;
} 
void recover(){
	rep(i, 1, n) h[i] = d[i] = 0;
	cnt = 1;
	path.clear();
}
int main(){
	int T, x, y, a, b;
	scanf("%d", &T);
	while (T--){
		scanf("%d%d%d", &n, &a, &b);
		rep(i, 2, n) scanf("%d%d", &x, &y), Add_Edge(x, y);
		len = getlen(a, b);
		if (play(a)) {printf("YES\n"); goto done;}
		if (play(b)) {printf("YES\n"); goto done;}
		//if (play()) {printf("YES\n"); goto done;}
		printf("NO\n");
		done:recover();
	} 
	return 0;
}


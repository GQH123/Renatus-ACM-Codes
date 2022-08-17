#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define maxn 300020
#define maxb 20
#define maxm
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
#define lowbit(x) (x & -x)
using namespace std;

int n;
int a[maxn];

struct inter{
	int l, r, x;
	inter(int l, int r, int x) : l(l), r(r), x(x){}
	inter(){}
	bool operator < (const inter b) const{
		return r < b.r;
	}
};
set<inter> se;

namespace BST{
	int get_dis(int x, int y);
};

namespace CDT{
	struct edge{
		int next, to, len;
		edge(int next, int to, int len) : next(next), to(to), len(len){}
		edge(){}
	}e[maxn << 1];
	int h[maxn], cnt = 1;
	void Add_Edge(int x, int y, int z){
		e[++cnt] = edge(h[x], y, z);
		h[x] = cnt;
		e[++cnt] = edge(h[y], x, z);
		h[y] = cnt;
	}
	int root, d[maxn], fa[maxn], dfs[maxn], s[maxn], num[maxn], ti = 0;
	ll v[maxn], ans = 0;
	//bool vis[maxn];
	void DFS(int x){
		//assert(!vis[x]);
		//vis[x] = 1;
		//printf("%d\n", x);
		dfs[x] = ++ti;
		s[x] = 1;
		erep(i, x){
			int op = e[i].to;
			if (op == fa[x]) continue;
			fa[op] = x, d[op] = d[x] + e[i].len;
			DFS(op);
			s[x] += s[op];
		}
	}
	int st[maxb];
	int cs = 0;
	inline void Add(int x){
		int _x = x; cs = 0;
		while (x) st[++cs] = x, x = fa[x]; 
		int last = 0; x = _x;
		per(i, cs, 1){
			int k = st[i];
			int temp = BST :: get_dis(x, k);
			ans += v[k] + (ll)temp * (num[k] - num[st[i - 1]]);
			v[k] += temp - last, last = temp;
			num[k]++;
		}
	}
	void work(){
		d[root] = fa[root] = 0, DFS(root);
		rep(i, 1, n) Add(a[i]), printf("%lld\n", ans); 
	}
};

namespace BST{
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
	int ns, g, s[maxn], d[maxn];
	bool isroot = 1, vis[maxn];
	void DFS(int x, int fa){
		s[x] = 1;
		bool f = 1;
		erep(i, x){
			int op = e[i].to;
			if (op == fa || vis[op]) continue;
			d[op] = d[x] + 1;
			DFS(op, x);
			if (s[op] > (ns >> 1)) f = 0;
			s[x] += s[op];
		}
		if (ns - s[x] > (ns >> 1)) f = 0;
		if (f) g = x;
	}
	void build_CDT(int x, int fa){
		d[x] = 0;
		DFS(x, x);
		x = g;
		if (isroot) isroot = 0, CDT :: root = x;
		else CDT :: Add_Edge(x, fa, d[x] + 1);
		vis[x] = 1; 
		int _ns = ns;
		erep(i, x){
			int op = e[i].to;
			if (vis[op]) continue;
			ns = (s[op] > s[x]) ? (_ns - s[x]) : s[op];
			build_CDT(op, x);
		}
	}
	void build_BST(){
		se.insert(inter(1, a[1] - 1, a[1]));
		se.insert(inter(a[1] + 1, n, a[1]));
		rep(i, 2, n){
			inter op = inter(a[i], a[i], a[i]);
			inter op2 = *se.lower_bound(op);
			se.erase(op2);
			BST :: Add_Edge(a[i], op2.x);
			inter _op = inter(op2.l, a[i] - 1, a[i]), __op = inter(a[i] + 1, op2.r, a[i]);
			if (_op.l <= _op.r) se.insert(_op);
			if (__op.l <= __op.r) se.insert(__op);
		}
	}
	int fa[maxn][maxb];
	void get_fa(int x){
		srep(i, 1, maxb) fa[x][i] = fa[fa[x][i - 1]][i - 1];
		erep(i, x){
			int op = e[i].to;
			if (op == fa[x][0]) continue;
			fa[op][0] = x;
			d[op] = d[x] + 1;
			get_fa(op);
		}
	}
	int get_lca(int x, int y){
		if (x == y) return x;
		if (d[x] < d[y]) swap(x, y);
		int dd = d[x] - d[y], now = 0;
		while (dd){	
			if (dd & 1) x = fa[x][now];
			now++;
			dd >>= 1;
		}
		if (x == y) return x;
		per(i, maxb - 1, 0) if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
		return fa[x][0];
	}
	int get_dis(int x, int y){
		if (!y) return 0;
		return d[x] + d[y] - 2 * d[get_lca(x, y)];
	}
	void init(){
		build_BST();
		ns = n;
		build_CDT(1, 1);
		d[1] = 0;
		get_fa(1);
	}
};

int main(){
	
		freopen("B.in", "r", stdin);
		
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]);
	BST :: init();
	CDT :: work();
	return 0;
}

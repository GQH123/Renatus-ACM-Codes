#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, r, l) for (int i = r; i >= l; i--)
#define srep(i, l, r) for (int i = l; i < r; i++)
#define sper(i, r, l) for (int i = r; i > l; i--)
#define erep(i, x) for (int i = h[x]; i; i = e[i].next)
#define ll long long int 
#define pb push_back
#define maxb 17
#define maxn 120021
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, m;

struct edge{
	int next, to, len;
	edge(int next, int to, int len) : next(next), to(to), len(len){}
	edge(){}
}e[maxn << 1];
int cnt = 1, h[maxn];
void Add_Edge(int x, int y, int z) {
	e[++cnt] = edge(h[x], y, z);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x, z);
	h[y] = cnt;
}
int fa[maxb][maxn]; ll d[maxn]; int dfs[maxn], siz[maxn], dep[maxn], idx = 0;
void DFS(int x) {
	dfs[x] = ++idx;
	siz[x] = 1;
	srep(i, 1, maxb) fa[i][x] = fa[i - 1][fa[i - 1][x]];
	erep(i, x) {
		int op = e[i].to;
		if (op == fa[0][x]) continue;
		fa[0][op] = x;
		d[op] = d[x] + e[i].len;
		dep[op] = dep[x] + 1;
		DFS(op);
		siz[x] += siz[op];
	}
}
int jump(int x, int step) {
	assert(step >= 0);
	int now = 0;
	while (step) {	
		if (step & 1) x = fa[now][x];
		now++;
		step >>= 1;
	}
	return x;
}
void init(){
	fa[0][1] = 1, d[1] = dep[1] = 0; DFS(1);
}


vector<pii> mo[maxn]; // i -> (time, point) && i = c

struct query{
	int id, x, l, r;
	query(int id, int x, int l, int r) : id(id), x(x), l(l), r(r){}
	query(){}
	bool operator < (const query b) const{
		return id < b.id;
	}
};
vector<query> q[maxn];

struct mod{
	int id, x, c;
	mod(int id, int x, int c) : id(id), x(x), c(c){}
	mod(){}
	bool operator < (const mod b) const{
		return id < b.id;
	}
}lismo[maxn]; int cm = 0;

//#define maxn2 141072

#define maxp 17 * 17 * 110121

int ct = 0;

struct node{
	int ls, rs, mx;
	node(int ls, int rs, int mx) : ls(ls), rs(rs), mx(mx){}
	node(){}
}pool[maxp];

int root = 0, o_qx, o_qy, o_qd, i_qx, i_qy, i_qd;

void i_pu(int o) {
	pool[o].mx = 0;
	if (pool[o].ls) pool[o].mx = max(pool[o].mx, pool[pool[o].ls].mx);
	if (pool[o].rs) pool[o].mx = max(pool[o].mx, pool[pool[o].rs].mx);
}
void i_mod(int l, int r, int& o) {
	if (!o) o = ++ct; 
	if (l == r) {
		pool[o].mx = max(pool[o].mx, i_qd);
		return;
	}
	int mid = ((r - l) >> 1) + l;
	if (i_qx <= mid) i_mod(l, mid, pool[o].ls);
	else i_mod(mid + 1, r, pool[o].rs);
	i_pu(o);
}
int i_get(int l, int r, int o) {
	// assert(i_qx <= i_qy);
	if (!o) return -1;
	if (i_qx <= l && r <= i_qy) {
		return pool[o].mx;
	}
	int mid = ((r - l) >> 1) + l, ans = -1;
	if (i_qx <= mid) ans = max(ans, i_get(l, mid, pool[o].ls));
	if (i_qy >  mid) ans = max(ans, i_get(mid + 1, r, pool[o].rs));
	return ans;
}
void o_mod(int l, int r, int& o) {
	// assert(o_qx <= o_qy);
	if (!o) o = ++ct;
	if (o_qx <= l && r <= o_qy) {
		i_mod(1, n, pool[o].mx);
		return; 
	}
	int mid = ((r - l) >> 1) + l;
	if (o_qx <= mid) o_mod(l, mid, pool[o].ls);
	if (o_qy > mid)  o_mod(mid + 1, r, pool[o].rs);
}
int o_get(int l, int r, int o) {
	if (!o) return -1;
	
	int ans = i_get(1, n, pool[o].mx);
	if (l == r) return ans;
	
	int mid = ((r - l) >> 1) + l;
	if (o_qx <= mid) return max(ans, o_get(l, mid, pool[o].ls));
	else 			 return max(ans, o_get(mid + 1, r, pool[o].rs));
}

void recover(){
	rep(i, 0, ct) pool[i].ls = pool[i].rs = pool[i].mx = 0;
	root = ct = 0;
}

ll res[maxn];
int main(){
	scanf("%d%d", &n, &m);
	int op, x, y, z, w;
	rep(i, 2, n) scanf("%d%d%d", &x, &y, &z), Add_Edge(x, y, z);
	init();
	
	rep(i, 1, m) {
		scanf("%d", &op);
		if (!op) {
			scanf("%d%d", &x, &y);
			mo[y].pb(pii(i, x));
			res[i] = -2;
		}
		else {
			scanf("%d%d%d%d", &x, &y, &z, &w);
			q[w].pb(query(i, x, y, z));
		}
	}
	//cerr << "Finish stage1!" << endl;
	rep(i, 1, n) {
		cm = 0;
		for (int j = i; j <= n; j += i) {
			for (auto it: mo[j]) lismo[++cm] = mod(it.fi, it.se, j);
		}
		int ptr = 1;
		sort(lismo + 1, lismo + 1 + cm);
		
		sort(q[i].begin(), q[i].end());
		
		for (auto it: q[i]) {
			while (ptr <= cm && lismo[ptr].id <= it.id) {
				int x = lismo[ptr].x;
				o_qx = dfs[x], o_qy = dfs[x] + siz[x] - 1, i_qx = lismo[ptr].c, i_qd = dep[x];
				o_mod(1, n, root);
				ptr++;
			}
			o_qx = dfs[it.x], i_qx = it.l, i_qy = it.r;
			int dis = o_get(1, n, root);
			
			if (dis == -1) res[it.id] = -1;
			else {
				int x = it.x;
				int y = jump(x, dep[x] - dis);
				res[it.id] = d[x] - d[y];
			}
		}
		
		recover();
	}
	
	rep(i, 1, m) {
		if (res[i] != -2) {
			if (res[i] == -1) printf("Impossible!\n");
			else printf("%lld\n", res[i]);
		}
	}
	return 0;
}

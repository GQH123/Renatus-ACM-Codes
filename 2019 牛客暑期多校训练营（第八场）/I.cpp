#include <bits/stdc++.h>
#define maxr 100000
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = hh[x]; i; i = e[i].next)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define ll long long int 
#define lowbit(x) (x & -x)
#define maxn 400019
#define maxm 400019
#define maxq 400019
#define pii pair<int, int>
#define fi first
#define se second
#define get GET
#define pb push_back
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}

int n, m, qq;
ll sum[maxn << 1];
int add[maxn << 1]; 
int qx, qy, qd;
inline void pu(int o){
	sum[o] = sum[o << 1] + sum[o << 1 | 1];
}
inline void pd(int l, int r, int o){
	if (add[o]){
		int& k = add[o], mid = ((r - l) >> 1) + l;
		add[o << 1] += k, add[o << 1 | 1] += k;
		sum[o << 1] += (ll)k * (mid + 1 - l), sum[o << 1 | 1] += (ll)k * (r - mid);
		k = 0;
	}
}
void Add(int l, int r, int o){
	if (l < r) pd(l, r, o);
	if (qx <= l && r <= qy) {
		add[o] += qd, sum[o] += qd * (r - l + 1);
		return;
	}
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) Add(l, mid, o << 1);
	if (qy > mid) Add(mid + 1, r, o << 1 | 1);
	pu(o);
}
ll Get(int l, int r, int o){
	if (l < r) pd(l, r, o);
	if (qx <= l && r <= qy) return sum[o];
	int mid = ((r - l) >> 1) + l;
	ll ans = 0;
	if (qx <= mid) ans += Get(l, mid, o << 1);
	if (qy > mid) ans += Get(mid + 1, r, o << 1 | 1);
	return ans;
}

struct edge{
	int next, to;
	edge(int next, int to) : next(next), to(to){}
	edge(){}
}e[maxm << 1];
int cnt = 1, hh[maxm];
void Add_Edge(int x, int y){
	e[++cnt] = edge(hh[x], y);
	hh[x] = cnt;
	e[++cnt] = edge(hh[y], x);
	hh[y] = cnt;
}
int dfs[maxm], siz[maxm], t = 0;
void DFS(int x, int fa){
	siz[x] = 1, dfs[x] = ++t;
	erep(i, x){
		int op = e[i].to;
		if (op == fa) continue;
		DFS(op, x);
		siz[x] += siz[op];
	}	
}
struct query{
	int u, v, l, r;
	query(int u, int v, int l, int r) : u(u), v(v), l(l), r(r){}
	query(){}
}q[maxm];

struct ele{
	int id, l, r;
	ele(int id, int l, int r) : id(id), l(l), r(r){}
	ele(){}
};
vector<pii> tag[maxm];
vector<ele> get[maxm];
ll ans[maxq];
int main(){
	#ifndef ONLINE_JUDGE
		freopen("I.in", "r", stdin);
	#endif
	int x, y, z, w;
	read(n), read(m);
	rep(i, 1, m) read(x), read(y), read(z), read(w), Add_Edge(x, y), q[i] = query(x, y, z, w);
	DFS(1, 1);
	rep(i, 1, m){
		query op = q[i];
		tag[dfs[op.v]].pb(pii(op.l, op.r));
	}
	read(qq);
	rep(i, 1, qq){
		read(x), read(y), read(z);
		get[dfs[x] - 1].pb(ele(-i, y, z)), get[dfs[x] + siz[x] - 1].pb(ele(i, y, z));
	}
	qx = 1, qy = n, qd = 1;
	Add(1, n, 1);
	rep(i, 1, m + 1){
		int sz = tag[i].size();
		srep(j, 0, sz){
			pii op = tag[i][j];
			qx = op.fi, qy = op.se, qd = 1;
			Add(1, n, 1);
		}
		sz = get[i].size();
		srep(j, 0, sz){
			ele op = get[i][j];
			qx = op.l, qy = op.r;
			if (op.id > 0) ans[op.id] += Get(1, n, 1);
			else ans[-op.id] -= Get(1, n, 1);
		}
	}
	rep(i, 1, qq) printf("%lld\n", ans[i]); 
}

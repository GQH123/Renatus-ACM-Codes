#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define maxn 600020 
#define pb push_back 
#define pii pair<int, int>
#define fi first
#define se second
#define ll long long int 
#define lowbit(x) (x & -x) 
using namespace std;    

int n, m; 
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
int s[maxn], fa[maxn], d[maxn], dfs[maxn], top[maxn], son[maxn], idfs[maxn];
int ti = 0;
void DFS(int x){
	s[x] = 1;
	son[x] = 0;
	erep(i, x) {
		int op = e[i].to;
		if (op == fa[x]) continue;
		fa[op] = x;
		d[op] = d[x] + 1;
		DFS(op);
		if (s[op] > s[son[x]]) son[x] = op;
		s[x] += s[op];
	}
}
void DFS(int x, int tp){
	dfs[x] = ++ti, idfs[ti] = x;
	top[x] = tp;
	if (son[x]) DFS(son[x], tp);
	erep(i, x){
		int op = e[i].to;
		if (op == fa[x] || op == son[x]) continue;
		DFS(op, op);
	}
}

struct ele{
	int l, r, v;
	ele(int l, int r, int v) : l(l), r(r), v(v){}
	ele(){}
	bool operator < (const ele b) const{
		return  (l == b.l) ? r < b.r : l < b.l;
	}
};
set<ele> ss;
set<ele> :: iterator st, ed, it;
void init(){
	DFS(1), DFS(1, 1);
	ss.clear();
	ss.insert(ele(1, n, 0));
}

pii lis[maxn];
int cs = 0;
void get_path(int x, int y){
	cs = 0;
	int f1 = top[x], f2 = top[y];
	while (f1 != f2){
		if (d[f1] > d[f2]){
			lis[++cs] = pii(dfs[f1], dfs[x]);
			x = fa[f1];
			f1 = top[x];
		}
		else {
			lis[++cs] = pii(dfs[f2], dfs[y]);
			y = fa[f2];
			f2 = top[y];
		}
	}
	lis[++cs] = pii(min(dfs[x], dfs[y]), max(dfs[x], dfs[y]));
}

void _merge(ele op){
	it = ss.lower_bound(op); ++it;
	if (it != ss.end()){ 
		if (it -> v == op.v) {
			int l = op.l, r = it -> r, v = op.v;
			ss.erase(it), ss.erase(op);
			op = ele(l, r, v);
			ss.insert(op);
		}
	}
}

void merge(ele op){
	it = ss.lower_bound(op);
	if (it != ss.begin()){
		--it;
		if (it -> v == op.v) {
			int l = it -> l, r = op.r, v = op.v;
			ss.erase(it), ss.erase(op);
			op = ele(l, r, v);
			ss.insert(op);
		}
	}
	_merge(op);
}

void op1(int x, int y, int k){
	get_path(x, y);
	rep(i, 1, cs){
		int l = lis[i].fi, r = lis[i].se;
		st = ss.lower_bound(ele(l + 1, l + 1, 0));
		st--; 
		
		while (st != ss.end() && st -> l <= r){ 
			ele op = *st;
			if (op.l < l){
				ss.insert(ele(op.l, l - 1, op.v));
				merge(ele(op.l, l - 1, op.v));
				op.l = l;
			}
			if (op.r > r){
				ss.insert(ele(r + 1, op.r, op.v));
				merge(ele(r + 1, op.r, op.v));
				op.r = r;
			} 
			st++;
			ss.erase(op); 
			op.v = op.v + k;
			ss.insert(op);
			merge(op); 
		}
	}
}
void op2(int x, int y, int k){
	get_path(x, y);
	rep(i, 1, cs){
		int l = lis[i].fi, r = lis[i].se;
		st = ss.lower_bound(ele(l + 1, l + 1, 0));
		st--; 
		
		while (st != ss.end() && st -> l <= r){ 
			ele op = *st;
			if (op.l < l){
				ss.insert(ele(op.l, l - 1, op.v));
				merge(ele(op.l, l - 1, op.v));
				op.l = l;
			}
			if (op.r > r){
				ss.insert(ele(r + 1, op.r, op.v));
				merge(ele(r + 1, op.r, op.v));
				op.r = r;
			} 
			st++;
			ss.erase(op); 
			op.v = op.v ^ k;
			ss.insert(op);
			merge(op); 
		}
	}
}
void op3(int x, int y, int k){
	get_path(x, y);
	rep(i, 1, cs){
		int l = lis[i].fi, r = lis[i].se;
		st = ss.lower_bound(ele(l + 1, l + 1, 0));
		st--; 
		
		while (st != ss.end() && st -> l <= r){ 
			ele op = *st;
			if (op.l < l){
				ss.insert(ele(op.l, l - 1, op.v));
				merge(ele(op.l, l - 1, op.v));
				op.l = l;
			}
			if (op.r > r){
				ss.insert(ele(r + 1, op.r, op.v));
				merge(ele(r + 1, op.r, op.v));
				op.r = r;
			} 
			st++;
			ss.erase(op); 
			if (op.v >= k) op.v = op.v - k;
			ss.insert(op);
			merge(op); 
		}
	}
}
void op4(int x, int y){
	get_path(x, y);
	ll ans = 0;
	rep(i, 1, cs){
		int l = lis[i].fi, r = lis[i].se;
		st = ss.lower_bound(ele(l + 1, l + 1, 0));
		st--; 
		while (st != ss.end() && st -> l <= r){ 
			ele op = *st; st++;
			ans += (min(op.r, r) - max(op.l, l) + 1) * (ll)op.v;
		}
	}
	printf("%lld\n", ans);
}
void op5(int x, int y){
	get_path(x, y);
	ll ans = 0;
	rep(i, 1, cs){
		int l = lis[i].fi, r = lis[i].se;
		st = ss.lower_bound(ele(l + 1, l + 1, 0));
		st--; 
		while (st != ss.end() && st -> l <= r){ 
			ele op = *st; st++;
			if ((min(op.r, r) & 1) ^ (max(op.l, l) & 1)) continue;
			ans ^= op.v;
		}
	}
	printf("%lld\n", ans);
}
void op6(int x, int y){
	get_path(x, y);
	ll mx = -1, mi = -1;
	rep(i, 1, cs){
		int l = lis[i].fi, r = lis[i].se;
		st = ss.lower_bound(ele(l + 1, l + 1, 0));
		st--; 
		while (st != ss.end() && st -> l <= r){ 
			ele op = *st; st++;
			mx = (mx == -1) ? op.v : max(mx, (ll)op.v);
			mi = (mi == -1) ? op.v : min(mi, (ll)op.v);
		}
	}
	printf("%lld\n", mx - mi);
}
void op7(int x, int y, int k){
	get_path(x, y);
	ll ans = -1;
	rep(i, 1, cs){
		int l = lis[i].fi, r = lis[i].se;
		st = ss.lower_bound(ele(l + 1, l + 1, 0));
		st--; 
		while (st != ss.end() && st -> l <= r){ 
			ele op = *st; st++;
			ans = (ans == -1) ? abs(op.v - k) : min(ans, (ll)abs(op.v - k));
		}
	}
	printf("%lld\n", ans);
}

int main(){	  
	int T, x, y, op, z;
	scanf("%d", &T);
	while (T--){ 
		scanf("%d%d", &n, &m); 
		rep(i, 2, n) scanf("%d%d", &x, &y), Add_Edge(x, y); 
		init();
		rep(i, 1, m){
			scanf("%d", &op);
			if (op == 1) {
				scanf("%d%d%d", &x, &y, &z); 
				op1(x, y, z);
			}
			else if (op == 2){
				scanf("%d%d%d", &x, &y, &z); 
				op2(x, y, z);
			}
			else if (op == 3){
				scanf("%d%d%d", &x, &y, &z); 
				op3(x, y, z);
			}
			else if (op == 4){
				scanf("%d%d", &x, &y); 
				op4(x, y);
			}
			else if (op == 5){
				scanf("%d%d", &x, &y); 
				op5(x, y);
			}
			else if (op == 6){
				scanf("%d%d", &x, &y); 
				op6(x, y);
			}
			else if (op == 7){
				scanf("%d%d%d", &x, &y, &z); 
				op7(x, y, z);
			}
		}
	}
	return 0;
} 

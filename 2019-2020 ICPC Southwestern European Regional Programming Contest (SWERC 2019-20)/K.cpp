#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
const int N = 200020, M = 200020;
using namespace std;

int n, m, i, x, y, q[N], ans;
int g1[N], g2[N], gd[N], v[M * 3 + N], nxt[M * 3 + N], ed;
int cnt, dfn[N], id[N], fa[N], f[N], mn[N], sd[N], idom[N];

void add(int* g, int x, int y) {v[++ed] = y, nxt[ed] = g[x], g[x] = ed;}
int F(int x){
	if (f[x] == x) return x;
	int y = F(f[x]);
	if (sd[mn[x]] > sd[mn[f[x]]]) mn[x] = mn[f[x]];
	return f[x] = y;
}
int _gd = 0;
void dfs(int x){
	id[dfn[x] = ++cnt] = x;
	for (int i = g1[x]; i; i = nxt[i]) if (!dfn[v[i]]) dfs(v[i]), fa[dfn[v[i]]] = dfn[x];
}
void tarjan(int S){
	int i, j, k, x;
	for (cnt = 0, i = 1; i <= n; i++) gd[i] = dfn[i] = id[i] = fa[i] = idom[i] = 0, f[i] = sd[i] = mn[i] = i;
	dfs(S);
	for (i = n; i > 1; i--){
		for (j = g2[id[i]]; j; j = nxt[j]) F(k = dfn[v[j]]), sd[i] = sd[i] < sd[mn[k]]? sd[i] : sd[mn[k]];
		add(gd, sd[i], i), _gd++;
		for (j = gd[f[i] = x = fa[i]]; j; j = nxt[j]) F(k = v[j]), idom[k] = sd[mn[k]] < x ? mn[k] : x;
		gd[x] = 0;
	}
	for (i = 2; i <= n; add(gd, idom[i], i), _gd++, i++) { 
		if (idom[i] != sd[i]) idom[i] = idom[idom[i]];
	}
}

set<int> s;
void final_dfs(int x){
	s.insert(x);
	for (int i = gd[dfn[x]]; i; i = nxt[i]) final_dfs(id[v[i]]); 
}
int cs, _cs;
int res[N], _res[N];

bool isd[N];
int main(){ 
	int S;
	scanf("%d%d%d", &n, &m, &S), S++;
	for (ed = 0, i = 1; i <= n; i++) g1[i] = g2[i] = 0;
	while (m--){
		scanf("%d%d", &x, &y), x++, y++, add(g1, y, x), add(g2, x, y);
	}
	tarjan(S); 
	//cerr << _gd << endl;
	for (i = gd[1]; i; i = nxt[i]) {
		isd[id[v[i]]] = 1;
		res[++cs] = id[v[i]];
	}
	/*
	rep(i, 1, n){
		cerr << i - 1 << ' ';
		for (int j = gd[dfn[i]]; j; j = nxt[j]){	
			cerr << id[v[j]] - 1 << ' ';
		}
		cerr << endl;
	}
	*/
	//rep(i, 1, cs) cerr << res[i] << ' ';
	//cerr << endl;
	//cerr << "res" << endl;
	rep(i, 1, cs){
		int x = res[i];
		//cerr << res[i] - 1 << ' ';
		bool f = 1;
		//set<int> s; s.clear();
		s.clear();
		final_dfs(x);
		//for (int j = gd[dfn[x]]; j; j = nxt[j]) s.insert(id[v[j]]); 
		for (int j = g2[x]; j; j = nxt[j]){
			if (v[j] == S) continue;
			if (!s.count(v[j])) {f = 0; break;}
		}
		if (f) _res[++_cs] = x;
	}
	//cerr << endl;
	if (!_cs){
		printf("0\n");
		return 0;
	}
	else {
		printf("%d\n", _cs);
		sort(_res + 1, _res + 1 + _cs);
		rep(i, 1, _cs) printf("%d\n", _res[i] - 1);
	}  
	return 0;
}

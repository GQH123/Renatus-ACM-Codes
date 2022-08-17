#include <bits/stdc++.h>
#define maxr 100000
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define M 998244353
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}

void reads(char* s){
	char ch = gc(); int len = 0;
	while (!('a' <= ch && ch <= 'z')) ch = gc();
	while ('a' <= ch && ch <= 'z') s[++len] = ch, ch = gc();
}

int n, m, q;
struct edge{
	int to, next;
	bool let[maxn];
	edge(int next, int to) : next(next), to(to){}
}e[maxn << 1];
int cnt = 1, h[maxn];
char lett[30];
void Add_Edge(int x, int y){
	e[++cnt] = edge(h[x], y);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x);
	h[y] = cnt;
	int len = reads(lett);
	rep(i, 1, len) e[cnt].let[lett[i] - 'a'] = e[cnt - 1].let[lett[i] - 'a'] = 1; 
}

struct Trie{
	int f[maxn];
	bool go[maxn][26];
	bool val[maxn];
	int sz = 0, root = 0;
	void insert(char* s, int len){
		int now = root;
		rep(i, 1, len){
			if (!go[now][s[i] - 'a']) go[now][s[i] - 'a'] = ++sz;
			now = go[now][s[i] - 'a'];
		}
		val[now] = 1;
	}
	int bfs[maxn], head = 0, tail = 0;
	void build_ac_automaton(){
		f[0] = 0;
		rep(i, 0, 25) if (go[0][i]) f[go[0][i]] = 0, bfs[++head] = go[0][i]; 
		while (tail < head){
			int x = bfs[++tail];
			rep(i, 0, 25){
				if (!go[x][i]) go[x][i] = go[f[x]][i];
				else {
					int now = f[x];
					while (!go[now][i]) now = f[now];
					f[go[x][i]] = go[now][i];
					bfs[++head] = go[x][i];
				}
			}
		}
	}
}T;

int fa[maxn], d[maxn], dfs[maxn], idfs[maxn], top[maxn], siz[maxn], son[maxn];
int t = 0;
void DFS(int x){
	siz[x] = 1;
	erep(i, x){
		int op = e[i].to;
		if (op == fa[x]) continue;
		d[op] = d[x] + 1, fa[op] = x;
		DFS(op, x);
		if (siz[op] > siz[son[x]]) son[x] = op;
		siz[x] += siz[op];
	}
}
void DFS(int x, int tp){
	dfs[x] = ++t, idfs[t] = x, top[x] = tp;
	if (son[x]) DFS(son[x], tp);
	erep(i, x){
		int op = e[i].to;
		if (op == son[x] || op == fa[x]) continue;
		DFS(op, op);
	}
}


struct MAT{
	int n, m;
	int mat[maxmat][maxmat];
	void MAT(int n, int m) : n(n), m(m) {ms(mat, 0);}
	void MAT() {ms(mat, 0);}
	void MAT1(){
		rep(i, 1, n) mat[i][i]  = 1;
	}
};
MAT multimat(MAT a, MAT b){
	MAT c(a.n, b.m);
	rep(i, 1, a.n){
		rep(j, 1, b.m){
			rep(k, 1, a.m){
				c.mat[i][j] += (ll)a.mat[i][k] * b.mat[k][j] % M, mo(c.mat[i][j]);
			}
		}
	}
	return c;
}
MAT trans[maxn];
void get_MAT(int x){
	erep(i, x){
		int op = e[i].to;
		if (op == fa[x]) continue;
		rep(i, 0, 25){
			
		}
	}
}
MAT sum[maxn << 1];
int qx, qy, qd;
inline void pu(int o){
	sum[o] = multimat(sum[o << 1], sum[o << 1 | 1]);
}
void init(int l, int r, int o){
	if (l == r){
		sum[o] = trans[idfs[l]];
		return;
	}
	int mid = ((r - l) >> 1) + l;
	init(l, mid, o << 1), init(mid + 1, r, o << 1 | 1);
	pu(o);
}
MAT get(int l, int r, int o){
	if (qx <= l && r <= qy){
		return sum[o];
	}
	int mid = ((r - l) >> 1) + l;
	MAT ans(T.sz, T.sz); ans.MAT1();
	if (qx <= mid) ans = multimat(ans, get(l, mid, o << 1));
	if (qy > mid) ans = multimat(ans, get(mid + 1, r, o << 1 | 1));
	return ans;
}

MAT ;
void query(int x, int y){
	MAT ans(T.sz, T.sz); ans.MAT1();
	int f1 = top[x], f2 = top[y];
	while (f1 != f2){
		if (d[f1] > d[f2]){
			qx = dfs[f1], qy = dfs[x];
			ans = multimat(ans, get(1, n, 1));
			x = fa[f1], f1 = top[x];
		}
		else {
			qx = dfs[f2], qy = dfs[y];
			ans = multimat(ans, get(1, n, 1));
			y = fa[f2], f2 = top[y];
		}
	}
	if (d[x] < d[y]) swap(x, y);
	qx = dfs[y] + 1, qy = dfs[x];
	if (qx <= qy) ans = multimat(ans, get(1, n, 1));
	
}


int main(){
	#ifndef ONLINE_JUDGE
		freopen("H.in", "r", stdin);
	#endif
	int x, y;
	read(n), read(m), read(q);
	srep(i, 1, n) read(x), read(y), Add_Edge(x, y); 
	rep(i, 1, m) reads(s), T.insert(s, strlen(s + 1));
	T.build_ac_automaton();
	DFS(1), DFS(1, 1), get_MAT(1), init(1, n, 1);
	rep(i, 1, q){
		read(x), read(y), query(x, y);
	}
	return 0;
}

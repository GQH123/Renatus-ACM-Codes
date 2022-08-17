#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 400020
#define maxb 20
#define ls ch[x][0]
#define rs ch[x][1]
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int rev[maxn], f[maxn], s[maxn], ch[maxn][2]; //s[i] = 1 初始化
inline void pu(int x){s[x] = s[ls] + s[rs] + 1;}
inline void pd(int x){if (!x) return;if (rev[x]) swap(ls, rs), rev[ls] ^= 1, rev[rs] ^= 1, rev[x] = 0;}
inline bool isroot(int x){return ch[f[x]][0] != x && ch[f[x]][1] != x;}
inline void rotate(int x){
	if (isroot(x)) return;
	int y = f[x];
	if (!isroot(y)){
		int z = f[y];
		ch[z][ch[z][1] == y] = x; 
	}
	f[x] = f[y];
	int k = ch[y][1] == x;
	ch[y][k] = ch[x][k ^ 1], f[ch[y][k]] = y;
	ch[x][k ^ 1] = y, f[y] = x;
	pu(y), pu(x); 
}
int tmp[maxn];
void splay(int x){
	if (!x) return;
	int ct = 0, _x = x;
	while (!isroot(x)) tmp[++ct] = x, x = f[x]; tmp[++ct] = x;
	while (ct) pd(tmp[ct--]);
	x = _x;
	while (!isroot(x)) {
		int y = f[x];
		if (!isroot(y)) {
			int z = f[y];
			(ch[z][1] == y) ^ (ch[y][1] == x) ? rotate(x) : rotate(y);
		}
		rotate(x);
	}
}
void access(int x){int last = 0; while (x) splay(x), rs = last, pu(x), last = x, x = f[x];}
int findroot(int x){access(x), splay(x); while (pd(x), ls) x = ls; return x;} 
void moveroot(int x){access(x), splay(x), rev[x] = 1, pd(x);}
void split(int x, int y){moveroot(y); access(x); splay(x);}
void link(int x, int y){if (findroot(x) == findroot(y)) return; moveroot(x), f[x] = y;} 
void cut(int x, int y){if (findroot(x) != findroot(y)) return; split(x, y); if (ch[y][1]) return; ls = 0; pu(x); f[y] = 0;} 

int n, m, q;
pii e[maxn];
int first[maxn];
int mi[maxn][maxb];
int lo[maxn];
void init(){
	lo[1] = 0; rep(i, 2, m) lo[i] = lo[i >> 1] + 1;
	rep(i, 1, m) mi[i][0] = first[i];
	srep(bit, 1, maxb) {
		rep(i, 1, m) mi[i][bit] = (i + (1 << bit - 1) <= m) ? min(mi[i][bit - 1], mi[i + (1 << bit - 1)][bit - 1]) : mi[i][bit - 1];
	}
}
int query(int l, int r){
	int k = lo[r - l + 1];
	return min(mi[l][k], mi[r - (1 << k) + 1][k]);
}
int main(){ 
	int T, x, y, l, r; scanf("%d", &T);
	while (T--){
		int lastans = 0;
		scanf("%d%d%d", &n, &m, &q);
		rep(i, 1, n) f[i] = ch[i][0] = ch[i][1] = rev[i] = 0, s[i] = 1;
		rep(i, 1, m) scanf("%d%d", &e[i].fi, &e[i].se);
		int ptr = 1;
		rep(i, 1, m){	
			while (ptr <= m && findroot(e[ptr].fi) != findroot(e[ptr].se)) link(e[ptr].fi, e[ptr].se), ptr++;
			first[i] = ptr;
			cut(e[i].fi, e[i].se);
		}
		init();
		rep(i, 1, q){
			scanf("%d%d", &x, &y);
			x ^= lastans, y ^= lastans;
			x = x % m + 1, y = y % m + 1;
			l = min(x, y), r = max(x, y);
			if (query(l, r) <= r) printf("Yes\n"), lastans = 1;
			else printf("No\n"), lastans = 0;
		}
	}
	return 0;
}

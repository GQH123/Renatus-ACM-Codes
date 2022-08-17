#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 500020
#define ls ch[x][0]
#define rs ch[x][1]
using namespace std;

int rev[maxn], f[maxn], s[maxn], v[maxn], a[maxn], ch[maxn][2];
inline void pu(int x){s[x] = s[ls] + s[rs] + 1, v[x] = v[ls] ^ v[rs] ^ a[x];}
inline void pd(int x){if (rev[x]) swap(ls, rs), rev[ls] ^= 1, rev[rs] ^= 1, rev[x] = 0;}
inline bool isroot(int x){return ch[f[x]][0] != x && ch[f[x]][1] != x;}
inline void rotate(int x){
	//if (isroot(x)) return;
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
			ch[z][1] == y ^ ch[y][1] == x ? rotate(x) : rotate(y);
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
int getval(int x, int y){split(x, y); return v[x];}
void mod(int x, int val){splay(x); a[x] = val; pu(x);}

namespace Test{
	int n, m, x, y, op;
	void test(){
		scanf("%d%d", &n, &m);
		rep(i, 1, n) scanf("%d", a + i);
		rep(i, 1, m) {
			scanf("%d%d%d", &op, &x, &y);
			if (!op) printf("%d\n", getval(x, y)); 
			else if (op == 1) link(x, y);
			else if (op == 2) cut(x, y);
			else if (op == 3) mod(x, y);
		}
	}
}
int main(){

	Test :: test();
	
	return 0;
}

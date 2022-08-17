#include <cstdio>
#include <algorithm>
#include <vector>
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, r, l) for (int i = r; i >= l; i--)
#define srep(i, l, r) for (int i = l; i < r; i++)
#define sper(i, r, l) for (int i = r; i > l; i--)
#define ll long long int 
#define maxn 600021
#define _maxq 100021
#define pb push_back
#define pii std :: pair<int, int>
#define fi first
#define se second

int n, m, a[maxn];

int tag0[maxn];

namespace SBT{
	#define w 31
	#define maxs w * _maxq
	#define ls ch[o][0]
	#define rs ch[o][1]
	
	int root, ct = 0;
	int ch[maxs][2];
	int num[maxs];
	int xorv[maxs];
	void mod(int x, int& o, int v) {
		if (!o) o = ++ct; int now = o;
		srep(i, 0, w) {
			num[now] += v, xorv[now] ^= (v & 1) * x;
			int d = x & 1; x >>= 1;
			if (!ch[now][d]) ch[now][d] = ++ct; now = ch[now][d];
		}
		num[o] += v, xorv[o] ^= (v & 1) * x;
	}
	inline void pu(int o) {
		num[o] = num[ls] + num[rs];
		xorv[o] = (xorv[ls] ^ xorv[rs]) << 1 | (num[rs] & 1);
	}
	void incr(int o) {
		if (!o) return;
		if (!ls && !rs) num[rs = ++ct] = num[o];
		else std :: swap(ls, rs), incr(ls);
		pu(o);
	}
	void recover(){
		rep(o, 0, ct) ls = rs = 0, num[o] = xorv[o] = 0; ct = root = 0;
	}
}using namespace SBT;

pii lisp[800021];

int cp = 0;

#define bn 8
int pos[bn << 1];

int main(){
	scanf("%d%d", &n, &m);
	rep(i, 1, n) scanf("%d", a + i);
	int op, x, y, v;
	rep(i, 1, m) {
		scanf("%d%d%d%d", &op, &x, &y, &v);
		if (op == 0) tag0[x] ^= v, tag0[y + 1] ^= v;
		else {
			lisp[++cp] = pii(x, v), lisp[++cp] = pii(y + 1, v + y - x + 1);
			//p[x].pb(pii(v, 1));
			//p[y + 1].pb(pii(v + y - x + 1, -1));
		}
	}
	std :: sort(lisp + 1, lisp + 1 + cp);
	
	int bs = cp / bn;
	pos[0] = 0;
	rep(i, 1, bn) pos[i] = i * bs;
	pos[bn] = cp;
	
	int ptr = 1;
	rep(epoch, 1, bn) {
		recover();
		rep(i, 1, n) {
			incr(root);
			while (ptr <= pos[epoch] && lisp[ptr].fi == i) {
				mod(lisp[ptr].se, root, 1);
				ptr++;
			}
			a[i] ^= xorv[root];
		}
	}
	
	int nowv = 0;
	rep(i, 1, n) {
		nowv ^= tag0[i];
		a[i] ^= nowv;
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}

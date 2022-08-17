#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define maxn 200020
#define maxnode 10000020
#define lowbit(x) (x & -x)
using namespace std; 

int n, m, a[maxn];
int sss[maxn], ss = 0;

int c[maxn];
int lis[maxn], cs = 0, lis2[maxn], cs2 = 0;
int ct = 0, ch[maxnode][2], sum[maxnode];
inline void pu(int o){
	sum[o] = sum[ch[o][0]] + sum[ch[o][1]];
}
int qx, qy, qd;
void mod(int l, int r, int& o){
	if (!o) o = ++ct;
	if (l == r) {sum[o] += qd; return;}
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) mod(l, mid, ch[o][0]);
	else mod(mid + 1, r, ch[o][1]);
	pu(o);
}
int get(int l, int r){
	if (l == r) return l;
	int mid = ((r - l) >> 1) + l;
	int suml = 0;
	rep(i, 1, cs) {
		int x = lis[i];
		suml += sum[ch[x][0]];
	}
	rep(i, 1, cs2){
		int x = lis2[i];
		suml -= sum[ch[x][0]];
	}
	if (suml >= qd) {
		rep(i, 1, cs) {
			int x = lis[i];
			lis[i] = ch[x][0];
		}
		rep(i, 1, cs2){
			int x = lis2[i];
			lis2[i] = ch[x][0];
		}
		return get(l, mid);
	}
	else {
		qd -= suml;
		rep(i, 1, cs) {
			int x = lis[i];
			lis[i] = ch[x][1];
		}
		rep(i, 1, cs2){
			int x = lis2[i];
			lis2[i] = ch[x][1];
		}
		return get(mid + 1, r);
	}
}

void add(int x, int v, int d){
	qx = v, qd = d;
	while (x <= n){ 
		mod(1, ss, c[x]);
		x += lowbit(x);
	}
}
int get(int l, int r, int k){
	cs = cs2 = 0;
	int x = l - 1;
	while (x){
		lis2[++cs2] = c[x];
		x -= lowbit(x);
	}
	x = r;
	while (x){
		lis[++cs] = c[x];
		x -= lowbit(x);
	}
	qd = k;
	return get(1, ss);
}

void recover(){ 
	rep(i, 1, ct) ch[i][0] = ch[i][1] = sum[i] = 0;
	ct = ss = 0;
	rep(i, 1, n) c[i] = 0;
}

struct ope{
	int op, l, r, d;
	ope(int op, int l, int r, int d) : op(op), l(l), r(r), d(d){}
	ope(){}
}q[maxn];

int main(){
	int x, y; 
	while (scanf("%d", &n) == 1){
		rep(i, 1, n) scanf("%d", a + i), sss[i] = a[i];
		scanf("%d", &m);
		ss = n;
		rep(i, 1, m){
			scanf("%d", &q[i].op);
			if (q[i].op == 1){
				scanf("%d%d", &q[i].l, &q[i].d);
				sss[++ss] = q[i].d;
			}
			else {
				scanf("%d%d%d", &q[i].l, &q[i].r, &q[i].d);
			}
		}
		sort(sss + 1, sss + 1 + ss);
		ss = unique(sss + 1, sss + 1 + ss) - sss - 1;
		rep(i, 1, n) a[i] = lower_bound(sss + 1, sss + 1 + ss, a[i]) - sss; 
		rep(i, 1, m) if (q[i].op == 1) q[i].d = lower_bound(sss + 1, sss + 1 + ss, q[i].d) - sss;  
		
		rep(i, 1, n) add(i, a[i], 1);
		rep(i, 1, m){
			if (q[i].op == 1){
				add(q[i].l, a[i], -1);
				a[i] = q[i].d;
				add(q[i].l, a[i], 1);
			}
			else printf("%d\n", sss[get(q[i].l, q[i].r, q[i].d)]); 
		}
		recover();
	}
	return 0;
}

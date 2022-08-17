#include <bits/stdc++.h>
#define maxr 100000
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define ll long long int 
#define maxn 1200005
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}

int n;
int X1, X2, A1, B1, C1, M1, Y1, Y2, A2, B2, C2, M2, X, X_, X__, Y, Y_, Y__;

struct op{
	int l, r;
	op(int l, int r) : l(l), r(r){}
	op(){}
}q[maxn];
int lis[maxn << 1];
int cs = 0;

ll sum[maxn << 1];
int add[maxn << 1];
int qx, qy;
ll qd;
inline void pu(int o){
	sum[o] = sum[o << 1] + sum[o << 1 | 1];
}
inline void pd(int l, int r, int o){
	if (add[o]){
		int& k = add[o]; int mid = ((r - l) >> 1) + l;
		add[o << 1] += k, add[o << 1 | 1] += k;
		sum[o << 1] += (ll)(lis[mid + 1] - lis[l]) * k, sum[o << 1 | 1] += (ll)(lis[r + 1] - lis[mid + 1]) * k;
		k = 0;
	}
}
void Add(int l, int r, int o){
	if (l < r) pd(l, r, o);
	if (qx <= l && r <= qy){
		add[o] += qd, sum[o] += (ll)(lis[r + 1] - lis[l]) * qd;
		return;
	}
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) Add(l, mid, o << 1);
	if (qy > mid) Add(mid + 1, r, o << 1 | 1);
	pu(o);
}
int get(int l, int r, int o){
	if (l < r) pd(l, r, o);
	if (l == r) return lis[l] + (qd - 1) / (sum[o] / (lis[r + 1] - lis[l])); 
	int mid = ((r - l) >> 1) + l;
	if (qd <= sum[o << 1]) return get(l, mid, o << 1);
	else {qd -= sum[o << 1]; return get(mid + 1, r, o << 1 | 1);}
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("E.in", "r", stdin);
	#endif
	read(n);
	read(X1), read(X2), read(A1), read(B1), read(C1), read(M1);
	read(Y1), read(Y2), read(A2), read(B2), read(C2), read(M2);
	q[1].l = min(X1, Y1) + 1, q[1].r = max(X1, Y1) + 1;
	q[2].l = min(X2, Y2) + 1, q[2].r = max(X2, Y2) + 1; 
	X_ = X2, X__ = X1, Y_ = Y2, Y__ = Y1;
	rep(i, 3, n){
		X = ((ll)A1 * X_ + (ll)B1 * X__ + C1) % M1;
		Y = ((ll)A2 * Y_ + (ll)B2 * Y__ + C2) % M2;
		X__ = X_, X_ = X, Y__ = Y_, Y_ = Y;
		q[i].l = min(X, Y) + 1, q[i].r = max(X, Y) + 1;
	}
	
	rep(i, 1, n) lis[++cs] = q[i].l, lis[++cs] = q[i].r + 1; 
	sort(lis + 1, lis + 1 + cs);
	cs = unique(lis + 1, lis + 1 + cs) - lis - 1;
	rep(i, 1, n) q[i].l = lower_bound(lis + 1, lis + 1 + cs, q[i].l) - lis, q[i].r = lower_bound(lis + 1, lis + 1 + cs, q[i].r + 1) - lis - 1;
	ll tot = 0;
	rep(i, 1, n){
		qx = q[i].l, qy = q[i].r, qd = 1;
		tot += lis[qy + 1] - lis[qx];
		Add(1, cs, 1);
		qd = (tot + 1) >> 1;
		printf("%d\n", get(1, cs, 1));
	}
	return 0;
}

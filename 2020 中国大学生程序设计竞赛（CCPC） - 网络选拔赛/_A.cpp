#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define ll long long int 
#define pb push_back
#define pc putchar
#define lowbit(x) (x & -x)
#define maxr 2000020
#define MAXN 200020
#define maxn (MAXN << 2)
#define maxm
#define maxs
#define maxb
#define M 
#define inf 1000000007
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}
int _num[20];
template <class T> void write(T x){	
	if (!x) {putchar('0'), putchar('\n'); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar('\n');
}

int n, lis[maxn], cs = 0, x[maxn], y[maxn], z[maxn];

namespace STB{
	#define ls (o << 1)
	#define rs (o << 1 | 1)
	ll miv[maxn << 2], miu[maxn << 2], smiv[maxn << 2], seg[maxn << 2], left[maxn << 2], right[maxn << 2], miadd[maxn << 2];
	ll sum[maxn << 2];
	int qx, qy, qd;
	inline void upd(int o, int v, int u) {
		if (v < miv[o]) smiv[o] = miv[o], miv[o] = v, miu[o] = u;
		else if (v == miv[o]) miu[o] += u;
		else if (v < smiv[o]) smiv[o] = v; 
	}
	inline void pu(int o) {
		sum[o] = sum[ls] + sum[rs] + abs(right[ls] - left[rs]);
		left[o] = left[ls], right[o] = right[rs];
		miv[o] = smiv[o] = inf, miu[o] = 0;
		upd(o, miv[ls], miu[ls]), upd(o, smiv[ls], 0);
		upd(o, miv[rs], miu[rs]), upd(o, smiv[rs], 0); 
		seg[o] = ((miv[ls] <= miv[rs]) ? seg[ls] : 0) + ((miv[rs] <= miv[ls]) ? seg[rs] : 0) + ((right[ls] != left[rs] && (right[ls] == miv[o] || left[rs] == miv[o])) ? 1 : 0); //XXX
	}
	inline void pass(int o, int k) {
		sum[o] -= 1ll * seg[o] * k, miadd[o] += k, left[o] += ((left[o] == miv[o]) ? k : 0), right[o] += ((right[o] == miv[o]) ? k : 0), miv[o] += k;
	}
	inline void pd(int o) {
		if (miadd[o]){ 
			ll& k = miadd[o];
			bool f1 = miv[ls] <= miv[rs], f2 = miv[rs] <= miv[ls]; //XXX
			if (f1) pass(ls, k);
			if (f2) pass(rs, k);
			k = 0;
		}
	}
	void init(int l, int r, int o) {
		sum[o] = miu[o] = seg[o] = miadd[o] = miv[o] = left[o] = right[o] = 0, smiv[o] = inf;
		if (l == r) return;
		int mid = ((r - l) >> 1) + l;
		init(l, mid, ls), init(mid + 1, r, rs);
	}
	void modmin(int l, int r, int o){
		pd(o);
		if (miv[o] >= qd) return;
		if (qx <= l && r <= qy) {
			if (qd < smiv[o]) {
				miadd[o] = qd - miv[o], miv[o] = qd, sum[o] -= 1ll * seg[o] * miadd[o], left[o] = max(left[o], qd * 1ll), right[o] = max(right[o], qd * 1ll);
				return;
			}
		}
		if (l == r){
			left[o] = right[o] = miv[o] = qd, miu[o] = 1, smiv[o] = inf, seg[o] = miadd[o] = sum[o] = 0;
			return;
		}
		int mid = ((r - l) >> 1) + l;
		if (qx <= mid) modmin(l, mid, ls);
		if (qy > mid) modmin(mid + 1, r, rs);
		pu(o);
	}
}

namespace IC{
	ll set[maxn << 2], sum[maxn << 2], qx, qy;
	inline void pu(int o) {
		sum[o] = sum[ls] + sum[rs]; 
	} 
	inline void init(int l, int r, int o) {
		set[o] = sum[o] = 0; if (l == r) return;
		int mid = ((r - l) >> 1) + l;
		init(l, mid, ls), init(mid + 1, r, rs);
	}
	void mod(int l, int r, int o) {	 
		if (set[o]) return;
		if (qx <= l && r <= qy) {
			set[o] = 1, sum[o] = lis[r + 1] - lis[l];
			return;
		}
		int mid = ((r - l) >> 1) + l;
		if (qx <= mid) mod(l, mid, ls);
		if (qy > mid) mod(mid + 1, r, rs);
		pu(o);
	}
} 

int main(){
	int T; read(T);
	while (T--){
		cs = 0;
		read(n);
		rep(i, 1, n) {
			read(x[i]), read(y[i]), read(z[i]);
			lis[++cs] = x[i], lis[++cs] = y[i];
		}
		sort(lis + 1, lis + 1 + cs);
		cs = unique(lis + 1, lis + 1 + cs) - lis - 1;
		IC :: init(1, cs, 1), STB :: init(1, cs, 1);
		rep(i, 1, n) {
			IC :: qx = lower_bound(lis + 1, lis + 1 + cs, x[i]) - lis;
			IC :: qy = lower_bound(lis + 1, lis + 1 + cs, y[i]) - lis - 1;
			IC :: mod(1, cs, 1);
			
			STB :: qx = IC :: qx, STB :: qy = IC :: qy, STB :: qd = z[i];
			STB :: modmin(1, cs, 1); 
			
			//cerr << (IC :: sum[1] << 1) << " " << (STB :: sum[1] + STB :: left[1] + STB :: right[1]) << endl;
			printf("%lld\n", (IC :: sum[1] << 1) + (STB :: sum[1] + STB :: left[1] + STB :: right[1]));
		} 
	} 
	return 0;
}


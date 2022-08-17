#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define pil pair<int, ll>
#define fi first
#define se second
#define pb push_back
#define ll long long int 
#define ld long double
#define lowbit(x) (x & -x)
#define mo(x) (x = (x >= M) ? (x - M) : x)
#define M 
#define B
#define maxn 200020
#define maxs
#define maxm 
#define maxk
#define maxb
//#define DEBUG
using namespace std;

int n, a[maxn], lis[maxn << 1], cs = 0;

int sum[maxn << 3];
ll vsum[maxn << 3];
int qx, qy, qd;
void inline pu(int o){
	sum[o] = sum[o << 1] + sum[o << 1 | 1];
	vsum[o] = vsum[o << 1] + vsum[o << 1 | 1];
}
int get(int l, int r, int o){
	if (l == r) return l;
	int mid = ((r - l) >> 1) + l;
	if (sum[o << 1] < qx) {qx -= sum[o << 1]; return get(mid + 1, r, o << 1 | 1);}
	else return get(l, mid, o << 1);
}
void mod(int l, int r, int o){
	if (l == r) {sum[o] += qd; vsum[o] += lis[l] * qd; return;}
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) mod(l, mid, o << 1);
	else mod(mid + 1, r, o << 1 | 1);
	pu(o);
}
pil get2(int l, int r, int o){
	if (qx <= l & r <= qy) return pil(sum[o], vsum[o]);
	int mid = ((r - l) >> 1) + l;
	int ans1 = 0;
	ll ans2 = 0;
	if (qx <= mid) {
		pil op = get2(l, mid, o << 1);
		ans1 += op.fi, ans2 += op.se;
	}
	if (qy > mid) {
		pil op = get2(mid + 1, r, o << 1 | 1);
		ans1 += op.fi, ans2 += op.se;
	}
	return pil(ans1, ans2);
}

int main(){
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", a + i), lis[++cs] = a[i], lis[++cs] = a[i] + 1;
	sort(lis + 1, lis + 1 + cs);
	cs = unique(lis + 1, lis + 1 + cs) - lis - 1;
	rep(i, 1, n) {
		qx = lower_bound(lis + 1, lis + 1 + cs, a[i]) - lis;
		qd = 1;
		mod(1, cs, 1);
	}
	
	ll ans = -1;
	rep(i, 1, n){
		qx = (n & 1) ? ((n + 1) >> 1) : (n >> 1);
		int v = get(1, cs, 1);
		
		ll _ans = 0;
		
		qx = v + 1, qy = cs;
		if (qx <= qy) {
			pil op = get2(1, cs, 1);
			_ans += op.se - (ll)lis[v] * op.fi;
		}
		qx = 1, qy = v - 1;
		if (qx <= qy) {
			pil op = get2(1, cs, 1);
			_ans += (ll)lis[v] * op.fi - op.se;
		}
		
		ll _r = _ans % n;
		_ans += (i - 1 < _r) ? (n + i - 1 - _r) : (i - 1 - _r);
		ans = (ans == -1) ? _ans : min(ans, _ans);
		
		qx = lower_bound(lis + 1, lis + 1 + cs, a[i]) - lis;
		qd = -1;
		mod(1, cs, 1);
		qx = lower_bound(lis + 1, lis + 1 + cs, a[i] + 1) - lis;
		qd = 1;
		mod(1, cs, 1);
	}
	printf("%lld", ans);
	return 0;
}

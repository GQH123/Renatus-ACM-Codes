#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define ll long long int 
#define maxn 200019
using namespace std;

int n;
int a[maxn];
ll sum[maxn << 1];
int add[maxn << 1];
int qx, qy, qd;
int last[maxn];

inline void pu(int o){	
	sum[o] = sum[o << 1] + sum[o << 1 | 1];
}
inline void pd(int o, int l, int r){
	if (add[o]) {	
		int mid = ((r - l) >> 1) + l;
		int& k = add[o];
		add[o << 1] += k, add[o << 1 | 1] += k;
		sum[o << 1] += (ll)(mid + 1 - l) * k, sum[o << 1 | 1] += (ll)(r - mid) * k;
		k = 0;
	}
}
void Add(int l, int r, int o){
	if (l < r) pd(o, l, r);
	if (qx <= l && r <= qy){
		sum[o] += (r - l + 1) * qd;
		add[o] += qd;
		return;
	}
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) Add(l, mid, o << 1);
	if (qy > mid) Add(mid + 1, r, o << 1 | 1);
	pu(o);
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("B.in", "r", stdin);
	#endif
	scanf("%d", &n);
	int mx = 0;
	rep(i, 1, n) scanf("%d", &a[i]), mx = max(mx, a[i]);
	rep(i, 1, mx) last[i] = 0;
	ll ans = 0;
	rep(i, 1, n){
		qx = last[a[i]] + 1, qy = i, qd = 1;
		Add(1, n, 1);
		ans += sum[1];
		last[a[i]] = i;
	}
	printf("%lld", ans);
	return 0;
}

#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define maxn 200020
#define pb push_back 
#define pll pair<ll, ll>
#define fi first
#define se second
#define ll long long int 
#define lowbit(x) (x & -x) 
using namespace std;   


int n, m, a[maxn];

ll sum[maxn << 2], al[maxn << 2], ar[maxn << 2], add[maxn << 2];
int qx, qy, qd;
inline void pu(int o){
	al[o] = al[o << 1];
	ar[o] = ar[o << 1 | 1];
	sum[o] = sum[o << 1] + sum[o << 1 | 1] - min(ar[o << 1], al[o << 1 | 1]);
}
inline void pd(int o){
	if (add[o]){
		ll& k = add[o];
		add[o << 1] += k, sum[o << 1] += k, al[o << 1] += k, ar[o << 1] += k;
		add[o << 1 | 1] += k, sum[o << 1 | 1] += k, al[o << 1 | 1] += k, ar[o << 1 | 1] += k;
		k = 0;
	}
}
void init(int l, int r, int o){ 
	add[o] = 0;
	if (l == r) {sum[o] = al[o] = ar[o] = a[l]; return;}
	int mid = ((r - l) >> 1) + l;
	init(l, mid, o << 1), init(mid + 1, r, o << 1 | 1);
	pu(o);
}
void mod(int l, int r, int o){
	pd(o);
	if (qx <= l && r <= qy) {sum[o] += qd, al[o] += qd, ar[o] += qd, add[o] += qd; return;}
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) mod(l, mid, o << 1);
	if (qy > mid) mod(mid + 1, r, o << 1 | 1);
	pu(o);
}
ll get(int l, int r, int o){
	pd(o);
	if (qx <= l && r <= qy) return sum[o];
	int mid = ((r - l) >> 1) + l;
	ll ans1 = 0, v1 = 0, ans2 = 0, v2 = 0;
	if (qx <= mid) ans1 = get(l, mid, o << 1), v1 = ar[o << 1];
	if (qy > mid) ans2 = get(mid + 1, r, o << 1 | 1), v2 = al[o << 1 | 1];
	return ans1 + ans2 - min(v1, v2);
}

int main(){	  
	int T, x, y, op;
	scanf("%d", &T);
	while (T--){ 
		scanf("%d%d", &n, &m); 
		rep(i, 1, n) scanf("%d", a + i);
		init(1, n, 1);
		rep(i, 1, m){
			scanf("%d", &op);
			if (op == 1){
				scanf("%d%d%d", &qx, &qy, &qd);
				mod(1, n, 1);
			}
			else if (op == 2){	
				scanf("%d%d", &qx, &qy);
				printf("%lld\n", get(1, n, 1));
			}
		}
	}
	return 0;
}

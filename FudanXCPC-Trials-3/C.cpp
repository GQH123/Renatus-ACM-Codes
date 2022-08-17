#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
#define maxn 200020
#define maxm
#define M 1000000007
#define mo(x) (x = (x >= M) ? (x - M) : x)
using namespace std;

int power(int x, int y){
	int ans = 1, con = x;
	while (y){
		if (y & 1) ans = 1ll * ans * con % M;
		con = 1ll * con * con % M;
		y >>= 1;
	}
	return ans;
}
int getinv(int x){
	return power(x, M - 2);
}

extern int getn(int l, int r, int o);

int n, lis[maxn], cs = 0;
int mi2[maxn], invmi2_1[maxn], miy[maxn];
//int mix[maxn], miy[maxn];
pii a[maxn];

int sum[maxn << 2], num[maxn << 2], mul[maxn << 2];
int qx, qy, qd;
inline void pu(int o){
	sum[o] = sum[o << 1] + sum[o << 1 | 1], mo(sum[o]);
	num[o] = num[o << 1] + num[o << 1 | 1];
}
inline void upd(int o, int k){
	mul[o] = 1ll * mul[o] * k % M, sum[o] = 1ll * sum[o] * k % M;
}
inline void pd(int o){
	if (mul[o] != 1){ 
		upd(o << 1, mul[o]), upd(o << 1 | 1, mul[o]);
		mul[o] = 1;
	}
}
void init(int l, int r, int o){
	sum[o] = num[o] = 0, mul[o] = 1;
	if (l == r) return;
	int mid = ((r - l) >> 1) + l;
	init(l, mid, o << 1), init(mid + 1, r, o << 1 | 1);
}
void Mul(int l, int r, int o){
	pd(o);
	if (qx <= l && r <= qy){ upd(o, qd); return; }
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) Mul(l, mid, o << 1);
	if (qy > mid) Mul(mid + 1, r, o << 1 | 1);
	pu(o);
}
void add(int l, int r, int o){ //qd == 1	
	pd(o);
	if (l == r){
		if (num[o]) sum[o] = 1ll * sum[o] * invmi2_1[num[o]] % M * (mi2[num[o] + 1] + M - 1) % M; 
		else {
			qx = 1, qy = l - 1;
			sum[o] = 1ll * mi2[(qx <= qy) ? getn(1, cs, 1) : 0] * miy[l] % M;
		}
		num[o]++;
		return;
	}
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) add(l, mid, o << 1);
	else add(mid + 1, r, o << 1 | 1);
	pu(o);
}
int gets(int l, int r, int o){
	pd(o);
	if (qx <= l && r <= qy) return sum[o];
	int mid = ((r - l) >> 1) + l, ans = 0;
	if (qx <= mid) ans += gets(l, mid, o << 1), mo(ans);
	if (qy > mid) ans += gets(mid + 1, r, o << 1 | 1), mo(ans);
	return ans;
}
int getn(int l, int r, int o){
	pd(o);
	if (qx <= l && r <= qy) return num[o];
	int mid = ((r - l) >> 1) + l, ans = 0;
	if (qx <= mid) ans += getn(l, mid, o << 1);
	if (qy > mid) ans += getn(mid + 1, r, o << 1 | 1);
	return ans;
}

int main(){
	while (scanf("%d", &n) == 1){
		mi2[0] = 1;
		rep(i, 1, n) mi2[i] = (mi2[i - 1] << 1), mo(mi2[i]);
		rep(i, 1, n) invmi2_1[i] = getinv((mi2[i] + M - 1) % M);
		//int inv2 = getinv(2);
		//invmi2[0] = 1;
		//rep(i, 1, n) invmi2[i] = 1ll * invmi2[i - 1] * inv2 % M;
		
		
		rep(i, 1, n) scanf("%d%d", &a[i].se, &a[i].fi); ///reversed!!!
		sort(a + 1, a + 1 + n);
		
		/*
		cs = 0; rep(i, 1, n) lis[++cs] = a[i].fi; 
		sort(lis + 1, lis + 1 + cs);
		cs = unique(lis + 1, lis + 1 + cs) - lis - 1;
		rep(i, 1, cs) mix[i] = power(2, lis[i]);
		rep(i, 1, n) a[i].fi = lower_bound(lis + 1, lis + 1 + cs, a[i].fi) - lis;
		*/
		
		cs = 0; rep(i, 1, n) lis[++cs] = a[i].se; 
		sort(lis + 1, lis + 1 + cs);
		cs = unique(lis + 1, lis + 1 + cs) - lis - 1;
		rep(i, 1, cs) miy[i] = power(2, lis[i]);
		rep(i, 1, n) a[i].se = lower_bound(lis + 1, lis + 1 + cs, a[i].se) - lis;
		
		init(1, cs, 1);
		int res = 0;
		rep(i, 1, n){
			int mi3 = power(3, a[i].fi);
			qx = a[i].se + 1, qy = cs;
			res += 1ll * mi3 * gets(1, cs, 1) % M, mo(res);
			qx = 1, qy = a[i].se;
			res += 1ll * mi3 * miy[a[i].se] % M * mi2[getn(1, cs, 1)] % M, mo(res);
			
			
			qx = a[i].se + 1, qy = cs, qd = 2;
			if (qx <= qy) Mul(1, cs, 1);
			qx = a[i].se;
			add(1, cs, 1);
		}
		printf("%d\n", res);
	}
	return 0;
}

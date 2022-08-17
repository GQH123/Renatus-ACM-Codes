#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
#define maxn (1 << 19)
#define lowbit(x) (x & -x)
using namespace std;

int n, m, w[maxn], v[maxn], d[maxn];

int A[25], B[25];
pii SA[1 << 10], SB[1 << 10]; 

int c[maxn], st[maxn], cs = 0;
void add(int x, int y){
	while (x < maxn){
		if (!c[x]) st[++cs] = x;
		c[x] = max(c[x], y);
		x += lowbit(x);
	}
}
int get(int x){
	int ans = 0;
	while (x){
		ans = max(ans, c[x]);
		x -= lowbit(x);
	}
	return ans;
}
void recover(){
	while (cs) c[st[cs--]] = 0;
}

int play(int x, int y){	
	int a = (d[x] + 1) >> 1, _a = a, b = d[x] - a, _b = b;
	while (a){
		A[--a] = x;
		x >>= 1;
	}
	while (b){
		B[--b] = x;
		x >>= 1;
	}
	/*
	a = _a, b = _b;
	srep(i, 0, (1 << a)){
		int sw = 0, sv = 0;
		srep(j, 0, a){
			if (i & (1 << j)) sw += w[A[j]], sv += v[A[j]];
		}
		SA[i] = pii(sw, sv);
	}
	srep(i, 0, (1 << b)){
		int sw = 0, sv = 0;
		srep(j, 0, b){
			if (i & (1 << j)) sw += w[B[j]], sv += v[B[j]];
		}
		SB[i] = pii(sw, sv);
	}
	*/
	a = _a, b = _b;
	int ca = 0, cb = 0, mx = 0;
	SA[ca++] = pii(0, 0), SB[cb++] = pii(0, 0);
	srep(i, 0, a){
		int _ca = ca;
		srep(j, 0, _ca){
			SA[ca++] = pii(SA[j].fi + w[A[i]], SA[j].se + v[A[i]]);
			if (SA[ca - 1].fi) add(SA[ca - 1].fi, SA[ca - 1].se);
		}
	}
	srep(i, 0, b){
		int _cb = cb;
		srep(j, 0, _cb) {
			SB[cb++] = pii(SB[j].fi + w[B[i]], SB[j].se + v[B[i]]);
			if (y >= SB[cb - 1].fi) mx = max(mx, get(y - SB[cb - 1].fi) + SB[cb - 1].se);
		}
	}
	mx = max(mx, get(y));
	recover();
	return mx;
	/*
	sort(SA, SA + (1 << a)); 
	sort(SB, SB + (1 << b));
	mxB[0] = SB[0].se;
	srep(i, 1, (1 << b)) mxB[i] = max(mxB[i - 1], SB[i].se);
	int mx = 0, ptr = (1 << b) - 1;
	srep(i, 0, (1 << a)){
		int noww = SA[i].fi;
		while (ptr > -1 && noww + SB[ptr].fi > y) ptr--;
		if (ptr > -1) mx = max(mx, SA[i].se + mxB[ptr]);
		else return mx;
	}
	return mx;
	*/
}
int main(){ 
	int x, y;
	scanf("%d", &n);
	rep(i, 1, n) d[i] = d[i >> 1] + 1, scanf("%d%d", v + i, w + i);
	scanf("%d", &m);
	rep(i, 1, m) scanf("%d%d", &x, &y), printf("%d\n", play(x, y));
	return 0;
}



#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define ll long long int  
#define fi first
#define se second
#define maxn (1 << 19)
using namespace std;

struct pii{
	int fi, se;
	pii(int fi, int se) : fi(fi), se(se){}
	pii(){}
	bool operator < (const pii b) const{
		return (fi == b.fi) ? se < b.se : fi < b.fi;
	}
};

int n, m, w[maxn], v[maxn], d[maxn];

int A[25], B[25];
pii SA[1 << 10], SB[1 << 10];
int mxB[1 << 10]; 
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
	a = _a, b = _b;
	int ca = 0, cb = 0;
	SA[ca++] = pii(0, 0), SB[cb++] = pii(0, 0);
	srep(i, 0, a){
		int _ca = ca;
		srep(j, 0, _ca){
			SA[ca++] = pii(SA[j].fi + w[A[i]], SA[j].se + v[A[i]]);
		}
	}
	srep(i, 0, b){
		int _cb = cb;
		srep(j, 0, _cb) {
			SB[cb++] = pii(SB[j].fi + w[B[i]], SB[j].se + v[B[i]]);
		}
	}
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
}
int main(){ 
	int x, y;
	scanf("%d", &n);
	rep(i, 1, n) d[i] = d[i >> 1] + 1, scanf("%d%d", v + i, w + i);
	scanf("%d", &m);
	rep(i, 1, m) scanf("%d%d", &x, &y), printf("%d\n", play(x, y));
	return 0;
}



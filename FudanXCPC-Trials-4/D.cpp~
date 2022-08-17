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
#define maxn 300020
#define maxm
#define lowbit(x) (x & -x)
using namespace std;

int n, v[3], maxt, mint;

struct person{
	int a, t, p, w, id;
	person(int a, int t, int p, int w, int id) : a(a), t(t), p(p), w(w), id(id){}
	person(){}
	bool operator < (const person& b) const{
		return p == b.p ? a < b.a : p < b.p;
	}
}p[maxn];
int res[maxn];

ll lis[maxn << 2], cs = 0;
int c[maxn << 2];
inline void add(int x, int v){
	while (x <= cs){
		c[x] += v;
		x += lowbit(x);
	}
}
inline int get(int x){
	int ans = 0;
	while (x){
		ans += c[x];
		x -= lowbit(x);
	}
	return ans;
}

/*
void play1(int type){
	cs = 0;
	rep(i, 1, n) if (p[i].a == type) lis[++cs] = p[i].p, lis[++cs] = p[i].p + p[i].w; 
	sort(lis + 1, lis + 1 + cs);
	cs = unique(lis + 1, lis + 1 + cs) - lis - 1;
	per(i, n, 1){
		if (p[i].a == type) {
			res[p[i].id] += get(lower_bound(lis + 1, lis + 1 + cs, p[i].p + p[i].w) - lis);
			int x = lower_bound(lis + 1, lis + 1 + cs, p[i].p) - lis;
			res[p[i].id] -= get(x - 1); 
			add(x, 1);
		}
	} rep(i, 1, cs) c[i] = 0;
}
*/

inline ll offset(int t){
	return 1ll * t * v[1] * v[2];
}

void play(int type){
	cs = 0;
	rep(i, 1, n) {
		if (p[i].a == type) lis[++cs] = 1ll * p[i].p * v[type] + offset(maxt - p[i].t), lis[++cs] = 1ll * (p[i].p + p[i].w) * v[type] + offset(maxt - p[i].t);
		else lis[++cs] = 1ll * p[i].p * v[3 - type] + offset(maxt - p[i].t);
	}
	sort(lis + 1, lis + 1 + cs);
	cs = unique(lis + 1, lis + 1 + cs) - lis - 1; 
	per(i, n, 1) if (p[i].a != type) add(lower_bound(lis + 1, lis + 1 + cs, 1ll * p[i].p * v[3 - type] + offset(maxt - p[i].t)) - lis, 1); 
	per(i, n, 1){
		if (p[i].a == type) {
			res[p[i].id] += get(lower_bound(lis + 1, lis + 1 + cs, 1ll * (p[i].p + p[i].w) * v[type] + offset(maxt - p[i].t)) - lis);
			res[p[i].id] -= get(lower_bound(lis + 1, lis + 1 + cs, 1ll * p[i].p * v[type] + offset(maxt - p[i].t)) - lis - 1);
		} 
	} rep(i, 1, cs) c[i] = 0;
}

int main(){
	int T, x, y, z, w; scanf("%d", &T);
	rep(TT, 1, T){
		printf("Case #%d:\n", TT);
		scanf("%d%d%d", &n, &v[1], &v[2]);
		rep(i, 1, n) res[i] = 0;
		rep(i, 1, n){
			scanf("%d%d%d%d", &x, &y, &z, &w);
			p[i] = person(x, y, z, w, i);
		}
		mint = p[1].t, maxt = p[1].t;
		rep(i, 1, n) mint = min(mint, p[i].t), maxt = max(maxt, p[i].t);
		//sort(p + 1, p + 1 + n), play1(1), play1(2), play2(1), play2(2);
		play(1), play(2);
		rep(i, 1, n) printf("%d\n", res[i]); 
	}
	return 0;
}

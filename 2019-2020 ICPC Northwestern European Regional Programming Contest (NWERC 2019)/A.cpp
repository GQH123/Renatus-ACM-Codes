#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define maxn 500020
#define pb push_back
#define ll long long int 
using namespace std; 

int n, m;
struct ele{
	ll t, v, s;
	ele(ll t, ll v, ll s) : t(t), v(v), s(s){}
	ele(){}
}p[maxn]; 
ll res[maxn];
int sc[maxn];

int main(){ 
	int x, k;
	scanf("%d%d", &n, &m);
	p[0] = ele(1, 1, 0);
	rep(i, 1, m){
		scanf("%d", &k);
		rep(j, 1, k){
			scanf("%d", &x);
			int id = sc[x];
			p[id].s += (i - p[id].t) * p[id].v, p[id].t = i, p[id].v++;
			res[x] += p[id].s;
			sc[x]++, id++;
			if (!p[id].v) p[id].v = 1, p[id].t = i, p[id].s = 0;
			p[id].s += (i - p[id].t) * p[id].v, p[id].t = i;
			res[x] -= p[id].s;
		}
	}
	
	rep(i, m + 1, m + 1){
		rep(x, 1, n){ 
			int id = sc[x];
			p[id].s += (i - p[id].t) * p[id].v, p[id].t = i;
			res[x] += p[id].s;  
		}
	}
	rep(i, 1, n) printf("%.8Lf\n", (long double)res[i] / m); 
	return 0;
}

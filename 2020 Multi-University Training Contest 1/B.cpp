#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define ll long long int 
#define maxn 300020
using namespace std;

int n;
struct ele{
	ll t, d;
	ele(ll t, ll d) : t(t), d(d){}
	ele(){}
	bool operator < (const ele b) const{
		return t < b.t;
	}
}p[maxn];
int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		scanf("%d", &n);
		rep(i, 1, n) scanf("%lld", &p[i].t);
		rep(i, 1, n) scanf("%lld", &p[i].d);
		sort(p + 1, p + 1 + n);
		ll nowt = 0;
		ll ans = 0;
		rep(i, 1, n){
			nowt = max(nowt, p[i].t);
			ans = max(ans, nowt - p[i].t);
			nowt += p[i].d;
		}
		printf("%lld\n", ans);
	}
	return 0;
}

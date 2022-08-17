#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define ui unsigned int
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define pb push_back
#define pi 3.141592653589793
#define maxn 25
#define maxm 
#define maxs 
#define M 
#define Base 
#define Hash 
#define Author Renatus
//#define DEBUG
//#define ONLINE_JUDGE
using namespace std;

int n;
struct ele{
	int h, t;
	bool operator < (const ele b) const{
		return h * b.t < b.h * t;
	}
}a[maxn];

int main(){
	
		#ifndef ONLINE_JUDGE
			freopen("A.in", "r", stdin);
		#endif
	
	while (scanf("%d", &n) == 1){
		int sum = 0;
		rep(i, 1, n) scanf("%d%d", &a[i].t, &a[i].h), sum += a[i].t;
		sort(a + 1, a + 1 + n);
		ll ans = 0;
		rep(i, 1, n){
			ans += (ll)sum * a[i].h;
			sum -= a[i].t;
		}
		printf("%lld\n", ans);
	}
	return 0;
}

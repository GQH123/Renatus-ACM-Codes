#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 400200
#define ll long long int 
using namespace std; 

const ll inf = 3000000000000000000ll;

ll n, a[maxn], up[maxn]; 

int main(){
	scanf("%lld", &n);
	rep(i, 0, n) scanf("%lld", a + i);
	if (!n){	
		if (a[0] == 1) printf("1");
		else printf("-1");
		return 0;
	} 
	up[0] = 1;
	if (up[0] < a[0]) {printf("-1"); return 0;}
	rep(i, 1, n){	
		up[i] = (up[i - 1] << 1) - (a[i - 1] << 1);
		if (up[i] > inf) up[i] = inf;
		if (i == n){
			if (up[i] < a[i]) {printf("-1"); return 0;}
		}
		else {
			if (up[i] <= a[i]) {printf("-1"); return 0;}
		} 
	}
	//rep(i, 0, n) cerr << up[i] << ' ';
	ll ans = 0;
	ll now = a[n];
	ans += now;
	per(i, n - 1, 0){
		now = now + a[i];
		now = min(now, up[i]);
		ans += now;
	}
	printf("%lld", ans);
	return 0;
}

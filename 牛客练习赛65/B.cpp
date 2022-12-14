#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define maxn 3020
#define maxm
#define pii pair<int, int>
#define ll long long int 
using namespace std;

int n, m, k; ll M;
int res[maxn];
ll power(int x, int y, ll M){
	ll ans = 1;
	rep(i, 1, y){
		ans = ans * x % M;
	}
	return ans;
}

int main(){
	scanf("%d%d%d%lld", &n, &m, &k, &M);
	if (k == 1) {printf("%lld", 1 % M); return 0;}
	ll x;
	rep(i, 1, n) rep(j, 1, m){
		scanf("%lld", &x);
		while (x > 1) x /= k, res[i]++; 
	}
	int mx = 0;
 	rep(i, 1, n) mx = max(mx, res[i]);
 	printf("%lld", power(k, mx, M));
	return 0;
}

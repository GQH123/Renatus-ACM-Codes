#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define maxn 
#define ll long long int 
using namespace std;

int main(){
	ll n, a, b;
	//#ifndef ONLINE_JUDGE
	//	freopen("A.in", "r", stdin);
	//#endif
	scanf("%lld%lld%lld", &n, &a, &b);
	if (abs(a - b) & 1) printf("%lld", min(a + ((b - a - 1) >> 1), n - b + 1 + ((b - a - 1) >> 1))); 
	else printf("%lld", abs(a - b) >> 1);
	return 0;
}

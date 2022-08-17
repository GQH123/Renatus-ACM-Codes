#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define ll long long int 
using namespace std;

int main(){
	ll a, b, c, d;
	scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
	ll _c = c, _d = d;
	ll ans1 = 0;
	while (c < a) c <<= 1, ans1++;
	while (d < b) d <<= 1, ans1++;
	c = _c, d = _d;
	ll ans2 = 0;
	while (c < b) c <<= 1, ans2++;
	while (d < a) d <<= 1, ans2++;
	printf("%lld\n", min(ans1, ans2));
	return 0;
}

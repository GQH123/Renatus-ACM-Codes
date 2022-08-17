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
#define maxn 200020
#define maxm
#define lowbit(x) (x & -x)
using namespace std;

int n, k, a[maxn], lis[maxn], cs = 0;
int c[maxn];
void add(int x, int v){
	while (x){
		c[x] += v;
		x -= lowbit(x);
	}
}
int get(int x){
	int ans = 0;
	while (x <= cs){
		ans += c[x];
		x += lowbit(x);
	}
	return ans;
}

int main(){
	while (scanf("%d%d", &n, &k) == 2){
		cs = 0; 
		rep(i, 1, n) scanf("%d", a + i), lis[++cs] = a[i];
		sort(lis + 1, lis + 1 + cs);
		cs = unique(lis + 1, lis + 1 + cs) - lis - 1;
		ll ans = 0;
		rep(i, 1, n){
			a[i] = lower_bound(lis + 1, lis + 1 + cs, a[i]) - lis;
			ans += get(a[i] + 1);
			add(a[i], 1);
		} 
		printf("%lld\n", max(0ll, ans - k));
		rep(i, 1, cs) c[i] = 0;
	} 
	return 0;
}

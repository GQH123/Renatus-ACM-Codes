#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int
#define maxn 
#define maxm 
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back

int a1,a2, k1, k2, n;

using namespace std;

int main(){
	freopen("A.in", "r", stdin);
	
	scanf("%d%d%d%d%d", &a1, &a2, &k1, &k2, &n);
	
	int _n = n, ans;
	
	if (k1 > k2) swap(a1, a2), swap(k1, k2);
	
	
	if (n > (k1 - 1) * a1 + (k2 - 1) * a2){
		n -= (k1 - 1) * a1 + (k2 - 1) * a2;
		printf("%d", min(a1 + a2, n));
	}
	else printf("0");
	
	
	n = _n, ans = 0;
	if (n > a1 * k1){
		ans += a1;
		n -= a1 * k1;
		printf(" %d", ans + n / k2);
	}
	else {
		printf(" %d", n / k1);
	}
	
	
	return 0;
}


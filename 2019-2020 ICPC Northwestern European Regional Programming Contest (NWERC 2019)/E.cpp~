#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define maxn 10
using namespace std; 

int a[maxn];

int main(){
	int x, y;
	rep(i, 1, 4) scanf("%d.%d", &x, &y), a[i] = 100 * x + y;
	int t;
	scanf("%d.%d", &x, &y), t = 100 * x + y;
	int mi = a[1], mx = a[1], sum = 0;
	rep(i, 1, 4) mi = min(mi, a[i]), mx = max(mx, a[i]), sum += a[i];
	//rep(i, 1, 4) cerr << a[i] << ' '; cerr << t << endl;
	if (sum - mi <= 3 * t) {
		printf("infinite");
		return 0;
	}
	if (sum - mx > 3 * t) {
		printf("impossible");
		return 0;
	}
	int ans = 3 * t - (sum - mi - mx);
	int a = ans / 100, b = ans % 100;
	if (b <= 9) printf("%d.0%d", a, b);
	else printf("%d.%d", a, b);
	return 0;
}

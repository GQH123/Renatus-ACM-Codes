#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define maxn 200020
using namespace std;

int n, a[maxn], m, b[maxn], k;
int main(){
	int x, y, z;
	scanf("%d%d%d", &n, &m, &k);
	int mia = maxn, mib = maxn;
	rep(i, 1, n) scanf("%d", a + i), mia = min(mia, a[i]);
	rep(i, 1, m) scanf("%d", b + i), mib = min(mib, b[i]);
	int res = mia + mib;
	rep(i, 1, k){
		scanf("%d%d%d", &x, &y, &z);
		res = min(res, a[x] + b[y] - z);
	} 
	printf("%d", res);
	return 0;
}

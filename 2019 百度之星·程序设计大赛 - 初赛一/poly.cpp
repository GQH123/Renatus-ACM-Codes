#include <bits/stdc++.h>
#define maxn 2019
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
using namespace std;

int n;
int a[maxn], b[maxn];
int gcd(int x, int y){
	return (!y) ? x : gcd(y, x % y);
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("poly.in", "r", stdin);
	#endif
	int T;
	scanf("%d", &T);
	while (T--){
		scanf("%d", &n);
		srep(i, 0, n) scanf("%d", &a[i]);
		srep(i, 0, n) scanf("%d", &b[i]);
		int mxa = 0, mxae = 0;
		per(i, n - 1, 0) {
			if (a[i]) {
				mxa = i, mxae = a[i];
				break;
			}
		}
		int mxb = 0, mxbe = 0;
		per(i, n - 1, 0) {
			if (b[i]) {
				mxb = i, mxbe = b[i];
				break;
			}
		}
		if (mxa < mxb) printf("0/1\n");
		else if (mxa > mxb) printf("1/0\n");
		else {
			int d = gcd(abs(mxae), abs(mxbe));
			printf("%d/%d\n", mxae / d, mxbe / d);
		}
	}
	return 0;
}

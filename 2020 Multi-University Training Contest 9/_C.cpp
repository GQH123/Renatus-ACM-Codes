#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
using namespace std;

/*
bool judge(int a, int mid, int tim){
	return tim + mid <= a;
}
int lower_bound(int a, int l, int r, int tim){
	while (l < r){
		int mid = ((r - l + 1) >> 1) + l;
		if (judge(a, mid, tim)) l = mid;
		else r = mid - 1;
	}
	return l;
}
*/

int cal(int k, int n){
	double res = n * (sqrt(4 + 1.0 * k * k) + 2 - k) / 2.0;
	return (int)res;
}

int main(){
	int T, a, b, k; scanf("%d", &T);
	while (T--){
		scanf("%d%d%d", &a, &b, &k);
		if (a > b) swap(a, b);
		if ((b - a) % (k + 1) != 0) {
			printf("1\n");
		}
		else {
			int tim = (b - a) / (k + 1);
			int res = cal(k + 1, tim);
			if (res == a){
				printf("0\n");
			}
			else {
				printf("1\n");
			}
			/*
			int res = lower_bound(a, 0, tim, tim);
			if (tim + res == a){
				printf("0\n");
			}
			else {
				printf("1\n");
			}
			*/
		}
	}
	return 0;
}

#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define ll long long int 
using namespace std;

ll a[6];
int main(){
	#ifndef ONLINE_JUDGE
		freopen("seq.in", "r", stdin);
		//freopen("table.out", "w", stdout);
	#endif
	int n;
	/*scanf("%d", &n);
	ll sum = 1;
	int a = 1;
	printf("%d\n", 1);
	rep(i, 2, n){
		a = sum % i;
		sum += a * i;
		printf("%d\n", a);
	}*/
	int T; ll x;
	scanf("%d", &T);
	while (T--){
		scanf("%I64d", &x);
		if (x == 1) printf("1\n");
		else if (x == 2) printf("1\n");
		else {
			ll pos = (x - 3) / 6;
			if (x % 6 == 3 || x % 6 == 5) printf("%I64d\n", pos);
			else if (x % 6 == 4) printf("%I64d\n", x - 1);
			else if (x % 6 == 0) printf("%I64d\n", x / 2);
			else if (x % 6 == 1) printf("%I64d\n", (pos + 1) * 4 + 1);
			else printf("%I64d\n", (pos + 1) * 3 + 1);
		}
	}
	return 0;
}

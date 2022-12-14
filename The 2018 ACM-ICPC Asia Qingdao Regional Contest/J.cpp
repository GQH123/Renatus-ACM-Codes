#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 200019
#define ll long long int 
using namespace std;

int n, m;
int a[maxn];

int main(){	
	#ifndef ONLINE_JUDGE
		freopen("J.in", "r", stdin);
	#endif
	int T;
	scanf("%d", &T);
	while (T--){
		scanf("%d%d", &n, &m);
		rep(i, 1, n) scanf("%d", &a[i]);
		if (n == m) printf("Richman\n");
		else {
			rep(i, 1, n) if (!a[i]) m--; 
			if (m < 0) printf("Impossible\n");
			else {
				ll sum = 0;
				rep(i, 1, n){
					if (!m) {
						int mi = 1000000001;
						rep(j, i, n) if (a[j]) mi = min(mi, a[j]); 
						sum += mi - 1;
						break;
					}
					if (a[i]) m--, sum += a[i]; 
				}
				printf("%lld\n", sum);
			}
		}
	}
	return 0;
}



#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 200020
using namespace std;

int res[maxn];
int main(){
	int T, n, x, y; scanf("%d", &T);
	while (T--){
		scanf("%d%d%d", &n, &x, &y);
		if (x == 1){
			if (y != n) printf("NO\n");
			else {
				printf("YES\n");
				per(i, n, 1) {
					if (i != n) printf(" ");
					printf("%d", i);
				}
				printf("\n");
			}
			continue;
		}
		if (y == 1){
			if (x != n) printf("NO\n");
			else {
				printf("YES\n");
				rep(i, 1, n) {
					if (i != 1) printf(" ");
					printf("%d", i);
				}
				printf("\n");
			}
			continue;
		}
		if (x + y > n + 1) {printf("NO\n"); continue;}
		int k = -1;
		rep(i, 1, x) if (n - x <= i * (y - 1)) {k = i; break;}
		if (k == -1) printf("NO\n");
		else {	
			if (n - x + k < y) {
				printf("NO\n");
				continue;
			}
			printf("YES\n");
			bool first = 1;
			rep(i, 1, n) res[i] = i;
			int rest = n - (x - k) - (k - 1) * y;
			int ptr = x - k + 1;
			rep(i, 1, k){
				if (i == 1){
					reverse(res + ptr, res + min(n + 1, ptr + rest));
					ptr += rest;
				}
				else {
					reverse(res + ptr, res + min(n + 1, ptr + y));
					ptr += y;
				} 
			}
			rep(i, 1, n){
				if (first) first = 0;
				else printf(" ");
				printf("%d", res[i]);
			}
			printf("\n");
			/*
			rep(i, 1, x - k) {
				if (first) first = 0;
				else printf(" ");
				printf("%d", i);
			}
			int ptr = 
			*/
		} 
	}
	return 0;
}

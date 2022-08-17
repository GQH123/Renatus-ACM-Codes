#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 2000020
using namespace std;

int num[10];
int judge(){
	for (register int i = 96; i >= 0; i -= 4){
		int x = i % 10, y = i / 10;
		if (x == y) {
			if (num[x] >= 2) return i;
		}
		else {
			if (num[x] && num[y]) return i;
		}
	}
	return -1;
}
int res[maxn];
int main(){
	int T; scanf("%d", &T);
	while (T--){
		int n = 0;
		rep(i, 0, 9) scanf("%d", num + i), n += num[i];
		int mx = -1;
		rep(i, 0, 9) {
			if (!num[i] || (i % 4)) continue;
			mx = max(mx, i);
		}
		/*
		if (n == 1) {
			int x = -1;
			rep(i, 0, 9) {
				if (num[i]) {
					x = i;
					break;
				}
			}
			if (x % 4 == 0) printf("%d\n", x);
			else printf("%d\n", mx);
			continue;
		}
		*/
		int ptr = 9, fin;
		rep(i, 1, n - 2){
			while (ptr >= 0 && !num[ptr]) ptr--;
			bool f = 0;
			per(j, ptr, 0) {
				if (!num[j]) continue;
				res[i] = j;
				num[j]--;
				if (judge() == -1) num[j]++; 
				else {f = 1; break;}
			}
			if (!f) {
				printf("%d\n", mx);
				goto done;
			}
		} 
		fin = judge();
		if (fin == -1){
			printf("%d\n", mx);
			goto done;
		}
		res[n - 1] = fin / 10, res[n] = fin % 10;
		ptr = 1;
		while (ptr <= n && !res[ptr]) ptr++;
		if (ptr > n) {
			printf("%d\n", mx);
			goto done;
		}
		rep(i, ptr, n) printf("%d", res[i]); printf("\n");
		done:; 
	}
	return 0;
}

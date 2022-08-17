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
#define maxn 1020
#define maxm
#define M 1000000007
#define mo(x) (x = (x >= M) ? (x - M) : x)
using namespace std; 

int n; char s[maxn];

int main(){
	int T; scanf("%d", &T);
	while (T--){
		scanf("%s", s + 1);
		n = strlen(s + 1);
		int l = -1, r = -1;
		rep(i, 1, n) {
			if (s[i] == 'R') {
				l = i;
				break;
			}
		}
		per(i, n, 1){
			if (s[i] == 'R') {
				r = i;
				break;
			}
		}
		int res = 0;
		if (l == -1){
			res++;
			rep(i, 1, n){
				if (s[i] == 'G') continue;
				res++;
				for (register int step = 1; step <= n; step += 2){
					int ptr = i + step;
					while (ptr <= n && s[ptr] != 'G') {
						res++, mo(res);
						ptr += step;
					}
				}
			}
		}
		else {
			int pass = 0, allred = 0;
			rep(i, 1, n) if (s[i] == 'R') allred++;
			if (l == r) res++;
			for (register int step = 1; step <= n; step += 2){ 
				int ptr, leftsum, rightsum;
				ptr = l + step;
				pass = 1;
				bool f = 1;
				while (ptr <= r) { 
					if (s[ptr] == 'R') pass++;
					if (s[ptr] == 'G') {f = 0; break;}
					ptr += step;
				}
				if (pass != allred || !f) continue;
				ptr = l - step, leftsum = 1;
				while (ptr >= 1 && s[ptr] != 'G') {	
					leftsum++;
					ptr -= step;
				}
				ptr = r + step, rightsum = 1;
				while (ptr <= n && s[ptr] != 'G') {
					rightsum++;
					ptr += step;
				}
				if (l == r) res += (1ll * leftsum * rightsum - 1) % M, mo(res); 
				else res += 1ll * leftsum * rightsum % M, mo(res);
			}
		}
		int all = 1;
		rep(i, 1, n) if (s[i] == '?') all <<= 1, mo(all); 
		printf("%d\n", (all + M - res) % M);
	}
	return 0;
}

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
#define maxn 
#define maxm
using namespace std;

int main(){
	int T, n, x; scanf("%d", &T);
	rep(TT, 1, T){
		printf("Case %d: ", TT);
		int res = 0, s = 0;
		scanf("%d", &n);
		rep(i, 1, n) {
			scanf("%d", &x);
			s = 1;
			while (x) s ^= (x & 1), x >>= 1; 
			res ^= s;
		}
		if (res) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}

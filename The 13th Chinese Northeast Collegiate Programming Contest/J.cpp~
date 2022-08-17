#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define maxn 300020
#define pb push_back 
#define pll pair<ll, ll>
#define fi first
#define se second
#define ll long long int 
using namespace std;  
int main(){	  
	int T, x, n;
	scanf("%d", &T);
	while (T--){ 
		scanf("%d", &n);
		int mi = 0;
		rep(i, 1, n){
			scanf("%d", &x);
			if (i == 1) mi = max(mi, x * 3);
			else mi = max(mi, x + 1);
		}
		printf("%d\n", (mi & 1) ? (mi + 1) : mi);
	}
	return 0;
}

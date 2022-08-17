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

int gcd(int x, int y){
	if (!y) return x;
	return gcd(y, x % y);
}

int main(){
	rep(n, 1, 10000) {
		int res = 1;
		rep(j, 1, n) if (gcd(j, n) == 1) res = 1ll * res * j % n;
		printf("%d : %d\n", n, res);
	}
	return 0;
}

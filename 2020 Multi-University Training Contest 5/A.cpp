#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define M 998244353
#define ll long long int 
#define maxn 6000020
using namespace std;


ll inv[maxn], res[maxn];
void init(){
	inv[1] = 1;
	srep(i, 2, maxn) inv[i] = M - M / i * inv[M % i] % M;
	srep(i, 1, maxn) res[i] = (res[i - 1] + inv[i] * inv[i] % M) % M; 
}

int main(){
	init();
	int T, x; scanf("%d", &T);
	rep(i, 1, T) {
		scanf("%d", &x);
		printf("%lld\n", res[x] * inv[x] % M * 3 % M);
	}
	return 0;
}

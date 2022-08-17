#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 2000020
#define M 998244353
#define mo(x) (x = (x >= M) ? (x - M) : x)
using namespace std;

int power(int x, int y) {
	int ans = 1, con = x;
	while (y) {
		if (y & 1) ans = 1ll * ans * con % M;
		con = 1ll * con * con % M;
		y >>= 1;
	}
	return ans;
}
int getinv(int x) {
	return power(x, M - 2);
}

int n, m, a[maxn];
int g[maxn], f[maxn];
void init(){
	g[1] = M - (n - 1);
	srep(i, 1, m) g[i + 1] = (1ll * i * (n - 1) % M * g[i] % M + M - 1ll * m * (n - 1) % M) * getinv(m - i) % M;
	f[m] = 0;
	int suf = 0;
	per(i, m - 1, 0) {
		suf += g[i + 1], mo(suf);
		f[i] = M - suf;
	}
}
void cal() {
	init();
	int res = 0;
	rep(i, 1, n) res += f[a[i]], mo(res); 
	res += M - 1ll * (n - 1) * f[0] % M, mo(res);
	printf("%d\n", 1ll * res * getinv(n) % M);
}
 
int main(){
	scanf("%d", &n); rep(i, 1, n) scanf("%d", a + i), m += a[i];
	cal(); 
	return 0;
}

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
#define maxn 200020
#define maxm
#define ull unsigned long long int 
using namespace std;

int p[maxn], facc[maxn], son[maxn], cp = 0;
bool vis[maxn];
void init(){
	srep(i, 2, maxn) {
		if (!vis[i]) p[++cp] = i, son[i] = cp; 
		rep(j, 1, cp) {
			if (i * p[j] >= maxn) break;
			vis[i * p[j]] = 1;
			son[i * p[j]] = j;
			if (i % p[j] == 0) break;
		}
	}
	facc[0] = 1;
	srep(i, 1, maxn) facc[i] = facc[i - 1] * i;
}
int getphi(int x){
	int res = 1;
	while (x > 1) {
		int s = son[x]; x /= p[s];
		res *= (p[s] - 1);
		while (x > 1 && son[x] == s) {
			res *= p[s];
			x /= p[s];
		}
	}
	return res;
}

ull _M; int b, P; __int128 M, inf = (__int128)1 << 64;

//18446744073709551616 

int power(int x, int y){
	int ans = 1, con = x;
	while (y){
		if (y & 1) ans = 1ll * ans * con % P;
		con = 1ll * con * con % P;
		y >>= 1;
	}
	return ans;
}

int main(){
	init();
	int T; scanf("%d", &T);
	rep(TT, 1, T){
		printf("Case #%d: ", TT);
		scanf("%d%d%llu", &b, &P, &_M);
		M = _M; __int128 res = 0;
		if (P == 1) {
			res = M + 1;
			if (res == inf) printf("18446744073709551616\n");
			else printf("%llu\n", (ull)res);
		}
		else {
			int phiP = getphi(P), fac = 1; bool f = 0;
			srep(n, 0, phiP) {
				if (n > M) break;
				if (!f && facc[n] < phiP) {
					if (power(n, fac) == b) res++;
				}
				else {
					f = 1;
					if (power(n, fac + phiP) == b) res++;
				}
				fac = 1ll * fac * (n + 1) % phiP;
			}
			
			int now = phiP;
			srep(i, 0, P) {
				if (power(now + i, phiP) == b && now + i <= M){
					res += (M - now - i) / P + 1;
				}
			}
			
			if (res == inf) printf("18446744073709551616\n");
			else printf("%llu\n", (ull)res);
		}
	}
	return 0;
}

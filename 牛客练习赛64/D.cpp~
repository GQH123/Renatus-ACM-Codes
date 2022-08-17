#include <bits/stdc++.h>
#define maxn 8020
#define maxm
#define maxb
#define maxr 200000
#define maxs 
#define pii pair<int, int>
#define pdd pair<double, double>
#define uint unsigned int
#define ull unsigned long long int
#define ll long long int 
#define lowbit(x) x & -x
#define fi first
#define se second
#define pb push_back
#define next NEXT
#define hash HASH
#define ls ch[x][0]
#define rs ch[x][1]
#define pi 3.141592653589793
#define ei 2.718281828459045
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define M 998244353
//#define ONLINE_JUDGE
//#define DEBUG
using namespace std;

char *p1, *p2, buffer[maxr];
template <class T> void read(T& x){
    char ch = gc(); x = 0; bool f = 1;
    while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
    if (ch == '-') f = 0, ch = gc();
    while ('0' <= ch && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = gc();
    x = f ? x : -x;
}

ll fac[maxn], ifac[maxn], inv[maxn];
void init(){
	fac[0] = ifac[0] = inv[1] = 1;
	srep(i, 1, maxn) fac[i] = fac[i - 1] * i % M;
	srep(i, 2, maxn) inv[i] = M - M / i * inv[M % i] % M;
	srep(i, 1, maxn) ifac[i] = ifac[i - 1] * inv[i] % M;
}
ll get(int m, int n){
	if (m < n) return 0;
	return fac[m] * ifac[m - n] % M * ifac[n] % M;
}

int n, a[maxn], num[maxn];

ll dp[2][maxn];
int DP(){
	int d = 0;
	dp[0][0] = 1;
	rep(i, 1, n){
		d ^= 1;
		dp[d][0] = 1;
		rep(j, 1, i){
			dp[d][j] = (dp[d ^ 1][j - 1] * num[i] % M + dp[d ^ 1][j]) % M;
		}
	}
	return d;
}


int main(){ 
	init();
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", a + i), num[a[i]]++;
	int ct = 0;
	rep(i, 1, n) if (num[i]) ct++; 
	ll ans = fac[n];
	int d = -1;
	int k = DP();
	rep(i, 1, ct){
		if (d == -1){
			ans = (ans + M - dp[k][i] * fac[n - i] % M) % M;
		}
		else {
			ans = (ans + dp[k][i] * fac[n - i] % M) % M;
		}
		d = -d;
	}
	printf("%lld", ans);
    return 0;
}

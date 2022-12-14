#include <bits/stdc++.h>
#define maxr 100000
#define maxn 600019
#define maxp 10
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define ll long long int 
#define M 998244353
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') ch = gc(), f = 0;
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}

ll n, m, k;
ll fac[maxn], ifac[maxn], inv[maxn];
void init(){
	fac[0] = ifac[0] = inv[1] = 1;
	srep(i, 1, maxn) fac[i] = fac[i - 1] * i % M;
	srep(i, 2, maxn) inv[i] = M - M / i * inv[M % i] % M;
	srep(i, 1, maxn) ifac[i] = ifac[i - 1] * inv[i] % M;
}

ll E[10];
ll dp[maxp][maxn];
bool vis[maxp][maxn];
int ct = 0;
ll DP(int nowp, int rest){
	if (!rest) return 1;
	if (!nowp) return 0;
	if (vis[nowp][rest] == ct) return dp[nowp][rest];
	vis[nowp][rest] = ct;
	ll& ans = dp[nowp][rest];
	ans = 0;
	ans += DP(nowp - 1, rest);
	ans += E[nowp] * DP(nowp, rest - 1) % M, ans %= M;
	/*rep(i, 0, rest){
		ans += now * now  xz   % M * ifac[i] % M * ifac[i] % M * DP(nowp - 1, rest - i) % M, ans %= M;
		now = now * E[nowp] % M;
	}*/
	return ans;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("B.in", "r", stdin);
	#endif
	init();
	read(n), read(m), read(k);
	ll A, B, C;
	if ((n & 1) && (m & 1)) A = ((n >> 1) * (m >> 1)), C = 1, B = (n >> 1) + (m >> 1);
	else if ((n & 1) || (m & 1)) A = ((n >> 1) * (m >> 1)), C = 0, B = ((n & 1) ? (m >> 1) : (n >> 1));
	else A = (n >> 1) * (m >> 1), B = C = 0;
	ll Ck1 = k, Ck2 = k * (k - 1) % M * inv[2] % M, Ck3 = k * (k - 1) % M * (k - 2) % M * inv[6] % M, Ck4 = k * (k - 1) % M * (k - 2) % M * (k - 3) % M * inv[24] % M;
	ll ans = 1;
	int mxpos;
	if (A){
		//E[1] = Ck1, E[2] = Ck2 * 4 % M, E[3] = Ck2 * 6 % M, E[4] = Ck2 * 4 % M, E[5] = Ck3 * 12 % M, E[6] = Ck3 * 12 % M, E[7] = Ck3 * 12 % M, E[8] = Ck4 * 24 % M;
		E[1] = Ck1, E[2] = Ck2 * 16 % M, E[3] = Ck2 * 36 % M, E[4] = Ck2 * 16 % M, E[5] = Ck3 * 144 % M, E[6] = Ck3 * 144 % M, E[7] = Ck3 * 144 % M, E[8] = Ck4 * 576 % M;
		ct++;
		//ans = ans * A % M * A % M;
		if (k == 1) mxpos = 1;
		else if (k == 2) mxpos = 4;
		else if (k == 3) mxpos = 7;
		else mxpos = 8;
		ll ans1 = DP(mxpos, A);
		ans = ans * ans1 % M;
	}
	if (B){
		//E[1] = Ck1, E[2] = Ck2 * 2 % M;
		E[1] = Ck1, E[2] = Ck2 * 4 % M;
		ct++;
		//ans = ans * B % M * B % M;
		if (k == 1) mxpos = 1;
		else mxpos = 2;
		ll ans2 = DP(mxpos, B);
		ans = ans * ans2 % M;
	}
	if (C){
		E[1] = Ck1;
		ct++;
		mxpos = 1;
		ll ans3 = DP(mxpos, C);
		ans = ans * ans3 % M;
	}
	printf("%lld", ans);
	return 0;
}

#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 400200
#define ll long long int 
#define M 1000000007
#define mo(x) (x = (x >= M) ? (x - M) : x)
using namespace std;  

int ufs[maxn];
int n, p[maxn];
int find_root(int x){
	return ufs[x] = (ufs[x] == x) ? x : find_root(ufs[x]);
}

ll fac[maxn], ifac[maxn], inv[maxn];
void init(){
	fac[0] = ifac[0] = inv[1] = 1;
	srep(i, 1, maxn) fac[i] = fac[i - 1] * i % M;
	srep(i, 2, maxn) inv[i] = M - M / i * inv[i] % M;
	srep(i, 1, maxn) ifac[i] = ifac[i - 1] * inv[i] % M;
}
ll get(int m, int n){
	if (m < n) return 0;
	return fac[m] * ifac[n] % M * ifac[m - n] % M;
}

int DP(int rest){
	if (!rest) return 0;
	if (vis[rest]) return dp[rest];
	vis[rest] = 1;
	int& ans = dp[rest];
	rep(i, 1, rest){
		ans += get(rest - 1, i - 1) * (n - rest) % M * fac[i] % M * DP(rest - i) % M;
		mo(ans);
	}
	rep(i, 2, rest){
		ans += get(rest - 1, i - 1) * fac[i - 1] % M * (DP(rest - i) + 1) % M;
		mo(ans);
	} 
	return ans;
}

int main(){ 	
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", p + i);
	
	rep(i, 1, n) ufs[i] = i, siz[i] = 1;
	rep(i, 1, n) {
		if (p[i] != -1){
			int x = find_root(i), y = find_root(p[i]);
			if (x != y) ufs[x] = y, siz[y] += siz[x];
		}
	}
	int have = 0, rest = 0;
	rep(i, 1, n) {
		if (p[i] != -1 && ufs[i] == i) have++;
		if (p[i] == -1) rest++;
	}
	int d = DP(rest);
	ll eff = 1;
	rep(i, 1, rest) eff = eff * (n - 1) % M;
	ll ans = (n - have) * eff % M;
	
	d = d + fac[n - 1
	
	/*
	int res = 0;
	rep(j, have, have + rest / 2){
		int out = j - have;
		if (rest < (out << 1)) break;
		ll ans = 1;
		ans = get(rest, out << 1);
		rep(i, 1, out) ans = ans * get((out << 1) - 2 * (i - 1), 2) % M;
		ans = ans * ifac[out] % M;
		int _rest = rest - (out << 1);
		int now = n - _rest;
		rep(i, 1, _rest){
			ans = ans * (n - _rest
		}
	}
	*/
	return 0;
}

#include <bits/stdc++.h>
#define maxr 100000
#define maxn 605
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define M 998244353
#define ll long long int 
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}

int n, m;
int a[maxn];
bool vis[maxn][maxn];
int dp[maxn][maxn];
/*bool vis2[maxn][maxn];
int sum[maxn][maxn];
int getsum(int l, int r){
	if (vis2[l][r]) return sum[l][r];
	vis2[l][r] = 1;
	int& ans = sum[l][r];
	rep(i, l - 1, r)  ans += (ll)DP(l, i) * DP(i + 1, r) % M, ans %= M;
	return ans;
}*/
int DP(int l, int r){
	if (l >= r) return 1;
	if (vis[l][r]) return dp[l][r];
	vis[l][r] = 1;
	int& ans = dp[l][r];
	int mi = n + 1, mip = -1;
	rep(i, l, r) if (mi > a[i]) mi = a[i], mip = i;
	int le = 0, ri = 0;
	srep(i, l - 1, mip) le += (ll)DP(l, i) * DP(i + 1, mip - 1) % M, le %= M;
	sper(i, r + 1, mip) ri += (ll)DP(i, r) * DP(mip + 1, i - 1) % M, ri %= M;
	return ans = (ll)le * ri % M;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("F.in", "r", stdin);
    #endif
    read(n), read(m);
    rep(i, 1, n) read(a[i]);
   	printf("%d", DP(1, n));
    return 0;
}

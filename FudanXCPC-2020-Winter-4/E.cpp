#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define maxr 100000
#define maxn 1000
#define maxm
#define maxv 10020
#define M
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}

int T, n;
int a[maxn];
int dp[maxn][maxv];
bool vis[maxn][maxv];
int DP(int pos, int have){
	if (pos > n) return have;
	if (vis[pos][have]) return dp[pos][have];
	vis[pos][have] = 1;
	int& ans = dp[pos][have];
	if (have + a[pos] <= T) ans = max(ans, DP(pos + 1, have + a[pos]));
	ans = max(ans, DP(pos + 1, have));
	return ans;
}

int ans = 0;
int out[maxn];
int cs = 0;
void Find(int pos, int have){
	if (pos > n) return;
	if (have + a[pos] <= T && DP(pos + 1, have + a[pos]) == ans) out[++cs] = a[pos], Find(pos + 1, have + a[pos]);
	else Find(pos + 1, have);
}

void recover(){
	ans = cs = 0;
	rep(i, 0, n) rep(j, 0, T) dp[i][j] = vis[i][j] = 0;
}


int main(){
	
		#ifndef ONLINE_JUDGE
			freopen("E.in", "r", stdin);
		#endif
	
	while (1){
		recover();
		scanf("%d", &T);
		if (!T) return 0;
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]);
		ans = DP(1, 0);
		Find(1, 0);
		rep(i, 1, cs) printf("%d ", out[i]);
		printf("%d\n", ans);
	}
	return 0;
}

#include <bits/stdc++.h>
#define maxr 100000
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define mo(x) x = (x >= M) ? (x - M) : x;
#define M 1000000007
#define ll long long int 
#define maxn 3019
#define pb push_back
#define DEBUG(x) { \
printf("%s: ", #x); rep(i, 1, n) printf("%d ", x[i]); printf("\n"); \
} 
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}

int C[maxn][maxn];
void init(){
	C[0][0] = 1;
	srep(m, 1, maxn) {C[m][0] = 1; srep(n, 1, maxn) C[m][n] = C[m - 1][n - 1] + C[m - 1][n], mo(C[m][n]); }
}
int n, k, a[maxn];
int sz[maxn];
int DFS(int x){
	if (x > n) return 0;
	sz[x] = 1;
	int mi = (x - 1) * k + 2, mx = x * k + 1;
	rep(i, mi, mx) sz[x] += DFS(i);
	return sz[x];
}
int dp[maxn];
bool vis[maxn];
int DP(int x){
	if ((x - 1) * k + 2 > n) return dp[x] = 1;
	if (vis[x]) return dp[x];
	vis[x] = 1;
	int& ans = dp[x];
	ans = 1;
	int mi = (x - 1) * k + 2, mx = x * k + 1;
	rep(i, mi, min(n, mx)) ans = (ll)ans * DP(i) % M;
	int rest = sz[x] - 1;
	rep(i, mi, min(n, mx)){
		ans = (ll)ans * C[rest][sz[i]] % M;
		rest -= sz[i];
	}
	return ans;
}
int inline fa(int x){
	if (x == 1) return 0;
	return (x - 2) / k + 1;
}
//int now[maxn]; //0 未加入，1 正在运算，2 成为历史
vector<int> now[maxn];
int coss[maxn];
void recover(){
	rep(i, 1, n) vis[i] = 0, dp[i] = coss[i] = 0;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("K.in", "r", stdin);
	#endif
	init();
	int T;
	read(T);
	rep(TT, 1, T){
		printf("Case #%d: ", TT);
		read(n), read(k);
		rep(i, 1, n) read(a[i]);
		DFS(1), DP(1);
		//DEBUG(sz); DEBUG(dp);
		int tot = dp[1], _rank = 0, ans = 1;
		int l = 1, r = 1, cost;
		while (1){
			if (l > n) break;
			rep(i, l, r){
				ans = 1;
				rep(j, l, i - 1) now[a[j]].pb(j);
				rep(j, i + 1, r) now[a[fa(j)]].pb(j);
				now[max(a[i], a[fa(i)])].pb(i);
				cost = 0;
				per(j, n, 1){
					int szz = now[j].size() - 1;
					rep(k, 0, szz){
						int x = now[j][k];
						if (x >= i) {
							if (n - j < cost) {ans = 0; goto jump;}
							ans = (ll)ans * C[n - j - cost][sz[x]] % M, cost += sz[x];
						}
						else {
							if (n - j < cost) {ans = 0; goto jump;}
							ans = (ll)ans * C[n - j - cost][sz[x] - 1] % M, cost += sz[x] - 1;
						}
					}
					cost += coss[j];
				}
				if (ans) rep(j, l, r) ans = (ll)ans * dp[j] % M;
				jump: _rank += ans, mo(_rank);
				rep(j, 1, n) now[j].clear();
				coss[a[i]] = 1;
			}
			l = (l - 1) * k + 2;
			r = (l - 1) * k + 1, r = min(r, n);
		}
		printf("%d\n", (M + tot - _rank) % M);
		recover();
	}
	return 0;
}

#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 3020
using namespace std;

const int inf = 2000000020;

int n, f[maxn], m[maxn];

int dp[maxn][maxn][2][2];
bool vis[maxn][maxn][2][2];
int DP(int pos, int rst, bool opf, bool opm){
	if (pos == n + 1){
		if (!opf || !opm) return inf;
		return 0;
	}
	if (f[pos] == 0 && m[pos] == 0) return DP(pos + 1, rst, opf, opm);
	if (vis[pos][rst][opf][opm]) return dp[pos][rst][opf][opm];
	int& ans = dp[pos][rst][opf][opm];
	vis[pos][rst][opf][opm] = 1;
	ans = inf;
	if (rst) {
		int _m = max(0, m[pos] - rst);
		if (rst > 1) ans = min(ans, DP(pos + 1, max(0, rst - m[pos]), opf | 1, opm | 1) + min(rst, m[pos]) + min(f[pos] + _m - 1, 2 * _m));
		else {
			ans = min(ans, DP(pos + 1, max(0, rst - m[pos]), opf, opm | 1) + min(rst, m[pos]) + f[pos] + _m - 1);
			ans = ans = min(ans, DP(pos + 1, max(0, rst - m[pos]), opf | 1, opm | 1) + min(rst, m[pos]) + 2 * _m);
			ans = min(ans, DP(pos + 1, max(0, rst - m[pos]), opf | 1, opm) + min(rst, m[pos]) + 2 * _m);
			ans = min(ans, DP(pos + 1, max(0, rst - m[pos]), opf | 1, opm | 1) + min(rst, m[pos]) + f[pos] + _m - 1);
		}
	}
	ans = min(ans, DP(pos + 1, rst, opf, opm | 1) + f[pos] + m[pos] - 1); 
	ans = min(ans, DP(pos + 1, rst, opf | 1, opm) + 2 * m[pos]);
	return ans;
}


int main(){

		//freopen("E.in", "r", stdin);	
		
	scanf("%d", &n);
	int ept = 0;
	bool have_ = 0;
	rep(i, 1, n){
		scanf("%d%d", &m[i], &f[i]);
		if (m[i] == 0 && f[i] == 0) ept++;
		if (m[i] != 0) have_ = 1;
	}
	if (!have_) {printf("0"); return 0;}
	//if (ept) printf("%d", min(DP(1, ept - 1, 1, 0), DP(1, ept, 0, 0)));
	printf("%d", DP(1, ept, 0, 0));
	return 0;
}

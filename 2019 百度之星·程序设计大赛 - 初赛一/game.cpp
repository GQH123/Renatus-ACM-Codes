#include <bits/stdc++.h>
#define maxn 1019
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
using namespace std;

int n;
inline int trans(int d){
	if (d & 1) {
		return d / 2 + 1;
	}
	else {
		return d / 2;
	}
}

int l[maxn], r[maxn];
int lis[maxn << 2], cs = 0;
int pos[maxn][4];

int dp[maxn << 2][maxn];
bool vis[maxn << 2][maxn];
int DP(int p, int id){
	if (id == n) return 0;
	if (vis[p][id]) return dp[p][id];
	vis[p][id] = 1;
	int& ans = dp[p][id];
	if (pos[id + 1][0] <= p && p <= pos[id + 1][3]) return ans = DP(p, id + 1);
	if (l[id + 1] == r[id + 1]) return ans = DP(pos[id + 1][0], id + 1) + trans(abs(l[id + 1] - lis[p]));
	int next;
	next = pos[id + 1][0];
	ans = DP(next, id + 1) + trans(abs(lis[next] - lis[p]));
	next = pos[id + 1][1];
	ans = min(ans, DP(next, id + 1) + trans(abs(lis[next] - lis[p])));
	next = pos[id + 1][2];
	ans = min(ans, DP(next, id + 1) + trans(abs(lis[next] - lis[p])));
	next = pos[id + 1][3];
	ans = min(ans, DP(next, id + 1) + trans(abs(lis[next] - lis[p])));
	return ans;
}

inline void recover(){
	rep(i, 0, cs) rep(j, 0, n) dp[i][j] = vis[i][j] = 0;
	cs = 0;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("game.in", "r", stdin);
	#endif
	int T;
	scanf("%d", &T);
	while (T--){
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d%d", &l[i], &r[i]);
		rep(i, 1, n) {
			lis[++cs] = l[i], lis[++cs] = l[i] + 1, lis[++cs] = r[i] - 1, lis[++cs] = r[i];
		}
		sort(lis + 1, lis + 1 + cs);
		cs = unique(lis + 1, lis + 1 + cs) - lis - 1;
		rep(i, 1, n){
			pos[i][0] = lower_bound(lis + 1, lis + 1 + cs, l[i]) - lis;
			pos[i][1] = lower_bound(lis + 1, lis + 1 + cs, l[i] + 1) - lis;
			pos[i][2] = lower_bound(lis + 1, lis + 1 + cs, r[i] - 1) - lis;
			pos[i][3] = lower_bound(lis + 1, lis + 1 + cs, r[i]) - lis;
		}
		if (l[1] == r[1]){
			printf("%d\n", DP(pos[1][0], 1));
		}
		else {
			printf("%d\n", min(min(DP(pos[1][0], 1), DP(pos[1][1], 1)), min(DP(pos[1][2], 1), DP(pos[1][3], 1))));
		}
		recover();
	}
	return 0;
}

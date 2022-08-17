#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 5020
#define pii pair<int, int>
#define fi first
#define se second
#define maxm 3020
using namespace std;

const int inf = 2000000020;

int n, m;

int f0[maxm], f1[maxm];
int d[maxm << 2];
bool vis[maxm << 2];
priority_queue<pii> pq;
void Dij(){
	rep(i, 1, 2 * m + 1) d[i] = inf;
	pq.push(pii(0, m + 1));
	while (!pq.empty()) {
		pii op = pq.top(); pq.pop();
		if (vis[op.se]) continue;
		int x = op.se;
		d[x] = -op.fi;
		vis[x] = 1;
		rep(i, -m, m){
			if (x + i < 1 || x + i > 2 * m + 1 || vis[x + i]) continue;
			assert(i != 0);
			int dd = d[x] + ((i > 0) ? f1[i] : f0[-i]);
			if (d[x + i] > dd){
				d[x + i] = dd;
				pq.push(pii(-dd, x + i));
			}
		}
	}
}
int dp[maxn][2];
void DP(){
	int offset = m + 1;
	rep(l, 2, n){
		dp[l][0] = dp[l][1] = inf;
		srep(jump, 1, min(l, m + 1)){
			dp[l][0] = min(dp[l][0], d[jump + offset] + max(dp[jump][1], dp[l - jump][0]));
			dp[l][1] = min(dp[l][1], d[-jump + offset] + max(dp[jump][0], dp[l - jump][1]));
		}
	}
}

int main(){
	freopen("D.in", "r", stdin);
	scanf("%d%d", &n, &m);
	rep(i, 1, m) scanf("%d", &f1[i]);
	rep(i, 1, m) scanf("%d", &f0[i]);
	Dij();
	//rep(i, 1, 2 * m + 1) printf("%d ", d[i]);
	//return 0;
	DP();
	printf("%d", dp[n][0]);
	return 0;
}

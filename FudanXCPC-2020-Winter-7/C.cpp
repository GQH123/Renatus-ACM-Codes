#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int
#define maxn 600020
#define maxm 
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back

using namespace std;

const int inf = 2000000020;

int n;
int a[maxn];
ll g[25][25];
int num[25];
bool vis[1 << 20];
ll dp[1 << 20];

bool vis2[20][1 << 20];
ll nnum[20][1 << 20];
ll Num(int pos, int op){
	if (!op) return 0;
	if (vis2[pos][op]) return nnum[pos][op];
	ll& ans = nnum[pos][op];
	vis2[pos][op] = 1;
	int nex = (op - 1) & op;
	if (!nex) {
		rep(i, 0, 19) {
			if (op & (1 << i)) return ans = g[pos][i];
		}
	}
	return ans = Num(pos, op - nex) + Num(pos, nex);
}
int bound = 0;
ll DP(int op){
	if (op == bound) return 0;
	if (vis[op]) return dp[op];
	vis[op] = 1;
	ll& ans = dp[op];
	ans = -1;
	rep(i, 0, 19){
		if (!num[i]) continue;
		if (!(op & (1 << i))) {
			ans = (ans != -1) ? min(ans, DP(op | (1 << i)) + Num(i, op)) : (DP(op | (1 << i)) + Num(i, op));
		}
	}
	return ans;
}

int main(){
	freopen("C.in", "r", stdin);
	scanf("%d", &n);
	rep(i, 1, n) {
		scanf("%d", &a[i]), a[i]--;
		rep(j, 0, 19) g[j][a[i]] += num[j];
		num[a[i]]++;
	}
	rep(i, 0, 19) if (num[i]) bound |= (1 << i);  
	printf("%lld", DP(0));
	return 0;
}


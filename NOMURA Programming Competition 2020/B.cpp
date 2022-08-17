#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 400200
using namespace std;

char T[maxn]; int n;
bool vis[maxn][2];
int dp[maxn][2];
int DP(int pos, bool op){
	if (pos > n) return 0;
	if (vis[pos][op]) return dp[pos][op];
	vis[pos][op] = 1;
	int& ans = dp[pos][op];
	if (T[pos] == 'D') return ans = DP(pos + 1, 0) + 1 + ((op == 1) ? 1 : 0);
	if (T[pos] == 'P') return ans = DP(pos + 1, 1);
	return ans = max(DP(pos + 1, 0) + 1 + ((op == 1) ? 1 : 0), DP(pos + 1, 1));
}

void find_ans(int pos, bool op){	
	if (pos > n) return; 
	int ans = dp[pos][op];
	if (T[pos] == 'D') {find_ans(pos + 1, 0); return;}
	if (T[pos] == 'P') {find_ans(pos + 1, 1); return;}
	if (ans == DP(pos + 1, 0) + 1 + ((op == 1) ? 1 : 0)) {T[pos] = 'D', find_ans(pos + 1, 0); return;}
	T[pos] = 'P', find_ans(pos + 1, 1); return; 
}

int main(){
	scanf("%s", T + 1);
	n = strlen(T + 1);
	DP(1, 0);
	find_ans(1, 0);
	printf("%s", T + 1);
	return 0;
}

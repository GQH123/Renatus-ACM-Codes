#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
#define maxn 
#define maxm
#define M 1000000007
#define mo(x) (x = (x >= M) ? (x - M) : x)
using namespace std;

namespace DP_I{
	int dp[maxn][3][3];
	int vis[maxn][3][3];
	int DP(int pos, int sta, int num){ // 1 = R, 0 = G
		if (pos > n) {
			if (sta == 1) return num == 2;
			else return 1;
		}
		if (vis[pos][sta][num] == tim) return dp[pos][sta][num];
		vis[pos][sta][num] = 1;
		int& ans = dp[pos][sta][num]; ans = 0;
		if (sta == 2){ //G
			if (s[pos] == 'R') return ans = 0;
			else return ans = DP(pos + 1, 2, 0);
		}
		if (sta == 1){ //R
			if (s[pos] == 'R') return ans = DP(pos + 1, 1, min(2, num + 1));
			else if (s[pos] == 'G') {
				if (num != 2) return 0;
				else return ans = DP(pos + 1, 2, 0);
			}
			else {
				if (num != 2){
					return ans = DP(pos + 1, 1, min(2, num + 1));
				}
				else {
					ans = DP(pos + 1, 1, 2) + DP(pos + 1, 2, 0), mo(ans);
					return ans;
				} 
			}
		}
		if (sta == 0) { //G
			if (s[pos] == 'R') return ans = DP(pos + 1, 1, 1);
			else if (s[pos] == 'G') return ans = DP(pos + 1, 0, 0);
			else {ans = DP(pos + 1, 1, 1) + DP(pos + 1, 0, 0), mo(ans); return ans;}
		}
	}
}

namespace DP_II{
	int len = 0;
	int dp[maxn][maxn][3];
	int vis[maxn][maxn][3];
	int DP(int pos, int st, int sta) {
		if (vis[pos][st][sta] == tim) return dp[pos][st][sta];
		vis[pos][st][sta] = tim;
		int& ans = dp[pos][st][sta];
		ans = 0;
		if (!sta) {	
			if (s[pos] == 'R') return ans = DP(pos + 1, pos, 1);
			else if (s[pos] == 'G') return ans = DP(pos + 1, 0, 0);
			else {
				ans = DP(pos + 1, 0, 0) + DP(
			}
		}
	}
}

int main(){
	int T; scanf("%d", &T);
	while (T--){
		scanf("%s", s + 1);
		n = strlen(s + 1);
		
	}
	return 0;
}

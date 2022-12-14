#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
#define maxn 120
#define maxl 12
using namespace std;

const int inf = 2000000020;

int n, k, t;
int co[maxn][maxn];
int dp[maxn][maxn][maxl][3];
int vis[maxn][maxn][maxl][3];
int idx = 0;
int DP(int pos, int c, int l, int f){
    if (pos == n) return 0;
    if (vis[pos][c][l][f] == idx) return dp[pos][c][l][f];
    vis[pos][c][l][f] = idx;
    int& ans = dp[pos][c][l][f]; ans = inf;
    if (f == 0) {
        if (!pos) {
            srep(i, 0, k) ans = min(ans, DP(pos + 1, i, 0, 0) + co[pos][i]);
            srep(i, 0, k) ans = min(ans, DP(pos + 1, i, 1, 1) + co[pos][i]);
        }
        else {
            srep(i, 0, k) {if (i == c) continue; ans = min(ans, DP(pos + 1, i, 0, 0) + co[pos][i]);}
            srep(i, 0, k) {if (i == c) continue; ans = min(ans, DP(pos + 1, i, 1, 1) + co[pos][i]);}
        }
    }
    else if (f == 1){
        srep(i, 0, k) {if (i == c) continue; ans = min(ans, DP(pos + 1, i, 0, 2) + co[pos][i]);} 
        if (l < t) ans = min(ans, DP(pos + 1, c, l + 1, 1) + co[pos][c]);
    }
    else {
        srep(i, 0, k) {if (i == c) continue; ans = min(ans, DP(pos + 1, i, 0, 2) + co[pos][i]);} 
    }
    return ans;
}

class Solution {
public:
    /**
     * @param costs: costs of paint ith house into color j
     * @param t: maximum length of street
     * @return: minimum costs of painting all houses
     */
    int paintHouseIII(vector<vector<int>> &costs, int tt) {
        // Write your code here.
        t = tt, idx++, n = costs.size(), k = costs[0].size();
        srep(i, 0, n) srep(j, 0, k) co[i][j] = costs[i][j];
        return DP(0, 0, 0, 0);
    }
};


int main(){

	return 0;
}

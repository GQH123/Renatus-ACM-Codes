#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, r, l) for (int i = r; i >= l; i--)
#define srep(i, l, r) for (int i = l; i < r; i++)
#define sper(i, r, l) for (int i = r; i > l; i--)
#define ll long long int 
#define maxn 55
#define maxt 505
#define inf 200000000
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;

struct ele{
    char s[20];
    bool operator < (const ele b) const{
        return strcmp(s, b.s) < 0;
    }
};

map<ele, int> cid;

int vec[maxn][101];

int n, m;

vector<pii> mat[maxn];

int dp[4][maxn][maxt], vis[4][maxn][maxt], idx = 0;
int DP(int pos, int t, int p) {
    if (pos == n + 1) return 0;
    if (vis[p][pos][t] == idx) return dp[p][pos][t];
    vis[p][pos][t] = idx;
    int& ans = dp[p][pos][t];
    ans = -inf;
    if (p) {
        rep(i, 0, 59) {
            if (t < vec[pos][i]) break;
            ans = max(ans, DP(pos + 1, t - vec[pos][i], p - 1) + i);
        }
    }
    rep(i, 60, 100) {
        if (t < vec[pos][i]) break;
        ans = max(ans, DP(pos + 1, t - vec[pos][i], p) + i);
    }
    return ans;
}

void work(){
    idx++;
    scanf("%d", &n);
    rep(i, 1, n) {
        ele op; scanf("%s", op.s);
        cid[op] = i;
    }
    scanf("%d", &m);
    int s, d;
    rep(i, 1, m) {
        ele op;
        scanf("%s%d%d", op.s, &s, &d);
        mat[cid[op]].pb(pii(s, d));
    }
    
    rep(i, 1, n) {
        vec[i][0] = 0; rep(j, 1, 100) vec[i][j] = inf;
        for (auto it: mat[i]){
            per(j, 100, it.fi) 
                vec[i][j] = min(vec[i][j], vec[i][j - it.fi] + it.se);
        }
        per(j, 99, 0) vec[i][j] = min(vec[i][j], vec[i][j + 1]);
    }
    
    int t, p;
    scanf("%d%d", &t, &p);
    int rs = DP(1, t, p);
    printf("%d\n", rs < 0 ? -1 : rs);
    
    rep(i, 1, n) mat[i].clear();
    cid.clear();
}


int main(){
    int T; scanf("%d", &T); 
    while (T--) work();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int MAXN = 5005;
int N, a[MAXN], c[MAXN];
vector<int> G[MAXN];
bool vis[MAXN];
int color[MAXN], b[MAXN];
bool f[MAXN];
using namespace std;
int Hungary(int u) {
    for(int v : G[u]) if(!vis[v]) {
        vis[v] = 1;
        if(!c[v] || Hungary(c[v])) {
            c[v] = u;
            c[u] = v;
            return 1;
        }
    }
    return 0;
}
void dfs(int u) {
    vis[u] = 1;
    for(int v : G[u]) if(!vis[v]) {
        color[v] = color[u] ^ 1;
        dfs(v);
    }
}
bool cov[MAXN];
void mark(int u) {
    cov[u] = 1;
    for(int v : G[u]) if(!cov[v]) {
        cov[v] = 1;
        if(c[v]) mark(c[v]);
    }
}
int main() {
    cin >> N;
    for(int i = 1; i <= N; ++ i) {
        scanf("%d", a + i);
        for(int j = 1; j < i; ++ j) if(__builtin_popcount(a[i] ^ a[j]) == 1) {
            G[i].push_back(j);
            G[j].push_back(i);
        }
    }
    int ans = 0;
    for(int i = 1; i <= N; ++ i) if(!vis[i]) dfs(i);
    for(int i = 1; i <= N; ++ i) if(color[i])
    {
        memset(vis, 0, sizeof vis);
        ans += Hungary(i);
    }
    cout << N - ans << endl;
    for(int i = 1; i <= N; ++ i) if(color[i] && !c[i]) mark(i);
    for(int i = 1; i <= N; ++ i) if(color[i]) cov[i] = !cov[i];
    for(int i = 1; i <= N; ++ i) if(!cov[i]) b[++ b[0]] = a[i];
    for(int i = 1; i <= b[0]; ++ i)
        printf("%d%c", b[i], (i == b[0] ? '\n' : ' '));
    return 0;
}

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
const int MAXN = 1e5 + 5;
using namespace std;
int n, m;
vector<int> G[MAXN];
int dis[2][22][MAXN];
int sa[22], sb[22];
void BFS(int S, int *d) {
    static int q[MAXN], l, r;
    static bool vis[MAXN];
    for(int i = 1; i <= n; ++ i) vis[i] = 0;
    l = r = 1; q[1] = S;
    d[S] = 0; vis[S] = 1;
    while(l <= r) {
        int u = q[l ++];
        for(int v : G[u]) if(!vis[v]) {
            q[++ r] = v;
            d[v] = d[u] + 1;
            vis[v] = 1;
        }
    }
}
long long work(int *DA, int *DB) {
    static int D[MAXN], C[MAXN * 2];
    static int Q1[MAXN], Q2[MAXN], l1, r1, l2, r2;
    l1 = l2 = 1; r1 = n; r2 = 0;
    int C0 = 0;
    for(int i = 1; i <= n; ++ i) {
        D[i] = DA[i] + DB[i];
        C0 = max(C0, D[i]);
    }
    for(int i = 0; i <= C0; ++ i) C[i] = 0;
    for(int i = 1; i <= n; ++ i)
        ++ C[D[i]];
    for(int i = 1; i <= C0; ++ i)
        C[i] += C[i-1];
    for(int i = 1; i <= n; ++ i)
        Q1[C[D[i]] --] = i;
    while((l1 <= r1) || (l2 <= r2)) {
        int u;
        if((l1 > r1)) u = Q2[l2 ++];
        else if(l2 > r2) u = Q1[l1 ++];
        else {
            if(D[Q1[l1]] <= D[Q2[l2]])
                u = Q1[l1 ++];
            else u = Q2[l2 ++];
        }
        for(int v : G[u])
            if(D[v] > D[u] + 1) {
                D[v] = D[u] + 1;
                Q2[++ r2] = v;
            }
    }
    long long ans = 0;
    for(int i = 1; i <= n; ++ i)
        ans += D[i];
    return ans;
}
int main() {
    int T; cin >> T;
    for(int Cas = 1; Cas <= T; ++ Cas) {
        cin >> n >> m;
        int u, v;
        for(int i = 1; i <= n; ++ i) G[i].clear();
        for(int i = 1; i <= m; ++ i) {
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        for(int i = 0; i <= sa[0]; ++ i) {
            scanf("%d", sa + i);
            if(i) BFS(sa[i], dis[0][i]);
        }
        for(int i = 0; i <= sb[0]; ++ i) {
            scanf("%d", sb + i);
            if(i) BFS(sb[i], dis[1][i]);
        }
        long long fz = 0, fm = 0;
        for(int i = 1; i <= sa[0]; ++ i)
            for(int j = 1; j <= sb[0]; ++ j) {
                fz += work(dis[0][i], dis[1][j]);
                fm += n;
            }
        long long GCD = __gcd(fz, fm);
        fz /= GCD; fm /= GCD;
        printf("Case #%d: %lld/%lld\n", Cas, fz, fm);
    }
    return 0;
}

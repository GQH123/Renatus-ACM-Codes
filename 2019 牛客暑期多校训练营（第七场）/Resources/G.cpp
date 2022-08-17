#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
#define x first
#define y second
#define mp make_pair
#define PII pair<int, int>
vector<int> G[MAXN];
vector<pair<int, PII> > vec, V[MAXN];
int n, m, W[MAXN], X[MAXN], K[MAXN], P[MAXN], ans[MAXN];
int fa[MAXN], htp[MAXN], hsn[MAXN], dep[MAXN], sz[MAXN];
int dfn[MAXN], ed[MAXN], rdfn[MAXN], dcnt;
void dfs(int u) {
    sz[u] = 1;
    for(int v : G[u]) if(!sz[v]) {
        dep[v] = dep[u] + 1;
        fa[v] = u; dfs(v);
        sz[u] += sz[v];
        if(sz[v] > sz[hsn[u]]) hsn[u] = v;
    }
}
void dfs2(int u, int tp) {
    dfn[u] = ++ dcnt;
    rdfn[dcnt] = u;
    htp[u] = tp;
    if(hsn[u]) dfs2(hsn[u], tp);
    for(int v : G[u]) if(!dfn[v])
        dfs2(v, v);
    ed[u] = dcnt;
}
void load2(int u, int tp) {
    vec.push_back(mp(u - W[tp], mp(tp, u)));
    for(int v : G[u]) if(v != fa[u]) load2(v, tp);
}
void load(int u) {
    vec.push_back(mp(u - W[u], mp(u, u)));
    for(int v : G[u]) if(v != fa[u] && v != hsn[u]) load2(v, u);
    for(int v : G[u]) if(v != fa[u]) load(v);
}
#define MID ((l + r) >> 1)
int mx[MAXN << 2];
void Ins(int i, int l, int r, int p, int v) {
    mx[i] = max(mx[i], v);
    if(l == r) return;
    if(p <= MID) Ins(i << 1, l, MID, p, v);
    else Ins(i << 1 | 1, MID + 1, r, p, v);
}
int Qmx(int i, int l, int r, int L, int R) {
    if(l > R || L > r) return 0;
    if(L <= l && r <= R) return mx[i];
    return max(Qmx(i << 1, l, MID, L, R),
        Qmx(i << 1 | 1, MID + 1, r, L, R));
}
void add(int ansid, int l, int r, int v) {
    if(v < 1 || l > r) return;
    if(v > n) v = n;
    V[v].push_back(mp(ansid, mp(l, r)));
}
void Query(int ansid, int K, int X) {
    add(ansid, dfn[X], ed[X], K + W[X]);
    while(X) {
        ans[ansid] = max(ans[ansid], Qmx(1, 1, n, dfn[htp[X]], dfn[X] - 1));    //minus 1 to avoid using vertex from the same subtree
        int Y = htp[X];
        X = fa[Y];
        if(!X) break;
        add(ansid, dfn[X], dfn[Y] - 1, K + W[X]);
        add(ansid, ed[Y] + 1, ed[X], K + W[X]);
    }
}
int main() {
    cin >> n >> m;
    int u, v;
    for(int i = 1; i <= n; ++ i)
        scanf("%d", W + i);
    for(int i = 1; i < n; ++ i) {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i = 1; i <= m; ++ i) {
        scanf("%d%d", X + i, K + i);
        P[i] = i;
    }
    sort(P + 1, P + m + 1, [](int a, int b){
        return K[a] < K[b];
    });
 
    dfs(1);
    dfs2(1, 1);
    load(1);
    sort(vec.begin(), vec.end());
 
    int p = 0;
    for(int i = 1; i <= m; ++ i) {
        while(p < (int)vec.size() && vec[p].x <= K[P[i]])
            Ins(1, 1, n, dfn[vec[p].y.x], vec[p].y.y), ++ p;
        Query(P[i], K[P[i]], X[P[i]]);
    }
    for(int i = n * 4; i; -- i) mx[i] = 0;
    for(int i = 1; i <= n; ++ i) {
        Ins(1, 1, n, dfn[i], i);
        for(auto u : V[i])
            ans[u.x] = max(ans[u.x], Qmx(1, 1, n, u.y.x, u.y.y));
    }
    for(int i = 1; i <= m; ++ i)
        printf("%d\n", ans[i]);
    return 0;
}

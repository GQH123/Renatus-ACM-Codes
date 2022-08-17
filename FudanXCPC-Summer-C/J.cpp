#include <bits/stdc++.h>
using namespace std;

const int MX = 100005;

int n, q;
int V[MX];
vector<int> G[MX];

struct Trie {
    struct Node {
        int son[2];
        int siz;
    } P[MX * 40];

    int ro[MX], cnt;

    void init(int len) {
        for(int i = 1; i <= len; i++) ro[i] = 0;
        cnt = 0;
    }

    void ins(int pre, int &o, int x, int d) {
        if(!o) o = ++cnt;
        P[o] = P[pre], P[o].siz++;
        if(d >= 0) {
            int b = (x >> d) & 1;
            ins(P[pre].son[b], P[o].son[b], x, d-1);
        }
    }

    int ask(int pre, int cur, int x, int d) {
        int b = (x>>d) & 1;
        int c = P[P[cur].son[b^1]].siz > P[P[pre].son[b^1]].siz;
        if(d) return (c<<d) | ask(P[pre].son[b^1], P[cur].son[b^1], x, d-1);
        else return c;
    }
} t;

void ade(int u, int v) {
    G[u].push_back(v);
    G[v].push_back(u);
}

int IN[MX], OUT[MX], idx, id[MX];
void dfs(int x, int fr) {
    IN[x] = ++idx;
    id[IN[x]] = x;
    for(int v : G[x]) 
        if(v != fr) dfs(v, x);
    OUT[x] = idx;
}

int main() {
    while(~scanf("%d%d", &n, &q)) {
        t.init(n);
        for(int i = 1; i <= n; i++) 
            scanf("%d", &V[i]);
        for(int i = 2; i <= n; i++) {
            int f; scanf("%d", &f);
            ade(i, f);
        }

        dfs(1, 0);
        for(int i = 1; i <= n; i++) 
            t.ins(t.ro[i-1], t.ro[i], V[id[i]], 30);

        for(int i = 1; i <= q; i++) {
            int u, x;
            scanf("%d%d", &u, &x);
            printf("%d\n", t.ask(t.ro[IN[u]-1],t.ro[OUT[u]],x,30));
        }
    }
}

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 27;
const int MAXS = 1 << 27;
int n, m, ans;
int G[MAXN];
char f[1 << 27];
int main() {
    cin >> n >> m;
    int u, v;
    for(int i = 1; i <= m; ++ i) {
        scanf("%d%d", &u, &v);
        G[u] |= (1 << v);
        G[v] |= (1 << u);
    }
    for(int S = 1; S < (1 << n); ++ S) {
        int p = S & -S; u = __builtin_ctz(p);
        f[S] = max((int)f[S ^ p], f[S ^ p ^ (G[u] & S)] + 1);
        ans += f[S];
        //printf("%x\t:\t%d\n", S, f[S]);
    }
    cout << ans << endl;
    return 0;
}

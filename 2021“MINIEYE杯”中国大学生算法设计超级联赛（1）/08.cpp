#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, r, l) for (int i = r; i >= l; i--)
#define srep(i, l, r) for (int i = l; i < r; i++)
#define sper(i, r, l) for (int i = r; i > l; i--)
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
#define maxn 3021
using namespace std;

int n, m, a[maxn][maxn];
int v[maxn][maxn];

int ufs[maxn], siz[maxn];

int find_root(int x) {
    return ufs[x] = (ufs[x] == x) ? x : find_root(ufs[x]);
}
void merge(int x, int y) {
    x = find_root(x), y = find_root(y);
    if (x == y) return;
    ufs[x] = y;
    siz[y] += siz[x];
}

pii lis[maxn];
bool vis[maxn];

void work(){
    scanf("%d%d", &n, &m);
    rep(i, 1, n) rep(j, 1, m) scanf("%d", &a[i][j]);
    per(i, n, 1) per(j, m, 1) {
        if (i == n) v[i][j] = 1;
        else {
            v[i][j] = a[i][j] <= a[i + 1][j] ? v[i + 1][j] + 1 : 1;
        }
    }
    ll ans = 0;
    per(i, n, 1) {
        rep(j, 1, m) ufs[j] = j, siz[j] = 1;
        rep(j, 1, m) lis[j] = pii(v[i][j], j);
        rep(j, 1, m) vis[j] = 0;
        sort(lis + 1, lis + 1 + m);
        per(j, m, 1){
            int x = lis[j].se;
            vis[x] = 1;
            if (x - 1 >= 1 && vis[x - 1]) {
                merge(x, x - 1);
            }
            if (x + 1 <= m && vis[x + 1]) {
                merge(x, x + 1);
            }
            x = find_root(x);
            ans = max(ans, 1ll * lis[j].fi * siz[x]);
        }
    }
    printf("%lld\n", ans);
}

int main(){    
    int T; scanf("%d", &T);
    while (T--){
        work();
    }
    return 0;
}

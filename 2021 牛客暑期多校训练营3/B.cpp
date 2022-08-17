#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, r, l) for (int i = r; i >= l; i--)
#define srep(i, l, r) for (int i = l; i < r; i++)
#define sper(i, r, l) for (int i = r; i > l; i--)
#define ll long long int
#define maxn 5021
using namespace std;
 
int ufs[maxn << 1];
int find_root(int x) {
    return ufs[x] = ufs[x] == x ? x : find_root(ufs[x]);
}
 
int cnt;
bool merge(int x, int y) {
    x = find_root(x), y = find_root(y);
    if (x == y) return false;
    ufs[x] = y;
    cnt--;
    return true;
}
 
struct ele{
    int x, y, v;
    ele(int x, int y, int v) : x(x), y(y), v(v){}
    ele(){}
    bool operator < (const ele b) const{
        return v < b.v;
    }
}a[maxn * maxn];
 
int main(){
    int n, m, aa, b, c, d, p;
    cin >> n >> m >> aa >> b >> c >> d >> p;
    a[0].v = aa;
    rep(i, 1, m * n) {
        a[i].v = (1ll * a[i - 1].v * a[i - 1].v * b + 1ll * a[i - 1].v * c + d) % p;
        a[i].x = (i - 1) / m + 1;
        a[i].y = (i - 1) % m + 1;
    }
    sort(a + 1, a + 1 + n * m);
    rep(i, 1, n + m) ufs[i] = i;
     
    int ans = 0; cnt = n + m;
    rep(i, 1, m * n) {
        if (cnt == 1) break;
        int x = a[i].x;
        int y = a[i].y;
        if (merge(x, n + y)) ans += a[i].v;
    }
    printf("%d\n", ans);
    return 0;
}

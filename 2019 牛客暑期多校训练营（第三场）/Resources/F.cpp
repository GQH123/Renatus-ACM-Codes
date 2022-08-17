#include <bits/stdc++.h>
#define maxn 525
#define maxr 100000
#define ll long long int
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;
int inf;
char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
    char ch = gc(); x = 0; bool f = 1;
    while (ch != '-' && !('0' <= ch && ch <= '9')) ch = gc();
    if (ch == '-') f = 0, ch = gc();
    while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
    x = (f) ? x : -x;
}
void chkmax(int& x, int y){
    x = (x > y) ? x : y;
}
void chkmin(int& x, int y){
    x = (x < y) ? x : y;
}
int n, m;
int a[maxn][maxn];
int mxq[maxn], hx, tx, miq[maxn], hi, ti;
int mx[maxn], mi[maxn];
 
int main(){
    inf = 1000000000;
    #ifndef ONLINE_JUDGE
        freopen("F.in", "r", stdin);
    #endif
    int T;
    read(T);
    while (T--){
        read(n), read(m);
        rep(i, 1, n) rep(j, 1, n) read(a[i][j]);
        int ans = 0;
        rep(i, 1, n) {
            rep(k, 1, n) mx[k] = -inf, mi[k] = inf;
            rep(j, i, n){
                rep(k, 1, n) chkmax(mx[k], a[j][k]), chkmin(mi[k], a[j][k]);
                hx = 0, tx = 1, hi = 0, ti = 1;
                int now = 0;
                while ((hx < tx || hi < ti || (mxq[tx] - miq[ti] <= m)) && now <= n){
                    ++now;
                    if (now == n + 1) break;
                    while (hx >= tx && mxq[hx] < mx[now]) hx--; mxq[++hx] = mx[now];
                    while (hi >= ti && miq[hi] > mi[now]) hi--; miq[++hi] = mi[now];
                }
                chkmax(ans, (now - 1) * (j - i + 1));
                rep(k, 2, n){
                    if (mxq[tx] == mx[k - 1]) tx++;
                    if (miq[ti] == mi[k - 1]) ti++;
                    while ((hx < tx || hi < ti || (mxq[tx] - miq[ti] <= m)) && now <= n){
                        ++now;
                        if (now == n + 1) break;
                        while (hx >= tx && mxq[hx] < mx[now]) hx--; mxq[++hx] = mx[now];
                        while (hi >= ti && miq[hi] > mi[now]) hi--; miq[++hi] = mi[now];
                    }
                    chkmax(ans, (now - k) * (j - i + 1));
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

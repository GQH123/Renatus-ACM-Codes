#include <bits/stdc++.h>
#define maxr 100005
#define maxn 3015
#define ll long long int
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define M 998244353
#define mo(x) x = (x >= M) ? (x - M) : x
using namespace std;
 
char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
    char ch = gc(); x = 0; bool f = 1;
    while (ch != '-' && !('0' <= ch && ch <= '9')) ch = gc();
    if (ch == '-') f = 0, ch = gc();
    while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
    x = (f) ? x : -x;
}
 
int C[maxn][maxn];
int suf[maxn][maxn];
void init(){
    C[0][0] = 1; srep(m, 1, maxn) C[0][m] = 0;
    srep(n, 1, maxn){
        C[n][0] = 1;
        srep(m, 1, maxn) C[n][m] = (C[n - 1][m - 1] + C[n - 1][m]) % M;
    }
     
    srep(n, 0, maxn - 2) per(m, n, 0) suf[n][m] = (suf[n][m + 1] + C[n][m]) % M;
}
 
int n, m;
char a[maxn], b[maxn];
 
int lis[maxn];
int cs = 0;
 
int dp[maxn][maxn];
bool vis[maxn][maxn];
int DP(int pn, int pm){
    if (pm == m + 1 || pn == n + 1) return 0;
    if (vis[pn][pm]) return dp[pn][pm];
    vis[pn][pm] = 1;
    int& ans = dp[pn][pm];
    ans = DP(pn + 1, pm);
    if (a[pn] > b[pm]){
        ans += C[n - pn][m - pm], mo(ans);
    }
    else if (a[pn] == b[pm]){
        ans += DP(pn + 1, pm + 1), mo(ans);
    }
    return ans;
}
 
int main(){
    #ifndef ONLINE_JUDGE
        freopen("G.in", "r", stdin);
    #endif
    int T;
    scanf("%d", &T);
    init();
    while (T--){
        scanf("%d%d", &n, &m);
        scanf("%s", a + 1);
        rep(i, 1, n) a[i] -= '0';
        scanf("%s", b + 1);
        rep(i, 1, m) b[i] -= '0';
        int len = m - 1;
        int ans = 0;
        rep(i, 1, n) if (a[i]) ans += suf[n - i][m], mo(ans);
        ans += DP(1, 1);
        mo(ans);
        /*int now = 1;
        cs = 0;
        rep(i, 1, n){
            if (a[i] > b[now]) ans += C[n - i][m - now], mo(ans);
            else if (a[i] == b[now]) lis[++cs] = i;
        }
        now++;
        while (now <= m && cs){
            int _cs = 0;
            rep(i, 1, cs){
                int x = lis[i];
                if (x + 1 > n) continue;
                if (a[x + 1] > b[now]){
                    ans += C[n - x - 1][m - now], mo(ans);
                }
                else if (a[x + 1] == b[now]) lis[++_cs] = x + 1;
            }
            cs = _cs, now++;
        }*/
        printf("%d\n", ans);
        rep(i, 1, n) rep(j, 1, m) vis[i][j] = dp[i][j] = 0;
    }
    return 0;
}

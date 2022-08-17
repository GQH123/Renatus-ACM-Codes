#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define maxn 100105
#define maxr 100000
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;
 
char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
    char ch = gc(); x = 0; bool f = 1;
    while (ch != '-' && !('0' <= ch && ch <= '9')) ch = gc();
    if (ch == '-') f = 0, ch = gc();
    while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
    x = (f) ? x : -x;
}
int n;
int a[maxn];
int b[maxn];
bool dp[maxn][3][3];
bool vis[maxn][3][3];
int tem[3];
bool DP(int x, int op1, int op2){
    if (x == n) return true;
    if (vis[x][op1][op2]) return dp[x][op1][op2];
    vis[x][op1][op2] = 1;
    bool& ans = dp[x][op1][op2];
    rep(i, 0, min(2, n - x)) {
        tem[0] = b[x - 1 - (2 - op1)];
        tem[1] = b[x - (2 - op2)];
        tem[2] = b[x + 1 - (2 - i)];
        sort(tem, tem + 3);
        if (tem[1] == b[x - 1] && DP(x + 1, op2, i)) {
            a[x + 1] = b[x + 1 - (2 - i)];
            return ans = true;
        }
    }
    return ans = false;
}
 
int main(){
    #ifndef ONLINE_JUDGE
        freopen("I.in", "r", stdin);
    #endif
    int T;
    read(T);
    while (T--){
        read(n);
        rep(i, 1, n - 2) read(b[i]);
        if (n == 3){
            rep(i, 1, 3) printf("%d ", b[1]); printf("\n");
            continue;
        }
        rep(i, 1, 2) {
            if (DP(2, 2, i)) {
                a[1] = b[1], a[2] = b[2 - (2 - i)];
                rep(i, 1, n) printf("%d ", a[i]); printf("\n");
                goto jump;
            }
        }
        printf("-1"); printf("\n");
        jump:;
        rep(i, 1, n) rep(j, 0, 2) rep(k, 0, 2) dp[i][j][k] = vis[i][j][k] = 0;
    }
    return 0;
}

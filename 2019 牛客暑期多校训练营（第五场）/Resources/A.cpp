#include <bits/stdc++.h>
#define maxn 105
#define maxp 10000
#define maxr 100005
#define ll long long int
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
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
 
int main(){
    #ifndef ONLINE_JUDGE
        freopen("A.in", "r", stdin);
    #endif
    int T;
    read(T);
    while (T--){
        read(n);
        /*ten[0] = 1;
        rep(i, 1, 9999) ten[i] = ten[i - 1] * 10 % n;
        if (DP(9999, 0)){
            bool f = 0;
            per(i, 9999, 0){
                if (!f && !ans[i]) continue;
                f = 1;
                printf("%d", ans[i]);
            }
        }
        per(i, 0, 9999) {
            if (DP(i, 0)){
                bool f = 0;
                per(j, i, 0){
                    if (!f && !ans[j]) continue;
                    f = 1;
                    printf("%d", ans[j]);
                }
                goto jump;
            }
        }
        printf("Impossible");
        jump:rep(i, 0, 9999) rep(j, 0, n - 1) dp[i][j] = vis[i][j] = 0;
        printf("\n");*/
        int s = 0, _n = n;
        while (n){
            s++;
            n /= 10;
        }
        n = _n;
        int k;
        if (s == 1){
            printf("%d\n", n);
        }
        else if (s == 2){
            rep(i, 1, n){
                printf("%d", n);
            }
            printf("\n");
        }
        else {
            rep(i, 1, 100) printf("1");
            printf("00");
            printf("\n");
        }
    }
    return 0;
}

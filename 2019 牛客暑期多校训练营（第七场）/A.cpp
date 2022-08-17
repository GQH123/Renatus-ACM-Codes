#include <bits/stdc++.h>
#define maxr 100000
#define maxn 315
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;
 
char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
    char ch = gc(); x = 0; bool f = 1;
    while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
    if (ch == '-') ch = gc(), f = 0;
    while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3), ch = gc();
}
int n;
char s[maxn];
 
int minrep(char* s, int n){
    int i = 0, j = 1;
    while (i < n && j < n){
        int k = 0;
        while (k < n && s[(i + k) % n] == s[(j + k) % n]) ++k;
        if (k >= n) break;
        if (s[(j + k) % n] < s[(i + k) % n])
            i = max(i + k + 1, j + 1);
        else
            j = max(i + 1, j + k + 1);
    }
    return min(i, j);
}
char t[maxn];
bool judge(int l, int r){
    rep(i, l, r) t[i - l] = s[i];
    int k = minrep(t, r - l + 1);
    return (k == 0);
}
int dp[maxn];
bool vis[maxn];
int DP(int x){
    if (x == n + 1) return 0;
    if (vis[x]) return dp[x];
    vis[x] = 1;
    int& ans = dp[x];
    ans = n;
    rep(i, x + 1, n + 1) if (judge(x, i - 1)) ans = min(ans, DP(i));
    return ans = ans + 1;
}
 
void DFS(int x){
    rep(i, x + 1, n + 1) {
        if (judge(x, i - 1) && DP(i) == DP(x) - 1) {
            rep(k, x, i - 1) printf("%c", s[k]); printf(" ");
            DFS(i);
            break;
        }
    }
}
 
int main(){
    #ifndef ONLINE_JUDGE
        freopen("A.in", "r", stdin);
    #endif
    int T;
    scanf("%d", &T);
    while (T--){
        scanf("%s", s + 1);
        n = strlen(s + 1);
        //printf("%d ", DP(1));
        DP(1), DFS(1);
        printf("\n");
        rep(i, 1, n) dp[i] = vis[i] = 0;
        /*int now = 1;
        while (now <= n && s[now] == '1') printf("%c", s[now]), now++;
        if (now != 1) printf(" ");
        int na = 0;
        rep(i, now, n){
            int op = s[i], _i = i;
            while (i <= n && s[i] == op) i++;
            a[++na] = i - _i;
            i--;
        }// start from 0
        rep(i, 1, na){
            if (i == na){
                rep(k, 1, a[i]) printf("0");
                printf(" ");
                break;
            }
            int now0 = a[i], now1 = a[i + 1];
            int _i = i + 2;
            while (_i + 1 <= na){
                if (a[_i] > now0 || (a[_i] == now0 && a[_i + 1] < now1)) break;
                _i += 2;
            }
            int d = 0;
            rep(k, i, _i - 1){
                rep(j, 1, a[k]) printf("%d", d);
                d ^= 1;
            }
            i = _i - 1;
            printf(" ");
        }
        printf("\n");*/
    }
    return 0;
}

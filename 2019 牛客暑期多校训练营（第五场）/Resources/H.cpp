#include <bits/stdc++.h>
#define maxr 100005
#define maxn 20015
#define ll long long int
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define END {printf("-1"); return 0;}
using namespace std;
 
char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
    char ch = gc(); x = 0; bool f = 1;
    while (ch != '-' && !('0' <= ch && ch <= '9')) ch = gc();
    if (ch == '-') f = 0, ch = gc();
    while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
    x = (f) ? x : -x;
}
int n, m;
char s[12][12][maxn];
int len[12][12];
int ptr[12][12];
bool mx[12];
char ans[maxn];
char nmd[5];
int qnm;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("H.in", "r", stdin);
    #endif
    scanf("%d%d", &n, &m);
    rep(i, 1, m){
        rep(j, i + 1, m){
            scanf("%s", nmd + 1);
            scanf("%d", &qnm);
            if (qnm){
                if (nmd[1] > nmd[2]) swap(nmd[1], nmd[2]);
                scanf("%s", s[nmd[1] - 'a' + 1][nmd[2] - 'a' + 1] + 1);
                len[nmd[1] - 'a' + 1][nmd[2] - 'a' + 1] = strlen(s[nmd[1] - 'a' + 1][nmd[2] - 'a' + 1] + 1);
            }
        }
    }
    rep(j, 1, m) rep(k, j + 1, m) ptr[j][k] = 1;
    rep(i, 1, n){
        rep(j, 1, m) mx[j] = 1;
        rep(j, 1, m){
            rep(k, j + 1, m){
                if (ptr[j][k] > len[j][k]) continue;
                if (s[j][k][ptr[j][k]] == 'a' + j - 1) mx[k] = 0;
                else mx[j] = 0;
            }
        }
        int ct = 0, mmx = 0;
        rep(j, 1, m) if (mx[j]) mmx = j, ct++;
        if (ct != 1) END
        ans[i] = mmx + 'a' - 1;
        rep(j, 1, m){
            rep(k, j + 1, m){
                if (s[j][k][ptr[j][k]] == 'a' + mmx - 1) ptr[j][k]++;
            }
        }
    }
    rep(j, 1, m) rep(k, j + 1, m) {
        if (ptr[j][k] != len[j][k] + 1) END
    }
    rep(i, 1, n) printf("%c", ans[i]);
    return 0;
}

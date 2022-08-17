#include <bits/stdc++.h>
#define maxr 100000
#define maxn 2019
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
    if (ch == '-') f = 0, ch = gc();
    while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
    x = (f) ? x : -x;
}
int n;
int mat[maxn][maxn];
int main(){
    #ifndef ONLINE_JUDGE
        freopen("E.in", "r", stdin);
    #endif
    int T;
    read(T);
    rep(TT, 1, T){ 
        printf("Case #%d: ", TT);
        read(n);
        if (n % 4 == 2 || n % 4 == 3) printf("No\n");
        else {
            rep(i, 1, n) rep(j, 1, n) mat[i][j] = 0;
            printf("Yes\n");
            if (n == 1){
                printf("0\n1\n");
                continue;
            }
            bool f = 0;
            if (n % 4) f = 1, n--;
            int sz = n >> 2;
            for (register int i = 1; i <= (n >> 1); i += sz){ 
                rep(j, i, i + sz - 1){
                    rep(l, i, i + sz - 1){
                        if (j != l) mat[j][l] = 1;
                    }
                }
            }
            //1 - 3 - 4 - 2
            rep(i, 1, sz){
                rep(j, 2 * sz + 1, 3 * sz){
                    mat[i][j] = mat[j][i] = 1;
                }
            }
            rep(i, 2 * sz + 1, 3 * sz){
                rep(j, 3 * sz + 1, 4 * sz){
                    mat[i][j] = mat[j][i] = 1;
                }
            }
            rep(i, 3 * sz + 1, 4 * sz){
                rep(j, sz + 1, 2 * sz){
                    mat[i][j] = mat[j][i] = 1;
                }
            }
            if (f){
                n++;
                rep(i, 1, 2 * sz) mat[n][i] = mat[i][n] = 1;
            }
            rep(i, 1, n) {rep(j, 1, n) printf("%d", mat[i][j]); printf("\n");}
            rep(i, 1, sz) printf("%d ", i + 2 * sz);
            rep(i, sz + 1, sz * 2) printf("%d ", i + 2 * sz);
            rep(i, 2 * sz + 1, 3 * sz) printf("%d ", i - sz);
            rep(i, 3 * sz + 1, 4 * sz - 1) printf("%d ", i - 3 * sz);
            if (f) printf("%d %d", n - 1 - 3 * sz, n);
            else printf("%d", n - 3 * sz);
            printf("\n");
        }
    }
    return 0;
}

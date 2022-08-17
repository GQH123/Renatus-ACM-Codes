#include <bits/stdc++.h>
#define maxr 100000
#define maxn 205
#define maxb
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
int m;
char s[maxn];
int t[maxn];
int main(){
    #ifndef ONLINE_JUDGE
        freopen("B.in", "r", stdin);
    #endif
    //printf("%d %d %d", ':', '0', 'a'); //58 48 97
    int T;
    scanf("%d", &T);
    rep(TT, 1, T) {
        printf("Case #%d: ", TT);
        m = 0;
        scanf("%s", s + 1);
        for (register int i = 1; i <= 128;){
            int x = 0;
            rep(j, i, i + 15) x = (x << 1) + s[j] - '0';
            t[++m] = x;
            i += 16;
        }
        //rep(i, 1, m) printf("%d ", t[i]); printf("\n");
        int mxlen = 0, mxlen2 = 0, mxp = 0;
        rep(i, 1, m){
            while (i <= m && t[i] != 0) i++;
            int now = 0, _i = i;
            while (i <= m && t[i] == 0) now++, i++; i--;
            if (now >= 2){
                int _now = now;
                if (_i == 1 || i == m) now = now + now - 2;
                else now = now + now - 1;
                if (now >= mxlen) mxlen = now, mxlen2 = _now, mxp = _i;
            }
        }
        rep(i, 1, m){
            if (i == mxp){
                printf(":");
                if (i == 1) printf(":");
                i += mxlen2 - 1;
            }
            else {
                char out[4]; int co = 0;
                if (t[i] == 0) out[co++] = '0';
                while (t[i]){
                    int k = t[i] % 16;
                    if (k > 9) out[co++] = k - 10 + 'a';
                    else out[co++] = '0' + k;
                    t[i] >>= 4;
                }
                per(j, co - 1, 0) printf("%c", out[j]);
                if (i != m) printf(":");
            }
        }
        printf("\n");
         
    }
    return 0;
}

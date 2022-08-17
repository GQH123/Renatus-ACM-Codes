#include <bits/stdc++.h>
#define maxn 400005
#define maxm 400005
#define maxb
#define maxr 200000
#define maxs
#define M 
#define pii pair<int, int>
#define pdd pair<double, double>
#define uint unsigned int
#define ull unsigned long long int
#define ll long long int 
#define lowbit(x) x & -x
#define fi first
#define se second
#define pb push_back
#define next NEXT
#define hash HASH
#define ls ch[x][0]
#define rs ch[x][1]
#define pi 3.141592653589793
#define ei 2.718281828459045
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define END return 0
//#define ONLINE_JUDGE
//#define DEBUG
using namespace std;

char *p1, *p2, buffer[maxr];
template <class T> void read(T& x){
    char ch = gc(); x = 0; bool f = 1;
    while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
    if (ch == '-') f = 0, ch = gc();
    while ('0' <= ch && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = gc();
    x = f ? x : -x;
}
int n;
pii out[maxn];
int ct = 0;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("C.in", "r", stdin);
    #endif
    read(n);
    if (n <= 2) {printf("No"); END;}
    int s = -1, __n = n;
    while (n) n >>= 1, s++; n = __n;
    if (n == (1 << s)) {printf("No"); END;}
    printf("Yes\n");
    out[++ct] = pii(1, 2);
    out[++ct] = pii(2, 3);
    out[++ct] = pii(3, n + 1);
    out[++ct] = pii(n + 1, n + 2);
    out[++ct] = pii(n + 2, n + 3);
    if (n & 1){
        for (register int i = 4; i <= n - 1; i += 2){
            out[++ct] = pii(i, i + 1);
            out[++ct] = pii(n + i, n + i + 1);
            out[++ct] = pii(i, 1);
            out[++ct] = pii(n + i + 1, n + 1);
        }
    }
    else {
        for (register int i = 4; i <= n - 1; i += 2){
            out[++ct] = pii(i, i + 1);
            out[++ct] = pii(n + i, n + i + 1);
            out[++ct] = pii(i, 1);
            out[++ct] = pii(n + i + 1, n + 1);
        }
        int s = 0, _n = n;
        while (n) n >>= 1, s++; s--;
        n = _n;
        if (n - (1 << s) == 2){
            out[++ct] = pii(n, n + 2); n ^= 3;
            out[++ct] = pii((_n << 1), n + _n);
        }
        else {
            out[++ct] = pii((1 << s), n); n ^= (1 << s); n ^= 1;
            out[++ct] = pii((_n << 1), n + _n);
        }
        
    }
    rep(i, 1, ct) printf("%d %d\n", out[i].fi, out[i].se);
    return 0;
}

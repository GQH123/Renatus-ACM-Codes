#include <bits/stdc++.h>
#define maxr 100000
#define maxn 30
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define ll long long int
using namespace std;
 
char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
    char ch = gc(); x = 0; bool f = 1;
    while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
    if (ch == '-') ch = gc(), f = 0;
    while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
    x = (f) ? x : -x;
}
 
ll a[maxn];
int main(){
    #ifndef ONLINE_JUDGE
        freopen("B.in", "r", stdin);
    #endif
    int T, n;
    read(T);
    while (T--){
        read(n);
        per(i, n, 0) read(a[i]);
        if ((n > 1) && (n & 1)) printf("No\n");
        else {
            if (n > 2) printf("No\n");
            else if (n == 1 || n == 0) printf("Yes\n");
            else {
                ll delta = a[1] * a[1] - 4 * a[0] * a[2];
                if (delta >= 0) printf("No\n");
                else printf("Yes\n");
            }
        }
    }
    return 0;
}

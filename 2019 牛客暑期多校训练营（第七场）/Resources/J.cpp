#include <bits/stdc++.h>
#define maxr 100000
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
    if (ch == '-') f = 0, ch = gc();
    while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
    x = (f) ? x : -x;
}
 
ll rev(ll x){
    ll ans = 0;
    while (x){
        ans *= 10;
        ans += x % 10;
        x /= 10;
    }
    return ans;
}
 
int main(){
    #ifndef ONLINE_JUDGE
        freopen("J.in", "r", stdin);
    #endif
    ll T, A, B;
    read(T);
    while (T--){
        read(A), read(B);
        printf("%lld\n", rev(rev(A) + rev(B)));
    }
    return 0;
}

#include <bits/stdc++.h>
#define maxr 100005
#define maxn 200105
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
ll c;
struct ele{ // -b / a
    ll a, b;
    ele(ll a, ll b) : a(a), b(b){}
    ele(){}
    bool operator < (const ele c) const{
        return b * c.a > a * c.b;
    }
    bool operator == (const ele c) const{
        return b * c.a == a * c.b;
    }
    bool operator > (const ele c) const{
        return b * c.a < a * c.b;
    }
}lis[maxn];

struct frac{ // a / b
    ll a, b;
    frac(ll a, ll b) : a(a), b(b){}
    frac(){}
    bool operator < (const frac c) const{
        return (b * c.b > 0) ? (a * c.b < b * c.a) : (a * c.b > b * c.a);
    }
    bool operator == (const frac c) const{
        return a * c.b == b * c.a;
    }
    bool operator > (const frac c) const{
        return (b * c.b > 0) ? (a * c.b > b * c.a) : (a * c.b < b * c.a);
    }
};

ll gcd(ll a, ll b){
    return (!b) ? a : gcd(b, a % b);
}

frac anss[5];
int cs = 0;

inline void recover(){
    cs = 0;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("D.in", "r", stdin);
    #endif
    int T;
    read(T);
    while (T--){
        read(n), read(c);
        rep(i, 1, n) read(lis[i].a), read(lis[i].b);
        sort(lis + 1, lis + 1 + n);
        ele op;
        ll SA = 0, SB = 0;
        rep(i, 1, n) SA -= lis[i].a, SB -= lis[i].b;
        frac nex = frac(-lis[1].b, lis[1].a), last;
        frac ans = frac(c - SB, SA);
        if (ans < nex || ans == nex) anss[++cs] = ans;
        rep(i, 1, n){
            last = frac(-lis[i].b, lis[i].a);
            op = lis[i];
            while (i <= n && lis[i] == op){
                SA += 2 * lis[i].a, SB += 2 * lis[i].b;
                i++;
            }
            if (SA == 0){
                if (SB == c){
                    printf("-1");
                    goto jump;
                }
                else {
                    i--;
                    continue;
                }
            }
            else  {
                ans = frac(c - SB, SA);
                if (i > n){
                    if (last < ans) anss[++cs] = ans;
                }
                else {
                    nex = frac(-lis[i].b, lis[i].a);
                    if (last < ans && (ans < nex || ans == nex)) anss[++cs] = ans;
                }
                i--;
                //if (ans < nex || ans == nex) anss[++cs] = ans;
            }
        }
        printf("%d", cs);
        rep(i, 1, cs){
            ll d = gcd(abs(anss[i].a), abs(anss[i].b));
            anss[i].a /= d, anss[i].b /= d;
            if (anss[i].a == 0) {
                printf(" 0/1");
            }
            else {
                if (anss[i].b < 0) {
                    anss[i].a = -anss[i].a;
                    anss[i].b = -anss[i].b;
                }
                printf(" %lld/%lld", anss[i].a, anss[i].b);
            }
        }
        jump:printf("\n");
        recover();
    }
    return 0;
}

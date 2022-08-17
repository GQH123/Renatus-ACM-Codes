#include <bits/stdc++.h>
#define maxr 100000
#define maxn 100019
#define maxc 205
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
 
int n;
struct tree{
    int h, c, n;
    tree(int h, int c, int n) : h(h), c(c), n(n){}
    tree(){}
    bool operator < (const tree b) const{   
        return h < b.h;
    }
}lis[maxn];
ll numc[maxc];
int main(){
    #ifndef ONLINE_JUDGE
        freopen("C.in", "r", stdin);
    #endif
    while (scanf("%d", &n) != EOF){
        srep(i, 1, maxc) numc[i] = 0;
        ll totc = 0;
        rep(i, 1, n) scanf("%d%d%d", &lis[i].h, &lis[i].c, &lis[i].n), totc += (ll)lis[i].c * lis[i].n;
        sort(lis + 1, lis + 1 + n);
        ll nowtot = 0, mi = totc;
        rep(i, 1, n){
            int nowh = lis[i].h, _i = i;
            ll nowhn = 0;
            while (i <= n && lis[i].h == nowh) {
                nowtot += lis[i].n;
                totc -= (ll)lis[i].n * lis[i].c;
                nowhn += lis[i].n;
                i++;
            }
            ll ans = totc, nowcn = 0, bound = 1 + nowtot - (nowhn << 1);
            if (bound > 0) {
                srep(c, 1, maxc){
                    if (nowcn + numc[c] > bound){
                        ans += (ll)(bound - nowcn) * c;
                        break;
                    }
                    else {
                        ans += (ll)c * numc[c];
                        nowcn += numc[c];
                    }
                }
            }
            mi = min(mi, ans);
            i = _i;
            while (i <= n && lis[i].h == nowh) numc[lis[i].c] += lis[i].n, i++;
            i--;
        }
        printf("%lld\n", mi);
    }
    return 0;
}

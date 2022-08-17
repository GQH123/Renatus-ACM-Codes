#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define maxn 3020
#define maxm 
#define M 
#define ll long long int 
#define ld long double
#define pb push_back
#define pc putchar
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define lowbit(x) (x & -x)
using namespace std;

int n, a[maxn], b[maxn], ran[maxn];
pii lis[maxn];
int main(){
    int T; scanf("%d", &T);
    while (T--){
        scanf("%d", &n);
        rep(i, 1, n) scanf("%d", a + i), lis[i] = pii(a[i], i);
        sort(lis + 1, lis + 1 + n);
        rep(i, 1, n) ran[lis[i].se] = i;
        rep(i, 1, n) scanf("%d", b + i); 
        int ans = 0;
        per(bound, n, 1){
            int res = 0; ll hav = 0;
            rep(i, 1, n){
                hav += b[i];
                if (hav >= a[i] && ran[i] <= bound) {    
                    res++, hav -= a[i];
                }
            }
            ans = max(ans, res);
        }
        printf("%d\n", ans);
    } 
    return 0;
}

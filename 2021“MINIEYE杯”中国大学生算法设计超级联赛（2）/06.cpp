#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, r, l) for (int i = r; i >= l; i--)
#define srep(i, l, r) for (int i = l; i < r; i++)
#define sper(i, r, l) for (int i = r; i > l; i--)
#define ll long long int 
#define M 1000000007
#define mo(x) (x = x >= M ? x - M : x)
#define maxn 1000021
using namespace std;

namespace Trans{
    int n, a[maxn], b[maxn];
    void trans(int* a, int s, int dft){
        //srep(i, 0, s) printf("%d ", a[i]); printf("\n");
        for (int st = 1; st < s; st *= 3) {
            for (int i = 0; i < s; i += 3 * st) {
                for (int j = i; j < i + st; j++) {
                    int x = a[j], y = a[j + st], z = a[j + st + st];
                    if (dft == 1) {
                        a[j] = x;
                        a[j + st] = x + y, mo(a[j + st]), a[j + st] += z, mo(a[j + st]);
                        a[j + st + st] = x + z, mo(a[j + st + st]);
                    }
                    else if (dft == -1){
                        a[j] = x;
                        a[j + st] = y + M - z, mo(a[j + st]);
                        a[j + st + st] = z + M - x, mo(a[j + st + st]);
                    }
                }
            }
        }
        //srep(i, 0, s) printf("%d ", a[i]); printf("\n");
    }
    int solve(int c){
        int s = 1, _n = n;
        while (n){
            s *= 3;
            n /= 3;
        }
        n = _n;
        srep(i, n, s) a[i] = b[i] = 0;
        trans(a, s, 1), trans(b, s, 1);
        srep(i, 0, s) a[i] = 1ll * a[i] * b[i] % M;
        trans(a, s, -1);
        
        int ans = 0, v = c;
        // s = min(s, bound + 1);
        srep(i, 1, s) {
            ans += 1ll * a[i] * v % M, mo(ans);
            v = 1ll * v * c % M;
        }
        return ans;
    }
}using namespace Trans;

int _a[maxn], _b[maxn], _c[maxn];
void work(){
    int n;
    scanf("%d", &n);
    rep(i, 1, n) scanf("%d", _a + i);
    rep(i, 1, n) scanf("%d", _b + i);
    rep(i, 1, n) scanf("%d", _c + i);
    int ans = 0;
    rep(i, 1, n) {
        Trans :: n = n / i + 1;
        a[0] = b[0] = 0; srep(j, 1, Trans :: n) a[j] = _a[j], b[j] = _b[j];
        
        ans += solve(_c[i]), mo(ans);
    }
    printf("%d\n", ans);
}

int main(){
    work();
    return 0;
}

#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define per(i, r, l) for (int i = r; i >= l; --i)
using namespace std;
typedef long long ll;
const int N = 2005;
const int mod = 1000000007;
const int inf = 1e9;
int T;
int n;
int a[N];
int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        rep(i, 1, n) { scanf("%d", &a[i]); }
        int cnt = 0;
        rep(i, 1, n) {
            rep(j, i + 1, n) {
                if (gcd(2 * a[i], a[j]) > 1 || gcd(a[i], 2 * a[j]) > 1) ++cnt;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int MAXN = 1006;
int n, m, c[MAXN][MAXN];
long long s[MAXN][MAXN], rmx[MAXN][MAXN];
int d[MAXN];
int main() {
    int T; cin >> T;
    for(int Cas = 1; Cas <= T; ++ Cas) {
        cin >> n >> m;
        for(int i = 1; i <= n; ++ i) {
            for(int j = 1; j <= m; ++ j) {
                scanf("%d", c[i] + j);
                c[i][j] = - c[i][j];
                s[i][j] = s[i][j-1] + c[i][j];
                rmx[i][j] = s[i][j];
            }
            for(int j = m - 1; j > 0; j --)
                rmx[i][j] = max(rmx[i][j], rmx[i][j + 1]);
        }
        for(int i = 1; i <= m; ++ i)
            scanf("%d", d + i);
        LL ans = 0, sum = 0;
        for(int j = 0; j <= m; ++ j) {
            sum += d[j];
            for(int i = 1; i <= n; ++ i)
                sum += c[i][j];
            LL tmp = 0;
            if(j < m) {
                bool flag = 0;
                for(int i = 1; i <= n; ++ i)
                    if(rmx[i][j + 1] - s[i][j] > 0)
                        tmp += rmx[i][j + 1] - s[i][j];
                    else flag = 1;
                if(!flag) {
                    LL mn = 1LL << 60;
                    for(int i = 1; i <= n; ++ i)
                        mn = min(mn, rmx[i][j + 1] - s[i][j]);
                    tmp -= mn;
                }
            }
            ans = max(ans, sum + tmp);
        }
        printf("Case #%d: %lld\n", Cas, ans);
    }
    return 0;
}

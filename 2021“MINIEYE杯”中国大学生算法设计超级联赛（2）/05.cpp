#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, r, l) for (int i = r; i >= l; i--)
#define srep(i, l, r) for (int i = l; i < r; i++)
#define sper(i, r, l) for (int i = r; i > l; i--)
#define ll long long int 
#define maxn 200020
#define M 1000000007
#define mo(x) (x = x >= M ? x - M : x)
using namespace std;


int n; char s[maxn];
char mi[maxn];
int main(){
    int T; scanf("%d", &T);
    while (T--){
        scanf("%d%s", &n, s + 1);
        /*
        mi[0] = 'z';
        rep(i, 1, n) mi[i] = min(mi[i - 1], s[i]); 
        per(i, n, 1){
            if (s[i] == mi[i]) 
        }
        */
        int ans = 1;
        rep(i, 1, n) {
            if (s[i] != s[1]) break;
            if (i == 1) ans *= 1;
            else ans *= 2, mo(ans);
        }
        printf("%d\n", ans);
    }
    return 0;
}

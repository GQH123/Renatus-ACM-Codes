#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 200020
using namespace std;

int a[maxn], pre[maxn], suf[maxn];
int main(){
    int n, q, x, y;
    scanf("%d%d", &n, &q);
    rep(i, 1, n) scanf("%d", a + i);
    pre[0] = n; pre[1] = a[1]; rep(i, 2, n) pre[i] = min(pre[i - 1], a[i]); 
    suf[n + 1] = n; suf[n] = a[n]; per(i, n - 1, 1) suf[i] = min(suf[i + 1], a[i]);
    rep(i, 1, q){
        scanf("%d%d", &x, &y);
        printf("%d\n", min(pre[x - 1], suf[y + 1]));
    }
	return 0;
}

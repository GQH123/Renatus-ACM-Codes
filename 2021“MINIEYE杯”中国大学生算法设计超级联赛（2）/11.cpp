#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, r, l) for (int i = r; i >= l; i--)
#define srep(i, l, r) for (int i = l; i < r; i++)
#define sper(i, r, l) for (int i = r; i > l; i--)
#define ll long long int 
#define M 998244353
#define maxn 1 << 21
#define mo(x) (x = x >= M ? x - M : x)
using namespace std;

void proc(int* v, int s, int dft = -1){
    int n = 1 << s;
    for (int st = 1; st < n; st <<= 1){
        for (int i = 0; i < n; i += (st << 1)){
            for (int j = i; j < i + st; j++) {
                if (dft == 1) v[j] = max(v[j], v[j + st]);
                else v[j] = min(v[j], v[j + st]);
            }
        }
    }
}

int n, a[maxn], b[maxn], mxa[maxn], mxb[maxn], mia[maxn], mib[maxn];

ll agg(int idx){
    return max(max(1ll * mxa[idx] * mxb[idx], 1ll * mia[idx] * mib[idx]), max(1ll * mxa[idx] * mib[idx], 1ll * mia[idx] * mxb[idx]));
}

void work(){
    scanf("%d", &n);
    srep(i, 0, n) scanf("%d", a + i), mxa[i] = mia[i] = a[i];
    srep(i, 0, n) scanf("%d", b + i), mxb[i] = mib[i] = b[i];
    int s = 0, _n = n;
    while (n) {
        n >>= 1;
        s++;
    }
    n = _n;
    
    srep(i, n, (1 << s)) mxa[i] = mxb[i] = -1000000020;
    srep(i, n, (1 << s)) mia[i] = mib[i] = 1000000020;
    proc(mxa, s, 1), proc(mxb, s, 1);
    proc(mia, s, -1), proc(mib, s, -1);
    
    int sum = 0; ll mx = agg(n - 1);
    
    per(i, n - 1, 0) { 
        mx = max(mx, agg(i));
        sum = (sum + M + mx % M) % M;
    }
    printf("%d\n", sum);
}
int main(){
    int T; scanf("%d", &T);
    while (T--) work();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int MX = 1000006;
const int MOD = 998244353;

int f[MX], g[MX], fac[MX], inv[MX], ifac[MX];

void sort(int &x, int &y, int &z) {
    if(x < y) swap(x,y);
    if(y < z) swap(y,z);
    if(x < y) swap(x,y);
    if(y < z) swap(y,z);
}

int C(int a, int b) { return b <= a ? 1ll * fac[a] * ifac[b] % MOD * ifac[a-b] % MOD : 0; }
int ab(int x) { return x > 0 ? x : -x; }

int FP(int a, int b) {
    int ans = 1, t = a;
    while(b) {
        if(b & 1) ans = 1ll * ans * t % MOD;
        t = 1ll * t * t % MOD;
        b >>= 1;
    }
    return ans;
}

int ptr;
pair<int,int> tmp[MX<<1];

int inv2[MX];

int main() {
    for(int i = 0; i <= 1000000; i++) {
        fac[i] = i <= 1 ? 1 : 1ll * fac[i-1] * i % MOD;
        inv[i] = i <= 1 ? i : MOD - 1ll * MOD / i * inv[MOD % i] % MOD;
        ifac[i] = i <= 1 ? 1 : 1ll * ifac[i-1] * inv[i] % MOD;
    }
    for(int i = 1; i <= 1000000; i+=3) {
        f[i] = (g[i-1] + 2) % MOD;
        g[i+2] = (f[i] + 2) % MOD;
    }
    int i2 = FP(2, MOD - 2);
    inv2[0] = 1; for(int i = 1; i <= 1000000; i++) { inv2[i] = 1ll * inv2[i - 1] * i2 % MOD; }

    int T; scanf("%d", &T); while(T--) {
        int x, y, z, n; scanf("%d%d%d", &x, &y, &z);
        n = x + y + z;
        if(n % 3) { puts("-1"); continue; }
        sort(x,y,z);
        int zz = z, ptr = 0;
        while(1) {
            int yy = min((n-zz+1) / 2, (n-2*zz));
            if(yy + 1 < y) break;
            if(zz <= n/3) 
                tmp[++ptr] = make_pair(zz, yy);
            else {    
                if(yy >= y) tmp[++ptr] = make_pair(zz, yy);
                tmp[++ptr] = make_pair(zz, yy+1);
            }
            zz++;
        }
        int tot = 0, ans = 0;
        for(int i = 1; i <= ptr ; i++) {
            int zz = tmp[i].first, yy = tmp[i].second, xx = n - zz - yy;
            int c;
            if(n - yy - zz != yy && n - yy - zz != zz) { // 不在直线上.
                if(zz <= n / 3) 
                    c = C(yy-y-1+zz-z, zz-z);
                else 
                    c = C(yy-y+zz-z-1, yy-y);
            } else c = C(yy-y+zz-z, yy-y);
            int d = yy-y+zz-z;
            sort(xx, yy, zz);
            if(xx - yy) ans = (ans + 1ll * c * inv2[d] % MOD * (d + f[ab(yy-zz)])) % MOD;
            else ans = (ans + 1ll * c * inv2[d] % MOD * (d + g[ab(yy-zz)])) % MOD;
        }
        //ans = 1ll * ans * FP(tot, MOD - 2) % MOD;
        printf("%d\n", ans);
    }
}
 

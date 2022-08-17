#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX = 200005;
const int M = 1000000007;

int fac[MX], inv[MX], ifc[MX];

int Comb(int n, int m) {
    if(m < 0 || m > n) return 0;
    return 1ll * fac[n] * ifc[m] % M * ifc[n-m] % M;
}

int main() {
    for(int i = 0; i < MX; i++) {
        fac[i] = i == 0 ? 1 : 1ll * i * fac[i-1] % M;
        inv[i] = i <= 1 ? i : M - 1ll * M/i * inv[M % i] % M;
        ifc[i] = i == 0 ? 1 : 1ll * inv[i] * ifc[i-1] % M;
    }
    int T; scanf("%d", &T); while(T--) {
        int A, B, C, K, c;
        scanf("%d%d%d%d%d", &A, &B, &C, &K, &c);
        printf("%d\n", 1ll * Comb(C, c) * ((Comb(A+B, K-c) - Comb(A, K-c) - Comb(B, K-c)) % M + M) % M);
    }
}

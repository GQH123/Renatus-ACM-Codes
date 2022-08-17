#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int bit[20], len, vis[20][2][1200], idx, k, bc[1200], upd[1200][10];
ll f[20][2][1200];

ll ask(int p, int d, int s) {
	if(vis[p][d][s] == idx) return f[p][d][s];
    if(bc[s] > k || bc[s] + p < k) return 0;
    if(p == 0) return bc[s] == k;
   
    
    vis[p][d][s] = idx, f[p][d][s] = 0;
     ll &cur = f[p][d][s];
    if(d) {
        for(int b = 0; b < bit[p-1]; b++)
            cur += ask(p-1, 0, upd[s][b]);
        cur += ask(p-1, 1, upd[s][bit[p-1]]);
    } else {
        for(int b = 0; b < 10; b++)
            cur += ask(p-1, 0, upd[s][b]);
    }
    return cur;
}
ll solve(ll x) {
    len = 0; while(x) bit[len++] = x % 10, x /= 10;
    return idx++, ask(len, 1, 0);
}

int main() {
    for(int i = 0; i < (1<<10); i++) bc[i] = bc[i>>1] + (i & 1);
    for(int s = 0; s < (1<<10); s++) 
        for(int b = 0; b < 10; b++) {
            int t = s;
            for(int i = b; i < 10; i++) 
                if(t >> i & 1) { t ^= 1 << i; break; }
            t ^= 1 << b;
            upd[s][b] = t;
        }
    int T; scanf("%d", &T); for(int cas = 1; cas <= T; cas++) {
        printf("Case #%d: ", cas);
        ll l, r;
        scanf("%lld%lld%d", &l, &r, &k);
        printf("%lld\n", solve(r) - solve(l-1));
    }
}

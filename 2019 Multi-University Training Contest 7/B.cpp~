#include <bits/stdc++.h>
#define maxn 300019
#define pb push_back
#define P 998244353
#define M 1000000009
#define M2 1000000007
#define ll long long int 
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define mo(x, y) x = (x >= y) ? (x - y) : x
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int fac[maxn], ifac[maxn], inv[maxn]; // mo 998244353
void init(){
    fac[0] = ifac[0] = inv[1] = 1;
    srep(i, 1, maxn) fac[i] = (ll)fac[i - 1] * i % P;
    srep(i, 2, maxn) inv[i] = P - P / i * (ll)inv[P % i] % P;
    srep(i, 1, maxn) ifac[i] = (ll)ifac[i - 1] * inv[i] % P;
}
ll power(int x, int y, int m){
    int ans = 1, con = x;
    while (y){
        if (y & 1) ans = (ll)ans * con % m;
        con = (ll)con * con % m;
        y >>= 1;
    }
    return ans;
}
int getinv(int x, int m){
    return power(x, m - 2, m);
}
ll getC(int m, int n, int k){
    if (m < n) return 0;
    return (ll)fac[m] * ifac[n] % k * ifac[m - n] % k;
}

int n;
vector<int> G[maxn];
int sz[maxn];
int siz[maxn];

void DFS(int x, int fa){    
    siz[x] = 1;
    srep(i, 0, sz[x]){
        int op = G[x][i];
        if (op == fa) continue;
        DFS(op, x);
        siz[x] += siz[op];
    }
}


set<pii> root;
map<pii, int> son[maxn];
map<pii, int> save;
int has[maxn], has2[maxn]; // hash of root
int dp[maxn];
bool cmp(int i, int j){
    return (siz[i] == siz[j]) ? ((has[i] == has[j]) ? has2[i] < has2[j] : has[i] < has[j]) : siz[i] < siz[j];
}
void Hash(int x, int fa){
    has[x] = has2[x] = 0;
    per(i, sz[x] - 1, 0){
        int op = G[x][i];
        if (op == fa) continue;
        Hash(op, x);
        //int k = has[op];
        //has[x] = (ll)has[x] * P % M + k, mo(has[x], M);
    }
    sort(G[x].begin(), G[x].end(), cmp);
    per(i, sz[x] - 1, 0){
        int op = G[x][i];
        if (op == fa) continue;
        int k = has[op];
        has[x] = (ll)has[x] * P % M + k, mo(has[x], M);
        int k2 = has2[op];
        has2[x] = (ll)has2[x] * P % M2 + k2, mo(has2[x], M2);
    }
    save.clear();
    srep(i, 0, sz[x]){
        int op = G[x][i];
        if (op == fa) continue;
        int k = has[op], k2 = has2[op];
        if (save.count(pii(k, k2))) save[pii(k, k2)]++;
        else save[pii(k, k2)] = 1;
    }
    has[x] = (ll)has[x] * P % M + 1, mo(has[x], M);
    has[x] = (ll)has[x] * siz[x] % M;
    has2[x] = (ll)has2[x] * P % M2 + 1, mo(has2[x], M2);
    has2[x] = (ll)has2[x] * siz[x] % M2;
    dp[x] = 1;
    int nowsz = (x == 1) ? sz[x] : (sz[x] - 1);
    srep(i, 0, sz[x]){
        int op = G[x][i];
        if (op == fa) continue;
        int k = has[op], k2 = has2[op];
        if (son[x].count(pii(k, k2))) son[x][pii(k, k2)]++;
        else son[x][pii(k, k2)] = 1;
        if (save[pii(k, k2)]) {
            dp[x] = (ll)dp[x] * power(dp[op], save[pii(k, k2)], P) % P * getC(nowsz, save[pii(k, k2)], P) % P;
            nowsz -= save[pii(k, k2)];
            save[pii(k, k2)] = 0;
        }
    }
}

//ll out[maxn], out2[maxn];
ll ans = 0;
void DP(int x, int fa){
    //out[x] = dp[x], out2[x] = has[x];
    if (!root.count(pii(has[x], has2[x]))) {
        ans += dp[x], mo(ans, P);
        root.insert(pii(has[x], has2[x]));
    }
    int _has = has[x], _has2 = has2[x], _dp = dp[x], _siz = siz[x];
    int prehas = siz[x], prehas2 = siz[x];
    ll nowp = P, nowp2 = P;
    srep(i, 0, sz[x]){
        int op = G[x][i], _hasop = (ll)has[op] * siz[x] % M * nowp % M, _hasop2 = (ll)has2[op] * siz[x] % M2 * nowp2 % M2, y;
        if (op == fa) goto jump; 
        dp[x] = (ll)dp[x] * son[x][pii(has[op], has2[op])] % P * getinv(dp[op], P) % P * getinv(sz[x], P) % P;
        has[x] = (((ll)has[x] + M - prehas + M - (ll)has[op] * siz[x] % M * nowp % M) * getinv(P, M) % M + prehas) % M;
        has2[x] = (((ll)has2[x] + M2 - prehas2 + M2 - (ll)has2[op] * siz[x] % M2 * nowp2 % M2) * getinv(P, M2) % M2 + prehas2) % M2;
        has[x] = (ll)has[x] * getinv(n, M) % M * (n - siz[op]) % M;
        has2[x] = (ll)has2[x] * getinv(n, M2) % M2 * (n - siz[op]) % M2;
        if (son[op].count(pii(has[x], has2[x]))) son[op][pii(has[x], has2[x])]++;
        else son[op][pii(has[x], has2[x])] = 1;
        dp[op] = (ll)dp[op] * inv[son[op][pii(has[x], has2[x])]] % P * dp[x] % P * sz[op] % P;
        siz[x] -= siz[op], siz[op] = n;
        sort(G[op].begin(), G[op].end(), cmp);
        has[op] = 0;
        per(j, sz[op] - 1, 0){
            y = G[op][j];
            has[op] = (ll)has[op] * P % M + has[y], mo(has[op], M);
        }
        has[op] = (ll)has[op] * P % M + 1, mo(has[op], M);
        has[op] = (ll)has[op] * n % M;
        has2[op] = 0;
        per(j, sz[op] - 1, 0){
            y = G[op][j];
            has2[op] = (ll)has2[op] * P % M2 + has2[y], mo(has2[op], M2);
        }
        has2[op] = (ll)has2[op] * P % M2 + 1, mo(has2[op], M2);
        has2[op] = (ll)has2[op] * n % M2;
        DP(op, x);
        
        jump: prehas += _hasop, mo(prehas, M), prehas2 += _hasop2, mo(prehas2, M2);
        has[x] = _has, has2[x] = _has2, dp[x] = _dp, siz[x] = _siz;
        (nowp *= P) %= M, (nowp2 *= P) %= M2;
    }
}

void recover(){
    root.clear();
    rep(i, 1, n) son[i].clear();
}

int main(){
    init();
    int T, x, y;
    scanf("%d", &T);
    while (T--){
        scanf("%d", &n);
        rep(i, 1, n) G[i].clear();
        srep(i, 1, n) scanf("%d%d", &x, &y), G[x].pb(y), G[y].pb(x);
        rep(i, 1, n) sz[i] = G[i].size();
        DFS(1, 1);
        //rep(i, 1, n) sort(G[i].begin(), G[i].end(), cmp);
        Hash(1, 1);
        ans = 0;
        DP(1, 1);
        printf("%lld\n", ans);
        //rep(i, 1, n) printf("%lld ", out[i]); printf("\n");
        //rep(i, 1, n) printf("%lld ", out2[i]);
        recover();
    }
    return 0;
}


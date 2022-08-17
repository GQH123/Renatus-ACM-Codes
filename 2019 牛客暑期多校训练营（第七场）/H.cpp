#include <bits/stdc++.h>
#define maxr 100000
#define maxb 31
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define ll long long int
using namespace std;
 
char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
    char ch = gc(); x = 0; bool f = 1;
    while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
    if (ch == '-') ch = gc(), f = 0;
    while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
    x = (f) ? x : -x;
}
 
int numa[maxb], numb[maxb], numc[maxb];
int ca = 0, cb = 0, cc = 0;
ll dp[maxb][2][2][2][2][3][3];
bool vis[maxb][2][2][2][2][3][3];
ll DP(int p, int a0, int b0, int opa, int opb, int opca, int opcx){
    if (opca == 2 && opcx == 2) return 0;
    if (p == -1){
        if (opca == 0 || opcx == 0) {
            if (!a0 && !b0) return 1;
            else return 0;
        }
        else return 0;
    }
    if (vis[p][a0][b0][opa][opb][opca][opcx]) return dp[p][a0][b0][opa][opb][opca][opcx];
    vis[p][a0][b0][opa][opb][opca][opcx] = 1;
    ll& ans = dp[p][a0][b0][opa][opb][opca][opcx];
    int _a0 = a0, _b0 = b0, _opca = opca, _opcx = opcx, _opa = opa, _opb = opb;
    rep(a, 0, 1){
        rep(b, 0, 1){
            if ((_opa && a > numa[p]) || (_opb && b > numb[p])) continue;
            a0 = _a0, b0 = _b0, opca = _opca, opcx = _opcx, opa = _opa, opb = _opb;
            if (opca == 1 && ((a & b) < numc[p])) opca = 2;
            else if (opca == 1 && ((a & b) > numc[p])) opca = 0;
            if (opcx == 1 && ((a ^ b) > numc[p])) opcx = 2;
            else if (opcx == 1 && ((a ^ b) < numc[p])) opcx = 0;
            if (opa && a < numa[p]) opa = 0;
            if (opb && b < numb[p]) opb = 0;
            if (a0 && a) a0 = 0;
            if (b0 && b) b0 = 0;
            ans += DP(p - 1, a0, b0, opa, opb, opca, opcx);
        }
    }
    return ans;
}
void dep(int* num, int& n, int x){
    n = 0;
    while (x){
        num[n++] = (x & 1);
        x >>= 1;
    }
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("H.in", "r", stdin);
    #endif
    int T, A, B, C;
    read(T);
    while (T--){
        read(A), read(B), read(C);
        dep(numa, ca, A), dep(numb, cb, B), dep(numc, cc, C);
        printf("%lld\n", DP(30, 1, 1, 1, 1, 1, 1));
        srep(i, 0, maxb) rep(a0, 0, 1) rep(b0, 0, 1) rep(j, 0, 1) rep(k, 0, 1) rep(l, 0, 2) rep(_l, 0, 2) {
            dp[i][a0][b0][j][k][l][_l] = vis[i][a0][b0][j][k][l][_l] = 0;
        }
        srep(i, 0, maxb) numa[i] = numb[i] = numc[i] = 0;
    }
    return 0;
}

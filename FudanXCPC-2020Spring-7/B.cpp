#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define pii pair<int, int>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define ll long long int 
#define pb push_back
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn 1 << 11
#define maxm
#define maxs
#define maxb
#define M 
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
    char ch = gc(); x = 0; bool f = 1;
    while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
    if (ch == '-') f = 0, ch = gc();
    while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
    x = (f) ? x : -x;
}
int _num[20];
template <class T> void write(T x){    
    if (!x) {putchar('0'), putchar('\n'); return;}
    if (x < 0) putchar('-'), x = -x;
    int c = 0;
    while (x) _num[++c] = x % 10, x /= 10;
    while (c) putchar('0' + _num[c--]); 
    putchar('\n');
}

int n, tt, a[15], b[15], bc[maxn], lo[maxn], v[15][15];
inline int cmpp(int i, int j){
    if (b[i] > a[j]) return 3;
    else if (b[i] == a[j]) return 1;
    return 0;
}
char vis[maxn][maxn >> 1];
float dp[maxn][maxn >> 1];
float DP(int op1, int op2){
    if (!op1) return 0;
    if (vis[op1][op2] == tt) return dp[op1][op2];
    vis[op1][op2] = tt;
    float& ans = dp[op1][op2], _ans;
    ans = 0;
    int _op1 = op1, _op2 = op2, num = bc[op1], _num = bc[op2], i, j;
    while (op1){
        i = lowbit(op1), op1 ^= i, _ans = 0;
        while (op2){    
            j = lowbit(op2), op2 ^= j;
            _ans += DP(_op1 ^ i, _op2 ^ j) + v[lo[i]][lo[j]]; 
        }
        if (num > _num) _ans += DP(_op1 ^ i, _op2) + v[lo[i]][n - 1]; 
        op2 = _op2, _ans /= num;
        ans = max(ans, _ans);
    }
    /*srep(i, 0, n){
        if (op1 & (1 << i)) {
            _ans = 0, _op1 = op1 ^ (1 << i);
            srep(j, 0, n) if (op2 & (1 << j)) _ans += DP(_op1, op2 ^ (1 << j)) + v[i][j];  
            _ans /= num;
            ans = max(ans, _ans);
        }
    }*/
    return ans;
}



int main(){
    
    //cerr << lowbit(8);
        //freopen("B.in", "r", stdin);
        
    //ios :: sync_with_stdio(false), cin.tie(0);
    //IMPOSSIBLE, POSSIBLE
    bc[0] = 0; srep(i, 1, maxn) bc[i] = bc[i >> 1] + (i & 1);
    lo[1] = 0; srep(i, 2, maxn) lo[i] = lo[i >> 1] + 1;
    int T;
    read(T);
    rep(TT, 1, T){
        tt = TT;
        read(n);
        srep(i, 0, n) read(a[i]);
        srep(i, 0, n) read(b[i]);
        srep(i, 0, n) srep(j, 0, n) v[i][j] = cmpp(i, j);
        printf("%.6f\n", DP((1 << n) - 1, (1 << (n - 1)) - 1));
    }
    
    return 0;
}

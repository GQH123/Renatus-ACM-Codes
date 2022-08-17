#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
const int MaxBlockSize = 1000;
const int MAXB = 1000;
#define LL unsigned long long
inline void GET(int &n) {
    static char c; n = 0;
    do c = getchar(); while('0' > c || c > '9');
    while('0' <= c && c <= '9') n = n * 10 + c - '0', c = getchar();
}
  
  
int L[MAXB], R[MAXB];
bool rev[MAXB];
LL val[MAXB][MaxBlockSize];
LL now[MAXB][MaxBlockSize];
  
LL RV[MAXN];
int pos[MAXN], id[MAXN];
int n, m, q, BlockNum, BlockSize;
int E[MAXN][2];
int deg[MAXN], big[MAXN];
bool isBig[MAXN];
bool del[MAXN];
  
vector<int> G[MAXN];
  
#define LEFT (E[j][0])
#define RIGHT (E[j][1])
void BruteForce(int Bid, int l, int r) {
    for(int j = max(l, L[Bid]); j <= min(r, R[Bid]); ++ j) {
        if(deg[LEFT] > BlockSize) now[Bid][id[LEFT]] ^= RV[RIGHT];
        if(deg[RIGHT]> BlockSize) now[Bid][id[RIGHT]] ^= RV[LEFT];
        del[j] ^= 1;
    }
}
void rever(int l,int r){
    for(int i = pos[l]; i <= pos[r]; ++ i) {
        if(l <= L[i] && R[i] <= r)
            rev[i] ^= 1;
        else BruteForce(i, max(l, L[i]), min(r, R[i]));
    }
}
  
LL S(int x) {
    LL st = 0;
    if(deg[x] > BlockSize) for(int i = 1; i <= BlockNum; ++ i)
        st ^= (now[i][id[x]] ^ (rev[i] ? val[i][id[x]] : 0));
    else for(int j : G[x]) if(!del[j] ^ rev[pos[j]])
        st ^= RV[LEFT ^ RIGHT ^ x];
    return st;
}
void query(int x, int y) {
    putchar(S(x) == S(y) ? '1' : '0');
}
 
void init() {
    mt19937_64 gen(593119681);
    for(int i = 1; i <= 100000; ++ i)
        RV[i] = gen();
}
void BuildBlock() {
    L[1] = 1; R[1] = min(BlockSize, m);
    for(int i = 2; i <= BlockNum; ++ i) {
        L[i] = L[i - 1] + BlockSize;
        R[i] = min(R[i - 1] + BlockSize, m);
    }
    for(int i = 1; i <= BlockNum; ++ i) {
        rev[i] = 0;
        for(int j = 1; j <= big[0]; ++ j)
            now[i][j] = val[i][j] = 0;
        for(int j = L[i]; j <= R[i]; ++ j) {
            pos[j] = i;
            if(deg[LEFT] > BlockSize) {
                val[i][id[LEFT]] ^= RV[RIGHT];
                now[i][id[LEFT]] ^= RV[RIGHT];
            }
            if(deg[RIGHT] > BlockSize) {
                val[i][id[RIGHT]] ^= RV[LEFT];
                now[i][id[RIGHT]] ^= RV[LEFT];
            }
        }
    }
}
int main() {
    //freopen("input", "r", stdin);
    //freopen("output","w",stdout);
    init();
    int T; cin >> T;
    while(T --) {
        GET(n); GET(m);
        for(BlockSize = 1; BlockSize * BlockSize < m; ++ BlockSize);
        BlockNum = (m + BlockSize - 1) / BlockSize;
        big[0] = 0;
        for(int i = 1; i <= max(n, m); ++ i) {
            deg[i] = 0;
            G[i].clear();
        }
        for(int i = 1; i <= m; ++ i) {
            GET(E[i][0]); GET(E[i][1]);
            del[i] = 0;
            ++ deg[E[i][0]];
            ++ deg[E[i][1]];
            G[E[i][0]].push_back(i);
            G[E[i][1]].push_back(i);
        }
        for(int i = 1; i <= n; ++ i)
            if(deg[i] > BlockNum) {
                big[++ big[0]] = i;
                id[i] = big[0];
            }
        BuildBlock();
        GET(q);
        int op, x, y;
        for(int i = 1; i <= q; ++ i) {
            GET(op); GET(x); GET(y);
            if(op == 1) rever(x, y);
            else query(x, y);
        }
        puts("");
    }
    return 0;
}

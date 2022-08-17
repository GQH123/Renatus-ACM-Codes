#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define maxn 2020
#define maxm
#define mo(x) (x = (x >= M) ? (x - M) : x)
using namespace std;

int n; char g[maxn][maxn];

inline int id(char ch){
    if ('a' <= ch && ch <= 'z') return ch - 'a';
    else return ch - 'A' + 26;
}
int power(int x, int y){
    int ans = 1, con = x;
    while (y){
        if (y & 1) ans = 1ll * ans * con % M;
        con = 1ll * con * con % M;
    }
    return ans;
}
int getinv(int x){
    return power(x, M - 2);
}
int prex[maxn][maxn], prey[maxn][maxn], iprex[maxn][maxn], iprey[maxn][maxn];
void init(){
    rep(j, 1, n) iprex[0][j] = 1;
    rep(i, 1, n) {
        rep(j, 1, n){
            prex[i][j] = (1ll * prex[i - 1][j] * base + id(g[i][j])) % M;
            iprex[i][j] = getinv(prex[i][j]);
        }
    }
    rep(i, 1, n) iprey[i][0] = 1;
    rep(j, 1, n) {
        rep(i, 1, n){
            prey[i][j] = (1ll * prey[i][j - 1] * base + id(g[i][j])) % M;
            iprey[i][j] = getinv(prey[i][j]);
        }
    }
}
int tmpx[maxn][maxn], tmpy[maxn][maxn];
bool judge(int x){
    if (x == 1) return true;
    x--;
    int mi = power(base, x);
    int allmi = power(base, x * x);
    rep(i, x, n){
        int has = 0;
        rep(j, 1, x) has = (1ll * has * mi + 1ll * prex[i][j] * iprex[i - x][j]) % M;
        tmpx[i][x] = has;
        rep(j, x + 1, n){
            has = (1ll * has * mi + M - 1ll * prex[i][j - x] * iprex[i][j - x] % M * allmi % M) % M;
            has += 1ll * prex[i][j] * iprex[i - x][j] % M, mo(has);
        }
    } 
    
    
    rep(j, x, n){   
        rep(i, 1, x){
            has = 1ll * has * mi + 1ll * prey[i][j] * ipre[i][j]
        }
        rep(i, x + 1, n){
            has = (1ll * has * mi + M - 1ll * prex[i][j - x] * iprex[i][j - x] % M * allmi % M) % M;
            has += 1ll * prex[i][j] * iprex[i - x][j] % M, mo(has);
        }
    }
}
int lower_bound(int l, int r){
    while (l != r){
        int mid = ((r - l + 1) >> 1) + l;
        if (judge(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}

int main(){
    while (scanf("%d", &n) == 1 && n){
        rep(i, 1, n) scanf("%s", g[i] + 1);
        printf("%d\n", lower_bound(1, n));
    }
	return 0;
}

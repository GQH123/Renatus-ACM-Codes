#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, r, l) for (int i = r; i >= l; i--)
#define srep(i, l, r) for (int i = l; i < r; i++)
#define sper(i, r, l) for (int i = r; i > l; i--)
#define ll long long int 
#define maxn 18
#define M 998244353
using namespace std;

int power(int x, int y) {
    int ans = 1, con = x;
    while (y){
        if (y & 1) ans = 1ll * ans * con % M;
        y >>= 1;
        con = 1ll * con * con % M;
    }
    return ans;
}

bitset<maxn * maxn << 2> mat[maxn * maxn << 2];

int solve(int n, int m){
    int now = 0;
    rep(j, 1, m){
        int f = -1;
        rep(i, now + 1, n) {
            if (mat[i][j]) {
                f = i;
                break;
            }
        }
        if (f == -1) continue;
        now++;
        swap(mat[now], mat[f]);
        rep(i, 1, n) {
            if (i == now) continue;
            if (mat[i][j]) mat[i] ^= mat[now];
        }
    }
    rep(i, now + 1, n) {
        if (mat[i][m + 1]) return 0;
    }
    /*
    printf("%d %d\n", m, now);
    rep(i, 1, n) {
        rep(j, 1, m) {
            printf("%d", (int)mat[i][j]);
        }
        printf("\n");
    }
    */
    return power(2, m - now);
}

char g[maxn << 1][maxn << 1];

struct ele{
    int x1, y1, x2, y2;
    ele(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2){}
    ele(){}
    void pro(){
        if (x1 > x2) swap(x1, x2), swap(y1, y2);
        else if (x1 == x2) {
            if (y1 > y2) swap(y1, y2);
        }
    }
    bool operator < (const ele b) const{
        return x1 == b.x1 ? y1 == b.y1 ? x2 == b.x2 ? y2 < b.y2 : x2 < b.x2 : y1 < b.y1 : x1 < b.x1;
    }
};

int n, m, cnum = 0;

map<ele, int> tab;

int getid(ele a){
    a.pro();
    if (!tab.count(a)) {
        tab[a] = ++cnum;
        return cnum;
    }
    return tab[a];
}

bool judge(int i, int j) {
    return 1 <= i && i <= n && 1 <= j && j <= m;
}

void work(){
    tab.clear();
    scanf("%d%d", &n, &m);
    srep(i, 1, n) scanf("%s", g[i] + 1);
    int pnum = 0; cnum = 0;
    rep(i, 1, n) rep(j, 1, m) {
        if (judge(i - 1, j)){
            getid(ele(i - 1, j, i, j));
        }
        if (judge(i + 1, j)){
            getid(ele(i + 1, j, i, j));
        }
        if (judge(i, j - 1)){
            getid(ele(i, j - 1, i, j));
        }
        if (judge(i, j + 1)){
            getid(ele(i, j + 1, i, j));
        }
    }
    rep(i, 1, n) rep(j, 1, m) {
        pnum++;
        mat[pnum].reset();
        if (judge(i - 1, j)){
            mat[pnum][getid(ele(i - 1, j, i, j))] = 1;
        }
        if (judge(i + 1, j)){
            mat[pnum][getid(ele(i + 1, j, i, j))] = 1;
        }
        if (judge(i, j - 1)){
            mat[pnum][getid(ele(i, j - 1, i, j))] = 1;
        }
        if (judge(i, j + 1)){
            mat[pnum][getid(ele(i, j + 1, i, j))] = 1;
        } 
    }
    srep(i, 1, n) srep(j, 1, m) {
        pnum++;
        mat[pnum].reset();
        if (g[i][j] == '1') {
            mat[pnum][cnum + 1] = 1;
        }
        if (g[i][j] != '.') {
            mat[pnum][getid(ele(i, j, i + 1, j))] = 1;
            mat[pnum][getid(ele(i, j, i, j + 1))] = 1;
            mat[pnum][getid(ele(i + 1, j + 1, i + 1, j))] = 1;
            mat[pnum][getid(ele(i + 1, j + 1, i, j + 1))] = 1;
        }
    }
    printf("%d\n", solve(pnum, cnum));
}

int main(){
    int T; scanf("%d", &T);
    while (T--){
        work();
    }
    return 0;
}

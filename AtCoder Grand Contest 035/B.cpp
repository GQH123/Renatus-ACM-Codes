#include <bits/stdc++.h>
#define maxn 100015
#define maxm 100015
#define maxb
#define maxr 200000
#define maxs
#define M 
#define pii pair<int, int>
#define pdd pair<double, double>
#define uint unsigned int
#define ull unsigned long long int
#define ll long long int 
#define lowbit(x) x & -x
#define fi first
#define se second
#define pb push_back
#define next NEXT
#define hash HASH
#define ls ch[x][0]
#define rs ch[x][1]
#define pi 3.141592653589793
#define ei 2.718281828459045
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define END return 0
//#define ONLINE_JUDGE
//#define DEBUG
using namespace std;

char *p1, *p2, buffer[maxr];
template <class T> void read(T& x){
    char ch = gc(); x = 0; bool f = 1;
    while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
    if (ch == '-') f = 0, ch = gc();
    while ('0' <= ch && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = gc();
    x = f ? x : -x;
}

int n,m;
struct edge{
    int next, to;
    edge(int next, int to) : next(next), to(to){}
    edge(){}
}e[maxm << 1];
int cnt = 1, h[maxn], ans[maxn];
void Add_Edge(int x, int y){
    e[++cnt] = edge(h[x], y);
    h[x] = cnt;
    e[++cnt] = edge(h[y], x);
    h[y] = cnt;
}
bool vis[maxm << 1];
pii e2[maxm];
pii out[maxm << 1];
int ct = 0;

int ufs[maxn];
int get(int x){
    return ufs[x] = (ufs[x] == x) ? x : get(ufs[x]);
}

int num[maxn];
void dfs(int x, int fa){
    if (ans[x]) num[x] = 1;
    erep(i, x){
        int op = e[i].to;
        if (op == fa) continue;
        dfs(op, x);
        if (num[op] ^ vis[i]) out[++ct] = pii(x, op);
        else out[++ct] = pii(op, x);
        num[x] ^= num[op];
    }
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("B.in", "r", stdin);
    #endif
    int x, y;
    read(n), read(m);
    if (m & 1) {printf("-1"); END;}
    rep(i, 1, n) ufs[i] = i;
    rep(i, 1, m) {
        read(x), read(y);
        ans[x] ^= 1;
        int _x = get(x), _y = get(y);
        if (_x == _y) out[++ct] = pii(x, y);
        else Add_Edge(x, y), ufs[_x] = _y, vis[cnt ^ 1] = 1;
    }
    dfs(1, 1);
    rep(i, 1, ct) printf("%d %d\n", out[i].fi, out[i].se);
    return 0;
}

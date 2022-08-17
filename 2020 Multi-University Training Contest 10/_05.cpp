#pragma comment (linker,"/STACK:102400000,102400000")
#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define maxn 600020        //twice the size of n 
using namespace std;

int n, k;
struct edge{
    int next, to;
    edge(int next, int to) : next(next), to(to){}
    edge(){}
}e[maxn << 1];
int cnt = 1, h[maxn];
void Add_Edge(int x, int y){
    e[++cnt] = edge(h[x], y);
    h[x] = cnt;
    e[++cnt] = edge(h[y], x);
    h[y] = cnt;
}

int g = 0, ns, s[maxn];
bool vis[maxn];
void dfs(int x, int fa){
    s[x] = 1; bool f = 1;
    erep(i, x){
        int op = e[i].to;
        if (op == fa || vis[op]) continue;
        dfs(op, x);
        s[x] += s[op];
        if (s[op] > (ns >> 1)) f = 0;
    }
    if (ns - s[x] > (ns >> 1)) f = 0;
    if (f) g = x;
}
int all[maxn], cur[maxn], res[maxn], mxd = 0, _mxd = 0;
void add(int x, int fa, int d){
    mxd = max(mxd, d), all[d]++;
    erep(i, x){
        int op = e[i].to;
        if (op == fa || vis[op]) continue;
        add(op, x, d + 1);
    } 
}
void sta(int x, int fa, int d){
    _mxd = max(_mxd, d), cur[d]++;
    erep(i, x){
        int op = e[i].to;
        if (op == fa || vis[op]) continue;
        sta(op, x, d + 1);
    } 
} 
void upd(int x, int fa, int d){
    res[x] += (k - d + 1 > mxd) ? 0 : all[max(0, k - d + 1)];
    res[x] -= (k - d + 1 > _mxd) ? 0 : cur[max(0, k - d + 1)];
    erep(i, x){
        int op = e[i].to;
        if (op == fa || vis[op]) continue;
        upd(op, x, d + 1);
    }
}
void solve(int x){
    dfs(x, 0);
    x = g;
    //dfs(x, 0);
    vis[x] = 1;
    all[0]++, mxd = 0;
    erep(i, x){
        int op = e[i].to;
        if (vis[op]) continue;
        add(op, x, 1);
    }
    per(i, mxd - 1, 0) all[i] += all[i + 1];
    res[x] += (k + 1 > mxd) ? 0 : all[k + 1];
    erep(i, x){
        int op = e[i].to;
        if (vis[op]) continue;
        _mxd = 0;
        sta(op, x, 1); 
        per(i, _mxd - 1, 0) cur[i] += cur[i + 1];
        upd(op, x, 1);
        rep(i, 0, _mxd) cur[i] = 0;
    }
    rep(i, 0, mxd) all[i] = 0;
    int _ns = ns;
    erep(i, x){
        int op = e[i].to;
        if (vis[op]) continue;
        if (s[op] > s[x]) ns = _ns - s[x], solve(op);
        else ns = s[op], solve(op);
    }
}

int main(){
    int T, x, y; scanf("%d", &T);
    while (T--){
        scanf("%d%d", &n, &k);
        rep(i, 2, n) scanf("%d%d", &x, &y), Add_Edge(x, n + i - 1), Add_Edge(y, n + i - 1);
        int _n = n; n = 2 * n - 1;
		ns = n; solve(1);
		int mi = n + 5;
		if (k & 1) rep(i, _n + 1, n) mi = min(mi, res[i]);
		else rep(i, 1, _n) mi = min(mi, res[i]);
        //rep(i, 1, n) printf("%d ", res[i]); printf("\n");
        printf("%d\n", mi >> 1);
        rep(i, 1, n) h[i] = res[i] = vis[i] = 0; cnt = 1;
    }
    return 0;
}

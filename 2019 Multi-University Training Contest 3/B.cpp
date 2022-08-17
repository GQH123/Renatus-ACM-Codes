#include <bits/stdc++.h>
#define maxr 100000
#define maxn 200015
#define maxm 4000015
#define maxb 20
#define ll long long int 
#define ms(a, b) memset(a, b, sizeof(a))
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define erep(graph, i, x) for(register int i = graph[x]; i; i = e[i].next)
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
    char ch = gc(); x = 0; bool f = 1;
    while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
    if (ch == '-') f = 0, ch = gc();
    while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
    x = (f) ? x : -x;
}
int n, m, q, S;
struct edge{
    int next, to;
    edge(int next, int to) : next(next), to(to){}
    edge(){}
}e[maxm]; //注意要考虑多图共存
int cnt = 1, out[maxn], h[maxn], rh[maxn], tree[maxn];
void Add_Edge(int* graph, int x, int y){
    e[++cnt] = edge(graph[x], y);
    graph[x] = cnt;
} //多图共存时的优秀写法

int idom[maxn], sdom[maxn], buc[maxn], dfs[maxn], idfs[maxn], ffa[maxn], t = 0; 
//注意 ffa 要防止与下面树的 fa 数组重名
int ufs[maxn], mn[maxn]; //mn 中是结点 dfs 序
int Find(int x){
    if (x == ufs[x]) return x;
    int _ufs = Find(ufs[x]);
    if (sdom[mn[ufs[x]]] < sdom[mn[x]]) mn[x] = mn[ufs[x]];
    return ufs[x] = _ufs;
}
void DFS(int x){
    dfs[x] = ++t, idfs[t] = x;
    erep(h, i, x){
        int op = e[i].to;
        if (!dfs[op]) { //由于用到 dfs 是否为 0 ，dfs必须清零
            DFS(op);
            ffa[dfs[op]] = dfs[x];
        }
    }
} //原图用来求 dfs 树，所以还是有用的
inline void chkmin(int& x, int y){
    x = (x < y) ? x : y;
}
void Dominator_Tree(){
    t = 0;
    rep(i, 1, S) ufs[i] = sdom[i] = mn[i] = i, buc[i] = dfs[i] = idom[i] = 0;
    DFS(S);
    per(i, S, 2) {    
        int x = idfs[i];
        erep(rh, j, x){
            int op = dfs[e[j].to];
            Find(op);
            chkmin(sdom[i], sdom[mn[op]]);
        }
        Add_Edge(buc, sdom[i], i);
        x = ffa[i];
        ufs[i] = x; //经测试貌似放在下面也可以
        erep(buc, j, x){
            int op = e[j].to;
            Find(op);
            idom[op] = (sdom[mn[op]] < x) ? mn[op] : x;
        }
    }
    rep(i, 2, S) {
        if (idom[i] != sdom[i]) idom[i] = idom[idom[i]];
        Add_Edge(tree, idfs[idom[i]], idfs[i]); //建树时要使用原来的标号
    }
}//整个 Dominator_Tree 的过程都在 dfs 树（即新标号）上进行，只有在寻找指向某点的点时才会用到原图的反图

int d[maxn], fa[maxn][maxb];
void DFS_Tree(int x){
    srep(i, 1, maxb) fa[x][i] = fa[fa[x][i - 1]][i - 1];
    erep(tree, i, x){
        int op = e[i].to;
        if (op == fa[x][0]) continue;
        fa[op][0] = x;
        d[op] = d[x] + 1;
        DFS_Tree(op);
    }
    /*printf("%d :", x);
    erep(tree, i, x){
        int op = e[i].to;
        if (op == fa[x][0]) continue;
        printf(" %d", op);
    }
    printf("\n");*/
}
int getlca(int x, int y){
    if (x == y) return x;
    if (d[x] < d[y]) swap(x, y);
    int di = d[x] - d[y], now = 0;
    while (di){
        if (di & 1) x = fa[x][now];
        di >>= 1, now++;
    }
    if (x == y) return x;
    assert(d[x] == d[y]);
    per(i, maxb - 1, 0) if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
    return fa[x][0];
}

void recover(){
    rep(i, 1, S) h[i] = tree[i] = rh[i] = out[i] = 0;
    cnt = 1;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("B.in", "r", stdin);
    #endif
    int T, x, y;
    read(T);
    while (T--){
        read(n), read(m);
        S = n + 1;
        rep(i, 1, m) read(x), read(y), Add_Edge(h, y, x), Add_Edge(rh, x, y), out[x]++;
        rep(i, 1, n) if (!out[i]) Add_Edge(h, S, i), Add_Edge(rh, i, S); 
        Dominator_Tree();
        d[S] = 1, fa[S][0] = 0; //由于 S 点发生变化，此时必须清零
        DFS_Tree(S);
        read(q);
        rep(i, 1, q){
            read(x), read(y);
            int lca = getlca(x, y);
            printf("%d\n", d[x] + d[y] - d[lca] - 1);
        }
        recover();
    }
    return 0;
}

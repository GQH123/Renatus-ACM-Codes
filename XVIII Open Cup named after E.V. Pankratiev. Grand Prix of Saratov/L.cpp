#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define pb push_back
#define pc putchar
#define lowbit(x) (x & -x)
#define maxr 2000020
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

namespace Fast_Read{
    char buffer[maxr], *p1, *p2;
    template<class T> void read_signed(T& x){
        char ch = gc(); x = 0; bool f = 1;
        while (!isdigit(ch) && ch != '-') ch = gc();
        if (ch == '-') f = 0, ch = gc();
        while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
        x = (f) ? x : -x;
    }
    template<class T, class... Args> void read_signed(T& x, Args&... args){
        read_signed(x), read_signed(args...);
    }
    template<class T> void read_unsigned(T& x){
        char ch = gc(); x = 0;
        while (!isdigit(ch)) ch = gc(); 
        while (isdigit(ch)) x = (x << 1) + (x << 3) + ch - '0', ch = gc(); 
    }
    template<class T, class... Args> void read_unsigned(T& x, Args&... args){
        read_unsigned(x), read_unsigned(args...);
    }
    #define isletter(ch) ('a' <= ch && ch <= 'z')
    int read_string(char* s){
        char ch = gc(); int l = 0;
        while (!isletter(ch)) ch = gc();
        while (isletter(ch)) s[l++] = ch, ch = gc();
        s[l] = '\0'; return l;
    }
}using namespace Fast_Read; 

int _num[20];
template <class T> void write(T x, char sep = '\n'){	
	if (!x) {putchar('0'), putchar(sep); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar(sep);
}

#define read read_signed
#define reads read_string 
#define writes puts

#define maxn 300020
#define maxm 300020
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

int n, m, res[maxn];
struct edge{
    int next, to, len;
    edge(int next, int to, int len) : next(next), to(to), len(len){}
    edge(){}
}e[maxm << 1];
int cnt = 1, h[maxn];

struct oriedge{
    int x, y, l;
    oriedge(int x, int y, int l) : x(x), y(y), l(l){}
    oriedge(){}
}pe[maxn];
void Add_Edge(int x, int y, int z) {
    e[++cnt] = edge(h[x], y, z);
    h[x] = cnt;
    e[++cnt] = edge(h[y], x, z);
    h[y] = cnt;
}

namespace Tree{
    struct edge{
    int next, to, id;
        edge(int next, int to, int id) : next(next), to(to), id(id){}
        edge(){}
    }e[maxn << 1];
    int cnt = 1, h[maxn];
    void Add_Edge(int x, int y, int id) {
        e[++cnt] = edge(h[x], y, id);
        h[x] = cnt;
        e[++cnt] = edge(h[y], x, id);
        h[y] = cnt;
    }
    int siz[maxn], dfs[maxn], idfs[maxn], fa[maxn], top[maxn], son[maxn], d[maxn], ti = 0;
    void DFS(int x) {
        siz[x] = 1;
        erep(i, x){
            int op = e[i].to;
            if (op == fa[x]) continue;
            d[op] = d[x] + 1;
            fa[op] = x;
            DFS(op);
            siz[x] += siz[op];
            if (siz[op] > siz[son[x]]) son[x] = op;
        }
    }
    void DFS(int x, int tp) {
        dfs[x] = ++ti;
        idfs[ti] = x;
        top[x] = tp;
        if (son[x]) DFS(son[x], tp);
        erep(i, x) {
            int op = e[i].to;
            if (op == fa[x] || op == son[x]) continue;
            DFS(op, op);
        }
    }
    int qx, qy, qd; bool set[maxn << 2]; 
    void mmod(int l, int r, int o) {
        if (qx <= l && r <= qy) {
            set[o] = 1;
            return;
        }
        int mid = ((r - l) >> 1) + l;
        if (qx <= mid) mmod(l, mid, o << 1);
        if (qy > mid) mmod(mid + 1, r, o << 1 | 1);  
    }
    bool get(int l, int r, int o) {
        if (set[o]) return 1;
        if (l == r) {
            return 0;
        }
        int mid = ((r - l) >> 1) + l;
        if (qx <= mid) return get(l, mid, o << 1);
        return get(mid + 1, r, o << 1 | 1);
    }
    void mod(int x, int y) {
        int f1 = top[x], f2 = top[y];
        while (f1 != f2) {
            if (d[f1] > d[f2]) {
                qx = dfs[f1], qy = dfs[x];
                mmod(1, n, 1);
                x = fa[f1], f1 = top[x];
            }
            else {
                qx = dfs[f2], qy = dfs[y];
                mmod(1, n, 1);
                y = fa[f2], f2 = top[y];
            }
        }
        qx = min(dfs[x], dfs[y]) + 1, qy = max(dfs[x], dfs[y]);
        if (qx <= qy) mmod(1, n, 1);
    }
    bool gget(int x, int op) {
        qx = dfs[op]; return get(1, n, 1);
    } 
    void query(int x) {
        erep(i, x) {
            int op = e[i].to;
            if (op == fa[x]) continue;
            if (!gget(x, op)) {
                res[e[i].id] = siz[op];
            }
            else res[e[i].id] = 0;
            query(op);
        }
    }
    void init(){
        DFS(1), DFS(1, 1); //init(1, n, 1);
    }
}

priority_queue<pii> pq;
int d[maxn]; bool vis[maxn];

int ufs[maxn];
int find_root(int x) {
    return ufs[x] = (ufs[x] == x) ? x : find_root(ufs[x]);
}
bool merge(int x, int y) {
    x = find_root(x), y = find_root(y);
    if (x == y) return false;
    ufs[x] = y;
    return true;
}
bool ontree[maxn];
void Dij(int s){
    rep(i, 1, n) d[i] = -1;
    d[s] = 0;
    pq.push(pii(0, s));
    while (!pq.empty()) {
        pii op = pq.top(); pq.pop();
        if (vis[op.se]) continue;
        vis[op.se] = 1;
        int x = op.se;
        erep(i, x) {
            int y = e[i].to;
            if (d[y] == -1 || d[y] > d[x] + e[i].len) {
                d[y] = d[x] + e[i].len;
                pq.push(pii(-d[y], y));
            }
        }
    }
    
    rep(i, 1, n) ufs[i] = i;
    rep(i, 1, m) {
        if (max(d[pe[i].x], d[pe[i].y]) - min(d[pe[i].x], d[pe[i].y]) == pe[i].l) {
            if (!merge(pe[i].x, pe[i].y)) {
                ontree[i] = 1;
            }
            else Tree :: Add_Edge(pe[i].x, pe[i].y, i);
        }
        else res[i] = 0;
    }
    Tree :: init();
    rep(i, 1, m) {
        if (ontree[i]) {
            Tree :: mod(pe[i].x, pe[i].y);
        }
    }
    Tree :: query(1);
} 
int main(){
    int x, y, z;
    read(n, m);
    rep(i, 1, m) {
        read(x, y, z);
        pe[i] = oriedge(x, y, z);
        Add_Edge(x, y, z);
    }
    Dij(1);
    rep(i, 1, m) printf("%d\n", res[i]);
	return 0;
}


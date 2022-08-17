#include <bits/stdc++.h>
  
#define st first
#define nd second
#define all(x) (x).begin(), (x).end()
  
using namespace std;
using namespace placeholders;
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
  
template <class T> void mini(T &l, T r){l = min(l, r);}
template <class T> void maxi(T &l, T r){l = max(l, r);}
  
template <class TH> void _dbg(const char *sdbg, TH h){cerr << sdbg << "=" << h << "\n";}
template <class TH, class ...TA> void _dbg(const char *sdbg, TH h, TA... a){
    while (*sdbg != ','){cerr << *sdbg++;}cerr << "=" << h << ","; _dbg(sdbg + 1, a...);
}
template <class T> ostream &operator <<(ostream &os, vector<T> V){
    os << "["; for (auto vv: V) os << vv << ","; return os << "]";
}
template <class L, class R> ostream &operator <<(ostream &os, pair<L, R> P){
    return os << "(" << P.st << "," << P.nd << ")";
}
  
#ifdef SFIC
    #define eput(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
    #define eput(...) 218
#endif
  
const int N = 2E5 + 10;
const int D = 18;
  
int n, Q;
vector<int> E[N];
int dep[N];
pii d[N][3];
int p[D][N];
  
struct node{
    int a[3];
    int i;
  
    bool operator <(const node& r){
        return a[0] < r.a[0];
    }
};
  
vector<node> b, que;
int q, ique[N][3], sque[N][3];
  
node c[N];
int ans[N];
  
inline void upd(pii a[], pii x){
    if (a[0] < x)
        a[2] = a[1], a[1] = a[0], a[0] = x;
    else if (a[1] < x)
        a[2] = a[1], a[1] = x;
    else if (a[2] < x)
        a[2] = x;
}
  
pii operator+(const pii &l, int c){
    return pii(l.st + c, l.nd);
}
  
void DFS1(int u, int pre){
    d[u][0].nd = u;
    for (auto &v: E[u]){
        if (pre == v)
            continue;
        p[0][v] = u;
        dep[v] = dep[u] + 1;
        DFS1(v, u);
        upd(d[u], d[v][0] + 1);
    }
}
  
void DFS2(int u, int pre, pii up){
    upd(d[u], up);
    b.push_back({d[u][0].st, d[u][1].st, d[u][2].st, u});
    for (auto &v: E[u]){
        if (pre == v)
            continue;
        DFS2(v, u, d[u][d[u][0] == d[v][0] + 1] + 1);
    }
}
  
void build(){
    for (int i = 1; i < D; ++i)
        for (int j = 0; j < n; ++j)
            p[i][j] = p[i - 1][p[i - 1][j]];
}
  
int query(int u, int v){
    if (dep[u] < dep[v])
        swap(u, v);
    int t = dep[u] - dep[v];
    for (int i = 0; t; ++i, t >>= 1)
        if (t & 1)
            u = p[i][u];
    if (u == v)
        return u;
  
    for (int i = D - 1; i >= 0; --i)
        if (p[i][u] != p[i][v])
            u = p[i][u], v = p[i][v];
    return p[0][u];
}
  
int step(int u, int v, int k){
    int w = query(u, v);
    if (dep[u] - dep[w] >= k){
        for (int i = 0; k; ++i, k >>= 1)
            if (k & 1)
                u = p[i][u];
        return u;
    }
    else{
        k = dep[u] + dep[v] - dep[w] * 2 - k;
        for (int i = 0; k; ++i, k >>= 1)
            if (k & 1)
                v = p[i][v];
        return v;
    }
}
  
ostream& operator <<(ostream& out, const node& r){
    out << '[' << r.a[0] << ','
            << r.a[1] << ','
            << r.a[2] << '.'
            << r.i << ']';
    return out;
}
  
void solve(int lv, int rv, int l, int r, int L, int R){
    constexpr auto f1 = [](const node& l, const node& r){return l.a[1] < r.a[1];};
    if (lv + 1 == rv || l == r || L == R){
        sort(b.begin() + l, b.begin() + r, f1);
        sort(que.begin() + L, que.begin() + R, f1);
        return;
    }
  
    int t = lv + rv >> 1;
    int m = lower_bound(b.begin() + l, b.begin() + r, t,
        [](const node& l, int r){return l.a[0] < r;}) - b.begin();
    int M = lower_bound(que.begin() + L, que.begin() + R, t,
        [](const node& l, int r){return l.a[0] < r;}) - que.begin();
  
    solve(lv, t, l, m, L, M);
    solve(t, rv, m, r, M, R);
  
    int cur = M - 1;
    node* p = nullptr;
    for (int i = r - 1; i >= m; --i){
        for (; cur >= L && que[cur].a[1] >= b[i].a[1]; --cur)
            if (p && que[cur].a[2] < p->a[2])
                ans[que[cur].i] = p->i;
  
        if (p == nullptr || p->a[2] < b[i].a[2])
            p = &b[i];
    }
  
    for (; cur >= L; --cur)
        if (p && que[cur].a[2] < p->a[2])
            ans[que[cur].i] = p->i;
  
    merge(b.begin() + l, b.begin() + m, b.begin() + m, b.begin() + r,
        c, f1);
    copy_n(c, r - l, b.begin() + l);
    merge(que.begin() + L, que.begin() + M, que.begin() + M, que.begin() + R,
        c, f1);
    copy_n(c, R - L, que.begin() + L);
}
  
int main(){
    scanf("%d", &n);
    for (int i = 1; i < n; ++i){
        int u, v;
        scanf("%d%d", &u, &v);
        E[u].push_back(v);
        E[v].push_back(u);
    }
    DFS1(0, -1);
    build();
    DFS2(0, -1, pii(0, -1));
  
    scanf("%d", &q);
    fill_n(ans, q, -2);
    for (int i = 0; i < q; ++i){
        int (&a)[3] = sque[i];
        scanf("%d%d%d", a, a + 1, a + 2);
        copy_n(a, 3, ique[i]);
        int s = a[0] + a[1] + a[2];
        if (s & 1)
            ans[i] = -1;
        else{
            s >>= 1;
            a[0] = s - a[0];
            a[1] = s - a[1];
            a[2] = s - a[2];
  
            sort(a, a + 3, greater<int>());
            if (a[2] < 0)
                ans[i] = -1;
            else
                que.push_back({a[0] - 1, a[1] - 1, a[2] - 1, i});
        }
    }
    sort(all(b));
    sort(all(que));
    solve(-1, n, 0, b.size(), 0, que.size());
  
    const int z[6][3] = {
        {0, 1, 2},
        {0, 2, 1},
        {1, 0, 2},
        {1, 2, 0},
        {2, 0, 1},
        {2, 1, 0},
    };
    for (int i = 0; i < q; ++i){
        if (ans[i] < 0){
            puts("-1");
            continue;
        }
  
        int u = ans[i];
        int (&a)[3] = sque[i], (&b)[3] = ique[i];
        int t[3];
        for (int j = 0; j < 3; ++j){
            t[j] = step(u, d[u][j].nd, a[j]);
        }
  
        for (int j = 0; j < 6; ++j){
            if (a[z[j][0]] + a[z[j][1]] == b[0]
                && a[z[j][0]] + a[z[j][2]] == b[1]
                && a[z[j][1]] + a[z[j][2]] == b[2]){
                printf("%d %d %d\n", t[z[j][0]], t[z[j][1]], t[z[j][2]]);
                break;
            }
        }
    }
    return 0;
}

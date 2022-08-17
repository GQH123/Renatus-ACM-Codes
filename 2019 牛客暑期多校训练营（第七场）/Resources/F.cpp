#include <bits/stdc++.h>
#define maxr 100000
#define maxn 100019
#define maxc 200019
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define ll long long int
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define lowbit(x) (x & -x)
#define ms(a, b) memset(a, b, sizeof(a))
using namespace std;
 
const int inf = 1000000000;
 
char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
    char ch = gc(); x = 0; bool f = 1;
    while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
    if (ch == '-') f = 0, ch = gc();
    while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
    x = (f) ? x : -x;
}
 
int n, m;
struct stone{
    int e, l, c;
    stone(int e, int l, int c) : e(e), l(l), c(c){}
    stone(){}
}a[maxn];
 
vector<pii> op[maxn];
 
struct Fenwick_Tree_Pre{
    ll c[maxc];
    void init(){ ms(c, 0); }
    void add(int x, ll v){
        while (x < maxc){
            c[x] += v;
            x += lowbit(x);
        }
    }
    ll get(int x){
        ll ans = 0;
        while (x){
            ans += c[x];
            x -= lowbit(x);
        }
        return ans;
    }
}C1; //记总和
struct Fenwick_Tree_Suf{
    int c[maxc];
    void init(){ ms(c, 0); }
    void add(int x, int v){
        while (x){
            c[x] += v;
            x -= lowbit(x);
        }
    }
    int get(int x){
        int ans = 0;
        while (x < maxc){
            ans += c[x];
            x += lowbit(x);
        }
        return ans;
    }
}C2; //记个数
 
multiset<int> s;
multiset<int> :: iterator it;
void upd(int t, int d){
    it = s.lower_bound(t);
    int x = *it;
    if (x < inf){
        C1.add(x - t, d * (x - t));
        C2.add(x - t, d);
    }
     
    it--;
    int y = *it;
    C1.add(t - y, d * (t - y));
    C2.add(t - y, d);
     
    if (x < inf){
        C1.add(x - y, -d * (x - y));
        C2.add(x - y, -d);
    }
}
void add(int t){
    upd(t, 1), s.insert(t);
}
void del(int t){
    s.erase(s.lower_bound(t)), upd(t, -1);
}
ll cal(int x){
    s.erase(s.begin());
    if (s.size() == 1) {s.insert(0); return 0;}
    if (!a[x].l) {s.insert(0); return a[x].e;}
    ll ans = 0;
    int mi = *s.begin();
    s.insert(0);
    ans = min((ll)a[x].c, a[x].e + (ll)a[x].l * mi);
     
    int bound = a[x].c / a[x].l;
    if (bound) ans += (ll)a[x].l * C1.get(bound);
    ans += (ll)a[x].c * C2.get(bound + 1);
    if (mi <= bound) ans -= mi * a[x].l;
    else ans -= a[x].c;
     
    //recover
    return ans;
}
 
void recover(){
    rep(i, 1, n + 1) op[i].clear();
    s.clear();
    C1.init(), C2.init();
}
 
int main(){
    #ifndef ONLINE_JUDGE
        freopen("F.in", "r", stdin);
    #endif
    int T, x, y, z;
    read(T);
    rep(TT, 1, T){
        printf("Case #%d: ", TT);
        read(n);
        rep(i, 1, n) read(a[i].e), read(a[i].l), read(a[i].c);
        read(m);
        rep(i, 1, m) read(x), read(y), read(z), op[y].pb(pii(x, 1)), op[z + 1].pb(pii(x, -1));
        ll ans = 0;
        s.insert(0), s.insert(inf); //左右哨兵，防止越界
        rep(i, 1, n){
            int sz = op[i].size();
            srep(j, 0, sz){
                pii x = op[i][j];
                if (x.se == 1) add(x.fi);
                else del(x.fi);
            }
            ans += cal(i);
        }
        printf("%lld\n", ans);
        recover();
    }
    return 0;
}

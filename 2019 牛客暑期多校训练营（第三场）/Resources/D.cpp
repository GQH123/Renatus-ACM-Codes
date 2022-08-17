#include <bits/stdc++.h>
#include <map>
#include <tr1/unordered_map>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 100005
#define maxr 100000
#define pii pair<int, int>
#define list LIST
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;
using namespace std::tr1;
 
char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
    char ch = gc(); x = 0; bool f = 1;
    while (ch != '-' && !('0' <= ch && ch <= '9')) ch = gc();
    if (ch == '-') f = 0, ch = gc();
    while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
    x = (f) ? x : -x;
}
typedef long long ll;
/*typedef long long ll;
typedef pair<int, int>P;
int phi(int n){
    int t = 1, i;
    for (i = 2; i * i <= n;i++) if (n % i == 0) for (n /= i, t *= i - 1; n % i == 0; n /= i, t *= i);
    if (n > 1) t *= n - 1;
    return t;
}
int pow(ll a, int b, int m) {ll t = 1; for (; b; b >>= 1, a = a * a % m) if (b & 1) t = t * a % m; return t;}
int bsgs(int a, int r, int m){
    if (r >= m) return -1;
    int i, g, x, c = 0, at = int(2 + sqrt(m));
    for (i = 0, x = 1 % m; i < 50; i++, x = ll(x) * a % m) if (x == r) return i;
    for (g = x = 1; __gcd(int(ll(x) * a % m), m) != g; c++) g = __gcd(x=ll(x)*a%m, m);
    if (r % g) return -1;
    if (x == r) return c;
    unordered_map<int, int> u;
    g = phi(m / g), u[x] = 0, g = pow(a, g - at % g, m);
    for (i = 1; i < at; i++){
        u.insert(P(x=ll(x)*a%m, i));
        if (x = r) return c+i;
    }
    for(i = 1; i < at; i++){
        unordered_map<int, int>::iterator t = u.find(r=ll(r)*g%m);
        if (t!=u.end()) return c+i * at + t -> second;
    }
    return -1;
}*/
int power(int a, int b, int p){
    int ans = 1, con = a;
    while (b){
        if (b & 1) ans = (ll)ans * con % p;
        con = (ll)con * con % p;
        b >>= 1;
    }
    return ans;
}
int get_min_x(int p){
    int n = p - 1;
    int mi = -1;
    rep(i, 1, n){
        if (i * i > n) return mi;
        if (n % i == 0){
            if (power(10, i, p) == 1) return i;
            if (i * i != n && power(10, n / i, p) == 1) mi = n / i;
        }
    }
    return mi;
}
 
int p, n, m;
bool vis[maxn];
int pri[maxn], cnt = 0;
void init_p(){
    srep(i, 2, maxn){
        if (!vis[i]) pri[++cnt] = i;
        rep(j, 1, cnt){
            if (i * pri[j] >= maxn) break;
            vis[i * pri[j]] = 1;
            if (i % pri[j] == 0) break;
        }
    }
}
int mu(int x){
    int ans = 1;
    rep(i, 1, cnt){
        if (pri[i] * pri[i] > x) break;
        bool f = 0;
        while (x % pri[i] == 0) {
            if (f) return 0;
            f = 1; x /= pri[i];
        }
        if (f) ans = -ans;
    }
    if (x != 1) ans = -ans;
    return ans;
}
ll Q(int n, int x){//d yi nei yu x hu zhi de ge shu
    ll ans = 0;
    rep(d, 1, x){
        if (d * d > x) return ans;
        if (x % d == 0) {
            ans += (ll)mu(d) * (n / d);
            if (d * d < x) ans += (ll)mu(x / d) * (n / (x / d));
        }
    }
    return ans;
}
int GCD(int x, int y){//x > y;
    return (!y) ? x : GCD(y, x % y);
}
pii list[maxn];
int cl = 0;
void dev(int x){
    cl = 0;
    rep(i, 1, cnt){
        if (pri[i] * pri[i] > x) break;
        pii op = pii(0, 0);
        bool f = 0;
        while (x % pri[i] == 0) f = 1, x /= pri[i], op.second++;
        if (f) op.first = pri[i], list[++cl] = op;
    }
    if (x > 1) list[++cl] = pii(x, 1);
}
ll f(int d){
    /*ll now = d, _gcd = -1, gcd, ans = 1;
    while(1){
        gcd = GCD(x, now);
        if (gcd == _gcd) break;
        now *= d, ans++, _gcd = gcd;
    }
    if (gcd != x) return 0;
    else return m - (ans - 1) + 1;*/
    int mx = 0;
    rep(i, 1, cl){
        int pp = list[i].first;
        if (d % pp != 0) return 0;
        int k = 0;
        while (d % pp == 0) d /= pp, k++;
        mx = max(mx, (list[i].second - 1) / k + 1);
    }
    return max(0, m - mx + 1);
}
int main(){
    /*#ifndef ONLINE_JUDGE
        freopen("D.in", "r", stdin);
    #endif*/
    ios::sync_with_stdio(false);
    init_p();
    int T;
    //puts("T");
    //read(T);
    cin>>T;
    while (T--){
        //read(p), read(n), read(m);
        cin>>p>>n>>m;
        if (p == 2 || p == 5) {printf("0\n"); continue;}
        else if (p == 3) {printf("%lld\n", (ll)(n / 3) * m); continue;}
        //int x = bsgs(10, 1, p);
        int x = get_min_x(p);
        ll ans = 0;
        dev(x);
        /*rep(d, 1, x){
            if (d * d > x) break;
            if (x % d == 0) {
                int k = f(d);
                if (k) ans += k * Q(n / d, x);
                if (d * d != x && d != 1) {
                    k = f(x / d);
                    if (k) ans += k * Q(n / (x / d), x);
                }
            }
        }
        ans += (ll)(n / x) * m;
        */
        int P = -1, temp = 1;
        rep(d,1,m)
        {
            temp = 1;
            P = -1;
            rep(i, 1, cl)
            {
                temp = temp * power(list[i].first, (list[i].second - 1) / d + 1 , p);
                P = max((list[i].second - 1) / d + 1, P);
            }
            ans += n / temp;
            if(P == 1)
            {
                ans += (ll)(m - d) * (n / temp);
                break;
            }
        }
        printf("%lld\n", ans);
        cl = 0;
    }
    /*rep(i, 1, 10000) {
        printf("mu[%d] = %d\n", i, mu(i));
    }
    printf("mu[%d] = %d\n", 1685520234, mu(1685520234));*/
    return 0;
}

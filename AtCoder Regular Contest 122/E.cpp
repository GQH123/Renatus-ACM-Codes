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

#define maxn 220
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll __int128


ll gcd(ll a, ll b) {
    return !b ? a : gcd(b, a % b);
}
ll qpow(ll a, ll b, ll m) {
    ll ans = 1, con = a;
    while (b){
        if (b & 1) ans = ans * con % m;
        con = con * con % m;
        b >>= 1;
    }
    return ans;
}

ll qmul(ll a, ll b, ll m) { a %= m; b %= m;
ll r = a * b, s = (long double)a * b / m;
return ((r - m * s) % m + m) % m;
}
bool miller_rabin(ll n, ll base) {
ll n2 = n - 1, s = 0;
while(n2 % 2 == 0) n2 /= 2, s ++;
ll t = qpow(base, n2, n);
if(t == 1 || t == n - 1) return true;
for(s --; s >= 0; s --)
if((t = qmul(t, t, n)) == n - 1) return true;
return false;
}
bool is_prime(ll n) {
static ll base[] = {2,3,5,7,11,13,17,19,23,29,31,37};
if(n < 2) return false;
for(int i = 0; i < 12 && base[i] < n; i ++) {
if(!miller_rabin(n, base[i])) return false;
}
return true;
}

ll f(ll x, ll m) { return (qmul(x, x, m) + 1) % m; }
ll rho(ll n) {
if(is_prime(n)) return n;
if(n % 2 == 0) return 2;
for(int i = 1; ; i ++) {
ll x = i, y = f(x, n), p = __gcd(y - x, n);
while(p == 1) { x = f(x, n); y = f(f(y, n), n);
p = __gcd((y - x + n) % n, n) % n;
}
if(p != 0 && p != n) return p;
}}

vector<ll> lisa, lisb;
void factor2(ll x, vector<ll>& lis){
    if (x == 1) return;
    if (is_prime(x)) lis.pb(x);
    else {
        ll p = rho(x);
        factor2(p, lis), factor2(x / p, lis);
    }
}
bool cmp(ll a, ll b) {
    if (a % b == 0 || b % a == 0) return a < b;  
    ll d = gcd(a, b);
    a /= d, b /= d;
    lisa.clear(), lisb.clear();
    factor2(a, lisa), factor2(b, lisb);
    sort(lisa.begin(), lisa.end());
    sort(lisb.begin(), lisb.end());
    cerr << (long long)a << ":";  for (auto it: lisa) cerr << (long long)it << ' '; cerr << endl;
    cerr << (long long)b << ":";  for (auto it: lisb) cerr << (long long)it << ' '; cerr << endl;
    assert(!lisa.empty() && !lisb.empty());
    //if (lisa.empty()) lisa.pb(max(a, b) + 1);
    //if (lisb.empty()) lisb.pb(max(a, b) + 1); 
    return lisa[0] > lisb[0];
}
ll lcm(ll a, ll b){
    ll d = gcd(a, b);
    return a / d * b;
}

vector<ll> debug_lis;
void debug(ll a) {
    debug_lis.clear();
    factor2(a, debug_lis);
    sort(debug_lis.begin(), debug_lis.end());
    cerr << (long long)a << ":";  for (auto it: debug_lis) cerr << (long long)it << ' '; cerr << endl; 
}

int n; ll a[maxn];
int main(){
    read(n); rep(i, 1, n) read(a[i]);
    sort(a + 1, a + 1 + n, cmp);
    rep(i, 1, n) cerr << (long long)a[i] << ' '; cerr << endl;
    
    cerr << endl;
    rep(i, 1, n) debug(a[i]);
    
    
    
    rep(i, 1, n) {
        ll tmp = 1;
        srep(j, 1, i) {
            tmp = lcm(tmp, gcd(a[j], a[i]));
        }
        if (tmp % a[i] == 0) {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    rep(i, 1, n) printf("%lld ", (long long)a[i]);
	return 0;
}


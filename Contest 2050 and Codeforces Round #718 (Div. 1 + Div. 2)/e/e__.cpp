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
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 998244353
#define ll long long int 

int n, a[maxn];

ll play0(){ 
    ll sump = 0, sumc = 0;
    rep(i, 1, n) sumc += a[i];
    int p = 1;
    while (p <= n && sumc >= sump) sumc -= a[p], sump += a[p], p++;
    return n + 1 - p; // not contain all Ps
}


int preodd[maxn];
int preeven[maxn];
void init(){
    for (int i = 1; i <= n; i += 2) preodd[i] = preodd[i - 2] + a[i];
    for (int i = 2; i <= n; i += 2) preeven[i] = preeven[i - 2] + a[i];
}
int lower_bound(int l, int r, int o) {
}

ll play1(){
    ll res = 0;

    ll sum = 0; rep(i, 1, n) sum += a[i];
    ll sumc = a[1]; int r = 1;
    while (r + 2 <= n && sumc < sum - sumc) { 
        r += 2;
        sumc += a[r];
    }
    res += (r >> 1);
    if (sumc < sum - sumc) res++;
    for (int l = 2; l <= n; l += 2) {
        sumc += a[l];
        while (r && sumc >= sum - sumc) sumc -= a[r], r -= 2;
        if (r < l) break;
        res += (r - l + 1) >> 1;
    }
    
    if (n >= 2) {
        r = 2; sumc = a[1] + a[2];
        while (r + 2 <= n && sumc < sum - sumc) { 
            r += 2;
            sumc += a[r];
        }
        res += (r >> 1) - 1;
        if (sumc < sum - sumc) res++;
        for (int l = 3; l <= n; l += 2) {
            sumc += a[l];
            while (r && sumc >= sum - sumc) sumc -= a[r], r -= 2;
            if (r < l) break;
            res += (r - l + 1) >> 1;
        }
    }
    
    return res;
}


int _a[maxn];
ll play2(){
    if (n < 3) return 0;
    ll res = 0;

    ll sum = 0; rep(i, 1, n) sum += a[i], _a[i] = a[i];
    srep(i, 1, n) a[i] = a[i + 1]; a[n] = a[0] = 0; n--;
    
    
    ll sumc = a[1]; int r = 1;
    while (r + 2 <= n && sumc < sum - sumc) { 
        r += 2;
        sumc += a[r];
    }
    res += (r >> 1);
    if (sumc < sum - sumc) res++;
    for (int l = 2; l <= n; l += 2) {
        sumc += a[l];
        while (r && sumc >= sum - sumc) sumc -= a[r], r -= 2;
        if (r < l) break;
        res += (r - l + 1) >> 1;
    }
    
    if (n > 2) {
        r = 2; sumc = a[1] + a[2];
        while (r + 2 <= n && sumc < sum - sumc) { 
            r += 2;
            sumc += a[r];
        }
        res += (r >> 1) - 1;
        if (sumc < sum - sumc) res++;
        for (int l = 3; l <= n; l += 2) {
            sumc += a[l];
            while (r && sumc >= sum - sumc) sumc -= a[r], r -= 2;
            if (r < l) break;
            res += (r - l + 1) >> 1;
        }
    }
    
    n++; rep(i, 1, n) a[i] = _a[i]; a[0] = a[n + 1] = 0;
    return res;
}

ll play3(){
    if (n < 3) return 0;
    ll res = 0;

    ll sum = 0; rep(i, 1, n) sum += a[i]; n--;

    ll sumc = a[1] + a[n + 1]; int r = 1;
    while (r + 2 <= n - 2 && sumc < sum - sumc) { 
        r += 2;
        sumc += a[r];
    }
    res += (r >> 1);
    if (sumc < sum - sumc) res++;
    for (int l = 2; l <= n - 2; l += 2) {
        sumc += a[l];
        while (r && sumc >= sum - sumc) sumc -= a[r], r -= 2;
        if (r < l) break;
        res += (r - l + 1) >> 1;
    }
    
    r = 2; sumc = a[1] + a[2] + a[n + 1];
    while (r + 2 <= n - 2 && sumc < sum - sumc) { 
        r += 2;
        sumc += a[r];
    }
    res += (r >> 1) - 1;
    if (sumc < sum - sumc) res++;
    for (int l = 3; l <= n - 2; l += 2) {
        sumc += a[l];
        while (r && sumc >= sum - sumc) sumc -= a[r], r -= 2;
        if (r < l) break;
        res += (r - l + 1) >> 1;
    }
    
    n++;
    return res;
}

ll play4(){
    if (n < 4) return 0;
    ll res = 0;

    ll sum = 0; rep(i, 1, n) sum += a[i], _a[i] = a[i];
    srep(i, 1, n) a[i] = a[i + 1]; a[n] = a[0] = 0; n--;
    
    
    ll sumc = a[1] + _a[n]; int r = 1;
    while (r + 2 <= n - 2 && sumc < sum - sumc) { 
        r += 2;
        sumc += a[r];
    }
    res += (r >> 1);
    if (sumc < sum - sumc) res++;
    for (int l = 2; l <= n - 2; l += 2) {
        sumc += a[l];
        while (r && sumc >= sum - sumc) sumc -= a[r], r -= 2;
        if (r < l) break;
        res += (r - l + 1) >> 1;
    }
    
    r = 2; sumc = a[1] + a[2] + _a[n];
    while (r + 2 <= n - 2 && sumc < sum - sumc) { 
        r += 2;
        sumc += a[r];
    }
    res += (r >> 1) - 1;
    if (sumc < sum - sumc) res++;
    for (int l = 3; l <= n - 2; l += 2) {
        sumc += a[l];
        while (r && sumc >= sum - sumc) sumc -= a[r], r -= 2;
        if (r < l) break;
        res += (r - l + 1) >> 1;
    }
    
    n++; rep(i, 1, n) a[i] = _a[i]; a[0] = a[n + 1] = 0;
    return res;
}

int main(){
    int T; read(T);
    while (T--){
        read(n); rep(i, 1, n) read(a[i]);
        printf("%lld\n", play0() + play1() + play2() + play3() + play4()); 
        rep(i, 0, n + 5) a[i] = 0;
    }
	return 0;
}


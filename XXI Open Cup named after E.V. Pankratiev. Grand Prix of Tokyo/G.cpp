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

#define maxn 1000020
#define maxm
#define maxs
#define maxb 7
#define inf 
#define eps
#define M 998244353
#define ll long long int 
#define mo(x) (x = (x >= M) ? (x - M) : x)
#define int ll

int power(int x, int y){
    int ans = 1, con = x;
    while (y) {
        if (y & 1) ans = 1ll * ans * con % M;
        y >>= 1;
        con = 1ll * con * con % M;
    }
    return ans;
}
int getinv(int x) {
    return power(x, M - 2);
}

int g = 14553391;
int invg_1 = getinv(g - 1);
int invg = getinv(g);
int mi[10];
int invmi[10];
int n, K;

int tmp[10];
void RFWT(int* v, int op = 1){
    int step = 1;
    for (int i = 0; i < maxb; i++) {
        for (int j = 0; j < 823543; j += 7 * step){ 
            for (int k = j; k < j + step; k++) {    
                int ptr = 0;
                for (int l = k; l < k + 7 * step; l += step) tmp[ptr++] = v[l]; 
                if (op == 1) {
                    ptr = 0;
                    for (int l = k; l < k + 7 * step; l += step){
                        v[l] = 0;
                        srep(m, 0, 7) {
                            v[l] += 1ll * tmp[m] * mi[m * ptr % 7] % M;
                            mo(v[l]);
                        }
                        ptr++; 
                    } 
                }
                else{
                    ptr = 0;
                    for (int l = k; l < k + 7 * step; l += step){
                        v[l] = 0;
                        srep(m, 0, 7) {
                            v[l] += 1ll * tmp[m] * invmi[m * ptr % 7] % M;
                            mo(v[l]);
                        }
                        ptr++; 
                    } 
                } 
            }
        }
        step *= 7;
    }
    if (op == -1) {
        int inv = getinv(823543);
        for (int i = 0; i < 823543; i++) v[i] = 1ll * v[i] * inv % M;
    }
}

void process(int* v, int K){
    for (int j = 0; j < 823543; j++) v[j] = power(v[j], K);
}

void RFWT_From(int* v){
    int step = 117649;
    for (int i = maxb - 1; i >= 0; i--){
        for (int j = 0; j < 823543; j += 7 * step){ 
            for (int k = j; k < j + step; k++) {
                /*
                int a = v[k], b = v[k + step], ptr = 0;
                for (int l = k; l < k + 7 * step; l += step){
                    if (ptr >= 2) v[l] = 0;
                    if (ptr == 1) {
                        v[l] = 1ll * (b + M - a) * invg_1 % M;
                    }
                    if (ptr == 0) {
                        v[l] = 1ll * (1ll * g * a % M + M - b) % M * invg_1 % M;
                    }
                    ptr++;
                } 
                */
                int ptr = 0;
                for (int l = k; l < k + 7 * step; l += step) tmp[ptr++] = v[l];
                
                ptr = 0;
                for (int l = k; l < k + 7 * step; l += step){
                    /*
                    if (ptr >= 2) {
                        assert(v[l] == 0);
                    }
                    */
                    v[l] = 0;
                    srep(m, 0, 7) {
                        v[l] += 1ll * tmp[m] * mi[m * ptr % 7] % M;
                        mo(v[l]);
                    }
                    ptr++;
                    //v[l] = (a + 1ll * b * mi[ptr++] % M) % M;   
                }
            }
        }
        step /= 7;
    }
}

int trans(int x) {
    int y = 0, e = 1;
    srep(i, 0, maxb) {
        if (x & (1 << i)) {
            y += e;
        }
        e = e * 7;
    }
    return y;
}

int a[maxn];
int v[maxn], _v[maxn];

signed main(){
    /*
    srep(i, 2, M) {
        if (power(i, 7) == 1) {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("Fuck!");
    */
    mi[0] = 1; mi[1] = g;
    rep(i, 2, 6) mi[i] = 1ll * mi[i - 1] * g % M;
    invmi[0] = 1;
    rep(i, 1, 6) invmi[i] = 1ll * invmi[i - 1] * invg % M;
    
    read(n, K); rep(i, 1, n) read(a[i]), v[trans(a[i])] = 1;
    RFWT(v, 1), process(v, K), RFWT(v, -1);
    /*
    RFWT_To(v); 
    process(v, K);
    srep(i, 0, 823543) _v[i] = v[i];
    RFWT_From(v);
    RFWT_To(v);
    */
    /*
    srep(i, 0, 823543) {
        if (_v[i] != v[i]) {printf("%lld\n", i); assert(false);}
    }
    */
    printf("%lld\n", v[0]);
	return 0;
}


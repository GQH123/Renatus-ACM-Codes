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

#define maxn 220
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 998244353
#define ll long long int 
#define mo(x) (x = (x >= M) ? (x - M) : x)

int power(int x, int y) {
    int ans = 1, con = x;
    while (y){
        if (y & 1) ans = 1ll * ans * con % M;
        y >>= 1;
        con = 1ll * con * con % M;
    }
    return ans;
}
int getinv(int x){
    return power(x, M - 2);
}

int n, m, a[maxn], b[maxn];
int w[maxn][maxn];

void work1(){
    read(n, m);
    int sum = 0;
    rep(i, 1, n) read(a[i]), sum += a[i], mo(sum);
    rep(i, 1, m) read(b[i]);
    int ans = n;
    rep(i, 1, n) rep(j, 1, m) {
        w[i][j] = 1ll * b[j] * getinv(a[i] + b[j]) % M;
        //ans += 1ll * b[j] * getinv(sum + b[j]) % M;
        //mo(ans);
    }
    
    rep(j, 1, m) {
        int tmp = 1;
        rep(i, 1, n) {
            tmp = 1ll * tmp * (1 + M - w[i][j]) % M;
        }
        ans += 1 + M - tmp, mo(ans);
    }
    printf("%d\n", ans);
}

void work2(){
    read(n, m);
    int sum = 0;
    rep(i, 1, n) read(a[i]), sum += a[i], mo(sum);
    rep(i, 1, m) read(b[i]);
    int ans = n;
    rep(i, 1, n) rep(j, 1, m) {
        ans += 1ll * b[j] * getinv(a[i] + b[j]) % M;
        mo(ans);
    }
    printf("%d\n", ans);
}

int dp[maxn][maxn * maxn];
bool vis[maxn][maxn * maxn];
int DP(int pos, int num) {
    if (pos == n + 1) return !num;
    if (vis[pos][num]) return dp[pos][num];
    vis[pos][num] = 1;
    int& ans = dp[pos][num]; ans = 0;
    if (num >= a[pos]) ans += DP(pos + 1, num - a[pos]), mo(ans);
    ans += DP(pos + 1, num);
    mo(ans);
    return ans;
}
int nnum[maxn * maxn];
void work3(){
    read(n, m);
    int sum = 0;
    rep(i, 1, n) read(a[i]), sum += a[i];
    rep(i, 1, m) read(b[i]);
    rep(i, 1, sum) nnum[i] = DP(1, i);
    int ans = n;
    rep(i, 1, sum) {
        rep(j, 1, m) {
            ans += 1ll * nnum[i] * b[j] % M * getinv(i + b[j]) % M;
            mo(ans);
        }
    }
    printf("%d\n", ans);
}

void work4(){
    read(n, m);
    int sumb = 0, sum = 0;
    rep(i, 1, n) read(a[i]), sum += a[i];
    rep(i, 1, m) read(b[i]), sumb += b[i];
    int ans = n;
    rep(j, 1, 
    printf("%d\n", ans);
}

int main(){

       work3();
	return 0;
}


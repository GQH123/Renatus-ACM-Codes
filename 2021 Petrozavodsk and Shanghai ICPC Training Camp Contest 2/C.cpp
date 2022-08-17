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

#define maxn 200020
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 998244353
#define ll long long int 

int cp = 0, vis[maxn], pri[maxn];

int getphi(int x){
	int res = 1;
	rep(i, 1, cp) {
		if (x % pri[i] == 0) {
			res *= pri[i] - 1; x /= pri[i];
			while (x % pri[i] == 0) x /= pri[i], res *= pri[i];
		}
	}
	if (x > 1) res *= x - 1;
	return res;
}
void init(){
	srep(i, 2, maxn) {
		if (!vis[i]) pri[++cp] = i;
		rep(j, 1, cp) {
			if (i * pri[j] >= maxn) break;
			vis[i * pri[j]] = 1;
			if (i % pri[j] == 0) break;
		}
	}
}
int power(int x, int y) {
	int ans = 1, con = x;
	while (y){
		if (y & 1) ans = 1ll * ans * con % M;
		con = 1ll * con * con % M;
		y >>= 1;
	}
	return ans;
}
int getinv(int x) {
	return power(x, M - 2);
}
int C(int n, int m) {
	if (m > n) return 0;
	int up = 1;
	rep(i, 1, m) up = 1ll * up * (n - i + 1) % M;
	int down = 1;
	rep(i, 1, m) down = 1ll * down * i % M;
	return 1ll * up * getinv(down) % M;
}

int n, k;
int main(){
	init();
	read(n, k);
	printf("%lld", 1ll * getphi(n) * C(n - 1, k - 1) % M);
	return 0;
}


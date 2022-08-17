#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, r, l) for (int i = r; i >= l; i--)
#define srep(i, l, r) for (int i = l; i < r; i++)
#define sper(i, r, l) for (int i = r; i > l; i--)
#define erep(i, x) for (int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (int& i = cur[x]; i; i = e[i].next)
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
#define maxbuf 2000020
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxbuf, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

namespace Fast_Read{
    char buffer[maxbuf], *p1, *p2;
    template<class T> void read_signed(T& x){
        char ch = gc(); x = 0; bool f = 1;
        while (!isdigit(ch) && ch != '-') ch = gc();
        if (ch == '-') f = 0, ch = gc();
        while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
        x = (f) ? x : -x;
    }
    template<class T, class... Args> void read_signed(T& x, Args&...args){
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

#define maxn 2000021
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 1000000007
#define ll long long int 

int fac[maxn], ifac[maxn], inv[maxn];
void init(){
	fac[0] = ifac[0] = inv[1] = 1;
	srep(i, 1, maxn) fac[i] = 1ll * fac[i - 1] * i % M;
	srep(i, 2, maxn) inv[i] = M - 1ll * M / i * inv[M % i] % M;
	srep(i, 1, maxn) ifac[i] = 1ll * ifac[i - 1] * inv[i] % M;
}

int lis[maxn];
int all[maxn]; int ca = 0;
int main(){
	init();
	int n, m;
	rep(n, 1, 8) {
		ca = 0;
		rep(i, 1, n) lis[i] = i;
		do{
			rep(i, 1, n) all[++ca] = lis[i];
		}while (next_permutation(lis + 1, lis + 1 + n));
		//rep(i, 1, ca) cerr << all[i] << ' '; cerr << endl;
		set<int> s;
		rep(m, 1, n) {
			int ans = 0;
			rep(i, 1, ca - m + 1) {
				rep(j, 1, m) s.insert(all[i + j - 1]);  
				if (s.size() == m && *s.begin() == 1 && *(--s.end()) == m) {
					ans++;
				}
				s.clear();
			}
			printf("n = %d, m = %d: %d, %d\n", n, m, ans, ans - fac[m] * fac[n - m + 1]);
		}
	}
	return 0;
}


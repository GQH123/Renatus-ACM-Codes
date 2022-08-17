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

#define maxn
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

int f[10], F[10], a[10], res[10];
int mi[10][10];
int main(){
	int T; read(T);
	rep(i, 1, 5) {
		ll x = 1;
		rep(j, 0, 4) {
			mi[i][j] = x;
			x *= i;
		}
	}
	while (T--){
		rep(i, 1, 5) read(f[i]);
		rep(i, 1, 5) res[i] = 0; 
		for (a[4] = -100; a[4] <= 100; a[4]++) {
			for (a[3] = -100; a[3] <= 100; a[3]++) {
				for (a[2] = -100; a[2] <= 100; a[2]++) {
					rep(i, 1, 5) res[i] = 0;
					rep(i, 1, 5) rep(j, 2, 4) res[i] += a[j] * mi[i][j];
					for (F[1] = f[1] - 1; F[1] <= f[1] + 1; F[1]++) {
						for (F[2] = f[2] - 1; F[2] <= f[2] + 1; F[2]++) {
							
							int rest1 = F[1] - res[1];
							int rest2 = F[2] - res[2];
							a[1] = rest2 - rest1;
							a[0] = rest1 - a[1];
							
							if (a[1] < -100 || a[1] > 100 || a[0] < -100 || a[0] > 100) continue;
							rep(i, 3, 5) {
								F[i] = i * a[1] + a[0] + res[i];
								if (abs(F[i] - f[i]) > 1) goto fail;
							}
							rep(i, 0, 4) printf("%d ", a[i]);  printf("\n");
							goto ok;
							fail:;
						}
					}
				}
			}
		}
		ok:;
	}
	return 0;
}


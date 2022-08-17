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

#define read read_unsigned
#define reads read_string 
#define writes puts

#define maxn 20
#define maxm
#define maxs
#define maxb
#define inf 
#define eps 1e-8
#define M 
#define ll long long int 

ll num[maxn][maxn];
ll ans[10];

void gcd(ll* x, ll* y, int p){
	if (!y[p]) return;
	int d = x[p] / y[p];
	rep(i, p, 6) x[i] -= y[i] * d;
	gcd(y, x, p);
}
bool solve(){
	int now = 1;
	rep(j, 1, 5) {
		int f = -1;
		rep(i, now, 5) {
			if (num[i][j]) {
				f = i;
				break;
			}
		}
		if (f == -1) continue;
		rep(k, 1, 6) swap(num[now][k], num[f][k]);
		if (num[now][j] < 0) rep(k, 1, 6) num[now][k] = -num[now][k];
		rep(i, 1, 5) {
			if (i == now) continue;
			if (num[now][j] < 0) rep(k, 1, 6) num[now][k] = -num[now][k];
			if (num[i][j] < 0) rep(k, 1, 6) num[i][k] = -num[i][k];
			gcd(num[i], num[now], j);
			/*
			long double d = num[i][j] / num[now][j];
			rep(k, j, 6) {
				num[i][k] -= d * num[now][k];
			}
			*/
			if (!num[now][j]) rep(k, 1, 6) swap(num[i][k], num[now][k]);
			if (num[now][j] < 0) rep(k, 1, 6) num[now][k] = -num[now][k];
		}
		now++;
	}
	rep(i, 1, 5) {
		int f = 0;
		rep(j, 1, 5) {
			if (num[i][j]) {
				f++;
				if (f == 2) return false;
				if (num[i][j] < 0) num[i][j] = -num[i][j], num[i][6] = -num[i][6];
				if (num[i][6] % num[i][j] != 0) return false;
				ans[i] = num[i][6] / num[i][j];
				if (ans[i] > 100 || ans[i] < -100) return false;
			}
		}
		if (!f) return false;
	}
	return true;
}
ll f[10];

int main(){
	int T; read(T);
	while (T--){
		rep(i, 1, 5) read(f[i]); 
		srep(S, 0, 243) {
			rep(i, 1, 5) {
				int x = 1;
				per(j, 5, 1) {
					num[i][j] = x;
					x *= i;
				}
			}
			int x = S;
			rep(i, 1, 5) {
				if (x % 3 == 0) {
					num[i][6] = f[i];
				} 
				else if (x % 3 == 1) {
					num[i][6] = f[i] + 1;
				}
				else {
					num[i][6] = f[i] - 1;
				}
				x /= 3;
			}
			if (solve()) {
				per(i, 5, 1) printf("%lld ", ans[i]); printf("\n");
				goto ok;
			}
		}
		assert(false);
		ok:;
	}
	return 0;
}


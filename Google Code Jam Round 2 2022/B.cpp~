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

#define maxn 2022
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 


int R;



bool g[maxn << 1 | 1][maxn << 1 | 1], g2[maxn << 1 | 1][maxn << 1 | 1];

ll roundd(ll x) { // round(sqrt(x))
	ll d = (ll)sqrt(x);
	if ((d + 1) - (double)sqrt(x) < (double)sqrt(x) - d) return d + 1;
	return d;
}

void setp(bool g[][maxn << 1 | 1], int x, int y) {
	g[x + R][y + R] = 1;
}
bool getp(bool g[][maxn << 1 | 1], int x, int y) {
	return g[x + R][y + R];
}
void recp(bool g[][maxn << 1 | 1], int x, int y) {
	g[x + R][y + R] = 0;
}

void drawp(bool g[][maxn << 1 | 1], int r){
	rep(x, -r, r) {
		ll y = roundd((ll)r * r - x * x);
		
		setp(g, x, y);
		setp(g, x, -y);
		setp(g, y, x);
		setp(g, -y, x);
	}
}
void drawc(bool g[][maxn << 1 | 1], int r) {
	rep(x, -r, r) {
		rep(y, -r, r) {
			if (roundd((ll)x * x + y * y) <= r) setp(g, x, y);
		}
	}
}

void debug(bool g[][maxn << 1 | 1], int r) {
	printf("\n");
	rep(x, -r, r) {
		rep(y, -r, r) {
			printf("%d", getp(g, x, y));
		}
		printf("\n");
	} 
}

void recover(bool g[][maxn << 1 | 1], int r){
	rep(x, -r, r) {
		rep(y, -r, r) {
			recp(g, x, y);
		}
	}
}

int main(){
	int T; read(T);
	rep(__, 1, T){
		printf("Case #%d: ", __); //printf("\n");
		read(R);
		rep(r, 0, R) drawp(g, r);
		drawc(g2, R);
		
		//debug(g, R), debug(g2, R);
		
		int res = 0;
		rep(x, -R, R) {
			rep(y, -R, R) {
				if (getp(g, x, y) != getp(g2, x, y)) res++;
			}
		}
		
		recover(g, R), recover(g2, R);
		printf("%d\n", res);
	}
	return 0;
}


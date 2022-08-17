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

#define maxn
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 998244353
#define ll long long int 

extern int getroot();
const int g = getroot();
int power(int x, int y){
	int ans = 1, con = x;
	while (y){
		if (y & 1) ans = (ll)ans * con % M;
		con = (ll)con * con % M;
		y >>= 1;
	}
	return ans;
}
int getinv(int x){
	return power(x, M - 2);
}
int pri[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
int cpri = 11;
int getroot(){
	srep(i, 0, cpri){
		int p = pri[i], con = (int)sqrt(M - 1); bool f = 1;
		rep(j, 2, con){
			if ((M - 1) % j) continue;
			if (power(p, j) == 1 || power(p, (M - 1) / j) == 1) {f = 0; break;}
		}
		if (f) return p;
	}
	assert(false);
	return -1;
}
int bitrev[maxn << 2];
void init(int bit){	
	srep(i, 1, (1 << bit)) bitrev[i] = bitrev[i >> 1] >> 1 | ((i & 1) << (bit - 1));
}
int mi[30][2];
void NTT(int* a, int n, int dft){
	srep(i, 0, n) if (bitrev[i] > i) swap(a[i], a[bitrev[i]]);
	for (register int step = 1, s = 0; step < n; step <<= 1, s++){
		int wn = mi[s][(dft == 1) ? 1 : 0];
		for (register int i = 0; i < n; i += (step << 1)){
			int wnk = 1;
			for (register int j = i; j < i + step; j++){
				int x = a[j], y = (ll)wnk * a[j + step] % M;
				a[j] = x + y, mo(a[j]);
				a[j + step] = x + M - y, mo(a[j + step]);
				wnk = (ll)wnk * wn % M;
			}
		}
	}
	if (dft == -1) {int invn = getinv(n); srep(i, 0, n) a[i] = (ll)a[i] * invn % M;} 
}
void init(){
	srep(s, 0, 23) mi[s][1] = power(g, (M - 1) / (1 << (s + 1))), mi[s][0] = getinv(mi[s][1]); 
}

int n, m, a[maxn << 2], b[maxn << 2];

/*
int main(){

		freopen("NumberTheoryTransform.in", "r", stdin);
		
	init();
	
	scanf("%d%d", &n, &m);
	rep(i, 0, n) scanf("%d", a + i);
	rep(i, 0, m) scanf("%d", b + i);
	int len = n + m + 2, s = 0;	
	while (len) len >>= 1, s++;
	len = (1 << s), init(s);
	NTT(a, len, 1), NTT(b, len, 1);
	srep(i, 0, len) a[i] = (ll)a[i] * b[i] % M;
	NTT(a, len, -1);
	rep(i, 0, n + m) printf("%d ", a[i]);
	return 0;
}
*/

int main(){
    
	return 0;
}


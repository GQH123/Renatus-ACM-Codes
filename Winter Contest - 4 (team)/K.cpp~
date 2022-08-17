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
    #define isletter(ch) ('0' <= ch && ch <= '1')
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

#define maxn 2000020
#define maxm
#define maxM 3
#define maxs
#define maxb
#define inf 
#define eps 
#define ll long long int 
#define bas 2333

int M[] = {19260817, 1000000007, 1000000009};
int mi[maxM][maxn];

int n;
int all[maxn];
vector<int> s[maxn];

char _s[maxn];


int power(int x, int y, int M) {
	int ans = 1, con = x;
	while (y){
		if (y & 1) ans = 1ll * ans * con % M;
		con = 1ll * con * con % M;
		y >>= 1;
	}
	return ans;
}
int getinv(int x, int M){
	return power(x, M - 2, M);
}

void init(int* mi, int& rev, int n, int M){
	mi[0] = 1; rep(i, 1, n) mi[i] = 1ll * bas * mi[i - 1] % M;
	rev = getinv(bas, M);
}
int has[maxM], rev[maxM], _has[maxM];
void gethas(int& has, int n, int M){
	has = 0; srep(i, 0, n) has = (1ll * bas * has + all[i]) % M; 
}
int res[maxM];
void add(int pos, int d, int n, int T) {
	res[T] = 1ll * res[T] * rev[T] % M[T];
	res[T] += 1ll * mi[T][n - 1] * d % M[T];
	res[T] %= M[T];
}
void updhas(int& has, int p, int v, int T){
	has += 1ll * v * mi[T][p] % M[T];
	has %= M[T];
}
int main(){
	read(n);
	int sum = 0;
	rep(i, 1, n) {
		int l = reads(_s);
		sum = max(sum, l);
		srep(j, 0, l) s[i].pb(_s[j] - '0');
	}
	srep(i, 0, sum) all[i] = 0;
	
	rep(i, 1, n) {
		int pos = 0;
		for (auto it : s[i]) {
			if (it) all[pos] ^= 1;
			pos++;
		}
	}
	srep(T, 0, maxM) init(mi[T], rev[T], sum, M[T]), gethas(has[T], sum, M[T]), _has[T] = has[T];
	
	ll out = 0;
	rep(i, 1, n) {
		int l = s[i].size(), ptr = 0;
		srep(T, 0, maxM) res[T] = 0, has[T] = _has[T];
		per(j, l - 1, 1) {
			if (s[i][j] == 1) srep(T, 0, maxM) updhas(has[T], sum - 1 - j, all[j] ? M[T] - 1 : 1, T); 
			srep(T, 0, maxM) add(ptr, s[i][j], sum, T); 
			int addd = 1;
			srep(T, 0, maxM) addd &= (res[T] == has[T]);
			ptr++;
			out += addd;
		}
	}
	printf("%lld\n", out);
	return 0;
}


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
#define mo(x) (x = (x >= M) ? (x - M) : x)
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

#define maxn 15
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 1000000007
#define ll long long int 

struct mat{
	int r, c, num[2][2];
};
mat operator * (mat a, mat b) {
	mat c;
	c.r = a.r, c.c = b.c;
	srep(i, 0, c.r) srep(j, 0, c.c) c.num[i][j] = 0;
	srep(i, 0, a.r) srep(j, 0, b.c) srep(k, 0, a.c) {
		c.num[i][j] += 1ll * a.num[i][k] * b.num[k][j] % M, mo(c.num[i][j]);
	}
	return c;
}
mat power(mat x, int y) {
	mat ans, con;
	ans.r = ans.c = con.r = con.c = x.r;
	srep(i, 0, con.r) srep(j, 0, con.c) ans.num[i][j] = 0;
	srep(i, 0, ans.r) ans.num[i][i] = 1;
	srep(i, 0, con.r) srep(j, 0, con.c) con.num[i][j] = x.num[i][j];
	while (y) {	
		if (y & 1) ans = ans * con;
		con = con * con;
		y >>= 1;
	}
	return ans;
}

int n, m;

int res4[] = {0, 10, 100, 44, 18, 14};

int cal(int n) {
	if (n == 1) return 2;
	mat dp, trans;
	dp.r = 1, dp.c = 2, dp.num[0][0] = 2, dp.num[0][1] = 2;
	trans.r = trans.c = 2, trans.num[0][0] = trans.num[0][1] = trans.num[1][0] = 1;
	trans.num[1][1] = 0;
	trans = power(trans, n - 1);
	dp = dp * trans;
	return dp.num[0][0];
}
int main(){
	int T; read(T);
	while (T--){
		read(n, m);
		if (n > m) swap(n, m);
		if (n <= 2) {
			int d = cal(m);
			printf("%d\n", (n == 2) ? 1ll * d * d % M : d);
		}
		if (n == 3) {
			if (m == 3) {
				printf("32\n");
			}
			else {
				int d = cal(m - 2);
				printf("%d\n", (1ll * 10 * d + 4) % M);
			}
		}
		if (n == 4) {
			printf("%d\n", res4[min(5, m)]);
		}
		if (n >= 5) {
			printf("8\n");
		}
	}
	return 0;
}


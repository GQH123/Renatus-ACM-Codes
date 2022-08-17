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

#define maxm 200021
#define maxs
#define maxb
#define inf 
#define eps
#define M 998244353
#define ll long long int
#define mo(x) (x = x >= M ? x - M : x)

#define maxn 211

struct mat{
	int num[maxn][maxn];
	int r, c;
	mat(){
		r = 0, c = 0;
		memset(num, 0, sizeof num);
	}
	void operator = (const mat b) {
		r = b.r, c = b.c;
		rep(i, 1, r) rep(j, 1, c) num[i][j] = b.num[i][j];
	}
};
mat operator * (mat a, mat b) {
	mat c;
	c.r = a.r, c.c = b.c;
	rep(i, 1, a.r) {
		rep(j, 1, b.c) {
			rep(k, 1, a.c) {	
				c.num[i][j] += 1ll * a.num[i][k] * b.num[k][j] % M;
				mo(c.num[i][j]);
			}
		}
	}
	return c;
}
mat power(mat x, int y) {
	mat ans, con = x;
	ans.r = ans.c = x.r;
	rep(i, 1, ans.r) ans.num[i][i] = 1;
	while (y) {
		if (y & 1) ans = ans * con;
		con = con * con;
		y >>= 1;
	}
	return ans;
}

int power2(int x, int y) {
	int ans = 1, con = x;
	while (y) {
		if (y & 1) ans = 1ll * ans * con % M;
		con = 1ll * con * con % M;
		y >>= 1;
	}
	return ans;
}
int getinv(int x) { return power2(x, M - 2); }

int n, m, k, deg[maxn];

struct edge{
	int x, y, z;
	edge(int x, int y, int z) : x(x), y(y), z(z){}
	edge(){}
}e[maxm];
void work(){
	read(n, m, k); rep(i, 1, n) deg[i] = 0;
	int x, y, z;
	rep(i, 1, m) {
		read(x, y, z), deg[x]++, deg[y]++, e[i] = edge(x, y, z);
	}
	
	mat trans;
	trans.r = trans.c = n << 1;
	mat dp;
	dp.r = 1, dp.c = n << 1;
	dp.num[1][n << 1] = 1;
	
	rep(i, 1, m) {
		x = e[i].x, y = e[i].y, z = e[i].z;
		int idx = getinv(deg[x]), idy = getinv(deg[y]);
		
		if (z) {
			trans.num[y][x + n] = idx, trans.num[x][y + n] = idy, 
			trans.num[y + n][x] = idx, trans.num[x + n][y] = idy;
		}
		else {
			trans.num[y][x] = idx, trans.num[x][y] = idy, 
			trans.num[y + n][x + n] = idx, trans.num[x + n][y + n] = idy;
		}
		
	}
	
	dp = dp * power(trans, k);
	
	printf("%d\n", dp.num[1][1]);
}

int main(){
	int T; read(T);
	while (T--) work();
	return 0;
}


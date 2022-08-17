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
    #define isletter(ch) ('T' == ch || ch == 'F')
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

#define maxn 40
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define mo(x) (x = (x >= M) ? (x - M) : x)
#define ll __int128

/*
struct bignum{
	int num[maxl], l;
	bignum(){l = 0; memset(num, 0, sizeof(num));}
	void operator = (bignum b) {
		l = b.l;
		srep(i, 0, l) num[i] = b.num[i];
	}
};
bignum operator + (bignum a, bignum b) {
	bignum c;
	c.l = max(a.l, b.l) + 5;
	srep(i, 0, c.l) {
		c.num[i] += a.num[i] + b.num[i];
		if (c.num[i] >= 10) c.num[i] -= 10, c.num[i + 1]++;
	} 
	while (c.l && !c.num[c.l]) c.l--;
	return c;
}
bignum operator * (bignum a, bignum b) {
	bignum c;
	c.l = a.l + b.l + 5;
	srep(i, 0, a.l) srep(j, 0, b.l) {
		c.num[i + j] += a.num[i] * b.num[j];
	}
	srep(i, 0, c.l) {
		c.num[i + 1] += c.num[i] / 10, c.num[i] %= 10;
	}
	while (c.l && !c.num[c.l]) c.l--;
	return c;
}

struct fact{ // x / y
	bignum x, y;  
	fact(){}
	fact(bignum x, bignum y) : x(x), y(y){}
};
fact operator + (fact a, fact b) {
	return fact(a.x * b.y + a.y * b.x, a.y * b.y);
}
*/

/*
#define bignum __int128

bignum gcd(bignum x, bignum y) {
	return !y ? x : gcd(y, x % y);
}
struct fact{ // x / y
	bignum x, y;  
	fact(){}
	fact(bignum x, bignum y) : x(x), y(y){}
	void init(){
		bignum d = gcd(x, y);
		x /= d, y /= d;
	}
};
fact operator + (fact a, fact b) {
	return fact(a.x * b.y + a.y * b.x, a.y * b.y).init();
}
*/

#define bignum __int128


bignum gcd(bignum x, bignum y) {
	return !y ? x : gcd(y, x % y);
}
struct fact{ // x / y
	bignum x, y;  
	fact(){}
	fact(bignum x, bignum y) : x(x), y(y){}
	void init(){
		bignum d = gcd(x, y);
		if (d) x /= d, y /= d;
	}
	bool operator < (const fact b) const{
		return x * b.y < y * b.x;
	}
};
fact operator + (fact a, fact b) {
	fact rr = fact(a.x * b.y + a.y * b.x, a.y * b.y);
	rr.init();
	return rr;
}
 
int n, m;
char ans[5][maxn]; 
int p[5];
ll dp[maxn][maxn][maxn][maxn];
int vis[maxn][maxn][maxn][maxn], idx = 0;
ll layer[maxn][2];
ll siz[maxn];
ll DP(int pos, int n1, int n2, int n3) {
	if (pos == m + 1) {
		if (n == 1)  return n1 == p[1];
		else if (n == 2)  return n1 == p[1] && n2 == p[2];
		else return n1 == p[1] && n2 == p[2] && n3 == p[3];
	}
	siz[pos][n1][n2][n3]++; 
	if (vis[pos][n1][n2][n3] == idx) return dp[pos][n1][n2][n3];
	vis[pos][n1][n2][n3] = idx;
	ll& anss = dp[pos][n1][n2][n3]; anss = 0;
	ll res1 = DP(pos + 1, n1 + (ans[1][pos] == 'T'), n2 + (ans[2][pos] == 'T'), n3 + (ans[3][pos] == 'T'));
	ll res2 = DP(pos + 1, n1 + (ans[1][pos] == 'F'), n2 + (ans[2][pos] == 'F'), n3 + (ans[3][pos] == 'F')); 
	layer[pos][0] += res1, layer[pos][1] += res2;
	return anss = res1 + res2;
}

/*
char res[maxn];
fact dp2[maxn][maxn][maxn][maxn];
int vis2[maxn][maxn][maxn][maxn];
fact trav(int pos, int n1, int n2, int n3) {
	if (pos == m + 1) {
		return fact(0, 1);
	}
	if (vis2[pos][n1][n2][n3] == idx) return dp2[pos][n1][n2][n3];
	vis2[pos][n1][n2][n3] = idx;
	fact& anss = dp2[pos][n1][n2][n3]; anss = fact(0, 1);
	
	fact res1 = trav(pos + 1, n1 + (ans[1][pos] == 'T'), n2 + (ans[2][pos] == 'T'), n3 + (ans[3][pos] == 'T'));
	fact res2 = trav(pos + 1, n1 + (ans[1][pos] == 'F'), n2 + (ans[2][pos] == 'F'), n3 + (ans[3][pos] == 'F'));
	ll nn1 = DP(pos + 1, n1 + (ans[1][pos] == 'T'), n2 + (ans[2][pos] == 'T'), n3 + (ans[3][pos] == 'T'));
	ll nn2 = DP(pos + 1, n1 + (ans[1][pos] == 'F'), n2 + (ans[2][pos] == 'F'), n3 + (ans[3][pos] == 'F'));
	
	
	if (res2 < res1) {
		res[pos] = 'T';
		anss = fact(nn1, nn1 + nn2) + trav(pos + 1, n1 + (ans[1][pos] == 'T'), n2 + (ans[2][pos] == 'T'), n3 + (ans[3][pos] == 'T'));
	}
	else {
		res[pos] = 'F';
		anss = fact(nn2, nn1 + nn2) + trav(pos + 1, n1 + (ans[1][pos] == 'F'), n2 + (ans[2][pos] == 'F'), n3 + (ans[3][pos] == 'F'));
	}
	return anss;
}
*/

char res[maxn];
fact dp2[maxn][maxn][maxn][maxn];
int vis2[maxn][maxn][maxn][maxn];
fact trav(int pos, int n1, int n2, int n3) {
	if (pos == m + 1) {
		return fact(0, 1);
	}
	if (vis2[pos][n1][n2][n3] == idx) return dp2[pos][n1][n2][n3];
	vis2[pos][n1][n2][n3] = idx;
	fact& anss = dp2[pos][n1][n2][n3]; anss = fact(0, 1);
	
	fact res1 = fact(layer[pos][0], layer[pos][0] + layer[pos][1]) + trav(pos + 1, n1 + (ans[1][pos] == 'T'), n2 + (ans[2][pos] == 'T'), n3 + (ans[3][pos] == 'T'));
	fact res2 = fact(layer[pos][1], layer[pos][0] + layer[pos][1]) + trav(pos + 1, n1 + (ans[1][pos] == 'F'), n2 + (ans[2][pos] == 'F'), n3 + (ans[3][pos] == 'F'));
	ll nn1 = DP(pos + 1, n1 + (ans[1][pos] == 'T'), n2 + (ans[2][pos] == 'T'), n3 + (ans[3][pos] == 'T'));
	ll nn2 = DP(pos + 1, n1 + (ans[1][pos] == 'F'), n2 + (ans[2][pos] == 'F'), n3 + (ans[3][pos] == 'F'));
	
	
	if (res2 < res1) {
		res[pos] = 'T';
		anss = res1;
	}
	else {
		res[pos] = 'F';
		anss = res2;
	}
	return anss;
}

int main(){ 
	int T; read(T);
	rep(TT, 1, T){
		idx++;
		printf("Case #%d: ", TT);
		read(n, m);
		
		rep(i, 1, n) reads(ans[i] + 1), read(p[i]);
		
		//ll deno = DP(1, 0, 0, 0);
		DP(1, 0, 0, 0);
		rep(i, 1, m) write(layer[i][0], ' '), write(layer[i][1]);
		fact xx = trav(1, 0, 0, 0);
		//ll d = gcd(deno, nume);
		//deno /= d, nume /= d;
		xx.init();
		printf("%s ", res + 1);
		rep(i, 1, m) res[i] = '\0', layer[i][0] = layer[i][1] = 0;
		write(xx.x, '/'), write(xx.y);
	}
	return 0;
}


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
#define ll long long int 
#define pb push_back
#define pc putchar
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn
#define maxm
#define maxs
#define maxb
#define M 1000000007
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}
int _num[20];
template <class T> void write(T x, char sep = '\n'){	
	if (!x) {putchar('0'), putchar(sep); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar(sep);
}

int power(int x, int y){
	int ans = 1, con = x;
	while (y){
		if (y & 1) ans = 1ll * ans * con % M;
		y >>= 1;
		con = 1ll * con * con % M;
	}
	return ans;
}
int getinv(int x){ return power(x, M - 2); }

int main(){
	int n, m, k;
	read(n), read(m), read(k);
	int center = 1, edge = n - 1, par = 0, rest = m - (n - 1);
	par += rest, edge -= 2 * rest;
	int ans1 = 1ll * edge * k % M * (n - k) % M * getinv(n - 1) % M * getinv(n) % M;
	int ans21 = 1ll * k * (n - k) % M * (n - k - 1) % M;
	int ans22 = 2ll * (k - 1) * k % M * (n - k) % M;
	int ans2 = 1ll * par * (ans21 + ans22) % M * getinv(n - 2) % M * getinv(n - 1) % M * getinv(n) % M;
	int ans3 = 1ll * (n - k) * getinv(n) % M;
	int res = (1ll * ans1 + ans2 + ans3) % M;
	write(res);
	return 0;
}


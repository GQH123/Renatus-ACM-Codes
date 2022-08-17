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
#define maxn 600020
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

int n, a[maxn], fac[maxn], two[maxn];
int main(){
	read(n); rep(i, 1, n) read(a[i]);
	sort(a + 1, a + 1 + n);
	two[0] = fac[0] = 1;
	srep(i, 1, maxn) two[i] = (two[i - 1] << 1) % M, fac[i] = 1ll * fac[i - 1] * i % M;
	int res = 1, ct = 0;
	rep(i, 1, n){
		int now = a[i], _i = i; ct++;
		while (i <= n && now == a[i]) i++;
		res = 1ll * res * fac[i - _i] % M;  
		if (i != n + 1) res = 1ll * res * ((i - _i) + 1) % M; 
		i--; 
	}
	//res = 1ll * res * two[ct - 1] % M;
	write(res);
	return 0;
}


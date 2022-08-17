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
#define maxn 200020
#define maxm
#define maxs
#define maxb
#define M 114514
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
int n, m, a[maxn], b[maxn], d[maxn], lis[maxn << 2], cs = 0;
int peo[maxn << 2], awa[maxn << 2];
int main(){
	read(n), read(m);
	rep(i, 1, n) read(a[i]), lis[++cs] = a[i];
	rep(i, 1, n) read(b[i]), lis[++cs] = b[i];
	rep(i, 1, m) read(d[i]), lis[++cs] = d[i];
	sort(lis + 1, lis + 1 + cs);
	cs = unique(lis + 1, lis + 1 + cs) - lis - 1;
	rep(i, 1, n) a[i] = lower_bound(lis + 1, lis + 1 + cs, a[i]) - lis, peo[a[i]]++;
	rep(i, 1, n) b[i] = lower_bound(lis + 1, lis + 1 + cs, b[i]) - lis, awa[b[i]]++;
	rep(i, 1, m) d[i] = lower_bound(lis + 1, lis + 1 + cs, d[i]) - lis;
	sort(d + 1, d + 1 + m);
	int last = 0, sumpeo = 0, sumawa = 0;
	ll res = 0;
	rep(i, 1, m){
		while (last < d[i]) { 
			sumpeo += peo[last]; 
			last++; 
			sumawa += awa[last];
		}
		res += 1ll * (sumawa) * (((__int128)(n - sumawa) * (n - sumawa - 1) * (n - sumawa - 2) / 6) % M) % M * sumpeo % M;
		res %= M;
	}
	write(res);
	return 0;
}


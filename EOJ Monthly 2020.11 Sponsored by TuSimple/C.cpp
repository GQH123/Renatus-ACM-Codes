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
#define maxn 18
#define maxm
#define maxs
#define maxb
#define M 5201314
#define int ll 
#define mo(x) (x %= M)
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
int n, a[maxn], b[maxn], sa[1 << maxn], sb[1 << maxn], G[1 << maxn], F[1 << maxn], bc[1 << maxn];

//int _a[1 << maxn], _b[1 << maxn];
int _a[1 << 10], _b[1 << 10];
signed main(){ 
	read(n); rep(i, 1, n) read(a[i]); rep(i, 1, n) read(b[i]); 
	int S = (1 << n);
	bc[0] = 0; srep(i, 1, S) bc[i] = bc[i >> 1] + (i & 1);
	srep(i, 0, S){
		rep(j, 1, n) {
			if (i & (1 << (j - 1))) {
				sa[i] += a[j];
				sb[i] ^= b[j];
			}
		}
	} 
	srep(i, 0, S){
		int& ans = G[i]; ans = 0;
		//int cc = 0; 
		int cc = (1 << bc[i]), ssa = 0, ssb = 0; 
		for (register int j = i; j != -1; j = (j == 0) ? -1 : (j - 1) & i){ 
			//++cc;
			//assert(j != -1);
			
			if (sa[j] >= 128) ans += 1ll * cc * sa[j] % M, mo(ans);
			else _a[sa[j]]++, ssa++;
			assert(sb[j] < 128);
			_b[sb[j]]++, ssb++;
		} 
		per(i, 127, 0) {
			ans += 1ll * i * _a[i] % M * (ssb - _b[i]) % M + 1ll * i * _b[i] % M * (ssa - _a[i]) % M + 1ll * i * _a[i] % M * _b[i] % M;
			mo(ans);
			ssa -= _a[i], ssb -= _b[i];
			_a[i] = _b[i] = 0;
		}
		//++cc;
		//_a[cc] = sa[0];
		//_b[cc] = sb[0];
		//assert(sa[0] == sb[0] && sa[0] == 0);
		//assert(cc == (1 << bc[i]));
		
		/*
		sort(_a + 1, _a + cc + 1), sort(_b + 1, _b + cc + 1);
		int ptra = cc, ptrb = cc;
		while (ptra && ptrb){
			if (_a[ptra] >= _b[ptrb]) {
				ans += 1ll * _a[ptra] * ptrb % M;
				ptra--;
				mo(ans);
			}
			else {
				ans += 1ll * _b[ptrb] * ptra % M;
				ptrb--;
				mo(ans);
			}
		}
		*/
		//write(ans, ' ');
	}
	//puts("");
	
	
	srep(i, 0, S){
		int ans = 0;
		for (register int j = i; j; j = (j - 1) & i){ 
			//assert(i | j == i ^ j);
			ans += (M + ((bc[i - j] & 1) ? -1 : 1) * G[j]);
			mo(ans);
		}
		int j = 0;
		ans += (M + ((bc[i - j] & 1) ? -1 : 1) * G[j]);
		mo(ans);
		write(ans, ' ');
	}
	
	return 0;
}


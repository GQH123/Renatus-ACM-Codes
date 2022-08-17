#include <bits/stdc++.h>
#define maxr 100000
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define M 1000000007
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}
int n;
int a[maxn << 1];

ll fac[maxn], ifac[maxn], inv[maxn];
void init(){
	fac[0] = ifac[0] = inv[1] = 1;
	srep(i, 1, maxn) fac[i] = fac[i - 1] * i % M;
	srep(i, 2, maxn) inv[i] = M - M / i * inv[M % i] % M;
	srep(i, 1, maxn) ifac[i] = ifac[i - 1] * inv[i] % M;
}
ll getC(int m, int n){
	if (m < n) return 0;
	return fac[m] * ifac[n] % M * ifac[m - n] % M;
}

int main(){
	#ifndef ONLINE_JUDGE	
		freopen("D.in", "r", stdin);
	#endif
	init();
	int T;
	read(T);
	while (T--){
		read(n);
		rep(i, 1, (1 << n)) read(a[i]);
		rep(i, 1, 
	}
	return 0;
}

#include <bits/stdc++.h>
#define maxr 100000
#define maxn 100005
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define M 998244353
#define mo(x) x = (x >= M) ? (x - M) : x
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}
int f[maxn];
void init(){
	f[0] = 1, f[1] = 1, f[2] = 1;
	srep(i, 3, maxn) f[i] = f[i - 1] + f[i - 3], mo(f[i]); //printf("%d\n", f[i]);
}
int main(){
	#ifndef ONLINE_JUDGE
		freopen("G.in", "r", stdin);
		//freopen("G.out", "w", stdout);
	#endif
	init();
	int T, x, y, n;
	read(T);
	while (T--){
		read(n), read(x), read(y);
		if (x != 1) x++;
		if (y != n) y--;
		printf("%d\n", (y >= x) ? f[y - x] : 0);
	}
	return 0;
}

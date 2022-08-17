#include <bits/stdc++.h>
#define maxr 100000
#define maxn 25
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
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
int ans[maxn];

int main(){
	#ifndef ONLINE_JUDGE	
		freopen("A.in", "r", stdin);
	#endif
	int T, x;
	read(T);
	while (T--){
		read(x);
		int sum = 0, ct = 0;
		int _x = x;
		while (x) sum += x % 10, x /= 10;
		x = _x;
		rep(i, 1, sum){
			if (x % i == 0 && sum % i == 0) ans[++ct] = i;
		}
		printf("%d\n", ct);
		printf("%d", ans[1]); rep(i, 2, ct) printf(" %d", ans[i]); printf("\n");
	}
	return 0;
}

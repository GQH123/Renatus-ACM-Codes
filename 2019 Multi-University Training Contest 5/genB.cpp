#include <bits/stdc++.h>
#define maxr 100000
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

int main(){
	srand(time(NULL));
	#ifndef ONLINE_JUDGE
		freopen("B.in", "w", stdout);
	#endif
	int T = 6;
	printf("%d\n", T);
	while (T--){
		int n = 100;
		printf("%d\n", n);
		rep(i, 1, n) printf("%d ", rand() % (1 << 15)); printf("\n");
		rep(i, 1, n) printf("%d ", ((rand() % (1 << 15) - 1) << 15)); printf("\n");
	}
	return 0;
}

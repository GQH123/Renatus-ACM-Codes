#include <bits/stdc++.h>
#define maxr 100000
#define maxn 600005
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template<class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}
int a[maxn];
int main(){
	#ifndef ONLINE_JUDGE
		freopen("C.in", "r", stdin);
	#endif
	int r, s, p, x, y;
	read(r), read(s), read(p);
	rep(i, 1, p){
		read(x), read(y);
		a[i] = ((y <= s) ? (s - y + 1) : (y - s)) + (r - x + 1);
	}
	sort(a + 1, a + 1 + p);
	rep(i, 1, p) if (a[i] <= a[i - 1]) a[i] = a[i - 1] + 1;
	printf("%d", a[p]);
	return 0;
}

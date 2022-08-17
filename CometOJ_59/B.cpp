#include <bits/stdc++.h>
#define maxr 100000
#define maxn 200005
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (ch != '-' && !('0' <= ch && ch <= '9')) ch = gc();
	if (ch == '-') ch = gc(), f = 0;
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f)? x : -x;
}
int n, k;
int a[maxn];

int main(){
	#ifndef ONLINE_JUDGE
		freopen("B.in", "r", stdin);
	#endif
	read(n), read(k);
	rep(i, 1, n) read(a[i]);
	int ans = 0;
	rep(i, 2, n) if (abs(a[i] - a[i - 1]) < k) ans++, i++;  
	printf("%d", ans);
	return 0;
}

#include <bits/stdc++.h>
#define maxr 100000
#define maxn 100005
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
struct point{
	int x, y;
	point(int x, int y) : x(x), y(y){}
	point(){}
	bool operator < (point b){
		return (x == b.x) ? y < b.y : x < b.x;
	}
}p[maxn];

int main(){
	#ifndef ONLINE_JUDGE
		freopen("D.in", "r", stdin);
	#endif
	read(n), read(k);
	rep(i, 1, n) read(p[i].x), read(p[i].y);
	sort(p + 1, p + 1 + n);
	rep(i, 1, n){
		
	}
	return 0;
}

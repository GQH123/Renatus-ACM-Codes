#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define pii pair<int, int>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define ll long long int 
#define pb push_back
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn 600020
#define maxm
#define maxs
#define maxb
#define M 
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
template <class T> void write(T x){	
	if (!x) {putchar('0'), putchar('\n'); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar('\n');
}

int n;
struct ele{
	ll a, x, y;
	ele(ll a, ll x, ll y) : a(a), x(x), y(y){}
	ele(){}
	bool operator < (ele b) const{
		return (long double)(y - a) * b.x < (long double)(b.y - b.a) * x;
	}
}p[maxn], g[maxn];
bool cmp(const ele x, const ele y){
	return x.a < y.a;
}

int main(){
	
		//freopen("D.in", "r", stdin);

	int T;
	read(T);
	while (T--){
		read(n);
		rep(i, 1, n) read(p[i].a), read(p[i].x), read(p[i].y);
		sort(p + 1, p + 1 + n, cmp);
		g[0] = ele(p[1].a - 1, 0, p[1].a - 2);
		int ans = 0;
		rep(i, 1, n){ 
			int d = upper_bound(g, g + 1 + ans, p[i]) - g;
			ans = max(ans, d);
			g[d] = p[i];
		} 
		printf("%d\n", ans);
		//recover();
	}
	return 0;
}


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
#define maxn 2020
#define maxm
#define maxs
#define maxb
#define M 1000000007
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

struct ele{
	int x, y, c;
	ele(int x, int y, int c) : x(x), y(y), c(c){}
	ele(){}
	bool operator < (const& ele b) const{
		return x == b.x ? y < b.y : x < b.x;
	}
}p[maxn];

int n, k, L;
pii lis[maxn];
int main(){
	scanf("%d%d%d", &n, &k, &L);
	rep(i, 1, n) scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].c);
	sort(p + 1, p + 1 + n);
	ll ans = 0;
	int last = -1;
	rep(i, 1, n) {
		int fac = p[i].x - last; last = p[i].x;
		rep(j, 1, n) {
			pii 
		}
		
		int x = p[i].x;
		while (i <= n && p[i].x == x) i++; i--;
	}
	printf("%lld", ans);
	return 0;
}


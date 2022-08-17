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
#define maxn 200020
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
int _num[65];
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
	ll x, y;
	ll vx, vy;
	ele(ll x, ll y) : x(x), y(y), vx(0), vy(0){}
	ele(){}
}a[maxn];

bool cmp1(const ele i, const ele j){
	return i.x < j.x;
}

bool cmp2(const ele i, const ele j){
	return i.y < j.y;
}

int main(){
	
		freopen("B.in", "r", stdin);
		
	ios :: sync_with_stdio(false), cin.tie(0);
	
	int T;
	read(T);
	while (T--){
		read(n);
		rep(i, 1, n) {
			read(a[i].x), read(a[i].y);
			ll t = a[i].y;
			a[i].y = a[i].x - a[i].y;
			a[i].x = a[i].x + t;
		}
		
		sort(a + 1, a + 1 + n, cmp1);
		ll now = 0;
		rep(i, 1, n) now += a[i].x - a[1].x;
		rep(i, 1, n){
			a[i].vx = now; 
			now += (ll)(2 * i - n) * (a[i + 1].x - a[i].x);
		}
		
		sort(a + 1, a + 1 + n, cmp2);
		now = 0;
		rep(i, 1, n) now += a[i].y - a[1].y;
		rep(i, 1, n){
			a[i].vy = now;
			now += (ll)(2 * i - n) * (a[i + 1].y - a[i].y);
		}
		
		ll ans = -1;
		rep(i, 1, n) ans = (ans == -1) ? (a[i].vx + a[i].vy) : (min(ans, a[i].vx + a[i].vy));
		write(ans >> 1);
	}
	return 0;
} 

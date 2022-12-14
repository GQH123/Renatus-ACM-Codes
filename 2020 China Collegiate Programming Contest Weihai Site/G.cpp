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
#define us unsigned short int 
#define ull unsigned long long int 
#define pb push_back
#define pc putchar
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn 1000020
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
template <class T> void write(T x, char sep = '\n'){	
	if (!x) {putchar('0'), putchar(sep); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar(sep);
}

int n, m; 
us a[maxn], b[maxn];
ull has[maxn << 2], mi[maxn];

int qx, qy;
us qd;
extern void pu(int l, int r, int o);
inline void init(int l, int r, int o) {
	if (l == r) {
		has[o] = b[l];
		return;
	}
	int mid = ((r - l) >> 1) + l;
	init(l, mid, o << 1), init(mid + 1, r, o << 1 | 1);
	pu(l, r, o);
}
inline void pu(int l, int r, int o) {
	int mid = ((r - l) >> 1) + l;
	has[o] = (has[o << 1] * mi[r - mid] + has[o << 1 | 1]);
}
ull get(int l, int r, int o) {
	if (qx <= l && r <= qy) return has[o];
	int mid = ((r - l) >> 1) + l; ull ans = 0;
	if (qx <= mid) ans = get(l, mid, o << 1);
	if (qy > mid) {
		ans *= mi[min(r, qy) - mid];
		ans += get(mid + 1, r, o << 1 | 1);
	}
	return ans;
}
void mod(int l, int r, int o){
	if (l == r) { has[o] = qd; return; } 
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) mod(l, mid, o << 1);
	else mod(mid + 1, r, o << 1 | 1); 
	pu(l, r, o);
}

namespace BIT{
	#define lowbit(x) (x & -x) 
	#define type us
	type c[maxn];
	type get(int x) {
		type ans = 0;
		while (x) {
			ans += c[x];
			x -= lowbit(x);
		}
		return ans;
	}
	void add(int x, type v){
		while (x <= n) {
			c[x] += v;
			x += lowbit(x);
		}
	}
}

ull gethash(int l, int r) {	
	qx = l + 1, qy = r;
	return (qx <= qy) ? get(1, n, 1) : 0;
}
bool judge(int x, int y, int l) {
	//cerr << endl;
	//cerr << BIT :: get(x) << ' ' << BIT :: get(y) << endl;
	//cerr << gethash(x, x + l - 1) << ' ' << gethash(y, y + l - 1) << endl;
	if (BIT :: get(x) != BIT :: get(y)) return false;
	return gethash(x, x + l - 1) == gethash(y, y + l - 1); 
}

int main(){
	read(n), read(m);
	mi[0] = 1; rep(i, 1, n) mi[i] = mi[i - 1] * 233;
	rep(i, 1, n) read(a[i]), b[i] = a[i] - a[i - 1], BIT :: add(i, b[i]);
	int op, x, y, z;
	init(1, n, 1);
	rep(i, 1, m) {
		read(op), read(x), read(y); 
		switch(op) {
			case 1: 
				BIT :: add(x, 1), qx = qy = x, qd = get(1, n, 1), qd++, mod(1, n, 1);
				if (y + 1 <= n) BIT :: add(y + 1, -1), qx = qy = y + 1, qd = get(1, n, 1), qd--, mod(1, n, 1);
				break;
			case 2: read(z); puts(judge(x, y, z) ? "yes" : "no"); break;
		}
	}
	return 0;
}


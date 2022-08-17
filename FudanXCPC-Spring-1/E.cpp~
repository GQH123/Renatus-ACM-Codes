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
#define ll __int128 
#define pb push_back
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn
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

/*int solve(int x){
	int l = 1, r = 1000000000, mid;
	while (l < r){
		mid = ((r - l) >> 1) + l;
		if ((ll)mid * mid == x) return mid;
		else if ((ll)mid * mid > x) r = mid;
		else l = mid + 1;
	}
	if ((ll) l * l == x) return l;
	return -1;
} 

ll ten[20];

ll play(int n, int x){
	int _n = n / x;
	if (_n < x) return -1;
	if (_n == x) return x;
	_n -= x;
	if (_n % 2) return -1;
	ll ans = _n / 2 + x, _ans = ans * ans;
	rep(i, 0, 18) if (_ans % ten[i] == n) return ans;
	return -1;
}*/

ll ten[20], cn = 0, n, mi = -1;
void get(int pos, ll x){
	if (pos == cn + 1) { 
		mi = (mi == -1) ? x : min(x, mi);
		return;
	}
	ll _x;
	rep(i, 0, 9){
		_x = x + ten[pos] * i;
		if ((_x * _x % ten[pos]) == (n % ten[pos])) get(pos + 1, _x); 
	}
}

int main(){
	
		freopen("E.in", "r", stdin);
	
	/*ll now = 1;
	ten[0] = 1;
	rep(i, 1, 18) ten[i] = ten[i - 1] * 10;
	
	int T, n;
	read(T);
	while (T--){
		read(n);
		if (!n) {write(0); continue;}
		int d = solve(n), mi = -1;
		if (d != -1) mi = ((mi == -1) ? d : min(mi, d));
		else {
			rep(i, 1, n){	
				if (i * i > n) break;
				if (n % i == 0) {
					d = play(n, i);
					if (d != -1) mi = ((mi == -1) ? d : min(mi, d));
				}
			}
		}
		if (mi == -1) printf("None\n");
		else write(mi);
	}*/
	
	ten[0] = 1;
	rep(i, 1, 18) ten[i] = ten[i - 1] * 10;
	int T;
	read(T);
	while (T--){
		mi = -1, cn = 0;
		read(n);
		if (!n) {write(0); continue;}
		ll _n = n;
		while (n) n /= 10, cn++;
		n = _n;
		get(0, 0);
		if (mi == -1) printf("None\n");
		else write(mi);
	}
	return 0;
}


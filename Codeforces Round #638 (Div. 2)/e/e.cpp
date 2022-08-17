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
#define maxn 520
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

int n, k, a[maxn], b[maxn];

int main(){
	
		//freopen("e.in", "r", stdin);
	ll sa = 0, sb = 0;
	read(n), read(k);
	rep(i, 1, n) read(a[i]), read(b[i]), sa += a[i], sb += b[i];
	if (sa % k == 0) {
		printf("%lld", sa / k + sb / k);
	}
	else if (sb % k == 0){
		printf("%lld", sa / k + sb / k);
	}
	else {
		int r1 = sa % k, r2 = sb % k;
		if (r1 + r2 < k) printf("%lld", sa / k + sb / k);
		else {
			rep(i, 1, n){
				if (a[i] >= k || b[i] >= k) {
					printf("%lld", sa / k + sb / k + 1);
					return 0;
				}
			}
			printf("%lld", sa / k + sb / k);
		}
	}
	return 0;
}


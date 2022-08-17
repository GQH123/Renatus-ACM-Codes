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
#define maxn 2000020
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

bool sqrt_lower_bound(int l, int r, ll x){
	while (l != r){	
		int mid = ((r - l) >> 1) + l; ll res = 1ll * mid * mid;
		if (res == x) return true;
		if (res < x) l = mid + 1;
		else r = mid;
	}
	return false;
}

int p[maxn], cp = 0;
bool vis[maxn];
void init(){
	rep(i, 2, maxn) {
		if (!vis[i]) p[++cp] = i;
		rep(j, 1, cp) {
			if (i * p[j] >= maxn) break;
			vis[i * p[j]] = 1;
			if (i % p[j] == 0) break;
		}
	}
}

int main(){
	int T; read(T); ll n;
	init();
	while (T--){
		read(n);
		if (sqrt_lower_bound(2, 1e9, n)) {
			puts("yes");
			goto done;
		}
		else {
			rep(i, 1, cp) {
				if (1ll * p[i] * p[i] > n) break;
				if (n % p[i] == 0) {
					int ct = 0;
					while (n % p[i] == 0) {
						n /= p[i];
						ct++;
					}
					if (ct > 1) {
						puts("yes");
						goto done;
					}
				}
			}
		}
		puts("no");
		done:;
	}
	return 0;
}


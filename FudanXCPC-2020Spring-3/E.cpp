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
#define mo(x) (x = (x >= m) ? (x - m) : x)
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

int fac[maxn], inv[maxn], ifac[maxn];
void init(int m){
	fac[0] = inv[1] = ifac[0] = 1;
	srep(i, 1, m) fac[i] = (ll)fac[i - 1] * i % m;
	srep(i, 2, m) inv[i] = m - m / i * (ll)inv[m % i] % m;
	srep(i, 1, m) ifac[i] = (ll)ifac[i - 1] * inv[i] % m;
}
ll cal(int x, int y, int m){
	if (x < m && y < m) return (x < y) ? 0 : ((ll)fac[x] * ifac[y] % m * ifac[x - y] % m);
	else return (ll)cal(x / m, y / m, m) * cal(x % m, y % m, m) % m;
}

int n, m, k;

int main(){
	
		freopen("E.in", "r", stdin);
		
	//ios :: sync_with_stdio(false), cin.tie(0);
	
	int T;
	read(T);
	rep(TT, 1, T){
		printf("Case %d: ", TT);
		read(n), read(k), read(m);
		if (!n || m == 1){	
			printf("0\n");
			continue;
		}
		init(m);
		int eff = cal(n, k, m); 
		n -= k;
		int _n = n / m * m, now = 1, ans = 0, d = ((n & 1) ? -1 : 1);
		per(i, n, _n) {
			ans += (m + d * now) % m, mo(ans);
			d = -d;
			now = (ll)now * i % m;
		}
		//printf("%d\n", ans);
		printf("%lld\n", (ll)ans * eff % m);
	}
	return 0;
}


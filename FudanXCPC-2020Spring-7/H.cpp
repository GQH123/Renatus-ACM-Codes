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
#define M 100000007
#define mo(x) (x = (x >= M) ? (x - M) : x) 
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

int n, a[maxn];
int c[maxn];
void add(int x, int v){
	while (x){
		c[x] += v;
		x -= lowbit(x); 
	}
}
int get(int x){
	int ans = 0;
	while (x <= n) {
		ans += c[x];
		x += lowbit(x);
	}
	return ans;
}

int c2[maxn];
void add2(int x, int v){
	while (x <= n){
		c2[x] += v;
		x += lowbit(x); 
	}
}
int get2(int x){
	int ans = 0;
	while (x) {
		ans += c2[x];
		x -= lowbit(x);
	}
	return ans;
}

int main(){
	
		//freopen("H.in", "r", stdin);
		
	
	int T;
	read(T);
	rep(TT, 1, T){
		printf("Case #%d: ", TT);
		read(n);
		rep(i, 1, n) read(a[i]);
		ll ans = 0;
		per(i, n, 1){
			int d = get(a[i] + 1);
			ans += (ll)d * (d - 1) / 2 % M, mo(ans);
			add(a[i], 1);
		}
		ll ans2 = 0;
		rep(i, 1, n) c[i] = 0;
		per(i, n, 1) add(a[i], 1); 
		rep(i, 1, n){
			int d1 = get2(a[i] - 1), d2 = get(a[i] + 1);
			ans2 += (ll)d1 * d2 % M, mo(ans2);
			add(a[i], -1), add2(a[i], 1);
		}
		//printf("%lld %lld ", ans, ans2);
		rep(i, 1, n) c[i] = c2[i] = 0;
		printf("%lld\n", (ans + M - ans2) % M);
	}
	return 0;
}


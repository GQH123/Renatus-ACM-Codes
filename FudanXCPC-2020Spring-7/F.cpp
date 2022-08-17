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
template <class T> void write(T x){	
	if (!x) {putchar('0'), putchar('\n'); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar('\n');
}

int n;
ll a[maxn], g[maxn];
int s[maxn];

bool cmp(ll i, ll j){
	return i > j;
}

int main(){

	//ll lis[] = {5, 5, 5, 4, 4, 4};
	//printf("%d %d \n", upper_bound(lis, lis + 6, 4, cmp) - lis, upper_bound(lis, lis + 6, 5, cmp) - lis);
	
		//freopen("F.in", "r", stdin);
	
	ll mx, mi;
	while (scanf("%d", &n) == 1){
		scanf("%lld", &a[1]), mx = mi = a[1];
		rep(i, 2, n) scanf("%lld", a + i), mx = max(mx, (ll)a[i]), mi = min(mi, (ll)a[i]); mx++, mi--;
		
		
		g[0] = mi; s[0] = n + 1; rep(i, 1, n) g[i] = mx, s[i] = 0;
		rep(i, 1, n) {
			int dd = lower_bound(g, g + 1 + n, a[i]) - g;
			g[dd] = a[i];
			if (s[dd - 1] > 0) s[dd - 1]--, s[dd]++;
		}
		per(i, n, 1) if (g[i] != mx) {printf("%d\n%d\n", i, s[i]); break;} 
		
		//g[0] = mx; rep(i, 1, n) g[i] = mi;
		//rep(i, 1, n) g[upper_bound(g, g + 1 + n, a[i], cmp) - g] = a[i];
		//per(i, n, 1) if (g[i] != mi) {printf("%d\n", i); break;} 
	}
	
	return 0;
}


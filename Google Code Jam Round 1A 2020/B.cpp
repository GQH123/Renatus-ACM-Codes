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
#define maxn 2020
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

int play(int x){
	int _x = x, s = 0;
	while (x) x >>= 1, s++;
	x = _x;
	rep(i, 0, s){
		if (x < i) break;
		x -= i;
		s = 0;
		while (x){
			if (!(x & 1)) s++;
			x >>= 1;
		}
		if (s == i) return s;
		x = _x;
	}
	return -1;
}

pii ans[maxn];
int cs = 0;
void solve(int n, int d, int add){
	n -= d;
	int x = 1, y = 1;
	ans[++cs] = pii(x, y);
	bool op = 0;
	while (n){
		if (n & 1){
			if (!op) {
				while (y < x) y++, ans[++cs] = pii(x, y);
				x++, y++;
				ans[++cs] = pii(x, y);
			}
			else {
				while (y > 1) y--, ans[++cs] = pii(x, y);
				x++;
				ans[++cs] = pii(x, y);
			}
			op ^= 1; 
		}
		else {
			if (!op) x++;
			else x++, y++;
			ans[++cs] = pii(x, y);
		}
		n >>= 1;
	}
	while (add){
		if (!op) x++;
		else x++, y++;
		ans[++cs] = pii(x, y);
		add--;
	}
}


int main(){
	
		freopen("B.in", "r", stdin);
		freopen("B.out", "w", stdout);
		
	//ios :: sync_with_stdio(false), cin.tie(0);
	//IMPOSSIBLE, POSSIBLE
	int T, n;
	scanf("%d", &T);
	rep(TT, 1, T){
		//printf("Case #%d:\n", TT);
		scanf("%d", &n);
		int add = 0, d = -1;
		while (1){
			d = play(n);
			if (d == -1) n--, add++;
			else break; 
		}
		solve(n, d, add);
		srep(i, 1, cs) printf("%d %d\n", ans[i].fi, ans[i].se);
		printf("-1 -1\n");
		cs = 0; 
	}
	return 0;
}


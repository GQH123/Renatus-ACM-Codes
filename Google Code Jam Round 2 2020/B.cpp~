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
#define maxn 220
#define maxm 2020
#define maxs
#define maxb
#define M 
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

const int inf = 2000000000;

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

int n, m, a[maxn];
struct edge{
	int next, to, id;
	edge(int next, int to, int id) : next(next), to(to), id(id) {}
	edge(){}
}e[maxm << 1];
int cnt = 1, h[maxn], d[maxn];
void Add_Edge(int x, int y, int id){
	e[++cnt] = edge(h[x], y, id);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x, id);
	h[y] = cnt;
}
int cs, cs2;
pii lis[maxn], lis2[maxn];
int ans[maxm];

int val[maxn];

int main(){
	int T, x, y;
	scanf("%d", &T);
	rep(TT, 1, T){
		cs = 0, cs2 = 0;
		printf("Case #%d: ", TT);
		scanf("%d%d", &n, &m);
		rep(i, 2, n) {
			scanf("%d", &a[i]);
			if (a[i] < 0) lis[++cs] = pii(-a[i], i);
			else lis2[++cs2] = pii(a[i] - 1, i);
		} 
		sort(lis2 + 1, lis2 + 1 + cs2); 
		int _cs = cs, ptr = 1;
		rep(i, 1, _cs){
			int d = lis[i].fi - (i - 1);
			while (d){
				d--;
				lis[++cs] = pii(
			}
			int now = lis[i].fi;
			while (i <= _cs && now == lis[i].fi) i++; i--;
		}
	} 
	return 0;
}


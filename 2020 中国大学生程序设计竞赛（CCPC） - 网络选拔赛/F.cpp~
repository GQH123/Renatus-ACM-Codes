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
#define maxn 520
#define maxk 2020
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

int n, k[maxn], c[maxn][maxk], b[maxn][maxk], d[maxn][maxk], a[maxn][maxk];
int cons[maxn][maxk];  

ll dfs(ll x, ll v, bool left = 1) {
	if (x == n) return v;
	int pos = lower_bound(a[x], a[x] + k[x], v) - a[x];
	if (pos < k[x] && a[x][pos] == v && !left) pos++;
	return dfs(d[x][pos], c[x][pos] * v + b[x][pos], left);
}

/*
inline ll trans(ll x, ll v, ll p) {	
	return c[x][p] * v + b[x][p];
}

bool dfs2(ll x, ll lv, ll rv) {	
	if (x == n || lv == rv) return true;
	int lp = lower_bound(a[x], a[x] + k[x], lv) - a[x];
	int rp = upper_bound(a[x], a[x] + k[x], rv) - a[x] - 1;
	if (lp > rp) return dfs2(d[x][lp], trans(x, lv, lp), trans(x, rv, lp));  
	else {
		srep(i, lp, rp) {
			if (!cons[x][i]) return false; 
			if (!dfs2(d[x][i], trans(x, a[x][i], i), trans(x, a[x][i + 1], i + 1))) return false; 
		} 
		if (lv < a[x][lp]) {
			if (!dfs2(d[x][lp], trans(x, lv, lp), trans(x, a[x][lp], lp))) return false;
		}
		if (rv > a[x][rp]) {
			if (!cons[x][rp]) return false;
			if (!dfs2(d[x][rp], trans(x, a[x][rp], rp), trans(x, rv, rp + 1))) return false;
		}
	}
	return true; 
}
*/

int main(){
	int T; read(T);
	rep(TT, 1, T){
		printf("Case #%d: ", TT);
		read(n);
		srep(i, 1, n) {
			read(k[i]); 
			srep(j, 0, k[i]) read(c[i][j]), read(b[i][j]), read(d[i][j]), read(a[i][j]);
			read(c[i][k[i]]), read(b[i][k[i]]), read(d[i][k[i]]);
		}
		per(i, n - 1, 1) {
			srep(j, 0, k[i]) {
				if (dfs(i, a[i][j], 0) != dfs(i, a[i][j], 1)) {
					printf("NO\n");
					goto done;
				}
				//else cons[i][j] = 1;
			}
		}
		printf("YES\n");
		done:;
		/*
		per(i, n - 1, 1) {
			srep(j, 0, k[i]) {
				if (
			}
		}
		*/
	}
	
	return 0;
}


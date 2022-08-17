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
#define maxn 55
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

int n, m;
int cc[maxn][maxn], c = 0;
char g[maxn][maxn];
bool ok(int i, int j){
	return 1 <= i && i <= n && 1 <= j && j <= m;
}
void dfs(int x, int y){
	if (!ok(x, y) || cc[x][y] || g[x][y] == '#') return; 
	cc[x][y] = c;
	for (register int i = -1; i <= 1; i += 2){
		dfs(x + i, y), dfs(x, y + i);
	}
}

void recover(){
	c = 0;
	rep(i, 1, n) rep(j, 1, m) cc[i][j] = 0;
}

int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		scanf("%d%d", &n, &m);
		rep(i, 1, n) scanf("%s", g[i] + 1);
		bool fb = 0, fg = 0;
		rep(i, 1, n){
			rep(j, 1, m){	
				if (g[i][j] == 'B') fb = 1;
				else if (g[i][j] == 'G') fg = 1;
			}
		}
		if (!fg) {printf("Yes\n"); goto over;}
		rep(i, 1, n) {
			rep(j, 1, m){
				if (g[i][j] == 'G' || (i == n && j == m)) {
					for (register int k = -1; k <= 1; k += 2){
						if (ok(i + k, j) && g[i + k][j] == 'B') {
							printf("No\n");
							goto over;
						}
						if (ok(i, j + k) && g[i][j + k] == 'B') {
							printf("No\n");
							goto over;
						}
					}
				}
			}
		}
		rep(i, 1, n) {
			rep(j, 1, m){
				if (g[i][j] == 'B') {
					for (register int k = -1; k <= 1; k += 2){ 
						if (ok(i + k, j) && g[i + k][j] == '.'){
							g[i + k][j] = '#';
						}
						if (ok(i, j + k) && g[i][j + k] == '.'){
							g[i][j + k] = '#';
						}
					}
				}
			}
		}
		rep(i, 1, n){
			rep(j, 1, m){
				if (g[i][j] == '#') continue;
				if (!cc[i][j]) c++, dfs(i, j);
			}
		}
		rep(i, 1, n){
			rep(j, 1, m){
				if (g[i][j] == 'G') {
					if (cc[i][j] != cc[n][m]) {
						printf("No\n");
						goto over;
					}
				}
			}
		}
		printf("Yes\n");
		over: recover();
	} 
	return 0;
}


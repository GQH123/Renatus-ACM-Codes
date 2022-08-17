#include <bits/stdc++.h>
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
#define maxn 219
#define maxr 100000
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

int const INF = 1000000019;

char buffer[maxr], *p1, *p2;
template<class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}

int n;
char s[maxn][maxn];
int d[maxn][maxn];

int Floyd(){
	int ans = 0;
	rep(k, 1, n){
		rep(i, 1, n){
			rep(j, 1, n){
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	
	rep(i, 1, n) rep(j, 1, n) ans = max(ans, d[i][j]);
	return ans;
}

bool vis[maxn], col[maxn];
bool dfs(int x, bool c){
	vis[x] = 1, col[x] = c;
	rep(op, 1, n){
		if (s[x][op] == '1') {
			if (vis[op]) {
				if (col[op] != c ^ 1) return false;
			}
			else {
				if (!dfs(op, c ^ 1)) return false;
			}
		}
	}
	return true;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("B.in", "r", stdin);
	#endif
	scanf("%d", &n);
	rep(i, 1, n) scanf("%s", s[i] + 1);
	rep(i, 1, n) rep(j, 1, n) d[i][j] = (s[i][j] == '1') ? 1 : INF; 
	rep(i, 1, n) d[i][i] = 0;
	if (!dfs(1, 0)) printf("-1");
	else printf("%d", Floyd() + 1);
	return 0;
}

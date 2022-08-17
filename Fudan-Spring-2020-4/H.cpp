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
#define maxn 1020
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
int x[maxn], y[maxn];
int s[maxn][maxn], dp[maxn][maxn];
/*
int ti = 0, vis[maxn][maxn];
int DP(int l, int r){
	if (l == r){
		s[l][r] = l;
		return dp[l][r] = 0;
	}
	if (vis[l][r] == ti) return dp[l][r];
	vis[l][r] = ti; 
	int& ans = dp[l][r];
	bool f = 0;
	rep(i, s[l][r - 1], s[l + 1][r]){
		if (i >= r) break;
		int d = DP(l, i) + DP(i + 1, r) + y[i] + x[i + 1];
		if (!f) ans = d, s[l][r] = i, f = 1;
		else {
			if (d < ans) ans = d, s[l][r] = i;
		}
	}
	return ans;
}
*/

void DP(){
	rep(len, 1, n){
		rep(l, 1, n - len + 1){
			int r = l + len - 1;
			if (l == r){
				s[l][r] = l;
				dp[l][r] = 0;
				continue;
			} 
			int& ans = dp[l][r];
			bool f = 0;
			rep(i, s[l][r - 1], s[l + 1][r]){
				if (i >= r) break;
				int d = dp[l][i] + dp[i + 1][r] + y[i] - y[r] + x[i + 1] - x[l];
				if (!f) ans = d, s[l][r] = i, f = 1;
				else {
					if (d < ans) ans = d, s[l][r] = i;
				}
			} 
		}
	}
	printf("%d\n", dp[1][n]);
	rep(i, 1, n) rep(j, i, n) dp[i][j] = s[i][j] = 0;
}

int main(){
	
		freopen("H.in", "r", stdin);
		
	while (scanf("%d", &n) == 1){	
		//ti++;
		rep(i, 1, n) scanf("%d%d", x + i, y + i);
		DP();
		//printf("%d\n", DP(1, n));
	} 
	return 0;
}


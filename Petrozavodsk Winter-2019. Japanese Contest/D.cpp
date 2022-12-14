#include <bits/stdc++.h>
#define maxr 100000
#define maxn 4019
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template<class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}
char a[maxn], b[maxn];
int n, m;
int nexa[maxn][2], nexb[maxn][2];
int last[2];
int dp[maxn][maxn];
bool vis[maxn][maxn];

int DP(int x, int y){
	if (x > n && y > m) return 0;
	else if (vis[x][y]) return dp[x][y];
	vis[x][y] = 1;
	int& ans = dp[x][y];
	return ans = min(DP(nexa[x][0], nexb[y][0]), DP(nexa[x][1], nexb[y][1])) + 1;
}

int out[maxn];
void DFS(int x, int y, int pos){
	if (x > n && y > m) return;
	if (DP(nexa[x][0], nexb[y][0]) == DP(x, y) - 1) out[pos] = 0, DFS(nexa[x][0], nexb[y][0], pos + 1);
	else out[pos] = 1, DFS(nexa[x][1], nexb[y][1], pos + 1);
}
int main(){
	#ifndef ONLINE_JUDGE
		freopen("D.in", "r", stdin);
	#endif
	scanf("%s%s", a + 1, b + 1);
	n = strlen(a + 1), m = strlen(b + 1);
	last[0] = last[1] = n + 1;
	nexa[n + 1][0] = nexa[n + 1][1] = n + 1;
	per(i, n, 1){	
		nexa[i][0] = last[0], nexa[i][1] = last[1];
		last[a[i] - '0'] = i;
	}
	nexa[0][0] = last[0], nexa[0][1] = last[1];
	
	last[0] = last[1] = m + 1;
	nexb[m + 1][0] = nexb[m + 1][1] = m + 1;
	per(i, m, 0){
		nexb[i][0] = last[0], nexb[i][1] = last[1];
		last[b[i] - '0'] = i;
	}
	nexb[0][0] = last[0], nexb[0][1] = last[1];
	int len = DP(0, 0);
	DFS(0, 0, 1);
	rep(i, 1, len) printf("%d", out[i]);
	return 0;
}

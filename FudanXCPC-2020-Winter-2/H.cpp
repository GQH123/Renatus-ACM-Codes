#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
#define maxr 100000
#define maxn 220
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

int n, m;
char g[maxn][maxn];
bool vis[maxn][maxn][2];

void dfs(int x, int y, char c){
	if (vis[x][y][c - 'A']) return;
	vis[x][y][c - 'A'] = 1;
	g[x][y] = c;
	for (register int i = -1; i < 3; i += 2){
		if (1 <= x + i && x + i <= n) {
			if (g[x + i][y] == 'Z') dfs(x + 2 * i, y, c);
			else if (g[x + i][y] == 'X') dfs(x + i, y, c);
		}
		if (1 <= y + i && y + i <= m) {
			if (g[x][y + i] == 'Z') dfs(x, y + 2 * i, c);
			else if (g[x][y + i] == 'X') dfs(x, y + i, c);
		}
		/*for (register int j = -1; j < 3; j += 2){
			if (1 <= x + i && x + i <= n && 1 <= y + j && y + j <= m){
				if (
			}
		}*/
	}
}

int AB = (int)'A' + 'B';

void add(int x, int y, char c){
	if (vis[x][y][c - 'A']) return;
	vis[x][y][c - 'A'] = 1;
	for (register int i = -1; i < 3; i += 2){
		if (1 <= x + i && x + i <= n) {
			if (g[x + i][y] == '.' || g[x + i][y] == (char)(AB - (int)c)) add(x + i, y, c);
		}
		if (1 <= y + i && y + i <= m) {
			if (g[x][y + i] == '.' || g[x][y + i] == (char)(AB - (int)c)) add(x, y + i, c);
		}
		/*for (register int j = -1; j < 3; j += 2){
			if (1 <= x + i && x + i <= n && 1 <= y + j && y + j <= m){
				if (
			}
		}*/
	}
}

inline void debug(){
	rep(i, 1, n) printf("%s\n", g[i] + 1);
}

inline void debug2(){
	rep(i, 1, n) {
		rep(j, 1, m) {
			if (g[i][j] != '.') printf("%c", g[i][j]);
			else {
				if (vis[i][j][0] || vis[i][j][1]) printf("1");
				else printf("0");
			}
		}
		printf("\n");
	}
}

int main(){
	
		#ifndef ONLINE_JUDGE
			freopen("H.in", "r", stdin);
		#endif
	
	scanf("%d%d", &n, &m);
	rep(i, 1, n) scanf("%s", g[i] + 1); 
	rep(i, 1, n - 2) {
		rep(j, 1, m - 2){
			if (g[i][j] == '.' && g[i][j + 1] == 'X' && g[i][j + 2] == '.'
			 && g[i + 1][j] == 'X' && g[i + 1][j + 1] == 'X' && g[i + 1][j + 2] == 'X'
			 && g[i + 2][j] == '.' && g[i + 2][j + 1] == 'X' && g[i + 2][j + 2] == '.') g[i + 1][j + 1] = 'Z';
		}
	}
	rep(i, 1, n){
		rep(j, 1, m){
			if (g[i][j] == 'A') {
				dfs(i, j, 'A');
				goto jump;
			}
		}
	}
	jump:;
	rep(i, 1, n){
		rep(j, 1, m){
			if (g[i][j] == 'B') {
				dfs(i, j, 'B');
				goto jump2;
			}
		}
	}
	//jump2:debug();
	jump2:;
	
	rep(i, 1, n) rep(j, 1, m) vis[i][j][0] = vis[i][j][1] = 0;
	rep(i, 1, n) rep(j, 1, m){
		if (g[i][j] == 'A') {
			add(i + 1, j + 1, 'A');
			goto jump3;
		}
	}
	jump3:;
	rep(i, 1, n) rep(j, 1, m){
		if (g[i][j] == 'B') {
			add(i + 1, j + 1, 'B');
			goto jump4;
		}
	}
	//jump4:debug2();
	jump4:;
	int ansA = 0, ansB = 0, ansC = 0;
	rep(i, 1, n) rep(j, 1, m){
		if (g[i][j] != '.') continue;
		if (vis[i][j][0]) ansA++;
		if (vis[i][j][1]) ansB++;
		if (vis[i][j][0] && vis[i][j][1]) ansC++;
	}
	printf("%d %d %d\n", ansA - ansC, ansB - ansC, ansC);
	return 0;
}

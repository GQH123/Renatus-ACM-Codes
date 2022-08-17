#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
#define maxn 4020
#define maxm 40020
using namespace std;

int n;
int g[maxn][maxn];
bool vis[maxm << 1];
int fa[maxm << 1];
int d[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

inline bool ok(int x, int y){
	return 0 <= x && x < maxn && 0 <= y && y < maxn && g[x][y];
}

void dfs(int x, int y, int dx, int dy){
	printf("%d %d\n", x, y);
	int c = g[x][y];
	vis[c] = 1;
	g[x][y] = 0;
	rep(i, 0, 3){
		if (ok(x + d[i][0], y + d[i][1]) && g[x + d[i][0]][y + d[i][1]] != c && !vis[g[x + d[i][0]][y + d[i][1]]]){	
			fa[g[x + d[i][0]][y + d[i][1]]] = c;
			dfs(x + d[i][0], y + d[i][1], d[i][0], d[i][1]);
			return;
		}
	}
	if (ok(x + dx, y + dy) && (g[x + dx][y + dy] == c || g[x + dx][y + dy] == fa[c])) {dfs(x + dx, y + dy, dx, dy); return;}
	rep(i, 0, 3){
		if (ok(x + d[i][0], y + d[i][1]) && g[x + d[i][0]][y + d[i][1]] == c){	
			dfs(x + d[i][0], y + d[i][1], d[i][0], d[i][1]);
			return;
		}
	}
	
	rep(i, 0, 3){
		if (ok(x + d[i][0], y + d[i][1]) && g[x + d[i][0]][y + d[i][1]] == fa[c]){	
			dfs(x + d[i][0], y + d[i][1], d[i][0], d[i][1]);
			return;
		}
	}
	
	//if (ok(x + dx, y + dy)) {dfs(x + dx, y + dy, dx, dy); return;}
	//assert(false);
	/*
	if ((x & 1) && (y & 1)){
		if (ok(x + 1, y) && g[x + 1][y]) dfs(x + 1, y, 1, 0);
		if (ok(x, y + 1) && g[x][y + 1]) dfs(x, y + 1, 0, 1);
		if (ok(x + dx, y + dy) && g[x + dx][y + dy]) dfs(x + dx, y + dy, dx, dy);
		if (ok(x - 1, y) && g[x - 1][y]) dfs(x - 1, y, -1, 0);
		if (ok(x, y - 1) && g[x][y - 1]) dfs(x, y - 1, 0, -1);
	}
	else if (!(x & 1) && (y & 1)){
		
		if (ok(x, y + 1) && g[x][y + 1]) dfs(x, y + 1, 0, 1);
		if (ok(x - 1, y) && g[x - 1][y]) dfs(x - 1, y, -1, 0);
		if (ok(x + dx, y + dy) && g[x + dx][y + dy]) dfs(x + dx, y + dy, dx, dy);
		if (ok(x, y - 1) && g[x][y - 1]) dfs(x, y - 1, 0, -1);
		if (ok(x + 1, y) && g[x + 1][y]) dfs(x + 1, y, 1, 0);
	}
	else if (!(x & 1) && !(y & 1)){ 
		
		if (ok(x - 1, y) && g[x - 1][y]) dfs(x - 1, y, -1, 0);
		if (ok(x, y - 1) && g[x][y - 1]) dfs(x, y - 1, 0, -1);
		if (ok(x + dx, y + dy) && g[x + dx][y + dy]) dfs(x + dx, y + dy, dx, dy);
		if (ok(x + 1, y) && g[x + 1][y]) dfs(x + 1, y, 1, 0);
		if (ok(x, y + 1) && g[x][y + 1]) dfs(x, y + 1, 0, 1);
	}
	else {
		
		if (ok(x, y - 1) && g[x][y - 1]) dfs(x, y - 1, 0, -1);
		if (ok(x + 1, y) && g[x + 1][y]) dfs(x + 1, y, 1, 0);
		if (ok(x + dx, y + dy) && g[x + dx][y + dy]) dfs(x + dx, y + dy, dx, dy);
		if (ok(x, y + 1) && g[x][y + 1]) dfs(x, y + 1, 0, 1);
		if (ok(x - 1, y) && g[x - 1][y]) dfs(x - 1, y, -1, 0);
	}
	*/
}
int main(){
	scanf("%d", &n);
	int stx = 0, sty = 0, x, y;
	rep(i, 1, n) { 
		scanf("%d%d", &x, &y);
		if (i == 1) stx = x << 1, sty = y << 1; 
		g[x << 1][y << 1] = g[x << 1 | 1][y << 1] = g[x << 1][y << 1 | 1] = g[x << 1 | 1][y << 1 | 1] = i;
		
	}
	dfs(stx, sty, -10000, -10000);
	return 0;
}

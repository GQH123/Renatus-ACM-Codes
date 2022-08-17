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
#define maxn 220
#define maxm
using namespace std;

int n, m;
bool g[maxn][maxn], vis[maxn];
int lis[maxn], num[maxn];
int ct = 0;
bool dfs(int x){
	num[++ct] = x, vis[x] = 1;
	if (ct == n) {
		if (g[x][lis[1]]) return true;
		ct--, vis[x] = 0;
		return false;
	} 
	rep(i, 1, n) {
		if (vis[lis[i]] || !g[x][lis[i]]) continue;
		if (dfs(lis[i])) return true;
	}
	ct--, vis[x] = 0;
	return false;
}
int main(){
	srand(71806291);
	int x, y;
	while (scanf("%d%d", &n, &m) == 2){ 
		rep(i, 1, m) scanf("%d%d", &x, &y), g[x][y] = g[y][x] = 1;
		int NUM = 100; bool f = 0;
		while (NUM--){
			rep(i, 1, n) lis[i] = i, vis[i] = 0; ct = 0;
			random_shuffle(lis + 1, lis + 1 + n);
			if (dfs(lis[1])) {f = 1; break;}
		}
		if (!f) {
			int fuck_problem_setter = 0 / 0;
			assert(false);
			return -1;
		}
		printf("%d", num[1]); rep(i, 2, n) printf(" %d", num[i]); printf("\n");
		rep(i, 1, n) rep(j, 1, n) g[i][j] = 0; 
	}
	return 0;
}

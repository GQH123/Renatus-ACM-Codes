#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define ll long long int
#define ld long double
#define pb push_back
#define pc putchar
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define lowbit(x) (x & -x)
#define maxn 10
#define maxm 
#define maxb 
#define maxs 
#define M  
using namespace std;

int n = 8, m = 8;
char g[maxn][maxn];

inline bool ok(int i, int j){
	return 1 <= i && i <= n && 1 <= j && j <= m;
}
int walk(int x, int y, int dx, int dy){
	int _x = x + dx, _y = y + dy, l = 0;
	while (ok(_x, _y) && g[_x][_y] == 'L') _x += dx, _y += dy, l++;
	if (!(!ok(_x, _y) || g[_x][_y] != 'D' || l == 0)) return l;
	else return 0;
}
int getnum(int x, int y){
	int sum = 0;
	rep(i, -1, 1){
		rep(j, -1, 1){
			if (!i && !j) continue;
			sum += walk(x, y, i, j);
		}
	} 
	return sum;
}
int main(){
	int T;
	scanf("%d", &T);
	rep(TT, 1, T){
		printf("Case %d: ", TT);
		rep(i, 1, 8) scanf("%s", g[i] + 1);
		int mx = 0;
		rep(i, 1, 8) rep(j, 1, 8){
			if (g[i][j] != '*') continue;
			mx = max(mx, getnum(i, j));
		}
		printf("%d\n", mx);
	} 
	return 0;
}

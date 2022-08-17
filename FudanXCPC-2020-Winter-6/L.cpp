#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int
#define maxn 2020
#define maxm 
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define lowbit(x) (x & -x)
using namespace std;

int n, m;
char g[maxn][maxn];

int c[maxn][maxn];
void add(int x, int y, int v){
	int _y = y;
	while (x <= n){
		y = _y;
		while (y <= m){
			c[x][y] += v;
			y += lowbit(y);
		}
		x += lowbit(x);
	}
}
int get(int x, int y){
	int ans = 0, _y = y;
	while (x){
		y = _y;
		while (y){
			ans += c[x][y];
			y -= lowbit(y);
		}
		x -= lowbit(x);
	}
	return ans;
}

int get(int x1, int y1, int x2, int y2){
	return get(x2, y2) + get(x1 - 1, y1 - 1) - get(x2, y1 - 1) - get(x1 - 1, y2);
}
bool judge(int r){
	if (r <= 2){
		rep(i, 1, n){
			if (i + r - 1 > n) break;
			rep(j, 1, m){
				if (j + r - 1 > m) break; 
				rep(_i, i, i + r - 1){
					char now = g[_i][j];
					rep(_j, j, j + r - 1){
						if (g[_i][_j] != now) goto jump; 
					}
				}
				return true;
				jump:;
			}
		}
		return false;
	}
	else {
		rep(i, 1, n){
			if (i + r - 1 > n) break;
			rep(j, 1, m){
				if (j + r - 1 > m) break;
				if (!get(i, j + 1, i + r - 1, j + r - 2)) return true;
			}
		}
		return false;
	}
	return false;
}

int solve(int l, int r){
	if (l == r) return l;
	int mid = ((r - l + 1) >> 1) + l;
	if (judge(mid)) return solve(mid, r);
	else return solve(l, mid - 1);
}

int main(){
	freopen("L.in", "r", stdin);
	scanf("%d%d", &n, &m);
	rep(i, 1, n) scanf("%s", g[i] + 1);
	rep(i, 1, n){
		srep(j, 1, m){
			if (g[i][j] != g[i][j + 1]) {
				add(i, j, 1), add(i, j + 1, 1);
			}
		}
	}
	int c = solve(1, min(n, m));
	printf("%d", c * c);
	return 0;
}


#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define pii pair<int, int>
#define fi first
#define se second
#define ll long long int 
#define pb push_back
#define lowbit(x) (x & -x)
#define maxn 30
#define maxm 
#define M 
using namespace std;

int n, m;
char g[maxn][maxn];

int main(){
	
		freopen("A.in", "r", stdin);
		
	int T;
	scanf("%d", &T);
	while (T--){
		scanf("%d%d", &n, &m);
		rep(i, 1, n) scanf("%s", g[i] + 1);
		int mxr = 0, mxx = -1, mxy = -1;
		rep(i, 1, n) {
			int now = 0, l = -1, r = -1;
			rep(j, 1, m) if (g[i][j] == '.') now++;
			if (now > mxr) {
				mxr = now, mxx = i; 
				rep(j, 1, m) {if (g[i][j] == '.') {l = j; break;}}
				per(j, m, 1) {if (g[i][j] == '.') {r = j; break;}}
				mxy = (l + r) >> 1;
			}
		}
		printf("%d %d %d\n", mxr >> 1, mxx, mxy);
	}
	return 0;
}

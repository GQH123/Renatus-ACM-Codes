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
#define maxn 
#define maxm
using namespace std;

int a[60], p[60], n, L, R;

bool vis[60];
int loop[60][60];
int len[60];
int cl = 0;
void dfs(int x){
	if (vis[x]) return;
	vis[x] = 1;
	loop[cl][++len[cl]] = x;
	dfs(p[x]);
}
int out[60];

int main(){
	int T; scanf("%d", &T);
	rep(TT, 1, T){
		printf("Case #%d:", TT);
		rep(i, 1, 52) scanf("%d", a + i);
		scanf("%d%d%d", &n, &L, &R);
		int ptr = L;
		rep(i, 1, R - L + 1) p[i] = i + L - 1; 
		rep(i, R - L + 2, R) p[i] = i - (R - L + 1); 
		rep(i, R + 1, 52) p[i] = i;
		rep(i, 1, 52) if (!vis[i]) ++cl, dfs(i); 
		rep(i, 1, cl){
			int offset = n % len[i];
			int x = loop[i][1], y = x;
			rep(j, 1, offset) y = p[y];
			rep(j, 1, len[i]) {
				out[x] = a[y];
				x = p[x], y = p[y];
			}
		}
		rep(i, 1, 52) printf(" %d", out[i]);
		printf("\n");
		
		rep(i, 1, 52) vis[i] = 0;
		rep(i, 1, cl) len[i] = 0;
		cl = 0;
	}
	return 0;
}

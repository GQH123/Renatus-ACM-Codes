#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define maxn 2000020
#define ll long long int 
using namespace std;

int n, cs = 0, ans[maxn], a[maxn], to[maxn], vis[maxn];

int main(){
	
		freopen("D.in", "r", stdin);
		
	ios :: sync_with_stdio(false), cin.tie(0);
	int T;
	scanf("%d", &T);
	while (T--){
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", a + i), to[i] = i - a[i];
		int x = 1;
		while (1){
			if (!vis[x]) vis[x]++;
			else if (vis[x] == 1) vis[x]++, ans[++cs] = x;
			else break;
			x = to[x];
		}
		printf("%d\n", cs);
		rep(i, 1, cs) printf("%d ", ans[i]);
		printf("\n");
		
		rep(i, 1, n) vis[i] = 0;
		cs = 0;
	}
	return 0;
}
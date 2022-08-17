#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define pii pair<int, int>
#define fi first
#define se second
#define maxn 200019
using namespace std;

int n, t;
pii p[maxn];

int main(){
	//#ifndef ONLINE_JUDGE
	//	freopen("A.in", "r", stdin);
	//#endif
	int T;
	scanf("%d", &T);
	rep(TT, 1, T){	
		scanf("%d%d", &n, &t);
		rep(i, 1, n) scanf("%d", &p[i].fi);
		rep(i, 1, n) scanf("%d", &p[i].se);
		sort(p + 1, p + 1 + n);
		int ans = 0;
		rep(i, 1, n){
			if (t < p[i].se) break; 
			t -= p[i].se;
			ans++;
		}
		printf("Case %d: %d\n", TT, ans);
	}
	return 0;
}

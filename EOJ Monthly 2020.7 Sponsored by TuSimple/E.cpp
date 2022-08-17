#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define pii pair<int, int>
#define pli pair<ll, int>
#define fi first
#define se second
#define ll long long int 
#define mo(x) (x = (x >= M) ? (x - M) : x)
#define maxn 100020
#define maxm
using namespace std;

int n;
pli fac[maxn];
ll ans[maxn], cs = 0;
void dfs(int pos, ll& now){ //0 dec, 1 inc
	if (!pos) {ans[++cs] = now; return; }
	if (now % fac[pos].fi){
		rep(i, 1, fac[pos].se){
			dfs(pos - 1, now);
			now *= fac[pos].fi;
		}
		dfs(pos - 1, now);
	}
	else {
		rep(i, 1, fac[pos].se){
			dfs(pos - 1, now);
			now /= fac[pos].fi;
		}
		dfs(pos - 1, now);
	}  
}

int main(){
	scanf("%d", &n);
	ll a = 1;
	rep(i, 1, n) {
		scanf("%lld%d", &fac[i].fi, &fac[i].se);
		rep(j, 1, fac[i].se) a *= fac[i].fi;
	}
	dfs(n, a);
	//cerr << "num:" << cs << endl;
	rep(i, 1, cs) printf("%lld\n", ans[i]);
	return 0;
}

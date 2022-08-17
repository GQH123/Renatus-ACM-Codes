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
#define maxn 2020
#define maxm
using namespace std;

const int inf = 2000000000;

int n;

namespace PRE{
	bool dp[maxn]; int dp2[maxn];
	pii a[maxn]; int ct;
	/*
	bool cmp(const pii& a, const pii& b){
		return a.fi - a.se < b.fi - b.se;
	}
	*/
	bool cmp(const pii& a, const pii& b){
		return a.fi < b.fi ;
	}
	void play(){
		sort(a + 1, a + 1 + ct, cmp);
		rep(i, 1, n) dp[i] = false, dp2[i] = inf;
		dp[0] = true, dp2[0] = 0;
		rep(i, 1, ct) {
			per(len, a[i].fi - a[i].se, 0) {
				if (!dp[len]) continue;
				dp[len + a[i].se] = true;
				dp2[len + a[i].se] = min(dp2[len + a[i].se], dp2[len] + 1);
			}
		}
	}
}
namespace SUF{	
	bool dp[maxn]; int dp2[maxn];
	pii a[maxn]; int ct;
	/*
	bool cmp(const pii& a, const pii& b){
		return n - a.fi + 1 - a.se < n - b.fi + 1 - b.se;
	}
	*/
	bool cmp(const pii& a, const pii& b){
		return a.fi > b.fi;
	}
	void play(){
		sort(a + 1, a + 1 + ct, cmp);
		rep(i, 1, n) dp[i] = false, dp2[i] = inf;
		dp[0] = true, dp2[0] = 0;
		rep(i, 1, ct) {
			per(len, n - a[i].fi + 1 - a[i].se, 0) {
				if (!dp[len]) continue;
				dp[len + a[i].se] = true;
				dp2[len + a[i].se] = min(dp2[len + a[i].se], dp2[len] + 1);
			}
		}
	}
}

int main(){
	int T, s, x, y, k; scanf("%d", &T);
	rep(TT, 1, T){
		printf("Case %d: ", TT);
		scanf("%d%d", &n, &k);
		rep(i, 1, k) {	
			scanf("%d%d%d", &s, &x, &y);
			if (s == 1) PRE :: a[++PRE :: ct] = pii(x, y);
			else SUF :: a[++SUF :: ct] = pii(x, y); 
		}
		PRE :: play(), SUF :: play();
		int mxl = -1, mio = inf;
		rep(i, 0, n) {
			if (!PRE :: dp[i]) continue;
			per(j, n - i, 0) {
				if (!SUF :: dp[j]) continue;
				if (i + j > mxl) mxl = i + j, mio = PRE :: dp2[i] + SUF :: dp2[j];
				else if (i + j == mxl) mio = min(mio, PRE :: dp2[i] + SUF :: dp2[j]);  
				break;
			}
		}
		printf("%d %d\n", mxl, mio);
		PRE :: ct = SUF :: ct = 0;
	}
	return 0;
}

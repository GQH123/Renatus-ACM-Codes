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
#define maxn 20
#define maxm 
#define maxb 
#define maxs 
#define M  
using namespace std;

const int inf = 2000000000;

int n;
pii p[maxn];
int ok = 0, all = 0;
inline double dist(int i, int j){	
	return sqrt(1.0 * (p[i].fi - p[j].fi) * (p[i].fi - p[j].fi) + 1.0 * (p[i].se - p[j].se) * (p[i].se - p[j].se));
}
void upd(double v, double& mi, double& mi2){
	if (v < mi) mi2 = mi, mi = v;
	else if (v < mi2) mi2 = v;
}
double dp[1 << maxn];
bool vis[1 << maxn];
double DP(int op){
	if (op == all) return 0;
	if (vis[op]) return dp[op];
	vis[op] = 1;
	double& ans = dp[op]; ans = inf;
	srep(i, 0, n){
		if (!(op & (1 << i))) {
			double mi = inf, mi2 = inf;
			srep(j, 0, n){
				if (op & (1 << j)) upd(dist(i + 1, j + 1), mi, mi2);
			}
			ans = min(ans, DP(op | (1 << i)) + mi + mi2);
		}
	}
	return ans;
}

int main(){
	int x, y;
	while (scanf("%d", &n) && n){
		int num = 0;
		ok = all = 0;
		rep(i, 1, n){
			scanf("%d%d", &x, &y), p[i] = pii(x, y);
			scanf("%d", &x); 
			if (x) ok |= (1 << (i - 1)), num++;
			all |= (1 << (i - 1));
		} 
		if (num <= 1) {
			if (n == 1) {
				if (num == 1) printf("%.6lf\n", 0.0);
				else printf("No Solution\n");
			}
			else printf("No Solution\n");
		}
		else {
			printf("%.6lf\n", DP(ok)); 
			rep(i, 0, all) dp[i] = vis[i] = 0;
		}
	}
	return 0;
}

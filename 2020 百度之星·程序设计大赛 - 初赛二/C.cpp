#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define maxn 
#define maxm 
#define M 
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
using namespace std;

vector<int> G[105][15];
bool is[30020];

int main(){
	int T, x, y, n, k; scanf("%d", &T);
	while (T--){
		scanf("%d", &n); 
		rep(i, 1, n) {
			is[i] = 0;
			scanf("%d", &k);
			rep(j, 1, k) {
				scanf("%d%d", &x, &y);
				G[x][y].pb(i);
			}
		}
		is[1] = 1;
		rep(t, 1, 100) rep(p, 1, 10) {
			int si = G[t][p].size();
			bool hav = 0;
			srep(i, 0, si) if (is[G[t][p][i]]) {hav = 1; break;}
			if (!hav) continue;
			srep(i, 0, si) is[G[t][p][i]] = 1; 
		}
		bool first = 1;
		rep(i, 1, n) {
			if (is[i]) {
				if (first) printf("%d", i), first = 0;
				else printf(" %d", i);
			}
		}
		printf("\n");
		rep(t, 1, 100) rep(p, 1, 10) G[t][p].clear();
	} 
	return 0;
}

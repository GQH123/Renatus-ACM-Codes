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
#define maxn 200020
#define maxm
using namespace std;

int n, m, k, q;
map<int, int> idx, idy;
int ctx, cty;
pii p[maxn];
map<pii, int> cc;

int main(){
	int T, x, y, op; scanf("%d", &T);
	rep(TT, 1, T){
		printf("Case #%d:\n", TT);
		scanf("%d%d%d", &n, &m, &k);
		rep(i, 1, k) {
			scanf("%d%d%d", &p[i].fi, &p[i].se, &x); 
			if (!idx.count(p[i].fi)) idx[p[i].fi] = ++ctx;
			if (!idy.count(p[i].se)) idy[p[i].se] = ++cty;
			cc[pii(idx[p[i].fi], idy[p[i].se])] += x;
		}
		scanf("%d", &q);
		rep(i, 1, q){
			scanf("%d%d%d", &op, &x, &y);
			if (op == 1){
				if (!idx.count(x) || !idx.count(y)) continue; 
				swap(idx[x], idx[y]);
			}
			else if (op == 2){
				if (!idy.count(x) || !idy.count(y)) continue;
				swap(idy[x], idy[y]);
			}
			else if (op == 3){
				if (!idx.count(x) || !idy.count(y)) continue; 
				printf("%d\n", cc[pii(idx[x], idy[y])]);
			}
		}
		
		idx.clear(), idy.clear(), cc.clear(); ctx = cty = 0;
	}
	return 0;
}

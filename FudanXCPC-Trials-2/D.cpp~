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
#define lowbit(x) (x & -x)
using namespace std;

const int inf = 2000000000;

int n, m;
int c[maxn], c2[maxn];
void add(int x, int v, int id){
	while (x){
		if (c[x] > v){
			c[x] = v;
			c2[x] = id;
		}
		x -= lowbit(x);
	}
}
int get(int x){
	int ans = inf, id = n + 1;
	while (x <= n){
		if (ans > c[x]) {
			ans = c[x];
			id = c2[x];
		}
		x += lowbit(x);
	}
	return id;
}

pii p[maxn];
int nxt[maxn][20];
int play(int x, int y){
	int st = lower_bound(p + 1, p + 1 + n, pii(x, -inf)) - p, ans = 0;
	st = get(st);
	if (p[st].se > y) return 0;
	per(i, 19, 0) if (p[nxt[st][i]].se <= y) st = nxt[st][i], ans += (1 << i); 
	return ans + 1;
}

int main(){
	int x, y;
	while (scanf("%d%d", &n, &m) == 2){
		rep(i, 1, n) c[i] = inf, c2[i] = n + 1;
		rep(i, 1, n) scanf("%d%d", &p[i].fi, &p[i].se);
		sort(p + 1, p + 1 + n);
		per(i, n, 1){
			int st = lower_bound(p + 1, p + 1 + n, pii(p[i].se, -inf)) - p;
			nxt[i][0] = get(st);
			add(i, p[i].se, i);
		}
		p[n + 1] = pii(inf, inf);
		rep(bit, 1, 19) rep(i, 1, n) nxt[i][bit] = (nxt[i][bit - 1] == n + 1) ? n + 1 : nxt[nxt[i][bit - 1]][bit - 1];
		rep(i, 1, m) scanf("%d%d", &x, &y), printf("%d\n", play(x, y));
	}
	return 0;
}

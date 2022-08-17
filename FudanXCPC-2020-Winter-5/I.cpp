#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int
#define maxn 520
#define maxm 
#define maxq 300020
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back

using namespace std;

const int inf = 2000000020;

int n, m, q;
int d[maxn][maxn];
int g[maxn][maxn];
int t[maxn], lis[maxn];

struct pla{
	int id, t;
	pla(int id, int t) : id(id), t(t){}
	pla(){}
	bool operator < (const pla b) const{
		return t < b.t;
	}
}pl[maxn];

struct cli{
	int id, x, y, k, t;
	cli(int id, int x, int y, int k, int t) : id(id), x(x), y(y), k(k), t(t){}
	cli(){}
	bool operator < (const cli b) const{
		return k < b.k;
	}
}cl0[maxq], cl1[maxq];
int ct0, ct1;

int out[maxq];

int main(){
	freopen("I.in", "r", stdin);
	
	int x, y, z, w;
	scanf("%d%d", &n, &m);
	rep(i, 1, n) scanf("%d", &t[i]), lis[i] = t[i], pl[i] = pla(i, t[i]);
	sort(pl + 1, pl + 1 + n);
	sort(lis + 1, lis + 1 + n);
	int _n = unique(lis + 1, lis + 1 + n) - lis - 1;
	rep(i, 1, n) rep(j, 1, n) g[i][j] = inf;
	rep(i, 1, m){
		scanf("%d%d%d", &x, &y, &z);
		g[x][y] = g[y][x] = z;
	}
	scanf("%d", &q);
	rep(i, 1, q) {
		scanf("%d%d%d%d", &x, &y, &z, &w); 
		if (!w) cl0[++ct0] = cli(i, x, y, z, w);
		else cl1[++ct1] = cli(i, x, y, z, w);
	}
	sort(cl0 + 1, cl0 + 1 + ct0);
	sort(cl1 + 1, cl1 + 1 + ct1);
	
	
	rep(i, 1, n) rep(j, 1, n) d[i][j] = g[i][j];
	int ptr = 1;
	rep(i, 1, ct0){
		cli op = cl0[i];
		int nowt = lis[min(op.k, _n)];
		while (ptr <= n && pl[ptr].t <= nowt){
			int x = pl[ptr].id;
			rep(j, 1, n){
				rep(k, 1, n){
					if (d[j][x] < inf && d[x][k] < inf)
						d[j][k] = min(d[j][k], d[j][x] + d[x][k]);
				}
			}
			ptr++;
		}
		out[op.id] = (d[op.x][op.y] == inf) ? -1 : d[op.x][op.y];
	}
	
	rep(i, 1, n) rep(j, 1, n) d[i][j] = g[i][j];
	ptr = n;
	rep(i, 1, ct1){
		cli op = cl1[i];
		int nowt = lis[_n + 1 - min(op.k, _n)];
		while (ptr >= 1 && pl[ptr].t >= nowt){
			int x = pl[ptr].id;
			rep(j, 1, n){
				rep(k, 1, n){
					if (d[j][x] < inf && d[x][k] < inf)
						d[j][k] = min(d[j][k], d[j][x] + d[x][k]);
				}
			}
			ptr--;
		}
		out[op.id] = (d[op.x][op.y] == inf) ? -1 : d[op.x][op.y];
	}
	
	rep(i, 1, q) printf("%d\n", out[i]);
	return 0;
}


/*


7 9
-53 -180 456 420 -210 15 150
1 2 2
1 3 1
2 3 4
2 4 2
2 5 5
3 4 6
6 4 10
4 5 4
3 7 2
4
1 5 2 1
1 2 1 1
5 6 1 0
1 7 2 1




6 5
5 10 20 10 10 8
1 2 5
2 3 5
3 4 5
4 5 5
5 6 5
4
1 6 2 1
1 6 1 1
4 5 1 0
2 4 1 1


*/


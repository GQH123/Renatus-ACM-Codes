#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define maxn 200020
#define maxm 400020
#define ll long long int 
using namespace std;

int n, m, d[maxn];
struct edge{
	int id, next, to;
	edge(int id, int next, int to) : id(id), next(next), to(to){}
	edge(){}
}e[maxm << 1];
int cnt = 1, h[maxn];
int v[maxm];
void Add_Edge(int id, int x, int y){
	e[++cnt] = edge(id, h[x], y);
	h[x] = cnt;
	e[++cnt] = edge(id, h[y], x);
	h[y] = cnt;
}
struct point{
	int id, d;
	point(int id, int d) : id(id), d(d){}
	point(){}
	bool operator < (const point b) const{
		return (d == b.d) ? id < b.id : d < b.d;
	}
}p[maxn];

int c[maxn];

int main(){
	
		//freopen("E.in", "r", stdin);
		
	int x, y;
	scanf("%d%d", &n, &m);
	rep(i, 1, n) scanf("%d", &d[i]), p[i] = point(i, d[i]);
	sort(p + 1, p + 1 + n);
	rep(i, 1, m) scanf("%d%d", &x, &y), Add_Edge(i, x, y);
	rep(j, 1, n){ 
		int x = p[j].id;
		if (c[x]) continue;
		assert(p[j].d == d[x]);
		bool f = 0;
		erep(i, x){
			int op = e[i].to;
			if (c[op]){
				v[e[i].id] = d[x];
				c[x] = 3 - c[op];
				f = 1;
				break;
			}
		}
		if (!f){
			bool f2 = 0;
			erep(i, x){
				int op = e[i].to;
				if (!c[op] && d[op] == d[x]){
					c[op] = 1, c[x] = 2, v[e[i].id] = d[x];
					f2 = 1;
					break;
				}
			}
			if (!f2) {
				printf("-1");
				return 0;
			}
		}
	}
	rep(i, 1, n){
		if (c[i] == 1) printf("B");
		else printf("W");
	}
	printf("\n");
	rep(i, 1, m){
		if (!v[i]) printf("1000000000\n");
		else printf("%d\n", v[i]);
	}
	return 0;
}

#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define pdi pair<double, int>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define ll long long int 
#define pb push_back
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn 60020
#define maxm 3000020
#define maxs
#define maxb 
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

const int inf = 2000000000;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}
int _num[20];
template <class T> void write(T x){	
	if (!x) {putchar('0'), putchar('\n'); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar('\n');
}

int n, s, t, M;
struct edge{
	int next, to;
	double len;
	edge(int next, int to, double len) : next(next), to(to), len(len){}
	edge(){}
}e[maxm];
int cnt = 1, h[maxn];
void Add_Edge(int x, int y, double z){	
	e[++cnt] = edge(h[x], y, z);
	h[x] = cnt;
}
double d[maxn];
bool vis[maxn];
priority_queue<pdi> pq;
void Dij(){
	if (s == t) {
		printf("0.00\n");
		return;
	}
	rep(i, 1, n) vis[i] = 0, d[i] = inf;
	d[s] = 0;
	pq.push(pdi(d[s], s));
	while (!pq.empty()){
		pdi op = pq.top(); pq.pop();
		if (vis[op.se]) continue;
		int x = op.se; vis[x] = 1;
		erep(i, x){
			int op = e[i].to;
			if (d[op] > d[x] + e[i].len) {
				d[op] = d[x] + e[i].len;
				pq.push(pdi(-d[op], op));
			} 
		}
	}
	if (d[t] == inf) printf("IMPOSSIBLE!\n");
	else printf("%.2lf\n", M - exp(log(M) - d[t]));
}

int main(){
	

		
	int x, y, z;
	while (scanf("%d", &n) == 1){
		rep(i, 1, n){
			scanf("%d", &x); 
			rep(j, 1, x){
				scanf("%d%d", &y, &z);
				Add_Edge(i, y, -log(1.0 - 1.0 * z / 100));
			}
		}
		scanf("%d%d%d", &s, &t, &M);
		Dij();
		cnt = 1; rep(i, 1, n) h[i] = 0;
	} 
	return 0;
}

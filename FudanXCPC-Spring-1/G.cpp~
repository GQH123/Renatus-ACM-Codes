#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define pii pair<int, int>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define ll long long int 
#define pb push_back
#define pc putchar
#define lowbit(x) (x & -x) 
#define maxn 5020
#define maxm 100005
#define maxk 52
#define maxs
#define maxb
#define M 
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std; 

const int inf = 2000000020;
int n, m, x[maxm], y[maxm], z[maxm], siz, offset;
struct edge{
	int next, to, len;
	edge(int next, int to, int len) : next(next), to(to), len(len){}
	edge(){}
}e[maxm << 1];
int cnt = 1, h[maxn];
void Add_Edge(int x, int y, int c){
	e[++cnt] = edge(h[x], y, c);
	h[x] = cnt; 
}
bool vis[maxk * maxn];
int d[maxk * maxn];
priority_queue<pii> pq;
int Dij(int s, int t){
d[s] = 0;
	pq.push(pii(0, s));
	while (!pq.empty()) {
		pii op = pq.top(); pq.pop();
		if (vis[op.se]) continue;
		int x = op.se, _x = (x - 1) % n + 1;
		vis[x] = 1;
		if (offset < x){
			erep(i, _x){
				int op = e[i].to, _op = op + offset;
				if (vis[_op] || d[x] + e[i].len > d[_op]) continue;
				d[_op] = d[x] + e[i].len;
				pq.push(pii(-(d[x] + e[i].len), _op));
			}
		}
		else {
			erep(i, _x){
				int op = e[i].to, _op = op + ((x - 1) / n + 1) * n;
				if (vis[_op] || d[x] + e[i].len > d[_op]) continue;
				d[_op] = d[x] + e[i].len;
				pq.push(pii(-(d[x] + e[i].len), _op));
			}
		} 
	}
	if (d[t] == inf) return -1;
	return d[t];
} 
//1 + offset ~ n + offset

int s, t, k;

int main(){
	
		freopen("G.in", "r", stdin); 
	while (scanf("%d", &n) == 1){
		scanf("%d", &m);
		rep(i, 1, m) scanf("%d%d%d", x + i, y + i, z + i);
		scanf("%d%d%d", &s, &t, &k);
		siz = ((k) ? ((k - 1) / 10 + 1) : 0); offset = n * siz;
		rep(i, 1, n + offset) vis[i] = 0, d[i] = 2000000020;
		rep(i, 1, m) Add_Edge(x[i], y[i], z[i]), Add_Edge(y[i], x[i], z[i]);
		printf("%d\n", (Dij(s, t + offset)));  
		rep(i, 1, n) h[i] = 0; cnt = 1;
	}	
	return 0;
}


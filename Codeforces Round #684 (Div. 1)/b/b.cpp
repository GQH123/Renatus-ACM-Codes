#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define ll long long int 
#define pb push_back
#define pc putchar
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn 300020
#define maxm
#define maxs
#define maxb
#define M 
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}
int _num[20];
template <class T> void write(T x, char sep = '\n'){	
	if (!x) {putchar('0'), putchar(sep); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar(sep);
}

int n, m, k;
struct edge{
	int next, to;
	edge(int next, int to) : next(next), to(to){}
	edge(){}
}e[maxn << 1];
int h[maxn], cnt = 1, deg[maxn];
void Add_Edge(int x, int y) {
	e[++cnt] = edge(h[x], y); h[x] = cnt;
	e[++cnt] = edge(h[y], x); h[y] = cnt;
	deg[x]++, deg[y]++;
}
int lis[maxn], head = 0, tail = 0; bool vis[maxn];
int _lis[maxn], _deg[maxn];
int res[maxn], ans = 0;
priority_queue<pii> pq;
int main(){
	int T, x, y; read(T);
	while (T--){
		read(n), read(m), read(k); 
		rep(i, 1, m) read(x), read(y), Add_Edge(x, y);
		
		rep(i, 1, n) vis[i] = 0, _deg[i] = deg[i]; head = tail = 0;
		rep(i, 1, n) if (deg[i] < k) lis[++head] = i, vis[i] = 1; 
		while (head != tail){
			int x = lis[++tail];
			erep(i, x){
				int op = e[i].to;
				if (vis[op]) continue;
				deg[op]--;
				if (deg[op] < k) vis[op] = 1, lis[++head] = op;
			}
		}
		ans = 0; rep(i, 1, n) if (!vis[i]) res[++ans] = i;
		if (ans) {
			printf("1 %d\n", ans);
			rep(i, 1, ans) printf("%d ", res[i]);
			printf("\n");
			continue;
		}
		
		rep(i, 1, n) vis[i] = 0, deg[i] = _deg[i]; head = tail = 0;
		rep(i, 1, n) if (deg[i] < k - 1) lis[++head] = i, vis[i] = 1; 
		while (head != tail){
			int x = lis[++tail];
			erep(i, x){
				int op = e[i].to;
				if (vis[op]) continue;
				deg[op]--;
				if (deg[op] < k - 1) vis[op] = 1, lis[++head] = op;
			}
		}
		rep(i, 1, n) if (!vis[i] && deg[i] == k - 1) pq.push(pii(-deg[i], i));
		while (!pq.empty()){
			pii op = pq.top(); pq.pop();
			int x = op.se;
			erep(i, x){
				int u = e[i].to;
				if (
			}
		} 
	}
	return 0;
}


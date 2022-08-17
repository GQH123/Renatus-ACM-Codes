#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define pii pair<int, int>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define ll long long int 
#define pb push_back
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn 1020
#define maxm
#define maxs
#define maxb
#define M 
#define Flow unsigned int
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

const int inf = (1ll << 31) - 1;

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

ui n, m, S, T;
struct edge{
	ui next, to, flow;
	edge(ui next, ui to, ui flow) : next(next), to(to), flow(flow){}
	edge(){}
}e[maxn * maxn * 3];
ui cnt = 1, h[maxn * maxn];
void Add_Edge(ui x, ui y, ui c){
	e[++cnt] = edge(h[x], y, c);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x, 0);
	h[y] = cnt;
}
ui a[maxn][maxn], c[maxn];
int bfs[maxn * maxn], head, tail, cur[maxn * maxn], d[maxn * maxn];
void recover(){
	cnt = 1; rep(i, 1, n) h[i] = 0;
}
bool BFS(){
	rep(i, 1, n) d[i] = -1, cur[i] = h[i];
	head = tail = 0, d[S] = 0;
	bfs[++head] = S;
	while (tail < head){
		int x = bfs[++tail];
		erep(i, x){
			if (!e[i].flow || d[e[i].to] != -1) continue;
			int op = e[i].to;
			d[op] = d[x] + 1;
			bfs[++head] = op;
		}
	}
	return d[T] != -1;
}
Flow DFS(int x, Flow flow){
	if (x == T) return flow;
	Flow rest = flow;
	erep2(i, x){
		if (!e[i].flow || d[e[i].to] != d[x] + 1) continue;
		int op = e[i].to;
		Flow k = DFS(op, min(rest, e[i].flow)); //注意，此处应使用 rest 进行比较而非 flow ，这个错误在某些 OJ 上甚至不会被检测出来
		e[i].flow -= k, e[i ^ 1].flow += k, rest -= k;
		if (!rest) return flow;
	}
	return flow - rest;
}
Flow Dinic(){
	Flow maxflow = 0, k = 0;
	while (BFS()) {
		while (k = DFS(S, inf)) {
			maxflow += k; 
		}
	}
	return maxflow;
}
int main(){
	
		freopen("F.in", "r", stdin);
		
	int TT;
	read(TT);
	while(TT--){
		read(n);
		rep(i, 1, n) rep(j, 1, n) read(a[i][j]);
		rep(i, 1, n) read(c[i]);
		S = 1, T = (n * (n + 3) >> 1) + 2;
		int cs = 1, _cs = (n * (n + 1) >> 1) + 1;
		ui ans = 0;
		rep(i, 1, n){
			rep(j, i + 1, n){
				cs++;
				Add_Edge(S, cs, a[i][j] + a[j][i]);
				Add_Edge(cs, _cs + i, inf);
				Add_Edge(cs, _cs + j, inf);
				//Add_Edge(cs, T, c[i] + c[j]);
				ans += a[i][j] + a[j][i];
			}
		}
		rep(i, 1, n){
			cs++;
			Add_Edge(S, cs, a[i][i]);
			Add_Edge(cs, _cs + i, inf);
			Add_Edge(_cs + i, T, c[i]);
			ans += a[i][i];
		}
		n = T;
		ans -= Dinic();
		printf("%d\n", ans);
		recover();
	}
	return 0;
}


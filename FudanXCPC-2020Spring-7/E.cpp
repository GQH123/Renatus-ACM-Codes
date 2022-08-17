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
#define maxn 3020
#define maxm 400020
#define maxs
#define maxb
#define M 
#define Flow ll
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

ll inf = 9223372036854775807ll;

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

int n, m, S, T, num[maxn];

struct edge{
	int next, to; Flow flow;
	edge(int next, int to, Flow flow) : next(next), to(to), flow(flow){}
	edge(){}
}e[maxm << 1];
int cnt = 1, h[maxn];
void Add_Edge(int x, int y, Flow z){
	e[++cnt] = edge(h[x], y, z);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x, 0);
	h[y] = cnt;
}
int bfs[maxn], head, tail, cur[maxn], d[maxn];
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
		Flow k = DFS(op, min(rest, e[i].flow)); 
		e[i].flow -= k, e[i ^ 1].flow += k, rest -= k;
		if (!rest) return flow;
	}
	return flow - rest;
}
Flow Dinic(){
	Flow maxflow = 0, k = 0;
	while (BFS()) while (k = DFS(S, inf)) maxflow += k; 
	return maxflow;
}

int id[maxn][maxn];
ll v[maxn][maxn];

int main(){
	
		//freopen("E.in", "r", stdin);
		
	//ios :: sync_with_stdio(false), cin.tie(0);
	//IMPOSSIBLE, POSSIBLE
	
	
	ll _T, x, y, w, k;
	read(_T);
	rep(TT, 1, _T){
		printf("Case #%d: ", TT);
		S = 1, T = 2;
		read(n);
		rep(i, 1, n){
			read(k), num[i] = k;
			rep(j, 1, k){
				read(x), read(y), read(w);
				id[i][j] = T++, v[i][j] = y - x;
				rep(t, 1, w){
					read(x), read(y);
					Add_Edge(id[i][j], id[x][y], inf);
				}
			}
		}
		ll sum = 0;
		rep(i, 1, n){
			rep(j, 1, num[i]){
				if (v[i][j] >= 0) Add_Edge(S, id[i][j], v[i][j]), sum += v[i][j];
				else Add_Edge(id[i][j], T, -v[i][j]);
			}
		}
		n = T;
		sum -= Dinic();
		printf("%lld\n", sum);
		recover();
	}
	
	return 0;
}


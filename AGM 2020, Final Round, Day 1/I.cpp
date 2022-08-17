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
#define maxn 302
#define maxm
#define maxs
#define maxb
#define M 
#define Flow int
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
template <class T> void write(T x){	
	if (!x) {putchar('0'), putchar('\n'); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar('\n');
}

const int inf = (1ll << 31) - 1;
int n, m, S, T;
struct edge{
	int next, to; Flow flow;
	edge(int next, int to, Flow flow) : next(next), to(to), flow(flow){}
	edge(){}
}e[maxn * maxn];
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


int main(){
	
		freopen("I.in", "r", stdin);
	
	read(n), read(m);
	S = 1, T = 2 + n + m;
	int sum = 0, k, x, v;
	rep(i, 1, n) read(v), Add_Edge(S + m + i, T, v);
	rep(i, 1, m) read(v), sum += v, Add_Edge(S, S + i, v);
	rep(i, 1, m){
		read(k);
		rep(j, 1, k) read(x), Add_Edge(S + i, S + m + x, inf); 
	}
	n = T;
	printf("%d\n", sum - Dinic());
	return 0;
}


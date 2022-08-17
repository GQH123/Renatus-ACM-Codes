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
#define pb push_back
#define pc putchar
#define lowbit(x) (x & -x)
#define maxr 2000020
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

namespace Fast_Read{
    char buffer[maxr], *p1, *p2;
    template<class T> void read_signed(T& x){
        char ch = gc(); x = 0; bool f = 1;
        while (!isdigit(ch) && ch != '-') ch = gc();
        if (ch == '-') f = 0, ch = gc();
        while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
        x = (f) ? x : -x;
    }
    template<class T, class... Args> void read_signed(T& x, Args&... args){
        read_signed(x), read_signed(args...);
    }
    template<class T> void read_unsigned(T& x){
        char ch = gc(); x = 0;
        while (!isdigit(ch)) ch = gc(); 
        while (isdigit(ch)) x = (x << 1) + (x << 3) + ch - '0', ch = gc(); 
    }
    template<class T, class... Args> void read_unsigned(T& x, Args&... args){
        read_unsigned(x), read_unsigned(args...);
    }
    #define isletter(ch) ('a' <= ch && ch <= 'z')
    int read_string(char* s){
        char ch = gc(); int l = 0;
        while (!isletter(ch)) ch = gc();
        while (isletter(ch)) s[l++] = ch, ch = gc();
        s[l] = '\0'; return l;
    }
}using namespace Fast_Read; 

int _num[20];
template <class T> void write(T x, char sep = '\n'){	
	if (!x) {putchar('0'), putchar(sep); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar(sep);
}

#define read read_signed
#define reads read_string 
#define writes puts

#define maxn 2020
#define maxm 2020000
#define maxs 
#define maxb
#define inf  2000000020
#define eps
#define M 
#define ll long long int 

int n, m, S, T, all;
struct edge{
	int next, to, flow, cost;
	edge(int next, int to, int flow, int cost) : next(next), to(to), flow(flow), cost(cost){}
	edge(){}
}e[maxm << 1];
int cnt = 1, h[maxn];
void Add_Edge(int x, int y, int z, int w) {
	e[++cnt] = edge(h[x], y, z, w);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x, 0, -w);
	h[y] = cnt;
}
bool f = 1;
int p[maxn], d[maxn], spfa[maxn], head = 0, tail = 0; bool vis[maxn];
void Augment(int& maxflow, int& mincost) {
	int now = T, mi = inf;
	while (now != S) {
		int k = p[now];
		mi = min(mi, e[k].flow);
		now = e[k ^ 1].to;
	}
	now = T;
	while (now != S) {
		int k = p[now];
		e[k].flow -= mi, e[k ^ 1].flow += mi;
		now = e[k ^ 1].to;
	}
	if (d[T] >= d[S]) { f = 0; return; }
	maxflow += mi, mincost += (d[T] - d[S]) * mi;
}
bool SPFA(){
	head = tail = 0;
	rep(i, 1, all) vis[i] = 0, d[i] = inf;
	d[S] = 0; vis[S] = 1;
	spfa[++head] = S;
	while (head > tail) {
		int x = spfa[++tail];
		erep(i, x) {
			int op = e[i].to;
			if (!e[i].flow) continue;
			if (d[op] > d[x] + e[i].cost) {
				d[op] = d[x] + e[i].cost;
				p[op] = i;
				if (!vis[op]) {
					vis[op] = 1;
					spfa[++head] = op;
				}
			}
		}
		vis[x] = 0;
	}
	return d[T] < inf;
}
void MCMF(int& maxflow, int& mincost){
	while (f && SPFA()) Augment(maxflow, mincost);
}

int main(){
	read(n, m), S = 2, all = T = (n << 1 | 1);
	int x, y, z;
	rep(i, 1, n) {
		read(x), Add_Edge(i << 1, i << 1 | 1, inf, -x); 
	}
	rep(i, 1, m) {
		read(x, y, z), Add_Edge(x << 1 | 1, y << 1, z, 0);
	}
	int maxflow = 0, mincost = 0;
	//cerr << maxflow << endl;
	MCMF(maxflow, mincost);
	printf("%d\n", -mincost);
	return 0;
}

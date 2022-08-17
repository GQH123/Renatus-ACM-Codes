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

#define maxn 6000020
#define maxs 500020
#define maxm 10002000 
#define maxb
#define inf 1000000020
#define eps
#define M 
#define ll long long int 

int n, m, a[maxs], num[maxs], lis[maxs], ch[maxs << 2][2];

int S, T, all;
struct edge{
	int next, to, flow;
	edge(int next, int to, int flow) : next(next), to(to), flow(flow){}
	edge(){}
}e[maxm];
int cnt = 1, h[maxn];
void Add_Edge(int x, int y, int z) {
	e[++cnt] = edge(h[x], y, z);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x, z);
	h[y] = cnt;
}
void init(int l, int r, int& o){
	if (!o) o = ++all;
	if (l == r) {
		Add_Edge(o, lower_bound(lis + 1, lis + 1 + m, a[l]) - lis + m, inf);
		return;
	}
	int mid = ((r - l) >> 1) + l; 
	init(l, mid, ch[o][0]), init(mid + 1, r, ch[o][1]);
	Add_Edge(o, ch[o][0], inf), Add_Edge(o, ch[o][1], inf);
}
int qx, qy, qd;
void add(int l, int r, int o) {
	if (qx <= l && r <= qy) {
		Add_Edge(qd, o, inf);
		return;
	}
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) add(l, mid, ch[o][0]);
	if (qy > mid) add(mid + 1, r, ch[o][1]);
}
vector<int> pos[maxs];

namespace Dinic{
	#define type int 
	int bfs[maxn], head, tail, cur[maxn], d[maxn];
	bool BFS(){
		rep(i, 1, all) d[i] = -1, cur[i] = h[i];
		head = tail = 0, d[S] = 0, bfs[++head] = S;
		while (tail < head){
		    int x = bfs[++tail];
		    erep(i, x){
		        if (!e[i].flow || d[e[i].to] != -1) continue; 
		        int op = e[i].to; d[op] = d[x] + 1; bfs[++head] = op;
		    }
		}
		return d[T] != -1;
	}
	type DFS(int x, type flow){
		if (x == T) return flow;
		type rest = flow;
		erep2(i, x){
		    if (!e[i].flow || d[e[i].to] != d[x] + 1) continue; 
		    int op = e[i].to;
		    type k = DFS(op, min(rest, e[i].flow)); 
		    e[i].flow -= k, e[i ^ 1].flow += k, rest -= k;
		    if (!rest) return flow;
		}
		return flow - rest;
	}
	type dinic(){
		type maxflow = 0, k = 0;
		while (BFS()) while (k = DFS(S, inf)) maxflow += k; 
		return maxflow;
	}
}using namespace Dinic;

int main(){
	read(n); rep(i, 1, n) read(a[i]), pos[a[i]].pb(i);
	rep(i, 1, n) num[a[i]]++, lis[++m] = a[i];
	sort(lis + 1, lis + 1 + m);
	m = unique(lis + 1, lis + 1 + m) - lis - 1; 
	int now = a[n];
	per(i, n, 1) {
		if (a[i] != now) break;
		num[now]--;
	}
	S = 2 * m + 1, T = 2 * m + 2, all = 2 * m + 2;
	rep(i, 1, m) { 
		Add_Edge(S, i, num[lis[i]]);
		Add_Edge(i + m, T, num[lis[i]]);
	} 
	int root = 0;
	init(1, n, root);
	rep(i, 1, m) {
		qd = i;
		sort(pos[lis[i]].begin(), pos[lis[i]].end());
		int last = -1;
		for (auto it: pos[lis[i]]) {
			if (last != -1) {
				qx = last + 1, qy = it - 1;
				if (qx <= qy) add(1, n, root);
			}
			last = it;
		}
	}
	//rep(i, 1, m) cout << lis[i] << ' ' << num[i] << endl;
	//int res = 0;
	//rep(i, 1, m) res += num[i];
	printf("%d\n", dinic());
	return 0;
}


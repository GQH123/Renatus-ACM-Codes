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

#define read read_unsigned
#define reads read_string 
#define writes puts

#define maxn 2020
#define maxm 20020
#define maxp 2020
#define maxT 20020
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

int n, m, K, p, T;
int d[maxp], d2[maxp], v[maxp];
struct edge{
	int next, to;
	edge(int next, int to) : next(next), to(to){}
	edge(){}
}e[maxm << 1];
int h[maxn], cnt = 1;
void Add_Edge(int x, int y){
	e[++cnt] = edge(h[x], y); h[x] = cnt;
	e[++cnt] = edge(h[y], x); h[y] = cnt;
}
queue<int> bfs;
int dis[maxn][maxn];
bool vis2[maxn];

void BFS(int* dis, int s){
	rep(i, 1, n) vis2[i] = 0;
	bfs.push(s);
	dis[s] = 0;
	vis2[s] = 1;
	while (!bfs.empty()) {
		int x = bfs.front();
		bfs.pop();
		erep(i, x) {
			int op = e[i].to;
			if (vis2[op]) continue;
			vis2[op] = 1;
			dis[op] = dis[x] + 1;
			bfs.push(op);
		}
	}
}

int dp[maxp][maxT];
bool vis[maxp][maxT];
int DP(int id, int rest) {
	if (rest < 0) return -1;
	if (id == p + 1) return 0;
	if (vis[id][rest]) return dp[id][rest];
	vis[id][rest] = 1;
	int& ans = dp[id][rest];
	ans = -1;
	int cost = K * dis[d[id]][d[id + 1]];
	ans = max(ans, DP(id + 1, rest - cost));
	if (1 <= id && id <= p) {
		cost = K * (dis[d[id]][d2[id]] + dis[d2[id]][d[id + 1]]);
		int dp = DP(id + 1, rest - cost);
		if (dp != -1) ans = max(ans, dp + v[id]);
	}
	return ans;
}

int main(){
	read(n, m, K);
	int x, y;
	rep(i, 1, m) read(x, y), Add_Edge(x, y);
	read(p, T);
	d[0] = 1, d[p + 1] = 1;
	rep(i, 1, p) read(d[i]);
	rep(i, 1, p) read(d2[i], v[i]);
	rep(i, 1, n) BFS(dis[i], i);
	int v = DP(0, T);
	if (v == -1) puts("Impossible");
	else printf("%d", v);
	return 0;
}


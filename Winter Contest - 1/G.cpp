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

#define maxn 200020
#define maxm 420
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

int n, k, lis[maxm];
struct edge{
	int next, to, c;
	edge(int next, int to, int c) : next(next), to(to), c(c){}
	edge(){}
}e[maxn << 1];
int cnt = 1, h[maxn];
void Add_Edge(int x, int y, int z) {
	e[++cnt] = edge(h[x], y, z);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x, z);
	h[y] = cnt;
}
int ns, g, siz[maxn];
bool vis[maxn];
void findg(int x, int fa){
	siz[x] = 1;
	bool f = 1;
	erep(i, x) {
		int op = e[i].to;
		if (op == fa || vis[op]) continue;
		findg(op, x);
		siz[x] += siz[op];
		if (siz[op] > (ns >> 1)) f = 0;
	}
	if (ns - siz[x] > (ns >> 1)) f = 0;
	if (f) g = x;
}
int last[maxm], nxt[maxn][maxm];
void dfs(int x, int fa){	
	siz[x] = 1;
	rep(i, 1, k) nxt[x][i] = last[i];
	erep(i, x) {
		int op = e[i].to;
		if (op == fa || vis[op]) continue;
		int bac = last[e[i].c];
		last[e[i].c] = x;
		dfs(op, x);
		last[e[i].c] = bac;
		siz[x] += siz[op];
	}
}
int num[maxm];
void mod(int x, int fa, int v) {
	int now = x;
	rep(i, 1, k) {
		now = nxt[now][lis[i]];
		if (now == -1) {
			num[i - 1] += v;
			break;
		}
	}
	if (now != -1) num[k] += v;
	erep(i, x) {
		int op = e[i].to;
		if (op == fa || vis[op]) continue;
		mod(op, x, v);
	}
}
ll ans = 0;
void cal(int x, int fa) {
	int now = x, res = -1;
	per(i, k, 1) {
		now = nxt[now][lis[i]];
		if (now == -1) {
			res = k - i;
			break;
		}
	}
	if (now != -1) res = k;
	ans += num[k] - ((res == k) ? 0 : num[k - res - 1]);
	erep(i, x) {
		int op = e[i].to;
		if (op == fa || vis[op]) continue;
		cal(op, x);
	}
}
void solve(int x){
	findg(x, -1);
	x = g;
	vis[x] = 1;
	rep(i, 0, k) last[i] = -1;
	dfs(x, -1);
	erep(i, x) {
		int op = e[i].to;
		if (vis[op]) continue;
		mod(op, x, 1);
	}
	num[0]++;
	erep(i, x) {
		int op = e[i].to;
		if (vis[op]) continue;
		mod(op, x, -1);
		rep(i, 1, k) num[i] += num[i - 1];
		cal(op, x);
		per(i, k, 1) num[i] -= num[i - 1];
		mod(op, x, 1);
	}
	ans += num[k];
	erep(i, x) {
		int op = e[i].to;
		if (vis[op]) continue;
		mod(op, x, -1);
	}
	num[0]--;
	int _ns = ns;
	erep(i, x) {
		int op = e[i].to;
		if (vis[op]) continue;
		if (siz[op] > siz[x]) ns = _ns - siz[x], solve(op);
		else ns = siz[op], solve(op);
	}
}
int a[maxm];
int main(){
	read(n, k);
	int x, y, z;
	rep(i, 2, n) read(x, y, z), Add_Edge(x, y, z);
	rep(i, 1, k) read(lis[i]), a[i] = lis[i];
	sort(a + 1, a + 1 + k);
	int _k = unique(a + 1, a + 1 + k) - a - 1;
	rep(i, 1, k) lis[i] = lower_bound(a + 1, a + 1 + _k, lis[i]) - a;
	rep(i, 2, cnt) {
		int p = lower_bound(a + 1, a + 1 + _k, e[i].c) - a;
		if (p <= _k && p >= 1 && e[i].c == a[p]) {
			e[i].c = p;
		}
		else e[i].c = 0;
	}
	ns = n; solve(1);
	write(ans);
	return 0;
}

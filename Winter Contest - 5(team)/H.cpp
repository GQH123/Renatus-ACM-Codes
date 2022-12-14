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

#define maxn 1000020
#define maxm
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

int n, m, a[maxn], b[maxn];
struct edge{
	int next, to;
	edge(int next, int to) : next(next), to(to){}
	edge(){}
}e[maxn << 1];
int cnt = 1, h[maxn], deg[maxn];
int lis[maxn], cs = 0, id[maxn], rid[maxn];
void Add_Edge(int x, int y){
	e[++cnt] = edge(h[x], y);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x);
	h[y] = cnt;
	deg[x]++, deg[y]++;
}
#define maxs 2020
int G[maxs][maxs];

set<pii> s[maxn];
set<pii> :: iterator it;
int bsiz;
void mod(int y, int z){
	if (deg[y] >= bsiz) {
		int _y = id[y];
		rep(i, 1, cs) {
			if (G[_y][i]) {
				int op = rid[i];
				s[op].erase(pii(a[y] - b[y], y)); 
			}
		}
		a[y] = z;
		rep(i, 1, cs) {
			if (G[_y][i]) {
				int op = rid[i]; 
				s[op].insert(pii(a[y] - b[y], y));
			}
		}
	}
	else {
		erep(i, y){
			int op = e[i].to;
			if (deg[op] >= bsiz) {
				s[op].erase(pii(a[y] - b[y], y));
			}
		}
		a[y] = z;
		erep(i, y){
			int op = e[i].to;
			if (deg[op] >= bsiz) {
				s[op].insert(pii(a[y] - b[y], y));
			}
		}
	} 
}
void dfs(int x, int fa){
	if (deg[x] >= bsiz) {
		it = s[x].lower_bound(pii(a[x] - b[x], -1));
		while (it != s[x].end() && it -> fi == a[x] - b[x]) {
			dfs(it -> se, x);
			it++;
		}
		mod(x, b[x]);
	}
	else {
		erep(i, x){
			int op = e[i].to;
			if (op == fa) continue;
			if (a[op] - b[op] == a[x] - b[x]) dfs(op, x);
		}
		mod(x, b[x]);
	}
	
}

int main(){
	int x, y, z;
	read(n, m); rep(i, 1, n) read(a[i]); rep(i, 1, n) read(b[i]);
	bsiz = (int)sqrt(3 * n) + 1;
	rep(i, 2, n) read(x, y), Add_Edge(x, y);
	rep(i, 1, n) {
		if (deg[i] >= bsiz) lis[++cs] = i, id[i] = cs, rid[cs] = i;
	}
	
	rep(x, 1, n) {
		erep(i, x){
			int op = e[i].to;
			if (deg[op] >= bsiz) {
				s[op].insert(pii(a[x] - b[x], x));
			}
		}
		if (deg[x] < bsiz) continue;
		erep(i, x) {
			int op = e[i].to;
			if (deg[op] >= bsiz) {
				G[id[x]][id[op]] = 1;
			}
		}
	}
	rep(i, 1, m) {
		//rep(i, 1, n) cerr << a[i] << ' '; cerr << endl;
		read(x, y);
		if (x == 1) read(z);
		
		if (x == 1) {
			mod(y, z);
		}
		else if (x == 2){
			printf("%d\n", a[y]);
		}
		else if (a[y] != b[y]) dfs(y, -1);
	}
	return 0;
}


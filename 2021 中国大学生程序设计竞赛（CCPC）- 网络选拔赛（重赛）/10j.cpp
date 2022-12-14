#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, r, l) for (int i = r; i >= l; i--)
#define srep(i, l, r) for (int i = l; i < r; i++)
#define sper(i, r, l) for (int i = r; i > l; i--)
#define erep(i, x) for (int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (int& i = cur[x]; i; i = e[i].next)
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
#define maxbuf 2000020
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxbuf, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

namespace Fast_Read{
    char buffer[maxbuf], *p1, *p2;
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

#define maxn 4021
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

int n, m;
struct edge{
	int next, to;
	edge(int next, int to) : next(next), to(to){}
	edge(){}
}e[(maxn << 1) << 1];
int h[maxn << 1], cnt = 1, deg[maxn << 1];

void Add_Edge(int x, int y) {
	e[++cnt] = edge(h[x], y);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x);
	h[y] = cnt;
	deg[x]++, deg[y]++;
}

set<int> le, ri;

int par[maxn << 1];

bool vis[maxn << 1];

int dfs(int x) {
	vis[x] = 1;
	erep(i, x) {
		int op = e[i].to;
		if (vis[op]) continue;
		return dfs(op);
	}
	return x;
}

int main(){
	int T; 
	read(T);
	while (T--) {
		read(n, m);
		
		int x, y; rep(i, 1, m) read(x, y), Add_Edge(x, n + y);
		
		rep(i, 1, n) if (deg[i] < 2) le.insert(i); 
		rep(i, n + 1, (n << 1)) if (deg[i] < 2) ri.insert(i);
		
		rep(i, 1, (n << 1)) {
			if (deg[i] == 1 && !vis[i]) {
				y = dfs(i);  
				par[y] = i, par[i] = y;
			}
		}
		
		//rep(i, 1, (n << 1)) cerr << par[i] << ' '; cerr << endl;
		//rep(i, 1, (n << 1)) cerr << deg[i] << ' '; cerr << endl;
		
		printf("%d\n", (n << 1) - m);
		while (m < (n << 1)){
			bool last = (m == ((n << 1) - 1));
			x = *le.begin();
			if (deg[x] == 0) {
				y = *ri.begin();
				printf("%d %d\n", x, y - n);
				
				if (deg[y] == 0) {
					par[x] = y, par[y] = x;
				}
				else if (deg[y] == 1) {
					par[par[y]] = x;
					par[x] = par[y];
					ri.erase(y);
				}
				else assert(false);
				
				deg[x]++, deg[y]++;
			}
			else if (deg[x] == 1){
				int rm = -1;
				if (!last && par[x] > n) ri.erase(par[x]), rm = par[x];
				
				y = *ri.begin();
				printf("%d %d\n", x, y - n);
				if (deg[y] == 0) {
					par[par[x]] = y;
					par[y] = par[x];
				}
				else if (deg[y] == 1){
					par[par[x]] = par[y];
					par[par[y]] = par[x];
					ri.erase(y);
				}
				else assert(false);
				
				le.erase(x);
				deg[x]++, deg[y]++;
				if (rm != -1) ri.insert(rm);
			}
			else assert(false); 
			m++;
		} 
		// rep(i, 1, (n << 1)) cerr << deg[i] << ' '; cerr << endl;
		cnt = 1; 
		rep(i, 1, (n << 1)) vis[i] = h[i] = par[i] = deg[i] = 0;
	}
	
	return 0;
}


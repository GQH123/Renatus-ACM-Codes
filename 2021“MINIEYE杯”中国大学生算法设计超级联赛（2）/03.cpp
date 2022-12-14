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

#define maxn 2021
#define maxm 300021
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
}e[maxm << 1];
int cnt = 1, h[maxn];
void Add_Edge(int x, int y) {
	e[++cnt] = edge(h[x], y);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x);
	h[y] = cnt;
}

int q[maxn], d[maxn], head = 0, tail = 0;
void bfs(int s){
	rep(i, 1, n) d[i] = -1;
	d[s] = 0; head = tail = 0;
	q[++head] = s;
	while (head > tail) {
		int x = q[++tail];
		erep(i, x) {
			int op = e[i].to;
			if (d[op] == -1) d[op] = d[x] + 1, q[++head] = op;
		}
	} 
}

bool dp[maxn][maxn];
int vis[maxn][maxn], idx = 0;
bool DP(int x, int y) {
	if (vis[x][y] == idx) return dp[x][y];
	vis[x][y] = idx;
	bool& ans = dp[x][y]; ans = 0;
	if (d[x] == d[y]) {
		if (!d[x]) return ans = 0;
		erep(i, x) {
			int op = e[i].to;
			if (d[op] < d[x]) ans |= DP(op, y);
		}
		return ans;
	}
	else {
		ans = 1;
		erep(i, y) {
			int op = e[i].to;
			if ((d[op] && op == x) || d[op] >= d[y]) continue; //XXX
			ans &= DP(x, op);
		}
		return ans;
	}
}
void work(){	
	idx++;
	read(n, m);
	int x, y, z, a, b, c;
	read(a, b, c);
	rep(i, 1, m) read(x, y), Add_Edge(x, y);
	bfs(c);
	rep(i, 1, n) if (d[i] == -1) d[i] = n << 1;
	if (d[a] < d[b]) {
		puts("1");
		return;
	}
	if (d[b] < d[a]) {
		puts("3");
		return;
	}
	if (d[a] == d[b] && d[a] == n << 1) {
		puts("2");
		return;
	}
	puts(DP(a, b) ? "1" : "2");
}
void clear(){
	rep(i, 1, n) h[i] = 0; cnt = 1;
}
int main(){
	int T; read(T);
	while (T--) work(), clear();
	return 0;
}


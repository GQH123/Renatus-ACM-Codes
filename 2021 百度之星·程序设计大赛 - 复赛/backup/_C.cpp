#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, r, l) for (int i = r; i >= l; i--)
#define srep(i, l, r) for (int i = l; i < r; i++)
#define sper(i, r, l) for (int i = r; i > l; i--)
#define erep(i, x) for (int i = h[x]; i; i = e[i].nxt)
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

#define maxn 400021
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

int n, p[maxn], b[maxn]; pii lis[maxn]; 

struct edge{
	int nxt, to;
	edge(int nxt, int to) : nxt(nxt), to(to){}
	edge(){}
}e[maxn << 1];
int cnt = 1, h[maxn], deg[maxn];

void Add_Edge(int x, int y) {
	e[++cnt] = edge(h[x], y);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x);
	h[y] = cnt;
	deg[x]++, deg[y]++;
}

int ufs[maxn], v[maxn]; bool vis[maxn];
int find_root(int x) {
	return ufs[x] = (ufs[x] == x) ? x : find_root(ufs[x]);
}
void merge(int x, int y) {
	x = find_root(x), y = find_root(y);
	if (x == y) return;
	ufs[x] = y, v[y] = max(v[x], v[y]);
	
} 

ll ans = 0;
pii tmp[maxn]; int cct = 0;
void solve(int x) {
	vis[x] = 1;
	cct = 0;
	erep(i, x) {
		int op = e[i].to;
		if (!vis[op] || !deg[op]) continue;
		tmp[++cct] = pii(v[find_root(op)], op);
	}
	
	sort(tmp + 1, tmp + 1 + cct);
	
	int ptr = cct, modd = b[x];
	while (deg[x] && ptr >= 1) {
		modd = b[x] - v[find_root(tmp[ptr].se)];
		merge(x, tmp[ptr].se); 
		deg[x]--, ptr--;
	}
	
	ans += modd;
}

void work(){
	read(n);
	int x, y;
	rep(i, 2, n) read(x, y), Add_Edge(x, y);
	
	rep(i, 1, n) read(b[i], p[i]), lis[i] = pii(b[i], i), deg[i] = min(p[i], deg[i]);
	
	rep(i, 1, n) ufs[i] = i, v[i] = b[i], vis[i] = 0;
	
	sort(lis + 1, lis + 1 + n);
	
	rep(i, 1, n) solve(lis[i].se);
	
	printf("%lld\n", ans);
}

void recover(){
	ans = 0;
	rep(i, 1, n) h[i] = deg[i] = 0; cnt = 1;
}

int main(){
	int T; read(T);
	while (T--) work(), recover();
	return 0;
}


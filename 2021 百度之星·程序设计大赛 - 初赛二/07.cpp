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

#define maxn 200021
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

int n, k, a[maxn];
struct edge{
	int next, to;
	edge(int next, int to) : next(next), to(to){}
	edge(){}
}e[maxn << 1];
int cnt = 1, h[maxn];
void Add_Edge(int x, int y) {
	e[++cnt] = edge(h[x], y);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x);
	h[y] = cnt;
}
int fa[maxn], d[maxn]; //dfs[maxn], idfs[maxn], idx = 0;

void dfs(int x) {
	//dfs[x] = ++idx;
	//idfs[idx] = x;
	erep(i, x) {
		int op = e[i].to;
		if (op == fa[x]) continue;
		d[op] = d[x] + 1;
		dfs(op);
	}
}

//int pre[maxn];

//bool have[maxn];

/*
bool have[maxn];

int jump(int x, int s) {
	int now = 0;
	while (s) {
		
	}
}
*/

/*
void dfs2(int x, bool& sum){
	if (a[x]) sum |= 1;
	erep(i, x) {
		int op = e[i].to;
		if (d[op] % (k + 1) == 0) {
			dfs2(op, have[op]);
		}
		else {
			dfs2(op, sum);
		}
	}
}
*/

pii lis[maxn]; int cs = 0;

int c[maxn], idx = 0;

void work(){ 
	read(n, k); rep(i, 1, n) c[i] = 0; fa[1] = 0; rep(i, 2, n) read(fa[i]), Add_Edge(i, fa[i]);
	
	dfs(1);
	
	rep(i, 1, n) {
		read(a[i]);
		if (a[i]) lis[++cs] = pii(d[i], i);
	}
	
	/*
	
	dfs2(1, have[1]);
	
	*/
	
	sort(lis + 1, lis + 1 + cs);
	
	per(i, cs, 1) {
		int x = lis[i].se, re = k, _x = x;
		while (x != 0 && re > -1) {
			if (c[x]) {
				goto done;
			}
			x = fa[x];
			re--;
		}
		x = _x;
		idx++;
		re = k;
		while (x != 0 && re > -1) {
			c[x] = idx;
			x = fa[x];
			re--;
		}
		done:;
	}
	
	//rep(i, 1, n) if (have[i]) ans++;
	
	printf("%d\n", idx);
	
	/*
	rep(i, 1, n) {
		if (a[i]) {
			pre[dfs[i]] = 1;
		}
	}
	rep(i, 1, n) pre[i] += pre[i - 1]; 
	*/
	
	
	rep(i, 1, n) h[i] = 0; cnt = 1; idx = 0; cs = 0;
}


int main(){
	int T; read(T);
	while (T--) work();
	return 0;
}


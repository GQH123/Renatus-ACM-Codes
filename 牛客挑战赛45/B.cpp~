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
#define ll long long int 
#define pb push_back
#define pc putchar
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn 2000020
#define maxm
#define maxs
#define maxb
#define M 
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
template <class T> void write(T x, char sep = '\n'){	
	if (!x) {putchar('0'), putchar(sep); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar(sep);
}

int n, k, a[maxn];
struct edge{
    int next, to, len;
    edge(int next, int to, int len) : next(next), to(to), len(len){}
    edge(){}
}e[maxn << 1];
int h[maxn], cnt = 1;
void Add_Edge(int x, int y, int z){
    e[++cnt] = edge(h[x], y, z), h[x] = cnt;
    e[++cnt] = edge(h[y], x, z), h[y] = cnt;
}
ll v[maxn];
ll ans = 0;
void dfs(int x, int fa){
	v[x] = a[x];
    erep(i, x){
        int op = e[i].to; 
        if (op == fa) continue; 
       	dfs(op, x);
       	v[x] += v[op];
       	if (v[op] % k != 0) ans += e[i].len;
    }
}
int main(){
	int x, y, z;
	read(n), read(k);
	rep(i, 1, n) read(a[i]);
	rep(i, 2, n) read(x), read(y), read(z), Add_Edge(x, y, z); 
	dfs(1, -1);
	write(ans);
	return 0;
}


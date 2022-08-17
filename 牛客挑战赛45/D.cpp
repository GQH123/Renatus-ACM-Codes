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
#define maxn 300020
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

int n, m;
ll v[maxn];
namespace T1{
	struct edge{
		int next, to, len;
		edge(int next, int to, int len) : next(next), to(to), len(len){}
		edge(){}
	}e[maxn << 1];
	int h[maxn], cnt = 1, deg[maxn];
	void Add_Edge(int x, int y, int z){
		e[++cnt] = edge(h[x], y, z), h[x] = cnt;
		e[++cnt] = edge(h[y], x, z), h[y] = cnt;
		deg[x]++, deg[y]++;
	}
	int fa[maxn]; ll d[maxn];
	void dfs(int x){
		erep(i, x) {
			int op = e[i].to;
			if (op == fa[x]) continue;
			fa[op] = x, d[op] = d[x] + e[i].len;
			dfs(op); 
		}
	}
	ll vmx[maxn];
	multiset<ll> sub[maxn];
	/*inline void update(ll& mx, ll& mx2, ll _mx){
		if (_mx >= mx) mx2 = mx, mx = _mx;
		else if (_mx > mx2) mx2 = _mx;
	}*/
	ll ans = -1;
	void dfs2(int x){
		vmx[x] = v[x];
		//ll mx = -1, mx2 = -1;
		erep(i, x){
			int op = e[i].to;
			if (op == fa[x]) continue;
			dfs2(op);
			//update(mx, mx2, vmx[op]);
			vmx[x] = max(vmx[x], vmx[op]);
			sub[x].insert(vmx[op]);
		}
		if (deg[x] >= 1) ans = max(ans, v[x] + *sub[x].rbegin() - 2 * d[x]);
		if (deg[x] >= 2) ans = max(ans, *sub[x].rbegin() + *(++sub[x].rbegin()) - 2 * d[x]);
	}
	void play(int x){
		int now = x;
		while (now) { 
			if (deg[now] >= 1) ans = max(ans, v[now] + *sub[now].rbegin() - 2 * d[now]);
			if (deg[now] >= 2) ans = max(ans, *sub[now].rbegin() + *(++sub[now].rbegin()) - 2 * d[now]);
			if (vmx[now] >= v[x]) break;
			int f = fa[now];
			if (f) {
				sub[f].erase(sub[f].lower_bound(vmx[now]));
				vmx[now] = v[x];
				sub[f].insert(vmx[now]);
			}
			now = f;
		}
	}
}
namespace T2{
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
	int fa[maxn], dfs[maxn], idfs[maxn], siz[maxn], tim = 0; ll d[maxn];
	void DFS(int x){
		dfs[x] = ++tim;
		idfs[tim] = x;
		siz[x] = 1;
		erep(i, x) {
			int op = e[i].to;
			if (op == fa[x]) continue;
			fa[op] = x, d[op] = d[x] + e[i].len;
			DFS(op);
			siz[x] += siz[op]; 
		}
	}
	void update(int x, ll k){
		int l = dfs[x], r = dfs[x] + siz[x];
		srep(i, l, r) {
			v[idfs[i]] += k; 
			T1 :: play(idfs[i]);
		}
	}
}
int main(){
	int x, y, z, k;
	read(n), read(m);
	rep(i, 2, n) read(x), read(y), read(z), T1 :: Add_Edge(x, y, z);
	rep(i, 2, n) read(x), read(y), read(z), T2 :: Add_Edge(x, y, z);
	rep(i, 2, n) T1 :: deg[i] -= 1;
	T1 :: dfs(1), T2 :: DFS(1);
	rep(i, 1, n) v[i] = T1 :: d[i] + T2 :: d[i];
	T1 :: dfs2(1);
	write(T1 :: ans); 
	rep(i, 1, m) {
		read(x), read(k), T2 :: update(x, k); 
		write(T1 :: ans);
	}
	return 0;
}


#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ll long long int 
#define ld long double
#define lowbit(x) (x & -x)
#define mo(x) (x = (x >= M) ? (x - M) : x)
#define M 
#define B
#define maxn 600020
#define maxnode 10000000
#define maxs
#define maxm 
#define maxk
#define maxb
//#define DEBUG
using namespace std;

int n;
struct edge{
	int next, to;
	edge(int next, int to) : next(next), to(to){}
	edge(){}
}e[maxn << 1];
int cnt = 1, h[maxn];
void Add_Edge(int x, int y){
	e[++cnt] = edge(h[x], y);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x);
	h[y] = cnt;
}

int mx[maxn << 2];
int qx, qy, qd;
void inline pu(int o){
	mx[o] = max(mx[o << 1], mx[o << 1 | 1]);
}
void init(int l, int r, int o){
	mx[o] = -1;
	if (l == r) return;
	int mid = ((r - l) >> 1) + l;
	init(l, mid, o << 1), init(mid + 1, r, o << 1 | 1);
}
int get(int l, int r, int o){
	if (qx <= l && r <= qy) return mx[o];
	int mid = ((r - l) >> 1) + l, ans = -1;
	if (qx <= mid) ans = max(ans, get(l, mid, o << 1));
	if (qy > mid) ans = max(ans, get(mid + 1, r, o << 1 | 1));
	return ans;
}
void mod(int l, int r, int o){
	if (l == r) {mx[o] = qd; return;}
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) mod(l, mid, o << 1);
	else mod(mid + 1, r, o << 1 | 1);
	pu(o);
} 

int sg[maxn], fa[maxn], dfs[maxn], siz[maxn], t = 0;
void DFS(int x){ 
	dfs[x] = ++t;
	siz[x] = 1;
	erep(i, x){
		int op = e[i].to;
		if (op == fa[x]) continue;
		fa[op] = x;
		DFS(op);
		siz[x] += siz[op];
	} 
}
void DFS2(int x){
	erep(i, x){
		int op = e[i].to;
		if (op == fa[x]) continue;
		DFS2(op);
	}
	qx = dfs[x], qy = dfs[x] + siz[x] - 1;
	sg[x] = get(1, n, 1) + 1;
	qx = dfs[x], qd = sg[x];
	mod(1, n, 1);
}

int hh[maxnode], ch[maxnode][2], ct = 0;
int sum[maxnode];
inline void pu2(int o){
	sum[o] = sum[ch[o][0]] + sum[ch[o][1]];
}
void mod2(int l, int r, int& o){
	if (!o) o = ++ct;
	if (l == r) {sum[o]++; return;}
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) mod2(l, mid, ch[o][0]);
	else mod2(mid + 1, r, ch[o][1]);
	pu2(o);
}
int get2(int l, int r, int o){
	if (!o) return 0;
	if (l == r) return sum[o];
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) return get2(l, mid, ch[o][0]);
	else return get2(mid + 1, r, ch[o][1]);
}
void merge(int l, int r, int& x, int y){
	if (!x || !y) {x += y; return;}
	if (l == r) {sum[x] += sum[y]; return;}
	int mid = ((r - l) >> 1) + l;
	merge(l, mid, ch[x][0], ch[y][0]);
	merge(mid + 1, r, ch[x][1], ch[y][1]);
	pu2(x);
}
int xsum;
ll ans = 0;
void DFS3(int x){
	erep(i, x){
		int op = e[i].to;
		if (op == fa[x]) continue;
		DFS3(op);
		merge(0, n, hh[x], hh[op]);
	}
	qx = xsum ^ sg[x];
	ans += get2(0, n, hh[x]);
	qx = sg[x];
	mod2(0, n, hh[x]);
}
/*
int dfs(int x){
	set<int> s;
	erep(i, x){
		int op = e[i].to;
		if (op == fa[x]) continue; 
		fa[op] = x;
		s.insert(dfs(op, x));
	}
	int i = 0;
	while (s.count(i)) i++;
	return sg[x] = i;
}
*/

int main(){
	int x, y;
	scanf("%d", &n);
	init(1, n, 1);
	srep(i, 1, n) scanf("%d%d", &x, &y), Add_Edge(x, y);
	DFS(1), DFS2(1); 
	rep(i, 1, n) xsum ^= sg[i];
	if (!xsum) printf("NO");
	else {	
		printf("YES\n");
		DFS3(1);
		printf("%lld", ans);
	} 
	return 0;
}

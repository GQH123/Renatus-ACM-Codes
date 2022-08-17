#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define pii pair<int, int>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define ll long long int 
#define pb push_back
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn 200020
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
template <class T> void write(T x){	
	if (!x) {putchar('0'), putchar('\n'); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar('\n');
}

int n, m;
struct edge{
	int next, to, len;
	edge(int next, int to, int len) : next(next), to(to), len(len){}
	edge(){}
}e[maxn << 1];
int cnt = 1, h[maxn];
void Add_Edge(int x, int y, int z){
	e[++cnt] = edge(h[x], y, z);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x, z);
	h[y] = cnt;
}
int siz[maxn], v[maxn];
bool on[maxn];
void DFS(int x, int fa){ 
	erep(i, x){
		int op = e[i].to;
		if (op == fa) continue;
		v[op] = e[i].len;
		DFS(op, x);
		siz[x] += siz[op];
	}
}
bool vis[2][maxn];
ll dp[2][maxn];
ll DP(bool op, int x, int fa){ 
	if (vis[op][x]) return dp[op][x];
	vis[op][x] = 1;
	ll& ans = dp[op][x];
	if (op){
		if (on[x]){
			ll sum = 0;
			erep(i, x){
				int op = e[i].to;
				if (op == fa || !siz[op]) continue;
				sum += DP(1, op, x);
			}
			ans = v[x] + sum;
		}
		else {
			ll mx = 0, sum = 0;
			erep(i, x){
				int op = e[i].to;
				if (op == fa || !siz[op]) continue;
				sum += DP(1, op, x);
				mx = max(mx, DP(1, op, x) - DP(0, op, x));
			}
			ans = min(v[x] + sum - mx, sum);
		} 
	}
	else {
		if (on[x]){
			ll sum = 0;
			erep(i, x){
				int op = e[i].to;
				if (op == fa || !siz[op]) continue;
				sum += DP(1, op, x);
			}
			ans = sum;
		}
		else {
			ll mx = 0, sum = 0;
			erep(i, x){
				int op = e[i].to;
				if (op == fa || !siz[op]) continue;
				sum += DP(1, op, x);
				mx = max(mx, DP(1, op, x) - DP(0, op, x));
			}
			ans = sum - mx;
		} 
	}
	return ans;
}

int main(){
	
		freopen("D.in", "r", stdin);
		
	ios :: sync_with_stdio(false), cin.tie(0);
	
	int T, x, y, z;
	read(T);
	while (T--){
		read(n), read(m);
		srep(i, 1, n) read(x), read(y), read(z), Add_Edge(x + 1, y + 1, z);
		rep(i, 1, n) siz[i] = on[i] = v[i] = 0;
		rep(i, 1, m) read(x), on[x + 1] = siz[x + 1] = 1;
		DFS(1, -1);
		write(DP(0, 1, -1));
		rep(j, 0, 1) rep(i, 1, n) dp[j][i] = vis[j][i] = 0;
		cnt = 1; rep(i, 1, n) h[i] = 0;
	} 
	return 0;
}


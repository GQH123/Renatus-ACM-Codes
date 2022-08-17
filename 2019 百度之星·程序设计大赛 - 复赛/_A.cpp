#include <bits/stdc++.h>
#define maxn 200005
#define maxm 
#define maxr 100000
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int 
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}

int n;
struct edge{
	int next, to;
	edge(int next, int to) : next(next), to(to){}
	edge(){}
}e[maxn << 1];
int h[maxn], cnt = 1;
void Add_Edge(int x, int y){
	e[++cnt] = edge(h[x], y);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x);
	h[y] = cnt;
}

ll dp[maxn][2];
bool vis[maxn][2];
ll v[maxn][2];
ll DP(int x, int op, int fa){
	if (vis[x][op]) return dp[x][op];
	vis[x][op] = 1;
	ll ans = abs(v[x][0] - v[fa][op]);
	erep(i, x){
		int k = e[i].to;
		if (k == fa) continue;
		ans += DP(k, 0, x);
	}
	ll ans2 = abs(v[x][1] - v[fa][op]);
	erep(i, x){
		int k = e[i].to;
		if (k == fa) continue;
		ans2 += DP(k, 1, x);
	}
	return dp[x][op] = max(ans, ans2);
}


int main(){
	#ifndef ONLINE_JUDGE
		freopen("A.in", "r", stdin);
	#endif
	int T;
	read(T);
	while (T--){
		int x, y;
		read(n);
		srep(i, 1, n) read(x), read(y), Add_Edge(x, y);
		rep(i, 1, n) read(v[i][0]), read(v[i][1]);
		ll ans1 = 0;
		erep(i, 1){
			ans1 += DP(e[i].to, 0, 1);
		}
		ll ans2 = 0;
		erep(i, 1){
			ans2 += DP(e[i].to, 1, 1);
		}
		printf("%lld\n", max(ans1, ans2));
		cnt = 1;
		rep(i, 1, n) h[i] = 0, vis[i][0] = vis[i][1] = 0;
	}
	return 0;
}

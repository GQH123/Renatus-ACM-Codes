#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
#define lowbit(x) (x & -x) 
#define maxn 520
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
	//e[++cnt] = edge(h[y], x);
	//h[y] = cnt;
}
bool vvis[maxn];
int lis[maxn], cs = 0;
void DFS(int x, int fa){
	vvis[x] = 1;
	lis[++cs] = x;
	erep(i, x){
		int op = e[i].to;
		if (op == fa || vvis[op]) continue;
		DFS(op, x);
	}
}

int type = 0;
bool vis[maxn][maxn];
int dp[maxn][maxn];
int DP(int pos, int last){
	if (pos == n + 1) return 0;
	if (vis[pos][last]) return dp[pos][last];
	int& ans = dp[pos][last];
	vis[pos][last] = 1;
	ans = DP(pos + 1, last);
	if (!type){
		if (last){	
			if (lis[pos] == lis[last] + 1 || (lis[last] == n && lis[pos] == 1)) ans = max(ans, DP(pos + 1, pos) + 1);
			//else if (!op) ans = max(ans, DP(pos + 1, pos, 1) + 1);
		}
		else ans = max(ans, DP(pos + 1, pos) + 1); 
	}
	else {
		if (last){	
			if (lis[pos] == lis[last] - 1 || (lis[last] == 1 && lis[pos] == n)) ans = max(ans, DP(pos + 1, pos) + 1);
			//else if (!op) ans = max(ans, DP(pos + 1, pos, 1) + 1);
		}
		else ans = max(ans, DP(pos + 1, pos) + 1); 
	}
	return ans;
}
inline void dprecover(){
	rep(i, 0, n) rep(j, 0, n) dp[i][j] = vis[i][j] = 0;
}
void recover(){
	cnt = 1; cs = 0;
	rep(i, 1, n) vvis[i] = h[i] = 0;
}

int c[maxn];
void add(int x, int v){
	while (x){
		c[x] = max(c[x], v);
		x -= lowbit(x);
	}
}
int get(int x){
	int ans = 0;
	while (x <= n) {
		ans = max(ans, c[x]);
		x += lowbit(x);
	}
	return ans;
}

int c2[maxn];
void add2(int x, int v){
	while (x <= n){
		c2[x] = max(c2[x], v);
		x += lowbit(x);
	}
}
int get2(int x){
	int ans = 0;
	while (x) {
		ans = max(ans, c2[x]);
		x -= lowbit(x);
	}
	return ans;
}


int main(){
	
		freopen("G.in", "r", stdin);
	
	int x, y;	
	while (1){
		scanf("%d", &n);
		int ans = n + 1, ptr, tot;
		if (!n) return 0;
		rep(i, 1, n) scanf("%d%d", &x, &y), Add_Edge(i, x), Add_Edge(i, y); DFS(1, -1);
		rep(i, 1, n) if (!vvis[i]) {printf("Not solvable.\n"); goto jump;}
		printf("Knot solvable.\n");
		assert(cs == n); 
		//rep(i, 1, n) printf("%d ", lis[i]); printf("\n");
		
		rep(i, 1, n){
			per(j, n, 1){
				int mx = get(lis[j] + 1);
				add(lis[j], mx + 1);
				ans = min(ans, n - mx - 1);
			} 
			int t = lis[1];
			srep(j, 1, n) lis[j] = lis[j + 1];
			lis[n] = t;
			rep(j, 1, n) c[j] = 0;
		}
		
		
		rep(i, 1, n){
			per(j, n, 1){
				int mx = get2(lis[j] - 1);
				add2(lis[j], mx + 1);
				ans = min(ans, n - mx - 1);
			} 
			int t = lis[1];
			srep(j, 1, n) lis[j] = lis[j + 1];
			lis[n] = t;
			rep(j, 1, n) c2[j] = 0;
		}
		
		/*
			type = 0;
			ans = min(ans, n - DP(1, 0));
			dprecover();
			type = 1;
			ans = min(ans, n - DP(1, 0));
			dprecover();
		*/
		printf("%d\n", ans);
		jump: recover();
	}
	return 0;
}

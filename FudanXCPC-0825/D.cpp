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
#define maxn 20020
#define maxm
#define ls ch[x][0]
#define rs ch[x][1]
using namespace std;

const int inf = 2000000000;

int n, m, a[maxn];
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
int fa[maxn], ch[maxn][2];
void dfs(int x){
	ls = rs = 0;
	erep(i, x){
		int op = e[i].to;
		if (op == fa[x]) continue;
		fa[op] = x;
		if (!ls) ls = op;
		else rs = op;
		dfs(op);
	}
}
int idx = 0;
int vis[maxn][2][2][2];
int dp[maxn][2][2][2];
int DP(int x, int p1, int p2, int goal){
	if (!x) return 0;
	if (vis[x][p1][p2][goal] == idx) return dp[x][p1][p2][goal];
	vis[x][p1][p2][goal] = idx;
	int& ans = dp[x][p1][p2][goal];
	ans = inf;	
	if (p2) {
		rep(subv, 0, 1){
			rep(lsv, 0, 1){
				if (!ls && lsv) continue;
				rep(rsv, 0, 1){ 
					if (!rs && rsv) continue;
					if (lsv && rsv) continue; 
					int st = a[x] ^ p1 ^ subv ^ p2;
					if (st ^ goal) continue;  
					ans = min(ans, DP(ls, p1 ^ subv, lsv, goal) + DP(rs, p1 ^ subv, rsv, goal) + subv);
				}
			}
		}
	}
	else {
		rep(subv, 0, 1){
			rep(lsv, 0, 1){
				if (!ls && lsv) continue;
				rep(rsv, 0, 1){ 
					if (!rs && rsv) continue; 
					bool hav = (lsv || rsv);
					int st = a[x] ^ p1 ^ subv ^ hav;
					if (!hav){
						if (st ^ goal) ans = min(ans, DP(ls, p1 ^ subv, lsv, goal) + DP(rs, p1 ^ subv, rsv, goal) + subv + 1);
						else ans = min(ans, DP(ls, p1 ^ subv, lsv, goal) + DP(rs, p1 ^ subv, rsv, goal) + subv);
					}
					else {
						if (st ^ goal) continue;  
						ans = min(ans, DP(ls, p1 ^ subv, lsv, goal) + DP(rs, p1 ^ subv, rsv, goal) + subv + hav);
					} 
				}
			}
		}
	} 
	return ans;
}

int main(){
	int x, y;
	while (scanf("%d", &n) == 1){
		idx++;
		printf("Case %d: ", idx); 
		rep(i, 2, n) scanf("%d%d", &x, &y), Add_Edge(x, y);
		rep(i, 1, n) scanf("%d", a + i);
		dfs(1);
		printf("%d\n", min(DP(1, 0, 0, 0), DP(1, 0, 0, 1)));
		//printf("%d %d\n", DP(1, 0, 0, 0), DP(1, 0, 0, 1));
		rep(i, 1, n) h[i] = 0; cnt = 1;
	}
	return 0;
}

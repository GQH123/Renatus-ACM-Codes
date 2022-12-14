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
using namespace std;

const int inf = 2000000000;

int n, a[maxn], idx = 0, son[maxn];
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
void dfs(int x, int fa){
	son[x] = 0;
	erep(i, x){
		int op = e[i].to;
		if (op == fa) continue;
		son[x]++;
		dfs(op, x);
	}
}

int vis[maxn][2][2][2];
int dp[maxn][2][2][2];
int lis[maxn], cs = 0;
int DP(int x, int op1, int op2, int goal, int fa){
	if (vis[x][op1][op2][goal] == idx) return dp[x][op1][op2][goal];
	vis[x][op1][op2][goal] = idx; int& ans = dp[x][op1][op2][goal]; ans = inf;
	
	
	
	
	
	
	
	
	
	
	erep(i, x){
		int op = e[i].to;
		if (op == fa) continue;
		DP(op, 0, 0, goal, x);
		DP(op, 0, 1, goal, x);
		DP(op, 1, 0, goal, x);
		DP(op, 1, 1, goal, x);
	}
	
	
	
	
	
	
	
	
	
	
	
	if (true){
		if (true){
			cs = 0; int sum = 0;
			erep(i, x){
				int op = e[i].to;
				if (op == fa) continue;
				lis[++cs] = DP(op, op1 ^ 1, 1, goal, x) - DP(op, op1 ^ 1, 0, goal, x), sum += DP(op, op1 ^ 1, 0, goal, x);
			}
			sort(lis + 1, lis + 1 + cs);   
			
			
			int st = a[x] ^ (op1 ^ 1), offset = 1, ptr = 1;
			if (st ^ goal) {
				for (register int i = 1; i <= (son[x] + 1) / 2; i += 2){	
					while (ptr <= (i << 1) && ptr <= cs) {
						sum += lis[ptr];
						ptr++;
					}
					ans = min(ans, sum + offset + i);
				}
			}
			else {
				for (register int i = 0; i <= (son[x] + 1) / 2; i += 2){	
					while (ptr <= (i << 1) && ptr <= cs) {
						sum += lis[ptr];
						ptr++;
					}
					ans = min(ans, sum + offset + i);
				}
			}
		}
		
		
		
		
		
		if (true){
			cs = 0; int sum = 0;
			erep(i, x){
				int op = e[i].to;
				if (op == fa) continue;
				lis[++cs] = DP(op, op1, 1, goal, x) - DP(op, op1, 0, goal, x), sum += DP(op, op1, 0, goal, x);
			}
			sort(lis + 1, lis + 1 + cs); 
			
			
			int st = a[x] ^ op1, offset = 0, ptr = 1;
			if (st ^ goal) {
				for (register int i = 1; i <= (son[x] + 1) / 2; i += 2){	
					while (ptr <= (i << 1) && ptr <= cs) {
						sum += lis[ptr];
						ptr++;
					}
					ans = min(ans, sum + offset + i);
				}
			}
			else {
				for (register int i = 0; i <= (son[x] + 1) / 2; i += 2){	
					while (ptr <= (i << 1) && ptr <= cs) {
						sum += lis[ptr];
						ptr++;
					}
					ans = min(ans, sum + offset + i);
				}
			} 
		} 
	} 
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	if (op2){
		if (true){
			cs = 0; int sum = 0;
			erep(i, x){
				int op = e[i].to;
				if (op == fa) continue;
				lis[++cs] = DP(op, op1 ^ 1, 1, goal, x) - DP(op, op1 ^ 1, 0, goal, x), sum += DP(op, op1 ^ 1, 0, goal, x);
			}
			sort(lis + 1, lis + 1 + cs); 
			
			
			int st = a[x] ^ (op1 ^ 1) ^ op2, offset = 1, ptr = 1;
			if (st ^ goal) {
				for (register int i = 1; i <= (son[x] + 1) / 2; i += 2){	
					while (ptr <= (i << 1 | 1) && ptr <= cs) {
						sum += lis[ptr];
						ptr++;
					}
					ans = min(ans, sum + offset + i);
				}
			}
			else {
				for (register int i = 0; i <= (son[x] + 1) / 2; i += 2){	
					while (ptr <= (i << 1 | 1) && ptr <= cs) {
						sum += lis[ptr];
						ptr++;
					}
					ans = min(ans, sum + offset + i);
				}
			}
		}
		
		
		
		
		
		
		if (true){
			cs = 0; int sum = 0;
			erep(i, x){
				int op = e[i].to;
				if (op == fa) continue;
				lis[++cs] = DP(op, op1, 1, goal, x) - DP(op, op1, 0, goal, x), sum += DP(op, op1, 0, goal, x);
			}
			sort(lis + 1, lis + 1 + cs); 
			
			
			int st = a[x] ^ op1 ^ op2, offset = 0, ptr = 1;
			if (st ^ goal) {
				for (register int i = 1; i <= (son[x] + 1) / 2; i += 2){	
					while (ptr <= (i << 1 | 1) && ptr <= cs) {
						sum += lis[ptr];
						ptr++;
					}
					ans = min(ans, sum + offset + i);
				}
			}
			else {
				for (register int i = 0; i <= (son[x] + 1) / 2; i += 2){	
					while (ptr <= (i << 1 | 1) && ptr <= cs) {
						sum += lis[ptr];
						ptr++;
					}
					ans = min(ans, sum + offset + i);
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
		dfs(1, 0);
		//printf("%d\n", min(DP(1, 0, 0, 0), DP(1, 0, 0, 1)));
		printf("%d %d\n", DP(1, 0, 0, 0, 0), DP(1, 0, 0, 1, 0));
		rep(i, 1, n) son[i] = h[i] = 0; cnt = 1;
	}
	return 0;
}

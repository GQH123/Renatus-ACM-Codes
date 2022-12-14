#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define maxn 300020
#define pb push_back 
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

int c[maxn];
int num[maxn][3], ct = 0;
vector<int> ss[maxn];
int vis[maxn][3][3];
void DFS(int x, int fa, int d, int op){ // op = 1 / 2
	if (vis[x][d][op] == -1) return;
	
	if (vis[x][d][op] == 0) vis[x][d][op] = fa;
	else if (vis[x][d][op] == fa) return;
	else vis[x][d][op] = -1;
	
	if (!d) {
		if (c[x]) return;
		c[x] = op, num[ct][op]++;
		ss[ct].pb(x);
		erep(i, x){
			int u = e[i].to;
			if (u == fa) continue;
			DFS(u, x, 2, 3 - op);
		}
	}
	else {
		erep(i, x){
			int u = e[i].to;
			if (u == fa) continue;
			DFS(u, x, d - 1, 3 - op);
		}
	}
}
stack<int> pool[4];

int res[maxn];
int main(){	
	int x, y;
	scanf("%d", &n);
	rep(i, 1, n) pool[(i - 1) % 3 + 1].push(i);
	rep(i, 2, n) scanf("%d%d", &x, &y), Add_Edge(x, y);
	rep(i, 1, n) if (!c[i]) ct++, DFS(i, -1, 0, 1);  
	if (ct > 3){
		rep(i, 1, n){
			printf("%d ", i);
			return 0;
		}
	}
	else {
		int all1 = (n + 2) / 3, all2 = (n + 1) / 3, rest = n / 3;
		srep(S, 0, (1 << ct)){
			int num1 = 0, num2 = 0;
			rep(i, 1, ct){
				if (S & (1 << (i - 1))) num1 += num[i][1], num2 += num[i][2]; 
				else num1 += num[i][2], num2 += num[i][1];
			}
			if (num1 < all1 || num2 < all2) continue;
			int d = num1 + num2 - all1 - all2;
			if (d <= rest){
				while (num1 > all1) {
					rep(i, 1, ct){
						if (S & (1 << (i - 1))){
							int si = ss[i].size();
							srep(j, 0, si){
								int x = ss[i][j];
								if (c[x] == 1) {
									res[x] = pool[3].top();
									pool[3].pop();
									num1--;
									c[x] = 3;
									if (num1 == all1) goto done1;
								}
							}
						}
						else {
							int si = ss[i].size();
							srep(j, 0, si){
								int x = ss[i][j];
								if (c[x] == 2) {
									res[x] = pool[3].top();
									pool[3].pop();
									num1--;
									c[x] = 3;
									if (num1 == all1) goto done1;
								}
							}
						} 
					}
				}
				done1:;
				while (num2 > all2){
					rep(i, 1, ct){
						if (S & (1 << (i - 1))){
							int si = ss[i].size();
							srep(j, 0, si){
								int x = ss[i][j];
								if (c[x] == 2) {
									res[x] = pool[3].top();
									pool[3].pop();
									num2--;
									c[x] = 3;
									if (num2 == all2) goto done2;
								}
							}
						}
						else {
							int si = ss[i].size();
							srep(j, 0, si){
								int x = ss[i][j];
								if (c[x] == 1) {
									res[x] = pool[3].top();
									pool[3].pop();
									num2--;
									c[x] = 3;
									if (num2 == all2) goto done2;
								}
							}
						} 
					}
				}
				done2:;
				rep(i, 1, ct){
					if (S & (1 << (i - 1))){
						int si = ss[i].size();
						srep(j, 0, si){
							int x = ss[i][j];
							if (c[x] != 3) {
								res[x] = pool[c[x]].top();
								pool[c[x]].pop();  
							}
						}
					}
					else {
						int si = ss[i].size();
						srep(j, 0, si){
							int x = ss[i][j];
							if (c[x] != 3) {
								res[x] = pool[3 - c[x]].top();
								pool[3 - c[x]].pop();  
							}
						}
					}
				}
				rep(i, 1, n) printf("%d ", res[i]);
				return 0;
			}
		}
		printf("-1");
	}
	return 0;
}

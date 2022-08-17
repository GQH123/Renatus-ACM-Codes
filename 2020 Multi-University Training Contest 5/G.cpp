#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define maxn 400020
#define ll long long int 
#define pii pair<ll, int>
#define fi first
#define se second
#define rank RANK
using namespace std;

int n, k;
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

int tim = 0;
int vis[maxn][2][2];
ll dp[maxn][2][2];

ll temp[maxn]; 
pii temp2[maxn]; 
int rank[maxn];

int fa[maxn];
void DFS(int x){
	erep(i, x){
		int op = e[i].to;
		if (op == fa[x]) continue;
		fa[op] = x;
		DFS(op);
	}
}

ll DP(int x, bool root, bool hav){
	if (vis[x][root][hav] == tim) return dp[x][root][hav];
	vis[x][root][hav] = tim;
	ll& ans = dp[x][root][hav]; ans = 0;
	int lim = (root) ? k : (k - 1); 
	
	if (hav){ 
		erep(i, x) {
			int op = e[i].to;
			if (op == fa[x]) continue;
			DP(op, 0, 0); DP(op, 0, 1);
		}
		ll _ans = 0;
		erep(i, x) {
			int op = e[i].to;
			if (op == fa[x]) continue;
			_ans += DP(op, 0, 0) + e[i].len;
		}
		ans = max(ans, _ans); 
		if (!lim) return ans;
		int ct2 = 0;
		erep(i, x) {
			int op = e[i].to;
			if (op == fa[x]) continue;
			temp2[++ct2] = pii(DP(op, 0, 0) + e[i].len, op);
		}
		sort(temp2 + 1, temp2 + 1 + ct2);
		//reverse(temp2 + 1, temp2 + 1 + ct2);
		rep(i, 1, ct2) rank[temp2[i].se] = ct2 + 1 - i;
		
		_ans = 0;
		rep(i, 1, min(ct2, lim)) _ans += temp2[ct2 - i + 1].fi;
		ans = max(ans, _ans);
		
		ll mi = temp2[ct2 + 1 - min(ct2, lim)].fi;
		erep(i, x){
			int op = e[i].to;
			if (op == fa[x]) continue;
			if (rank[op] <= lim) {
				ans = max(ans, _ans + DP(op, 0, 1) - DP(op, 0, 0));
				//ans = max(ans, _ans - mi + DP(op, 0, 1) + e[i].len);
			}
			else {
				ans = max(ans, _ans - mi + DP(op, 0, 1) + e[i].len);
			}
		}
		
		//rep(i, 1, ct2) temp2[i] = pii(0, 0); ct2 = 0;
	}
	else { 
		erep(i, x) {
			int op = e[i].to;
			if (op == fa[x]) continue;
			DP(op, 0, 0);
		}
		int ct = 0;
		erep(i, x) {
			int op = e[i].to;
			if (op == fa[x]) continue;
			temp[++ct] = DP(op, 0, 0) + e[i].len;
		}
		sort(temp + 1, temp + 1 + ct);
		rep(i, 1, min(ct, lim)) ans += temp[ct - i + 1];
		//rep(i, 1, ct) temp[i] = 0; ct = 0;
	}
	return ans;
}

int main(){
	int T, x, y, z; scanf("%d", &T);
	while (T--){
		tim++;
		scanf("%d%d", &n, &k);
		rep(i, 2, n) scanf("%d%d%d", &x, &y, &z), Add_Edge(x, y, z);
		ll res = 0;
		if (!k) {printf("0\n"); goto done;}
		fa[1] = -1;
		DFS(1); 
		rep(i, 1, n) res = max(res, DP(i, 1, 1));
		printf("%lld\n", (long long int)res);
		
		//rep(i, 1, ct) temp[i] = 0;
		//rep(i, 1, ct2) temp2[i] = pii(0, 0);
		done:cnt = 1; 
		rep(i, 1, n) h[i] = 0;
		rep(i, 1, n) rep(j, 0, 1) rep(l, 0, 1) dp[i][j][l] = 0;
	}
	return 0;
}

/*
Correct: 2220492007
My:      2880707415
20 1
2 1 614280960
3 1 629397560
4 3 266353200
2 5 708751622
6 2 618828720
7 1 528262668
7 8 303882232
9 3 286447136
10 9 417196960
3 11 135478680
12 9 104211412
6 13 748654156
14 7 764885120
6 15 827683160
11 16 514939136
17 15 417908650
16 18 722242310
19 15 974900197
1 20 49842696
*/

/*
6
7 2
1 2 5
2 3 2
2 4 3
2 5 4
1 6 6
6 7 8
6 1
1 2 5
2 3 2
2 4 3
2 5 4
1 6 6
5 2
1 2 5
2 3 2
2 4 3
2 5 4
5 2
1 2 5
2 3 2
2 4 3
2 5 4
5 0
1 2 5
2 3 2
2 4 3
2 5 4
7 2
1 2 5
2 3 2
2 4 3
2 5 4
1 6 6
6 7 8
*/

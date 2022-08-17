#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define maxn 200020
#define maxm 400020
#define pb push_back 
#define pii pair<int, int>
#define fi first
#define se second
#define ll long long int 
#define lowbit(x) (x & -x) 
using namespace std;    

int n, m;
char s1[maxn], s2[maxn];
struct edge{
	int next, to;
	edge(int next, int to) : next(next), to(to){}
	edge(){}
}e[maxm << 1];
int cnt = 1, h[maxn], out[maxn][7];
void Add_Edge(int x, int y){	
	e[++cnt] = edge(h[y], x);
	h[y] = cnt;
	rep(j, 1, 6) out[x][j]++;
}//reverse

inline bool isA(int who){
	return (s1[who] == 'A' && s2[who] == '0') || (s1[who] == 'B' && s2[who] == '1');
}
inline bool isB(int who){
	return !isA(who);
}

pii bfs[maxn << 3];
int head = 0, tail = 0;
int vis[maxn][7];
int dp[maxn][7];
set<pii> pool;
void topo_sort(){
	int ct = 0;
	rep(i, 1, n) rep(j, 1, 6) if (!out[i][j]) bfs[++head] = pii(i, j), dp[i][j] = (s1[j] == 'A') ? 2 : 1, ct++, vis[i][j] = 1;
	while (ct < n * 6){
		while (tail < head){
			pii op = bfs[++tail];
			int x = op.fi, who = op.se, d = dp[x][who];
			erep(i, x){
				int u = e[i].to;
				
				int prewho = (who + 4) % 6 + 1;
				if (!(dp[u][prewho] == 1 || dp[u][prewho] == 2)){
					if (d == 4) dp[u][prewho] = 4;
					else if (d == 1){
						if (isA(prewho)) {	
							dp[u][prewho] = 1;
							if (!pool.count(pii(u, prewho))) pool.insert(pii(u, prewho)); 
						}
					}
					else {
						if (isB(prewho)) {
							dp[u][prewho] = 2; 
							if (!pool.count(pii(u, prewho))) pool.insert(pii(u, prewho)); 
						}
					}
				} 
				
				out[u][prewho]--;
				if (!out[u][prewho] && !vis[u][prewho]){
					if (dp[u][prewho] == 0) {
						if (isA(prewho)) dp[u][prewho] = 2;
						else dp[u][prewho] = 1;
					}
					ct++;
					bfs[++head] = pii(u, prewho), vis[u][prewho] = 1;
					if (pool.count(pii(u, prewho))) pool.erase(pii(u, prewho));
				}
			}
		} 
		if (ct < n * 6){ 
			if (pool.empty()) return;
			while (!pool.empty()){	
				pii op = *pool.begin(); pool.erase(op);
				bfs[++head] = op, vis[op.fi][op.se] = 1, ct++;
			}
			/*
			rep(i, 1, n){
				rep(j, 1, 6) {
					if (vis[i][j]) continue;
					if (dp[i][j] == 1 || dp[i][j] == 2) bfs[++head] = pii(i, j), vis[i][j] = 1, ct++, f = 1;
				}
			}
			*/ 
		}
	}
	
}

/*
int DP(int pos, int who){
	if (vis[pos][who] == 1) return 4;
	else if (vis[pos][who] == 2) return dp[pos][who];
	vis[pos][who] = 1;
	int& ans = dp[pos][who]; ans = 0;
	bool f = 0;
	erep(i, pos) { 
		f = 1;
		break;
	}
	if (!f) ans = (s1[who] == 'A') ? 2 : 1; 
	else {
		int draw = 0, bad = 0;
		erep(i, pos) { 
			int d = DP(e[i].to, who % 6 + 1);
			if (d == 4) draw = 4; 
			else if (d == 1){
				if () {ans = 1; goto done;}
				else bad = 1;
			}
			else {
				if ((s1[who] == 'B' && s2[who] == '0') || (s1[who] == 'A' && s2[who] == '1')) {ans = 2; goto done;}
				else bad = 2;
			}
		}
		if (draw) {ans = 4; goto done;}
		else {
			assert(bad);
			ans = bad;
		}
	}
	done:;
	vis[pos][who] = 2;
	return ans;
}
*/

int main(){	  
	int T, x, y, op;
	scanf("%d", &T);
	while (T--){ 
		scanf("%d%d", &n, &m); 
		rep(i, 1, m) scanf("%d%d", &x, &y), Add_Edge(x, y);
		scanf("%s%s", s1 + 1, s2 + 1);
		//rep(i, 1, 6) if (s2[i] == '1') s1[i] = (s1[i] == 'A') ? 'B' : 'A';
		topo_sort(); 
		rep(i, 1, n){
			//int d = DP(i, 1);
			int d = dp[i][1];
			if (d == 1) printf("A");
			else if (d == 2) printf("B");
			else printf("D"); // d == 4 || d == 0
		}
		printf("\n");
		rep(i, 1, n) rep(j, 1, 6) vis[i][j] = dp[i][j] = out[i][j] = 0;
		cnt = 1;
		rep(i, 1, n) h[i] = 0;
		head = tail = 0;
	}
	return 0;
}

/*
8
10 10
1 2
2 3
3 4
4 5
5 6
6 1
1 7
2 8
4 9
5 10
AAABBB
000000
4 4
1 2
2 3
3 1
1 4
AAABBB
000000
6 6
1 2
2 3
3 1
1 4
2 5
5 6
AAABBB
001000
10 10
1 2
2 3
3 4
4 5
5 6
6 1
1 7
2 8
4 9
5 10
AAABBB
000000
1 1
1 1
AABABB
001001
2 2
1 1
1 2
AABABB
000000
2 2
1 1
1 2
AABABB
010010
2 3
1 1
1 2
2 2
AABABB
000001



DAADAABBBB
DADB
ABBBBB
DAADAABBBB
D
AB
BB
DD
*/

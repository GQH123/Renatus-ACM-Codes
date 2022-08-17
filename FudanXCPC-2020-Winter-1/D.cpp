#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int 
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first 
#define se second 
#define maxr 100019
#define maxn 4020
#define maxm
#define maxs 
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template<class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}

const int inf = 2000000020;

int n, k;
int f1[maxn];
int f0[maxn];
bool vis[maxn][maxn][2];
int dp[maxn][maxn][2];
int DP(int l, int r, bool op){
	if (l >= r) return 0;
	if (vis[l][r][op]) return dp[l][r][op];
	vis[l][r][op] = 1;
	int& ans = dp[l][r][op];
	ans = inf;
	if (op == 0){
		rep(nex, l + 1, r){
			if (nex - l > k) break;
			ans = min(f1[nex - l] + max(DP(l + 1, nex, 1), DP(nex, r, 0)), ans);
		}
	}
	else{
		per(nex, r - 1, l){
			if (r - nex > k) break;
			ans = min(f0[r - nex] + max(DP(nex, r - 1, 0), DP(l, nex, 1)), ans);
		}
	}
	return ans;
}


struct edge{
	int next, to, len;
	edge(int next, int to, int len) : next(next), to(to), len(len){}
	edge(){}
}
int cnt = 1, h[maxn];
void Add_Edge(int x, int y, int z){
	e[++cnt] = edge(h[x], y, z);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x, z);
	h[y] = cnt;
}


int spfa[maxn];
int tail, head;
bool vis[maxn];
int d[maxn];
void SPFA(int s){
	srep(i, 1, maxn) d[i] = inf; d[s] = 0;
	spfa[++head] = s;
	if (head == maxn - 1) head = 0;
	vis[s] = 1;
	while (head != tail){
		int x = spfa[++tail];
		if (tail == maxn - 1) tail = 0;
		erep(i, x){
			int op = e[i].to;
			if (d[op] > d[x] + e[i].len) {
				d[op] = d[x] + e[i].len;
				if (!vis[op]) {
					vis[op] = 1, spfa[++head] = op;
					if (head == maxn - 1) head = 0;
				}
			}
		}
		vis[x] = 0;
	}
	rep(i, 1, k) f1[i] = d[s + i], f0[i] = d[s - i];
}

int main(){
	
		#ifndef ONLINE_JUDGE
			freopen("D.in", "r", stdin);
		#endif
	
	scanf("%d%d", &n, &k);
	rep(i, 1, k) scanf("%d", &f1[i]);
	rep(i, 1, k) scanf("%d", &f0[i]);	
	
	int s = k + 1;
	rep(i, 1, 2k + 1){
		rep(j, 1, k){
			if (i - j < 1) break;
			Add_Edge(
		}
		rep(j, 1, k){
			if (i + j > 2 * k) break;
		}
	}
	rep(i, 1, k) Add_Edge(s, s + i, f1[i]), Add_Edge(s, s - i, 
	printf("%d", DP(1, n, 0));
	return 0;
}

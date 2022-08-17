#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define ll long long int 
#define pb push_back
#define pc putchar
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn 120
#define maxm 
#define maxs
#define maxb 10
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

/*
int ti;
int n;
pii p[maxn];
int dp[maxn][1 << maxb];
int vis[maxn][1 << maxb];
int bc[1 << maxb];
int DP(int pos, int last, int op){
	if (op == (1 << n) - 1) return n;
	if (vis[pos][last][op] == ti) return dp[pos][last][op];
	vis[pos][last][op] = ti;
	int& ans = dp[pos][last][op];
	ans = bc[op];
	if (ans & 1){
		srep(i, 0, n){	
			if (op & (1 << i)) {
				
			}
		}
	}
	else {
	}
	
}
*/

int n;
pii p[maxn], k[maxn][maxn];
set<pii> s;

int gcd(int x, int y){
	if (!y) return x;
	return gcd(y, x % y);
}

int to[maxn];

int ins[maxn];
int len = 0, ans = 0;
void DFS(int x, pii dir){
	//ins[x] = 1, len++;
	if (!ins[x]) ins[x]++, len++, ans = max(ans, len); 
	else {
		ins[x]++;
		if (ins[to[x]] == 1) {
			DFS(to[x], dir);
			ins[x]--;
			return;
		}
	} 
	if (!to[x]){
		rep(i, 1, n) if (!ins[i] && ans != n) {
			to[x] = i, to[i] = x;
			DFS(i, dir);
			to[x] = to[i] = 0;
		}
	}
	else {
		if (dir == pii(0, 0)){
			rep(i, 1, n){
				if (ins[i] == 2 || i == x) continue;
				if (k[i][x] != pii(0, 0) && ans != n) DFS(i, k[i][x]); 
			}
		}
		else {
			rep(i, 1, n){		
				if (ins[i] == 2 || i == x) continue;
				if (k[i][x] == dir && ans != n) DFS(i, dir);
			}
		}
	}
	if (ins[x] == 2) ins[x]--;
	else ins[x]--, len--; 
}

int main(){
	//srep(i, 1, (1 << maxb)) bc[i] = bc[i >> 1] + (i & 1);
	int T;
	scanf("%d", &T);
	rep(TT, 1, T){
		//ti++;
		printf("Case #%d: ", TT);
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d%d", &p[i].fi, &p[i].se);
		sort(p + 1, p + 1 + n);
		//srep(i, 0, n) scanf("%d%d", &p[i].fi, &p[i].se);
		//int ans = 0;
		/*
		srep(i, 0, n){
			srep(j, 0, n){
				if (i == j) continue;
				srep(k, 0, n){
					if (i == k || j == k) continue;
					ans = max(ans, DP(k, j, (1 << i) | (1 << j) | (1 << k)));
				}
			}
		}
		*/ 
		rep(i, 1, n) ins[i] = 0, to[i] = 0, k[i][i] = pii(0, 0);
		len = 0;
		rep(i, 1, n){	
			s.clear();
			per(j, i - 1, 1){	
				int x = p[j].fi - p[i].fi;
				int y = p[j].se - p[i].se;
				int d = gcd(abs(x), abs(y));
				//assert(d);
				x /= d, y /= d; 
				if (s.count(pii(x, y))) k[j][i] = k[i][j] = pii(0, 0);
				else k[j][i] = pii(x, y), k[i][j] = pii(-x, -y), s.insert(pii(x, y));
			}
		}
		s.clear();
		ans = 0;
		rep(i, 1, n) DFS(i, pii(0, 0));
		printf("%d\n", ans); 
	} 
	return 0;
}


#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
#define maxr 100000
#define maxn 220
#define maxs (maxn * maxn)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define M 78294349
using namespace std;

int r, c; 
char s[maxn][maxn];
int g[maxn][maxn], _g[maxn][maxn];
int gcd(int x, int y){
	return (!y) ? x : gcd(y, x % y);
}

pii pos[maxn * maxn];

inline void debug(){
	/*printf("\n");
	rep(i, 1, r) {
		rep(j, 1, c){
			printf("%d\t", g[i][j]);
			//if (g[i][j]) printf("#");
			//else printf(".");
		}
		printf("\n");
	}
	printf("\n");
	*/
}

int cnt = 0;
bool vis[maxn][maxn];
int lis[maxn * maxn];
int cs = 0;
void dfs(int x, int y){
	if (vis[x][y]) return;
	vis[x][y] = 1;
	cnt++;
	int v = g[x][y];
	int _x = pos[v].fi, _y = pos[v].se;
	dfs(_x, _y);
}


int add[maxs];
int p[maxs];
int cp = 0;
bool visp[maxs];
int son[maxs];
void init(){
	rep(i, 2, maxs) {
		if (!visp[i]) p[++cp] = i, son[i] = cp;
		rep(j, 1, cp){
			if (i * p[j] >= maxs) break;
			visp[i * p[j]] = 1;
			son[i * p[j]] = j;
			if (i % p[j] == 0) break;
		}
	}
}

ll power(ll x, ll y){
	ll ans = 1, con = x;
	while (y){
		if (y & 1) ans = ans * con % M;
		con = con * con % M;
		y >>= 1;
	}
	return ans;
}

void recover(){
	cnt = cs = 0;
	rep(i, 1, r) rep(j, 1, c) vis[i][j] = 0;
	rep(i, 1, cp) add[i] = 0;
}

int main(){
	
		#ifndef ONLINE_JUDGE
			freopen("H.in", "r", stdin);
		#endif
		
	init();
	
	int T;
	scanf("%d", &T);
	rep(TT, 1, T){
		printf("Case %d: ", TT);
		scanf("%d%d", &r, &c);
		rep(i, 1, r) scanf("%s", s[i] + 1);
		int ct = 0;
		rep(i, 1, r){
			rep(j, 1, c){
				if (s[i][j] == '#') _g[i][j] = g[i][j] = ++ct, pos[_g[i][j]] = pii(i, j);
				else _g[i][j] = g[i][j] = 0;
			}
		}
		
		//--->
		rep(i, 1, r){
			int flag = -1;
			per(j, c, 1){
				if (g[i][j]) {
					flag = j;
					break;
				}
			}
			if (flag == -1) continue;
			int ptr = c;
			per(j, flag, 1) g[i][ptr--] = g[i][j];
			per(j, ptr, 1) g[i][j] = 0;
		}debug();
		
		
		//^
		rep(j, 1, c){
			int flag = -1;
			rep(i, 1, r){
				if (g[i][j]) {
					flag = i;
					break;
				}
			}
			if (flag == -1) continue;
			int ptr = 1;
			rep(i, flag, r) g[ptr++][j] = g[i][j];
			rep(i, ptr, r) g[i][j] = 0;
		}debug();
		
		//<--
		rep(i, 1, r){
			int flag = -1;
			rep(j, 1, c){
				if (g[i][j]) {
					flag = j;
					break;
				}
			}
			if (flag == -1) continue;
			int ptr = 1;
			rep(j, flag, c) g[i][ptr++] = g[i][j];
			rep(j, ptr, c) g[i][j] = 0;
		}debug();
		
		//V
		rep(j, 1, c){
			int flag = -1;
			per(i, r, 1){
				if (g[i][j]) {
					flag = i;
					break;
				}
			}
			if (flag == -1) continue;
			int ptr = r;
			per(i, flag, 1) g[ptr--][j] = g[i][j];
			per(i, ptr, 1) g[i][j] = 0;
		}debug();
		
		rep(i, 1, r){
			rep(j, 1, c){
				if (!g[i][j]) continue;
				if (!vis[i][j]) {
					int _cnt = cnt;
					dfs(i, j);
					lis[++cs] = cnt - _cnt;
				}
			}
		}
		
		//int sum = 0;
		//rep(i, 1, cs) printf("%d ", lis[i]), sum += lis[i];
		//printf("%d", sum);
		/*ll ans = 1;
		rep(i, 1, cs){
			ans = ans * lis[i] / gcd(ans, lis[i]);
		}
		*/
		rep(i, 1, cs){
			int x = lis[i];
			while (x > 1){
				int sonn = son[x], s = 0;
				while (x > 1 && son[x] == sonn){
					s++;
					x /= p[son[x]];
				}
				add[sonn] = max(add[sonn], s);
			}
		}
		
		ll ans = 1;
		rep(i, 1, cp){
			ans = ans * power(p[i], add[i]) % M;
		}
		printf("%lld\n", ans);
		recover();
	}
	return 0;
}

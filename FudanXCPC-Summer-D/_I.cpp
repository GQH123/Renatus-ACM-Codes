#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define maxn 5020
#define maxm 
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define pc putchar
#define ll long long int 
#define ld long double 
#define lowbit(x) (x & -x)
#define M 1000000007
#define mo(x) (x = (x >= M) ? (x - M) : x)
using namespace std;

int n, m, _k;
bool key[maxn];
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
int power(int x, int y){
	int ans = 1, con = x;
	while (y){
		if (y & 1) ans = 1ll * ans * con % M;
		con = 1ll * con * con % M;
		y >>= 1;
	}
	return ans;
}
int getinv(int x){
	return power(x, M - 2);
}
int tim = 0;
int vis[maxn][maxn];
int dp[maxn][maxn];
int vis2[maxn][maxn];
int dp2[maxn][maxn];
extern int DP(int x, int fa, int k);
int DP2(int x, int fa, int k){ 
	if (k < 0) return 1; 
	//if (!k) return (key[x]) ? 1 : 0; 
	if (vis2[x][k] == tim) return dp2[x][k];
	vis2[x][k] = tim; 
	int& ans = dp2[x][k]; ans = 1;
	rep(i, 0, k) ans += DP(x, fa, i), mo(ans); 
	return ans;
}
int DP(int x, int fa, int k){
	if (k < 0) return 0; 
	if (!k) return (key[x]) ? 1 : 0; 
	if (vis[x][k] == tim) return dp[x][k];
	vis[x][k] = tim;  
	int& ans = dp[x][k]; ans = 0;
	if (k == _k + 1){
		erep(i, x){
			int op = e[i].to;
			if (op == fa) continue;
			ans += DP(op, x, _k + 1), mo(ans);
		}
		if (key[x]) ans += (DP2(x, fa, _k) + M - 1) % M, mo(ans);
		ans += (DP2(x, fa, _k) + M - 1) % M, mo(ans);
		ans += M - DP(x, fa, 0), mo(ans);
		erep(i, x){
			int op = e[i].to;
			if (op == fa) continue;
			ans += (1 + M - DP2(op, x, _k - 1)), mo(ans);
		} 
		return ans;
	}
	else {
		if ((k << 1) <= _k) {
			int temp = 1, _temp = 1;
			erep(i, x){
				int op = e[i].to;
				if (op == fa) continue;
				temp = 1ll * temp * DP2(op, x, k - 1) % M;
				_temp = 1ll * _temp * DP2(op, x, k - 2) % M;
			}
			ans += (temp + M - _temp) % M, mo(ans);
		}
		else {
			int temp = 1, sum = 0;
			erep(i, x){
				int op = e[i].to;
				if (op == fa) continue;
				temp = 1ll * temp * DP2(op, x, _k - k - 1) % M; 
				sum += 1ll * DP(op, x, k - 1) * getinv(DP2(op, x, _k - k - 1)) % M;
			} 
			ans += 1ll * temp * sum % M, mo(ans);
		}
		return ans;
	} 
}

void recover(){
	rep(i, 1, n) key[i] = h[i] = 0;
	cnt = 1;
}

int main(){
	int x, y;
	while (scanf("%d%d%d", &n, &m, &_k) == 3){
		++tim;
		srep(i, 1, n) scanf("%d%d", &x, &y), Add_Edge(x, y);
		rep(i, 1, m) scanf("%d", &x), key[x] = 1; 
		m = 0;
		rep(i, 1, n) if (key[i]) m++; 
		if (_k == 0) {printf("%d\n", m); goto done;}
		printf("%d\n", DP(1, -1, _k + 1));
		recover();
		done:;
	}
	return 0;
}

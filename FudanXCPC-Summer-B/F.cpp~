#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define ll long long int
#define ld long double
#define pb push_back
#define pc putchar
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define lowbit(x) (x & -x)
#define maxn 2020
#define maxm 20
#define maxb 
#define maxs 
#define M  
using namespace std;

int n, m, tim = 0;
struct ele{
	double p, q;
	ele(double p, double q) : p(p), q(q){}
	ele(){}
	bool operator < (const ele b)const{
		return p * b.q > q * b.p;
	}
}a[maxn];
 
int vis[maxn][maxm];
double dp[maxn][maxm];
double DP(int pos, int rest){
	if (pos > n || rest < 0) return 0;
	if (vis[pos][rest] == tim) return dp[pos][rest];
	vis[pos][rest] = tim;
	double& ans = dp[pos][rest];
	return ans = a[pos].p + (1 - a[pos].p - a[pos].q) * DP(pos + 1, rest) + a[pos].q * DP(pos + 1, rest - 1);
}

int main(){
	int T;
	scanf("%d", &T);
	rep(TT, 1, T){
		tim++;
		printf("Case %d: ", TT);
		scanf("%d%d", &n, &m);
		rep(i, 1, n) scanf("%lf%lf", &a[i].p, &a[i].q);
		sort(a + 1, a + 1 + n);
		printf("%.5lf\n", DP(1, m)); 
	} 
	return 0;
}

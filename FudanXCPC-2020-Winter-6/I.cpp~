#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int
#define maxn 4020
#define maxm 4000200
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define M 1000000007
#define mo(x) (x = (x >= M) ? (x - M) : x)
using namespace std;

int n, l;
struct edge{
	int next, to;
	edge(int next, int to) : next(next), to(to){}
	edge(){}
}e[maxm << 1];
int cnt = 1, h[maxn];
void Add_Edge(int x, int y){
	e[++cnt] = edge(h[y], x);
	h[y] = cnt;
}//reverse

int dp[maxn];
bool vis[maxn];
int DP(int x){
	if (x == 1) return 1;
	if (vis[x]) return dp[x];
	int& ans = dp[x];
	vis[x] = 1;
	erep(i, x){
		int op = e[i].to;
		ans += DP(op), mo(ans);
	}
	return ans;
}


bool dp2[maxn];
bool vis2[maxn];
bool DP2(int x){
	if (x == 1) return true;
	if (vis2[x]) return dp2[x];
	bool& ans = dp2[x];
	vis2[x] = 1;
	erep(i, x){
		int op = e[i].to;
		ans |= DP2(op);
	}
	return ans;
}

int main(){
	freopen("I.in", "r", stdin);
	int k, x;
	scanf("%d%d", &n, &l);
	rep(i, 1, l){
		scanf("%d", &k);
		rep(j, 1, k) scanf("%d", &x), Add_Edge(i, x);
	}
	ll ans = 0;
	int sum = 0;
	rep(i, l + 1, n){
		if (DP2(i)){
			sum++;
			ans += DP(i), mo(ans);
		}
	}
	printf("%lld %d\n", ans, sum);
	return 0;
}


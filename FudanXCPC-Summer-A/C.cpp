#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define maxn 90
#define maxm 
#define M 
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
using namespace std;

int num[maxn], sum[maxn];

bool vis[maxn][2];
int dp[maxn][2];
int DP(int pos, int op){	
	if (!op) return (1 << pos);
	if (!pos) return 1;
	if (vis[pos][op]) return dp[pos][op];
	vis[pos][op] = 1;
	int& ans = dp[pos][op];
	if (num[pos]) return ans = DP(pos - 1, 0) + DP(pos - 1, 1);
	else return ans = DP(pos - 1, 1);
}

bool vis2[maxn][2][maxn];
int dp2[maxn][2][maxn];
int DP2(int pos, int op, int gpos){
	if (pos == gpos) {
		if (op) {
			if (!num[pos]) return 0;
			else return DP(pos - 1, 1);
		}
		else return DP(pos, op) >> 1; 
	}
	if (vis2[pos][op][gpos]) return dp2[pos][op][gpos];
	vis2[pos][op][gpos] = 1;
	int& ans = dp2[pos][op][gpos];
	if (op){
		if (num[pos]) return ans = DP2(pos - 1, 1, gpos) + DP2(pos - 1, 0, gpos);
		else return ans = DP2(pos - 1, 1, gpos);
	}
	else return ans = 2 * DP2(pos - 1, 0, gpos);
}


int dep(int x){
	int n = 0;
	while (x){
		num[++n] = x & 1;
		x >>= 1;
	}
	return n;
}
void play(int x, int d){
	
	int n = dep(x); //cerr << DP(n, 1) << endl;
	rep(i, 1, n) sum[i] += d * DP2(n, 1, i); 
	rep(i, 0, n) rep(j, 0, 1) dp[i][j] = vis[i][j] = 0;
	rep(i, 0, n) rep(j, 0, 1) rep(k, 0, n) dp2[i][j][k] = vis2[i][j][k] = 0;
}

int main(){
	int a, b; 
	while (scanf("%d%d", &a, &b) == 2){ 
		if (a) play(a - 1, -1);
		//rep(i, 1, maxn) printf("%d ", sum[i]); printf("\n");
		play(b, 1);
		//rep(i, 1, maxn) printf("%d ", sum[i]); printf("\n");
		int pos = 0;
		ll res = 0;
		while (pos < maxn){
			res += (sum[pos] >> 1);
			if (pos < maxn - 1) sum[pos + 1] += (sum[pos] >> 1);
			pos++;
		}
		printf("%lld\n", res);
		srep(i, 0, maxn) sum[i] = 0;
	} 
	return 0;
}

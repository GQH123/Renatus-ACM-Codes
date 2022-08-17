#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 319
#define ll long long int 
#define M 1000000007
#define rank RANK
//#define DEBUG
using namespace std;

const ll inv2 = 500000004;

int n, k;
int a[maxn], b[maxn], rank[maxn];
ll ans1[maxn], ans2[maxn];
ll C[maxn][maxn], fac[maxn];
void initC(){
	fac[0] = 1;
	srep(i, 1, maxn) fac[i] = fac[i - 1] * i % M;
	C[0][0] = 1;
	srep(i, 1, maxn) {
		C[i][0] = 1; srep(j, 1, maxn) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % M;
	}
}

int iid;
bool viss[maxn][maxn];
ll sum[maxn][maxn];
ll SUM(int pos, int rest){
	if (pos < rest || !pos || !rest) return 0;
	if (viss[pos][rest]) return sum[pos][rest];
	viss[pos][rest] = 1;
	ll& ans = sum[pos][rest];
	if (pos == iid){
		ans = SUM(pos - 1, rest);
	}
	else {
		ans = (SUM(pos - 1, rest) + SUM(pos - 1, rest - 1)) % M;
		ans += b[pos] * ((pos > iid) ? C[pos - 2][rest - 1] : C[pos - 1][rest - 1]) % M, ans %= M;	
		//printf("%d %d\n", pos, rest);
	}
	return ans;
}

/*bool vis[maxn][maxn][maxn];
ll dp[maxn][maxn][maxn];
ll DP(int pos, int id, int num){
	if (!pos) {
		if (!num) return 1;
		else return 0;
	}
	if (vis[pos][id][num]) return dp[pos][id][num];
	vis[pos][id][num] = 1;
	ll& ans = dp[pos][id][num];
	if (num){
		ans = C[n - id - num + 1][1] * pos % M * DP(pos - 1, id, num - 1) % M;
	 	ans += C[id - 1 - (pos - 1 - num)][1] * pos % M * DP(pos - 1, id, num) % M;
	 	ans %= M;
	}
	else {
		ans = C[id - 1 - (pos - 1 - num)][1] * pos % M * DP(pos - 1, id, num) % M;
	}
	return ans;
}*/


int main(){
	//#ifndef ONLINE_JUDGE
	//	freopen("H.in", "r", stdin);
	//#endif
	initC();
	scanf("%d%d", &n, &k);
	rep(i, 1, n) scanf("%d", &a[i]), b[i] = a[i];
	sort(b + 1, b + 1 + n);
	rep(i, 1, n) rank[i] = lower_bound(b + 1, b + 1 + n, a[i]) - b;
	rep(id, 1, n - k + 1){
		srep(i, 0, maxn) srep(j, 0, maxn) viss[i][j] = sum[i][j] = 0;
		rep(pos, k, n){ 
			/*ans1[id] = C[n - id][k - 1] * ((k > 1) ? C[pos - 1][k - 2] : 1) % M * fac[k - 1] % M * C[pos - k + 1][1] % M * fac[pos - k] % M * SUM(id - 1, pos - k) % M;
				
			rep(rankk, k + 1, pos){
				ans1[id] = C[n - id][rankk - 1] * C[pos - 1][rankk - 1] % M * fac[rankk - 1] % M * fac[pos - rankk] % M * SUM(rankk - 1, pos - rankk) % M;
			}
			*/
			
			/*rep(bigger_num, k - 1, pos - 1){
				ans1[id] += C[n - id][bigger_num] * C[pos - 1][bigger_num] % M * fac[bigger_num] % M * C[id - 1][pos - 1 - bigger_num] % M * fac[pos - 1 - bigger_num] % M;
				ans1[id] %= M;
			}*/
			iid = id;
			if (k > 1){
			
				rep(bound, id + 1, n - k + 2){
					ans1[id] += ((k > 1) ? C[n - bound][k - 2] : 1) * C[pos - 1][k - 1] % M * fac[k - 1] % M * fac[pos - k] % M * SUM(bound - 1, pos - k) % M * fac[n - pos] % M;
					ans1[id] %= M;
				}
				
				
				ans1[id] += C[n - id][k - 1] * C[pos - 1][k - 2] % M * fac[k - 1] % M * C[pos - k + 1][1] % M * fac[pos - k] % M * SUM(id - 1, pos - k) % M * fac[n - pos] % M;
				ans1[id] %= M;
			}
			else {
				ll pre = 0;
				rep(i, 1, n) pre += b[i], pre %= M;
				pre += M - b[id], pre %= M;
				ans1[id] = pre * fac[n] % M * inv2 % M;
			}
		}
		ans1[id] += fac[n] * b[id] % M, ans1[id] %= M;
	}
	ll pre = 0;
	rep(i, 1, n - k + 1) pre += b[i], pre %= M;
	rep(id, n - k + 2, n){
		pre += b[id], pre %= M;
		ans1[id] = fac[n] * pre % M;
	}
	
	#ifdef DEBUG
		rep(i, 1, n){
			printf("%lld ", ans1[rank[i]]);
		} printf("\n");
	#endif
	
	rep(id, 1, n){
		rep(pos, 1, n){
			rep(num, k, min(pos - 1, n - id)) {
				ans2[id] += C[n - id][num] * C[pos - 1][num] % M * fac[num] % M * C[id - 1][pos - 1 - num] % M * fac[pos - 1 - num] % M * fac[n - pos] % M * (num - k + 1) % M;
				//ans2[id] += DP(pos - 1, id, num) * (num - k + 1) % M;
				ans2[id] %= M;
			}
		}
	}
	
	#ifdef DEBUG
		rep(i, 1, n){
			printf("%lld ", ans2[rank[i]]);
		} printf("\n");
	#endif
	
	printf("%lld", ans1[rank[1]] * ans2[rank[1]] % M);
	rep(i, 2, n){
		printf(" %lld", ans1[rank[i]] * ans2[rank[i]] % M);
	}
	return 0;
}

#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
#define lowbit(x) (x & -x) 
#define maxn 320
using namespace std;

char s[maxn];
int n, m, k;
int blo[maxn];


int v[maxn][2];
int dp[maxn][2];
bool vis[maxn][2];
int DP(int pos, bool op){
	if (pos == k + 1) return 0;
	if (vis[pos][op]) return dp[pos][op];
	int& ans = dp[pos][op];
	vis[pos][op] = 1; 
	if (pos == 1) ans = min(DP(pos + 1, 0) + v[pos][0], DP(pos + 1, 1) + v[pos][1] + 1);
	else {
		if (op) ans = min(DP(pos + 1, 0) + v[pos][0], DP(pos + 1, 1) + v[pos][1]); 
		else ans = min(DP(pos + 1, 0) + v[pos][0], DP(pos + 1, 1) + v[pos][1] + 2); 
	} 
	return ans;
}
void recoverdp(){
	rep(i, 1, k) rep(j, 0, 1) dp[i][j] = vis[i][j] = 0;
}

int num[maxn][2];


int main(){
	
		freopen("B.in", "r", stdin);
		
	scanf("%s", s + 1);
	n = strlen(s + 1);
	scanf("%d", &m);
	k = (n - 1) / m + 1;
	rep(i, 1, n) blo[i] = (i - 1) / m + 1;
	if (m < sqrt(n)){ 
		int ans = n + 1;//tot = 0;
		srep(op, 0, (1 << m)){
			//tot = 0;
			for (register int i = 1; i <= n; i += m){
				v[blo[i]][0] = 0, v[blo[i]][1] = 0;
				srep(j, i, i + m){
					if (j > n) break;
					if ((s[j] - '0') ^ ((op >> (j - i)) & 1)) v[blo[i]][0]++;
					else v[blo[i]][1]++;
				}
				//tot += min(v[blo[i]][0], v[blo[i]][1]);
			}
			//ans = min(ans, tot);
			ans = min(ans, DP(1, 0));
			recoverdp();
		}
		printf("%d\n", ans);
	}
	else {
		//ans = n + 1; int tot = 0;
		int ans = n + 1, tot = 0;
		srep(op, 0, (1 << k)){
			tot = 0;
			bool las = 0;
			srep(i, 0, k){
				if (!i) {
					if ((op >> i) & 1) las = 1, tot += 1;
					else las = 0;
				}
				else {
					if (las){	
						if ((op >> i) & 1) las = 1;
						else las = 0;
					}
					else {
						if ((op >> i) & 1) las = 1, tot += 2;
						else las = 0;
					}
				}
			}
			rep(i, 1, m){
				num[i][0] = num[i][1] = 0;
				for (register int j = i; j <= n; j += m){
					if ((op >> (blo[j] - 1)) & 1) num[i][(s[j] - '0') ^ 1]++;
					else num[i][s[j] - '0']++;
				}
				tot += min(num[i][0], num[i][1]);
			}
			ans = min(ans, tot);
		}
		printf("%d\n", ans);
	} 
	//assert(false);
	return 0;
}

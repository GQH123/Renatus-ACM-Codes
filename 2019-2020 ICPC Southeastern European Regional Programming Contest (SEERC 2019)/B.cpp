#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 505
#define DP(x, y, z) dp[d ^ 1][y][z]
#define ll long long int 
using namespace std;

int n, a[2][maxn], t[2][maxn], _s1, _s2;


inline void upd(ll& ans, ll res){
	ans = (ans == -1) ? res : min(ans, res);
}
/*
bool vis[maxn][maxn][maxn];
ll dp[maxn][maxn][maxn];
ll DP(int pos, int s1, int s2){ 
	if (!s1 && !s2) return 0;
	if (pos > n) return -1;
	if (vis[pos][s1][s2]) return dp[pos][s1][s2];
	vis[pos][s1][s2] = 1;
	ll& ans = dp[pos][s1][s2];
	ans = -1;
	if (s1){
		if (s1 < a[0][pos]) {
			ll res = DP(pos + 1, 0, max(0, s2 - (a[0][pos] - s1)));// + t[0][pos];
			if (res != -1) upd(ans, res + t[0][pos]);
		}
		else {
			ll res = DP(pos + 1, s1 - a[0][pos], s2);// + t[0][pos];
			if (res != -1) upd(ans, res + t[0][pos]);
		}
	}
	ll res = DP(pos + 1, s1, max(0, s2 - a[1][pos]));// + t[1][pos];
	if (res != -1) upd(ans, res + t[1][pos]);
	
	res = DP(pos + 1, s1, s2);
	if (res != -1) upd(ans, res);
	
	return ans;
}
*/

ll dp[2][maxn][maxn];
void _DP(){
	int d = 0;
	rep(s1, 0, _s1) rep(s2, 0, _s2) dp[d][s1][s2] = -1;
	dp[d][0][0]  = 0;
	per(pos, n, 1){
		d ^= 1;
		per(s1, _s1, 0){
			per(s2, _s2, 0){
				ll& ans = dp[d][s1][s2];
				ans = -1;
				if (s1){
					if (s1 < a[0][pos]) {
						ll res = DP(pos + 1, 0, max(0, s2 - (a[0][pos] - s1)));// + t[0][pos];
						if (res != -1) upd(ans, res + t[0][pos]);
					}
					else {
						ll res = DP(pos + 1, s1 - a[0][pos], s2);// + t[0][pos];
						if (res != -1) upd(ans, res + t[0][pos]);
					}
				}
				ll res = DP(pos + 1, s1, max(0, s2 - a[1][pos]));// + t[1][pos];
				if (res != -1) upd(ans, res + t[1][pos]);
				
				res = DP(pos + 1, s1, s2);
				if (res != -1) upd(ans, res);
			}
		} 
	}
	printf("%lld", dp[d][_s1][_s2]);
}



struct ele{
	int a1, a2, t1, t2;
	ele(int a1, int a2, int t1, int t2) : a1(a1), a2(a2), t1(t1), t2(t2){}
	ele(){}
	bool operator < (const ele b) const{
		return a1 < b.a1;
	}
}p[maxn];


int main(){
	scanf("%d%d%d", &n, &_s1, &_s2);
	rep(i, 1, n) scanf("%d%d%d%d", &p[i].a1, &p[i].t1, &p[i].a2, &p[i].t2);
	sort(p + 1, p + 1 + n);
	rep(i, 1, n) a[0][i] = p[i].a1, a[1][i] = p[i].a2, t[0][i] = p[i].t1, t[1][i] = p[i].t2;
	_DP();
	//printf("%lld", DP(1, s1, s2));
	return 0;
}

#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ll long long int 
#define ld long double
#define lowbit(x) (x & -x)
#define mo(x) (x = (x >= M) ? (x - M) : x)
#define M 
#define B
#define maxn 1020
#define maxs
#define maxm 
#define maxk
#define maxb
//#define DEBUG
using namespace std;

const int inf = 2000000000;

int n, c0, c1, vp, vs;
int p1[maxn], p0[maxn], s1[maxn], s0[maxn];
int sl[maxn], sr[maxn], pl[maxn], pr[maxn];
char s[maxn], t[maxn];

namespace D1{
	bool vis[maxn][maxn];
	int dp[maxn][maxn];
	int DP(int pos, int ss1){
		if (pos > n) {
			if (!ss1) return 0;
			else return -inf;
		}
		if (vis[pos][ss1]) return dp[pos][ss1];
		vis[pos][ss1] = 1;
		int& ans = dp[pos][ss1];
		
		if (t[pos] == '1'){
			int pp1 = c1 - ss1 + 1;
			if (!(pl[pos] <= pp1 && pp1 <= pr[pos] && sl[pos] <= ss1 && ss1 <= sr[pos])) return ans = -inf;
			int v = 0;
			if (pp1 == p1[pos]) v += vp;
			if (ss1 == s1[pos]) v += vs;
			return ans = v + DP(pos + 1, ss1 - 1);
		}
		else if (t[pos] == '0'){
			int pp1 = c1 - ss1;
			if (!(pl[pos] <= pp1 && pp1 <= pr[pos] && sl[pos] <= ss1 && ss1 <= sr[pos])) return ans = -inf;
			int v = 0;
			if (pp1 == p1[pos]) v += vp;
			if (ss1 == s1[pos]) v += vs;
			return ans = v + DP(pos + 1, ss1);
		}
		else {
			int pp1 = c1 - ss1 + 1, ans1 = -inf, ans2 = -inf;
			if (pl[pos] <= pp1 && pp1 <= pr[pos] && sl[pos] <= ss1 && ss1 <= sr[pos]) {
				int v = 0;
				if (pp1 == p1[pos]) v += vp;
				if (ss1 == s1[pos]) v += vs;
				ans1 = v + DP(pos + 1, ss1 - 1);
			}
			
			pp1 = c1 - ss1;
			if (pl[pos] <= pp1 && pp1 <= pr[pos] && sl[pos] <= ss1 && ss1 <= sr[pos]) {
				int v = 0;
				if (pp1 == p1[pos]) v += vp;
				if (ss1 == s1[pos]) v += vs;
				ans2 = v + DP(pos + 1, ss1); 
			}
			return ans = max(ans1, ans2);
		}
	}
}

namespace D2{
	bool vis[maxn][maxn];
	int dp[maxn][maxn];
	int DP(int pos, int ss1){
		if (pos > n) {
			if (!ss1) return 0;
			else return inf;
		}
		if (vis[pos][ss1]) return dp[pos][ss1];
		vis[pos][ss1] = 1;
		int& ans = dp[pos][ss1];
		
		if (t[pos] == '1'){
			int pp1 = c1 - ss1 + 1;
			if (!(pl[pos] <= pp1 && pp1 <= pr[pos] && sl[pos] <= ss1 && ss1 <= sr[pos])) return ans = inf;
			int v = 0;
			if (pp1 == p1[pos]) v += vp;
			if (ss1 == s1[pos]) v += vs;
			return ans = v + DP(pos + 1, ss1 - 1);
		}
		else if (t[pos] == '0'){
			int pp1 = c1 - ss1;
			if (!(pl[pos] <= pp1 && pp1 <= pr[pos] && sl[pos] <= ss1 && ss1 <= sr[pos])) return ans = inf;
			int v = 0;
			if (pp1 == p1[pos]) v += vp;
			if (ss1 == s1[pos]) v += vs;
			return ans = v + DP(pos + 1, ss1);
		}
		else {
			int pp1 = c1 - ss1 + 1, ans1 = inf, ans2 = inf;
			if (pl[pos] <= pp1 && pp1 <= pr[pos] && sl[pos] <= ss1 && ss1 <= sr[pos]) {
				int v = 0;
				if (pp1 == p1[pos]) v += vp;
				if (ss1 == s1[pos]) v += vs;
				ans1 = v + DP(pos + 1, ss1 - 1);
			}
			
			pp1 = c1 - ss1;
			if (pl[pos] <= pp1 && pp1 <= pr[pos] && sl[pos] <= ss1 && ss1 <= sr[pos]) {
				int v = 0;
				if (pp1 == p1[pos]) v += vp;
				if (ss1 == s1[pos]) v += vs;
				ans2 = v + DP(pos + 1, ss1); 
			}
			return ans = min(ans1, ans2);
		}
	}
}

int main(){
	scanf("%d%d%d%d%d", &n, &c0, &c1, &vp, &vs);
	scanf("%s", s + 1);
	rep(i, 1, n){
		p0[i] = p0[i - 1], p1[i] = p1[i - 1];
		if (s[i] == '0') p0[i]++;
		else p1[i]++;
	}
	per(i, n, 1){	
		s0[i] = s0[i + 1], s1[i] = s1[i + 1];
		if (s[i] == '0') s0[i]++;
		else s1[i]++;
	}
	scanf("%s", t + 1);
	int _n0 = 0, _n1 = 0, _n2 = 0;
	rep(i, 1, n) {
		if (t[i] == '0') _n0++;
		else if (t[i] == '1') _n1++;
		else _n2++;
	}
	int _t0 = c0 - _n0, _t1 = c1 - _n1;
	int n0 = 0, n1 = 0, n2 = 0;
	per(i, n, 1){
		if (t[i] == '0') n0++;
		else if (t[i] == '1') n1++;
		else n2++;
		sl[i] = n1 + max(0, n2 - _t0), sr[i] = n1 + min(n2, _t1);
	}
	n0 = n1 = n2 = 0;
	rep(i, 1, n){
		if (t[i] == '0') n0++;
		else if (t[i] == '1') n1++;
		else n2++;
		pl[i] = n1 + max(0, n2 - _t0), pr[i] = n1 + min(n2, _t1);
	}
	//printf("%d \n", D1 :: DP(1, c1));
	printf("%d %d\n", D2 :: DP(1, c1), D1 :: DP(1, c1));
	return 0;
}

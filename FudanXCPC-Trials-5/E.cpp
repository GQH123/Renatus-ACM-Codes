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
#define maxn 30
#define maxm
using namespace std;

int n, a[maxn], p[maxn], bound;

bool vis[maxn >> 1][maxn][1 << (maxn >> 1)];
ll dp[maxn >> 1][maxn][1 << (maxn >> 1)];
extern ll DP(int x, int suf, int s);

inline bool judge(int a, int b) {
	return (a << 1) <= b || (b << 1) <= a;
}
inline bool judge_pos(int x, int pos, int& left, int& right) {
	if (a[(pos << 1) - 1]) {
		if (!judge(x, a[(pos << 1) - 1])) return false;
		else left = 0;
	}
	if (a[(pos << 1) + 1]) {
		if (!judge(x, a[(pos << 1) + 1])) return false;
		else right = 0;
	}
	return true;
}
inline ll cal(int n, int m) {
	if (!m) return 1;
	if (m == 1) return n;
	if (m == 2) return 1ll * n * (n - 1);
	assert(false);
}
inline ll play(int x, int suf, int s, int pos){	
	int left = 1, right = 1;
	if (!judge_pos(x, pos, left, right)) return 0;
	if (pos > 1 && (s & (1 << (pos - 2)))) left = 0;
	if (pos < bound - 1 && (s & (1 << pos))) right = 0;
	int num = left + right;
	if (suf < num) return 0;
	return cal(suf, num) * DP(x - 1, suf - num, s ^ (1 << (pos - 1)));
	
}
ll DP(int x, int suf, int s){
	if (!x) return 1;
	if (vis[x][suf][s]) return dp[x][suf][s];
	vis[x][suf][s] = 1;
	ll& ans = dp[x][suf][s]; ans = 0;
	
	if ((x << 1) >= bound && !p[x << 1]) suf++;
	if ((x << 1 | 1) >= bound && !p[x << 1 | 1]) suf++;
	
	if (p[x]) {
		if (s & (1 << (p[x] - 1))) return 0;
		else ans += play(x, suf, s, p[x]);
	} 
	else srep(i, 1, bound) {
		if (!(s & (1 << (i - 1)))) 
			ans += play(x, suf, s, i); 
	}
	
	return ans;
}
int main(){
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", a + i), p[a[i]] = i;
	bound = (n + 1) >> 1;
	rep(i, 1, n) {
		if (a[i]) {	
			if (a[i] < bound) {
				printf("0\n");
				return 0;
			}
		}
		i++;
	}
	rep(i, 2, n) {
		if (a[i]) {
			if (a[i] >= bound) {
				printf("0\n");
				return 0;
			}
		}
		i++;
	}
	rep(i, 1, bound - 1) {
		if (p[i]) p[i] >>= 1;
	}
	printf("%lld\n", DP(bound - 1, 0, 0));
	
	return 0;
}

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
#define maxm
using namespace std;

int n;
/*
int dp[maxn][maxn][1 << maxn];
bool vis[maxn][maxn][1 << maxn];
*/

struct ele{
	int pos, last, s;
	ele(int pos, int last, int s) : pos(pos), last(last), s(s){}
	ele(){}
	bool operator < (const ele& b) const{	
		return pos == b.pos ? last == b.last ? s < b.s : last < b.last : pos < b.pos;
	}
};
map<ele, int> dp;
int dfs(int pos, int last, int s){
	if (pos == n + 1) return 1;
	if (dp.count(ele(pos, last, s))) return dp[ele(pos, last, s)];
	int ans = 0;
	rep(i, 1, n) {
		if (s & (1 << (i - 1))) {
			if (last == -1 || (last << 1) <= i || (i << 1) <= last) {
				ans += dfs(pos + 1, i, s ^ (1 << (i - 1)));
			}
		}
	}
	dp[ele(pos, last, s)] = ans;
	return ans;
}
int main(){
	cin >> n; 
	cout << n << " : " << dfs(1, -1, (1 << n) - 1) << endl;
	return 0;
}

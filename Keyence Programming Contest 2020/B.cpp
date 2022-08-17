#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 200020
#define ll long long int 
using namespace std;

int n;

struct ele{
	int id, l, r;
	ele(int id, int l, int r) : id(id), l(l), r(r){}
	ele(){}
	bool operator < (const ele b) const{
		return (l == b.l) ? ((r == b.r) ? (id < b.id) : r < b.r) : l < b.l;
	}
}p[maxn];

bool vis[maxn];
int dp[maxn];
int DP(int pos){
	if (pos == n + 1) return 0;
	if (vis[pos]) return dp[pos];
	vis[pos] = 1;
	int& ans = dp[pos];
	return ans = max(DP(pos + 1), 1 + DP(lower_bound(p + 1, p + 1 + n, ele(-1, p[pos].r, p[pos].r)) - p));
}

int main(){
	
		//freopen("B.in", "r", stdin);
		
	int x, y;
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d%d", &x, &y), p[i] = ele(i, x - y, x + y);
	sort(p + 1, p + 1 + n);
	printf("%d", DP(1));
	return 0;
}

#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define maxr 100000
#define maxn 3020
#define maxm
#define M 1000000007
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define mo(x) (x = (x >= M) ? (x - M) : x)
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}

int n, e, k;
bool no[maxn][maxn];

bool vis[maxn][maxn];
int dp[maxn][maxn];
int DP(int pos, int op){ // 0000000000 <-back front->
	if (pos == n + 1) return 1;
	if (vis[pos][op]) return dp[pos][op];
	vis[pos][op] = 1;
	int& ans = dp[pos][op];
	if ((op & 1) && (op & 2)) return ans = DP(pos + 1, op >> 2);
	if (op & 1){ //second line go!
		int d = min(n - pos, e);
		rep(i, 1, d){
			if (!(op & (1 << (2 * i))) && !no[pos + i][pos]){
				ans += DP(pos + 1, (op | (1 << (2 * i))) >> 2), mo(ans);
			}
		}
	}
	else if (op & 2){ //first line go!
		int d = min(n - pos, e);
		rep(i, 1, d){
			if (!(op & (1 << (2 * i + 1))) && !no[pos][pos + i]){
				ans += DP(pos + 1, (op | (1 << (2 * i + 1))) >> 2), mo(ans);
			}
		}
	}
	else {
		if (!no[pos][pos]) ans += DP(pos + 1, op >> 2), mo(ans);
		int d = min(n - pos, e);
		rep(i, 1, d){//first line
			if (!(op & (1 << (2 * i + 1))) && !no[pos][pos + i]){
				rep(j, 1, d){
					if (!(op & (1 << (2 * j))) && !no[pos + j][pos]){
						ans += DP(pos + 1, (op | (1 << (2 * j)) | (1 << (2 * i + 1))) >> 2), mo(ans);
					}
				}
			}
		}
	}
	return ans;
}

int main(){
	
		#ifndef ONLINE_JUDGE
			freopen("F.in", "r", stdin);
		#endif
	
	scanf("%d%d%d", &n, &e, &k);
	int x, y;
	rep(i, 1, k){
		scanf("%d%d", &x, &y);
		no[x][y] = 1;
	}
	printf("%d", DP(1, 0));
	return 0;
}

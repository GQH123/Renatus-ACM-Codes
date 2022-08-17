#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 35
#define maxm 10
using namespace std;

const int inf = 1000000020;

int n, m;
char g[maxn][maxm];
int row[maxn * maxm], col[maxn * maxm];
bool vis[maxn * maxm][10020]; //3**8 = 6561
int dp[maxn * maxm][10020];
int con = 1;
int DP(int x, int op){	//0 no water, 1 have water, 2 poor sugar...
	if (x == n * m + 1) {
		while (op){
			if (op % 3 == 2) return -inf;
			op /= 3;
		}
		return 0;
	}
	if (vis[x][op]) return dp[x][op];
	vis[x][op] = 1;
	int& ans = dp[x][op];
	int left = (col[x] == 1) ? 0 : (op / con), up = op % 3;
	if (g[row[x]][col[x]] == '#') {
		if (up == 2) return ans = -inf;
		return ans = DP(x + 1, op / 3);
	}
	else {
		if (up == 2) { // must be water 
			if (left == 2) return ans = DP(x + 1, (op - 2 * con) / 3 + con);
			else return ans = DP(x + 1, op / 3 + con); 
		}
		int res = -inf, _op = op;
		if (left == 2) _op -= 2 * con;
		res = max(res, DP(x + 1, _op / 3 + con));
		// could be water
		_op = op;
		if (left == 1 || up == 1) res = max(res, DP(x + 1, _op / 3) + 1);
		else res = max(res, DP(x + 1, _op / 3 + 2 * con) + 1);
		// sugar
		_op = op;
		res = max(res, DP(x + 1, _op / 3));
		// no sugar
		return ans = res;
	}
}


char out[maxn][maxm];
void FA(int x, int op){	//O water, X sugar, . sand, # rock
	if (x == n * m + 1) return; 
	const int ans = dp[x][op];
	int left = (col[x] == 1) ? 0 : op / con, up = op % 3;
	int xx = row[x], yy = col[x];
	if (g[xx][yy] == '#') {
		if (up == 2) return;
		out[xx][yy] = '#', FA(x + 1, op / 3); 
		return;
	}
	else {
		if (up == 2) { // must be water 
			out[xx][yy] = 'O';
			if (left == 2) {FA(x + 1, (op - 2 * con) / 3 + con); return;}
			else {FA(x + 1, op / 3 + con); return;}
		}
		int _op = op;
		if (left == 2) _op -= 2 * con;
		if (ans == DP(x + 1, _op / 3 + con)) {
			out[xx][yy] = 'O';
			FA(x + 1, _op / 3 + con);
			return;
		}
		// could be water
		_op = op;
		if (left == 1 || up == 1) {
			if (ans == DP(x + 1, _op / 3) + 1){
				out[xx][yy] = 'X';
				FA(x + 1, _op / 3);
				return;
			}
		}
		else {
			if (ans == DP(x + 1, _op / 3 + 2 * con) + 1){
				out[xx][yy] = 'X';
				FA(x + 1, _op / 3 + 2 * con);
				return;
			}
		}
		// sugar
		_op = op;
		if (ans == DP(x + 1, _op / 3)){
			out[xx][yy] = '.';
			FA(x + 1, _op / 3);
			return;
		}
		// no sugar
		return;
	}
}


int main(){
	scanf("%d%d", &n, &m);
	rep(i, 1, n) scanf("%s", g[i] + 1); 
	rep(i, 1, n * m){
		row[i] = (i - 1) / m + 1;
		col[i] = (i - 1) % m + 1;
	}
	rep(i, 1, m - 1) con *= 3;
	//cerr << DP(1, 0) << endl;
	
	DP(1, 0);
	FA(1, 0);
	rep(i, 1, n) {rep(j, 1, m) printf("%c", out[i][j]); printf("\n");}
	//rep(i, 1, n) printf("%s\n", out[i] + 1); 
	
	return 0;
}

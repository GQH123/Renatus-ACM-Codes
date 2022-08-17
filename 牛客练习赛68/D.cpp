#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 502
#define M 998244353
#define mo(x) (x = (x >= M) ? (x - M) : x)
#define ll long long int 
using namespace std;

int n, aa, b, c, s, num[maxn]; ll k;


int a[maxn][maxn], ans[maxn][maxn], con[maxn][maxn], tt[maxn][maxn], dp[2][maxn];
void mul(int a[][maxn], int b[][maxn], int c[][maxn]){
	rep(i, 1, n) rep(j, 1, n) tt[i][j] = 0;
	rep(i, 1, 1) rep(j, 1, n) rep(k, 1, n) tt[i][j] += 1ll * a[i][k] * b[k][j] % M, mo(tt[i][j]);
	
	rep(i, 1, n) rep(j, 1, n) c[i][j] = tt[1][(j + n - i) % n + 1];
}
void muldp(){
	rep(j, 1, n) tt[1][j] = 0;
	rep(j, 1, n) rep(k, 1, n) tt[1][j] += 1ll * dp[1][k] * ans[k][j] % M, mo(tt[1][j]);
	rep(j, 1, n) dp[1][j] = tt[1][j];
}
void muldp2(){
	rep(j, 1, n) tt[1][j] = 0;
	rep(j, 1, n) rep(k, 1, n) tt[1][j] += 1ll * dp[1][k] * con[k][j] % M, mo(tt[1][j]);
	rep(j, 1, n) dp[1][j] = tt[1][j];
}
void power(ll y){
	//rep(i, 1, n) ans[i][i] = 1;
	rep(i, 1, n) rep(j, 1, n) con[i][j] = a[i][j];
	while (y){
		if (y & 1) muldp2();//mul(ans, con, ans);
		mul(con, con, con);
		y >>= 1;
	}
}
int power(int x, int y){
	int ans = 1, con = x;
	while (y){
		if (y & 1) ans = 1ll * ans * con % M;
		con = 1ll * con * con % M;
		y >>= 1;
	}
	return ans;
}
int getinv(int x) { return power(x, M - 2); }

int main(){ 
	scanf("%d%lld%d%d%d", &n, &k, &aa, &b, &c);
	s = aa + b + c; 
	int invs = getinv(s);
	int p1 = 1ll * aa * invs % M, p2 = 1ll * b * invs % M, p3 = 1ll * c * invs % M;
	rep(i, 1, n) scanf("%d", &dp[1][i]); 
	rep(j, 1, n) {
		a[j][j] = p3;
		if (j == 1) a[n][j] = p1; else a[j - 1][j] = p1;
		if (j == n) a[1][j] = p2; else a[j + 1][j] = p2;
	}
	//rep(i, 1, n) {rep(j, 1, n) printf("%d ", a[i][j]); printf("\n");} 
	power(k);
	//rep(i, 1, n) {rep(j, 1, n) printf("%d ", con[i][j]); printf("\n\n");}
	//muldp(); 
	rep(i, 1, n) printf("%d ", dp[1][i]); 
	return 0;
}

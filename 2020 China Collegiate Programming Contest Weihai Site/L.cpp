#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define ll long long int 
#define pb push_back
#define pc putchar
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn 30020
#define maxm
#define maxs 3500
#define maxb 30020
#define M 
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}
int _num[20];
template <class T> void write(T x, char sep = '\n'){	
	if (!x) {putchar('0'), putchar(sep); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar(sep);
}

int p[maxn], cp = 0;
bool vis[maxn];
void init(){
	srep(i, 2, maxn) {
		if (!vis[i]) p[++cp] = i;// lis[++cs] = i;
		rep(j, 1, cp) {
			if (i * p[j] >= maxn) break;
			vis[i * p[j]] = 1;
			if (i % p[j] == 0) break;
		}
	}
	/*
	rep(i, 1, cp) {
		int now = p[i];
		while (maxn / p[i] >= now) {
			now *= p[i];
			lis[++cs] = now;
		}
	}
	cerr << cs << endl;
	*/
}

/*
int vis[maxs][maxb], idx;
double dp[maxs][maxb];
double DP(int pos, int rest){
	if (pos == cs + 1) return 0;
	if (vis[pos][rest] == idx) return dp[pos][rest];
	vis[pos][rest] = idx;
	double& ans = dp[pos][rest]; ans = 0;
	int now = p[pos];
	if (rest >= now) ans = max(ans, DP(pos + 1, rest - now) + log(now));
	while (maxn / p[pos] >= now && (now *= p[pos], rest >= now)) ans = max(ans, DP(pos + 1, rest - now) + log(now)); 
	return ans;
}
*/

#define DP(x, y) dp[x][y]
#define type double
type dp[maxs][maxb];
void solve(){
	per(pos, cp, 1){
		type _co, co; _co = co = log(p[pos]);
		srep(rest, 0, maxb) {
			co = _co;
			type& ans = dp[pos][rest]; ans = 0;
			int now = p[pos]; 
			ans = max(ans, DP(pos + 1, rest));
			if (rest >= now) ans = max(ans, DP(pos + 1, rest - now) + co);
			while (rest / p[pos] >= now) now *= p[pos], co += _co, ans = max(ans, DP(pos + 1, rest - now) + co); 
		}
	}
}

int main(){
	//cerr << log(2) << ' ' << log(3) << endl;
	init(), solve();
	int T, b; read(T);
	while (T--){
		read(b);
		printf("%.10f\n", dp[1][b]);
		//if (T) printf("\n");
	}
	return 0;
}


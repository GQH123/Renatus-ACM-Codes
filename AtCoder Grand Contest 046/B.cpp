#include <bits/stdc++.h>
#define maxn 3020
#define maxm maxn * maxn
#define maxb
#define maxr 200000
#define maxs 
#define pii pair<int, int>
#define pdd pair<double, double>
#define uint unsigned int
#define ull unsigned long long int
#define ll long long int 
#define lowbit(x) x & -x
#define fi first
#define se second
#define pb push_back
#define next NEXT
#define hash HASH
#define ls ch[x][0]
#define rs ch[x][1]
#define pi 3.141592653589793
#define ei 2.718281828459045
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define M 998244353
#define mo(x) (x = (x >= M) ? (x - M) : x)
//#define ONLINE_JUDGE
//#define DEBUG
using namespace std;

char *p1, *p2, buffer[maxr];
template <class T> void read(T& x){
    char ch = gc(); x = 0; bool f = 1;
    while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
    if (ch == '-') f = 0, ch = gc();
    while ('0' <= ch && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = gc();
    x = f ? x : -x;
}

int a, b, c, d;

//int C[maxn][maxn], fac[maxn];
ll fac[maxm], ifac[maxm], inv[maxm];
void init(){
	fac[0] = ifac[0] = inv[1] = 1;
	srep(i, 1, maxm) fac[i] = fac[i - 1] * i % M;
	srep(i, 2, maxm) inv[i] = M - M / i * inv[M % i] % M;
	srep(i, 1, maxm) ifac[i] = ifac[i - 1] * inv[i] % M;
	/*
	C[0][0] = 1;
	srep(i, 1, maxn) {
		C[i][0] = 1;
		rep(j, 1, i) C[i][j] = C[i - 1][j] + C[i - 1][j - 1], mo(C[i][j]); 
	}
	fac[0] = 1;
	srep(i, 1, maxn) fac[i] = (ll)fac[i - 1] * i % M;
	*/
}
ll get(int m, int n){
	if (m < n) return 0;
	return fac[m] * ifac[n] % M * ifac[m - n] % M;
}

int power(int y, int x){
	int ans = 1, con = x;
	while (y){
		if (y & 1) ans = (ll)ans * con % M;
		con = (ll)con * con % M;
		y >>= 1;
	}
	return ans;
}


bool vis[maxn][maxn];
int dp[maxn][maxn];
int DP(int pos, int rest){
	if (pos > d - b) return power(rest, b);
	if (vis[pos][rest]) return dp[pos][rest];
	vis[pos][rest] = 1;
	int& ans = dp[pos][rest];
	rep(i, 1, c - a){
		if (i - 1 > rest) break;
		ans += get(rest, i - 1) * get(c - a, i) % M * fac[i - 1] % M * DP(pos + 1, rest - i + 1) % M;
		mo(ans);
	}  
	rep(i, 0, c - a){
		if (i > rest) break;
		ans += get(rest, i) * get(c - a, i) % M * fac[i] % M * a % M * DP(pos + 1, rest - i) % M;
		mo(ans);
	}  
	return ans;
}


ll cal(int i, int j, int c, int d){
	ll ans = 0, dd = 1;
	rep(l, 0, min(i, j)){
		ans += dd * get(i, l) % M * get(j, l) % M * fac[l] % M * power(j - l, d) % M * power(i - l, c) % M;
		mo(ans);
		dd = M - dd;
	}
	return ans;
}

int main(){ 
	init(); 
	scanf("%d%d%d%d", &a, &b, &c, &d);
	printf("%d", DP(1, c - a));
	ll ans = 0;//(ll)power(c - a, d) * power(d - b, c) % M; 
	/*
	int dd = 1, con = min(c - a, d - b);
	rep(i, 0, con){ 
		ans += (ll)dd * C[c - a][i] % M * C[d - b][i] % M * fac[i] % M * power(c - a - i, d) % M * power(d - b - i, c) % M;
		mo(ans);
		dd = M - dd;
	}
	*/
	/*
		rep(i, 0, c - a){ 
			rep(j, 0, d - b){
				int dd = ((i + j) & 1) ? (M - 1) : 1;
				ans += (ll)dd * C[c - a][i] % M * C[d - b][j] % M * fac[i] % M * power(c - a - i, d) % M * power(d - b - i, c) % M;
				mo(ans); 
			} 
		}
	*/
	/*
	int S = (c - a) * (d - b);
	rep(i, 0, c - a){
		rep(j, 0, d - b){
			//ans += (ll)power(c - a - i, b) * power(d - b - j, a) % M * get(c - a, i) % M * get(d - b, j) % M * cal(i, j, d - b, c - a) % M;
			ans += (ll)power(c - a - i, b) * power(d - b - j, a) % M * get(c - a, i) % M * get(d - b, j) % M * cal(i, j, d - b, c - a) % M;
			mo(ans);
		}
	}
	printf("%lld", ans);
	*/
    return 0;
}

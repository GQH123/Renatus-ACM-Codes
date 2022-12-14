#include <bits/stdc++.h>
#define maxr 100000
#define maxn 300019
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define P 998244353
#define M 1000000007
#define ll long long int 
#define mo(a, b) a = (a >= b) ? (a - b) : a
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}

int n;
struct edge{
	int next, to;
	edge(int next, int to) : next(next), to(to){}
	edge(){}
}e[maxn << 1];
int cnt = 1, h[maxn];
void Add_Edge(int x, int y){
	e[++cnt] = edge(h[x], y);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x);
	h[y] = cnt;
}

int fac[maxn], ifac[maxn], inv[maxn];
void init(){
	fac[0] = ifac[0] = inv[1] = 1;
	srep(i, 1, maxn) fac[i] = (ll)fac[i - 1] * i % P;
	srep(i, 2, maxn) inv[i] = P - P / i * (ll)inv[P % i] % P;
	srep(i, 1, maxn) ifac[i] = (ll)ifac[i - 1] * inv[i] % P;
}
int power(int x, int y, int m){
	int ans = 1, con = x;
	while (y){
		if (y & 1) ans = (ll)ans * con % m;
		con = (ll)con * con % m;
		y >>= 1;
	}
	return ans;
}
int getinv(int x, int m){	
	return power(x, m - 2, m);
}
int getC(int m, int n, int k){
	if (m < n) return 0;
	return (ll)fac[m] * ifac[n] % k * ifac[m - n] % k;
}
int siz[maxn], has[maxn], dp[maxn], lis[maxn], cs = 0;
map<int, int> save;
bool cmp(int i, int j){
    return (siz[i] == siz[j]) ? has[i] > has[j] : siz[i] > siz[j];
}
void DFS(int x, int fa){	
	siz[x] = 1;
	erep(i, x){
		int op = e[i].to;
		if (op == fa) continue;
		DFS(op, x);
		siz[x] += siz[op];
	}	
	save.clear();
	cs = 0;
	has[x] = 0;
	dp[x] = 1;
	erep(i, x){
		int op = e[i].to;
		if (op == fa) continue;
		lis[++cs] = op;
		int k = has[op];
		if (save.count(k)) save[k]++;
		else save[k] = 1;
	}
	sort(lis + 1, lis + 1 + cs, cmp);
	int sz = cs;
	rep(i, 1, cs){
		int op = lis[i], k = has[op];
		if (save[k]) {
			dp[x] = (ll)dp[x] * getC(sz, save[k], P) % P * power(dp[op], save[k], P) % P;
			sz -= save[k];
			save[k] = 0;
		}
		has[x] = (ll)has[x] * P % M + k, mo(has[x], M);
	}
	has[x] = (ll)has[x] * P % M + 1, mo(has[x], M);
	has[x] = (ll)has[x] * siz[x] % M;
}
set<int> root;
void recover(){
	root.clear();
	cnt = 1;
	rep(i, 1, n) h[i] = 0;
}
ll out[maxn], out2[maxn];
int main(){
	#ifndef ONLINE_JUDGE
		freopen("B.in", "r", stdin);
		freopen("B.ans", "w", stdout);
	#endif
	init();
	int T, x, y;
	read(T);
	while (T--){
		read(n);
		srep(i, 1, n) read(x), read(y), Add_Edge(x, y);
		ll ans = 0;
		rep(i, 1, n){
			DFS(i, i);
			out[i] = dp[i], out2[i] = has[i];
			if (!root.count(has[i])) root.insert(has[i]), ans += dp[i], mo(ans, P);
		}
		printf("%lld\n", ans);
		//rep(i, 1, n) printf("%lld ", out[i]); printf("\n");
		//rep(i, 1, n) printf("%lld ", out2[i]);
		recover();
	}
	return 0;
}

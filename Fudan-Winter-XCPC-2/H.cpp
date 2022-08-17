#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define pii pair<int, int>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define ll long long int 
#define pb push_back
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn 1020
#define maxm
#define maxs
#define maxb
#define M 
#define eps 1e-9
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
template <class T> void write(T x){	
	if (!x) {putchar('0'), putchar(' '); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar(' ');
}

int n, l, a[maxn], b[maxn];
double w, dp[maxn];
bool vis[maxn];
double DP(int pos){ 
	if (vis[pos]) return dp[pos];
	vis[pos] = 1;
	double& ans = dp[pos]; ans = 0;
	bool f = 1;
	rep(i, pos + 1, n){
		double dd = sqrt(abs(a[i] - a[pos] - l));
		if (f) ans = DP(i) + dd - w * b[i], f = 0;
		else ans = min(ans, DP(i) + dd - w * b[i]);
	}
	return ans;
}
bool equ(double a, double b){
	if (a - b > eps || b - a > eps) return false;
	return true;
}
int anss[maxn], cs = 0;
void find_ans(int pos){
	double ans = 0;
	bool f = 1;
	rep(i, pos + 1, n){
		double dd = sqrt(abs(a[i] - a[pos] - l));
		if (f) ans = DP(i) + dd - w * b[i], f = 0;
		else ans = min(ans, DP(i) + dd - w * b[i]);
		if (equ(ans, dp[pos])) {anss[++cs] = i, find_ans(i); return;}
	} 
}
bool judge(){
	rep(i, 0, n) vis[i] = 0, dp[i] = 0;
	double d = DP(0);  
	if (d < -eps) {cs = 0, find_ans(0); return true;}
	else return false;
}
double solve(double l, double r){
	int T = 100;
	while (T--){
		w = (r + l) / 2.0;
		if (judge()) r = w;
		else l = w;
	} 
	return l;
}

int main(){
	
		freopen("H.in", "r", stdin); 
		
	read(n), read(l);
	rep(i, 1, n) read(a[i]), read(b[i]);
	//printf("%lf\n", solve(0, 2000000000.0));
	solve(0, 2000000000.0);
	rep(i, 1, cs) write(anss[i]);
	return 0;
}


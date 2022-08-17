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
#define maxn 55
#define maxx 220
#define maxm
#define maxs
#define maxb
#define M  
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

const int inf = 2000000020;

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
	if (!x) {putchar('0'), putchar('\n'); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar('\n');
}

int n, x, y;
int vx[maxn], vy[maxn];

int ti;
int vis[maxn][maxx];
int dp[maxn][maxx];
int tag = 0;
int DP(int pos, int rest){ 
	if (pos == n + 1) {
		if (rest) return -inf;
		return 0;
	}
	if (vis[pos][rest] == tag) return dp[pos][rest];
	vis[pos][rest] = tag;
	int& ans = dp[pos][rest];
	ans = -inf;
	rep(i, 0, rest){
		if (i * vx[pos] > ti) break;
		ans = max(ans, DP(pos + 1, rest - i) + (ti - vx[pos] * i) / vy[pos]);
	}
	return ans;
}

bool judge(){
	tag++;
	return DP(1, x) >= y;
}

int solve(int l, int r){
	while (l < r){
		ti = ((r - l) >> 1) + l;
		if (judge()) r = ti;
		else l = ti + 1;
	}
	return l;
}

int main(){
	
		freopen("A.in", "r", stdin);
		
	//ios :: sync_with_stdio(false), cin.tie(0);
		
	int T;
	read(T);
	rep(TT, 1, T){
		printf("Case %d: ", TT);
		read(n), read(x), read(y);
		rep(i, 1, n) read(vx[i]), read(vy[i]);
		printf("%d\n", solve(1, 600020));
	}
	return 0;
}


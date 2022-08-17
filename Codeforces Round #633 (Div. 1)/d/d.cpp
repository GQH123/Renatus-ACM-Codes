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
#define maxn 200020
#define maxm
#define maxs
#define maxb
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
template <class T> void write(T x){	
	if (!x) {putchar('0'), putchar('\n'); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar('\n');
}

int n;
struct edge{
	int next, to;
	edge(int next, int to) : next(next), to(to){}
	edge(){}
}e[maxn << 1];
int cnt = 1, h[maxn], deg[maxn];
void Add_Edge(int x, int y){
	e[++cnt] = edge(h[x], y);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x);
	h[y] = cnt;
	deg[x]++, deg[y]++;
}

bool vis[maxn][2][2];
int dp[maxn][2][2];
int DP(int x, int fa, int op, int op2){
	if (vis[x][op][op2]) return dp[x][op][op2];
	vis[x][op][op2] = 1;
	int& ans = dp[x][op][op2];
	if (op){
		int mx1 = 0, mx2 = 0;
		erep(i, x){
			int y = e[i].to;
			if (y == fa) continue; 
			int d = DP(y, x, 0, op2);
			if(d > mx1) mx2 = mx1, mx1 = d;
			else if (d > mx2) mx2 = d;
		}
		return ans = mx1 + mx2;
	}
	else {
		if (op2){
			int mx1 = 0, mx2 = 0, sum = 0;
			erep(i, x){
				int y = e[i].to;
				if (y == fa) continue; 
				sum++;
				int d = max(DP(y, x, 0, 0), DP(y, x, 1, 0) + 1);
				if (d > mx1) mx2 = mx1, mx1 = d;
				else if (d > mx2) mx2 = d; 
			}
			ans = max(ans, mx1 + mx2 + sum - 2);
		}
		int mx = 0, sum = 0;
		erep(i, x){
			int y = e[i].to;
			if (y == fa) continue; 
			sum++;
			int d = max(DP(y, x, 0, op2), DP(y, x, 1, op2) + 1);
			mx = max(mx, d);
		}
		if (mx) sum--; 
		ans = max(ans, mx + sum);
		return ans;
	}
}


int main(){
	
		//freopen("d.in", "r", stdin);
	int x, y;
	read(n);
	srep(i, 1, n) read(x), read(y), Add_Edge(x, y);
	printf("%d\n", max(DP(1, -1, 0, 1), DP(1, -1, 1, 1) + 1)); 
	return 0;
}


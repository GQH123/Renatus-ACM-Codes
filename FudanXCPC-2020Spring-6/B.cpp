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
#define M 100000007
#define mo(x) (x = (x >= M) ? (x - M) : x)
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

int dp[maxn][maxn << 1][2];
bool vis[maxn][maxn << 1][2];
int DP(int pos, int rest, bool op){
	if (rest < 0) return 0;
	if (!pos) return rest == 0;
	if (vis[pos][rest][op]) return dp[pos][rest][op];
	vis[pos][rest][op] = 1;
	int& ans = dp[pos][rest][op];
	ans = ((ll)DP(pos - 1, rest - 2, 0) + DP(pos - 1, rest - 1, 1) + DP(pos - 1, rest - 1, 0) * 2) % M;
	if (op) ans += DP(pos - 1, rest, 1), mo(ans); 
	else ans = (ans + (ll)DP(pos - 1, rest, 0) + DP(pos - 1, rest, 1) * 2) % M; 
	return ans;
}

int n, k;

int main(){
	
		//freopen("B.in", "r", stdin);
	
	//ios :: sync_with_stdio(false), cin.tie(0);
	//IMPOSSIBLE, POSSIBLE
	
	int T;
	read(T);
	rep(TT, 1, T){
		read(n), read(k);
		printf("%d\n", (DP(n - 1, k - 2, 0) + DP(n - 1, k - 1, 1)) % M);
	}
	
	return 0;
}

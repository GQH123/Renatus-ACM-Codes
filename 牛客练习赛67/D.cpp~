#include <bits/stdc++.h>
#define maxn 200020
#define maxm
#define maxb
#define maxr 200000
#define maxs
#define M 
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

const int inf = 2000000000;

int n, a[maxn];

int dp[maxn][2];
bool vis[maxn][2];
int DP(int pos, bool f){
	if (!pos) return 0;
	if (vis[pos][f]) return dp[pos][f];
	vis[pos][f] = 1;
	int& ans = dp[pos][f];
	ans = inf;
	ans = min(ans, DP(pos - 1, f) + ((a[pos] ^ f) == 1));
	ans = min(ans, DP(pos - 1, f ^ 1) + 1 + ((a[pos] ^ f ^ 1) == 1));
	return ans;
}

int main(){
    read(n); rep(i, 1, n) read(a[i]);
	printf("%d", DP(n, 0));
    return 0;
}

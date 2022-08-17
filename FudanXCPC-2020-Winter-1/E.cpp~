#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int 
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first 
#define se second 
#define maxr 100019
#define maxn 2020
#define maxm
#define maxs 
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template<class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}

/*const int inf = 2000000020;

int n, k;
int a[maxn];
int mx[maxn][maxn];

int DP(int pos, int rest){
	if (pos == n + 1) {
		if (rest) return -inf;
		else return 0;
	}
	if (!rest) 
	if (vis[pos][rest]) return 
}*/

int n, k;
int a[maxn];

int main(){
	/*
		#ifndef ONLINE_JUDGE
			freopen("E.in", "r", stdin);
		#endif
	*/
	scanf("%d%d", &n, &k);
	rep(i, 1, n) scanf("%d", &a[i]);
	/*rep(i, 1, n){
		mx[i][i] = a[i];
		rep(j, i + 1, n) mx[i][j] = max(mx[i][j - 1], a[j]); 
	}
	printf("%d", DP(1, k));*/
	sort(a + 1, a + 1 + n);
	int ans = 0;
	per(i, n, n - k + 1) ans += a[i]; 
	printf("%d", ans);
	return 0;
}

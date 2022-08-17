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
#define maxn 200020
#define maxk 320
#define maxm
#define maxs
#define maxb 20
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

int mi[maxb][maxn], lo[maxn];
int get(int l, int r){
	int k = lo[r - l + 1];
	return min(mi[k][l], mi[k][r - (1 << k) + 1]);
}

int id[maxn], n, a[maxn], st, ed;
int lis[maxn], cs = 0;

/*
map<pii, ll> dp[maxn];
ll DP(int l, int r){
	if (l > r) return 0;
	int res = get(l, r);
	if (res < st || res > ed) {
		int x = a[res];
		return DP(l, x - 1) + DP(x + 1, r) + r - l + 1;
	}
	else {
		int lptr = lower_bound(lis + 1, lis + 1 + cs, l) - lis;
		int rptr = upper_bound(lis + 1, lis + 1 + cs, r) - lis - 1;
		rep(j, lptr, rptr){
			
		}
	}
}
*/

ll dp[maxk][maxk];
bool vis[maxk][maxk];
ll DP(int l, int r){
	if (l > r) return 0;
	int res = get(l, r);
	if (res < st || res > ed) {
		int x = a[res];
		return DP(l, x - 1) + DP(x + 1, r) + r - l + 1;
	}
	else {
		int lptr = lower_bound(lis + 1, lis + 1 + cs, l) - lis;
		int rptr = upper_bound(lis + 1, lis + 1 + cs, r) - lis - 1;
		if (vis[lptr][rptr]) return dp[lptr][rptr];
		vis[lptr][rptr] = 1;
		ll& ans = dp[lptr][rptr]; ans = -1;
		rep(j, lptr, rptr){
			int x = lis[j];
			ll d = DP(l, x - 1) + DP(x + 1, r);
			ans = (ans == -1) ? d : min(ans, d);
		}
		return ans += r - l + 1;
	}
}

int main(){
	read(n); rep(i, 1, n) read(a[i]), id[a[i]] = i; read(st), read(ed);
	rep(i, st, ed) lis[++cs] = a[i];
	sort(lis + 1, lis + 1 + cs);
	
	rep(i, 2, n) lo[i] = lo[i >> 1] + 1;
	rep(i, 1, n) mi[0][i] = id[i];
	srep(i, 1, maxb) { 
		rep(j, 1, n) {
			if (j + (1 << (i - 1)) > n) mi[i][j] = mi[i - 1][j];
			else mi[i][j] = min(mi[i - 1][j], mi[i - 1][j + (1 << (i - 1))]);
		}
	}
	//int now = -1; per(i, l - 1, 1) id[i] = now--;
	//now = 1; rep(i, r + 1, n) id[i] = now++;
	write(DP(1, n));
	return 0;
}


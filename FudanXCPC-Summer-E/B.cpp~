#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define maxn 2020
#define maxm 
#define M 
#define ll long long int 
#define ld long double
#define pb push_back
#define pc putchar
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define lowbit(x) (x & -x)
using namespace std;

int n, m, t, l;
int a[maxn], w[maxn];
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

inline void upd(int& x, int y, int z){
	if (y == -1) return;
	if (x == -1) x = y + z;
	else x = min(x, y + z);
}
int dp[maxn][maxn]; //dp[time][pos] when arrive
void DP(){
	rep(i, 0, t) rep(j, 1, n) dp[i][j] = -1;
	/*
	if (a[1] > t) {
		printf("It is a trap");
		return;
	}
	*/
	dp[0][1] = w[1];
	rep(i, 0, t){
		rep(j, 1, n){	
			if (i >= a[j]) upd(dp[i][j], dp[i - a[j]][j], w[j]);
			erep(k, j){
				int op = e[k].to;
				if (i >= a[op] + l) upd(dp[i][j], dp[i - a[op] - l][op], w[j]);
			}
		}
	}
	if (a[1] > t) {
		printf("It is a trap.");
		return;
	}
	else {
		if (dp[t - a[1]][1] == -1) printf("It is a trap.");
		else  printf("%d", dp[t - a[1]][1]);
	}
}

int main(){
	scanf("%d", &t);
	int x, y, z;
	scanf("%d%d%d", &n, &m, &l);
	rep(i, 1, m) scanf("%d%d", &x, &y), Add_Edge(x, y);
	rep(i, 1, n) scanf("%d%d", a + i, w + i);
	DP();
	return 0;
}

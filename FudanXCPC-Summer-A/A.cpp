#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define maxn 320
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

int n, m, a[maxn];
bool vis[maxn];
int main(){
	int x;
	while (scanf("%d", &n) == 1){
		rep(i, 1, n) scanf("%d", a + i);
		scanf("%d", &m);
		rep(i, 1, m) scanf("%d", &x), vis[x] = 1;
		int s0 = 0, s1 = 0, n0 = 0, n1 = 0;
		rep(i, 1, n) {
			if (!vis[i]) s0 += a[i], n0++;
			else s1 += a[i], n1++;
		}
		if (n1 == n) {
			if (!s1) printf("%.2lf\n", 0.0);
			else printf("inf\n");
		}
		else printf("%.2lf\n", 1.0 * s0 / (n - n1) + 1.0 * s1 * n0 / ((n - n1) * (n - n1))); 
		rep(i, 1, n) vis[i] = 0; 
	} 
	return 0;
}

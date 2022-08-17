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

int vis[maxn];
int main(){
	int x, n;
	while (scanf("%d", &n) == 1){
		int ans = -1;
		rep(i, 1, n + 1) {
			scanf("%d", &x), vis[x]++;
			if (vis[x] == 2) ans = x;
		}
		printf("%d\n", ans); 
		rep(i, 1, n) vis[i] = 0;
	}

	return 0;
}

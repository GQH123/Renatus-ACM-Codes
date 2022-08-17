#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int
#define maxn 2020
#define maxm 
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;

int n, k;
int a[maxn];
bool go[maxn];

int main(){
	freopen("M.in", "r", stdin);
	
	scanf("%d%d", &n, &k);
	rep(i, 1, n) scanf("%d", &a[i]);
	srep(i, 1, n) if (a[i + 1] - a[i] <= k) go[i] = 1; else go[i] = 0;
	int ans = 0;
	rep(i, 1, n){
		int sum = 1;
		while (i < n && go[i]) i++, sum++;
		ans = max(ans, sum);
	}
	printf("%d", ans);
	return 0;
}


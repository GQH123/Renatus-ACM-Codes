#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int
#define maxn 
#define maxm 
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back

using namespace std;

int main(){
	freopen("H.in", "r", stdin);
	
	int v, n;
	scanf("%d%d", &v, &n);
	for (register int d = 10; d <= 90; d += 10){
		printf("%lld ", ((ll)v * d * n - 1) / 100 + 1);
	}
	return 0;
}


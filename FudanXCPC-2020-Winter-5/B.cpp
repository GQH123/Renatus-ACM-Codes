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
	freopen("B.in", "r", stdin);
	int n, x, y;
	scanf("%d", &n);
	scanf("%d", &x);
	bool f = 1;
	rep(i, 2, n) {
		scanf("%d", &y);
		if (x < y) f = 0;
	}
	if (f) printf("S");
	else printf("N");
	return 0;
}


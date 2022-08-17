#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 
using namespace std;

int ans[10] = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1};

int f(int x){
	if (!x) return 1;
	int as = 0;
	while (x){
		as += ans[x % 10];
		x /= 10;
	}
	return as;
}

int main(){	
	#ifndef ONLINE_JUDGE
		freopen("M.in", "r", stdin);
	#endif
	int T, x, k;
	scanf("%d", &T);
	while (T--){
		scanf("%d%d", &x, &k);
		while (k && x) k--, x = f(x); 
		if (!x){
			if (k & 1) x = 1;
			else x = 0;
		}
		printf("%d\n", x);
	}
	return 0;
}



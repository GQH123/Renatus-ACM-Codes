#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define maxn
#define ll long long int 
#define ld lond double
#define pii pair<int, int>
#define fi first
#define se second
#define lowbit(x) (x & -x)
#define mo(x) (x = (x >= M) ? (x - M) : x)
using namespace std;

int main(){
	int a, b;
	scanf("%d%d", &a, &b);
	if (b == a + 1){
		printf("%d %d\n", a + 2, a + 1);
		rep(i, 1, a + 1) printf("%d %d\n", i, i + 1); 
	}
	else if (b > a + 1){
		if (!a) printf("-1\n");
		else {
			printf("%d %d\n", b + 1, b);
			rep(i, 1, a) printf("%d %d\n", i, i + 1);
			rep(i, 1, b - a) printf("%d %d\n", a + 1, a + 1 + i);
		} 
	}
	else if (b < a + 1){
		printf("%d %d\n", 2 * a - b + 3, 3 * a - 2 * b + 3);
		rep(i, 1, b) printf("%d %d\n", i, i + 1);
		int ct = b + 1;
		rep(i, 1, a - b + 1){
			printf("%d %d\n", ct, ct + 1);
			printf("%d %d\n", ct + 1, ct + 2);
			printf("%d %d\n", ct, ct + 2);
			ct += 2;
		}
	}
	return 0;
}

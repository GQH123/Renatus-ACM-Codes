#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define maxn
#define maxm
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int main(){
	
		freopen("C.in", "w", stdout);
		
	srand(time(NULL));
	int n;
	scanf("%d", &n); printf("%d\n", n);
	rep(i, 2, n) printf("%d %d\n", i, rand() % (i - 1) + 1); 
	rep(i, 1, n) printf("%d ", rand() % 1500000 + 1);
	return 0;
}

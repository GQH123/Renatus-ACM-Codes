#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define maxn 300020
#define maxm
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int lis[maxn];

int main(){
	
		freopen("B.in", "w", stdout);
		
	srand(time(NULL));
	int n = 250000;
	rep(i, 1, n) lis[i] = i;
	random_shuffle(lis + 1, lis + 1 + n);
		
	printf("%d\n", n);
	rep(i, 1, n) printf("%d ", lis[i]);
	return 0;
}

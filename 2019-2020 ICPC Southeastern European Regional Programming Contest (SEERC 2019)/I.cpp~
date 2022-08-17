#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 2020
using namespace std;

int n, a[maxn], b[maxn];

int main(){
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d",  a + i);
	rep(i, 1, n) scanf("%d",  b + i);
	int mx = 0;
	rep(i, 1, n){
		int mi = abs(a[i] - b[1]);
		rep(j, 2, n) mi = min(mi, abs(a[i] - b[j])); 
		mx = max(mx, mi);
	}
	printf("%d", mx);
	return 0;
}

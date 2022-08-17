#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define maxn 600020
using namespace std;

int n, a[maxn];

int main(){
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", a + i);
	sort(a + 1, a + 1 + n);
	rep(i, 1, n) printf("%d ",a[i]);
	return 0;
}

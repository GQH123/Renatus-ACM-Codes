#include <bits/stdc++.h>
#define maxn 
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define ll long long int 
using namespace std;

int n;
char a[maxn], b[maxn];
int tag[maxn];

int main(){
	#ifndef ONLINE_JUDGE
		freopen("B.in", "r", stdin);
	#endif
	scanf("%d", &n);
	scanf("%s%s", a + 1, b + 1);
	rep(i, 1, n) a[i] -= '0', s[i] = a[i], b[i] -= '0', t[i] = b[i]; 
	ll c = 0;
	rep(i, 1, n - 1){
		c += abs(a[i] - b[i]);
		tag[i] = b[i] - a[i];
		a[i + 1] += b[i] - a[i];
	}
	if (a[n] != b[n]) {
		printf("-1");
		return 0;
	}
	printf("%lld", c);
	return 0;
}

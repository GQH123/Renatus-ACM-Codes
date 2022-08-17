#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define pii pair<int, int>
#define fi first
#define se second
#define ll long long int 
#define mo(x) (x = (x >= M) ? (x - M) : x)
#define maxn
#define maxm
using namespace std;

int main(){
	int n, x;
	char s[10];
	scanf("%d", &n);
	int mx = 0;
	rep(i, 1, n){
		scanf("%s", s + 1);
		scanf("%d", &x);
		if (s[1] == 'S') mx = max(mx, x);
		if (s[1] == 'M') mx = max(mx, (1 << x) - 1);
	}
	printf("%d\n", mx);
	return 0;
}

#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int main(){ 
	int a, v, b, w, t;
	scanf("%d%d%d%d%d", &a, &v, &b, &w, &t);
	if (v <= w) printf("NO");
	else {
		if ((ll)t * (v - w) >= abs(a - b)) printf("YES");
		else printf("NO");
	}
	return 0;
}



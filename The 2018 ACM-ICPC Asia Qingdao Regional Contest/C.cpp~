#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 2000019
#define pii pair<int, int>
#define fi first
#define se second
#define ll long long int 
using namespace std;

int n;
int num[maxn];
char s[maxn], t[maxn];
int ct = 0;
pii lis[maxn];

int main(){	
	#ifndef ONLINE_JUDGE
		freopen("C.in", "r", stdin);
	#endif
	int T;
	scanf("%d", &T);
	while (T--){
		ct = 0;
		scanf("%d", &n);
		scanf("%s%s", s + 1, t + 1);
		rep(i, 1, n) num[i] = (s[i] - '0') ^ (t[i] - '0'); 
		rep(i, 1, n){
			int now = num[i], _i = i;
			while (i <= n && num[i] == now) i++; i--;
			lis[++ct] = pii(now, i - _i + 1);
		}
		int le1 = -1, le2 = -1;
		rep(i, 1, ct){
			if (lis[i].fi) {
				if (le1 == -1) le1 = lis[i].se;
				else if (le2 == -1) le2 = lis[i].se;
				else {
					printf("0\n");
					goto jump;
				}
			}
		}
		if (le1 == -1) printf("%lld\n", (ll)(n + 1) * n >> 1); 
		else if (le2 == -1) printf("%d\n", (n - le1 + le1 - 1) << 1);
		else printf("6\n");
		jump:;
	}
	return 0;
}



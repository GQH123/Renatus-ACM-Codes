#include <bits/stdc++.h>
#define maxb 60
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define ll long long int 
using namespace std;

ll x, y;

bool numx[maxb], numy[maxb];

void dep(bool* num, ll x){
	int l = 0;
	while (x){
		num[l] = (x & 1);
		x >>= 1;
		l++;
	}
}

int main(){
	int T;
	ll x, y;
	scanf("%d", &T);
	while (T--){
		scanf("%lld%lld", &x, &y);
		dep(numx, x), dep(numy, y);
		ll ans = 0;
		per(i, maxb - 1, 0){
			if (numx[i] && numy[i]) ans |= (1ll << i);
		}
		if (ans == 0) {
			srep(i, 0, maxb){
				if (numx[i] ^ numy[i]){
					ans |= (1ll << i);
					goto jump;
				}
			}
			ans++;
		}
		jump:printf("%lld\n", ans);
		srep(i, 0, maxb) numx[i] = numy[i] = 0;
	}
	return 0;
}

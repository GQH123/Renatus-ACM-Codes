#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 
#define maxm 
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define pc putchar
#define ll long long int 
#define ld long double 
#define lowbit(x) (x & -x)
#define M 
#define mo(x) (x = (x >= M) ? (x - M) : x)
using namespace std;

ll power(int x, int y){
	ll ans = 1, con = x;
	while (y){
		if (y & 1) ans = 1ll * ans * con;
		con = 1ll * con * con;
		y >>= 1;
	}
	return ans;
}
int main(){
	ll n;
	while (scanf("%lld", &n) == 1){
		int ans = 0, i = 1;
		while (i < 16){
			if (power(i, i) > n) break;
			ans++, i++;
		}
		printf("%d\n", ans);
	}
	return 0;
}

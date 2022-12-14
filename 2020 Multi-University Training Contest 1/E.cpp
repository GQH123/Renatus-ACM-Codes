#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define ll __int128
#define M 1000000009
using namespace std;

ll power(ll x, ll y){	
	ll ans = 1, con = x;
	while (y){
		if (y & 1) ans = ans * con;
		con = con * con;
		y >>= 1;
	}
	return ans;
}

void play(int k, int c, int n){
	ll a = 0, b = 1, now = 0, num = -1;
	ll ans = 0;
	while (num != n){
		if (now % c == 0) ans += power(a, k), num++;
		ll _b = b; b = a + b, a = _b;
		now++;
	}
	printf("Ans = %lld", ans);
}

int main(){
	int n = 100;
	rep(k, 1, 10){
		rep(c, 1, 10) {
			rep(n, 1, 10){
				printf("\n");
				printf("k = %d c = %d n = %d ", k, c, n);
				play(k, c, n);
				printf("\n");
			} 
		}
	}
	
	return 0;
}

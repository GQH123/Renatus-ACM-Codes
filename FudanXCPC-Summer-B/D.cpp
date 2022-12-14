#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define ll long long int
#define ld long double
#define pb push_back
#define pc putchar
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define lowbit(x) (x & -x)
#define maxn 65
#define maxm 65
#define maxb 
#define maxs 
#define M  
using namespace std;


int n, m, q;
ll be_con[maxn];
/*
ll con[maxn], sta[1 << 25];
map<ll, int> get;

void init(){
	srep(bit, 0, (1 << (m >> 1))){
		int k = lowbit(bit);
		get[
	}
}
*/

ll mat[maxn];
ll Gauss(ll b){
	rep(i, 1, n) {
		mat[i] = be_con[i];
		if (b & (1ll << i)) mat[i] += (1ll << (m + 1));
	}
	int now = 1;
	rep(i, 1, m){
		int f = -1;
		rep(j, now, n) if (mat[j] & (1ll << i)) {f = j; break;} 
		if (f == -1) continue;
		swap(mat[f], mat[now]);
		rep(j, 1, n) {
			if (j == now) continue;
			if (mat[j] & (1ll << i)) mat[j] ^= mat[now];
		}
		now++;
	}
	ll ans = 1; 
	rep(i, 1, n){
		ll x = mat[i];
		int bit = 0;
		while (x) {
			if (x & 1) bit++;
			x >>= 1;
		}
		int b_bit = (mat[i] & (1ll << (m + 1))) ? 1 : 0;
		bit -= b_bit; 
		if (!bit) {
			if (b_bit) return 0;
			else continue;
		} 
	}
	ans = ans * (1ll << (m - now + 1));
	return ans;
}

int main(){
	int T, k, x;
	scanf("%d", &T);
	rep(TT, 1, T){
		printf("Case %d:\n", TT);
		scanf("%d%d", &n, &m);
		rep(i, 1, n) be_con[i] = 0;
		rep(i, 1, m){ 
			scanf("%d", &k);
			rep(j, 1, k) scanf("%d", &x), be_con[x] |= (1ll << i);
		} 
		scanf("%d", &q);
		ll que = 0;
		rep(i, 1, q){
			que = 0;
			rep(j, 1, n) {
				scanf("%d", &x);
				if (x == 1) que |= (1ll << j);
			}  
			printf("%lld\n", Gauss(que));
		}
	}
	return 0;
}

#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 600020
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
#define seed 203112331
using namespace std;

int n, m;
ll ran[maxn];
ll v[maxn];
bool squ[maxn];
map<ll, int> find_;
int main(){

		freopen("D.in", "r", stdin);
		
	srand(seed);
	srep(i, 1, maxn) ran[i] = (ll)rand() * rand();
		
	int T, x, y;
	scanf("%d", &T);
	while (T--){
		scanf("%d%d", &n, &m);
		rep(i, 1, n) squ[i] = v[i] = 0;
		rep(i, 1, m) {
			scanf("%d%d", &x, &y);
			if (x == y) squ[x] = 1;
			else v[x] ^= ran[y], v[y] ^= ran[x];
		}
		ll ans = 0;
		rep(i, 1, n){
			if (squ[i]) continue;
			ans += find_[v[i]] + find_[v[i] ^ ran[i]];
			find_[v[i]]++, find_[v[i] ^ ran[i]]++;
		}
		find_.clear();
		rep(i, 1, n){
			if (!squ[i]) continue;
			ans += find_[v[i]] + find_[v[i] ^ ran[i]];
			find_[v[i]]++, find_[v[i] ^ ran[i]]++;
		}
		find_.clear();
		printf("%lld\n", ans);
	}
		
	return 0;
}

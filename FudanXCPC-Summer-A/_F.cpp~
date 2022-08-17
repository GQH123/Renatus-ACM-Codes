#include <bits/stdc++.h>
#define rep(i, l, r) for (register ll i = l; i <= r; i++)
#define per(i, r, l) for (register ll i = r; i >= l; i--)
#define srep(i, l, r) for (register ll i = l; i < r; i++)
#define sper(i, r, l) for (register ll i = r; i > l; i--)
#define maxn 24 
#define M 1000000007
#define mo(x) (x = (x >= M) ? (x - M) : x)
#define ll long long int
using namespace std;

ll C[maxn + 5][maxn + 5];
ll Seff[maxn][maxn + 2]; //1~n
ll power(ll x, ll y){
	ll ans = 1, con = x % M;
	while (y){
		if (y & 1) ans = 1ll * ans * con % M;
		con = 1ll * con * con % M;
		y >>= 1;
	}
	return ans;
}
ll getinv(ll x){
	return power(x % M, M - 2);
}
void init(){
	C[0][0] = 1;
	srep(i, 1, maxn + 5) {
		C[i][0] = 1;
		rep(j, 1, i) C[i][j] = C[i - 1][j] + C[i - 1][j - 1], mo(C[i][j]);
	}
	Seff[0][1] = 1;
	srep(k, 1, maxn) {
		rep(j, 0, k + 1) Seff[k][j] = C[k + 1][j];
		Seff[k][0] += M - 1, mo(Seff[k][0]);
		rep(j, 0, k - 1) rep(l, 0, j + 1) {
			Seff[k][l] += M - 1ll * C[k + 1][j] * Seff[j][l] % M, mo(Seff[k][l]);
		}
		ll inv = getinv(k + 1);
		rep(j, 0, k + 1) Seff[k][j] = 1ll * Seff[k][j] * inv % M;
	}
}
int stat = -1;
ll eff[maxn][maxn], _eff[maxn][maxn];
ll Ans(ll a, ll b, ll c, ll k, ll n){
	ll a1 = a / c, a2 = a - a1 * c, b1 = b / c, b2 = b - b1 * c;
	if (n <= 0) return 0;
	if (!a2 && !b2){
		stat = 1;
		ll res = 0;
		rep(k1, 0, k) rep(k2, 0, k) {
			if (k1 + k2 > k) continue;
			ll _k = k1 + k2;
			rep(_k1, k1, _k) rep(_k2, 0, k2) {
				if (_k1 + _k2 > _k || _k2) continue;
				ll preff = 1ll * C[k2][_k1 - k1] * C[k2 - _k1 + k1][_k2] % M * power(a1, _k1 - k1) % M * power(b1, k2 - _k1 + k1 - _k2) % M * eff[k1][k2] % M;
				ll nowx = 1, x = n % M;
				rep(j, 0, _k1 + 1) res += 1ll * preff * Seff[_k1][j] % M * nowx % M, mo(res), nowx = 1ll * x * nowx % M;
			}
		} 
		/*
		rep(k1, 0, k) rep(k2, 0, k) {
			if (k2) continue;
			rep(j, 0, k1 + 1) res += 1ll * eff[k1][k2] * Seff[k1][j] % M * power(n, j) % M, mo(res); 
		}
		*/
		return res;
	}
	if (!a2){
		stat = 2;
		ll res = 0;
		rep(k1, 0, k) rep(k2, 0, k) {
			if (k1 + k2 > k) continue;
			ll _k = k1 + k2;
			rep(_k1, k1, _k) rep(_k2, 0, k2) {
				if (_k1 + _k2 > _k) continue;
				ll preff = 1ll * C[k2][_k1 - k1] * C[k2 - _k1 + k1][_k2] % M * power(a1, _k1 - k1) % M * power(b1, k2 - _k1 + k1 - _k2) % M * eff[k1][k2] % M;
				ll nowx = 1, x = n % M;
				rep(j, 0, _k1 + 1) res += 1ll * preff * Seff[_k1][j] % M * nowx % M * power(b2 / c, _k2) % M, mo(res), nowx = 1ll * x * nowx % M;
			}
		} 
		/*
		rep(k1, 0, k) rep(k2, 0, k) { 
			rep(j, 0, k1 + 1) res += 1ll * eff[k1][k2] * Seff[k1][j] % M * power(n, j) % M * power(b2 / c, k2) % M, mo(res); 
		}
		*/
		return res;
	} 
	ll _a = c, _b = c - b2 - 1, _c = a2, _n = (1ll * a2 * n + b2) / c;
	srep(i, 0, maxn) srep(j, 0, maxn) _eff[i][j] = 0; ll res = 0;
	rep(k1, 0, k) rep(k2, 0, k) {
		if (k1 + k2 > k) continue;
		ll _k = k1 + k2;
		rep(_k1, k1, _k) rep(_k2, 0, k2) {
			if (_k1 + _k2 > _k) continue;
			ll preff = 1ll * C[k2][_k1 - k1] * C[k2 - _k1 + k1][_k2] % M * power(a1, _k1 - k1) % M * power(b1, k2 - _k1 + k1 - _k2) % M * eff[k1][k2] % M; 
			ll _pff = power(_n, _k2), _x = n % M, nowx = 1;
			rep(i, 0, _k1 + 1){
				res += 1ll * preff * _pff % M * Seff[_k1][i] % M * nowx % M;
				mo(res); nowx = 1ll * nowx * _x % M;
			} 
			
			/*
			if ((a2 + b2) / c == 0) {
				rep(i, 0, _k2 - 1) rep(j, 0, _k1 + 1){
					ll mideff = 1ll * (M - C[_k2][i]) * Seff[_k1][j] % M;
					//_eff[i][j] += 1ll * preff * mideff % M, mo(_eff[i][j]);
					res += 1ll * preff * mideff % M * power(0, i) % M * power(_b / _c, j) % M, mo(res);
				}
				
				_pff = power((a2 + b2) / c, _k2), _x = (1ll * c * ((a2 + b2) / c - 1) + _b) / a2, nowx = 1;
				rep(i, 0, _k1 + 1){
					res += M - 1ll * preff * _pff % M * Seff[_k1][i] % M * nowx % M;
					mo(res); nowx = 1ll * nowx * _x % M;
				} 
				
			}
			*/
			
			rep(i, 0, _k2 - 1) rep(j, 0, _k1 + 1){
				ll mideff = 1ll * (M - C[_k2][i]) * Seff[_k1][j] % M;
				_eff[i][j] += 1ll * preff * mideff % M, mo(_eff[i][j]);
			}
		}
	}
	rep(i, 0, k) rep(j, 0, k) eff[i][j] = _eff[i][j]; 
	if (_n && (1ll * a2 + b2) / c == 0) rep(i, 0, k) rep(j, 0, k) { 
		res += 1ll * power(0, i) * power(_b / _c, j) % M * eff[i][j] % M, mo(res);
	} 
	res += Ans(_a, _b, _c, k, _n - 1), mo(res);
	return res;
}

int main(){
	init();
	ll T, a, b, c, n, k1, k2;
	scanf("%lld", &T);
	while (T--){
		stat = -1;
		scanf("%lld%lld%lld%lld%lld%lld", &a, &b, &c, &n, &k1, &k2);
		srep(i, 0, maxn) srep(j, 0, maxn) eff[i][j] = 0;
		eff[k1][k2] = 1;
		if (!n) printf("0");
		else printf("%lld", (Ans(a, b, c, k1 + k2, n - 1) + 1ll * power(0, k1) * power(b / c, k2) % M) % M); 
		//if (stat == 1) cout << " S1 ";
		//if (stat == 2) cout << " S2 ";
		cout << endl;
	}
	return 0;
}

/*
2
2 0 1 3 1 1
52234124 45352 224244 1000000000 3 7

10
722837509
*/

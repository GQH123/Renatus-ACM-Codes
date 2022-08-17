#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--) 
#define ll long long int 
#define M 1000000007
#define mo(x) (x = (x >= M) ? (x - M) : x)
using namespace std;

int C[20][20];
void init_C(){
	C[0][0] = 1;
	srep(i, 1, 20){
		C[i][0] = 1;
		srep(j, 1, 20) C[i][j] = C[i - 1][j] + C[i - 1][j - 1], mo(C[i][j]);
	}
}
int power(int x, int y){
	int ans = 1, con = x;
	while (y){
		if (y & 1) ans = 1ll * ans * con % M;
		con = 1ll * con * con % M;
		y >>= 1;
	}
	return ans;
}
int getinv(int x){
	return power(x, M - 2);
}
typedef struct Polynomial{
	int n, num[21];
	void clear(){
		n = 0; memset(num, 0, sizeof(num));
	}
	Polynomial(){
		clear();
	}
	Polynomial(int* a, int _n){
		clear(); n = _n; rep(i, 0, n) num[i] = a[i];
	}
	Polynomial(int x){
		clear(); n = 0, num[0] = x;
	}
	void operator = (const Polynomial b){
		clear(); n = b.n; rep(i, 0, n) num[i] = b.num[i];
	}
	void operator += (const Polynomial b){
		n = max(n, b.n); rep(i, 0, b.n) num[i] += b.num[i], mo(num[i]);
		while (n && !num[n]) n--;
	}
	void operator -= (const Polynomial b){
		n = max(n, b.n); rep(i, 0, b.n) num[i] += M - b.num[i], mo(num[i]);
		while (n && !num[n]) n--;
	}
	void operator *= (const Polynomial b){
		Polynomial _a(num, n); clear();
		n = _a.n + b.n;
		rep(i, 0, n) rep(j, 0, i) num[i] += 1ll * _a.num[j] * b.num[i - j] % M, mo(num[i]);
	}
	void operator *= (int x){
		rep(i, 0, n) num[i] = 1ll * num[i] * x % M;
	}
}poly;
poly operator + (poly a, poly b){
	poly c; c.n = max(a.n, b.n);
	rep(i, 0, c.n) c.num[i] = a.num[i] + b.num[i], mo(c.num[i]);
	while (c.n && !c.num[c.n]) c.n--;
	return c;
}
poly operator - (poly a, poly b){
	poly c; c.n = max(a.n, b.n);
	rep(i, 0, c.n) c.num[i] = a.num[i] + M - b.num[i], mo(c.num[i]);
	while (c.n && !c.num[c.n]) c.n--;
	return c;
}
poly operator * (poly a, int x){
	poly c; c = a;
	rep(i, 0, c.n) c.num[i] = 1ll * c.num[i] * x % M;
	return c;
}
poly operator * (poly a, poly b){
	poly c; c.n = a.n + b.n;
	rep(i, 0, c.n) rep(j, 0, i) c.num[i] += 1ll * a.num[j] * b.num[i - j] % M, mo(c.num[i]); 
	return c;
}
poly binom(int a, int n){
	poly c; c.n = n;
	rep(i, 0, n) c.num[i] = 1ll * power(a, n - i) * C[n][i] % M;
	return c;
}// return (x + a)^n
poly binom(int a, int b, int n){
	poly c; c.n = n;
	rep(i, 0, n) c.num[i] = 1ll * power(a, i) * power(b, n - i) % M * C[n][i] % M;
	return c;
}// return (ax + b)^n
poly spoly[21];
void init_spoly(){
	spoly[0].n = 1, spoly[0].num[1] = 1;
	srep(k, 1, 21){
		spoly[k] = binom(1, k + 1) - poly(1);
		srep(j, 0, k) spoly[k] -= spoly[j] * C[k + 1][j];
		spoly[k] *= getinv(k + 1);
	}
} //1~n
poly sum(poly a){
	poly c;
	c.n = a.n + 1;
	rep(i, 0, a.n) {
		rep(j, 0, spoly[i].n) {
			c.num[i] += 1ll * a.num[i] * spoly[i].num[j] % M, mo(c.num[i]);
		}
	}
	return c;
}// return \sum a(x)
int getval(poly& f, int x){
	int nowx = 1, res = 0;
	rep(i, 0, f.n){
		res += 1ll * nowx * f.num[i] % M, mo(res);
		nowx = 1ll * nowx * x % M;
	}
	return res;
}
int Ans(int a, int b, int c, int n, poly f, int k2){
	cerr << a << ' ' << b << ' ' << c << ' ' << n << endl;
	if (!a){
		f = sum(f);
		return 1ll * power(b / c, k2) * getval(f, n) % M;
	}
	if (n < 50) {	
		int res = 0;
		rep(i, 1, n) res += 1ll * getval(f, i) * power((1ll * a * i + b) / c % M, k2) % M, mo(res);
		return res;
	}
	int a1 = a / c, a2 = a - a1 * c, b1 = b / c, b2 = b - b1 * c, res = 0, _n = (1ll * a2 * n + b2) / c;
	if (!a2){
		poly _f;
		_f = f * binom(a1, b1, k2);
		_f = sum(_f);
		res = getval(_f, n);
		return res;
	}
	rep(j, 0, k2){
		poly _f;
		_f = f * binom(a1, b1, k2 - j) * C[k2][j];
		_f = sum(_f);
		if (!j) {
			res += getval(_f, n);
			mo(res);
			continue;
		}
		poly __f;
		__f.num[j] = 1, __f.n = j;
		__f -= binom(1, j);
		assert(__f.num[j] == 0); 
		rep(_k2, 0, _f.n){
			res += 1ll * _f.num[_k2] * Ans(c, c - b2 - 1, a2, _n - 1, __f, _k2) % M, mo(res);
		}
		res += 1ll * power(_n, j) * getval(_f, (1ll * c * (_n + 1) - b2 - 1) / a2) % M, mo(res);
		res += 1ll * (M - 1) * getval(_f, (c - b2 - 1) / a2) % M, mo(res);
	}
	return res;
} //1~n
void init(){
	init_C(), init_spoly();
} 
int main(){
	init();
	int T, a, b, c, n, k1, k2;
	scanf("%d", &T);
	while (T--){
		poly f;
		scanf("%d%d%d%d%d%d", &a, &b, &c, &n, &k1, &k2);
		f.n = k1, f.num[k1] = 1;
		printf("%lld\n", (Ans(a, b, c, n - 1, f, k2) + 1ll * power(0, k1) * power(b / c, k2) % M) % M);
	}
	return 0;
}

/*
int Seff[20][21];
int C[20][20];
int _a[21], _b[21];
void muleff(int* a, int n, int* b, int m, int* c, int& k){
	rep(i, 0, n) _a[i] = a[i]; rep(i, 0, m) _b[i] = b[i];
	k = n + m;
	rep(i, 0, k) c[i] = 0;
	rep(i, 0, n + m){	
		rep(j, 0, i){
			c[i] += 1ll * _a[i - j] * _b[j] % M, mo(c[i]);
		}
	}
}
void bieff(int a, int n, int* c, int& k){
	rep(i, 0, n) c[i] = 1ll * power(a, n - i) * C[n][i] % M, mo(c[i]);
	k = n;
}
void addeff(
//(x + a)^n 
void init(){
	C[0][0] = 1;
	srep(i, 1, 20){
		C[i][0] = 1;
		srep(j, 1, 20) C[i][j] = C[i - 1][j] + C[i - 1][j - 1], mo(C[i][j]);
	}
	Seff[0][1] = 1;
	rep(k, 1, 19) {
		
	}
}
int power(int x, int y){
	int ans = 1, con = x;
	while (y){
		if (y & 1) ans = 1ll * ans * con;
		con = 1ll * con * con;
		y >>= 1;
	}
	return ans;
}//0^0 = 1
int getinv(int x){
	return power(x, M - 2);
}
int getval(int x, int k, int* eff){
	int ans = 0, nowx = 1;
	rep(i, 0, k) {
		ans += 1ll * eff[i] * nowx % M;
		mo(ans);
		nowx = 1ll * nowx * x % M;
	}
	return ans;
}
int getS(int n, int k){
	
}//1 ~ n, i^k
int Ans(int a, int b, int c, int n, int* eff, int k1, int k2){
	if (!a) {
	}
	int a1 = a / c, a2 = a - a1 * c, b1 = b / c, b2 = b - b1 * c;
	int nxt_a = 
}//1 ~ n, eff is a polynomial...

int eff[21];

*/

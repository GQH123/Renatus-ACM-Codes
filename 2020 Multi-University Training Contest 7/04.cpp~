#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 2000020
#define ll long long int  
#define mo(x) (x = (x >= m) ? (x - m) : x)
using namespace std;

int t, a, c, m;

ll cal(ll n, ll a, ll b, ll m){
	return n == 0 ? 0 : 
	a >= m ? (n * (a / m) + cal(n, a % m, b, m)) : 
	//a < 0 ? (-n + cal(n, a + m, b, m)) :
	b >= m ? ((n - 1) * n / 2 * (b / m) + cal(n, a, b % m, m)) : 
	//b < 0 ? (-(n - 1) * n / 2 + cal(n, a, b + m, m)) :
	cal((a + b * n) / m, (a + b * n) % m, m, b);
}//0 ~ n - 1
ll cal2(ll n, ll a, ll b, ll m){
	return cal(n, a, b, m) - 2 * cal(n, a, b, m * 2);
}
ll play(int d, int B, int A){ // v1 = d, v2 = 0 --> v1 = t, v2 = t - d delta = t - d
	int init = d; //0 ~ t - d
	A += 1ll * init * B % m, mo(A);
	B = B * 2, mo(B);
	ll res = 0;
	if (!(m & 1)){
		if (B & 1) res += (A & 1) ? (t - d + 1 - (t - d + 1) / 2) : ((t - d + 1) / 2);
		else res += (A & 1) * (t - d + 1);
	}
	else {
		res += cal2(t - d + 1, m * (A & 1) + A, m * (B & 1) + B, m);
	}
	//cerr << res << ' ' << t - d + 1 - res << endl;
	return t - d + 1 - res;
	/*
	//res += (A & 1) * (t - d + 1);
	if ((B & 1) && !(m & 1)){
		res += (t - d + 1) / 2;
	}
	else if (!(B & 1) && (m & 1)){
		res -= cal2(t - d + 1, A, B, m);
	}
	else if ((B & 1) && (m & 1)){
		res -= cal2();
	}
	*/ 
}
ll gcd(ll x, ll y){
	return (!y) ? x : gcd(y, x % y);
}
int main(){
	int T; scanf("%d", &T);
	while (T--){
		scanf("%d%d%d%d", &t, &a, &c, &m);
		int B0 = 1, A0 = 0;
		ll res = 0, all = 1ll * (t + 1) * (t + 1);
		rep(i, 0, t){
			res += ((i == 0) ? 1 : 2) * play(i, B0, A0);
			A0 += 1ll * c * B0 % m, mo(A0);
			B0 = 1ll * a * B0 % m;
		}
		ll d = gcd(res, all);
		res /= d, all /= d;
		printf("%lld/%lld\n", res, all);
	}
	return 0;
}

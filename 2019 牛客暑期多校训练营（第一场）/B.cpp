#include <bits/stdc++.h>
#define maxr 100000
#define maxn 1019
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define ll long long int
#define pii pair<int, int>
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define M 1000000007
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> bool read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-' && ch != EOF) ch = gc();
	if (ch == EOF) return false;
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
	return true;
}

void reads(char* s, int& len){	
	char ch = gc(); len = 0;
	while (!('a' <= ch && ch <= 'z')) ch = gc();
	while ('a' <= ch && ch <= 'z') s[++len] = ch, ch = gc();
}

int n;
ll a[maxn];

ll power(ll a, ll b){
	ll ans = 1, con = a;
	while (b){
		if (b & 1) ans = ans * con % M;
		con = con * con % M;
		b >>= 1;
	}
	return ans;
}

ll getinv(ll x){
	return power(x, M - 2);
}

ll res[maxn][maxn];
ll solve(){
	rep(i, 1, n) res[i][i] = getinv(a[i] << 1);
	rep(l, 2, n){
		rep(i, 1, n - l + 1){
			ll A = res[i + 1][i + l - 1];
			ll B = res[i][i + l - 2];
			res[i][i + l - 1] = (B - A + M) * getinv(a[i + l - 1] * a[i + l - 1] % M - a[i] * a[i] % M + M) % M;
		}
	}
	return res[1][n];
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("B.in", "r", stdin);
	#endif
	while (read(n)){
		rep(i, 1, n) read(a[i]);
		printf("%lld\n", solve());
	}
	return 0;
}

#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define maxn 
#define maxm 
#define M 998244353
#define ll long long int 
#define ld long double
#define pb push_back
#define pc putchar
#define pii pair<int, int>
#define fi first
#define se second
#define mo(x) (x = (x >= M) ? (x - M) : x)
#define lowbit(x) (x & -x)
#define maxr 1000000
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template<class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') ch = gc(), f = 0;
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}
void reads(char* s){
	char ch = gc(); int l = 0;
	while (!('a' <= ch && ch <= 'z')) ch = gc();
	while ('a' <= ch && ch <= 'z') s[l++] = ch, ch = gc();
	s[l] = '\0';
}

ll power(ll x, ll y){
	ll ans = 1, con = x;
	while (y){
		if (y & 1) ans = ans * con % M;
		con = con * con % M;
		y >>= 1;
	}
	return ans;
}
ll getinv(ll x){
	return power(x, M - 2);
}

int main(){
	//ios :: sync_with_stdio(false);
	//cin.tie(0);
	int T; read(T);
	ll m, p, q;
	while (T--){
		read(m), read(p), read(q);
		ll invp = getinv(p);
		ll inv100 = getinv(100);
		ll res = (q * invp % M + (M - q * inv100 % M) + (M - 1)) % M;
		res += (m - 1) * (q * invp % M + M - 1) % M;
		res %= M;
		printf("%lld\n", (M - res) % M);
	}
	
	return 0;
}

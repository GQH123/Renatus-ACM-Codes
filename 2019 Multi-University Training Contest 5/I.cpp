#include <bits/stdc++.h>
#define maxr 100000
#define maxp 100015
#define eb emplace_back
#define pb push_back
#define pii pair<int, int>
#define ll long long int 
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') ch = gc(), f = 0;
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}

ll power(ll a, ll b, ll p){
	ll ans = 1, con = a;
	while (b){
		if (b & 1) ans = ans * con % p;
		con = con * con % p;
		b >>= 1;
	}
	return ans;
}

ll getinv(ll x, ll p){
	return getinv(x, p - 2, p);
}

map<ll, ll> s;
ll Baby_Step_Giant_Step(ll a, ll b, ll p){ // p is a prime, 0 <= a, b <= p - 1
	int sz = (int)sqrt(p), nm = p / sz + 1;
	ll now = 1;
	srep(i, 0, sz) {
		s[now] = i;
		(now *= a) %= p;
	}
	now = getinv(now, p);
	ll x = 0;
	srep(i, 0, sz){
		if (s.count(b)) return (ll)i * sz + s[b];
		(b *= now) %= p;
	}
	return -1;
} //a ^ x = b (mod p) return x (mod (p - 1))

ll Chinese_Remainder_Theorem(int n, ll* a, ll* p){
	ll x = 0, P = 1;
	rep(i, 1, n) P *= p[i]; 
	rep(i, 1, n) (x += P / p[i] * a[i] % P * getinv(P / p[i], p[i]) % P) %= P; 
	return x;
} //x_i = a_i (mod p_i) return x (mod p) 1 <= i <= n

bool vp[maxp];
int pri[maxp], cp = 0;
void Prime_Sieve_of_Euler(){
	srep(i, 2, maxn){
		if (!vp[i]) pri[++cp] = i;
		rep(j, 1, cp){
			if (i * pri[j] >= maxn) break;
			vp[i * pri[j]] = 1;
			if (i % pri[j] == 0) break;
		}
	}
}

vector< pii<int, int> > pi;
void Prime_Factorize(ll p){
	int ai;
	rep(i, 1, cp){
		if ((ll)pri[i] * pri[i] > p) break;
		if (p % pri[i] == 0){
			ai = 0;
			while (p % pri[i] == 0) p /= pri[i], ai++;
			pi.eb(pii(pri[i], ai));
		}
	}
	if (p > 1) pi.eb(pii(p, 1)); // Just an experiment...
}

ll Find_Primitive_Root(ll p){ // 1, 2, 4, p^e, 2p^e
	//需要先对 p - 1 做 Prime_Factorize
	//Prime_Factorize(p - 1);
	int sz = pi.size();
	rep(g, 2, p - 1){
		srep(i, 0, sz) if (power(g, (p - 1) / pi[i].fi, p) == 1) goto fail; 
		return g;
		fail:;
	}
	return -1;
}

ll A[maxnp], P[maxnp];
int cn;
ll Pohlig_Hellman_General(ll g, ll h, ll p){	
	cn = 0;
	ll gi, hi, x;
	int nump = pi.size();
	srep(i, 0, nump){
		ll Pi = 1;
		srep(j, 0, pi[i].se) Pi *= pi[i].fi;
		gi = power(g, (p - 1) / Pi, p);
		hi = power(h, (p - 1) / Pi, p);
		x = Pohlig_Hellman_Prime_Power(gi, hi, pi[i].fi, pi[i].se);
	}
	return Chinese_Reminder_Theorem(cn, A, P);
} //a ^ x = b (mod p ^ e) return x

ll gcd(ll a, ll b){
	return (!b) ? a : gcd(b, a % b);
}

ll getphi(ll p){
	//需要先对 p 做 Prime_Factorize，此处的 p 实际上就是输入中的 p - 1
	//Prime_Factorize(p - 1);
	int sz = pi.size();
	ll ans = p;
	srep(i, 0, sz) ans = ans / pi[i].fi * (pi[i].fi - 1);
	return ans;
}

ll full_getinv(ll a, ll p){
	return power(a, getphi(p) - 1, p);
}

ll Solve_Linear_Congruence_Equation(ll a, ll b, ll p){
	ll d = gcd(a, b);
	if (p % d) return -1;
	a /= d, b /= d, p /= d;
	if (gcd(a, p) != 1) return -1;
	return x = b * full_getinv(a, p) % p;
}//ax = b (mod p)

int main(){
	#ifndef ONLINE_JUDGE
		freopen("I.in", "r", stdin);
	#endif
	Prime_Sieve_of_Euler();
	int T;
	read(T);
	ll p, a, b, g;
	while (T--){
		read(p), read(a), read(b);
		Prime_Factorize(p - 1);
		g = Find_Primitive_Root(p);
		ll _a = Pohlig_Hellman(g, a, p);
		ll _b = Pohlig_Hellman(g, b, p);
		if (_a == -1 || _b == -1) printf("-1\n");
		printf("%lld\n", Solve_Linear_Congruence_Equation(_a, _b, p - 1));
	}
	return 0;
}

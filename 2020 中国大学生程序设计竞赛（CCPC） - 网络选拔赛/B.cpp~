#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define ll long long int 
#define pb push_back 
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn 2020
#define maxm
#define maxs
#define maxb 
#define MAX 200020
#define LL long long int 
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}
int _num[20];
template <class T> void write(T x){	
	if (!x) {putchar('0'), putchar('\n'); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar('\n');
}


/*
int cp = 0, p[maxn]; bool pvis[maxn];
void init(){
	srep(i, 2, maxn) {
		if (!pvis[i]) p[++cp] = i;
		rep(j, 1, cp) {
			if (i * p[j] >= maxn) break;
			pvis[i * p[j]] = 1;
			if (i % p[j] == 0) break;
		}
	}
}

int main(){
	init();
	int sum = 0;
	rep(i, 3, 101) {
		if (i & 1) {
			if (!pvis[i]) sum += (i << 1);
			else sum += i;
		}
		else sum += i;
	}
	cout << sum << endl;
	return 0;
}
*/

int lim, pc, prime[MAX];
bool vis[MAX];
LL N, s1[MAX], s2[MAX], f1[MAX], f2[MAX];
void preprocess(LL n) {
	pc = 0;
	lim = sqrt(n + 0.5);
	while ((lim + 1LL) * (lim + 1) <= n) lim++;
	for (int i = 2; i <= lim; i++){
		if (!vis[i]) prime[pc++] = i;
		for (int j = 0; j < pc; j++){
			int x = i * prime[j];
			if (x > lim) break;
			vis[x] = true;
			if (i % prime[j] == 0) break;
		}
	}
}
inline LL get_sp(LL x){
	return x <= lim ? s1[x] : s2[N / x];
}
inline LL get_f(LL x){
	return x <= lim ? f1[x] : f2[N / x];
}
LL solve(LL n){
	N = n;
	lim = sqrt(n + 0.5);
	while ((lim + 1LL) * (lim + 1) <= n) lim++;
	for (int i = 1; i <= lim; i++){
		s1[i] = (2LL+i)*(i-1)/2, s2[i] = (2LL+n / i)*(n/i - 1)/2;
		//s1[i] = i - 1, s2[i] = n / i - 1;
	}
	for (int i = 0; i < pc && prime[i] <= lim; i++){
		int p = prime[i], k = lim / p, l = min((LL)lim, n / p / p);
		for (int j = 1; j <= k && j <= l; j++){
			s2[j] -= p*(s2[j * p] - s1[p - 1]);
		}
		LL t = n / p;
		for (int j = k + 1; j <= l; j++){
			s2[j] -= p*(s1[t / j] - s1[p - 1]);
		}
		for (int j = lim; j >= (LL)p * p; j--){
			s1[j] -= p*(s1[j / p] - s1[p - 1]);
		}
	}
	/*
	int mxp = 0;
	for (int &i = mxp; i < pc && prime[i] <= lim; i++);
	for (int i = 1; i <= lim; i++) f1[i] = f2[i] = 1;
	int lst = lim + 1;
	for (int i = mxp - 1; i >= 0; i--){
		int p = prime[i];
		LL tmp = (LL)lst * lst;
		for (int j = 1;	j <= lim; j++){
			LL t = N / j / p;
			if (t < p) break;
			if (tmp * j > N) f2[j] += s2[j] - s1[p];
			for (int k = 1; t; k++, t /= p)
				f2[j] += (get_f(t) + (tmp > t && t > p ? get_sp(t) - s1[p] : 0)) * (2 * k + 1);
		}
		for (int j = lim; j >= 1; j--){
			LL t = j / p;
			if (t < p) break;
			if (tmp > j) f1[j] += s1[j] - s1[p];
			for (int k = 1; t; k++, t /= p) f1[j] += (get_f(t) + (tmp > t && t > p ? get_sp(t) - s1[p] : 0)) * (2 * k + 1);
		}
		lst = p;
	}
	LL tmp = (LL)lst * lst;
	for (int i = 1; i <= lim; i++){
		if (tmp <= i) break;
		f1[i] += s1[i];
	}
	for (int i = lim; i >= 1; i--){
		if (tmp <= N / i) break;
		f2[i] += s2[i];
	}
	*/
	return s2[1];
}

ll n, M;

ll cal_even(ll n) { // 2n
	ll _n = n % M;
	return (_n * (_n + 1) % M + M - 2) % M;
}
ll cal_odd(ll n) { //2n + 1
	ll _n = n % M;
	return ((_n + 1) * (_n + 1) % M + M - 1) % M;
}
int main(){
	preprocess(10000000020ll); 
	int T; scanf("%d", &T);
	while (T--){
		scanf("%lld%lld", &n, &M); n++;
		//cerr << cal_even(n / 2) << endl << cal_odd((n - 1) / 2) << endl << solve(n) << endl;
		printf("%lld\n", (1ll * cal_even(n / 2) + 1ll * cal_odd((n - 1) / 2) + 1ll * solve(n) % M + M - 2) % M);
	} 
}


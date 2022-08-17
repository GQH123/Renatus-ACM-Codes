#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int 
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first 
#define se second 
#define maxr 100019
#define maxn 10000019
#define maxm
#define maxs 
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template<class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}

ll C;

int p[maxn];
bool vis[maxn];
int ct = 0;
void init(){
	srep(i, 2, maxn) {
		if (!vis[i]) p[++ct] = i;
		rep(j, 1, ct){
			if (i * p[j] >= maxn) break;
			vis[i * p[j]] = 1;
			if (i % p[j] == 0) break;
		}
	}
}

ll _sqrt(ll C){
	ll l = 1, r = 5147483648;
	while (l < r){
		ll mid = (r + l) / 2;
		if (C % mid == 0) {
			if (C / mid == mid) return mid; 
		}
		if (mid <= C / mid) l = mid + 1;
		else r = mid;
	}
	if (l * l != C) return -1;
	else return l;
}

int main(){
	/*
		#ifndef ONLINE_JUDGE
			freopen("H.in", "r", stdin);
		#endif
	*/
	init();
	scanf("%lld", &C);
	ll ans = 1;
	rep(i, 1, ct){
		if (C % p[i] == 0) {
			int d = 0;
			while (C % p[i] == 0) {
				d ^= 1;
				C /= p[i];
			}
			if (d) ans *= p[i];
		}
	}
	if (C > 1){
		ll k = _sqrt(C);
		if (k == -1) ans *= C;
	}
	printf("%lld", ans);
	return 0;
}

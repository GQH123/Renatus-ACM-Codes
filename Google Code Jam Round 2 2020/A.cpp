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
#define pc putchar
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn
#define maxm
#define maxs
#define maxb
#define M 
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

inline ll cal(ll x){
	return (ll)x * (x + 1) >> 1;
}
ll lower_bound2(ll l, ll r, ll x){
	while (l < r){
		ll mid = ((r - l) >> 1) + l;
		if (cal(mid) < x) l = mid + 1;
		else r = mid;
	}
	return l;
}

inline ll cal2(ll x, ll ans){
	return ((ll)ans + ans + (x - 1) * (ll)2) * (ll)x >> 1;
}
ll upper_bound2(ll l, ll r, ll x, ll ans){ // ans, ans + 2, ans + 4, ..., ans + (l - 1) * 2;
	while (l < r){
		ll mid = ((r - l) >> 1) + l;
		if (cal2(mid, ans) <= x) l = mid + 1;
		else r = mid;
	}
	return l;
}

int main(){
	//cerr << cal(1714642818) << endl;
	int T;
	ll A, B;
	scanf("%d", &T);
	rep(TT, 1, T){	
		printf("Case #%d: ", TT);
		scanf("%lld%lld", &A, &B);
		ll ans = 0;
		if (A > B){
			ll d = A - B;
			ll id = lower_bound2(0, 2000000000, d);
			A -= cal(id);
			ans = id;
			if (A < 0) {
				ans--;
				A += id;
				printf("%lld %lld %lld\n", ans, A, B);
				continue;
			}
			if (A < B) ans--, A += id; // Now is A's play!!!
		}
		else {
			ll d = B - A;
			ll id = lower_bound2(0, 2000000000, d);
			B -= cal(id);
			ans = id;
			if (B < 0){
				ans--;
				B += id;
				printf("%lld %lld %lld\n", ans, A, B);
				continue;
			}
		}
		ll ansA = upper_bound2(1, 2000000000, A, ans + 1);
		ll ansB = upper_bound2(1, 2000000000, B, ans + 2);
		if (ansA <= ansB){
			ansA--; 
			B -= cal2(ansA, ans + 2);
			A -= cal2(ansA, ans + 1);
			ans += (ansA << 1);
			printf("%lld %lld %lld\n", ans, A, B);
			continue;
		}
		else {
			ansB--; 
			B -= cal2(ansB, ans + 2);
			A -= cal2(ansB + 1, ans + 1);
			ans += (ansB << 1 | 1);
			printf("%lld %lld %lld\n", ans, A, B);
			continue;
		}
	}
	return 0;
}


#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pli pair<ll, int>
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
#define maxn 200020
#define maxm
#define maxs
#define maxb
#define M 1000000007
#define mo(x) (x = (x >= M) ? (x - M) : x)
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
template <class T> void write(T x, char sep = '\n'){	
	if (!x) {putchar('0'), putchar(sep); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar(sep);
}

ll bas[64];
int bas_cnt = 0;
void add(ll v) {
	per(i, 60, 0) {
		if (v & (1ll << i)) {
			if (bas[i]) v ^= bas[i];
			else {bas[i] = v; bas_cnt++; return;}
		}
	}
}
bool chk(ll v){
	if (!v) return true;
	per(i, 60, 0) {
		if (v & (1ll << i)) {
			if (bas[i]) {
				v ^= bas[i];
				if (!v) return true;
			}
			else return false;
		}
	}
	return false;
}
int mi[maxn];
pli lis[maxn]; int cs = 0;
int n; ll a[maxn], suf[maxn]; 

int main(){
	read(n); mi[0] = 1; rep(i, 1, n) read(a[i]), mi[i] = mi[i - 1] << 1, mo(mi[i]);
	sort(a + 1, a + 1 + n);
	reverse(a + 1, a + 1 + n);
	rep(i, 1, n) {
		ll now = a[i]; int _i = i;
		while (i <= n && a[i] == now) i++;
		lis[++cs] = pli(now, i - _i), i--;
	}
	per(i, cs, 1) {
		suf[i] = suf[i + 1];
		if (lis[i].se & 1) suf[i] ^= lis[i].fi;
	}
	int ans = 0, pre_cnt = 0; ll pre = 0;
	rep(i, 1, cs){
		int odd = mi[lis[i].se - 1], even = odd + M - 1; mo(even);
		if (lis[i].se & 1) {
			ll all = pre ^ suf[i + 1];
			if (all == lis[i].fi) ans += odd, mo(ans);
			if ((all ^ lis[i].fi) == lis[i].fi - 1) ans += even, mo(ans);
			all = suf[i + 1] ^ (lis[i].fi - 1);
			if (chk(all)) ans += 1ll * (((pre == all) ? (M - 1) : 0) + mi[pre_cnt - bas_cnt]) % M * odd % M, mo(ans); 
			all = suf[i + 1] ^ lis[i].fi ^ lis[i].fi;
			if (chk(all)) ans += 1ll * (((pre == all) ? (M - 1) : 0) + mi[pre_cnt - bas_cnt]) % M * even % M, mo(ans); 
		}
		else {
			ll all = pre ^ suf[i + 1];
			if ((all ^ lis[i].fi) == lis[i].fi) ans += odd, mo(ans);
			if (all == lis[i].fi - 1) ans += even, mo(ans);
			all = suf[i + 1] ^ lis[i].fi ^ (lis[i].fi - 1);
			if (chk(all)) ans += 1ll * (((pre == all) ? (M - 1) : 0) + mi[pre_cnt - bas_cnt]) % M * odd % M, mo(ans); 
			all = suf[i + 1] ^ lis[i].fi;
			if (chk(all)) ans += 1ll * (((pre == all) ? (M - 1) : 0) + mi[pre_cnt - bas_cnt]) % M * even % M, mo(ans); 
		}
		add(lis[i].fi);
		pre_cnt += lis[i].se;
		pre ^= ((lis[i].se & 1) ? lis[i].fi : 0);
	}
	if (!suf[1]) ans++, mo(ans);
	write(ans);
	return 0;
}


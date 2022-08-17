#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, r, l) for (int i = r; i >= l; i--)
#define srep(i, l, r) for (int i = l; i < r; i++)
#define sper(i, r, l) for (int i = r; i > l; i--)
#define erep(i, x) for (int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (int& i = cur[x]; i; i = e[i].next)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define ll long long
#define pb push_back
#define pc putchar
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn 300020
#define maxm
#define maxs
#define maxb
#define M 
#define int long long
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

ll n, a1, d, a[maxn]; ll pre[maxn];
ll k, y;

ll numk[100], ck = 0;
ll numy[100], cy = 0;
void dep(ll x, ll* num, int& ct){
	memset(num, 0, sizeof(num));
	ct = 0; while (x) num[ct++] = x & 1, x >>= 1; 
}
int dfs(int pos, int op){
	if (pos == -1) return 0;
	if (numy[pos]) {
		if (numk[pos]) return dfs(pos - 1, 1); 
		else return 0;
	}
	else return dfs(pos - 1, op) + (numk[pos] ? (1ll << pos) : 0); 
}
signed main(){
	read(n), read(a1), read(d), read(k), read(y);
	dep(k, numk, ck);
	a[1] = pre[1] = a1; rep(i, 2, n) a[i] = a[i - 1] + d, pre[i] = pre[i - 1] + a[i];
	ll res = -1, _res = -1;
	per(i, n, 1) {
		if (pre[i - 1] > y) continue;
		int num = n - i + 1;
		ll nowy = (y - pre[i - 1]) / num; // smaller than or equal to nowy 
		if (nowy >= k) _res = 0;
		else {
			dep(nowy, numy, cy);
			_res = dfs(ck - 1, 1);
		} 
		_res = _res * num << 1;
		res = (res == -1) ? _res : min(res, _res);
		//cout << nowy << ' ' << res << ' ' << _res << endl;
	}
	write(res);
	return 0;
}


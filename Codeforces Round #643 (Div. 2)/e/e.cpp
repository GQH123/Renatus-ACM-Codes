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
#define maxn 200020
#define maxm
#define maxs
#define maxb 
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

int n, a[maxn], _a[maxn];
ll pre[maxn];

int A, R, M;

ll play1(ll fin, ll r){
	ll ans = (ll)r * R, _ans = 0;  
	//ll fin = sum / n;
	rep(i, 1, n) a[i] = _a[i];
	per(i, n, 1){
		int k = a[i] - fin;
		if (k < r) a[i] = fin, r -= k;
		else {a[i] -= r; break;}
	}
	rep(i, 1, n) _ans += (ll)abs(fin - a[i]) * M;  
	return ans + (_ans >> 1);
}

ll play2(ll fin, ll r){
	//r = _r;
	//ll fin = (sum % n) ? (sum / n + 1) : (sum / n);
	rep(i, 1, n) a[i] = _a[i];
	ll ans = (ll)r * A, _ans = 0;  
	rep(i, 1, n){
		int k = fin - a[i];
		if (k < r) a[i] = fin, r -= k;
		else {a[i] += r; break;}
	}
	rep(i, 1, n) _ans += (ll)abs(fin - a[i]) * M; 
	return ans + (_ans >> 1);
}

int main(){
	scanf("%d", &n), scanf("%d%d%d", &A, &R, &M);
	rep(i, 1, n) scanf("%d", a + i);
	M = min(M, A + R);
	sort(a + 1, a + 1 + n);
	rep(i, 1, n) _a[i] = a[i];
	ll ans2 = 0;
	rep(i, 1, n) ans2 += (ll)(a[n] - a[i]) * A;
	ll ans3 = 0;
	rep(i, 1, n) ans3 += (ll)(a[i] - a[1]) * R;
	ll sum = 0;
	rep(i, 1, n) sum += a[i];
	int r = sum % n;
	int _r = (r) ? (n - r) : 0;
	ll ans = min(play1(sum / n, r), play2((sum % n) ? (sum / n + 1) : (sum / n), _r)); 
	rep(i, 1, n) a[i] = _a[i], pre[i] = pre[i - 1] + a[i];
	ll ans4 = -1;
	rep(i, 1, n){
		int li = i, now = a[i];
		while (i <= n && a[i] == now) i++; i--;
		int ri = i;
		ll nA = (ll)(li - 1) * now - pre[li - 1];
		ll nR = (pre[n] - pre[ri]) - (ll)(n - ri) * now; 
		ll __ans = min(nA, nR) * M + (nA - min(nA, nR)) * A + (nR - min(nA, nR)) * R;
		ans4 = (ans4 == -1) ? __ans : min(ans4, __ans); 
	}
	printf("%lld", min(ans4, min(min(ans3, ans2), ans)));
	return 0;
}


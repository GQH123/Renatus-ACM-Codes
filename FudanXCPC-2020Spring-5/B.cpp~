#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define pii pair<int, int>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define ll long long int 
#define pb push_back
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn 300020
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

int n, t;
ll a[maxn];

int main(){
	
		freopen("B.in", "r", stdin);
		
	read(n), read(t);
	rep(i, 1, n) read(a[i]);
	int st = lower_bound(a + 1, a + 1 + n, 0ll) - a, add = 0, ans = -1;
	if (a[st] != 0 || st < 1 || st > n) {
		n++;
		per(i, n, st + 1) a[i] = a[i - 1];
		a[st] = 0;
		add--;
	}
	int l = st, r = st;
	while (l >= 1 && -(ll)a[l] + a[r] + min(-a[l], a[r]) <= (ll)t) l--;
	l++;
	ans = r - l + 1;
	r = st + 1;
	for (; r <= n; r++){
		while (l <= st && -(ll)a[l] + a[r] + min(-a[l], a[r]) > (ll)t) l++;
		if (l <= st) ans = max(ans, r - l + 1);
		else break;
	}
	write(ans + add);
	/*
	int st = lower_bound(a + 1, a + 1 + n, 0) - a, ans = -1, add = 0;
	if (a[st] == 0) {
		add = 1;
		srep(i, st, n) a[i] = a[i + 1]; n--;
		//if (st > n) st--;
	}//st - 1 < 0 , st > 0;
	per(l, st - 1, 1) {
		if (-a[l] <= t) ans = (ans == -1) ? (st - l) : max(ans, st - l);
	} 
	rep(r, st, n) {
		if (a[r] <= t) ans = (ans == -1) ? (r - st + 1) : max(ans, r - st + 1);
	}  
	if (a[1] > 0 || a[n] < 0) {write(ans + add); return 0;}
	int l = st - 1, mxl = -a[l], mxr = a[st];
	while (l >= 1 && mxl + mxr + min(mxl, mxr) <= t){
		l--;
		mxl = -a[l];
	} 
	l++, mxl = -a[l];
	if (mxl + mxr + min(mxl, mxr) <= t) ans = (ans == -1) ? (st - l + 1) : max(ans, st - l + 1);
	rep(r, st + 1, n){
		mxr = a[r];
		while (l < st && mxl + mxr + min(mxl, mxr) > t){
			l++;
			mxl = -a[l];
		}
		if (l >= st) break;
		ans = (ans == -1) ? (r - l + 1) : max(ans, r - l + 1);
	}
	write(ans + add);
	*/
	
	return 0;
}


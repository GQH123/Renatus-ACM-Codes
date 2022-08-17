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
#define maxn 220
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

char s[maxn];
int ctl[maxn], ctx[maxn];

int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		scanf("%s", s + 1);
		int n = strlen(s + 1);
		ctl[n + 1] = ctx[n + 1] = 0;
		per(i, n, 1){
			ctl[i] = ctl[i + 1] + (s[i] == 'l');
			ctx[i] = ctx[i + 1] + (s[i] == 'x');
		}
		if (ctx[1] < 3) {printf("0\n"); continue;}
		int _ct = 0, pos = -1;
		rep(i, 1, n){
			if (s[i] == 'x') _ct++;
			if (_ct == 3) {pos = i; break;}
		}
		int res = -1;
		int ans = 0;
		rep(i, pos, n){
			if (s[i] == 'x') {
				res = (res == -1) ? (ans + max(0, ctl[i] - 1)) : min(res, (ans + max(0, ctl[i] - 1)));
				ans++;
			} 
		}
		res = (res == -1) ? ans : min(res, ans);
		printf("%d\n", res);
		/*
		int ctl = 0, pos = -1;
		per(i, n, 1){
			if (s[i] == 'x') ctl++;
			if (ctl == 3){
				pos = i;
				break;
			}
		}
		
		if (pos == -1) {printf("0\n"); continue;}
		int ans = 0, _ans = 0;
		per(i, n, 1){
			if (s[i] == 'x') break;
			_ans++;
		}
		//ans = max(0, _ans - 1);
		int __ans = 0;
		rep(i, 1, n) if (s[i] == 'x') __ans++;
		__ans -= 2;
		ans = min(max(0, _ans - 1), __ans);
		printf("%d\n", ans);
		*/
	} 
	return 0;
}


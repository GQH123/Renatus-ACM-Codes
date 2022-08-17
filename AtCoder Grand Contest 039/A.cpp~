#include <bits/stdc++.h>
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
#define maxn 219
#define maxr 100000
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
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
int n, k;
char s[maxn];
int main(){
	#ifndef ONLINE_JUDGE
		freopen("A.in", "r", stdin);
	#endif
	scanf("%s", s + 1);
	scanf("%d", &k);
	n = strlen(s + 1);
	if (s[1] == s[n]){
		int pre = 0, suf = 0, ans = 0;
		rep(i, 1, n){
			int now = s[i], _i = i;
			while (i <= n && s[i] == now) i++;
			if (i - _i == n) {
				printf("%lld", (ll)n * k >> 1);
				return 0;
			}
			if (_i == 1) pre = i - _i;
			else if (i == n + 1) suf = i - _i;
			else ans += ((i - _i) >> 1); 
			i--;
		}
		printf("%lld", (ll)ans * k + (ll)(k - 1) * ((pre + suf) >> 1) + (pre >> 1) + (suf >> 1));
	}
	else {
		int ans = 0;
		rep(i, 1, n){
			int now = s[i], _i = i;
			while (i <= n && s[i] == now) i++;
			ans += ((i - _i) >> 1);
			i--;
		}
		printf("%lld", (ll)ans * k);
	}
	return 0;
}

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
#define maxn 200020
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

int n;
vector<int> A0, A1, B0, B1;

int main(){
	
		freopen("E.in", "r", stdin); 
	
	int x;
	while (scanf("%d", &n) == 1){
		rep(i, 1, n) {
			scanf("%d", &x);
			if (x < 0) A0.pb(x);
			else A1.pb(x);
		}
		rep(i, 1, n) {
			scanf("%d", &x);
			if (x < 0) B0.pb(x);
			else B1.pb(x);
		}
		sort(A0.begin(), A0.end());
		sort(A1.begin(), A1.end());
		sort(B0.begin(), B0.end());
		sort(B1.begin(), B1.end());
		if (A0.size() == B1.size()){
			int s = A0.size();
			ll ans;
			bool f = 0;
			srep(i, 0, s) {
				if (!f) ans = (ll)A0[i] * B1[i], f = 1;
				else ans = max(ans, (ll)A0[i] * B1[i]);
			}
			srep(i, 0, n - s) {
				if (!f) ans = (ll)A1[i] * B0[i], f = 1;
				else ans = max(ans, (ll)A1[i] * B0[i]);
			}
			printf("%lld\n", ans);
		}
		else if (A0.size() > B1.size()){
			int s = A0.size(), _s = B0.size(), k = A0.size() - B1.size();
			ll ans; bool f = 0;
			rep(i, 1, k){
				if (!f) ans = (ll)A0[s - i] * B0[_s - (k - i + 1)], f = 1;
				else ans = max(ans, (ll)A0[s - i] * B0[_s - (k - i + 1)]);
			}
			printf("%lld\n", ans);
		} 
		else {
			int k = B1.size() - A0.size();
			ll ans; bool f = 0;
			srep(i, 0, k){
				if (!f) ans = (ll)A1[i] * B1[k - 1 - i], f = 1;
				else ans = max(ans, (ll)A1[i] * B1[k - 1 - i]);
			}
			printf("%lld\n", ans);
		}
		A0.clear(), A1.clear(), B0.clear(), B1.clear();
	}
		
	return 0;
}


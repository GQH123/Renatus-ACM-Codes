#include <bits/stdc++.h>
#define maxr 100000
#define maxn 5019
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
int f[maxn][maxn];
int n, a[maxn];
map<int, int> mp;
int main(){
	#ifndef ONLINE_JUDGE
		freopen("B.in", "r", stdin);
	#endif
	read(n);
	rep(i, 1, n) read(a[i]);
	sort(a + 1, a + 1 + n);
	int ans = 2;
	mp[a[1]] = 1;
	rep(i, 2, n){
		mp[a[i]] = i;
		per(j, i - 1, 1){
			if (a[j] - (a[i] - a[j]) < 0) {
				per(k, j, 1) f[k][i] = 2;
				break;
			}
			f[j][i] = (mp.count(a[j] - (a[i] - a[j]))) ? f[mp[a[j] - (a[i] - a[j])]][j] + 1 : 2;
			ans = max(ans, f[j][i]);
		}
	}
	printf("%d", ans);
	return 0;
}

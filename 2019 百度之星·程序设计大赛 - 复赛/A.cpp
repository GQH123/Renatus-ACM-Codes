#include <bits/stdc++.h>
#define maxn 200005
#define maxm 
#define maxr 100000
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}

int n;
vector<int> g[maxn];
int l[maxn], r[maxn], deg[maxn];
bool cmp1(const int i, const int j){
	return r[i] > r[j];
}
bool cmp2(const int i, const int j){
	return l[i] > l[j];
}
int lis[maxn];
bool vist[maxn];

void recover(){
	rep(i, 1, n) vist[i] = deg[i] = 0, g[i].clear();
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("A.in", "r", stdin);
	#endif
	int T, x, y;
	read(T);
	while (T--){
		read(n);
		srep(i, 1, n) read(x), read(y), deg[x]++, deg[y]++, g[x].pb(y), g[y].pb(x);
		rep(i, 1, n) read(l[i]), read(r[i]);
		
		rep(i, 1, n) lis[i] = i;
		sort(lis + 1, lis + 1 + n, cmp1);
		ll ans = 0;
		rep(i, 1, n){
			int x = lis[i];
			if (deg[x] <= 0) continue;
			vist[x] = 1;
			ans += (ll)r[x] * deg[x];
			int si = g[x].size();
			srep(i, 0, si) deg[g[x][i]] -= 2;
		}
		
		rep(i, 1, n) lis[i] = i;
		sort(lis + 1, lis + 1 + n, cmp2);
		rep(i, 1, n){
			int x = lis[i];
			if (vist[x]) continue;
			vist[x] = 1;
			ans += (ll)l[x] * deg[x];
			int si = g[x].size();
			srep(i, 0, si) deg[g[x][i]] -= 2;
		}
		printf("%lld\n", ans); 
		recover();
	}
	return 0;
}

#include <bits/stdc++.h>
#define maxr 100000
#define maxn 1000015
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define ll long long int 
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
char s[maxn];
int f[maxn];
ll sz[maxn];
void init(){	
	f[0] = 0, f[1] = 0;
	srep(i, 2, n){
		int now = f[i - 1];
		while (now && s[now] != s[i - 1]) now = f[now];
		f[i] = (s[now] == s[i - 1]) ? (now + 1) : 0;
	}
}
int main(){
	#ifndef ONLINE_JUDGE
		freopen("F.in", "r", stdin);
	#endif
	int T;
	scanf("%d", &T);
	while (T--){
		scanf("%s", s);
		n = strlen(s);
		init();
		ll ans = 0;
		per(i, n - 1, 1){
			sz[i]++;
			ans += sz[i];
			sz[f[i]] += sz[i];
		}
		printf("%lld\n", ans);
		rep(i, 0, n) sz[i] = f[i] = 0;
	}
	return 0;
}

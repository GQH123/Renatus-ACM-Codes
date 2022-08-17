#include <bits/stdc++.h>
#define maxn
#define maxm
#define maxr 200000
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
//#define ONLINE_JUDGE
//#define DEBUG
using namespace std;

char *p1, *p2, buffer[maxr];
template <class T> void read(T& x){
    char ch = gc(); x = 0; bool f = 1;
    while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
    if (ch == '-') f = 0, ch = gc();
    while ('0' <= ch && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = gc();
    x = f ? x : -x;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("J.in", "r", stdin);
    #endif
	read(T);
	rep(TT, 1, T){
		printf("Case #%d: ", TT);
		read(n), read(m);
		rep(i, 1, n) rep(j, 1, m) read(c[i][j]);
		rep(i, 1, m) read(d[i]);
		ll ans = 0;
		rep(lev, 1, m){
			ans += d[lev];
			
		}
		printf("%lld\n", ans);
	}
    return 0;
}

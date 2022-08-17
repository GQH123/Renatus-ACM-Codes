#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second
#define ll long long int
#define ld long double
#define pb push_back
#define pc putchar 
#define ms(x, a) memset(x, a, sizeof(x))
#define mo(x) (x = (x >= M) ? (x - M) : x)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define maxn 
#define maxm
#define maxr 2000000
#define maxs
#define maxb
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){	
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}

char _num[30];
template <class T> void write(T x, char sep = ' '){
	if (!x) {pc('0'), pc(sep); return;}
	if (x < 0) pc('-'), x = -x;
	int cn = 0;
	while (x) _num[++cn] = x % 10 + '0', x /= 10;
	while (cn) pc(_num[cn--]); pc(sep);
} 

int main(){

	freopen(".in", "r", stdin);
	//ios :: sync_with_stdio(false), cin.tie(0);
	
	return 0;
}

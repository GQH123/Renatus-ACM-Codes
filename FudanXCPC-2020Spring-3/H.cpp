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

ll x, y, n;

int pri[maxn], son[maxn];
bool vis[maxn];
int cp = 0;
void init(int mx){
	rep(i, 2, mx) {
		if (!vis[i]) pri[++cp] = i, son[i] = cp;
		rep(j, 1, cp){
			if (i * pri[j] > mx) break;
			vis[i * pri[j]] = 1;
			son[i * pri[j]] = j;
			if (i % pri[j] == 0) break;
		}
	}
}

pii num[maxn];
int cn = 0;
void dep(ll x){
	rep(j, 1, cp){
		if (pri[j] * pri[j] > x) break;
		if (x % pri[j] == 0){
			int c = 0;
			while (x % pri[j] == 0) c++, x /= pri[j];
			num[++cn] = pii(pri[j], c);
		}
	}
	if (x > 1) num[++cn] = pii(x, 1);
}

ll solve(ll x){
	ll ans = 0;
	srep(i, 0, (1 << cn)){
		int d = 1;
		ll div = 1;
		srep(j, 0, i) if (i & (1 << j)) d = -d, div = div * num[j + 1].fi; 
		ans += d * (x / div);
	}
	return ans;
}

int main(){
	
		freopen("H.in", "r", stdin);
		
	//ios :: sync_with_stdio(false), cin.tie(0);
	int T;
	read(T);
	init(200000);
	rep(TT, 1, T){
		printf("Case #%d: ", TT);
		read(x), read(y), read(n);
		dep(n);
		printf("%lld\n", solve(y) - solve(x - 1));
		cn = 0;
	}
	return 0;
}


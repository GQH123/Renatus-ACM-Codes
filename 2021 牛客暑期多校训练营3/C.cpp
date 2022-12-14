#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, r, l) for (int i = r; i >= l; i--)
#define srep(i, l, r) for (int i = l; i < r; i++)
#define sper(i, r, l) for (int i = r; i > l; i--)
#define erep(i, x) for (int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (int& i = cur[x]; i; i = e[i].next)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define pb push_back
#define pc putchar
#define lowbit(x) (x & -x)
#define maxbuf 2000020
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxbuf, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

namespace Fast_Read{
    char buffer[maxbuf], *p1, *p2;
    template<class T> void read_signed(T& x){
        char ch = gc(); x = 0; bool f = 1;
        while (!isdigit(ch) && ch != '-') ch = gc();
        if (ch == '-') f = 0, ch = gc();
        while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
        x = (f) ? x : -x;
    }
    template<class T, class... Args> void read_signed(T& x, Args&... args){
        read_signed(x), read_signed(args...);
    }
    template<class T> void read_unsigned(T& x){
        char ch = gc(); x = 0;
        while (!isdigit(ch)) ch = gc(); 
        while (isdigit(ch)) x = (x << 1) + (x << 3) + ch - '0', ch = gc(); 
    }
    template<class T, class... Args> void read_unsigned(T& x, Args&... args){
        read_unsigned(x), read_unsigned(args...);
    }
    #define isletter(ch) ('a' <= ch && ch <= 'z')
    int read_string(char* s){
        char ch = gc(); int l = 0;
        while (!isletter(ch)) ch = gc();
        while (isletter(ch)) s[l++] = ch, ch = gc();
        s[l] = '\0'; return l;
    }
}using namespace Fast_Read; 

int _num[20];
template <class T> void write(T x, char sep = '\n'){	
	if (!x) {putchar('0'), putchar(sep); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar(sep);
}

#define read read_signed
#define reads read_string 
#define writes puts

#define maxn 2021
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

bool vis[maxn][maxn];
vector<int> row[maxn], col[maxn];
int n, m, k;
int a[maxn], b[maxn];
bool oka[maxn], okb[maxn];

pii lis[maxn << 1]; int cs = 0;

int g[maxn][maxn];
int main(){	
	read(n, m, k);
	rep(i, 1, n) read(a[i]), lis[++cs] = pii(a[i], i);
	rep(i, 1, n) read(b[i]), lis[++cs] = pii(b[i], i + n);
	rep(i, 1, n) rep(j, 1, n) g[i][j] = -1;
	sort(lis + 1, lis + 1 + cs);
	int x, y;
	rep(i, 1, m) read(x, y), row[x].pb(y), col[y].pb(x), g[x][y] = 0;
	ll ans = 0;
	per(i, cs, 1) {
		int v = lis[i].fi, id = lis[i].se;
		if (id <= n) {
			if (oka[id]) continue;
			int niceit = -1;
			for (auto it: row[id]) {
				if (!vis[id][it] && !okb[it] && b[it] == v) {
					niceit = it;
					break;
				}
			}
			if (niceit != -1) {
				ans += v;
				vis[id][niceit] = 1;
				g[id][niceit] = v;
				okb[niceit] = oka[id] = true;
			}
			else {
				for (auto it: row[id]) {
					if (!vis[id][it] && b[it] >= v) {
						vis[id][it] = 1;
						g[id][it] = v;
						ans += v;
						okb[it] = oka[id] = true;
						break;
					}
				}
			}
		}
		else {
			id -= n;
			if (okb[id]) continue;
			int niceit = -1;
			for (auto it: col[id]) {
				if (!vis[it][id] && !oka[it] && a[it] == v) {
					niceit = it;
					break;
				}
			}
			if (niceit != -1) {
				ans += v;
				vis[niceit][id] = 1;
				g[niceit][id] = v;
				oka[niceit] = okb[id] = true;
			}
			else {
				for (auto it: col[id]) {
					if (!vis[it][id] && a[it] >= v) {
						vis[it][id] = 1;
						g[it][id] = v;
						ans += v;
						oka[it] = okb[id] = true;
						break;
					}
				}
			}
		}
	}
	rep(i, 1, n) {
		rep(j, 1, n) {
			if (g[i][j] == -1) printf("- ");
			else printf("%d ", g[i][j]);
		}
		puts("");
	}
	printf("%lld\n", ans);
	return 0;
}


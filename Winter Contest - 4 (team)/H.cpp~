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
#define pb push_back
#define pc putchar
#define lowbit(x) (x & -x)
#define maxr 2000020
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

namespace Fast_Read{
    char buffer[maxr], *p1, *p2;
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

#define maxn 200020
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 128
#define P 19260817
#define bas 2333
#define ll long long int 

int n, m; char s[maxn];
int lis[maxn], cs = 0, len[maxn];
int has[maxn], mi[maxn];
int gethash(int l, int r) {
	return (has[r] + P - 1ll * has[l - 1] * mi[r - l + 1] % P) % P;
}

int vis[maxn], idx = 0;
pii dp[maxn];
pii DP(int pos){
	if (pos > n) return pos == n + 1 ? pii(0, 1) : pii(0, -1);
	if (vis[pos] == idx) return dp[pos];
	vis[pos] = idx;
	pii& ans = dp[pos]; ans = pii(0, -1);
	rep(i, 1, cs) {
		if (gethash(pos, pos + len[i] - 1) == lis[i]) {
			//cerr << "ok" << endl;
			pii dd = DP(pos + len[i]);
			if (dd.se == -1) continue;
			if (dd.fi == 1) {
				ans.fi = 1;
				if (ans.se == -1) ans.se = 0;
				ans.se += dd.se, ans.se %= 128;
			}
			else {
				if (ans.se == -1) ans = dd;
				else {
					ans.fi = 1;
					if (ans.se == -1) ans.se = 0;
					ans.se += dd.se, ans.se %= 128;
				}
			}
		}
	} 
	return ans;
}

int main(){
	mi[0] = 1;
	srep(i, 1, maxn) mi[i] = 1ll * bas * mi[i - 1] % P;
	int T; scanf("%d", &T);
	while (T--){
		idx++;
		cs = 0; scanf("%d%d", &n, &m);
		rep(i, 1, m) {
			scanf("%s", s); scanf("%s", s);
			int l = strlen(s), res = 0;
			srep(i, 0, l) res = (1ll * res * bas + s[i] - '0' + 1) % P; 
			lis[++cs] = res;
			len[cs] = l;
		}
		scanf("%s", s + 1);
		rep(i, 1, n) has[i] = (1ll * has[i - 1] * bas + s[i] - '0' + 1) % P; 
		pii d = DP(1); 
		if (d.se == -1) puts("nonono");
		else if (d.fi == 0) puts("happymorsecode");
		else printf("puppymousecat %d\n", d.se); 
	}
	return 0;
}


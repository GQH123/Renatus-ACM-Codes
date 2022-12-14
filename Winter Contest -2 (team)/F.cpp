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

#define read read_unsigned
#define reads read_string 
#define writes puts

#define maxn 31
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

int n, m;
int num[maxn][maxn];
int res[maxn][maxn];
int T = 1;
int l = maxn, r = 0, u = maxn, d = 0;
void dfs(int pos) {
	bool havok = false;
	int mx = -1;
	if (pos > 1) {
		int x = min(r - l + 1, d - u + 1), y = max(r - l + 1, d - u + 1);
		res[x][y] = max(res[x][y], pos - 1);
		if (pos - 1 <= res[x][y] - T) return;
	}
	rep(i, 1, n - pos + 1) rep(j, 1, m - pos + 1) {
		bool ok = true;
		rep(a, i, i + pos - 1) rep(b, j, j + pos - 1) {
			if (num[a][b]) {
				ok = false;
				goto fail;
			}
		}
		fail:;
		if (ok) {
			if (pos == 1) cerr << i << " " << j << endl;
			havok = true;
			rep(a, i, i + pos - 1) rep(b, j, j + pos - 1) {
				num[a][b] = 1;
			}
			int _l = l, _r = r, _u = u, _d = d;
			l = min(l, i), r = max(r, i + pos - 1), u = min(u, j), d = max(d, j + pos - 1);
			dfs(pos + 1);
			l = _l, r = _r, u = _u, d = _d;
			rep(a, i, i + pos - 1) rep(b, j, j + pos - 1) {
				num[a][b] = 0;
			}
		}
	}
	return;
}

int main(){
	/*
	for (n = 1; n <= maxn - 1; n++) {
		bool rush = false;
		for (m = n; m <= maxn - 1; m++) {
			int ans = rush ? n : dfs(1);
			if (ans == n) rush = 1;
			cerr << n << ", " << m << ": " << ans << endl;
			cout << n << ", " << m << ": " << ans << endl;
		}
	}
	*/
	n = m = 30;
	dfs(1);
	rep(i, 1, maxn - 1) {
		rep(j, i, maxn - 1) {
			rep(a, 1, i) rep(b, a, j) {
				res[i][j] = max(res[i][j], res[a][b]);
			}
		}
	}
	rep(i, 1, maxn - 1) {rep(j, i, maxn - 1) printf("%d, %d: %d\n", i, j, res[i][j]);}
	return 0;
}


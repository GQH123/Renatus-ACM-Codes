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

#define maxn 122
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 998244353
#define ll long long int 
#define mo(x) (x = x >= M ? x - M : x)

int inv[maxn * 10];
void init(){
	inv[0] = 0, inv[1] = 1;
	srep(i, 2, maxn) inv[i] = M - 1ll * M / i * inv[M % i] % M; 
	
	
	//srep(i, 1, maxn) cerr << inv[i] << ' '; cerr << endl;;
}

int n, s0, m;
int out[maxn];
int g[maxn][maxn];
vector<int> adj[maxn];

namespace DP_1{
	int dp1[maxn][maxn][maxn];
	int vis1[maxn][maxn][maxn];
	int idx1 = 0;
	int DP1(int x, int y, int l) {
		if (l == 0) return x == y;
		if (vis1[x][y][l] == idx1) return dp1[x][y][l];
		vis1[x][y][l] = idx1;
		int& ans = dp1[x][y][l]; ans = 0;
		
		// inv[out[x]]
		for (auto it: adj[x]) ans += DP1(it, y, l - 1), mo(ans);
		ans = 1ll * ans * inv[out[x]] % M;
		return ans;
	}
}

namespace DP_2{
	int dp2[maxn][maxn][maxn];
	int vis2[maxn][maxn][maxn];
	int idx2 = 0;
	int DP2(int st, int lim, int l) {
		if (st == lim) return 0;
		if (l == 0) return 1;
		if (vis2[st][lim][l] == idx2) return dp2[st][lim][l];
		vis2[st][lim][l] = idx2;
		int& ans = dp2[st][lim][l]; ans = 0;
		
		for (auto it: adj[st]){
			//if (it == lim) continue;
			ans += DP2(it, lim, l - 1), mo(ans);
		}
		ans = 1ll * ans * inv[out[st]] % M;
		return ans;
	}
}

int main(){
	init();
	DP_1 :: idx1++;
	DP_2 :: idx2++;

	read(n, s0, m);
	int x;
	rep(i, 1, n) {
		read(out[i]);
		rep(j, 1, out[i]) {
			read(x);
			g[i][x] = 1;
			adj[i].pb(x);
		}
	}
	
	int ans = 0;
	rep(p, 1, m) {
		rep(x, 1, n) {
			rep(y, 1, n) {	
				//int _ans = ans;
				if (!g[y][x]) continue;
				ans += 1ll * DP_1 :: DP1(s0, y, p - 1) * (1 + M - DP_2 :: DP2(x, y, m - p)) % M * x % M * inv[out[y]] % M;
				mo(ans);
				
				//if (ans != _ans) cerr << p << ' ' << x << ' ' << y << ' ' << (ans + M - _ans) % M << ' ' << m - p << endl;
				//if (ans != _ans) cerr << DP_1 :: DP1(s0, y, p - 1) << ' ' << (DP_2 :: DP2(x, y, m - p)) << ' ' << x << ' ' << inv[out[y]] << endl;
			}
		}
	}
	
	printf("%d\n", ans);
	return 0;
}


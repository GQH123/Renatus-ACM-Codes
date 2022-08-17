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

#define maxn 2020
#define maxm
#define maxs
#define maxb 31
#define inf 
#define eps
#define M 
#define ll long long int 

int ones[maxn][maxb];
int zeros[maxn][maxb];

ll cal(int l, int r){
	ll res = 0;
	srep(i, 0, maxb) if (ones[r][i] > ones[l - 1][i] && zeros[r][i] > zeros[l - 1][i]) res |= (1 << i); 
	return res;
}

/*
int last[maxb];
void DP(){
	srep(i, 0, maxb) last[i] = -1;
	rep(pos, 1, n) {
		rep(rest, 0, k) {
		
		}
		
	}
}
*/
bool judge(int pos, int x, ll v) {
	return cal(pos, x) > v;
}
int find(int l, int r, int x, ll v) {
	while (l != r) {
		int mid = ((r - l + 1) >> 1) + l;
		if (judge(mid, x, v)) l = mid;
		else r = mid - 1;
	}
	return l;
}


#define DP(i, j) dp[i][j]
/*
bool vis[maxn][maxn];
ll dp[maxn][maxn];
ll DP(int pos, int rest) {
	if (pos == 0) {
		return (rest) ? -1 : 0;
	}
	if (rest == 1) return cal(1, pos);
	if (vis[pos][rest]) return dp[pos][rest];
	vis[pos][rest] = 1;
	ll& ans = dp[pos][rest];
	ans = -1;
	ll now = pos, nowv = 0;
	while (1) {
		ll d = DP(now - 1, rest - 1);
		if (d != -1) ans = max(ans, DP(now - 1, rest - 1) + nowv);
		now = find(0, now, pos, nowv);
		if (!now) break;
		nowv = cal(now, pos);
	}
	return ans;
}
*/
int n, k, a[maxn];
ll dp[maxn][maxn];
pii que[maxn]; int cq = 0;
void solve(){
	rep(pos, 0, n) {
		bool fir = true;
		rep(rest, 0, k) {
		if (pos == 0) {
			dp[pos][rest] = (rest) ? -1 : 0;
			continue;
		}
		if (rest == 1) {dp[pos][rest] = cal(1, pos); continue;}
		//if (vis[pos][rest]) {dp[pos][rest] = dp[pos][rest]; continue;}
		//vis[pos][rest] = 1;
		ll& ans = dp[pos][rest];
		ans = -1;
		if (fir) {
			fir = false;
			ll now = pos, nowv = 0;
			cq = 0;
			que[++cq] = pii(now, nowv);
			while (1) {
				ll d = DP(now - 1, rest - 1);
				if (d != -1) ans = max(ans, DP(now - 1, rest - 1) + nowv);
				now = find(0, now, pos, nowv);
				if (!now) break;
				nowv = cal(now, pos);
				que[++cq] = pii(now, nowv);
			}
		}
		else {
			rep(i, 1, cq) {
				ll now = que[i].fi, nowv = que[i].se;
				ll d = DP(now - 1, rest - 1);
				if (d != -1) ans = max(ans, DP(now - 1, rest - 1) + nowv);
			}
		}
		}
	}
}
int main(){
	read(n, k);
	rep(i, 1, n) {
		read(a[i]);
		srep(j, 0, maxb) {
			ones[i][j] = ones[i - 1][j];
			zeros[i][j] = zeros[i - 1][j];
			if (a[i] & (1 << j)) ones[i][j] = ones[i - 1][j] + 1;
			else zeros[i][j] = zeros[i - 1][j] + 1;
		}
	}
	solve();
	write(DP(n, k));
	//DP();
	return 0;
}


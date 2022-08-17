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

#define maxn 3000021
#define maxm 200021
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 
#define ull unsigned ll

int n, m, pri[maxm], vis[maxn];
int pfac[maxn];
int dp[maxn];

int dpnxt[maxn];

multiset<int> s;

void work(){
	read(n, m);
	rep(i, 1, m) read(pri[i]);
	
	/*
	rep(i, 1, m) for (int j = pri[i]; j <= n; j += pri[i]) fac[j].pb(i); 
	*/
	
	rep(i, 1, n) pfac[i] = vis[i] = 0;
	rep(i, 1, m) for (int j = pri[i]; j <= n; j += pri[i]) pfac[j] = max(pfac[j], pri[i]), vis[j]++;
	
	int lim = n;
	rep(i, 1, n) {
		if (vis[i] == m) {
			lim = i - 1;
			break;
		}
	}
	
	int mi = lim;
	rep(i, 1, m) {
		mi = min(mi, lim / pri[i] * pri[i]);
	}
	
	dp[0] = 0; rep(i, 1, n) dp[i] = 0;
	
	per(i, lim, 1) {
		dpnxt[i] = mi;
		mi = min(mi, i - pfac[i]);
	}
	
	rep(i, 1, lim) dp[i] = dp[dpnxt[i]] + 1; 
	
	//rep(i, 1, n) printf("%d ", dp[i]); printf("\n");
	//fflush(stdout);
	
	/*
	rep(i, 1, n) {
		if (pfac[i].size() == m) break;
		
	}
	*/
	
	ull res = 0, mip = 1;
	per(i, n, 1) {
		res += mip * (ull)dp[i];
		mip = mip * (ull)23333;
	}
	printf("%llu\n", res);
	
	//rep(i, 1, n) pfac[i].clear();
}
int main(){
	int T; read(T);
	while (T--) work();
	return 0;
}


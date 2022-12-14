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

#define maxn 300021
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 998244353
#define ll long long int 
#define mo(x) (x = x >= M ? x - M : x)


int n, a[maxn], dp[maxn], suf[maxn];

int nxt[maxn];

int trans[maxn][2];


multiset<int> s;
void add(int x) {
	s.insert(x);
}
void rm(int x) {
	s.erase(s.lower_bound(x));
}
int get(){
	if (s.size() < 3) return -1;
	int x = *s.begin(); rm(x);
	int y = *s.begin(); rm(y);
	int rs = *s.begin();
	add(x), add(y);
	return rs;
}

int main(){
	read(n); rep(i, 1, n) read(a[i]);
	int lasteq = n;
	
	dp[n] = 1; rep(i, 1, n) nxt[i] = n + 1;
	nxt[a[n]] = n;
	
	suf[n] = 1;
	
	rep(i, 1, n) add(nxt[i]);
	
	per(i, n - 1, 1) {
	
		rm(nxt[a[i]]);
		nxt[a[i]] = i;
		add(nxt[a[i]]);
		
		int& ans = dp[i]; ans = dp[i + 1];
		
		if (a[i] == a[i + 1]) { lasteq = i; suf[i] = suf[i + 1] + ans, mo(suf[i]); continue; }
		
		if (i == n - 1) {
			suf[i] = suf[i + 1] + ans, mo(suf[i]);
			continue;
		}
		
		int nr = get();
		
		if (nr != -1 && lasteq >= nr) {
			ans += suf[nr], mo(ans);
			ans += (M - suf[lasteq + 1]), mo(ans);
		}
		if (lasteq >= i + 2 && nr > i + 2) {
			ans += dp[i + 2], mo(ans);
		}
		
		suf[i] = suf[i + 1] + ans, mo(suf[i]);
	}
	
	printf("%d\n", dp[1]);
	return 0;
}


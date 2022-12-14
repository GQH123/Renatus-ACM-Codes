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

#define maxn 800020
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 
#define end END


int n; 
pii lis[maxn];

int c[maxn];
int get(int x) {
	int ans = 0;
	while (x) {
		ans = max(ans, c[x]);
		x -= lowbit(x);
	}
	return ans;
}
void mod(int x, int v) {
	while (x <= 2 * n) {
		c[x] = max(c[x], v);
		x += lowbit(x);
	}
}

bool operator < (pii a, pii b){
	return a.fi < b.fi && a.se > b.se;
}

int seg[maxn], cs = 0;
pii end[maxn];
int main(){
	read(n);
	rep(i, 1, n) read(lis[i].fi, lis[i].se);
	rep(i, 1, n) {
		if ((lis[i].fi <= n && lis[i].se <= n) || (lis[i].fi > n && lis[i].se > n)) {
			puts("-1");
			return 0;
		}
	}
	sort(lis + 1, lis + 1 + n);
	rep(i, 1, n) {	
		int d = get(lis[i].se);
		if (d > 1) {
			puts("-1");
			return 0;
		}
		mod(lis[i].se, d + 1);
	}
	
	//lis[n + 1] = pii(n + 1, n << 2);
	rep(i, 1, n) {
		int _i = i;
		while (i < n && lis[i] < lis[i + 1]) i++;
		seg[++cs] = i - _i + 1;
	}
	int odd = 0, even = 0;
	
	int now = 1;
	rep(i, 1, cs) {
		int nxt = now + seg[i] - 1;
		end[i] = pii(now, nxt);
		now = nxt + 1;
	}
	assert(now == n + 1);
	rep(i, 2, cs) {
		if (lis[end[i - 1].fi].se > lis[end[i].se].se) {
			puts("-1");
			return 0; 
		}
	}
	rep(i, 3, cs) { 
		if (lis[end[i - 2].se].se < lis[end[i].fi].se) {	
			puts("-1");
			return 0; 
		} 
	}
	rep(i, 1, cs) {
		if (i & 1) odd += seg[i];
		else even += seg[i];
	}
	printf("%d\n", min(even, odd)); 
	return 0;
}


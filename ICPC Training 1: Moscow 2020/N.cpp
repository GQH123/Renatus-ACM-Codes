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

#define maxn
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 1000000007
#define mo(x) (x = (x >= M) ? (x - M) : x)
#define ll long long int 

int n, a[maxn], m;

pii get_inter(int l, int r) {
	if (l < r) {
		int l = lower_bound(a + 1, a + 1 + n, l) - a, r = upper_bound(a + 1, a + 1 + n, r) - a - 1;
		if (l > r) return pii(-1, -1);
		else return pii(l, r);
	}
	else {
		pii a = get_inter(l, m), b = get_inter(0, r);
		if (a.fi > a.se && b.fi > b.se) return pii(-1, -1);
		if (a.fi > a.se) return b;
		if (b.fi > b.se) return a;
		return pii(a.fi, b.se);
	}
}

int two[maxn];
int main(){
	read(n, m); m <<= 1;
	rep(i, 1, n) read(a[i]), a[i] <<= 1;
	two[0] = 1; srep(i, 1, maxn) two[i] = two[i - 1] << 1, mo(two[i]);
	sort(a + 1, a + 1 + n);
	if (n <= 3) {
		printf("0");
		return 0;
	}
	else {
		ll sum_single_c = 2;
		ll sum_single_p = 2 * n;
		ll sum_fail_1 = 0;
		
		rep(i, 1, n) {
			pii k = get_inter(a[i] + 1, (a[i] + (m >> 1) - 1) % m);
			if (k.fi == -1) continue;
			int num = 0;
			if (k.fi <= k.se) num = k.se - k.fi + 1;
			else num = (n - k.fi + 1) + k.se;
			
			sum_fail_1 += two[num], mo(sum_fail_1);
			sum_fail_1 += M - 1,    mo(sum_fail_1);
		}
		
		rep(i, 1, n) {
			int l = a[i] + (m >> 1), r = a[i == n ? 1 : i + 1] + (m >> 1);
			pii k = get_inter(l, r);
			if (k.fi == -1) continue;
			int num = 0;
			if (k.fi <= k.se) num = k.se - k.fi + 1;
			else num = (n - k.fi + 1) + k.se;
			
			
			
			sum_fail_2 += num - 1, mo(sum_fail_2);
		}
		
		ll all = two[n];
		ll ans = all - 2 * sum_fail_1 + sum_fail_2 + 
	}
	return 0;
}


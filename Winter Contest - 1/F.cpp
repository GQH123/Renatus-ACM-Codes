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

#define maxn 500020
#define maxm
#define maxa 40000020
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

int n, p, q, m, b, c, t;
bool judge(int x, int y) {
	return 1ll * p * y <= 1ll * q * x && 1ll * p * x <= 1ll * q * y;
}
int a[maxa];
pii bb[maxn];
int main(){
	read(n, p, q, m, b, c, t);
	rep(i, 1, m) read(a[i]), bb[i] = pii(a[i], i);
	sort(bb + 1, bb + 1 + m);
	srep(i, 1, m) {
		//if (1ll * p * b[i].fi <= 1ll * q * b[i + 1].fi && 1ll * p * b[i + 1].fi <= 1ll * q * b[i].fi) {
		if (judge(bb[i + 1].fi, bb[i].fi)){
			printf("%d %d\n", min(bb[i].se, bb[i + 1].se), max(bb[i].se, bb[i + 1].se));
			return 0;
		}
	}
	int mx = 0, mx2 = -1, smx = 0, smx2 = -1;
	srep(i, m, n) {
		a[i + 1] = (1ll * b * a[i] + c) % t + 1; 
		int d = a[i + 1];
		if (d >= mx) smx = mx, smx2 = mx2, mx = d, mx2 = i + 1;
		else if (d > smx) smx = d, smx2 = i + 1;
		
		int pos = lower_bound(bb + 1, bb + 1 + m, pii(a[i + 1], -1)) - bb;
		if (pos <= m) {
			if (judge(bb[pos].fi, a[i + 1])) {
				printf("%d %d\n", min(bb[pos].se, i + 1), max(bb[pos].se, i + 1));
				return 0;
			}
		}
		pos--;
		if (pos >= 1){
			if (judge(bb[pos].fi, a[i + 1])) {
				printf("%d %d\n", min(bb[pos].se, i + 1), max(bb[pos].se, i + 1));
					return 0;
			}
		}
	}
	if (mx2 != -1 && smx2 != -1 && judge(mx, smx)) {
		printf("%d %d\n", min(mx2, smx2), max(mx2, smx2));
		return 0;
	}
	printf("-1");
	return 0;
}


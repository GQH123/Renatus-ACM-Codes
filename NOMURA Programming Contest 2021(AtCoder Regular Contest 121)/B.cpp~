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

#define maxn 300020
#define maxm
#define maxs
#define maxb
#define inf 1ll << 55
#define eps
#define M 
#define ll long long int 

ll get_nearest(ll* a, int n, ll x) {
	if (!n) return inf;
	int p = lower_bound(a + 1, a + 1 + n, x) - a;
	return min(abs(x - a[p]), abs(x - a[p - 1]));
}
int index(char ch) {
	if (ch == 'R') return 0;
	else if (ch == 'G') return 1;
	else return 2;
}

ll lis[3][maxn]; int cs[3];
int odd[3], co = 0;

int main(){	
	int n;
	scanf("%d", &n);
	char ch[5]; ll x;
	rep(i, 1, n << 1) {
		scanf("%lld%s", &x, ch);
		lis[index(ch[0])][++cs[index(ch[0])]] = x;
	}
	rep(i, 0, 2) if (cs[i] & 1) odd[++co] = i; 
	assert(co == 0 || co == 2);
	if (co == 0) {
		puts("0");
		return 0;
	}
	else {
		int x = odd[1], y = odd[2], z = 3 - x - y;
		ll res = inf;
		rep(i, 0, 2) {
			sort(lis[i] + 1, lis[i] + 1 + cs[i]);
			lis[i][0] = -inf, lis[i][cs[i] + 1] = inf;
		}
		//lis[0][0] = lis[1][0] = lis[2][0] = -inf;
		//lis[0][cs[0] + 1] = lis[1][cs[1] + 1] = lis[2][cs[2] + 1] = inf;
		
		
		rep(i, 1, cs[x]) {
			res = min(res, get_nearest(lis[y], cs[y], lis[x][i]));
		}
		rep(i, 1, cs[y]) {
			res = min(res, get_nearest(lis[x], cs[x], lis[y][i]));
		}
		
		ll tmp1 = inf, tmp2 = inf;
		rep(i, 1, cs[x]) {
			tmp1 = min(tmp1, get_nearest(lis[z], cs[z], lis[x][i]));
		}
		rep(i, 1, cs[y]) {
			tmp2 = min(tmp2, get_nearest(lis[z], cs[z], lis[y][i]));
		}
		res = min(tmp1 + tmp2, res);
		
		cout << res << endl;
	}
	
	return 0;
}


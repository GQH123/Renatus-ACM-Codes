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

#define maxn 2022
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

int a[maxn], b[maxn], c[maxn << 1]; int n, m;

ll sum[2];
vector<int> g[2];


#define bound 29

int main(){
	
	int T; cin >> T;
	while (T--) {
		
		n = m = sum[0] = sum[1] = 0;
		ll tot = 0;
		
		cin >> n;
		rep(i, 0, bound) a[i] = (1 << i), tot += a[i];
		srep(i, (bound + 1), n) a[i] = (1 << bound) + i - bound, tot += a[i];
		
		srep(i, 0, n) cout << a[i] << ' '; cout << endl;
		
		srep(i, 0, n) cin >> b[i], tot += b[i];
		
		//assert(tot % 2 == 0);
		
		tot >>= 1;
		
		srep(i, 0, n) c[m++] = b[i];
		srep(i, 0, n - (bound + 1)) c[m++] = a[n - 1 - i];
		sort(c, c + m);
		
		//srep(i, 0, m) cout << c[i] << ' '; cout << endl;
		
		srep(i, 0, m) {
			if (sum[0] <= sum[1]) sum[0] += c[i], g[0].pb(c[i]);
			else sum[1] += c[i], g[1].pb(c[i]);
		}
		
		ll d = tot - sum[0];
		
		int now = 0;
		while (d) {
			if (d & 1) g[0].pb(a[now]); 
			now++;
			d >>= 1;
		}
		
		for (auto it: g[0]) cout << it << ' '; cout << endl;
		
		g[0].clear(), g[1].clear();
	}
	return 0;
}


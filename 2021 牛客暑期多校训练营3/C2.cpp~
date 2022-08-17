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

#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

/*
namespace KM{
	#define maxn 521
	#define inf 2000000000
	int n, visl[maxn], visr[maxn], parl[maxn], parr[maxn];
	int pre[maxn], que[maxn], head = 0, tail = 0;
	ll e[maxn][maxn], slk[maxn], potl[maxn], potr[maxn];
	bool find_augment_path(int y) {
		if (visr[y] = 1, parr[y]) return !(visl[que[++head] = parr[y]] = 1);
		while (y) swap(y, parl[parr[y] = pre[y]]); return true;
	}
	void bfsl(int s){
		fill(slk + 1, slk + 1 + n, inf);
		fill(visl + 1, visl + 1 + n, 0);
		fill(visr + 1, visr + 1 + n, 0);
		head = tail = 0, visl[que[++head] = s] = 1;
		while (true){
			while (head != tail) {
				int x = que[++tail]; ll d = -1;
				rep(y, 1, n) {
					if (!visr[y] && slk[y] >= (d = potl[x] + potr[y] - e[y][x])) {
						if (pre[y] = x, d) slk[y] = d;
						else if (find_augment_path(y)) return;
					}
				}
			}
			ll d = inf;
			rep(y, 1, n) if (!visr[y] && d > slk[y]) d = slk[y];
			rep(x, 1, n) if (visl[x]) potl[x] -= d;
			rep(y, 1, n) if (visr[y]) potr[y] += d; else slk[y] -= d;
			rep(y, 1, n) if (!visr[y] && !slk[y] && find_augment_path(y)) return;
		}
	}
	ll solve(){
		rep(y, 1, n) potr[y] = *max_element(e[y] + 1, e[y] + 1 + n); rep(x, 1, n) bfsl(x);
		ll res = 0; rep(x, 1, n1) res += e[parl[x]][x]; return res;
	} 
	void recover(){
		fill(e + 1, e + 1 + n * n, 0);
		fill(parl + 1, parl + 1 + n, 0);
		fill(parr + 1, parr + 1 + n, 0);
		fill(potl + 1, potl + 1 + n, 0);
		fill(potr + 1, potr + 1 + n, 0);
		fill(pre +  1, pre  + 1 + n, 0); 
	}
}
*/

namespace HK {
	// :: comment Both left and right points starts from 1.
	#define maxn 521
	#define maxm 300021
	int n, n1, n2; // :: delete 'm'
	struct edge{
		int next, to;
		edge(int next, int to) : next(next), to(to){}
		edge(){}
	}e[maxm << 1];
	int h[maxn], cnt = 1;
	void Add_Edge(int x, int y) {
		e[++cnt] = edge(h[x], y), h[x] = cnt;
	}
	int depl[maxn], depr[maxn], parl[maxn], parr[maxn];
	int que[maxn], head = 0, tail = 0; // :: modify 'que[maxn]' -> 'que[maxn << 1]'
	bool bfsl(){
		bool augment_path_found = false;
		head = tail = 0;
		rep(i, 1, n1) if (!parl[i]) depl[i] = 1, que[++head] = i; else depl[i] = 0;
		rep(i, 1, n2) depr[i] = 0;
		while (head != tail) {
			int x = que[++tail];
			erep(i, x) {
				int op = e[i].to;
				if (depr[op]) continue; depr[op] = depl[x] + 1;
				if (parr[op]) depl[parr[op]] = depr[op] + 1, que[++head] = parr[op];
				else augment_path_found = true;
			}
		}
		return augment_path_found;
	}
	int vis[maxn], idx = 0;
	bool dfsl(int x) { // :: comment dfsl() always acts on left side
		erep(i, x) { int op = e[i].to;
			if (depr[op] == depl[x] + 1 && vis[op] != idx) { vis[op] = idx;
				if (!parr[op] || dfsl(parr[op])) { parr[op] = x, parl[x] = op; return true; }
			}
		} return false; //XXX
	}
	int solve(){
		int res = 0; while (bfsl()) { idx++; rep(i, 1, n1) if (!parl[i]) res += dfsl(i); }
		return res;
	}
	void recover(){ // :: add 'recover()' 
		fill(   h + 1,    h + 1 + n1, 0);
		fill(depl + 1, depl + 1 + n1, 0);
		fill(parl + 1, parl + 1 + n1, 0);
		fill(depr + 1, depr + 1 + n2, 0);
		fill(parr + 1, parr + 1 + n2, 0);
		fill( vis + 1,  vis + 1 + n2, 0);
		idx = n = n1 = n2 = 0; cnt = 1;
	}
};


#define maxn 2021 

int n, m, k, cs = 0, a[maxn], b[maxn];
pii lis[maxn << 1];
bool ok[maxn][maxn];

int lisl[maxn], lisr[maxn], cl = 0, cr = 0;

int main(){
	read(n, m, k);
	rep(i, 1, n) read(a[i]), lis[++cs] = pii(a[i], i);
	rep(i, 1, n) read(b[i]), lis[++cs] = pii(b[i], n + i);
	sort(lis + 1, lis + 1 + cs);
	int x, y; rep(i, 1, m) read(x, y), ok[x][y] = 1;
	ll ans = 0;
	per(i, cs, 1) {
		int v = lis[i].fi; cl = cr = 0;
		while (i >= 1 && lis[i].fi == v) {
			int x = lis[i].se;
			if (x <= n) lisl[++cl] = x;
			else lisr[++cr] = x - n;
			i--;
		} i++;
		if (!cl || !cr) {
			ans += 1ll * (cl + cr) * v;
			continue;
		}
		HK :: n1 = cl, HK :: n2 = cr, HK :: n = cl + cr;
		rep(i, 1, cl) rep(j, 1, cr) if (ok[lisl[i]][lisr[j]]) HK :: Add_Edge(i, j); 
		ans += 1ll * (cl + cr - HK :: solve()) * v;
		HK :: recover();
	}
	printf("%lld\n", ans);
	return 0;
}


/*
int m;
namespace Sample{
#define read read_unsigned
void build(){
int x, y; read(n1, n2, m), n = n1 + n2; rep(i, 1, m) read(x, y), Add_Edge(x, y);
}
void sample(){
build(); printf("%d\n", solve());
rep(i, 1, n1) printf("%d ", parl[i] ? parl[i] : 0); printf("\n");
}
}

int main(){
	int T = 10;
	while (T--) {
		Sample :: sample();
		recover();
	} 
}
*/


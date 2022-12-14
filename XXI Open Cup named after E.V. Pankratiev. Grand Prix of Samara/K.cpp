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
#define inf 
#define eps
#define M 
#define ll long long int 

int n, m;
struct ele{
	int c, v, id;
	ele(int c, int v, int id) : c(c), v(v), id(id){}
	ele(){}
}p[maxn], good[maxn], bad[maxn], _bad[maxn];
/*
bool bad_cmp(const ele a, const ele b) {
	return a.c - a.v < b.c - b.v;
}
*/
bool good_cmp(const ele a, const ele b) {
	//if (a.c == b.c) return !bad_cmp(a, b);
	//else return a.c < b.c;
	//return a.v == b.v ? a.c < b.c : a.v > b.v;
	return a.c < b.c;
}
bool bad_cmp(const ele a, const ele b) {
	return a.v == b.v ? a.c < b.c : a.v > b.v;
}

bool vis[maxn];

int main(){
	int T; read(T);
	while (T--){
		int x, y, cg = 0, cb = 0;
		read(n, m);
		rep(i, 1, n) vis[i] = 0;
		rep(i, 1, n) read(x, y), y = min(y, m + x - 2), p[i] = ele(x, y, i); 
		rep(i, 1, n) {
			if (p[i].v >= p[i].c) good[++cg] = p[i];
			else bad[++cb] = p[i];
		}
		//sort(good + 1, good + 1 + cg, good_cmp);
		sort(bad + 1, bad + 1 + cb, bad_cmp);
		rep(i, 1, cb) _bad[i] = bad[i];
		sort(_bad + 1, _bad + 1 + cb, good_cmp);
		
		ll pool = m;
		rep(i, 1, cg) pool += good[i].v - good[i].c, vis[good[i].id] = 1;
		rep(i, 1, cb) {
			if (pool < bad[i].c) {
				puts("NO");
				goto fail;
			}
			else {
				pool -= (bad[i].c - bad[i].v); 
				vis[bad[i].id] = 1;
			}
		}
		/*
		int ptr = cb;
		while (ptr >= 1 && vis[_bad[ptr].id]) ptr--;
		rep(i, 1, cb) {
			if (vis[bad[i].id]) continue;
			while (ptr >= 1 && pool - (bad[i].c - bad[i].v) < _bad[ptr].c) { 
				if (_bad[ptr].id == bad[i].id || vis[_bad[ptr].id]) {ptr--; continue;}
				if (pool < _bad[ptr].c) {
					puts("NO");
					goto fail;
				}
				else {
					pool -= (_bad[ptr].c - _bad[ptr].v); 
					vis[_bad[ptr].id] = 1;
				}
				ptr--;
				while (i <= cb && vis[bad[i].id]) i++;
			}
			if (!vis[bad[i].id]) {
				if (pool < bad[i].c) {
					puts("NO");
					goto fail;
				}
				else {
					pool -= (bad[i].c - bad[i].v); 
					vis[bad[i].id] = 1;
				}
			}
			while (ptr >= 1 && vis[_bad[ptr].id]) ptr--;
		}
		*/
		
		puts("YES");
		fail:;
	}
	return 0;
}


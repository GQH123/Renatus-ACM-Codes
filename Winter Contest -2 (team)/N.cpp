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

#define maxm 220
#define maxd 6020
#define maxs
#define maxb
#define eps
#define M 
#define ll long long int 
#define inf 2000000020

int d, b, m, a[maxm];

struct SegmentTree {
    struct Node {
        int mx;
    } T[maxd << 2];
    void maintain(int o) {
        T[o].mx = min(T[o<<1].mx, T[o<<1^1].mx);
    }
    void update(int o, int L, int R, int p, int v) {
        if(L == R) { T[o].mx = v; return; }
        int mid = L + R >> 1;
        if(p <= mid) update(o<<1, L, mid, p, v);
        else update(o<<1^1, mid+1, R, p, v);
        maintain(o);
    }
    int ask(int o, int L, int R, int l, int r) {
        if(L == l && R == r) return T[o].mx;
        int mid = L + R >> 1;
        if(r <= mid) return ask(o<<1, L, mid, l, r);
        else if(mid < l) return ask(o<<1^1, mid+1, R, l, r);
        else return min(ask(o<<1, L, mid, l, mid), ask(o<<1^1, mid+1, R, mid+1, r));
    }
    void init(int o, int L, int R){
    	if (L == R) {T[o].mx = 0; return;}
    	int mid = ((R - L) >> 1) + L;
    	init(o << 1, L, mid);
    	init(o << 1 ^ 1, mid + 1, R);
    	maintain(o);
    }
}t[maxm];

bool judge(int x){
	rep(i, 1, m) t[i].init(1, 0, d);
	rep(p, 0, d) {
		rep(i, 1, m) {
			if (i == 1) {
				if (p <= x) t[i].update(1, 0, d, p, abs(p - a[1]));
				else t[i].update(1, 0, d, p, inf);
			}
			else {
				int dp = t[i - 1].ask(1, 0, d, max(0, p - x), p);
				if (dp != inf) dp += abs(p - a[i]);
				t[i].update(1, 0, d, p, dp);
			}
		}
	}
	//cerr << x << ":" << t[m].ask(1, 0, d, d - x, d) << endl;
	return t[m].ask(1, 0, d, d - x, d) <= b;
}

int solve(int l, int r) {
	while (l < r) {
		int mid = ((r - l) >> 1) + l;
		if (judge(mid)) r = mid;
		else l = mid + 1;
	}
	return l;
}

int main(){
	read(d, b, m); rep(i, 1, m) read(a[i]);  sort(a + 1, a + 1 + m);
	printf("%d\n", solve(1, d));
	return 0;
}


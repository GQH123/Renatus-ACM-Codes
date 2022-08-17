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

#define maxn 400020
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

int miadd[maxn << 2], miv[maxn << 1], smiv[maxn << 1], add[maxn << 1];
int qx, qy, qd;

inline void upd(int o, int v, int u) {
	if (v > miv[o]) smiv[o] = 
}
void pu(int o) {
	
}
void pd(int o) {
	
}
void mod(int l, int r, int o) {
	pd(o);
	if (qx <= l && r <= qy) {
		add[o] += 1;
		miv[o] += 1;
		smiv[o] += 1;
		return;
	}
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) mod(l, mid, o << 1);
	if (qy > mid) mod(mid + 1, r, o << 1 | 1);
	pu(o);
}
void modmax(int l, int r, int o) {
	pd(o);
	if (qx <= l && r <= qy){
	}
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) modmax(l, mid, o << 1);
	if (qy > mid) modmax(mid + 1, r, o << 1 | 1);
	pd(o);
}
int getmx(int l, int r, int o) {
	pd(o);
	if (qx <= l && r <= qy) {
		return miv[o];
	}
	int mid = ((r - l) >> 1) + l, ans = 0;
	if (qx <= mid) ans = max(ans, getmx(l, mid, o << 1));
	if (qy > mid) ans = max(ans, getmx(mid + 1, r, o << 1 | 1));
	return ans;
}
void solve(int l, int r, int o) {
	pd(o);
	if (l == r) {
		printf("%d ", a[o]);
		return;
	}
	int mid = ((r - l) >> 1) + l;
	solve(l, mid, o << 1), solve(mid + 1, r, o << 1 | 1);
}

int n, m, a[maxn];
int main(){
	scanf("%d%d", &n, &m);
	rep(i, 1, n) scanf("%d", a + i);
	rep(i, 1, m) {
		scanf("%d%d", &x, &y);
	}
	return 0;
}


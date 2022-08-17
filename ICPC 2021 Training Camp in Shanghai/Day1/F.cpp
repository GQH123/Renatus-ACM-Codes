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

int n, m, a[maxn];
struct ele{
	int div, x, y;
	ele(int div, int x, int y) : div(div), x(x), y(y){}
	ele(){}
}tag[maxn << 2];

int qx, qy, qd, mx[maxn << 2];
inline void pu(int l, int r, int o) {
	if (l < r) mx[o] = max(mx[o << 1] < tag[o << 1].div ? tag[o << 1].x : tag[o << 1].y, mx[o << 1 | 1] < tag[o << 1 | 1].div ? tag[o << 1 | 1].x : tag[o << 1 | 1].y);
	tag[o] = ele(mx[o], -1, mx[o]);
}
void init(int l, int r, int o) {
	if (l == r) {
		mx[o] = a[l];
		pu(l, r, o);
		return;
	}
	int mid = ((r - l) >> 1) + l;
	init(l, mid, o << 1), init(mid + 1, r, o << 1 | 1);
	pu(l, r, o); 
}
inline ele merge(ele x, ele y) { // x < y
	return ele(x.div, x.x == y.div ? y.y : y.x, x.y == y.div ? y.y : y.x);
}
inline void pd(int o) {
	if (tag[o].x != -1) {
		tag[o << 1] = merge(tag[o << 1], tag[o]);
		//mx[o << 1] = tag[o << 1].y;
		tag[o << 1 | 1] = merge(tag[o << 1 | 1], tag[o]);
		//mx[o << 1 | 1] = tag[o << 1 | 1].y;
		
		mx[o] = (mx[o] < tag[o].div) ? tag[o].x : tag[o].y;
		tag[o] = ele(mx[o], -1, mx[o]);
	}
}

void mod(int l, int r, int o) {
	pd(o);
	if (qx <= l && r <= qy){
		if (mx[o] == qd) {
			//mx[o] = qd + 1; 
			tag[o] = ele(qd, qd, qd + 1);
		}
		else {
			//mx[o] = qd; 
			tag[o] = ele(qd, qd, qd);
		}
		
		//pu(l, r, o);
		return;
	}
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) mod(l, mid, o << 1);
	if (qy > mid) mod(mid + 1, r, o << 1 | 1);
	pu(l, r, o);
}
int getmx(int l, int r, int o) {
	pd(o);
	if (qx <= l && r <= qy){
		pu(l, r, o);
		return mx[o];
	}
	int mid = ((r - l) >> 1) + l, ans = 0;
	if (qx <= mid) ans = max(ans, getmx(l, mid, o << 1));
	if (qy > mid) ans = max(ans, getmx(mid + 1, r, o << 1 | 1));
	pu(l, r, o);
	return ans;
}
void solve(int l, int r, int o) {
	pd(o);
	if (l == r) {
		printf("%d ", mx[o]);
		pu(l, r, o);
		return;
	}
	int mid = ((r - l) >> 1) + l;
	solve(l, mid, o << 1), solve(mid + 1, r, o << 1 | 1);
	pu(l, r, o);
}

int main(){ 
	scanf("%d%d", &n, &m);
	rep(i, 1, n) scanf("%d", a + i);
	init(1, n, 1);
	rep(i, 1, m) {
		scanf("%d%d", &qx, &qy);
		qd = getmx(1, n, 1);
		mod(1, n, 1);
		//solve(1, n, 1); printf("\n");
	}
	solve(1, n, 1); //printf("\n");
	return 0;
}


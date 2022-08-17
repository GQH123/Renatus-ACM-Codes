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

#define maxn 200020
#define maxm
#define maxs
#define maxb
#define inf  1 << 30
#define eps
#define M 
#define ll long long int 


int mi[maxn << 2];
int qx, qy, qd;
int tag[maxn << 2];
void init(int l, int r, int o) {
	mi[o] = inf, tag[o] = -1;
	if (l == r) return;
	int mid = ((r - l) >> 1) + l;
	init(l, mid, o << 1), init(mid + 1, r, o << 1 | 1);
}
inline void pu(int o) {
	mi[o] = min(mi[o << 1], mi[o << 1 | 1]);
}
inline void pd(int o) {
	if (tag[o] != -1) {
		int& k = tag[o];
		tag[o << 1] = tag[o << 1 | 1] = k, mi[o << 1] = mi[o << 1 | 1] = k;
		k = -1;
	}
}
void mod(int l, int r, int o) {
	pd(o);
	if (qx <= l && r <= qy){
		tag[o] = qd;
		mi[o] = qd;
		return;
	}
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) mod(l, mid, o << 1);
	if (qy > mid) mod(mid + 1, r, o << 1 | 1);
	pu(o);
}
int get(int l, int r, int o) {
	pd(o);
	if (qx <= l && r <= qy) {
		return mi[o];
	}
	int mid = ((r - l) >> 1) + l, mi = inf;
	if (qx <= mid) mi = min(mi, get(l, mid, o << 1));
	if (qy > mid) mi = min(mi, get(mid + 1, r, o << 1 | 1));
	return mi;
}

int n, m;
struct ele{
	int l, r, id;
	ele(int l, int r, int id) : l(l), r(r), id(id){}
	ele(){}
	bool operator < (const ele b) const{
		return (r - l == b.r - b.l) ? id > b.id : r - l < b.r - b.l;
	}
}p[maxn], lis[maxn];


int ans[maxn];
int main(){
	int x, y;
	read(n, m);
	rep(i, 1, m) read(x, y), p[i] = lis[i] = ele(x, y, i);
	sort(lis + 1, lis + 1 + m);
	init(1, n, 1);
	int ptr = m, nowans = 0;
	per(l, n, 1) {
		while (ptr && lis[ptr].r - lis[ptr].l + 1 >= l) {
			qx = lis[ptr].l, qy = lis[ptr].r;
			int mi = get(1, n, 1);
			if (mi >= lis[ptr].id) {
				while (mi != inf) {
					qx = p[mi].l, qy = p[mi].r, qd = inf;
					nowans -= qy - qx + 1;
					mod(1, n, 1);
					
					qx = lis[ptr].l, qy = lis[ptr].r;
					mi = get(1, n, 1);
				}
				qx = lis[ptr].l, qy = lis[ptr].r, qd = lis[ptr].id;
				nowans += qy - qx + 1;
				mod(1, n, 1);
			}
			ptr--;
		}
		ans[l] = nowans;
	}
	rep(i, 1, n) printf("%d\n", ans[i]);
	return 0;
}


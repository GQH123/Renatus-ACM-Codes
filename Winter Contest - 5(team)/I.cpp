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

#define maxn 4000020
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 


int add[maxn << 2], mx[maxn << 2];
int qx, qy, qd;
inline void pd(int o) {
	if (add[o]) {
		int& k = add[o];
		add[o << 1] += k, add[o << 1 | 1] += k;
		mx[o << 1] += k, mx[o << 1 | 1] += k;
		k = 0;
	}
}
inline void pu(int o) {
	mx[o] = max(mx[o << 1], mx[o << 1 | 1]);
}
void mod(int l, int r, int o) {
	pd(o);
	if (qx <= l && r <= qy){
		add[o] += qd;
		mx[o] += qd;
		return;
	}
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) mod(l, mid, o << 1);
	if (qy > mid) mod(mid + 1, r, o << 1 | 1);
	pu(o);
}
int get(int l, int r, int o) {
	pd(o);
	if (l == r) {
		return mx[o] >= 0 ? l : -1;
	}
	int mid = ((r - l) >> 1) + l;
	if (mx[o << 1 | 1] >= 0) return get(mid + 1, r, o << 1 | 1);
	else return get(l, mid, o << 1);
}

int n;
int main(){
	read(n);
	int op, x;
	int lim = 2000020;
	rep(i, 0, lim) {
		qx = i, qy = lim, qd = -1;
		mod(0, lim, 1);
	}
	while (n--){
		read(op, x);
		if (op == 1){
			qx = x, qy = lim, qd = 1;
			mod(0, lim, 1);
		}
		else {
			qx = x, qy = lim, qd = -1;
			mod(0, lim, 1);
		}
		printf("%d\n", get(0, lim, 1) + 1);
	}
	return 0;
}


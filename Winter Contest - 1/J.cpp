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
    #define isletter(ch) (ch == '(' || ch == ')')
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

#define maxn 300020
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

int n, m;
char s[maxn];

int sum[maxn << 2], mi[maxn << 2], mx[maxn << 2]; bool rev[maxn << 2];
int qx, qy, qd;
inline void pu(int o) {
	mi[o] = min(mi[o << 1], sum[o << 1] + mi[o << 1 | 1]);
	mx[o] = max(mx[o << 1], sum[o << 1] + mx[o << 1 | 1]);
	sum[o] = sum[o << 1] + sum[o << 1 | 1];
}
inline void pd(int o){
	if (rev[o]) {
		rev[o << 1] ^= 1, rev[o << 1 | 1] ^= 1;
		rev[o] = 0;
		swap(mx[o << 1], mi[o << 1]), swap(mx[o << 1 | 1], mi[o << 1 | 1]);
		sum[o << 1] = -sum[o << 1], sum[o << 1 | 1] = -sum[o << 1 | 1];
		mx[o << 1] = -mx[o << 1], mi[o << 1] = -mi[o << 1];
		mx[o << 1 | 1] = -mx[o << 1 | 1], mi[o << 1 | 1] = -mi[o << 1 | 1];
	}
}
void init(int l, int r, int o) {
	if (l == r) {
		if (s[l] == '(') sum[o] = mx[o] = 1, mi[o] = 0;
		else sum[o] = mi[o] = -1, mx[o] = 0;
		return;
	}
	int mid = ((r - l) >> 1) + l;
	init(l, mid, o << 1), init(mid + 1, r, o << 1 | 1);
	pu(o);
}
void mod(int l, int r, int o) {
	pd(o);
	if (qx <= l && r <= qy) {
		rev[o] ^= 1;
		sum[o] = -sum[o];
		mx[o] = -mx[o], mi[o] = -mi[o];
		swap(mx[o], mi[o]);
		return;
	}
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) mod(l, mid, o << 1);
	if (qy > mid) mod(mid + 1, r, o << 1 | 1);
	pu(o);
}
/*
int c[maxn];
int mod(int x){	
	while (x <= n) {
		c[x] ^= 1;
		x += lowbit(x);
	}
}
int get(int x){
	int ans = 0;
	while (x) {
		ans ^= c[x];
		x -= lowbit(x);
	}
	return ans;
}
*/

int main(){
	read(n, m);
	reads(s + 1);
	init(1, n, 1);
	int x, y;
	rep(i, 1, m) {
		read(qx), read(qy);
		mod(1, n, 1);
		if (sum[1] == 0 && mi[1] >= 0) puts("yes");
		else puts("no");
	}
	
	/*
	int x, y;
	rep(i, 1, m) {
		read(x), read(y);
		mod(x), mod(y + 1);
	}
	int val = 0;
	rep(i, 1, n) {
		if (get(i)) s[i] = (s[i] == '(') ? ')' : '(';
		if (s[i] == '(') val++;
		else val--;
		if (val < 0) {
			puts("no");
			return 0;
		}
	}
	if (val) {
		puts("no");
		return 0;
	}
	puts("yes");
	*/
	return 0;
}


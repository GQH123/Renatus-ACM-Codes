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
    #define isletter(ch) ('0' <= ch && ch <= '1')
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

#define maxn 1000021
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

#define get GET


char s[maxn];


int kb[maxn];

int n, tag[maxn << 2], qx, qy, qd;
bool hav[maxn << 2];

void pd(int o) {
	if (tag[o] != -1) {
		hav[o << 1] = hav[o << 1 | 1] = tag[o];
		tag[o << 1] = tag[o << 1 | 1] = tag[o];
		tag[o] = -1;
	}
}
void pu(int o) {
	hav[o] = hav[o << 1] | hav[o << 1 | 1];
}
void init(int l, int r, int o) {
	tag[o] = -1;
	if (l == r) {
		hav[o] = kb[l];
		return;
	}
	int mid = ((r - l) >> 1) + l;
	init(l, mid, o << 1), init(mid + 1, r, o << 1 | 1), pu(o);
}
int getl(int l, int r, int o) {
	if (l == r) return hav[o] ? l : -1;
	pd(o);
	int mid = ((r - l) >> 1) + l;
	if (hav[o << 1]) return getl(l, mid, o << 1);
	return getl(mid + 1, r, o << 1 | 1);
}
int getr(int l, int r, int o) {
	if (l == r) return hav[o] ? l : -1;
	pd(o);
	int mid = ((r - l) >> 1) + l;
	if (hav[o << 1 | 1]) return getr(mid + 1, r, o << 1 | 1);
	return getr(l, mid, o << 1);
}
void mod(int l, int r, int o) {
	if (l != r) pd(o);
	if (qx <= l && r <= qy) {
		tag[o] = hav[o] = qd;
		return;
	}
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) mod(l, mid, o << 1);
	if (qy > mid) mod(mid + 1, r, o << 1 | 1);
	pu(o);
}

int out[maxn], cs = 0;

int main(){
	read(n);
	int l = reads(s + 1);
	int ptr = n;
	per(i, l, 1) {
		kb[ptr] = s[i] - '0';
		ptr--;
	}
	per(i, ptr, 1) kb[i] = 0;
	
	init(1, n, 1);
	
	out[++cs] = 1;
	
	ptr = 1;
	while (true) {
		int lp = getl(1, n, 1);
		if (lp == n) break; 
		int rp = getr(1, n, 1);
		
		qx = rp + 1, qy = n, qd = 1;
		mod(1, n, 1);
		qx = qy = rp, qd = 0;
		mod(1, n, 1);
		
		lp = getl(1, n, 1);
		if (lp > ptr) {
			out[++cs] = 0;
			ptr++;
			continue;
		}
		else {
			out[++cs] = 1;
			
			qx = rp + 1, qy = n, qd = 0;
			mod(1, n, 1);
			qx = qy = rp, qd = 1;
			mod(1, n, 1);
			
			qx = qy = lp, qd = 0;
			mod(1, n, 1);
			
			ptr++;
			continue;
		}
	}
	
	
	rep(i, 1, cs) printf("%d", out[i]);
	
	return 0;
}


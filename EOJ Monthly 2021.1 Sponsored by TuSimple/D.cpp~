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

#define maxn 6000020
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 1000000007
#define ll long long int 
#define mo(x) (x = (x >= M) ? (x - M) : x)

ll fac[maxn], ifac[maxn], inv[maxn];
void init(){
	fac[0] = ifac[0] = inv[1] = 1;
	srep(i, 1, maxn) fac[i] = fac[i - 1] * i % M;
	srep(i, 2, maxn) inv[i] = M - M / i * inv[M % i] % M;
	srep(i, 1, maxn) ifac[i] = ifac[i - 1] * inv[i] % M;
}
ll cal(int m, int n) {
	if (m < n) return 0;
	return fac[m] * ifac[m - n] % M * ifac[n] % M;
}

/*
int c[2][maxn];
void add(int id, int x, int v) {	
	while (x < maxn) {
		c[id][x] += v, mo(c[id][x]);
		x += lowbit(x);
	}
}
int get(int id, int x){
	int ans = 0;
	while (x) {
		ans += c[id][x], mo(ans);
		x -= lowbit(x);
	}
	return ans;
}
*/
/*
int c[maxn];
void add(int x, int v) {	
	while (x < maxn) {
		c[x] += v, mo(c[x]);
		x += lowbit(x);
	}
}
int get(int x){
	int ans = 0;
	while (x) {
		ans += c[x], mo(ans);
		x -= lowbit(x);
	}
	return ans;
}
*/

int sum[maxn << 2], add[maxn << 2], qx, qy, qd;
void pd(int l, int r, int o) {
	if (add[o]) {
		int& k = add[o]; int mid = ((r - l) >> 1) + l;
		add[o << 1] += k, mo(add[o << 1]);
		add[o << 1 | 1] += k, mo(add[o << 1 | 1]);
		sum[o << 1] += 1ll * (mid - l + 1) * k % M, mo(sum[o << 1]);
		sum[o << 1 | 1] += 1ll * (r - mid) * k % M, mo(sum[o << 1 | 1]);
		k = 0;
	}
}
void pu(int o) {
	sum[o] = sum[o << 1] + sum[o << 1 | 1], mo(sum[o]);
}
int get(int l, int r, int o){
	pd(l, r, o);
	if (qx <= l && r <= qy) return sum[o];
	int mid = ((r - l) >> 1) + l, ans = 0;
	if (qx <= mid) ans += get(l, mid, o << 1), mo(ans);
	if (qy > mid) ans += get(mid + 1, r, o << 1 | 1), mo(ans);
	return ans;
}
void mod(int l, int r, int o) {
	pd(l, r, o);
	if (qx <= l && r <= qy) {
		add[o] += qd, mo(add[o]);
		sum[o] += 1ll * (r - l + 1) * qd % M, mo(sum[o]);
		return;
	}
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) mod(l, mid, o << 1);
	if (qy > mid) mod(mid + 1, r, o << 1 | 1);
	pu(o);
}
int n, m, lisp[maxn], liss[maxn];
int main(){
	read(n, m);
	if (m == 1) {
		write(1);
		return 0;
	}
	
	
	/*
	add(1, 1), add(m + 1, -1);
	lisp[0] = 1;
	rep(i, 1, n) {
		int ans = get(i);
		add(i + 1, ans), add(i + m + 1, -ans);
		lisp[i] = ans;
	}
	rep(i, 1, n) cerr << lisp[i] << ' '; cerr << endl;
	
	srep(i, 0, maxn) c[i] = 0;
	
	add(1, 1), add(m, -1);
	liss[0] = 1;
	rep(i, 1, n) {
		int ans = get(i);
		add(i + 1, ans), add(i + m, -ans);
		liss[i] = ans;
	}
	rep(i, 1, n) cerr << liss[i] << ' '; cerr << endl;
	
	int ans = 0;
	rep(i, 1, n - m + 1) {
		ans += 1ll * lisp[i - 1] * liss[n - m - i + 1] % M, mo(ans);
	}
	write(ans);
	*/
	/*
	int ptr = 1;
	add(m, 1), add(m + 1, M-1);
	per(i, n - 1, 1) {
		int f1 = get(ptr) + M - get(ptr - 1), sum = get(ptr + m - 1) + M - get(ptr - 1); mo(f1), mo(sum), ptr++;
		add(ptr, f1), add(ptr + m - 1, M-f1);
		add(ptr + m - 1, sum), add(ptr + m, M-sum);
		if (i == 1) write(get(ptr));
	}
	*/
	/*
	add(m, 1), add(m + 1, -1);
	rep(i, m, n) {
		int ans = get(i);
		add(i + 1, ans), add(i + m + 1, -ans);
		if (i == n) write(ans);
	}
	*/
	qx = qy = m, qd = 1;
	mod(1, n << 1, 1);
	int ptr = 1;
	per(i, n - 1, 1) {
		qx = qy = ptr;
		int f1 = get(1, n << 1, 1);
		qx = ptr, qy = ptr + m - 1; 
		int sum = get(1, n << 1, 1);
		ptr++;
		qx = ptr, qy = ptr + m - 2, qd = f1;
		mod(1, n << 1, 1);
		qx = qy = ptr + m - 1, qd = sum;
		mod(1, n << 1, 1);
		if (i == 1) {
			qx = qy = ptr;
			write(get(1, n << 1, 1));
		}
	}
	return 0;
}


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

#define maxn 200022
#define maxm
#define maxs
#define maxb
#define maxk 622
#define inf 
#define eps
#define M 
#define ll long long int 

struct ST{
	int n;
	ll sum[maxn << 2]; int left[maxn << 2];
	inline void init(int l, int r, int o) {
		sum[o] = 0, left[o] = (maxn >> 1) + 1;
		if (l == r) return;
		int mid = ((r - l) >> 1) + l;
		init(l, mid, o << 1), init(mid + 1, r, o << 1 | 1);
	}
	inline void pu(int o) {
		sum[o] = sum[o << 1] + sum[o << 1 | 1];
		left[o] = min(left[o << 1], left[o << 1 | 1]);
	}
	void mod(int l, int r, int o, int qx, int qd) { // +1
		if (l == r) {
			sum[o] += qd;
			left[o] = l;
			return; 
		}
		int mid = ((r - l) >> 1) + l;
		if (qx <= mid) mod(l, mid, o << 1, qx, qd);
		else mod(mid + 1, r, o << 1 | 1, qx, qd);
		pu(o);
	}
	ll get_sum(int l, int r, int o, int qx, int qy) {
		if (qx <= l && r <= qy) return sum[o];
		int mid = ((r - l) >> 1) + l; ll ans = 0;
		if (qx <= mid) ans += get_sum(l, mid, o << 1, qx, qy);
		if (qy > mid) ans += get_sum(mid + 1, r, o << 1 | 1, qx, qy);
		return ans;
	}
	int get_near(int l, int r, int o, int qx) {
		if (l == r) return l;
		int mid = ((r - l) >> 1) + l;
		int lleft = n + 1, rleft = n + 1;
		if (qx <= mid) {
			lleft = get_near(l, mid, o << 1, qx);
			rleft = left[o << 1 | 1];
			return min(lleft, rleft);
		}
		else {
			return get_near(mid + 1, r, o << 1 | 1, qx);
		}
	}
}S1, S2; // S1 -> > 0, S2 -> all

int ufs[maxk][maxn << 2];
int find_root(int k, int x) {
	return ufs[k][x] = (ufs[k][x] == x) ? x : find_root(k, ufs[k][x]);
}
int jump(int k, int x) {
	while (1) {
		x = find_root(k, x);
		int d = S2.get_sum(1, S2.n, 1, x + 1, x + k);
		if (d > 0) {
			ufs[k][x] = x + k;
			x = x + k;
		}
		else break;
	}
	return x;
}
int horizon(int k, int x) {
	int pos = S1.get_near(1, S1.n, 1, x + 1);
	pos -= x;
	pos = k * ((pos - 1) / k + 1);
	return pos + x;
}

int k = 500;

void mod(int x, int y){ 
	if (y > 0) S1.mod(1, S1.n, 1, x, y);
	S2.mod(1, S2.n, 1, x, 1);
}
void work(int d) {
	int x = 0, res = 0;
	while (d > k) {
		ll dec = S1.get_sum(1, S1.n, 1, x + 1, x + d);
		int num = S2.get_sum(1, S2.n, 1, x + 1, x + d);
		x += d;
		res++;
		if (num == 0) goto done;
		d -= dec;
	}
	while (d > 0) {
		int ju = jump(d, x);
		int ho = horizon(d, x);
		
		if (ju < ho) {
			res += (ju - x) / d + 1;
			break;
		}
		else {
			ll dec = S1.get_sum(1, S1.n, 1, x + 1, ho);
			res += (ho - x) / d;
			d -= dec;
			x = ho;
		}
	}
	done:printf("%d\n", res);
}

int main(){
	S1.n = S2.n = 200000;
	S1.init(1, S1.n, 1);
	S2.init(1, S2.n, 1);
	
	
	rep(i, 0, 200000) rep(j, 1, k) ufs[j][i] = i;
	
	int m;
	read(m);
	int op, x, y;
	rep(i, 1, m) {
		read(op);
		if (op == 1) {
			read(x, y);
			mod(x, y);
		}
		else {
			read(x);
			work(x);
		}
	}
	return 0;
}


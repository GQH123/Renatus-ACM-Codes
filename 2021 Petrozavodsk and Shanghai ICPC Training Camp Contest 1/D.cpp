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
#define ll long long

#define int ll
#define double ll 

namespace LC{
	struct Seg{
		double k, b;
		Seg(){}
		Seg(int k, int b) : k(k), b(b){}
		double gety(int x) {return k * x + b;}
	}s[maxn << 2]; 
	int m, op, cnt, X0, Y0, X1, Y1, ans, v[maxn << 2];
	inline int sig(double x) {return !x ? 0 : (x > 0 ? 1 : -1); }
	void ins(int x, int a, int b, int c, int d, int p) {
		if (c <= a && b <= d) {
			if (sig(s[p].gety(a) - s[v[x]].gety(a)) > 0
				&& sig(s[p].gety(b) - s[v[x]].gety(b)) > 0) {v[x] = p; return;}
			if (sig(s[p].gety(a) - s[v[x]].gety(a)) <= 0
				&& sig(s[p].gety(b) - s[v[x]].gety(b)) <= 0) return;
			if (a == b) return;
		}
		int mid = (a + b) >> 1;
		if (c <= mid) ins(x << 1, a, mid, c, d, p);
		if (d > mid) ins(x << 1 | 1, mid + 1, b, c, d, p);
	}
	void ask(int x, int a, int b, int c) {
		if (sig(s[ans].gety(c) - s[v[x]].gety(c)) < 0) ans = v[x];
		else if (!sig(s[ans].gety(c) - s[v[x]].gety(c)) && ans > v[x]) ans = v[x];
		if (a == b) return;
		int mid = (a + b) >> 1;
		c <= mid ? ask(x << 1, a, mid, c) : ask(x << 1 | 1, mid + 1, b, c);
	}
}

namespace LC2{
	struct Seg{
		double k, b;
		Seg(){}
		Seg(int k, int b) : k(k), b(b){}
		double gety(int x) {return k * x + b;}
	}s[maxn << 2]; 
	int m, op, cnt, X0, Y0, X1, Y1, ans, v[maxn << 2];
	inline int sig(double x) {return !x ? 0 : (x > 0 ? 1 : -1); }
	void ins(int x, int a, int b, int c, int d, int p) {
		if (c <= a && b <= d) {
			if (sig(s[p].gety(a) - s[v[x]].gety(a)) > 0
				&& sig(s[p].gety(b) - s[v[x]].gety(b)) > 0) {v[x] = p; return;}
			if (sig(s[p].gety(a) - s[v[x]].gety(a)) <= 0
				&& sig(s[p].gety(b) - s[v[x]].gety(b)) <= 0) return;
			if (a == b) return;
		}
		int mid = (a + b) >> 1;
		if (c <= mid) ins(x << 1, a, mid, c, d, p);
		if (d > mid) ins(x << 1 | 1, mid + 1, b, c, d, p);
	}
	void ask(int x, int a, int b, int c) {
		if (sig(s[ans].gety(c) - s[v[x]].gety(c)) < 0) ans = v[x];
		else if (!sig(s[ans].gety(c) - s[v[x]].gety(c)) && ans > v[x]) ans = v[x];
		if (a == b) return;
		int mid = (a + b) >> 1;
		c <= mid ? ask(x << 1, a, mid, c) : ask(x << 1 | 1, mid + 1, b, c);
	}
}

int n, mx[maxn];
struct ele{
	int t, l, id;
	ele(int t, int l, int id) : t(t), l(l), id(id){}
	ele(){}
}lis[maxn], _lis[maxn];
bool cmp1(const ele a, const ele b) {
	return a.l < b.l;
}
bool cmp2(const ele a, const ele b) {
	return mx[a.t] < mx[b.t];
}
int num[maxn]; 
ll suf[maxn];
int rev[maxn];
ll res[maxn];
signed main(){
	LC :: s[0].b = 0;
	LC2 :: s[0].b = 0;
	read(n);
	rep(i, 1, n) read(lis[i].t, lis[i].l), lis[i].id = i, mx[lis[i].t] = max(mx[lis[i].t], lis[i].l), _lis[i] = lis[i]; 
	rep(i, 1, n) if (lis[i].l == mx[lis[i].t]) num[lis[i].t]++;
	sort(lis + 1, lis + 1 + n, cmp1);
	sort(_lis + 1, _lis + 1 + n, cmp2);
	rep(i, 1, n) rev[lis[i].id] = i;
	per(i, n, 1) suf[i] = suf[i + 1] + lis[i].l;//suf[i] = suf[i + 1] + (num[lis[i].t] == 1 ? 0 : lis[i].l);
	//ll sum = 0;
	rep(i, 1, n) {
		if (_lis[i].l == mx[_lis[i].t] && num[_lis[i].t] == 1) {
			//sum += _lis[i].l;
			continue;
		}
		int _mx = mx[_lis[i].t];
		LC :: s[++LC :: cnt] = LC :: Seg(_mx,  -_lis[i].l);
		LC :: ins(1, 1, n, 1, rev[_lis[i].id], LC :: cnt);
		
		LC2 :: s[++LC2 :: cnt] = LC2 :: Seg(_mx,  0);
		LC2 :: ins(1, 1, n, rev[_lis[i].id], n, LC2 :: cnt);
	}
	//if (!LC :: cnt) {
		/*
		rep(k, 1, n) {
			printf("%lld\n", suf[1]);
		}
		*/
	//}
	//else {
		rep(k, 1, n) {
			LC :: X0 = k; LC :: ans = 0; LC :: ask(1, 1, n, LC :: X0);
			LC2 :: X0 = k; LC2 :: ans = 0; LC2 :: ask(1, 1, n, LC2 :: X0);
			//printf("%lld\n", LC :: s[LC :: ans].gety(k) + suf[k]);
		 	res[k] = max(LC :: s[LC :: ans].gety(k) + suf[k], LC2 :: s[LC2 :: ans].gety(k) + suf[k + 1]);
		 	res[k] =  max(res[k], res[k - 1]);
		}
	//}
	rep(k, 1, n) printf("%lld\n", res[k]);
	
	return 0;
}
























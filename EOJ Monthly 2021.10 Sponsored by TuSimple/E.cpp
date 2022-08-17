#pragma GCC optimize(3)

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

#define maxn 600021
#define maxm
#define maxs
#define maxb 32
#define maxa maxb * maxn
#define inf 
#define eps
#define M 
#define ll long long int 
#define ls(x) ch[x][0]
#define rs(x) ch[x][1]

int n, K, a[maxn];


int ch[maxa][2];
int u[maxa], s[maxa];

vector<int> vv[maxa];
//int vv[maxa];
int ct = 0, root = 0;

void init(){
	root = ++ct;
	s[ct] = u[ct] = ls(ct) = rs(ct) = 0;
}

void mod(int v, int dd) {
	int x = root; s[x] += dd;
	per(i, maxb - 1, 0) {
		int d = ((v >> i) & 1);
		if (!ch[x][d]) ch[x][d] = ++ct, s[ct] = u[ct] = ls(ct) = rs(ct) = 0;
		x = ch[x][d];
		s[x] += dd;
	}
	u[x] += dd;
}

void mod2(int v, int dd) {
	int x = root; s[x] += dd;
		if (dd == 1) vv[x].pb(v);
		else vv[x].pop_back();
	per(i, maxb - 1, 0) {
		int d = ((v >> i) & 1);
		if (!ch[x][d]) ch[x][d] = ++ct, s[ct] = u[ct] = ls(ct) = rs(ct) = 0;
		x = ch[x][d];
		s[x] += dd;
			if (dd == 1) vv[x].pb(v);
			else vv[x].pop_back();
	}
	u[x] += dd;
}

struct edge{
	int next, to;
	edge(int next, int to) : next(next), to(to){}
	edge(){}
}e[maxn << 1];
int cnt = 1, h[maxn];
void Add_Edge(int x, int y) {
	e[++cnt] = edge(h[x], y);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x);
	h[y] = cnt;
}
/*
int get_rank(int k, int v) { //? ^ k < v
	int num = 0, x = root;
	per(i, maxb - 1, 0) {
		if (!x) return num;
		int dk = ((k >> i) & 1);
		int dv = ((v >> i) & 1);
		if (dk == 0) {
			if (dv == 0) {
				x = ls(x);
				continue;
			}
			else {
				num += s[ls(x)];
				x = rs(x);
				continue;
			}
		}
		else {
			if (dv == 0) {
				x = rs(x);
				continue;
			}
			else {
				num += s[rs(x)];
				x = ls(x);
				continue;
			}
		}
	}
	return num;
}
*/
int lis[maxn], cs = 0;

//int _k, _v;
bool cat(int k, int v, bool op) {
	//if (!x || !s[x] || d == -1) return true;
	int x = root;
	per(d, maxb - 1, 0) {
		if (!x) return true;
		int dk = ((k >> d) & 1);
		int dv = ((v >> d) & 1);
		if (dk == 0) {
			if (dv == 0) {
				if (cs + s[rs(x)] > K) return false;
				cs += s[rs(x)];
				x = ls(x);
			}
			else {
				x = rs(x);
			}
		}
		else {
			if (dv == 0) {
				if (cs + s[ls(x)] > K) return false;
				cs += s[ls(x)];
				x = rs(x);
			}
			else {
				x = ls(x);
			}
		}
	}
	return true;
}

bool cat2(int k, int v, bool op) {
	//if (!x || !s[x] || d == -1) return true;
	int x = root;
	per(d, maxb - 1, 0) {
		if (!x) return true;
		int dk = ((k >> d) & 1);
		int dv = ((v >> d) & 1);
		if (dk == 0) {
			if (dv == 0) {
				if (cs + s[rs(x)] > K) return false;
				for (auto it: vv[rs(x)]) {
					lis[++cs] = k ^ it;
				}
				x = ls(x);
			}
			else {
				x = rs(x);
			}
		}
		else {
			if (dv == 0) {
				if (cs + s[ls(x)] > K) return false;
				for (auto it: vv[ls(x)]) {
					lis[++cs] = k ^ it;
				}
				x = rs(x);
			}
			else {
				x = ls(x);
			}
		}
	}
	return true;
}



bool dfs(int x, int fa, int v) { // > v, push into pq
	if (!cat(a[x], v, false)) return false;
	mod(a[x], 1);
	erep(i, x) {
		int op = e[i].to;
		if (op == fa) continue;
		if (!dfs(op, x, v)) {
			mod(a[x], -1);
			return false;
		}
	}
	mod(a[x], -1);
	return true;
}

bool dfs2(int x, int fa, int v) { // > v, push into pq
	if (!cat2(a[x], v, false)) return false;
	mod2(a[x], 1);
	erep(i, x) {
		int op = e[i].to;
		if (op == fa) continue;
		if (!dfs2(op, x, v)) {
			mod2(a[x], -1);
			return false;
		}
	}
	mod2(a[x], -1);
	return true;
}

bool judge(int v) {
	cs = 0;
	return dfs(1, -1, v); // num > k return false, else true (<=)
}
bool judge2(int v) {
	cs = 0;
	return dfs2(1, -1, v); // num > k return false, else true (<=)
}
int solve(int l, int r) {
	while (l < r) {
		int mid = ((r - l) >> 1) + l;
		if (judge(mid)) r = mid;
		else l = mid + 1;
	}
	judge2(l);
	return l;
}

int main(){
	init();
	int x, y;
	read(n, K);
	rep(i, 2, n) read(x, y), Add_Edge(x, y);
	rep(i, 1, n) read(a[i]);
	
	x = solve(0, (1 << 30) - 1 + (1 << 30));
	//cerr << x << endl;
	int rest = K - cs;
	rep(i, 1, rest) lis[++cs] = x;
	sort(lis + 1, lis + 1 + cs);
	per(i, cs, 1) printf("%d\n", lis[i]);
	return 0;
}


#pragma GCC optimize (3)

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

#define maxn 400021
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

struct ele{
	int x, y, v, r, id;
	ele(int x, int y, int v, int r, int id) : x(x), y(y), v(v), r(r), id(id){}
	ele(){} 
	bool operator < (const ele b) const{
		return x == b.x ? y < b.y : x < b.x;
	}
}_p[maxn], p[maxn];

namespace KDT{
	#define ls ch[0][o]
	#define rs ch[1][o]
	
	int n, root, dir[4][maxn], ch[2][maxn], ct = 0; 
	ll sum[maxn];
	ele v[maxn];
	// up -> 0, down -> 1, left -> 2, right -> 3 
	bool cmpx(const ele a, const ele b){
		return a.x == b.x ? a.y < b.y : a.x < b.x;
	}
	bool cmpy(const ele a, const ele b){
		return a.y == b.y ? a.x < b.x : a.y < b.y;
	}
	void self(int o) {		
		dir[0][o] = dir[1][o] = v[o].y;
		dir[2][o] = dir[3][o] = v[o].x;
		sum[o] = v[o].v;
	}
	void pu(int o) {
		// pushup information below
		self(o);
		if (ls) {
			dir[0][o] = max(dir[0][o], dir[0][ls]);
			dir[1][o] = min(dir[1][o], dir[1][ls]);
			dir[2][o] = min(dir[2][o], dir[2][ls]);
			dir[3][o] = max(dir[3][o], dir[3][ls]);
			sum[o] += sum[ls];
		}
		if (rs){
			dir[0][o] = max(dir[0][o], dir[0][rs]);
			dir[1][o] = min(dir[1][o], dir[1][rs]);
			dir[2][o] = min(dir[2][o], dir[2][rs]);
			dir[3][o] = max(dir[3][o], dir[3][rs]); 
			sum[o] += sum[rs];
		}
	}
	void build(int l, int r, int& o, bool f){
		o = ++ct;	
		int mid = (l + r) >> 1;
		nth_element(p + l, p + mid, p + r + 1, f ? cmpy : cmpx);
		
		v[o] = p[mid];
		self(o);
		
		if (l <= mid - 1) build(l, mid - 1, ls, f ^ 1); 
		if (mid + 1 <= r) build(mid + 1, r, rs, f ^ 1);
		pu(o);
	}
	void insert(ele val, int& o, int f) {
		if (!o) {
			o = ++ct;
			v[o] = val;
			self(o);
			return;
		}
		insert(val, ch[f ? cmpy(v[o], val) : cmpx(v[o], val)][o], f ^ 1);
		pu(o);
	}
	ll dist(int x, int y, int _x, int _y) {
		return 1ll * (x - _x) * (x - _x) + 1ll * (y - _y) * (y - _y);
	}
	ll getfar(int x, int y, int o) {
		int resx = 0, resy = 0;
		resx = max(abs(dir[2][o] - x), abs(dir[3][o] - x));
		resy = max(abs(dir[0][o] - y), abs(dir[1][o] - y));
		return dist(resx, resy, 0, 0);
		/*
		return max(	max(dist(x, y, dir[0][o], dir[2][o]), dist(x, y, dir[0][o], dir[3][o])), 
                    max(dist(x, y, dir[1][o], dir[2][o]), dist(x, y, dir[1][o], dir[3][o])));
        It's toooo slow!!!
       */
    }
	ll getnear(int x, int y, int o) {
		int resx = 0, resy = 0;
		if (x < dir[2][o]) resx = dir[2][o] - x;
		if (x > dir[3][o]) resx = x - dir[3][o];
		if (y < dir[1][o]) resy = dir[1][o] - y;
		if (y > dir[0][o]) resy = y - dir[0][o];
		return dist(resx, resy, 0, 0);
	}
	ll query(int x, int y, int r, int o) { // query points with dist to (x, y) not greater than r
	 
		if (getnear(x, y, o) > 1ll * r * r) return 0;
		if (getfar(x, y, o) <= 1ll * r * r) return sum[o];
		
		ll ans = 0;
		if (dist(v[o].x, v[o].y, x, y) <= 1ll * r * r) ans += v[o].v;
		if (ls) ans += query(x, y, r, ls);
		if (rs) ans += query(x, y, r, rs);
		
		return ans;
	} 
}using namespace KDT;

void recover(){
	rep(o, 1, ct) ls = rs = 0; root = ct = 0; 
}

#define bound 30000
void work(){	
	int x, y, v, r;
	read(n);
	rep(i, 1, n) read(x, y, v, r), _p[i] = p[i] = ele(x, y, v, r, i); 
	rep(i, 1, n){ 
		insert(p[i], root, 0);
		printf("%lld\n", query(p[i].x, p[i].y, p[i].r, root));  
		if (i % bound == 0) {
			recover();
			build(1, i, root, 0);
		}
	}
} 

int main(){
	int T; read(T);  
	while (T--) work(), recover();  
	return 0;
}


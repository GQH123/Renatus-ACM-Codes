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

#define maxn
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 


bool Set[maxn << 1]; int qx, qy, sum[maxn << 2];
void init(int l, int r, int o) {
	Set[o] = sum[o] = 0; if (l == r) return; 
	int mid = ((r - l) >> 1) + l;
	init(l, mid, o << 1), init(mid + 1, r, o << 1 | 1);
}
inline void pd(int l, int r, int o) {
	if (Set[o]) {
		Set[o] = 0, Set[o << 1] = Set[o << 1 | 1] = 1;
		int mid = ((r - l) >> 1) + l;
		sum[o << 1] = mid - l + 1, sum[o << 1 | 1] = r - mid;
	}
}
inline void pu(int o) {
	sum[o] = sum[o << 1] + sum[o << 1 | 1];
}
void mod(int l, int r, int o) {
	pd(l, r, o);
	if (qx <= l && r <= qy) {
		Set[o] = 1;
		sum[o] = r - l + 1;
		return;
	}
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) mod(l, mid, o << 1);
	if (qy > mid) mod(mid + 1, r, o << 1 | 1);
	pu(o);
}
int get(int l, int r, int o) {
	if (qx <= l && r <= qy) return sum[o];
	int mid = ((r - l) >> 1) + l, ans = 0;
	if (qx <= mid) ans += get(l, mid, o << 1);
	if (qy > mid) ans += get(mid + 1, r, o << 1 | 1);
}

struct ele{
	int l, r, id, type;
	ele(int l, int r, int id, int type) : l(l), r(r), id(id), type(type){}
	ele(){}
	bool operator < (const ele b) const{
		return l == b.l ? r < b.r : l < b.l;
	}
}lis[maxn], res[maxn], q[maxn]; int cs = 0, cr = 0, head = 0;

void process(){
	head = 0;
	sort(lis + 1, lis + 1 + cs);
	rep(i, 1, cs){
		while (head && q[head].r >= lis[i].r) head--;
		q[++head] = lis[i];
	} 
	cr = head; rep(i, 1, cr) res[i] = q[i];
}

int n, k;
int cc[maxn];
int add(int x, int v) {
	while (x) {
		cc[x] += v;
		x -= lowbit(x);
	}
}
int cal(int x) {
	int ans = 0;
	while (x <= n + 1) {
		ans += cc[x];
		x += lowbit(x);
	}
	return ans;
}
void rev(){
	rep(i, 1, n + 1) cc[i] = 0;
}

#define maxb 61

struct bit{
	ele cond[maxn];
	vector<int> spe[maxn];
	vector<ele> fail0;
	void init(){
		rec(), init(1, n, 1);
		rep(i, 1, k) {
			if (cond[i].type) {
				qx = cond[i].l, qy = cond[i].r;
				mod(1, n, 1);
				add(qx, 1), add(qy + 1, -1);
			}
		}
		rep(i, 1, k) {
			if (cond[i].type) {
				qx = cond[i].l, qy = cond[i].r;
				mod(1, n, 1);
				add(qx, 1), add(qy + 1, -1);
			}
			else {
				qx = cond[i].l, qy = cond[i].r;
				mod(1, n, 1);
			}
		}
	} 
}proc[maxb];


int main(){
	int x, y; ll z;
	read(n, k);
	rep(i, 1, k) {
		read(x, y, z);
		srep(j, 0, maxb) {
			if (z & (1ll << j)) {
				cond[j][i] = ele(x, y, i, 1);
			}
			else {
				cond[j][i] = ele(x, y, i, 0);
			}
		}
	}
	srep(j, 0, maxb) proc[j].init();
	
	return 0;
}


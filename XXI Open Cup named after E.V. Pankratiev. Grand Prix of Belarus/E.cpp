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

#define maxn 1000020
#define maxm
#define maxs 
#define inf 
#define eps
#define M 
#define ll long long int 


bool Set[maxn << 1]; int qx, qy, qd, sum[maxn << 2]; vector<int> ssp[maxn << 2];
void init(int l, int r, int o) {
	Set[o] = sum[o] = 0; ssp[o].clear(); if (l == r) return; 
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
		ssp[o].pb(qd);
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
int cal(int l, int r, int o, int& cct, int& cid) { 
	cct += ssp[o].size();
	if (!ssp[o].empty()) cid = ssp[o][0];
	if (cct > 1) return -1;
	if (l == r) return cid;  
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) return cal(l, mid, o << 1, cct, cid);
	else return cal(mid + 1, r, o << 1 | 1, cct, cid);
}

struct ele{
	int l, r, id, type;
	ele(int l, int r, int id, int type) : l(l), r(r), id(id), type(type){}
	ele(){}
	bool operator < (const ele b) const{
		return l == b.l ? r < b.r : l < b.l;
	}
}lis[maxn], q[maxn]; int cs = 0, head = 0;

void process(){
	head = 0;
	sort(lis + 1, lis + 1 + cs);
	rep(i, 1, cs){
		while (head && q[head].r >= lis[i].r) head--;
		q[++head] = lis[i];
	} 
	cs = head; rep(i, 1, cs) lis[i] = q[i];
}

int n, k;
/*
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
*/

#define maxb 61

ele cond[maxn];
bool fail[maxn];
vector<int> spe[maxn]; 
int led[maxn], red[maxn];
void init(){
	cs = 0;
	rep(i, 1, k) spe[i].clear(); 
	fail0.clear();
	init(1, n, 1);
	rep(i, 1, k) {
		if (cond[i].type) {
			qx = cond[i].l, qy = cond[i].r, qd = i;
			mod(1, n, 1);
			add(qx, 1), add(qy + 1, -1);
		}
	}
	rep(i, 1, k) {
		if (!cond[i].type) {
			qx = cond[i].l, qy = cond[i].r;
			if (get(1, n, 1) == qy - qx + 1) {
				lis[++cs] = cond[i];
				fail[i] = 1;
			} 
		}
	}
	process();
	rep(i, 1, cs) led[i] = lis[i].l, red[i] = lis[i].r;
	rep(i, 1, n) {
		qx = i;
		int rs = get(1, n, 1, 0, -1);
		if (rs != -1) spe[rs].pb(i);
	}
}

struct query{
	int x, y; ll z;
	query(int x, int y, ll z) : x(x), y(y), z(z){}
	query(){}
}qq[maxn];
bool res[maxb][maxn];

int main(){
	int x, y; ll z;
	read(n, k);
	rep(i, 1, k) {
		read(x, y, z);
		qq[i] = query(x, y, z);
	}
	srep(j, 0, maxb) { rep(i, 1, k){
		x = qq[i].x, y = qq[i].y, z = qq[i].z;
			if (z & (1ll << j)) {
				cond[i] = ele(x, y, i, 1);
			}
			else {
				cond[i] = ele(x, y, i, 0);
			}
		}
		init();
		rep(i, 1, k) {
			if (cond[i].type) {
				if (!cs) res[j][i] = 1; 
				else { 
					int last = 1; bool ffail = 0;
					for (auto it: spe[i]) {
						int rrr = upper_bound(led + 1, led + 1 + cs, it) - led - 1;
						int lll = lower_bound(red + 1, red + 1 + cs, it) - red;
						if (lll <= last + 1) {
							last = rrr; 
						}
						else {
							ffail = 1;
							break;
						}
					}
					if (last < cs) ffail = 1;
					res[j][i] = 1 - ffail;
				}
			}
			else {
				if (!cs) res[j][i] = 1;
				else {
					if (cs == 1 && fail[i]) res[j][i] = 1; 
					else res[j][i] = 0;
				}
			}
		}
	}
	
	rep(i, 1, k) {
		int rs = 1;
		srep(j, 0, maxb) {
			rs = rs & res[j][i];
		}
		printf("%d", rs);
	}
	return 0;
}


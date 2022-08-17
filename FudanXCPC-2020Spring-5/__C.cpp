#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define pii pair<int, int>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define ll long long int 
#define pb push_back
#define lowbit(x) (x & -x)
#define maxr 20000020
#define maxn 200020
#define maxm
#define maxs
#define maxb
#define M 
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}
int _num[20];
template <class T> void write(T x){	
	if (!x) {putchar('0'), putchar('\n'); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar('\n');
} 

const int inf = 1000000000;



int n; ll k;

int lis[maxn << 3];
int cs = 0;

int c[maxn << 2];
void add(int x, int v){
	while (x <= cs){
		c[x] += v;
		x += lowbit(x);
	}
}
int get(int x){
	int ans = 0;
	while (x){
		ans += c[x];
		x -= lowbit(x);
	}
	return ans;
}

struct ele{
	int x, y;
	ele(int x, int y) : x(x), y(y){}
	ele(){}
	bool operator < (const ele b) const{
		return y < b.y;
	}
}p[maxn];

struct half{
	int type, x, y1, y2, d;
	half(int type, int x, int y1, int y2, int d) : type(type), x(x), y1(y1), y2(y2), d(d){}
	half(){}
	bool operator < (const half b) const{
		return (x == b.x) ? type > b.type : x < b.x;
	}
}h[maxn << 2];
int ch = 0;  

inline bool judge(int d){ //num >= k;
	ch = cs = 0;
	rep(i, 1, n) h[++ch] = half(0, p[i].x, p[i].y, p[i].y, 0);
	rep(i, 1, n){
		h[++ch] = half(1, p[i].x - d, p[i].y - d, p[i].y + d, 1);
		h[++ch] = half(1, p[i].x + d + 1, p[i].y - d, p[i].y + d, -1); 
	}
	rep(i, 1, n) lis[++cs] = p[i].y, lis[++cs] = p[i].y - d, lis[++cs] = p[i].y + d; 
	sort(lis + 1, lis + 1 + cs);
	cs = unique(lis + 1, lis + 1 + cs) - lis - 1;
	int now = 1;
	rep(i, 1, n) {
		while (now <= cs && lis[now] < h[i].y1) now++; h[i].y1 = now; 
	}
	now = 1;
	for (register int i = n + 1; i <= ch; i += 2){
		while (now <= cs && lis[now] < h[i].y1) now++; h[i].y1 = now;
		h[i + 1].y1 = h[i].y1;
	}
	now = 1;
	for (register int i = n + 1; i <= ch; i += 2){
		while (now <= cs && lis[now] < h[i].y2) now++; h[i].y2 = now;
		h[i + 1].y2 = h[i].y2;
	}
	sort(h + 1, h + 1 + ch); 
	ll num = 0;
	rep(i, 1, ch){
		half op = h[i];
		if (!op.type) {
			num += get(op.y1);
			//qx = qy = op.y1;
			//get(1, cs, 1, num);
		}
		else {
			add(op.y1, op.d);
			add(op.y2 + 1, -op.d);
			//qx = op.y1, qy = op.y2, qd = op.d;
			//mod(1, cs, 1);
		}
	}
	return ((num - n) >> 1) >= k;
}

int solve(int l, int r){
	while (l < r){
		int mid = ((r - l) >> 1) + l;
		if (judge(mid)) r = mid;
		else l = mid + 1;
	}
	return l;
}

int main(){
	
	freopen("C.in", "r", stdin);
		
	//ios :: sync_with_stdio(false), cin.tie(0); 
	int x, y; 
	read(n), read(k);
	rep(i, 1, n) read(x), read(y), p[i] = ele(x + y, x - y); 
	sort(p + 1, p + 1 + n);
	write(solve(1, inf));
	return 0;
}
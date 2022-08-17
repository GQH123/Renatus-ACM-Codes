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

int p[2][maxn];

struct half{
	int type, x, y1, y2, d;
	half(int type, int x, int y1, int y2, int d) : type(type), x(x), y1(y1), y2(y2), d(d){}
	half(){}
	bool operator < (const half b) const{
		return (x == b.x) ? type > b.type : x < b.x;
	}
}h[maxn << 2];
int ch = 0;
//clock_t t1, t2, tsum = 0, t3, t4;

int lower_bound(int l, int r, int x){	
	while (l < r){
		int mid = ((r - l) >> 1) + l;
		if (lis[mid] < x) l = mid + 1;
		else r = mid;
	}
	//assert(lis[l] == x);
	return l;
}
bool judge(int d){ //num >= k;

	
	ch = cs = 0;
	rep(i, 1, n) h[++ch] = half(0, p[0][i], p[1][i], p[1][i], 0);
	rep(i, 1, n){
		h[++ch] = half(1, p[0][i] - d, p[1][i] - d, p[1][i] + d, 1);
		h[++ch] = half(1, p[0][i] + d + 1, p[1][i] - d, p[1][i] + d, -1); 
	}
	rep(i, 1, n) lis[++cs] = p[1][i], lis[++cs] = p[1][i] - d, lis[++cs] = p[1][i] + d; 
	sort(lis + 1, lis + 1 + cs);
	cs = unique(lis + 1, lis + 1 + cs) - lis - 1;
	
	//t1 = clock();
	rep(i, 1, n) h[i].y1 = lower_bound(1, 1 + cs, h[i].y1); 
	for (register int i = n + 1; i <= ch; i += 2){
		h[i].y1 = lower_bound(1, 1 + cs, h[i].y1);  
		h[i + 1].y1 = h[i].y1; 
	}
	for (register int i = n + 1; i <= ch; i += 2){ 
		h[i].y2 = lower_bound(1, 1 + cs, h[i].y2); 
		h[i + 1].y2 = h[i].y2;
	}
	sort(h + 1, h + 1 + ch); 
	//t2 = clock();
	//tsum += (t2 - t1);
	
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
	//t3 = clock();
	freopen("C.in", "r", stdin);
		
	//ios :: sync_with_stdio(false), cin.tie(0); 
	int x, y; 
	read(n), read(k);
	rep(i, 1, n) read(x), read(y), p[0][i] = x + y, p[1][i] = x - y;
	write(solve(1, inf));
	//printf("%lf\n", (double)tsum / 1000000);
	//t4 = clock();
	//printf("%lf\n", (double)(t4 - t3) / 1000000);
	return 0;
}

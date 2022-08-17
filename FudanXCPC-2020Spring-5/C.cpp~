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
#define maxn 100020
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

const int inf = 400000000;



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

int h[4][maxn << 2];

/*
struct half{
	int x, y1, y2;
	char d;
	half(int x, int y1, int y2, char d) : x(x), y1(y1), y2(y2), d(d){}
	half(){}
}h[maxn << 2];
*/

int ch = 0;
int sor[maxn << 2];
bool cmp(int i, int j){
	return (h[0][i] == h[0][j]) ? (h[3][i] != 0) > (h[3][j] != 0) : h[0][i] < h[0][j];
}

inline bool judge(int d){ //num >= k;
	cs = 0; 
	rep(i, 1, n) h[0][i] = p[0][i], h[1][i] = p[1][i];
	for (register int i = n + 1, s = 1; i <= ch; i += 2, s++){ 
		h[0][i] = p[0][s] - d, h[1][i] = p[1][s] - d, h[2][i] = p[1][s] + d; 
		h[0][i + 1] = p[0][s] + d + 1, h[1][i + 1] = h[1][i], h[2][i + 1] = h[2][i]; 
	}
	rep(i, 1, n) lis[++cs] = p[1][i], lis[++cs] = p[1][i] - d, lis[++cs] = p[1][i] + d; 
	sort(lis + 1, lis + 1 + cs);
	cs = unique(lis + 1, lis + 1 + cs) - lis - 1;
	rep(i, 1, n) h[1][i] = lower_bound(lis + 1, lis + 1 + cs, h[1][i]) - lis; 
	for (register int i = n + 1; i <= ch; i += 2){
		h[1][i] = lower_bound(lis + 1, lis + 1 + cs, h[1][i]) - lis;
		h[2][i] = lower_bound(lis + 1, lis + 1 + cs, h[2][i]) - lis;
		h[1][i + 1] = h[1][i];
		h[2][i + 1] = h[2][i];
	}
	sort(sor + 1, sor + 1 + ch, cmp); 
	ll num = 0;
	rep(i, 1, ch){
		int op = sor[i];
		if (!h[3][op]) {
			num += get(h[1][op]);
			//qx = qy = op.y1;
			//get(1, cs, 1, num);
		}
		else {
			add(h[1][op], h[3][op]);
			add(h[2][op] + 1, -h[3][op]);
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
	ch = 3 * n;
	rep(i, 1, ch) sor[i] = i;
	rep(i, 1, n) read(x), read(y), p[0][i] = x + y, p[1][i] = x - y;  
	rep(i, 1, n) h[3][i] = 0;
	for (register int i = n + 1; i <= ch; i += 2){ 
		h[3][i] = 1;
		h[3][i + 1] = -1;
	}
	write(solve(1, inf));
	return 0;
}


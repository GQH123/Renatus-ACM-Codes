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
#define maxr 2000020
#define maxn 2000020
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

int n, m, a[maxn], b[maxn], lis[maxn], cs = 0, d[maxn];

int c[maxn];
int add(int x, int v){
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
void mod(int x, int v){
	add(x, v), add(x + 1, -v);
}
int _lower_bound(int l, int r, int v){
	int st = l, vst = get(st - 1);
	while (l < r){
		int mid = ((r - l) >> 1) + l;
		if (get(mid) - vst >= v) r = mid;
		else l = mid + 1;
	}
	return l;
}
int get_first_nonzero(int l, int r){
	while (l < r){
		int mid = ((r - l) >> 1) + l;
		if (b[mid] - d[mid] > 0) r = mid;
		else l = mid + 1;
	}
	return l;
}

void recover(){
	
}

int main(){
	
		freopen("F.in", "r", stdin);
		
	
	int T;
	read(T);
	while (T--){
		read(n); rep(i, 1, n) read(a[i]);
		read(m); rep(i, 1, m) read(b[i]);
		sort(a + 1, a + 1 + n);
		sort(b + 1, b + 1 + m);
		rep(i, 1, m){
			cs++;
			int now = b[i], _i = i;
			while (i <= m && b[i] == now) i++; i--;
			lis[cs] = i - _i + 1;
		}
		m = unique(b + 1, b + 1 + m) - b - 1;
		assert(m == cs);
		ll ans = 0;
		per(i, n, 1){ 
			if (b[x] - d[x] == b[x - 1]){
				int st = get_first_nonzero(1, cs);
				int x = _lower_bound(st, cs, m - a[i] + 1);
				int _num = get(x - 1);
				int _d = _num - (m - a[i]);
				d[x + 1]++;
				if (b[x - 1] - d[x - 1] == 0) {
					
				}
				mod(x - 1, _d), mod(x, -_d);
			}
			else d[x]++; 
		}
		recover();
	}
	return 0;
}


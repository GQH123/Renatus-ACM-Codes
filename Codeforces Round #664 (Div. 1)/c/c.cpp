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
#define ll long long int 
#define pb push_back
#define pc putchar
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn 600020
#define maxm 
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

int n; char s[maxn];

struct ele{
	int x, y, xx, yy, id;
	ele(int x, int y, int id) : x(x), y(y), id(id){}
	ele(){}
	bool operator < (const ele b) const{
		return (x == b.x) ? (y == b.y) ? id < b.id : y < b.y : x < b.x;
	}
}lis[maxn]; 

struct PREBIT{
	ll c[maxn]; 
	void add(int x, int v){
		while (x < maxn) {
			c[x] += v;
			x += lowbit(x);
		}
	}
	ll get(int x){
		ll ans = 0;
		while (x){
			ans += c[x];
			x -= lowbit(x);
		}
		return ans;
	}
	int num[maxn];
	void nadd(int x, int v){
		while (x < maxn) {	
			num[x] += v;
			x += lowbit(x);
		}
	}
	int nget(int x){
		int ans = 0;
		while (x){
			ans += num[x];
			x -= lowbit(x);
		}
		return ans;
	}
}RD, _LD, _RD;

struct SUFBIT{
	ll c[maxn]; 
	void add(int x, int v){
		while (x) {
			c[x] += v;
			x -= lowbit(x);
		}
	}
	ll get(int x){
		ll ans = 0;
		while (x < maxn){
			ans += c[x];
			x += lowbit(x);
		}
		return ans;
	}
	int num[maxn];
	void nadd(int x, int v){
		while (x) {	
			num[x] += v;
			x -= lowbit(x);
		}
	}
	int nget(int x){
		int ans = 0;
		while (x < maxn){
			ans += num[x];
			x += lowbit(x);
		}
		return ans;
	}
}LU, _LU, _RU;

int x[maxn], y[maxn], xx[maxn], yy[maxn], st[maxn];

int main(){
	scanf("%d", &n);
	int ptr = 0;
	rep(i, 1, n){
		int num0 = 0, num1 = 0;
		scanf("%s", s + ptr + 1);
		st[i] = ptr + 1;
		int l = strlen(s + ptr + 1);
		//ptr += l;
		srep(j, ptr + 1, ptr + 1 + l) {
			if (s[j] == 'B') num1++;
			else num0++;
		}
		ptr += l;
		lis[i] = ele(num0, num1, i), x[i] = num0, y[i] = num1, xx[i] = num0 + num1, yy[i] = num0 - num1;
	}
	st[n + 1] = ptr + 1;
	
	sort(lis + 1, lis + 1 + n);
	
	sort(xx + 1, xx + 1 + n);
	int cx = unique(xx + 1, xx + 1 + n) - xx - 1;
	sort(yy + 1, yy + 1 + n);
	int cy = unique(yy + 1, yy + 1 + n) - yy - 1;
	rep(i, 1, n){
		lis[i].xx = lower_bound(xx + 1, xx + 1 + cx, lis[i].x + lis[i].y) - xx;
		lis[i].yy = lower_bound(yy + 1, yy + 1 + cy, lis[i].x - lis[i].y) - yy;
	}
	
	sort(x + 1, x + 1 + n);
	cx = unique(x + 1, x + 1 + n) - x - 1;
	sort(y + 1, y + 1 + n);
	cy = unique(y + 1, y + 1 + n) - y - 1;
	rep(i, 1, n){
		lis[i].x = lower_bound(x + 1, x + 1 + cx, lis[i].x) - x;
		lis[i].y = lower_bound(y + 1, y + 1 + cy, lis[i].y) - y;
	}
	
	rep(i, 1, n){
		RD.add(lis[i].y, x[lis[i].x] - y[lis[i].y]), RD.nadd(lis[i].y, 1);
		_RU.add(lis[i].yy, xx[lis[i].xx] + yy[lis[i].yy]), _RU.nadd(lis[i].yy, 1);
		_RD.add(lis[i].yy, xx[lis[i].xx] - yy[lis[i].yy]), _RD.nadd(lis[i].yy, 1);
	}
	ll min = -1, min2 = -1;
	rep(i, 1, n){
		int _i = i, _x = lis[i].x;
		while (i <= n && lis[i].x == _x){ 
			_RU.add(lis[i].yy, -(xx[lis[i].xx] + yy[lis[i].yy])), _RU.nadd(lis[i].yy, -1);
			_RD.add(lis[i].yy, -(xx[lis[i].xx] - yy[lis[i].yy])), _RD.nadd(lis[i].yy, -1);
			i++;
		}
		
		srep(j, _i, i){
			RD.add(lis[j].y, -(x[lis[j].x] - y[lis[j].y])), RD.nadd(lis[j].y, -1);
			
			ll _res = 0;
			_res += RD.get(lis[j].y - 1) + 1ll * RD.nget(lis[j].y - 1) * (-x[lis[j].x] + y[lis[j].y]);
			_res += LU.get(lis[j].y + 1) + 1ll * LU.nget(lis[j].y + 1) * (x[lis[j].x] - y[lis[j].y]); 
			ll res = 0;
			res += _LU.get(lis[j].yy + 1) + 1ll * _LU.nget(lis[j].yy + 1) * (xx[lis[j].xx] - yy[lis[j].yy]);
			res += _LD.get(lis[j].yy) + 1ll * _LD.nget(lis[j].yy) * (xx[lis[j].xx] + yy[lis[j].yy]);
			res += _RU.get(lis[j].yy + 1) + 1ll * _RU.nget(lis[j].yy + 1) * (-xx[lis[j].xx] - yy[lis[j].yy]);
			res += _RD.get(lis[j].yy) + 1ll * _RD.nget(lis[j].yy) * (-xx[lis[j].xx] + yy[lis[j].yy]);
			res = (res / 2) + _res;
			if (min2 == -1) {
				min2 = lis[j].id;
				min = res;
			}
			else {
				if (res < min) min = res, min2 = lis[j].id;
			} 
			
			LU.add(lis[j].y, -x[lis[j].x] + y[lis[j].y]), LU.nadd(lis[j].y, 1);
		}
		
		srep(j, _i, i){
			_LU.add(lis[j].yy, -xx[lis[j].xx] + yy[lis[j].yy]), _LU.nadd(lis[j].yy, 1);
			_LD.add(lis[j].yy, -xx[lis[j].xx] - yy[lis[j].yy]), _LD.nadd(lis[j].yy, 1);
		} 
		i--;
	}
	printf("%lld\n", min);
	srep(i, st[min2], st[min2 + 1]) printf("%c", s[i]);
	return 0;
}


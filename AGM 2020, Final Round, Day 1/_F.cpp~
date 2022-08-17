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
#define ls ch[x][0]
#define rs ch[x][1]
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

int n, m, a[maxn], b[maxn];

int root, ct = 0;
int ch[maxn << 1][2];
int add[maxn << 1], v[maxn << 1], num[maxn << 1], s[maxn << 1], p[maxn << 1];
inline void pd(int x){
	v[x] += add[x];
	if (ls) add[ls] += add[x];
	if (rs) add[rs] += add[x];
	add[x] = 0;
}
inline void pu(int x){
	s[x] = ((ls) ? s[ls] : 0) + ((rs) ? s[rs] : 0) + num[x];
}
void rotate(int& x, int d){
	int y = ch[x][d]; ch[x][d] = ch[y][d ^ 1], ch[y][d ^ 1] = x;
	x = y;
}
void insert(int& x, int _v, int _num){
	pd(x);
	if (!x) {x = ++ct, v[x] = _v, s[x] = num[x] = _num, p[x] = rand(); return;}
	if (v[x] == _v) {num[x] += _num; s[x] += _num; return;}  
	insert(ch[x][v[x] > _v], _v, _num);
	if (p[ch[x][v[x] > _v]] > p[x]) rotate(x, v[x] > _v);
	pu(x);
}
int get_kth(int x, int k){
	while (1){
		if (!x) return -1;
		pd(x);
		if (s[ls] < k && s[ls] + num[x] >= k) return x;
		else if (s[ls] >= k) x = ls;
		else k -= (s[ls] + num[x]), x = rs;
	}
}
int find_rank(int x, int _v){
	int ans = 0;
	while (1){
		if (!x) return ans;
		pd(x);
		if (v[x] > _v) ans += s[ls] + num[x], x = rs;
		else if (v[x] == _v) return ans + s[ls];
		else x = ls;
	}
}
int find_v(int x, int _v){
	while (1){
		if (!x) return -1;
		pd(x);
		if (v[x] == _v) return x;
		x = ch[x][v[x] > _v];
	}
}
void Add(int x, int _v, int ad){
	while (1){
		if (!x) return;
		pd(x);
		if (v[x] > _v) v[x] += ad, add[ls] += ad, x = rs;
		else if (v[x] == _v) {add[x] += ad; return;}
		else x = ls; 
	} 
} // direction = v[x] > _v !!!
void del(int& x, int _v){
	if (!x) return;
	pd(x);
	if (v[x] == _v) {
		if (ls && rs){
			rotate(x, p[ls] < p[rs]);
			del(ch[x][v[x] > _v], _v);
		}
		else if (!ls) x = rs; 
		else x = ls;
	}
	else del(ch[x][v[x] > _v], _v);
	if (x) pu(x);
}

void recover(){
	rep(i, 1, ct) s[i] = v[i] = num[i] = p[i] = add[i] = ch[i][0] = ch[i][1] = 0;
	root = ct = 0; 
}

int main(){
	
		freopen("F.in", "r", stdin);
		
	int T;
	read(T);
	while (T--){
		//ll sa = 0, sb = 0;
		read(n); read(m);
		rep(i, 1, n) read(a[i]);
		rep(i, 1, m) read(b[i]);//, sb += b[i];
		//printf("%lld\n", min(sa, sb));
		sort(b + 1, b + 1 + m);
		sort(a + 1, a + 1 + n);
		rep(i, 1, m){ 
			int now = b[i], _i = i;
			while (i <= m && b[i] == now) i++;
			if (now > 0) insert(root, now, i - _i);
			i--;
		}
		ll ans = 0;
		rep(i, 1, n){
			if (!a[i]) continue;
			int d = min(a[i], s[root]);
			ans += d;
			int x = get_kth(root, d);
			int prenum = find_rank(root, v[x]);
			int _v = v[x], _num = num[x];
			int _prenode = find_v(root, _v + 1);
			int __v = v[_prenode];
			//printf("%d %d %lld %d %d %d %d %d\n", a[i], d, ans, x, prenum, _v, _prenode, s[root]);
			if (_prenode != -1){
				int __num = num[_prenode];
				del(root, _v), del(root, __v);
				if (_v - 1 > 0 && d - prenum > 0) insert(root, _v - 1, d - prenum);
				if (_num - (d - prenum) + __num > 0) insert(root, _v, _num - (d - prenum) + __num);
				Add(root, _v + 2, -1);
			}
			else {
				del(root, _v);
				if (_v - 1 > 0 && d - prenum > 0) insert(root, _v - 1, d - prenum);
				if (_num > (d - prenum)) insert(root, _v, _num - (d - prenum));
				Add(root, _v + 1, -1);
			}
		}
		recover();
		printf("%lld\n", ans);
	}
	return 0;
}


#pragma comment (linker,"/STACK:102400000,102400000")
#include <cstdio>
#include <cassert>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
#define maxn 100020
#define maxm
#define maxr 1000000
#define ls c[x][0]
#define rs c[x][1]
#define M 1000000007
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

int power(int x, int y){
	int ans = 1, con = x;
	if (x == 1) return 1;
	while (y){
		if (y & 1) ans = 1ll * ans * con % M;
		con = 1ll * con * con % M;
		y >>= 1;
	}
	return ans;
}
int getinv(int x){
	if (x == 1) return 1;
	return power(x, M - 2);
}


struct value
{
	int a,b;

	value() : a(0), b(0){}

	value(ll x):a(0),b(0)
	{
		while (x%M==0)
		{
			x/=M;
			b++;
		}
		a=x;
	}

	value(int a,int b):a(a),b(b){}

	value operator * (const value v) const
	{
		return value(1ll * a*v.a%M,b+v.b);
	}

	value operator / (const value v) const
	{
		return value(1ll * a*getinv(v.a)%M,b-v.b);
	}

	void output() const
	{
		assert(b >= 0) ;
		if (b>0)
			puts("0");
		else
			printf("%d\n",a);
	}
}v[maxn], vv[maxn];

char buffer[maxr], *p1, *p2;
template<class T> void read(T& x){
	char ch = gc(); x = 0;
	while (!('0' <= ch && ch <= '9')) ch = gc();
	if ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
}

int n, m, a[maxn];



int c[maxn][2], s[maxn], vs[maxn], f[maxn], st[maxn]; bool r[maxn];
inline bool nroot(int x){ return c[f[x]][0] == x || c[f[x]][1] == x; } 
inline void pu(int x) {
	s[x] = s[ls] + s[rs] + a[x] + vs[x]; 
	v[x] = v[ls] * v[rs] * (value)s[x] * vv[x];
}
inline void puv(int x, int d){
	if (d == 1) {
		vs[f[x]] += s[x];
		vv[f[x]] = vv[f[x]] * v[x];
		return;
	}
	else if (d == -1){
		vs[f[x]] -= s[x];
		vv[f[x]] = vv[f[x]] / v[x];
		return;
	}
	assert(false);
}
inline void pass(int x) { int t = ls; ls = rs, rs = t, r[x] ^= 1;}
inline void pd(int x) { if (r[x]) pass(ls), pass(rs), r[x] = 0;}
void rotate(int& x){
	int y = f[x], z = f[y], k = c[y][1] == x, w = c[x][!k];
	if (nroot(y)) c[z][c[z][1] == y] = x; c[x][!k] = y; c[y][k] = w;
	if (w) f[w] = y; f[y] = x; f[x] = z; pu(y);
}
void splay(int x){
	int y = x, z = 0; st[++z] = y;
	while (nroot(y)) st[++z] = y = f[y];
	while (z) pd(st[z--]);
	while (nroot(x)) {
		y = f[x], z = f[y];
		if (nroot(y)) rotate((c[y][1] == x) ^ (c[z][1] == y) ? x : y); rotate(x);
	} pu(x);
}
void access(int x) { for (register int y = 0; x; x = f[y = x]) splay(x), puv(rs, 1), rs = y, puv(rs, -1), pu(x);}
void moveroot(int x){ access(x), splay(x), pass(x);}
void split(int x, int y){ moveroot(y), access(x), splay(x);}
void link(int x, int y) {
	moveroot(x); 
	f[x] = y;
	puv(x, 1);
}
void cut(int x, int y) { moveroot(x); if (f[y] != x || c[y][0]) return; f[y] = rs = 0; pu(x);}
int root = 0;
inline void get(int x){
	moveroot(root);
	v[x].output();
}
int ch[maxn][2], fa[maxn];
void mod(int x, int d){
	if (d == 0) { //right-rotation
		if (!ch[x][0]) return;
		int y = ch[x][0]; 
		fa[y] = fa[x]; if (fa[x]) cut(x, fa[x]), link(y, fa[x]), ch[fa[x]][ch[fa[x]][1] == x] = y;
		else root = y;
		ch[x][0] = ch[y][1]; if (ch[y][1]) cut(ch[y][1], y), link(x, ch[y][1]), fa[ch[y][1]] = x;
		ch[y][1] = x, fa[x] = y;
	}
	else if (d == 1){ //left-rotation	
		if (!ch[x][1]) return;
		int y = ch[x][1];
		fa[y] = fa[x]; if (fa[x]) cut(x, fa[x]), link(y, fa[x]), ch[fa[x]][ch[fa[x]][1] == x] = y; else root = y;
		ch[x][1] = ch[y][0]; if (ch[y][0]) cut(y, ch[y][0]), link(x, ch[y][0]), fa[ch[y][0]] = x;
		ch[y][0] = x, fa[x] = y;
	}
}
//int get(int x, int y){ split(x, y); return s[x];}
//void mod(int x, int y){ splay(x); v[x] = y; pu(x);}

void recover(){
	rep(x, 1, n) fa[x] = c[x][0] = c[x][1] = f[x] = r[x] = 0; root = 0; 
}

int main(){
	int T, x, y; read(T);
	rep(TT, 1, T){
		printf("Case #%d:\n", TT);
		read(n), read(m);
		rep(i, 1, n) read(a[i]), read(ch[i][0]), read(ch[i][1]); 
		rep(i, 1, n) s[i] = a[i], v[i] = value(a[i]), vs[i] = 0, vv[i] = value(1);
		v[0] = value(1), vv[0] = value(1), s[0] = vs[0] = 0;
		rep(i, 1, n) { 
			if (ch[i][0]) fa[ch[i][0]] = i, link(i, ch[i][0]);
			if (ch[i][1]) fa[ch[i][1]] = i, link(i, ch[i][1]);
		}
		rep(i, 1, n) if (!fa[i]) {root = i; break;}
		rep(i, 1, m){
			read(x), read(y);
			if (x != 2) mod(y, x);
			else get(y);//printf("%d\n", get(y));
		}
		recover();
	}
	return 0;
}

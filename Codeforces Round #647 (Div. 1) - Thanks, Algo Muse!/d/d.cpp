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
#define pdi pair<double, int>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define ll long long int 
#define pb push_back
#define pc putchar
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn
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

int gcd(int x, int y){
	if (!y) return x;
	return gcd(y, x % y);
}

/*
struct ele{
	int x, y, dx, dy;
	ele(int x, int y, int dx, int dy) : x(x), y(y), dx(dx), dy(dy){}
	ele(){}
	bool operator < (const ele b){
	}
}a[maxn];
*/ 

struct ele{
	int x, y, id;
	ele(int x, int y, int id) : x(x), y(y), id(id){}
	ele(){} 
	bool operator < (const ele b) const{
		return x < b.x;
	} 
};

vector<ele> lis[maxn];
ll sum[maxn];

int cs = 0;
map<pii, int> id;
pii iid[maxn];

pdi sil[maxn];
int ct = 0;

inline double dis(ele op){
	return sqrt((ll)op.x * op.x + (ll)op.y * op.y);
}

int main(){
	scanf("%d%d", &n, &k);
	int x, y;
	rep(i, 1, n){
		scanf("%d%d", &x, &y);
		dx = x, dy = y;
		if (!x && !y) continue; 
		int d = gcd(abs(x), abs(y));
		dx /= d, dy /= d;
		//a[i] = ele(x, y, dx, dy);
		if (!id.count(pii(dx, dy))) id[pii(dx, dy)] = ++cs, iid[cs] = pii(dx, dy);
		lis[id[pii(dx, dy)]].pb(ele(x, y, i));
	}
	rep(i, 1, cs) sort(lis[i].begin(), lis[i].end()); 
	rep(i, 1, cs){
		int si = lis[i].size();
		ll psum = 0, ssum = 0;
		double k = (double)sqrt((ll)dx * dx + (ll)dy * dy) / dx;
		srep(j, 0, si) ssum += lis[i][j].x;
		srep(j, 0, si){
			ele op = lis[i][j];
			double dist = abs(ssum - (ll)(si - i) * op.x + (ll)i * op.x - psum) * k + dis(op);
			sil[++ct] = pdi(dist, op.id);//s.insert(pdi(dist, op.id));
			psum += op.x, ssum -= op.x;
		}
	}
	int _k = k;
	
	sort(sil + 1, sil + 1 + ct);	
	double res1 = 0, sum = 0;
	per(i, ct, 1){
		if (!k) break;
		res1 += sil[i].fi;
		k--;
	}
	
	k = _k;
	double res2 = 0;
	return 0;
}


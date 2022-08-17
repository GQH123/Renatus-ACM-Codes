#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
#define maxn 2020
#define maxm
using namespace std;

struct pint{
	int x, y;
	pint(int x, int y) : x(x), y(y){}
	pint(){}
	pint operator - (const pint& b) const{
		return pint(x - b.x, y - b.y);
	}
	double operator * (const pint& b) const{
		return x * b.y - y * b.x;
	}
	void read(){ scanf("%d%d", &x, &y); }
}p[maxn];

inline int dist(int x, int y){
	return x * x + y * y;
}
inline int dist(pint a, pint b){
	return dist(a.x - b.x, a.y - b.y);
}

struct seg{
	int a, b, l;
	seg(int a, int b) : a(a), b(b) {l = dist(p[a], p[b]);}
	seg(){}
	bool operator < (const seg& x) const{
		return l < x.l;
	}
}pre[maxn], e[maxn * maxn], lis[maxn];
int ce = 0, cs = 0;

int dcmp(int x){
	if (x > 0) return 1;
	if (x == 0) return 0;
	if (x < 0) return -1;
	assert(false);
}
bool inter(const seg& a, const seg& b)
{
	if (a.a == b.a || a.a == b.b || a.b == b.a || a.b == b.b) return false;
	if (max(p[b.a].x,p[b.b].x)<min(p[a.a].x,p[a.b].x)||max(p[b.a].y,p[b.b].y)<min(p[a.a].y,p[a.b].y))
		return false;
	if (max(p[a.a].x,p[a.b].x)<min(p[b.a].x,p[b.b].x)||max(p[a.a].y,p[a.b].y)<min(p[b.a].y,p[b.b].y))
		return false;
	if (dcmp((p[a.b]-p[a.a])*(p[b.a]-p[a.a]))*dcmp((p[a.b]-p[a.a])*(p[b.b]-p[a.a]))>0)
		return false;
	if (dcmp((p[b.b]-p[b.a])*(p[a.a]-p[b.a]))*dcmp((p[b.b]-p[b.a])*(p[a.b]-p[b.a]))>0)
		return false;
	return true;
} 

int n, m, ufs[maxn];
int find_root(int x){
	return ufs[x] = (ufs[x] == x) ? x : find_root(ufs[x]);
}
void merge(int x, int y){
	x = find_root(x), y = find_root(y);
	if (x == y) return;
	ufs[x] = y;
}
bool inone(int x, int y){
	return find_root(x) == find_root(y);
}

int main(){
	scanf("%d", &n); 
	rep(i, 1, n) p[(i << 1) - 1].read(), p[i << 1].read(), pre[i] = seg((i << 1) - 1, i << 1);
	m = n, n <<= 1;
	rep(i, 1, n) ufs[i] = i;
	rep(i, 1, n) merge(i, i + 1), i++;
	rep(i, 1, n){
		int soul = (i & 1) ? (i + 1) : (i - 1);
		rep(j, i + 1, n) {
			if (j == soul) continue;
			e[++ce] = seg(i, j);
		}
	}
	double res = 0;
	sort(e + 1, e + 1 + ce);
	rep(i, 1, ce){ 
		if (inone(e[i].a, e[i].b)) continue;
		rep(j, 1, m) if (inter(pre[j], e[i])) goto done; 
		lis[++cs] = e[i];
		merge(e[i].a, e[i].b);
		res += sqrt(e[i].l);
		done:;
	}
	printf("%.10lf\n", res);
	return 0;
}

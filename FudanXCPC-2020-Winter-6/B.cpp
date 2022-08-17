#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int
#define maxn 20020
#define maxm 
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define pi (3.141592653589793)
#define eps 1e-15
using namespace std;

int n;
struct point{
	int x, y;
	double ang;
	point(int x, int y) : x(x), y(y){}
	point(){}
}p[maxn];

inline double dist(point a){
	return sqrt(1.0 * a.x * a.x + 1.0 * a.y * a.y);
}

struct inter{
	double l, r;
	inter(double l, double r) : l(l), r(r){}
	inter(){}
	bool operator < (const inter b) const{
		return (-eps <= b.l - l && b.l - l <= eps) ? (b.r - r > eps) : (b.l - l > eps);
	}
}lis[maxn << 1];
int cs = 0;

bool judge(double r){
	cs = 0;
	r = r / 8.0;
	rep(i, 1, n){	
		double d = dist(p[i]);
		if (!(d - r > eps)) return false;
		if (d - sqrt(2.0 * r * r) > eps) continue;
		double theta = acos(r / d);
		//assert(pi / 2.0 - theta > eps);
		lis[++cs] = inter(theta - p[i].ang, pi / 2.0 - theta - p[i].ang);
		if (lis[cs].r < -eps && lis[cs].l < -eps) lis[cs].r += pi, lis[cs].l += pi;
		//assert(lis[cs].r - lis[cs].l > eps);
		lis[++cs] = inter(pi / 2.0 + theta - p[i].ang, pi - theta - p[i].ang); 
		if (lis[cs].r < -eps && lis[cs].l < -eps) lis[cs].r += pi, lis[cs].l += pi;
		//assert(lis[cs].r - lis[cs].l > eps);
	}
	if (!cs) return true;
	sort(lis + 1, lis + 1 + cs);
	double mx = -2 * pi;
	rep(i, 1, cs){
		if (lis[i].r - mx > eps) mx = lis[i].r;
		if (i < cs) {if (lis[i + 1].l - mx > eps) return true;}
	}
	if (lis[1].l + pi - mx > eps) return true;
	//if ((lis[1].l > eps) || (pi - lis[cs].r > eps)) return true;
	//printf("%lf %lf %lf %lf\n", lis[1].l, lis[1].r, lis[cs].l, lis[cs].r);
	//srep(i, 1, cs) if (lis[i + 1].l - lis[i].r > eps) return true;
	//if (lis[1].l + pi - lis[cs].r > eps) return true;
	return false;
}

double solve(){
	double l = 0, r = 16000000000;
	int T = 200;
	while (T--){
		double mid = (r + l) / 2;
		if (judge(mid)) l = mid;
		else r = mid;
	}
	return l;
}

int main(){
	freopen("B.in", "r", stdin);
	
	scanf("%d", &n);
	rep(i, 1, n) {
		scanf("%d%d", &p[i].x, &p[i].y);
		if (p[i].y < 0) p[i].x = -p[i].x, p[i].y = -p[i].y;
		p[i].ang = acos(p[i].x / dist(p[i]));
	}
	printf("%.4lf", solve());
	return 0;
}


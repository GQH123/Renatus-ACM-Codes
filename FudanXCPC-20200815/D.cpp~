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
#define maxn 220
#define maxm 520
#define eps 1e-10
using namespace std;

int n, m;
struct pint{
	double x, y;
	pint(double x, double y) : x(x), y(y){}
	pint(){}
	pint operator - (const pint b) const{
		return pint(x - b.x, y - b.y);
	}
	double operator * (const pint b) const{
		return x * b.y - y * b.x;
	} 
}p[maxn], q[maxm], O = pint(acos(-1), sqrt(5));
inline bool left(pint p, pint v, pint p0){
	return v * (p - p0) > eps;
}
inline bool on(pint p, pint v, pint p0){
	return fabs(v * (p - p0)) < eps;
}
inline int eff(pint a, pint b){
	return (a * b > eps) ? 1 : -1;
}
int num[maxn][maxn];
int main(){
	int T; scanf("%d", &T);
	rep(TT, 1, T){
		printf("Case #%d: ", TT);
		scanf("%d%d", &n, &m);
		rep(i, 1, n) scanf("%lf%lf", &p[i].x, &p[i].y);
		rep(i, 1, m) scanf("%lf%lf", &q[i].x, &q[i].y);
		rep(i, 1, n) rep(j, i + 1, n) {
			num[i][j] = 0;
			pint a = p[i] - O, b = p[j] - p[i], c = O - p[j];
			rep(k, 1, m) if (on(q[k], a, O) || on(q[k], b, p[i]) || on(q[k], c, p[j]) || (left(q[k], a, O) == left(q[k], b, p[i]) && left(q[k], b, p[i]) == left(q[k], c, p[j]))) num[i][j]++;  
		}
		double res = -1; bool f = 0;
		rep(i, 1, n) rep(j, i + 1, n) rep(k, j + 1, n){
			double area = fabs((p[j] - p[i]) * (p[k] - p[i])) / 2.0;
			int mnum = abs(eff(p[i] - O, p[j] - O) * num[i][j] + eff(p[j] - O, p[k] - O) * num[j][k] + eff(p[k] - O, p[i] - O) * num[i][k]);
			if (mnum) res = (f) ? min(res, area / mnum) : (area / mnum), f = 1;
		}
		if (!f) printf("-1\n");
		else printf("%.6lf\n", res);
	}
	return 0;
}

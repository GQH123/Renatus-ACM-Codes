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
#define maxn 
#define maxm
using namespace std;

struct pint{
    double x, y;
    pint(double x, double y) : x(x), y(y){}
    pint(){}
    pint operator + (const pint& b) const {
        return pint(x + b.x, y + b.y);
    }
    pint operator - (const pint& b) const {
        return pint(x - b.x, y - b.y);
    }
    pint operator * (const double& k) const {
        return pint(x * k, y * k);
    }
    double operator * (const pint& b) const {
        return x * b.y - y * b.x;
    }
};
struct line{
    pint p, v;
    line(pint p, pint v) : p(p), v(v){}
    line(){}
};
pint inc(const line& a, const line& b) {
    return b.p + b.v * ((b.p - a.p) * a.v / (a.v * b.v));
}

int main(){
    int T; scanf("%d", &T);
    while (T--){
        double x1, y1, x2, y2, xs, ys, xe, ye;
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &xs, &ys, &xe, &ye);
        line mir = line(pint(x2, y2), pint(x1 - x2, y1 - y2)); 
        line ee = line(pint(xe, ye), pint(-mir.v.y, mir.v.x));
        pint midp = inc(mir, ee);
        double _xe = midp.x * 2 - xe, _ye = midp.y * 2 - ye;
        line _e = line(pint(_xe, _ye), pint(xs - _xe, ys - _ye));
        pint inter = inc(mir, _e);
        printf("%.3lf %.3lf\n", inter.x, inter.y);
    }
	return 0;
}

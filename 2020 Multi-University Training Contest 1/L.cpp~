#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define N 2020
#define pi acos(-1)
#define eps 1e-10
using namespace std;	

struct P{
	double x, y;
	P(){x = y = 0;}
	P(double _x, double _y){x = _x, y = _y;}
	P operator - (const P& a) const {return P(x - a.x, y - a.y);}
	P operator + (const P& a) const {return P(x + a.x, y + a.y);}
	P operator * (double a) const {return P(x * a, y * a);}
	P operator / (double a) const {return P(x / a, y / a);}
	void read() {scanf("%lf%lf", &x, &y);}
}p[N], a[N];
double dist(const P& a, const P& b){
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
double length(const P& a){
	return dist(a, P(0, 0));
}
struct L{
	P p, v; double a;
	L(){}
	L(P _p, P _v){p = _p, v = _v;}
	bool operator < (const L& b) const {return a < b.a;}
	void cal(){a = atan2(v.y, v.x);}
	void move(int good, double r){
		P _v = P(-v.y, v.x);
		_v = _v / length(_v);
		if (good == 1) p = p + _v * r;
		else p = p - _v * r;
	}// move left
}line[N], q[N];
// p is start point, v is direction vector, a is angle 
int i, cl;
double cross(const P& a, const P& b) {return a.x * b.y - a.y * b.x;}
void newL(const P& a, const P& b) {line[++cl] = L(a, b - a);}
bool left(const P& p, const L& l) {return cross(l.v, p - l.p) > 0;}
P pos(const L& a, const L& b){
	P x = a.p - b.p; double t = cross(b.v, x) / cross(a.v, b.v);
	return a.p + a.v * t;
}

int n, r, aa, b;
double halfplane(){
	double full = 0;
	srep(i, 0, n - 1) full += cross(a[i], a[i + 1]); full += cross(a[n - 1], a[0]);
	full /= 2.0;
	full = fabs(full);
	if (aa <= b) return aa * full;
	rep(i, 1, cl) line[i].cal();
	sort(line + 1, line + cl + 1);
	int h = 1, t = 1;
	q[1] = line[1];
	rep(i, 2, cl) {
		while (h < t && !left(p[t - 1], line[i])) t--;
		while (h < t && !left(p[h], line[i])) h++;
		if (fabs(cross(q[t].v, line[i].v)) < eps) q[t] = left(q[t].p, line[i]) ? q[t] : line[i];
		else q[++t] = line[i];
		if (h < t) p[t - 1] = pos(q[t], q[t - 1]);
	}
	while (h < t && !left(p[t - 1], q[h])) t--;
	p[t] = pos(q[t], q[h]);
	if (t - h <= 1) return aa * full;
	double ans = 0, para = 0;
	srep(i, h, t) ans += cross(p[i], p[i + 1]), para += dist(p[i], p[i + 1]);
	ans += cross(p[t], p[h]), para += dist(p[t], p[h]);
	ans /= 2.0;
	ans = fabs(ans);
	if (ans < eps) return aa * full;
	ans += pi * r * r;
	ans += para * r;
	return aa * (full - ans) + b * ans;
}

inline void recover(){
	cl = 0;
}
int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		scanf("%d%d%d%d", &n, &r, &aa, &b);  
		srep(i, 0, n) a[i].read();
		int good = -1;
		srep(i, 0, n){
			if (cross(a[(i + 1) % n] - a[i], a[(i + 2) % n] - a[(i + 1) % n]) > eps) {good = 1; break;}
			else if (cross(a[(i + 1) % n] - a[i], a[(i + 2) % n] - a[(i + 1) % n]) < eps) {good = 0; break;}
		}
		if (good == -1) printf("%d\n", 0 / 0);
		if (!good) reverse(a, a + n);
		srep(i, 0, n) newL(a[i], a[(i + 1) % n]), line[cl].move(1, r);
		printf("%.8lf\n", halfplane());
		recover();
	}
	return 0;
}

 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
 
using namespace std;
 
const int maxn = 11111;
const double eps = 1e-6;
struct point_t {
    double x, y;
	point_t() { }
	point_t(double tx, double ty) {
		x = tx, y = ty;
	}
	point_t operator-(const point_t &r) const {
		return point_t(x - r.x, y - r.y);
	}
	point_t operator+(const point_t &r) const {
		return point_t(x + r.x, y + r.y);
	}
	point_t operator/(const double &r) {
		return point_t(x / r, y / r);
	}
	point_t operator*(const double &r) {
		return point_t(x * r, y * r);
	}
} p[maxn], tp[maxn], sk[maxn];
int n, top;
double S, R;
 
double cross(point_t p1, point_t p2) {
	return p1.x * p2.y - p1.y * p2.x;
}
 
double sqr(double x) { return x * x; }
double dist(point_t p1, point_t p2) {
	p2 = p2 - p1;
	return sqrt(sqr(p2.x) + sqr(p2.y));
}
 
point_t normalize(point_t p) {
	double l = sqrt(sqr(p.x) + sqr(p.y));
	return p / l;
}
 
int dblcmp(double x) {
	return x < -eps ? -1 : x > eps;
}
 
bool cmp(const point_t &p1, const point_t &p2) {
	return dblcmp(p1.y - p2.y) == 0 ? p1.x < p2.x : p1.y < p2.y;
}
 
void graham() {
	sort(p + 1, p + 1 + n, cmp);
	top = 2, sk[1] = p[1], sk[2] = p[2];
	for (int i = 3; i <= n; ++i) {
		while (top >= 2 && dblcmp(cross(p[i] - sk[top - 1], sk[top] - sk[top - 1])) >= 0) --top;
		sk[++top] = p[i];
	}
	int ttop = top;
	for (int i = n - 1; i >= 1; --i) {
		while (top > ttop && dblcmp(cross(p[i] - sk[top - 1], sk[top] - sk[top - 1])) >= 0) --top;
		sk[++top] = p[i];
	}
	--top;
	n = top;
	for (int i = 1; i <= n; ++i) {
		p[i] = sk[i];
	}
}
 
point_t inter(point_t a, point_t b, point_t c, point_t d) {
	point_t p1 = b - a, p2 = d - c;
	double a1 = p1.y, b1 = -p1.x, c1;
	double a2 = p2.y, b2 = -p2.x, c2;
	c1 = a1 * a.x + b1 * a.y;
	c2 = a2 * c.x + b2 * c.y;
	return point_t((c1 * b2 - c2 * b1) / (a1 * b2 - a2 * b1), (c1 * a2 - c2 * a1) / (b1 * a2 - b2 * a1));
}
 
void extend(double d) {
	p[0] = p[n]; p[n + 1] = p[1];
	for (int i = 1; i <= n; ++i) {
		point_t p1 = p[i - 1], p2 = p[i], p3 = p[i + 1];
		point_t v1 = normalize(p2 - p1);
		swap(v1.x, v1.y);
		v1.y = -v1.y;
		point_t v2 = normalize(p3 - p2);
		swap(v2.x, v2.y);
		v2.y = -v2.y;	   
		v1 = v1 * d, v2 = v2 * d;
		tp[i] = inter(p1 + v1, p2 + v1, p2 + v2, p3 + v2);  
	}
}
 
char buf[1024];
 
double area() {
	double ans = 0;
	for (int i = 2; i <= n; ++i) {
		ans += cross(tp[i - 1] - tp[1], tp[i] - tp[1]);
	}
	return fabs(ans) / 2;
}
 
double maxdist() {
	tp[0] = tp[n], p[0] = p[n];
	int to = 0;
	double ans = 0;
	for (int i = 0; i < n; ++i) {
		while ((to + 1) % n != i && dblcmp(fabs(cross(tp[i + 1] - tp[i], p[to] - tp[i])) - fabs(cross(tp[i + 1] - tp[i], p[to + 1] - tp[i]))) <= 0) to = (to + 1) % n;
		ans = max(ans, dist(tp[i], p[to]));
		ans = max(ans, dist(tp[i + 1], p[to]));
	}
	return ans;
}
 
double work1() {
	double begin = 0, end = 1e15, mid;
	while (begin + 1e-9 < end) {
		mid = (begin + end) / 2;
		extend(mid);
		double a = area();
		if (a < S) {
			begin = mid;
		} else {
			end = mid;
		}
	}
	return end;
}
 
double work2() {
	double begin = 0, end = 1e15, mid;
	while (begin + 1e-9 < end) {
		mid = (begin + end) / 2;
		extend(mid);
		double d = maxdist();
		if (d > R) {
			end = mid;
		} else {
			begin = mid;
		}
	}
	return begin;
}
 
int main() {
	while (scanf("%d", &n) != EOF) {
		for (int i = 1; i <= n; ++i) {
			scanf("%s", buf);
			sscanf(buf, "(%lf,%lf)", &p[i].x, &p[i].y);
		}
		scanf("%lf%lf", &S, &R);
		graham();
		double ans1 = work1(), ans2 = work2();
		bool flag1 = true, flag2 = true;
		extend(ans1);
		if (dblcmp(area() - S) < 0) flag1 = false;
		extend(ans2);
		if (dblcmp(maxdist() - R) > 0) flag2 = false;
		if (dblcmp(ans1 - ans2) > 0 || !flag1 || !flag2) {
			puts("no appropriate design");
		} else {
			if (ans1 > ans2) swap(ans1, ans2);
			printf("%.3lf %.3lf\n", ans1, ans2);
		}
	}
	return 0;
}
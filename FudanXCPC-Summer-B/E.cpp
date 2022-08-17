#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)     
#define maxn 20020  
#define Author Renatus
using namespace std;

int n;
struct vec{
	double x, y;
	vec(double x, double y) : x(x), y(y){}
	vec(){}
}p[maxn], q[3], _p[maxn];

double dot(vec a, vec b){
	return a.x * b.x + a.y * b.y;
}
double cross(vec a, vec b){
	return a.x * b.y - a.y * b.x;
}
vec operator + (vec a, vec b){
	return vec(a.x + b.x, a.y + b.y);
}
vec operator - (vec a, vec b){
	return vec(a.x - b.x, a.y - b.y);
}
vec operator * (vec a, double k){
	return vec(a.x * k, a.y * k);
}
double dist(vec a, vec b){
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
double length(vec a){
	return dist(a, vec(0, 0));
}
vec rot(vec a, double sinn, double coss){
	return vec(a.x * coss - a.y * sinn, a.x * sinn + a.y * coss);
}

int main(){
	int T;
	scanf("%d", &T);
	rep(TT, 1, T){
		printf("Case %d:\n", TT);
		scanf("%d", &n);
		rep(i, 1, n) scanf("%lf%lf", &p[i].x, &p[i].y);
		scanf("%lf%lf%lf%lf", &q[1].x, &q[1].y, &q[2].x, &q[2].y);
		rep(i, 2, n) p[i].x -= p[1].x, p[i].y -= p[1].y;
		p[1] = vec(0, 0);
		double bigger = dist(q[1], q[2]) / dist(p[1], p[2]);
		rep(i, 1, n) p[i] = p[i] * bigger;
		double sinn = cross(p[2] - p[1], q[2] - q[1]) / length(p[2] - p[1]) / length(q[2] - q[1]);
		double coss = dot(p[2] - p[1], q[2] - q[1]) / length(p[2] - p[1]) / length(q[2] - q[1]);
		_p[1] = p[1];
		srep(i, 1, n){
			vec op = p[i + 1] - p[i];
			op = rot(op, sinn, coss);
			_p[i + 1] = _p[i] + op;
		}
		rep(i, 2, n) p[i] = _p[i] + q[1] - p[1];
		p[1] = q[1];
		rep(i, 1, n) printf("%.2lf %.2lf\n", p[i].x, p[i].y);
	} 
	
	return 0;
}

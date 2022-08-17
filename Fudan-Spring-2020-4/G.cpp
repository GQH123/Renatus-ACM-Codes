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
#define maxn 220
#define maxm
#define maxs
#define maxb
#define M 
#define pi acos(-1)
#define eps 1e-8
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

/*

struct circle{
	double a, b, c, d, e; //ax^2 + by^2 + cx + dy + e = 0;
};

struct 

circle get_circle(){
}

*/

int dcmp(double x, double y){
	if (x - y > eps) return 1;
	if (y - x > eps) return -1;
	return 0;
}

int n;
double s, h, ang[maxn], a[maxn];

bool judge(double x){ //0 = <-, 1 = ->
	a[1] = x;
	rep(i, 2, n) a[i] = a[1] * tan(ang[1]) / tan(ang[i]); 
	double sum = 0;
	a[n + 1] = a[1];
	rep(i, 1, n){
		if (dcmp(s, a[i] + a[i + 1]) == 1) return 1;
		if (dcmp(a[i] + s, a[i + 1]) == -1 || dcmp(a[i + 1] + s, a[i]) == -1) return 0;
		double v = (a[i] * a[i] + a[i + 1] * a[i + 1] - s * s) / (2 * a[i] * a[i + 1]);
		if (dcmp(v, 1) == 0) v = 1.0 - eps;
		if (dcmp(v,- 1) == 0) v = -1.0 + eps;
		sum += acos(v);
	}
	if (dcmp(sum, 2 * pi) >= 0) return 1;
	else return 0;
}

double solve(double l, double r){
	int T = 200;
	while (T--){
		double mid = (r + l) / 2.0;
		if (judge(mid)) l = mid;
		else r = mid;
	}
	return r;
}

int main(){
	
		freopen("G.in", "r", stdin); 
		
	int T;
	scanf("%d", &T);
	while (T--){
		bool f = 0, f2 = 0;
		scanf("%d%lf%lf", &n, &s, &h), h /= 100.0;
		rep(i, 1, n) {
			scanf("%lf", ang + i), ang[i] = ang[i] / 180.0 * pi;
			if (dcmp(tan(ang[i]), 0) == 0) f = 1;
			if (dcmp(ang[i], 0) == -1) f2 = 1, ang[i] = -ang[i];
		}
		if (f) {printf("%.4lf\n", h); continue;}
		double res = solve(0, 1000000.0);
		if (f2) res = -res;
		printf("%.4lf\n", res * tan(ang[1]) + h);
	}
	return 0;
}


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

double area(double a, double b, double c){
	double ctheta = (a * a + b * b - c * c) / (2 * a * b);
	double stheta = sqrt(1 - ctheta * ctheta);
	return a * b * stheta / 2.0;
}
double play(int a, int b, int c, int d, double h){
	return area(a, b, h) + area(c, d, h);
}

int main(){
	int T, a, b, c, d; scanf("%d", &T);
	rep(TT, 1, T){
		printf("Case %d: ", TT);
		scanf("%d%d%d%d", &a, &b, &c, &d);
		int mx = max(max(a, b), max(c, d));
		if (a + b + c + d <= 2 * mx) printf("-1\n");
		else {
			double h = sqrt((a * a + b * b + c * c + d * d) / 2.0);
			double res = 0;
			res = max(res, play(a, b, c, d, h));
			res = max(res, play(a, c, b, d, h));
			res = max(res, play(a, b, d, c, h));
			printf("%.6lf\n", res);
		}
	}
	return 0;
}

#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 2020
#define pi 3.141592653589793
#define eps 1e-7
using namespace std;

int n;
struct point{
	int x, y, b;
	point(int x, int y, int b) : x(x), y(y), b(b){}
	point(){}
}p[maxn];

double lis[maxn * maxn];
int cs = 0;

int main(){

	//printf("%lf %lf %lf %lf %lf %lf\n", acos(1), acos(sqrt(2) / 2.0), acos(0), acos(-sqrt(2) / 2.0), acos(-1), acos(-2));
		
		freopen("D.in", "r", stdin);
		
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].b);
	rep(i, 1, n){
		rep(j, 1, n){
			if (p[i].b > p[j].b){
				double ang = acos(1.0 * (p[i].x - p[j].x) / sqrt((p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y)));
				if (p[i].y < p[j].y) ang = 2 * pi - ang;
				lis[++cs] = ang;
			}
		}
	}
	if (!cs) {printf("Y"); return 0;}
	sort(lis + 1, lis + 1 + cs);
	//rep(i, 1, cs) printf("%lf ", lis[i]); printf("\n");
	lis[cs + 1] = lis[1] + 2 * pi;
	rep(i, 1, cs) if (!(lis[i + 1] - lis[i] - pi < -eps)) {printf("Y"); return 0;} 
	printf("N");
	return 0;
}

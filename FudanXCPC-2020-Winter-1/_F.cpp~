#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 320
using namespace std;

int n;
struct point{
	int x, y;
	point(int x, int y) : x(x), y(y){}
	point(){}
}p[maxn];
point operator - (point a, point b){
	return point(a.x - b.x, a.y - b.y);
}
int cross(point a, point b){
	return a.x * b.y - a.y * b.x;
}

double ans[maxn];

int main(){
	freopen("F.in", "r", stdin);
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d%d", &p[i].x, &p[i].y);
	
	rep(i, 1, n){
		rep(j, i + 1, n){
			int l = 0, r = 0;
			rep(k, 1, n){
				if (k == i || k == j) continue;
				int d = cross(p[j] - p[i], p[k] - p[i]);
				if (d > 0) l++;
				else if (d < 0) r++;
				else {
					if ((min(p[i].x, p[j].x) <= p[k].x && p[k].x <= max(p[i].x, p[j].x)) &&  (min(p[i].y, p[j].y) <= p[k].y && p[k].y <= max(p[i].y, p[j].y))) l++, r++;
				}
			}
			
			rep(k, 1, n){
				if (k == i || k == j) continue;
				int d = cross(p[j] - p[i], p[k] - p[i]);
				if (d > 0) ans[k] += (double)d / (l * (l + 1) * (l + 2)); 
				else if (d < 0) ans[k] -= (double)d / (r * (r + 1) * (r + 2)); 
			}
			
			jump:;
		}
	}
	rep(i, 1, n) printf("%.18lf\n", ans[i]);
	return 0;
}

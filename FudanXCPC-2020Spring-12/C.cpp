#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define ll long long int 
#define maxn 500020
//#define DEBUG
using namespace std;

int n, k;
struct point{
	ll x, y;
	point(ll x, ll y) : x(x), y(y){}
	point(){}
	bool operator < (const point b) const{
		return (x == b.x) ? y < b.y : x < b.x;
	}
}a[maxn], b[maxn];

ll cross(point x, point y, point z){
	return (x.x - z.x) * (y.y - z.y) - (x.y - z.y) * (y.x - z.x);
}

point con[maxn];
int cs = 0;
void Andrew(){
	sort(b + 1, b + 1 + k);
	con[++cs] = b[1];
	rep(i, 2, k){
		while (cs > 1 && cross(b[i], con[cs], con[cs - 1]) >= 0) cs--;
		con[++cs] = b[i];
	}
	int _cs = cs;
	per(i, k - 1, 1){
		while (cs > _cs && cross(b[i], con[cs], con[cs - 1]) >= 0) cs--;
		con[++cs] = b[i];
	}
}

bool on_right_side(point a, point b, point c){
	return cross(a, b, c) > 0;
}

bool res[maxn];

int main(){
	int T; scanf("%d", &T);
	while (T--){ 
		scanf("%d", &n);
		rep(i, 1, n) res[i] = 0; cs = 0;
		rep(i, 1, n) scanf("%lld%lld", &a[i].x, &a[i].y);
		scanf("%d", &k);
		rep(i, 1, k) scanf("%lld%lld", &b[i].x, &b[i].y); 
		Andrew();
		#ifdef DEBUG
			printf("\n");
			printf("%d\n", cs);
			rep(i, 1, cs) printf("%d %d\n", con[i].x, con[i].y);
			printf("\n");
		#endif
		
		int mi = n + 1, mx = -1;
		rep(i, 1, n){
			if (on_right_side(a[i], con[2], con[1])){
				mi = min(mi, i), mx = max(mx, i);
			}
		}
		res[mi] = res[mx] = 1;
		#ifdef DEBUG
			printf("%d: %d %d, %d: %d %d\n", mi, a[mi].x, a[mi].y, mx, a[mx].x, a[mx].y);
		#endif
		srep(i, 2, cs){
			while (!on_right_side(a[mi], con[i + 1], con[i])){
				mi++;
				if (mi == n + 1) mi = 1;
			}
			while (!on_right_side(a[mx], con[i + 1], con[i])){
				mx++;
				if (mx == n + 1) mx = 1;
			}
			while (on_right_side(a[mx], con[i + 1], con[i])){
				mx++;
				if (mx == n + 1) mx = 1;
			}
			mx--;
			if (mx == 0) mx = n;
			res[mi] = res[mx] = 1;
			#ifdef DEBUG
				printf("%d: %d %d, %d: %d %d\n", mi, a[mi].x, a[mi].y, mx, a[mx].x, a[mx].y);
			#endif
		}
		int ans = 0;
		rep(i, 1, n) if (res[i]) ans++; 
		if (ans > (k << 1)) printf("No\n");
		else {
			printf("Yes\n");
			printf("%d\n", ans);
			rep(i, 1, n) if (res[i]) printf("%d ", i);
			printf("\n");
		} 
	}
	return 0;
}

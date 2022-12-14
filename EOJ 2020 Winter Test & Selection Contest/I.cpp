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
#define lowbit(x) (x & -x) 
#define maxn 2020
using namespace std;

const int inf = 2000000020;

int n;
int mxr = -inf, mil = inf, mxu = -inf, mid = inf;
struct point{
	int x, y;
	point(int x, int y) : x(x), y(y){}
	point(){}
}p[maxn];

int main(){
	
		freopen("I.in", "r", stdin);
		
	int x, y;
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d%d", &x, &y), p[i] = point(x, y);
	p[n + 1] = p[1];
	int ans = 0;
	rep(i, 1, n){
		if (p[i].x == p[i + 1].x){
			ans += abs(p[i].y - p[i + 1].y);
			mid = min(mid, min(p[i].y, p[i + 1].y));
			mxu = max(mxu, max(p[i].y, p[i + 1].y));
		}
		else {
			ans += abs(p[i].x - p[i + 1].x);
			mil = min(mil, min(p[i].x, p[i + 1].x));
			mxr = max(mxr, max(p[i].x, p[i + 1].x));
		}
	}
	printf("%d", ans - ((mxr - mil + mxu - mid) << 1));
	return 0;
}

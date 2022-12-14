#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxb 20
#define maxn 600020
#define pb push_back
#define ll long long int 
using namespace std;   

int n, m;
int h[maxn];

struct ele{
	int x, y;
	double d;
	ele(int x, int y) : x(x), y(y){}
	ele(){}
	bool operator < (const ele b) const{
		return (d == b.d) ? x < b.x : d > b.d;
	}
}p[maxn];

bool segl(int i, double k, double b, double& ans){
	if (h[i] <= k * i + b) {ans = i; return true;}
	if (h[i + 1] > k * (i + 1) + b) return false;
	ll _k = h[i + 1] - h[i];
	ll _b = (ll)h[i] * (i + 1) - (ll)h[i + 1] * i;
	if (k == _k) return false;
	else {
		ans = (double)(_b - b) / (k - _k); 
		if (ans < i || i + 1 < ans) return false;
		return true;
	}
}

void play(double k){
	rep(i, 0, n) p[i].d = p[i].y - k * p[i].x;
	sort(p, p + 1 + n);
	double res = -1; bool ok = 0;
	int ptr = 0; 
	double ansx = 0;
	while (ptr < n){ 
		if (ptr == p[0].x) break;
		if (segl(ptr, k, p[0].d, ansx)){ 
			res = p[0].x - ansx;
			ok = 1; 
			break;
		}
		else ptr++;
	}
	rep(i, 1, n){
		while (ptr != p[i].x && !segl(ptr, k, p[i].d, ansx)) ptr++;
		if (ptr != p[i].x) {
			if (!ok) {
				res = p[0].x - ansx;
				ok = 1; 
			}
			else {
				res = max(res, p[i].x - ansx);
			}
		} 
	}
	if (ok) printf("%.8lf\n", res);
	else printf("-1\n");
}

int main(){ 
	scanf("%d%d", &n, &m);
	rep(i, 0, n) scanf("%d", h + i), p[i] = ele(i, h[i]);
	double k;
	rep(i, 1, m){	
		scanf("%lf", &k);
		play(k);
	} 
	return 0;
}


/*
9 7
2
3 
4
-1
3
4
6
2
6
*/



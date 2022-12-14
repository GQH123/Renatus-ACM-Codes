#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define maxr 100000
#define maxn 220
#define maxm
#define M
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
int n, m;
struct point{
	int x, y;
	point(int x, int y) : x(x), y(y){}
	point(){}
	bool operator < (const point b) const{
		return (x == b.x) ? y < b.y : x < b.x;
	}
}p[maxn], a[maxn];
point operator - (point a, point b){
	return point(a.x - b.x, a.y - b.y);
}
int cross(point a, point b){
	return a.x * b.y - a.y * b.x;
}
point con[maxn];
int cc = 0;
void get_Convex(){
	sort(p + 1, p + 1 + n);
	rep(i, 1, n){
		while (cc > 1 && cross(con[cc] - con[cc - 1], p[i] - con[cc - 1]) >= 0) cc--;
		con[++cc] = p[i];
	}
	int k = cc;
	per(i, n - 1, 1){
		while (cc > k && cross(con[cc] - con[cc - 1], p[i] - con[cc - 1]) >= 0) cc--;
		con[++cc] = p[i];
	}
	//con[cc + 1] = con[1];
}

bool judge(int x){
	bool f0 = 0, f1 = 0;
	srep(i, 1, cc){
		int d = cross(con[i] - a[x], con[i + 1] - a[x]);
		if (d >= 0) f1 = 1;
		if (d <= 0) f0 = 1;
	}
	if (f1 && f0) return 1;
	else return 0;
}


int main(){
	
		#ifndef ONLINE_JUDGE
			freopen("H.in", "r", stdin);
		#endif
	
	int T;
	scanf("%d", &T);
	rep(TT, 1, T){
		if (TT != 1) printf("\n");
		printf("Case %d\n", TT);
		scanf("%d%d", &n, &m);
		rep(i, 1, n) scanf("%d%d", &p[i].x, &p[i].y);
		get_Convex();
		per(i, cc, 1) printf("%d %d\n", con[i].x, con[i].y);
		rep(i, 1, m) scanf("%d%d", &a[i].x, &a[i].y);
		rep(i, 1, m) {
			if (!judge(i)) {
				printf("%d %d is unsafe!\n", a[i].x, a[i].y);
			}
			else {
				printf("%d %d is safe!\n", a[i].x, a[i].y);
			}
		}
		cc = 0;
	}
	
	return 0;
}

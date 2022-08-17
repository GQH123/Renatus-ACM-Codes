#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int
#define maxn 2020
#define maxm 
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back

using namespace std;

int r, c, n, s, t;
struct point{
	int x, y, r;
	point(int x, int y, int r) : x(x), y(y), r(r){}
	point(){}
}p[maxn];


int ufs[maxn];
int find_root(int x){
	return ufs[x] = (ufs[x] == x) ? x : find_root(ufs[x]);
}
inline void merge(int x, int y){
	x = find_root(x), y = find_root(y);
	ufs[x] = y;
}

int main(){

	freopen("A.in", "r", stdin);
	
	int x, y, z;
	scanf("%d%d%d", &r, &c, &n);
	rep(i, 1, n) scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].r);
	s = 0, t = n + 1;
	rep(i, 0, n + 1) ufs[i] = i;
	rep(i, 1, n){
		if (p[i].y <= p[i].r || r - p[i].x <= p[i].r) merge(i, s);
		if (c - p[i].y <= p[i].r || p[i].x <= p[i].r) merge(i, t);
	}
	rep(i, 1, n){
		rep(j, i + 1, n){
			if ((p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y) <= (p[i].r + p[j].r) * (p[i].r + p[j].r)){
				merge(i, j);
			}
		}
	}
	if (find_root(s) == find_root(t)) printf("N");
	else printf("S");
	return 0;
}

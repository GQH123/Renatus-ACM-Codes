#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define maxn 200020
#define maxm
#define pii pair<int, int>
#define ll long long int 
#define fi first
#define se second
using namespace std;


int n, m;
pii p[maxn], q[maxn];

set<pii> dir;
int gcd(int x, int y){
	if (!y) return x;
	return gcd(y, x % y);
}
int main(){
	scanf("%d%d", &n, &m);
	rep(i, 1, n) {
		scanf("%d%d", &p[i].fi, &p[i].se); 
		if (!p[i].fi && !p[i].se) i--, n--;
	}
	rep(i, 1, m) scanf("%d%d", &q[i].fi, &q[i].se);
	rep(i, 1, n){
		int x = p[i].fi, y = p[i].se;
		int d = gcd(abs(x), abs(y));
		x /= d, y /= d;
		if (x < 0) x = -x, y = -y;
		else if (x == 0) y = abs(y);
		dir.insert(pii(x, y));
	}
	int si = dir.size();
	rep(i, 1, m){
		int x = q[i].fi, y = q[i].se;
		if (!x && !y) {
			printf("0\n");
			continue;
		}
		int d = gcd(abs(x), abs(y));
		x /= d, y /= d;
		if (x < 0) x = -x, y = -y;
		else if (x == 0) y = abs(y);
		
		if (dir.count(pii(x, y))) {
			printf("1\n");
			continue;
		}
		if (si == 1 || si == 0){
			printf("-1\n");
			continue;
		}
		else if (si == 2){
			if (n > 2) {
				printf("2\n");
				continue; 
			}
			else {
				if (q[i].fi == p[1].fi + p[2].fi && q[i].se == p[1].se + p[2].se){
					printf("3\n");
					continue; 
				}
				else {
					printf("2\n");
					continue; 
				}
			}  
		}
		else {
			printf("2\n");
			continue; 
		}
	}
	return 0;
}

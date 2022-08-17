#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define maxn 2020
#define maxm 
#define M 
#define ll long long int 
#define ld long double
#define pb push_back
#define pc putchar
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define lowbit(x) (x & -x)
using namespace std;

bool not_intersect(int a, int b, int c, int d){
	return b < c || d < a;
}
int gcd(int x, int y){
	if (!y) return x;
	return gcd(y, x % y);
}
int n, x[maxn], y[maxn], z[maxn];
int main(){
	while (scanf("%d", &n) == 1){
		rep(i, 1, n) scanf("%d%d%d", x + i, y + i, z + i);
		rep(i, 1, n){
			rep(j, i + 1, n){
				if (!not_intersect(y[i], z[i], y[j], z[j])) {
					printf("Cannot Take off\n");
					goto done;
				}
				int d = gcd(x[i], x[j]);
				if (z[i] < y[j]){
					ll mi = y[j] - z[i], mx = z[j] - y[i];
					if (mi % d == 0 || mx % d == 0) {
						printf("Cannot Take off\n");
						goto done;
					}
					if (mi / d != mx / d){
						printf("Cannot Take off\n");
						goto done;
					}
				}
				else {
					ll mi = y[i] - z[j], mx = z[i] - y[j];
					if (mi % d == 0 || mx % d == 0) {
						printf("Cannot Take off\n");
						goto done;
					}
					if (mi / d != mx / d){
						printf("Cannot Take off\n");
						goto done;
					}
				}
			}
		}
		printf("Can Take off\n");
		done:;
	}
	return 0;
}

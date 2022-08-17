#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define pii pair<int, int>
#define fi first
#define se second
#define maxn 200020
using namespace std;

char s[maxn], t[maxn];
struct ele{
	int x, y, id;
	ele(int x, int y, int id) : x(x), y(y), id(id){}
	ele(){}
	bool operator < (const ele b) const{
		return (y == b.y) ? ((x == b.x) ? id < b.id : x < b.x) : y < b.y;
	}
}q[maxn];

int n, m, k;
int lis[30][30];
int res[maxn];

int main(){
	int T, x, y;
	scanf("%d", &T);
	while (T--){
		scanf("%s", s + 1), n = strlen(s + 1);
		scanf("%s", t + 1), m = strlen(t + 1); 
		rep(j, 1, m) rep(i, 1, m) lis[i][j] = 1;
		scanf("%d", &k);
		rep(i, 1, k) scanf("%d%d", &x, &y), q[i] = ele(x, y, i); 
		sort(q + 1, q + 1 + k);
		int ptr = 1;
		rep(i, 1, n){
			rep(j, 1, m) {
				per(k, m, 1) {
					if (j + k > m) continue;
					if (s[i] != t[j + k]) continue;
					lis[j][k + 1] = lis[j][k];
				}
				if (s[i] == t[j]) lis[j][1] = -i; 
			}
			while (ptr <= k && q[ptr].y == i) {
				int x = q[ptr].x, mx = 0;
				rep(j, 1, m){
					int pos = upper_bound(lis[j] + 1, lis[j] + m + 1, -x) - lis[j] - 1;
					mx = max(mx, pos);
				}
				res[q[ptr].id] = m - mx + q[ptr].y - q[ptr].x + 1 - mx;
				ptr++;
			}
		}
		rep(i, 1, k) printf("%d\n", res[i]);
		rep(j, 1, m) rep(i, 1, m) lis[i][j] = 1;
	}
	return 0;
}

#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 220
#define maxk 11
using namespace std;

int n, k, a[(maxn << 1) * (1 << maxk)];
int lis[maxn << 1][1 << maxk];
int cs[maxn << 1];
int to[1 << maxk], _to[1 << maxk];

int main(){
	int T; scanf("%d", &T);
	while (T--){
		scanf("%d%d", &n, &k);
		int l = 2 * n * (1 << k);
		rep(i, 1, l) scanf("%d", a + i);
		rep(i, 1, (1 << k)) to[i] = i;
		int st = 1, ed = 0;
		per(i, k - 1, 1){
			ed = st + (1 << i); 
			reverse(to + st, to + ed);
			st = ed;
		}
		rep(i, 1, (1 << k)) _to[i] = to[(1 << k) + 1 - to[i]];
		//rep(i, 1, (1 << k)) to[i] = _to[i];
		//rep(i, 1, (1 << k)) printf("%d ", to[i]); printf("\n");
		int _n = (n << 1), now = _n, d = -1;
		rep(i, 1, l) {
			lis[now][++cs[now]] = a[i];
			now += d;
			if (!now) {
				now = 1;
				d = 1;
			}
			else if (now == _n + 1){	
				now = _n;
				d = -1;
			}
		}
		rep(i, 1, _n) assert(cs[i] == (1 << k));
		int stt = (1 << k) - 1; bool dd = 1;
		rep(i, 1, _n){
			stt = (1 << k) - 1; dd = 1;
			rep(j, 1, (1 << k)){
				if (j == 1 && i == 1) printf("%d", lis[i][stt]);
				else printf(" %d", lis[i][stt]);
				//printf("%d ", lis[i][stt]);
				if (dd) stt = (1 << k) + 1 - stt;
				else stt = to[stt];
				dd ^= 1;
			}
		}
		printf("\n");
		rep(i, 1, _n) cs[i] = 0;
	}
	return 0;
}

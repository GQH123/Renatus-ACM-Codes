#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 300020
using namespace std;

const int inf = 2000000000;

struct pii{
	int l, r;
	pii(int l, int r) : l(l), r(r){}
	pii(){}
};

pii val[maxn];

pii intersect(pii a, pii b){ 
	return pii(max(a.l, b.l), min(a.r, b.r));
}

int n, k;
int main(){
	int T, x, y; scanf("%d", &T);
	while (T--){
		scanf("%d%d", &n, &k);
		rep(i, 1, n){
			scanf("%d%d", &x, &y);
			val[i] = pii(x, y);
		}
		int now;
		
		per(i, n - 1, 1){
			val[i] = intersect(val[i], pii(val[i + 1].l - k, val[i + 1].r + k));
			if (val[i].l > val[i].r) {
				printf("NO\n");
				goto done;
			}
		}
		printf("YES\n"); 
		now = val[1].l;
		rep(i, 1, n){
			if (i != 1) printf(" ");
			printf("%d", now);
			if (val[i + 1].l <= now && now <= val[i + 1].r) now = now;
			else {
				if (now > val[i + 1].r) now = val[i + 1].r;
				else now = val[i + 1].l;
			}
		}
		printf("\n");
		done:;
	}
	return 0;
}

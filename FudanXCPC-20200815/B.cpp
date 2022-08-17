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
#define maxn 2000020
#define maxm
using namespace std;

int n, m, a[maxn];
//int pre[maxn][10]; 

inline int getroot(int x){
	if (!x) return 0;
	return (x - 1) % 9 + 1;
}

vector<pii> q[maxn];
int bit[maxn];
int res[maxn][5];

int last[maxn][10], noww[10], pre[maxn];

int main(){
	int T, x, y; scanf("%d", &T);
	rep(TT, 1, T){
		printf("Case #%d:\n", TT);
		scanf("%d", &n);
		int prenum = 0;
		rep(i, 0, 9) noww[i] = -1;
		noww[0] = 0;
		rep(i, 1, n) {
			scanf("%d", a + i); 
			//if (x != 0) x = (x - 1) % 9 + 1;
			a[i] = getroot(a[i]);
			
			prenum += a[i], prenum = getroot(prenum);
			rep(j, 0, 9) last[i][j] = noww[j];
			noww[prenum] = i; 
			pre[i] = prenum;
		}
		scanf("%d", &m); 
		rep(i, 1, m){
			scanf("%d%d", &x, &y);
			q[y].push_back(pii(x, i));
		}
		//rep(i, 1, n) sort(q[i].begin(), q[i].end()); 
		rep(i, 1, n){
			/*
			int now = a[i], mask = 0, hav = 0;
			mask |= (1 << now);
			per(j, i, 1){
				hav |= (mask & bit[j]);
				if (hav == 1023) break;
				mask ^= (mask & bit[j]);
				bit[j] |= mask;
				now = getroot(now + a[j - 1]);
				if (!(hav & (1 << now))) mask |= (1 << now);
			}
			*/
			if (a[i]) {
				rep(j, 0, 9){
					if (last[i][j] == -1) continue;
					int k = getroot(pre[i] + 9 - j), st = last[i][j] + 1;
					per(l, st, 1){
						if (!(bit[l] & (1 << k))) bit[l] |= (1 << k);
						else break;
					}
				}
			}
			else{
				int k = 0, st = i;
				per(l, st, 1){
					if (!(bit[l] & (1 << k))) bit[l] |= (1 << k);
					else break;
				}
			}
			int si = q[i].size();
			srep(j, 0, si) {
				pii op = q[i][j];
				int ct = 0, x = op.fi, id = op.se;
				per(k, 9, 0) {
					if (ct == 5) break;
					if (bit[x] & (1 << k)) {
						res[id][ct++] = k;
					}
				}
				while (ct < 5) res[id][ct++] = -1;
			}
		}
		rep(i, 1, m) {
			rep(j, 0, 4) { 
				if (j) printf(" ");
				printf("%d", res[i][j]);
			}
			printf("\n");
		} 
		if (TT != T) printf("\n");
		rep(i, 1, n) bit[i] = 0, q[i].clear();
	}
	return 0;
}

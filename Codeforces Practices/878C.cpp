#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxr 100000
#define maxn 100019
#define pii pair<int, int>
#define fi first
#define se second
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

int n, k;
int a[maxn][11];

int cnt = 0;
int num[maxn];
set<pii> mi[11], mx[11];
set<pii> :: iterator it1, it2, it3;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("878C.in", "r", stdin);
	#endif
	read(n), read(k);
	mi[1].insert(pii(1, 1));
	it1 = mi[1].begin(), it2 = mi[1].end();
	rep(i, 1, n) {
		rep(j, 1, k) read(a[i][j]); 
		if (!cnt) {
			cnt++;
			rep(j, 1, k) mi[j].insert(pii(a[i][j], cnt)), mx[j].insert(pii(a[i][j], cnt));
			num[cnt] = 1;
		}
		else {
		
			bool mxx = 1;
			rep(j, 1, k) if (a[i][j] < mx[j].rbegin() -> fi) {mxx = 0; break;} 
			if (mxx){
				cnt++;
				rep(j, 1, k) mi[j].insert(pii(a[i][j], cnt)), mx[j].insert(pii(a[i][j], cnt));
				num[cnt] = 1;
				continue;
			}
			
			bool mii = 1;
			rep(j, 1, k) if (a[i][j] > mi[j].begin() -> fi) {mii = 0; break;}
			if (mii){
				cnt++;
				rep(j, 1, k) mi[j].insert(pii(a[i][j], cnt)), mx[j].insert(pii(a[i][j], cnt));
				num[cnt] = 1;
				continue;
			}
			
			rep(j, 1, k){
				it1 = mx[j].lower_bound(pii(a[i][j], 0));
				while (1){
					if (it 
				}
				//left = min(left, lower_bound(mx[j] + 1, mx[j] + 1 + cnt, a[i][j]) - mx[j]);
				//right = max(right, upper_bound(mi[j] + 1, mi[j] + 1 + cnt, a[i][j]) - mi[j] - 1);
				for (it = it1; it != it2; it++){
					it3 = it, it3++;
					if (it3 == 1t2) break;
					num[it3 -> se] += num[it -> se];
					erase(
				}
			}
		}
	}
	
	return 0;
}

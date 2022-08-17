#include <bits/stdc++.h>
#define maxr 100000
#define maxn 21
#define maxb 1000000
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define ll long long int 
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}
struct ele{
	int x, y;
	bool operator < (const ele b) const{
		return (y - x == b.y - b.x) ? (y > b.y) : (y - x < b.y - b.x);
	}
	ele(int x, int y) : x(x), y(y){}
	ele(){}
}lis[maxn * maxn * 2];
int cs = 0;
int n; ll k;
ll fac[maxn];
int ans[maxn];
bool vis[maxn];
void init(){
	fac[0] = 1; 
	srep(i, 1, maxn) fac[i] = fac[i - 1] * i;
}
struct ele2{
	int num[9];
	bool operator < (const ele2 b) const{
		srep(i, 1, n)
			if (num[i] - num[i - 1] != b.num[i] - b.num[i - 1]) {
				return (num[i] - num[i - 1]) < (b.num[i] - b.num[i - 1]);
			}
	}
}per[maxb];
int a[maxn];
int main(){
	#ifndef ONLINE_JUDGE
		freopen("E.in", "r", stdin);
	#endif
	init();
	int T;
	read(T);
	while (T--){
		read(n), read(k);
		if (n >= 10){
			cs = 0;
			rep(i, 1, n){
				vis[i] = 0;
				rep(j, i + 1, n) {
					lis[++cs] = ele(i, j);
					lis[++cs] = ele(j, i);
				}
			}
			sort(lis + 1, lis + 1 + cs);
			int now = -1;
			rep(i, 1, cs){
				if (k > fac[n - 2]) k -= fac[n - 2];
				else {now = i; break;}
			}
			ans[1] = lis[now].x, ans[2] = lis[now].y;
			vis[ans[1]] = vis[ans[2]] = 1;
			rep(i, 3, n){
				rep(j, 1, n){
					if (vis[j]) continue;
					if (k > fac[n - i]) k -= fac[n - i];
					else {
						ans[i] = j, vis[j] = 1;
						break;
					}
				}
			}
			printf("%d", ans[1]); rep(i, 2, n) printf(" %d", ans[i]); printf("\n");
		}
		else {
			rep(i, 1, n) a[i] = i;
			rep(j, 1, fac[n]){
				srep(i, 0, n) per[j].num[i] = a[i + 1];
				next_permutation(a + 1, a + 1 + n);
			}
			sort(per + 1, per + 1 + fac[n]);
			printf("%d", per[k].num[0]); srep(i, 1, n) printf(" %d", per[k].num[i]); printf("\n");
		}
	}
	return 0;
}

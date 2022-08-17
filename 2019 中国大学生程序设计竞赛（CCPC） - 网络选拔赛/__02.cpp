#include <bits/std++.h>
#define maxm 
#define maxnode 
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
using namespace std;

int n, m;
int a[maxn];
int h[maxm];
int sum[maxnode];
int ct = 0;
int qx, qy, qd;
void add(int l, int r, int& o){
	if (!o) o = ++ct;
	sum[o] += qd;
	if (l == r) return; 
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) add(l, mid, ch[o][0]);
	else add(mid + 1, r, ch[o][1]);
}
int getsum(int l, int r, int o){
	if (!o) return 0;
	if (qx <= l && r <= qy) return sum[o];
	int mid = ((r - l) >> 1) + l, ans = 0;
	if (qx <= mid) ans += getsum(l, mid, ch[o][0]);
	if (qy > mid) ans += getsum(mid + 1, r, ch[o][1]);
	return ans;
}
int get(int l, int r, int& o){
	if (!o) o = ++ct;
	if (l == r) return (sum[o]) ? -1 : l; 
	int mid = ((r - l) >> 1) + l, ans = -1;
	if (qx <= mid && (qy = mid, getsum(l, r, o) < (mid - qx + 1))){
		return get(l, mid, ch[o][0]);
	}
	else return get(mid + 1, r, ch[o][1]);
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("02.in", "r", stdin);
	#endif
	int T;
	scanf("%d", &T);
	while (T--){
		scanf("%d%d", &n, &m);
		rep(i, 1, n) scanf("%d", &a[i]);
		rep(i, 1, n) hei[i] = 1;
		rep(i, 1, n) qx = a[i], qd = 1, add(1, n, hei[i]); 
		rep(i, 1, m){
			scanf("%d", &op);
			if (op == 1){
				scanf("%d", &qx);
				qd = -1, add(1, n, hei[i]), hei[i]++;
				qd = 1, add(1, n, hei[i]);
			}
			else if (op == 2){
				scanf("%d%d", 
			}
		}
	}
	return 0;
}

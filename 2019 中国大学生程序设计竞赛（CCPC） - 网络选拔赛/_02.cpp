#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define lowbit(x) (x & -x)
#define maxn 100019
#define maxm 100019
#define maxnode 30000000
using namespace std;

int n, m;
int a[maxn];

int h[maxn];
int qx, qy, qd;
int sum[maxnode];
int ct = 0;
int ch[maxnode][2];
bool exi[maxn];
void insert(int l, int r, int& o){
	if (!o) o = ++ct;
	sum[o] += qd;
	if (l == r) return;
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) insert(l, mid, ch[o][0]);
	else insert(mid + 1, r, ch[o][1]);
}
int get(int l, int r, int o){
	if (!o) return 0;
	if (qx <= l && r <= qy) return sum[o];
	int mid = ((r - l) >> 1) + l, ans = 0;
	if (qx <= mid) ans += get(l, mid, ch[o][0]);
	if (qy > mid) ans += get(mid + 1, r, ch[o][1]);
	return ans;
}
void add(int x, int d){
	qx = a[x], qd = d;
	while (x <= n){
		insert(1, n, h[x]);
		x += lowbit(x);
	}
}
int get(int x, int r){
	int ans = 0;
	qx = 1, qy = r;
	if (qx > qy) return 0;
	while (x){
		ans += get(1, n, h[x]);
		x -= lowbit(x);
	}
	return ans;
}

int solve(int k, int l, int r, int x){
	if (l == r) return l;
	int mid = ((r - l) >> 1) + l;
	if (get(x, mid) - get(x, k - 1) < mid - k + 1) return solve(k, l, mid, x);
	else return solve(k, mid + 1, r, x);
}

int lastans = 0;
void recover(){
	lastans = 0;
	rep(i, 1, ct) sum[i] = ch[i][0] = ch[i][1] = 0;
	ct = 0;
	rep(i, 1, n) h[i] = 0;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("02.in", "r", stdin);
	#endif
	int T, x, y, z;
	scanf("%d", &T);
	while (T--){
		scanf("%d%d", &n, &m);
		rep(i, 1, n) scanf("%d", &a[i]), add(i, 1), exi[i] = 1;
		rep(i, 1, m){
			scanf("%d", &x);
			if (x == 1){
				scanf("%d", &x);
				x ^= lastans;
				if (!exi[x]) continue;
				add(x, -1);
				exi[x] = 0;
			}
			else if (x == 2){
				scanf("%d%d", &x, &y);
				x ^= lastans, y ^= lastans;
				printf("%d\n", lastans = solve(y, y, n + 1, x));
			}
		}
	}
	return 0;
}

#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define maxn 300019
#define maxn2 600019
#define pii pair<int, int>
#define fi first
#define se second
#define lowbit(x) (x & (-x))
#define ll long long int 
using namespace std;

int n, m, v, p;
int a[maxn];
/*pii pro[maxn];
int cp = 0;

int c[maxn2];
void add(int x, int v){
	while (x){
		c[x] += v;
		x -= lowbit(x);
	}
}
int get(int x){
	int ans = 0;
	while (x < maxn2) {
		ans += c[x];
		x += lowbit(x);
	}
	return ans;
}

int lis[maxn2];
int cs = 0;*/

int num[maxn2];
bool judge(int x){
	int sum = x;
	int pos = upper_bound(a + 1, a + 1 + n, a[x] + m) - a;
	if (n + 1 - pos >= p) return false;
	sum += p - 1;
	if (sum >= v) return true;
	//if (sum >= m) return true;
	//sper(i, pos - 1, x) b[i] = a[i];
	//rep(i, 1, n) num[i] = 0; 
	//int suf = 0, acc = 0;
	ll acc = 0;
	sper(i, n - p + 1, x){
		//num[i] = a[x] + m - 1 - a[i] - suf;
		//acc += num[i];
		//suf = suf + num[i] - num[i + v - sum - 1];
		acc += a[x] + m - a[i];
	}
	return acc >= (ll)m * (v - sum);
}
int solve(int l, int r){
	while (l < r){
		int mid = ((r - l) >> 1) + l;
		if (judge(mid)) r = mid;
		else l = mid + 1;
	}
	return l;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("B.in", "r", stdin);
	#endif
	scanf("%d%d%d%d", &n, &m, &v, &p);
	rep(i, 1, n) scanf("%d", &a[i]);
	//rep(i, 1, n) lis[++cs] = a[i], lis[++cs] = a[i] + m;
	//sort(lis + 1, lis + 1 + cs);
	//cs = unique(lis + 1, lis + 1 + cs) - lis - 1;
	sort(a + 1, a + 1 + n);
	//rep(i, 1, n) printf("%d ", a[i]); printf("\n");
	//printf("%d\n", solve(1, n));
	printf("%d", n - solve(1, n) + 1);
	
	/*srep(i, 1, v) add(lower_bound(lis + 1, lis + 1 + cs, a[i] + m) - lis, 1);
	rep(i, v, n) add(lower_bound(lis + 1, lis + 1 + cs, a[i]) - lis, 1);
	int ans = 0;
	add(lower_bound(lis + 1, lis + 1 + cs, a[v]) - lis, -1);
	add(lower_bound(lis + 1, lis + 1 + cs, a[v] + m) - lis, 1);
	srep(i, 1, v) if (get(lower_bound(lis + 1, lis + 1 + cs, a[i] + m) - lis + 1) < p) ans++; 
	add(lower_bound(lis + 1, lis + 1 + cs, a[v]) - lis, 1);
	add(lower_bound(lis + 1, lis + 1 + cs, a[v] + m) - lis, -1);
	rep(i, v, n) if (get(lower_bound(lis + 1, lis + 1 + cs, a[i] + m) - lis + 1) < p) ans++;
	printf("%d", ans);
	//rep(i, 1, n) b[i] = a[i];
	//srep(i, 1, v) b[i] += m;
	//sort(b + 1, b + 1 + n);
	//int ans = 0;
	//rep(i, v, n) ans += ((1 + b + 1 + n - upper_bound(b + 1, b + 1 + n, a[i] + m)) <= p) ? 1 : 0; 
	
	/*rep(i, 1, n){
		int now = a[i], _i = i;
		while (i <= n && a[i] == now) i++;
		pro[++cp] = pii(now, i - _i);
		i--;
	}
	int sum = 0, ans = 0;
	per(i, cp, 1){
		if (sum < p) sum += pro[i].se, ans += pro[i].se;
		else {
			
		}
	}*/
	return 0;
}

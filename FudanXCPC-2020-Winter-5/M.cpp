#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int
#define maxn 200020
#define maxm 
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back

using namespace std;

int n, c, t;
int a[maxn];
int mx = 0;

bool judge(int times){
	ll amo = (ll)times * t;
	if (amo < mx) return false;
	ll sum = 0;
	int ans = 0;
	rep(i, 1, n){
		ans++;
		while (i <= n && sum + a[i] <= amo){
			sum += a[i];
			i++;
		}
		i--;
		sum = 0;
	}
	return ans <= c;
}
int solve(int l, int r){
	if (l == r) return l;
	int mid = ((r - l) >> 1) + l;
	if (judge(mid)) return solve(l, mid);
	else return solve(mid + 1, r);
}

int main(){
	freopen("M.in", "r", stdin);
	
	scanf("%d%d%d", &n, &c, &t);
	rep(i, 1, n) scanf("%d", &a[i]), mx = max(mx, a[i]);
	printf("%d", solve(1, 2000000020));
	return 0;
}


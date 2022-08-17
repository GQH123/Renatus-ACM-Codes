#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int
#define maxn 300020
#define maxm 
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back

using namespace std;

int n;
int a[maxn];

int main(){
	freopen("F.in", "r", stdin);
	
	scanf("%d", &n);
	rep(i, 1, n) {
		scanf("%d", &a[i]);
		if (a[i] > 0) a[i] = 1;
		else if (a[i] == 0) a[i] = 0;
		else a[i] = -1;
	}
	ll tot0 = 0, tot1 = 0, tot_ = 0, ans0 = 0, ans1 = 0, ans_ = 0;
	rep(i, 1, n){
		if (a[i] == 1) ans1++;
		else if (a[i] == 0) ans0 = i, ans1 = ans_ = 0;
		else swap(ans1, ans_), ans_++;
		tot0 += ans0, tot1 += ans1, tot_ += ans_;
	}
	printf("%lld %lld %lld", tot_, tot0, tot1);
	return 0;
}


#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define maxn 300020
#define maxm 
#define M 
#define ll long long int 
#define ld long double
#define pb push_back
#define pc putchar
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define lowbit(x) (x & -x)
#define prev PREV
using namespace std;

int n, m[maxn], v[maxn], lis[maxn];
ll prem[maxn], prev[maxn];
int ans[maxn], cs = 0;

bool cmp(const int i, const int j){
	return (ll)v[i] * m[j] < (ll)v[j] * m[i];
}

int main(){
	while (scanf("%d", &n) == 1 && n){
		cs = 0;
		rep(i, 1, n) scanf("%d%d", m + i, v + i), lis[i] = i;
		sort(lis + 1, lis + 1 + n, cmp);
		rep(i, 1, n) cerr << lis[i] << ' '; cerr << endl;
		rep(i, 1, n) prem[i] = prem[i - 1] + m[lis[i]];
		rep(i, 1, n) prev[i] = prev[i - 1] + v[lis[i]];
		per(i, n, 2) if (prem[i - 1] * (prev[i - 1] - v[lis[i - 1]] + v[lis[i]]) < prev[i - 1] * (prem[i - 1] - m[lis[i - 1]] + m[lis[i]])) ans[++cs] = n - i + 1; 
		printf("%d\n", cs);
		rep(i, 1, cs) printf("%d\n", ans[i]);
	}
	return 0;
}

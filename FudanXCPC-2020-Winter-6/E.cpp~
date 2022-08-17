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

int n, k;
char s[maxn];


inline ll cal(int x){
	return (x + 1) * (ll)x >> 1;
}

int main(){
	freopen("E.in", "r", stdin);
	scanf("%s", s + 1);
	scanf("%d", &k);
	n = strlen(s + 1);
	
	int pre = 0, suf = 0;
	
	int ptr = 1;
	while (ptr <= n && s[ptr] == 'P') ptr++, pre++;
	ptr = n;
	while (ptr >= 1 && s[ptr] == 'P') ptr--, suf++;
	
	if (pre == n || suf == n) {
		printf("0");
		return 0;
	}
	ll ans = 0;
	if (k < n) ans = (ll)n * k;
	else ans = (ll)n * (n - 1) + 1;
	bool f = 1;
	rep(i, 1, n){
		int _i = i;
		while (i <= n && s[i] != 'P') i++;
		int sum = 0;
		while (i <= n && s[i] == 'P') i++, sum++; i--;
		if (!((pre && f) || (suf && (i == n)))){
			ll ssum = cal(sum);
			if (sum - k + 1 > 1) ssum -= cal(sum - k);
			ans -= ssum;
		}
		f = 0;
	}
	int sum = pre + suf;
	ll ssum = cal(sum);
	if (sum - k + 1 > 1) ssum -= cal(sum - k);
	ans -= ssum;
	printf("%lld", ans);
	return 0;
}


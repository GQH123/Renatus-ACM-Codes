#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
#define maxr 100000
#define maxn 10000020
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char s[maxn], t[maxn];

int main(){
	
		#ifndef ONLINE_JUDGE
			freopen("C.in", "r", stdin);
		#endif
	
	scanf("%s%s", s + 1, t + 1);
	int n = strlen(s + 1);
	int m = strlen(t + 1), _m = m;
	rep(i, 1, n) t[++m] = ((s[i] - 'A') - (t[i] - 'A') + 26) % 26 + 'A'; 
	printf("%s", t + _m + 1);
	return 0;
}

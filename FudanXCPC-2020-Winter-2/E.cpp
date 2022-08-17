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
#define maxn 220
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

int n;

char s[maxn];

int main(){
	
		#ifndef ONLINE_JUDGE
			freopen("E.in", "r", stdin);
		#endif
	
	
	scanf("%s", s + 1);
	n = strlen(s + 1);
	int ans = n;
	rep(l, 1, n) rep(r, l, n){
		int nowans = n + r - l + 1;
		int len = r - l + 1;
		rep(i, 1, n){
			bool f = 1;
			rep(j, 1, len){
				if (s[i + j - 1] != s[l + j - 1]) {
					f = 0;
					break;
				}
			}
			if (f) {
				i += len - 1;
				nowans -= (len - 1);
			}
		}
		ans = min(nowans, ans);
	}
	printf("%d", ans);
	return 0;
}

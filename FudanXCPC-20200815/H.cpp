#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
#define maxn 2020
#define maxm
using namespace std;

char s[maxn], t[maxn];
int a[maxn], b[maxn];
int main(){
	int T; scanf("%d", &T);
	rep(TT, 1, T){
		printf("Case #%d: ", TT); 
		scanf("%s%s", s + 1, t + 1);
		int n = strlen(s + 1);
		rep(i, 1, n) a[i] = ((s[i] - 'a') & 1), b[i] = ((t[i] - 'a') & 1);
		if (n == 1){
			if (a[1] == b[1]) printf("YES\n");
			else printf("NO\n");
		}
		else if (n == 2){
			bool f = 0;
			rep(i, 0, 25){
				if (s[1] == t[1] && s[2] == t[2]) {
					f = 1; break;
				}
				swap(s[1], s[2]);
				if (s[1] == 'z') s[1] = 'a';
				else s[1]++;
				if (s[2] == 'z') s[2] = 'a';
				else s[2]++;
			}
			if (f) printf("YES\n");
			else printf("NO\n");
		}
		else {
			int na = 0, nb = 0;
			rep(i, 1, n) if (a[i] == 1) na++;
			rep(i, 1, n) if (b[i] == 1) nb++;
			if ((na & 1) == (nb & 1)) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}

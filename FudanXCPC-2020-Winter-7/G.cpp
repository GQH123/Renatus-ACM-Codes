#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int
#define maxn 400020
#define maxm 
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back

using namespace std;

int n;
char s[maxn], t[maxn];

int abp = 0, bap = 0;

pii ans[maxn];
int cs = 0;

int main(){
	freopen("G.in", "r", stdin);
	scanf("%d", &n);
	scanf("%s%s", s + 1, t + 1);
	rep(i, 1, n){
		if (s[i] == t[i]) continue;
		if (s[i] == 'a' && t[i] == 'b'){
			if (abp){
				ans[++cs] = pii(abp, i);
				abp = 0;
			}
			else abp = i;
		}
		else if (s[i] == 'b' && t[i] == 'a'){
			if (bap){
				ans[++cs] = pii(bap, i);
				bap = 0;
			}
			else bap = i;
		}
	}
	if (bap && abp) ans[++cs] = pii(bap, bap), ans[++cs] = pii(bap, abp); 
	else if (bap || abp){
		printf("-1");
		return 0;
	}
	printf("%d\n", cs);
	rep(i, 1, cs) printf("%d %d\n", ans[i].fi, ans[i].se);
	return 0;
}


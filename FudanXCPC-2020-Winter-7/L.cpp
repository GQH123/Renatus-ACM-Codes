#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int
#define maxn 2020
#define maxm 
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back

using namespace std;

const int inf = 2000000020;

int n, k;
char s[3][maxn];

int main(){
	freopen("L.in", "r", stdin);
	
	scanf("%d%d", &n, &k);
	rep(i, 1, 2) scanf("%s", s[i] + 1);
	
	int mi = inf, mi2 = -1, mi3 = -1;
	rep(i, 1, n){
		int mx = 0;
		rep(j, 1, n){
			if (s[1][j] == '1') mx = max(mx, abs(i - j));
			if (s[2][j] == '1') mx = max(mx, i + j + k);
		}
		if (mx < mi) {
			mi = mx;
			mi2 = 2;
			mi3 = i;
		}
	}
	
	rep(i, 1, n){
		int mx = 0;
		rep(j, 1, n){
			if (s[2][j] == '1') mx = max(mx, abs(i - j));
			if (s[1][j] == '1') mx = max(mx, i + j + k);
		}
		if (mx < mi) {
			mi = mx;
			mi2 = 1;
			mi3 = i;
		}
	}
	
	printf("%d\n%d %d", mi, mi2, mi3);
	return 0;
}


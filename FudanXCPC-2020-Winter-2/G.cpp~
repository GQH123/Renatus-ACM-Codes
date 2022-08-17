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
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

int n, s[4];
int peg[4][64];//1 = start, 3 = desti
int pos[64];

ll get_rank(int n, int A, int B){
	if (pos[n] != A && pos[n] != B) return -1;
	if (n == 1){
		if (pos[1] == A) return 1;
		else return 2;
	}
	else if (pos[n] == A) {
		ll ans = get_rank(n - 1, A, 6 - B - A);
		if (ans == -1) return -1;
		else return ans;
	}
	else {
		ll ans = get_rank(n - 1, 6 - B - A, B);
		if (ans == -1) return -1;
		else return ans + (1ll << (n - 1));
	}
}

int main(){
	
		#ifndef ONLINE_JUDGE
			freopen("G.in", "r", stdin);
		#endif
		
	rep(i, 1, 3) {
		scanf("%d", &s[i]), n += s[i];
		rep(j, 1, s[i]) scanf("%d", &peg[i][j]); 
	}
	rep(i, 1, 3) srep(j, 1, s[i]){
		if (peg[i][j] < peg[i][j + 1]) {
			printf("No");
			return 0;
		}
	}
	rep(i, 1, 3) rep(j, 1, s[i]) pos[peg[i][j]] = i; 
	ll ans = get_rank(n, 1, 3);
	if (ans == -1) printf("No");
	else printf("%lld", (1ll << n) - ans);
	return 0;
}

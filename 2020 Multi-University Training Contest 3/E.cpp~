#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define M    1000000007
#define inv2 500000004
#define inv3 333333336
#define maxn 200020
#define pii pair<int, int>
#define fi first
#define se second
#define mo(x) (x = (x >= M) ? (x - M) : x)
using namespace std;

int n, sa1, sa2, ans = 0;
int s1[maxn], s2[maxn], ufs[maxn]; 

inline int cal2(int x){
	return 1ll * x * (x - 1) % M * inv2 % M;
}
inline int cal3(int x) {
	return 1ll * x * (x - 1) % M * (x - 2) % M * inv2 % M * inv3 % M;
}
 
int find_root(int x){
	return ufs[x] = (ufs[x] == x) ? x : find_root(ufs[x]);
}
void merge(int x, int y){
	x = find_root(x), y = find_root(y);
	if (x == y) return;
	ans += M - 1ll * s2[x] * s2[y] % M * (sa2 - s2[x] - s2[y] + sa1 - s1[x] - s1[y]) % M, mo(ans);
	ans += M - 1ll * s1[x] * s2[y] % M * (sa2 - s2[x] - s2[y]) % M, mo(ans);
	ans += M - 1ll * s2[x] * s1[y] % M * (sa2 - s2[x] - s2[y]) % M, mo(ans);
	ufs[x] = y;
	s1[y] += s1[x];
	s2[y] += s2[x];
}

int main(){
	int T, x, y;
	scanf("%d", &T);
	while (T--){
		scanf("%d", &n);
		sa1 = 0, sa2 = 0, ans = 0; 
		rep(i, 1, n) {
			scanf("%d", &x);
			ufs[i] = i;
			s1[i] = s2[i] = 0;
			if (x == 1) s1[i] = 1, sa1++;
			else s2[i] = 1, sa2++;
		} 
		ans = (1ll * cal2(sa2) * sa1 % M + 1ll * cal3(sa2)) % M;
		printf("%d\n", ans);
		rep(i, 2, n) {
			scanf("%d%d", &x, &y);
			merge(x, y);
			printf("%d\n", ans);
		}
	}
	return 0;
}

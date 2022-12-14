#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 200020
#define M 199999
#define inv24 141666
using namespace std;

inline int cal(int x){
	return (3ll * x * x % M * x % M + 10ll * x * x % M + 9ll * x % M + 2ll) % M * x % M * x % M * inv24 % M;
}

char s[maxn];
int ans[M + 5];

int main(){
	ans[1] = cal(1);
	rep(i, 2, M) ans[i] = 1ll * ans[i - 1] * cal(i) % M;
	int T; scanf("%d", &T);
	while (T--){
		scanf("%s", s + 1);
		int n = strlen(s + 1);
		if (n >= 7) {
			printf("0\n");
		}
		else {
			int x = 0, res = 1;
			rep(i, 1, n) x = x * 10 + s[i] - '0';
			if (x >= M) printf("0\n");
			else printf("%d\n", ans[x]);
		}
	}
	return 0;
}

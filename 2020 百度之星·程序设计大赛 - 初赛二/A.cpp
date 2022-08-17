#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define maxn 
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
using namespace std;

int main(){
	int T, n, m, p;
	scanf("%d", &T);
	while (T--){
		scanf("%d%d%d", &n, &m, &p);  
		if (n >= m) {
			int d = (m * p - 1) / 100 + 1;
			printf("%d\n", (n - m) / d + 1); 
		}
		else printf("0\n");
	} 
	return 0;
}

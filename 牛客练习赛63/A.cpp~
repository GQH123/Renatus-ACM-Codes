#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ll long long int 
#define ld long double
#define lowbit(x) (x & -x)
#define mo(x) (x = (x >= M) ? (x - M) : x)
#define M 
#define B
#define maxn 205
#define maxs
#define maxm 
#define maxk
#define maxb
//#define DEBUG
using namespace std;

int n, a[maxn];

int main(){
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", a + i);
	sort(a + 1, a + 1 + n);
	rep(i, 1, n - 2){
		if (a[i] + a[i + 1] > a[i + 2]) {
			printf("%d %d %d\n", a[i], a[i + 1], a[i + 2]);
			return 0;
		}
	}
	printf("No solution");
	return 0;
}

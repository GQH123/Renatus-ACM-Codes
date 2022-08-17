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
#define maxn 
#define maxs
#define maxm 
#define maxk
#define maxb
//#define DEBUG
using namespace std;

int h, l, H, L;

int main(){
	scanf("%d%d%d%d", &h, &l, &H, &L);
	if (h * L <= H * l) printf("%.9lf", 1.0 * h * h * L / (2 * H));
	else printf("%.9lf", 1.0 * h * l - 1.0 * l * l * H / (2 * L));
	return 0;
}

#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define ll long long int 
#define pb push_back
#define pc putchar
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn 200020
#define maxm
#define maxs
#define maxb
#define M 
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

int n;
char _a[maxn], _b[maxn];
int ans[maxn << 2], a[maxn], b[maxn], cs = 0;
bool ok = 0;
int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		scanf("%d", &n);
		scanf("%s%s", _a + 1, _b + 1);
		rep(i, 1, n) a[i] = _a[i] - '0', b[i] = _b[i] - '0';
		int l = 1, r = n, ok = 0;
		per(i, n, 1){
			int x;
			if (l < r) x = a[i - 1 + l];
			else x = a[l - i + 1];
			x ^= ok;
			if (x == b[i]) {
				if (l < r) r--;
				else r++;
				continue;
			}
			x = a[l] ^ ok;
			if ((x ^ 1) != b[i]) {
				ans[++cs] = 1;
				a[l] ^= 1;
			}
			ans[++cs] = i;
			swap(l, r);
			ok ^= 1; 
			if (l < r) r--;
			else r++;
		}
		printf("%d", cs);
		rep(i, 1, cs) printf(" %d", ans[i]);
		printf("\n");
		cs = 0;
	}
	return 0;
}


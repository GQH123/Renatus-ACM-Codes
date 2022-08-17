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
#define maxn 200020
#define mxc 11
#define maxr 500000 
#define base 2333
#define M 1000000007
#define base2 3217
#define M2 998244353
#define rank RANK
#define mo(x, M) (x = (x >= M) ? (x - M) : x)
#define isdigit(ch) ('0' <= ch && ch <= '9')
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
void reads(char* s){
	char ch = gc(); int l = 0;
	while (!isdigit(ch)) ch = gc();
	while (isdigit(ch)) s[l++] = ch, ch = gc(); s[l] = '\0';
}
template<class T> void read(T& x){
	char ch = gc(); x = 0;
	while (!isdigit(ch)) ch = gc();
	while (isdigit(ch)) x = (x << 1) + (x << 3) + ch - '0', ch = gc();
} 

void exkmp(char* s, int* a, int n){
	a[0] = n; int p = 0, r = 0;
	srep(i, 1, n) {
		a[i] = (r > i) ? min(r - i, a[i - p]) : 0;
		while (i + a[i] < n && s[i + a[i]] == s[a[i]]) ++a[i];
		if (r < i + a[i]) r = i + a[i], p = i;
	}
}

int n, _n, m;
char s[maxn]; int a[maxn];
pii plis[maxn]; int cp = 0;
pii slis[maxn]; int cs = 0;

int main(){
	int T; read(T);
	rep(TT, 1, T){ 
		printf("Case %d: ", TT);
		reads(s);
		_n = n = strlen(s);
		srep(i, 0, n) s[i + n] = s[i]; s[n << 1] = '\0';
		_n <<= 1; m = 10; 
		exkmp(s, a, _n);
		//int pre = 0, mid = 1, suf = 0;
		//srep(i, 0, _n) cerr << a[i] << ' '; cerr << endl;
		int has = 0, mi = 1;
		int has2 = 0, mi2 = 1;
		rep(i, 1, n) mi = 1ll * mi * base % M, mi2 = 1ll * mi2 * base2 % M2;
		srep(i, 0, n) has = (1ll * has * base + s[i]) % M, has2 = (1ll * has2 * base2 + s[i]) % M2;
		srep(i, 1, n) {
			has = 1ll * has * base % M, has2 = 1ll * has2 * base2 % M2;
			has += M - 1ll * s[i - 1] * mi % M, mo(has, M);
			has2 += M2 - 1ll * s[i - 1] * mi2 % M2, mo(has2, M2);
			has += s[n + i - 1], mo(has, M);
			has2 += s[n + i - 1], mo(has2, M2);
			if (a[i] >= n) continue;
			if (s[i + a[i]] < s[a[i]]) plis[++cp] = pii(has, has2);
			if (s[i + a[i]] > s[a[i]]) slis[++cs] = pii(has, has2);
		}
		sort(plis + 1, plis + 1 + cp), cp = unique(plis + 1, plis + 1 + cp) - plis - 1;
		sort(slis + 1, slis + 1 + cs), cs = unique(slis + 1, slis + 1 + cs) - slis - 1;
		printf("%d %d %d\n", cp, 1, cs);
		cp = cs = 0;
	}
	return 0;
}

#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define ll long long int 
#define pb push_back
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn 200020
#define maxm
#define maxs
#define maxb
#define M1 998244353
#define M2 1000000007
#define B1 23333
#define B2 428491213
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}
int _num[20];
template <class T> void write(T x){	
	if (!x) {putchar('0'), putchar('\n'); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar('\n');
}

int n;
char s[30], _s[30], t[maxn << 1]; 


int main(){
	
		freopen("A.in", "r", stdin);
		
	//ios :: sync_with_stdio(false), cin.tie(0);
	//IMPOSSIBLE, POSSIBLE
	
	int T;
	scanf("%d", &T);
	rep(TT, 1, T){
		scanf("%s%s", s, t + 1);
		rep(i, 0, 25) _s[s[i] - 'a'] = 'a' + i;
		n = strlen(t + 1);
		int ans = 0;
		pll HP = pll(0, 0), HS = pll(0, 0);
		ll NOWB1 = 1, NOWB2 = 1;
		srep(i, 1, n){
			if ((i << 1) > n) break;
			HP.fi = (B1 * HP.fi % M1 + t[i] - 'a') % M1;
			HP.se = (B2 * HP.se % M2 + t[i] - 'a') % M2;
			HS.fi = (HS.fi + NOWB1 * (s[t[n - i + 1] - 'a'] - 'a') % M1) % M1;
			HS.se = (HS.se + NOWB2 * (s[t[n - i + 1] - 'a'] - 'a') % M2) % M2;
			NOWB1 = NOWB1 * B1 % M1;
			NOWB2 = NOWB2 * B2 % M2;
			if (HP.fi == HS.fi && HP.se == HS.se) ans = i;
		}
		int cs = n;
		rep(i, ans + 1, n - ans) t[++cs] = _s[t[i] - 'a']; t[++cs] = '\0';
		printf("%s\n", t + 1);
	}
	
	return 0;
}


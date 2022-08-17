#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define pii pair<int, int>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define ll long long int 
#define pb push_back
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn 20020
#define maxm
#define maxs
#define maxb
#define M 
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

int n, m;
char pre[maxn], mid[maxn], suf[maxn], s[maxn];
int cp, cm, cs; 

int main(){
	
		freopen("A.in", "r", stdin);
		
	//ios :: sync_with_stdio(false), cin.tie(0);
	//IMPOSSIBLE, POSSIBLE
	int T;
	scanf("%d", &T);
	rep(TT, 1, T){
		printf("Case #%d: ", TT);
		scanf("%d", &n);
		bool ok = 1;
		rep(i, 1, n){
			scanf("%s", s + 1);
			m = strlen(s + 1); 
			
			rep(j, 1, m){
				if (s[j] < 'A' || s[j] > 'Z') break;
				if (j > cp) pre[++cp] = s[j];
				else {
					if (pre[j] != s[j]) ok = false;
				}
			}
			
			per(j, m, 1){
				if (s[j] < 'A' || s[j] > 'Z') break;
				if (m - j + 1 > cs) suf[++cs] = s[j];
				else {
					if (suf[m - j + 1] != s[j]) ok = false;
				}
			}
			
			int l = 1, r = m;
			while (l <= m && 'A' <= s[l] && s[l] <= 'Z') l++;
			while (r >= 1 && 'A' <= s[r] && s[r] <= 'Z') r--;
			l++, r--;
			rep(j, l, r) {	
				if (s[j] != '*') mid[++cm] = s[j]; 
			}
		} 
		if (!ok) printf("*");
		else {
			pre[++cp] = '\0';
			printf("%s", pre + 1);
			mid[++cm] = '\0';
			printf("%s", mid + 1);
			reverse(suf + 1, suf + 1 + cs);
			suf[++cs] = '\0';
			printf("%s", suf + 1);
		}
		printf("\n");
		cp = cm = cs = 0;
	}
	return 0;
}


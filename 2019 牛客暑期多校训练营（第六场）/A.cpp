#include <bits/stdc++.h>
#define maxr 100000
#define maxn 2019
#define maxb
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
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
char s[maxn], t[27];
int main(){
	#ifndef ONLINE_JUDGE
		freopen("A.in", "r", stdin);
	#endif
	int T;
	scanf("%d", &T);
	rep(TT, 1, T){
		printf("Case #%d: ", TT);
		scanf("%s%s", s + 1, t);
		int n = strlen(s + 1);
		int ch = 0, cw = 0, cd = 0;
		rep(i, 1, n){
			if (t[s[i] - 'a'] == 'h') ch++;
			else if (t[s[i] - 'a'] == 'w') cw++;
			else cd++;
		}
		if ((ch << 2) >= n) printf("Harmful");
		else if (10 * ch <= n) printf("Recyclable");
		else if (cd >= (cw << 1)) printf("Dry");
		else printf("Wet");
		printf("\n");
	}
	return 0;
}

#include <bits/stdc++.h>
#define maxr 100000
#define maxn 2000005
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
//#define M 998244353
#define ll long long int 
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}
int n;
char s[maxn];
bool vis[maxn];
int main(){
	#ifndef ONLINE_JUDGE
		freopen("E.in", "r", stdin);
	#endif
	scanf("%s", s + 1);
	n = strlen(s + 1);
	int l, r;
	l = r = n >> 1;
	while (l >= 1 && r <= n){
		if (s[l] == s[r]) vis[l] = vis[r] = 1, l--, r++;
		else if (l > 1 && s[l - 1] == s[r]) vis[l - 1] = vis[r] = 1, l -= 2, r++;
		else if (r < n && s[l] == s[r + 1]) vis[l] = vis[r + 1] = 1, l--, r += 2;
		else if (l > 1 && r < n && s[l - 1] == s[r + 1]) vis[l - 1] = vis[r + 1] = 1, l -= 2, r += 2;
		else {
			if (l == 1) r++;
			if (r == n) l--;
		}
	}
	rep(i, 1, n) if (vis[i]) printf("%c", s[i]);
	return 0;
}

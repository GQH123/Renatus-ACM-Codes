#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int 
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first 
#define se second 
#define maxr 100019
#define maxn 219
#define maxm
#define maxs 
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template<class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}

int k;
char op;
char s[maxn];
int a[maxn];


int main(){
	
		#ifndef ONLINE_JUDGE
			freopen("A.in", "r", stdin);
		#endif
	
	scanf("%c", &op);
	scanf("%d", &k);
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	rep(i, 1, n) a[i] = s[i] - 'a';
	int d = -1;
	rep(i, 1, n){
		if (op == 'E') d = 1;
		else d = -1;
		a[i] = a[i] + d * k;
		a[i] = (a[i] % 26 + 26) % 26;
		printf("%c", 'a' + a[i]);
	}
	return 0;
}

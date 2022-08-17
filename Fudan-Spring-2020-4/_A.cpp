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
#define maxn
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

int gcd(int x, int y){
	if (!y) return x;
	return gcd(y, x % y);
}

int main(){
	 
		freopen("A.out", "w", stdout);
	//ios :: sync_with_stdio(false), cin.tie(0);
	/*int n;
	read(n);	
	rep(i, 1, n){
		if (i == 1) printf("1 : 0\n");
		else {
			int ans = 1;
			srep(j, 1, i) if (gcd(j, i) == 1) ans = (ll)ans * j % i; 
			if (ans == i - 1) ans = -1;
			if (i % 4 == 0 && i != 4 && ans != 1) printf("Fuck!!!\n");
			else if (ans != -1){
				if (i % 4 == 0) printf("");
				else printf("%d : %d\n", i, ans);
			}
		} 
	}*/	
	rep(i, 1, 2000){
		if (i == 1) printf("1 : 0\n");
		else {
			int ans = 1;
			srep(j, 1, i) if (gcd(j, i) == 1) ans = (ll)ans * j % i;  
			printf("%d : %d\n", i, ans);
		} 
	}
	return 0;
}


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
#define maxn 200020
#define maxm
#define maxs
#define maxb 40
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
	if (!x) {putchar('0'), putchar(' '); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar(' ');
}

int n, a[maxn];
int num[maxb], num2[maxb];

int main(){
	
		//freopen("A.in", "r", stdin);
		
	ios :: sync_with_stdio(false), cin.tie(0);
	
	read(n);
	rep(i, 1, n) read(a[i]);
	int x, now = 0;
	rep(i, 1, n){
		x = a[i], now = 0;
		while (x) { 
			if (x & 1) num[now]++, num2[now] = i;
			now++, x >>= 1;
		}
	}
	int f = -1;
	per(i, maxb - 1, 0){
		if (num[i] == 1){
			f = num2[i];
			break;
		}
	} 
	if (f != -1) write(a[f]);
	rep(i, 1, n){
		if (i == f) continue;
		write(a[i]);
	} 
	return 0;
}


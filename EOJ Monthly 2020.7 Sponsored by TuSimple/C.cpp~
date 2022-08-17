#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define pii pair<int, int>
#define fi first
#define se second
#define ll long long int 
#define mo(x) (x = (x >= M) ? (x - M) : x)
#define lowbit(x) (x & -x)
#define maxn
#define maxm
#define maxr 200000
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char *p1, *p2, buffer[maxr];
template <class T> void read(T& x){
    char ch = gc(); x = 0; bool f = 1;
    while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
    if (ch == '-') f = 0, ch = gc();
    while ('0' <= ch && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = gc();
    x = f ? x : -x;
}

int n, m, a, b;
int c[4020][2420];
void add(int x, int y, int v){
	int _y = y;
	while (x) {
		y = _y;
		while (y){
			c[x][y] += v;
			y -= lowbit(y);
		}
		x -= lowbit(x);
	}
}
int get(int x, int y){ 
	int _y = y, ans = 0;
	while (x <= a) {
		y = _y;
		while (y <= b){
			ans += c[x][y];
			y += lowbit(y);
		}
		x += lowbit(x);
	}
	return ans;
}
int num[4020][2420];

int main(){
	read(n), read(m), read(a), read(b);
	int x;
	rep(i, 1, n) rep(j, 1, m){
		read(x);
		if (x) {
			add(i + a - n, j + b - m, 1);
			add(i - 1, j + b - m, -1);
			add(i + a - n, j - 1, -1);
			add(i - 1, j - 1, 1); 
		}
	}
	int mx = 0;
	rep(i, 1, a) rep(j, 1, b) num[i][j] = get(i, j), mx = max(mx, num[i][j]);
	/*
	rep(i, 1, a) {rep(j, 1, b){
		printf("%lld ", num[i][j]);
	}
	printf("\n");
	}
	*/
	rep(i, 1, a) {rep(j, 1, b){
		printf("%lld ", 1ll * 100 * num[i][j] / mx);
	}
	printf("\n");
	}
	return 0;
}

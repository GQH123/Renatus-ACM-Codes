#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define maxr 100000
#define maxn 2020
#define maxm 120
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

int n;
char s[maxm];
char g[maxn][maxn];
char _g[maxn][maxn];
//v>^<
void turn_left(){
	rep(i, 1, n){
		rep(j, 1, n){
			_g[i][j] = g[j][n + 1 - i];
			if (_g[i][j] == '^') _g[i][j] = '<';
			else if (_g[i][j] == '<') _g[i][j] = 'v';
			else if (_g[i][j] == 'v') _g[i][j] = '>';
			else if (_g[i][j] == '>') _g[i][j] = '^';
		}
	}
	rep(i, 1, n) rep(j, 1, n) g[i][j] = _g[i][j];
}

void turn_right(){
	rep(i, 1, n){
		rep(j, 1, n){
			_g[i][j] = g[n + 1 - j][i];
			if (_g[i][j] == '^') _g[i][j] = '>';
			else if (_g[i][j] == '>') _g[i][j] = 'v';
			else if (_g[i][j] == 'v') _g[i][j] = '<';
			else if (_g[i][j] == '<') _g[i][j] = '^';
		}
	}
	rep(i, 1, n) rep(j, 1, n) g[i][j] = _g[i][j];
}

int main(){
	
		#ifndef ONLINE_JUDGE
			freopen("A.in", "r", stdin);
		#endif
	
	scanf("%d", &n); scanf("%s", s + 1);
	rep(i, 1, n) scanf("%s", g[i] + 1);
	int m = strlen(s + 1);
	rep(i, 1, m){
		if (s[i] == 'L') turn_left();
		else turn_right();
	}
	rep(i, 1, n) printf("%s\n", g[i] + 1);
	return 0;
}

#include <bits/stdc++.h>
#define maxr 100000
#define maxn 3019
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
	if (ch == '-') ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}

int n, m;
char s[maxn][maxn];
int num[maxn][maxn];
int down[maxn][maxn];
int sta[maxn], head = 0;
int main(){
	#ifndef ONLINE_JUDGE
		freopen("A.in", "r", stdin);
	#endif
	scanf("%d%d", &n, &m);
	rep(i, 1, n) scanf("%s", s[i] + 1);
	rep(i, 1, n) rep(j, 1, m) num[i][j] = s[i][j] - '0';
	rep(j, 1, m) {
		int last = m + 1;
		per(i, n, 1) down[i][j] = last, last = (!num[i][j]) ? i : last;
	}
	int last = m + 1;
	per(j, m, 1){
		if (!num[1][j]) continue;
		while (head && down[1][j] < down[1][sta[head]]) head--;
		sta[++head] = j;
		
	}
	rep(i, 1, n){
		per(j, m, 1){
			
		}
	}
	return 0;
}

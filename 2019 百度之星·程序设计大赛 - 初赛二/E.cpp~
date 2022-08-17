#include <bits/stdc++.h>
#define maxr 100000
#define maxn 200019
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
int n;
int ans[maxn];
int d[maxn];
int ca = 0;
struct ele{
	int l, r, d;
	ele(int l, int r, int d) : l(l), r(r), d(d){}
	ele(){}
}sta[maxn];
int head = 0;
int main(){
	#ifndef ONLINE_JUDGE	
		freopen("E.in", "r", stdin);
	#endif
	int T;
	read(T);
	while(T--){
		read(n);
		rep(i, 1, n) read(d[i]);
		head = ca = 0;
		per(i, n, 1){
			sta[++head] = ele(i, i, d[i]);
			while (head > 1 && sta[head].d == sta[head - 1].d) {
				sta[head - 1].l = sta[head].l, ans[++ca] = sta[head].r, sta[head - 1].d--, head--;
				if (sta[head].d < 0) {
					printf("Impossible");
					goto jump;
				}
			}
		}
		if (head != 1 || sta[head].d != 0) printf("Impossible");
		else {
			printf("Possible\n");
			printf("%d", ans[ca]); per(i, ca - 1, 1) printf(" %d", ans[i]);
		}
		jump: printf("\n");
	}
	return 0;
}

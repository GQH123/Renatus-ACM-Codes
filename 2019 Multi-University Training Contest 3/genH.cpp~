#include <bits/stdc++.h>
#define maxr 100000
#define maxn 100105
#define ll long long int 
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
int main(){
	srand(time(NULL));
	#ifndef ONLINE_JUDGE
		freopen("H.in", "w", stdout);
	#endif
	int n, m, x, y;
	n = m = 100000;
	int T = 6;
	while (T--){
		printf("%d %d\n", n, m);
		rep(i, 1, n) printf("%d ", rand() % 1000001); printf("\n");
		rep(i, 1, m){
			int type = rand() % 2 + 1;
			if (type == 1){
				x = rand() % n + 1, y = rand() % n + 1;
				if (x > y) swap(x, y);
				printf("%d %d %d\n", type, x, y);
			}
			else if (type == 2){
				x = rand() % (n - 1) + 1;
				printf("%d %d\n", type, x);
			}
		}
	}
	return 0;
}

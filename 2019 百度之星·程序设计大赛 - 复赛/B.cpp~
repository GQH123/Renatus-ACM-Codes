#include <bits/stdc++.h>
#define maxn
#define maxm 
#define maxr 100000
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
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

int main(){
	#ifndef ONLINE_JUDGE
		freopen("B.in", "r", stdin);
	#endif
	int T;
	read(T);
	ll a, b, c, d, x, y;
	while (T--){
		read(a), read(b), read(c), read(d);
		if (a == c && b == d) printf("Yes\n\n");
		else {
			if (a == b) printf("No\n");
			else {
				if (abs(c - a) % abs(a - b) != 0 || abs(d - b) % abs(b - a) != 0) printf("No\n");
				else {
					x = (c - a) / (a - b);
					y = (d - b) / (b - a);
					if (x < 0 || y < 0) printf("No\n");
					else {
						a = x, b = y;
						bool f = 0;
						per(i, 62, 0) {
							if ((a & (1ll << i)) == 0 && (b & (1ll << i)) == 0){
								if (f) {
									printf("No\n");
									goto jump;
								}
								else continue;
							}
							f = 1;
							if ((a & (1ll << i)) && (b & (1ll << i))) {
								printf("No\n");
								goto jump;
							}
						}
						printf("Yes\n");
						rep(i, 0, 62){
							if (a & (1ll << i)) printf("B");
							else if (b & (1ll << i)) printf("A");
							else {printf("\n"); break;}
						}
						jump:;
					}
				}
			}
		}
	}
	return 0;
}

#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define M 998244353
#define mo(x) (x = (x >= M) ? (x - M) : x)
#define maxn 520
#define ll long long int 
#define maxr 2000020
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template<class T> void read(T& x){
	char ch = gc(); x = 0;
	while (!('0' <= ch && ch <= '9')) ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = gc();
}
void reads(char* s){
	int x = 0; char ch = gc(); 
	while (!('a' <= ch && ch <= 'z')) ch = gc();
	while ('a' <= ch && ch <= 'z') s[x++] = ch, ch = gc();
	s[x] = '\0';
}


int n, m, k;

int t[maxn][maxn];
int a[maxn][maxn];

int main(){	
	ll xx;
	read(n), read(m), read(k);
	rep(i, 1, n) rep(j, 1, m){
		read(xx), a[i][j] = xx % M;
	}
	char op[5];
	int x, y;
	ll res = 0;
	rep(i, 1, k){
		reads(op), read(x), read(xx);
		//scanf("%s%d%lld", op, &x, &xx);
		y = xx % M;
		if (op[0] == 'r'){
			rep(j, 1, m){
				res += 1ll * (M + y - t[x][j]) * a[x][j] % M;
				mo(res);
				t[x][j] = y;
			}
		}
		else {
			rep(i, 1, n){
				res += 1ll * (M + y - t[i][x]) * a[i][x] % M;
				mo(res);
				t[i][x] = y;
			}
		}
	}
	printf("%lld", res);
	return 0;
}

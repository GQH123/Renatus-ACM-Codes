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
#define maxn 220
#define maxm
#define maxs
#define maxb
#define M 
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

const int inf = 2000000000;
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


int n, m, C;
bool ok[maxn];
double p[maxn][maxn], d[maxn][maxn];
void F1(){
	rep(i, 1, n) rep(j, 1, n){
		if (p[i][j] == 0) d[i][j] = inf;
		else d[i][j] = log(1 / p[i][j]);
	}
	rep(k, 1, n){
		rep(i, 1, n){
			rep(j, 1, n){ 
				if (d[i][j] > d[i][k] + d[k][j]) d[i][j] = d[i][k] + d[k][j];
			}
		}
	}
}

int lis[maxn];
int cs = 0;
void F2(){
	int ss, tt; cs = 0;
	rep(i, 1, n) {
		if (ok[i]) lis[++cs] = i;
		if (i == 1) ss = cs;
		if (i == 2) tt = cs;
	}
	rep(i, 1, n) rep(j, 1, n){
		if (d[i][j] == inf) continue;
		else d[i][j] = exp(d[i][j]);
	}
	rep(_k, 1, cs){
		rep(_i, 1, cs){
			rep(_j, 1, cs){
				int i = lis[_i], j = lis[_j], k = lis[_k];
				if (d[i][j] > d[i][k] + d[k][j]) d[i][j] = d[i][k] + d[k][j];
			}
		}
	}
	printf("%.7lf\n", C * d[ss][tt]);
}

int main(){
	
		//freopen("C.in", "r", stdin);
	
	int T, x;
	scanf("%d", &T);
	while (T--){
		scanf("%d", &n);
		rep(i, 1, n) ok[i] = 0;
		rep(i, 1, n) rep(j, 1, n) scanf("%lf", &p[i][j]), p[i][j] /= 100.0;
		scanf("%d", &m);
		rep(i, 1, m) scanf("%d", &x), ok[x] = 1;
		ok[1] = ok[2] = 1;
		scanf("%d", &C);
		
		F1();
		F2();
		
	}
	
	return 0;
}


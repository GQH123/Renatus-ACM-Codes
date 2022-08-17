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

int p[maxn], cp = 0;
bool vis[maxn];
void init(){
	srep(i, 2, maxn) {
		if (!vis[i]) p[++cp] = i;
		rep(j, 1, cp){
			if (i * p[j] >= maxn) break;
			vis[i * p[j]] = 1;
			if (i % p[j] == 0) break;
		}
	}
}

void work(int x){ 
	if (x == 1) {printf("0\n"); return;}
	if (x == 4) {printf("3\n"); return;}
	int c2 = 0, _x = x;
	while (x % 2 == 0) x /= 2, c2++;
	if (c2 > 1) {printf("1\n"); return;}
	else {
		int pnum = 0;
		rep(j, 2, cp){
			if ((ll)p[j] * p[j] > x) break;
			if (x % p[j] == 0){
				pnum++;
				while (x % p[j] == 0) x /= p[j];
			}
		}
		if (x > 1) pnum++;
		if (pnum == 1) printf("%d\n", _x - 1);
		else printf("1\n");
	}
	
}

int main(){
	
		freopen("A.in", "r", stdin);
		
	//ios :: sync_with_stdio(false), cin.tie(0);
	int x;
	init();
	while (scanf("%d", &x) == 1) work(x); 
	return 0;
}


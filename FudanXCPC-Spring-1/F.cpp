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
#define pc putchar
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn 220
#define maxv 230020
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

void getdouble(int& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = 10 * x + ch - '0', ch = gc();
	ch = gc();
	while ('0' <= ch && ch <= '9') x = 10 * x + ch - '0', ch = gc();
	x = (f) ? x : -x;
}
int num[20];
void putdouble(int x){
	if (x < 0) printf("-"), x = -x;
	srep(i, 0, 5) num[i] = x % 10, x /= 10;
	per(i, 4, 0) {
		if (i == 4) printf("%d.", num[i]);
		else printf("%d", num[i]);
	}
	printf("\n");
}


int n, sg, a[maxn];
bitset<maxv> vis[2];
int DP(){ 	
	vis[0].reset(), vis[1].reset();
	int d = 0;
	vis[d][200000] = 1;
	rep(i, 1, n){ 
		d ^= 1;
		vis[d] = vis[d ^ 1];
		if (a[i] >= 0) vis[d] |= (vis[d ^ 1] << a[i]); 
		else vis[d] |= (vis[d ^ 1] >> (-a[i])); 
		
	}
	return d;
}

int main(){
	
		freopen("F.in", "r", stdin);
		
	int T; double x;
	read(T);
	while (T--){
		getdouble(sg), sg += 200000, read(n);
		rep(i, 1, n) getdouble(a[i]);
		sort(a + 1, a + 1 + n);
		int d = DP();
		int mi = -1, mi2;
		srep(i, sg, 220000){
			if (vis[d][i]) {
				mi = i - sg, mi2 = i;
				break;
			}
		}
		per(i, sg, 0){
			if (vis[d][i]){
				if (mi == -1 || sg - i <= mi) mi = sg - i, mi2 = i;
				break;
			}
		}
		mi2 -= 200000;
		putdouble(mi2);
	} 
	return 0;
}


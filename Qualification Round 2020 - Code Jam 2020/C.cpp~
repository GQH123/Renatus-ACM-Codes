#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second
#define ll long long int
#define ld long double
#define pb push_back
#define pc putchar 
#define ms(x, a) memset(x, a, sizeof(x))
#define mo(x) (x = (x >= M) ? (x - M) : x)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define maxn 2020
#define maxm
#define maxr 2000000
#define maxs
#define maxb
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){	
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}

char _num[30];
template <class T> void write(T x, char sep = ' '){
	if (!x) {pc('0'), pc(sep); return;}
	if (x < 0) pc('-'), x = -x;
	int cn = 0;
	while (x) _num[++cn] = x % 10 + '0', x /= 10;
	while (cn) pc(_num[cn--]); pc(sep);
}  

struct edge{
	int next, to;
	edge(int next, int to) : next(next), to(to){}
	edge(){}
}e[maxn * maxn << 1];
int cnt = 1, h[maxn];
void Add_Edge(int x, int y){
	e[++cnt] = edge(h[x], y);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x);
	h[y] = cnt;
}

int c[maxn];
bool DFS(int x, int cc){
	if (c[x]) return c[x] == cc;
	c[x] = cc;
	erep(i, x){
		int op = e[i].to;
		if (!DFS(op, 3 - cc)) return false;
	}
	return true;
}

int n, l[maxn], r[maxn];

bool overlap(int i, int j){
	return !(r[i] <= l[j] || r[j] <= l[i]);
}

void recover(){
	rep(i, 1, n) h[i] = c[i] = 0;
	cnt = 1;
}

int main(){

	freopen("C.in", "r", stdin);
	
	int T;
	read(T);
	rep(TT, 1, T){ 
		printf("Case #%d: ", TT);
		read(n);
		rep(i, 1, n) read(l[i]), read(r[i]);
		rep(i, 1, n) rep(j, i + 1, n) if (overlap(i, j)) Add_Edge(i, j); 
		rep(i, 1, n) {
			if (!c[i]) {
				if (!DFS(i, 1)){
					printf("IMPOSSIBLE\n");
					goto fail;
				}
			}
		}
		rep(i, 1, n) pc((c[i] == 1) ? 'C' : 'J'); pc('\n');
		fail: recover();
	}
	return 0;
}

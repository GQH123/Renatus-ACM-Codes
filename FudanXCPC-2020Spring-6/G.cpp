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
#define maxn 5020
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

int n, r, c, cost;
int s, t;
char g[maxn];
int lis[maxn];
int cs = 0;
priority_queue<pii> pq;
int d[maxn];
bool vis[maxn];
void Dij(){
	pq.push(pii(0, s));
	d[s] = 0;
	while (!pq.empty()){
		pii op = pq.top(); pq.pop();
		if (-op.fi != d[op.se]) continue;
		int x = op.se, a = x / c, b = x % c;
		vis[x] = 1;
		if (a) {	
			int op = (a - 1) * c + b;
			if (g[op] == '#' || vis[op]) goto nex1;
			int l = (g[op] == '*') ? cost : 0;
			if (d[op] > d[x] + l) d[op] = d[x] + l, pq.push(pii(-d[op], op));
		}
		nex1:;
		if (a < r - 1){
			int op = (a + 1) * c + b;
			if (g[op] == '#' || vis[op]) goto nex2;
			int l = (g[op] == '*') ? cost : 0;
			if (d[op] > d[x] + l) d[op] = d[x] + l, pq.push(pii(-d[op], op));
		}
		nex2:;
		if (b){
			int op = a * c + b - 1;
			if (g[op] == '#' || vis[op]) goto nex3;
			int l = (g[op] == '*') ? cost : 0;
			if (d[op] > d[x] + l) d[op] = d[x] + l, pq.push(pii(-d[op], op));
		}
		nex3:;
		if (b < c - 1){
			int op = a * c + b + 1;
			if (g[op] == '#' || vis[op]) goto nex4;
			int l = (g[op] == '*') ? cost : 0;
			if (d[op] > d[x] + l) d[op] = d[x] + l, pq.push(pii(-d[op], op));
		}
		nex4:;
		if (g[x] == 'P'){
			rep(i, 1, cs){
				int op = lis[i];
				if (d[op] > d[x]) d[op] = d[x], pq.push(pii(-d[op], op));
			}
		}
	}
	if (!vis[t]) printf("Damn teoy!\n");
	else printf("%d\n", d[t]); 
}

void recover(){
	cs = 0;
	srep(i, 0, n) vis[i] = 0, d[i] = inf;
}

int main(){
	
		freopen("G.in", "r", stdin);
		
	while (scanf("%d", &r) == 1){ 
		scanf("%d%d", &c, &cost);
		rep(i, 1, r) scanf("%s", g + (i - 1) * c);
		//printf("%s\n", g);
		n = r * c; 
		recover();
		srep(i, 0, n){
			if (g[i] == 'Y') s = i; 
			else if (g[i] == 'C') t = i;
			else if (g[i] == 'P') lis[++cs] = i;
		}
		Dij(); 
	}
	//ios :: sync_with_stdio(false), cin.tie(0);
	//IMPOSSIBLE, POSSIBLE
	/*
	int T;
	scanf("%d", &T);
	rep(TT, 1, T){
		printf("Case #%d: ", TT);
		
		
		
		printf("\n");
	}
	*/
	return 0;
}


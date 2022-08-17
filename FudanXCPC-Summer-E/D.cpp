#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define maxn 2020
#define maxm 
#define M 
#define ll long long int 
#define ld long double
#define pb push_back
#define pc putchar
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define lowbit(x) (x & -x)
using namespace std;

int n, m;
struct ele{
	int l; char name[40];
	bool operator < (const ele b) const{
		if (l != b.l) return l < b.l;
		srep(i, 0, l) {
			if (name[i] != b.name[i]) return name[i] < b.name[i];
		}
		return false;
	}
	void read(){
		scanf("%s", name);
		l = strlen(name);
	}
}a, b, c, d;
map<ele, int> s2n;
map<int, ele> n2s;
int ct = 0;

struct edge{
	int next, to;
	edge(int next, int to) : next(next), to(to){}
	edge(){}
}e[maxn << 1];
int cnt = 1, h[maxn];
void Add_Edge(int x, int y){
	e[++cnt] = edge(h[x], y);
	h[x] = cnt;
}

bool vis[maxn];
bitset<300> dp[maxn];
void DP(int x){
	if (vis[x]) return;
	vis[x] = 1;
	dp[x][x] = 1;
	erep(i, x){
		int op = e[i].to;
		DP(op);
		dp[x] |= dp[op];
	}
}

inline void read(ele& x){
	x.read();
}

int main(){
	scanf("%d%d", &n, &m);
	rep(i, 1, n) {
		read(a), read(b), read(b), read(b), read(b);
		if (!s2n.count(a)) s2n[a] = ++ct, n2s[ct] = a;
		if (!s2n.count(b)) s2n[b] = ++ct, n2s[ct] = b;
		Add_Edge(s2n[a], s2n[b]);
	}
	rep(i, 1, n) DP(i);
	rep(j, 1, m){	
		read(a), read(b), read(b), read(b), read(b);
		int x = s2n[a], y = s2n[b];
		if (!s2n.count(a) || !s2n.count(b)) {
			printf("Pants on Fire\n");
		} 
		else if (dp[x][y] == 1) {
			printf("Fact\n");
		}
		else if (dp[y][x] == 1) {
			printf("Alternative Fact\n");
		}
		else {
			printf("Pants on Fire\n");
		} 
	}
	return 0;
}

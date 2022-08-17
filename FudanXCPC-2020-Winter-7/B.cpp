#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int
#define maxn 300020
#define maxm 
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back

using namespace std;

int n, k;
struct edge{
	int next, to;
	edge(int next, int to) : next(next), to(to){}
	edge(){}
}e[maxn << 1];
int cnt = 1, h[maxn], deg[maxn];
void Add_Edge(int x, int y){
	e[++cnt] = edge(h[x], y);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x);
	h[y] = cnt;
	deg[x]++, deg[y]++;
}

bool col[maxn];
int num[maxn];
void DFS(int x, int fa){
	if (col[x]) num[x]++;
	erep(i, x){
		int op = e[i].to;
		if (op == fa) continue;
		DFS(op, x);
		num[x] += num[op];
	}
}
int out[maxn];
int ans = 0;
void DP(int x, int fa){
	bool f = 1;
	erep(i, x){
		int op = e[i].to;
		if (op == fa) continue;
		if (!num[op]) {f = 0; break;}
	}
	if (x != 1 && num[x] == k) f = 0;
	if (f && !col[x]) out[++ans] = x;
	erep(i, x){	
		int op = e[i].to;
		if (op == fa) continue;
		DP(op, x);
	}
}

int main(){
	freopen("B.in", "r", stdin);
	
	scanf("%d%d", &n, &k);
	int x, y;
	rep(i, 1, k) scanf("%d", &x), col[x] = 1;
	srep(i, 1, n) scanf("%d%d", &x, &y), Add_Edge(x, y);
	DFS(1, 1);
	DP(1, 1);
	sort(out + 1, out + 1 + ans);
	printf("%d\n", ans);
	rep(i, 1, ans) printf("%d ", out[i]);
	return 0;
}


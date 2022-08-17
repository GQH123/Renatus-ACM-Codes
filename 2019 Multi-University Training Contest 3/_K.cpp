#include <bits/stdc++.h>
#define maxr 100000
#define maxn 200105
#define ll long long int 
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define ms(a, b) memset(a, 0, sizeof(a))
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}

int n;
struct edge{
	int next, to, len;
	edge(int next, int to, int len) : next(next), to(to), len(len){}
	edge(){}
}e[maxn << 1];
int cnt = 1, h[maxn];
void Add_Edge(int x, int y, int z){
	e[++cnt] = edge(h[x], y, z);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x, z);
	h[y] = cnt;
}

int f[maxn][3], v[maxn][3];

void update1(int x, int k){
	if (k >= f[x][0]) f[x][2] = f[x][1], f[x][1] = f[x][0], f[x][0] = k;
	else if (k >= f[x][1]) f[x][2] = f[x][1], f[x][1] = k;
	else if (k > f[x][2]) f[x][2] = k;
}

inline void update2(int x, int k, int op, int len, int id, int id2){
	if (k == f[x][0]) {
		v[x][0] = max(min(v[op][id] + len, f[op][id2]), f[x][1]);
		v[x][1] = max(min(v[op][id] + len, f[op][id2]), f[x][2]);
	}
	if (k == f[x][1]){
		v[x][2] = max(min(v[op][id] + len, f[op][id2]), f[x][2]);
	}
}

void DFS(int x, int fa){
	erep(i, x){
		int op = e[i].to;
		if (op == fa) continue;
		DFS(op, x);
		update1(x, f[op][0] + e[i].len);
	}
	erep(i, x){
		int op = e[i].to;
		if (op == fa) continue;
		update2(x, f[op][0] + e[i].len, op, e[i].len, 0, 0);
	}
}

int ans1, ans2;
void DP(int x, int fa, int id1, int id2){
	if (id2 != -1){
		erep(i, x){
			int op = e[i].to;
			if (op == fa) update2(x, f[fa][id1] + e[i].len, fa, e[i].len, id2, id1);  
			else update2(x, f[op][0] + e[i].len, op, e[i].len, 0, 0);
		}
	}
	
	int ans = v[x][0];
	if (ans < ans2) ans1 = x, ans2 = ans;
	else if (ans == ans2) ans1 = min(ans1, x);
	
	erep(i, x){
		int op = e[i].to;
		if (op == fa) continue;
		int k = f[op][0] + e[i].len, id1;
		if (k == f[x][0]) update1(op, f[x][1] + e[i].len), id1 = 1;//用f1  
		else update1(op, f[x][0] + e[i].len), id1 = 0;//用f0
		
		if (k == f[x][0]) DP(op, x, id1, 2);//用v2
		else if (k == f[x][1]) DP(op, x, id1, 1);//用v1
		else DP(op, x, id1, 0);//用v0
	}
}

int main(){
	int inf = 1000000000;
	#ifndef ONLINE_JUDGE
		freopen("K.in", "r", stdin);
	#endif
	int T;
	read(T);
	while (T--){
		ans1 = ans2 = inf;
		int x, y, z;
		read(n);
		srep(i, 1, n) read(x), read(y), read(z), Add_Edge(x, y, z);
		DFS(1, 1);
		DP(1, 1, -1, -1);
		printf("%d %d\n", ans1, ans2);
		cnt = 1, ms(h, 0), ms(f, 0), ms(v, 0);
	}
	return 0;
}

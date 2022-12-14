#include <bits/stdc++.h>
#define maxr 100000
#define maxn 200105
#define ll long long int 
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ms(a, b) memset(a, b, sizeof(a))
#define pb push_back
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}

/*struct edge{
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
}/*

/*
int dp1[maxn], dp2[maxn], me1[maxn], me2[maxn], ch1[maxn], ch2[maxn];

void update(int x, int k, int op, int i, int me){
	if (k > dp1[x]) dp2[x] = dp1[x], me2[x] = me1[x], ch2[x] = ch1[x], dp1[x] = k, me1[x] = max(me, e[i].len), ch1[x] = op;
	else if (k == dp1[x]){
		if (max(me, e[i].len) > me1[x]) {
			dp2[x] = dp1[x], me2[x] = me1[x], ch2[x] = ch1[x], dp1[x] = k, me1[x] = max(me, e[i].len), ch1[x] = op;
		}
	}
	else if (k > dp2[x]) dp2[x] = k, me2[x] = max(me, e[i].len), ch2[x] = op;
	else if (k == dp2[x]){
		if (max(me, e[i].len) > me2[x]) me2[x] = max(me, e[i].len), ch2[x] = op;
	}
}

void DFS(int x, int fa){	
	erep(i, x){
		int op = e[i].to;
		if (op == fa) continue;
		DFS(op, x);
		int k = dp1[op] + e[i].len;
		update(x, k, op, i, me1[op]);
	}
}

int ans1 = 0, ans2 = 0;
void DP(int x, int fa){
	int ans = max(dp1[x] - me1[x], dp2[x]);
	if (ans < ans2) ans2 = ans, ans1 = x;
	else if (ans == ans2) ans1 = min(ans1, x);
	erep(i, x){
		int op = e[i].to;
		if (op == fa) continue;
		if (op == ch1[x]){
			int k = dp2[x] + e[i].len;
			update(op, k, x, i, me2[x]);
			DP(op, x);
		}
		else {
			int k = dp1[x] + e[i].len;
			update(op, k, x, i, me1[x]);
			DP(op, x);
		}
	}
}
*/

int n, deg[maxn], fa[maxn];
vector<int> to[maxn];
vector<int> len[maxn];

int f[maxn][2];

void update(int x, int pos, int& t0, int& t00, int& mifop, int& fop){
	int k = f[to[x][pos]][0] + len[x][pos];
	if (k >= t0) t00 = t0, t0 = k;
	else if (k > t00) t00 = k;
}//????????????????????????????????????

extern void DP(int x){}

void div(int x, int l, int r, int t0, int t00, int mifop, int fop){
	if (l == r){
		if (to[x][l] == fa[x]) return; //????????????????????????DP
		f[x][0] = t0; 
		f[x][1] = min(max(t00, fop), max(mifop, t0)); //?????????????????????????????????????????????????????????????????????
		DP(to[x][l]);
		return;
	}
	int m = ((r - l) >> 1) + l;
	int _t0 = t0, _t00 = t00, _mifop = mifop, _fop = fop;
	rep(i, l, m) update(x, i, _t0, _t00, _mifop, _fop);
	div(x, m + 1, r, _t0, _t00, _mifop, _fop);
	_t0 = t0, _t00 = t00, _mifop = mifop, _fop = fop;
	rep(i, m + 1, r) update(x, i, _t0, _t00, _mifop, _fop);
	div(x, l, m, _t0, _t00, _mifop, _fop); 
}//??????f0???????????????????????????f[op][1] + e[i].len?????????????????????????????? f[op'][1] + e[i].len

int ans1 = inf, ans2 = inf;
void DP(int x){
	int t0 = 0, t00 = 0, f0 = f[x][0], f1 = f[x][1];//???????????????
	
	f[x][0] = 0, f[x][1] = inf;//??????????????????
	srep(i, 0, deg[x]) {
		int op = to[x][i];
		int k = f[op][0] + len[x][i];
		f[x][0] = max(f[x][0], k);
		if (k >= t0) t00 = t0, t0 = k;
		else if (k > t00) t00 = k;
	}
	srep(i, 0, deg[x]) {
		int op = to[x][i];
		if (f[op][0] + len[x][i] == t0) f[x][1] = min(f[x][1], max(min(f[op][1] + len[x][i], f[op][0]), t00));
		else f[x][1] = min(f[x][1], max(min(f[op][1] + len[x][i], f[op][0]), t0)); 
	}//??????????????????????????????
	
	int ans = f[x][1];
	if (ans < ans2) ans2 = ans, ans1 = x;
	else if (ans == ans2) ans1 = min(ans1, x);//????????????
	
	div(x, 0, deg[x] - 1, 0, 0, inf, inf);//????????????????????????????????????????????????
	
	f[x][0] = f0, f[x][1] = f1;//???????????????
}

void DFS(int x){
	int t0 = 0, t00 = 0;
	srep(i, 0, deg[x]) {
		int op = to[x][i];
		if (op == fa[x]) continue;
		fa[op] = x;
		DFS(op, x);
		int k = f[op][0] + len[x][i];
		f[x][0] = max(f[x][0], k);
		if (k >= t0) t00 = t0, t0 = k;
		else if (k > t00) t00 = k;
	}
	srep(i, 0, deg[x]) {
		int op = to[x][i];
		if (op == fa[x]) continue;
		if (f[op][0] + len[x][i] == t0) f[x][1] = min(f[x][1], max(min(f[op][1] + len[x][i], f[op][0]), t00));
		else f[x][1] = min(f[x][1], max(min(f[op][1] + len[x][i], f[op][0]), t0)); 
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
		/*ans1 = ans2 = inf;
		int x, y, z;
		read(n);
		srep(i, 1, n) read(x), read(y), read(z), Add_Edge(x, y, z);
		DFS(1, 1);
		DP(1, 1);
		printf("%d %d\n", ans1, ans2);
		ms(dp1, 0), ms(dp2, 0), ms(me1, 0), ms(me2, 0), ms(ch1, 0), ms(ch2, 0), cnt = 1, ms(h, 0);	
		*/
		/*
		int x, y, z;
		read(n);
		srep(i, 1, n) read(x), read(y), read(z), Add_Edge(x, y, z);
		rep(i, 1, n) f[i][1] = inf, f[i][0] = 0;
		DFS(1, 1);
		DP(1, 1);
		printf("%d %d\n", ans1, ans2);
		ms(h, 0), cnt = 1;
		*/
		int x, y, z;
		read(n);
		srep(i, 1, n) read(x), read(y), read(z), to[x].pb(y), len[x].pb(z), to[y].pb(x), len[y].pb(z), deg[x]++, deg[y]++;
		DFS(1, 1);
		DP(1, 1);
	}
	return 0;
}

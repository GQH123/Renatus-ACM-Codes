#include <bits/stdc++.h>
#define maxn 300019
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
using namespace std;

const int INF = 1073741824;

int n, m, A, B;
int v[maxn];

struct edge{
	int next, to;
	edge(int next, int to) : next(next), to(to){}
	edge(){}
}e[maxn << 1];
int cnt = 1, h[maxn];
void Add_Edge(int x, int y){
	e[++cnt] = edge(h[x], y);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x);
	h[y] = cnt;
}

int da[maxn], db[maxn];
bool vis[maxn];
int spfa[maxn], tail = 0, head = 0;

void SPFA(int* d, int s){
	tail = head = 0;
	rep(i, 1, n) d[i] = INF;
	d[s] = 0, vis[s] = 1;
	spfa[++head] = s;
	while (tail < head){
		int x = spfa[++tail];
		erep(i, x){
			int op = e[i].to;
			if (d[op] > d[x] + 1) {
				d[op] = d[x] + 1;
				if (!vis[op]) spfa[++head] = op, vis[op] = 1; 
			}
		}
		vis[x] = 0;
	}
}

bool if_on_loop[maxn];
int lis[maxn]; //node on loop
int ct = 0;

int fa[maxn];
int viss[maxn];
int tim = 0;
void DFS(int x){
	viss[x] = ++tim;
	bool f = 1;
	erep(i, x){
		int op = e[i].to;
		if (op == fa[x] && f) {	
			f = 0;
			continue;
		}
		if (viss[op] && viss[op] < viss[x]) {
			int _x = x;
			while (_x != op){
				lis[++ct] = _x;
				if_on_loop[_x] = 1;
				_x = fa[_x];
			}
			lis[++ct] = op, if_on_loop[op] = 1;
		}
		else if (!viss[op]) {
			fa[op] = x;
			DFS(op); 
		}
	}
}

int d[maxn], root[maxn];

void DFS2(int x){
	erep(i, x){
		int op = e[i].to;
		if (op == fa[x]) continue;
		d[op] = d[x] + 1;
		fa[op] = x;
		root[op] = root[x];
		DFS2(op);
	}
}

void get_loop(){
	fa[1] = 0;
	DFS(1);
	rep(i, 1, ct){
		int x = lis[i];
		root[x] = x, fa[x] = d[x] = 0;
		erep(i, x){
			int op = e[i].to;
			if (!if_on_loop[op]) {
				root[op] = fa[op] = x, d[op] = 1;
				DFS2(op);
			}
		}
	}
}

bool is_key[maxn]; //only work on loop-node
int up = -1, down = -1;
bool process(){	
	rep(i, 1, m){
		if (root[v[i]] == root[A] || root[v[i]] == root[B]) {	
			swap(v[i], v[m]), i--, m--;
		}
	}
	
	if (!m) return false;

	rep(i, 1, m) is_key[root[v[i]]] = 1;
	return true;
}

void process2(){
	rep(i, 1, ct){
		if (lis[i] == root[A]) {
			int j = i;
			while (lis[j] != root[B]){
				if (is_key[lis[j]]) {
					up = lis[j];
					break;
				}
				j++, j = (j > ct) ? (j - ct) : j;
			}
			j = i;
			while (lis[j] != root[B]){
				if (is_key[lis[j]]) {
					down = lis[j];
					break;
				}
				j--, j = (j <= 0) ? (j + ct) : j;
			}
		}
	}
}

void debug(){
 	printf("\n");
	printf("ct: "); printf("%d: ", ct); rep(i, 1, ct) printf("%d ", lis[i]); printf("\n");
	printf("v: "); rep(i, 1, m) printf("%d ", v[i]); printf("\n");
	printf("root: "); rep(i, 1, n) printf("%d ", root[i]); printf("\n");
	printf("is_key: "); rep(i, 1, n) printf(is_key[i]? "is  " : "not "); printf("\n");
	printf("on_loop: "); rep(i, 1, n) printf(if_on_loop[i]? "on  " : "not "); printf("\n");
	printf("fa: "); rep(i, 1, n) printf("%d ", fa[i]); printf("\n");
	printf("up : %d\ndown : %d\n", up, down);
	printf("\n");
}

void recover(){
	cnt = 1;
	rep(i, 1, n) d[i] = root[i] = fa[i] = 0, is_key[i] = if_on_loop[i] = 0, viss[i] = h[i] = 0;
	tim = ct = 0;
	up = down = -1;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("H.in", "r", stdin);
	#endif
	int T, x, y, x1, x2, y1, y2, mi, mx;
	scanf("%d", &T);
	rep(TT, 1, T){
		printf("Case %d: ", TT);
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d%d", &x, &y), Add_Edge(x, y);
		scanf("%d", &m);
		rep(i, 1, m) scanf("%d", &v[i]);
		scanf("%d%d", &A, &B);
		SPFA(da, A), SPFA(db, B);
		
		//-----------------------Case 0-----------------------//
		rep(i, 1, m){
			if (da[v[i]] <= db[v[i]]) {
				printf("Panda\n");
				goto jump;
			}
		}
		
		get_loop();
		if (!process()) {
			printf("Sheep\n");
			goto jump;
		}
		//-----------------------Case 1.5-----------------------// 
		if (root[A] == root[B]){
			if (d[A] > d[B]) {
				printf("Sheep\n");
				goto jump;
			}
			else {
				printf("Panda\n");
				goto jump;
			}
		}
		
		process2();
		assert(up != -1 || down != -1);
		if (up == -1 || down == -1) {
			if (up == -1) up = down;
			if (da[up] <= db[up]) {
				printf("Panda\n");
				goto jump;
			}
			else {
				printf("Sheep\n");
				goto jump;
			}
		}
		//-----------------------Case 1-----------------------//
		if (d[A] == d[B]) {
			if (da[up] <= db[up] || da[down] <= db[down]) {
				printf("Panda\n");
				goto jump;
			}
			else {
				printf("Sheep\n");
				goto jump;
			}
		}
		//-----------------------Case 2-----------------------//
		x1 = da[up] - da[root[A]], y1 = db[up] - db[root[B]];
		x2 = da[down] - da[root[A]], y2 = db[down] - db[root[B]];
		
		if (y1 - x1 + y2 - x2 > -2) {
			printf("Panda\n");
			goto jump;
		}
		
		if (d[A] < d[B]) {
			mi = min(x1 - y1, x2 - y2);
			if (d[B] - d[A] >= mi) {
				printf("Panda\n");
				goto jump;
			}
			else {
				printf("Sheep\n");
				goto jump;
			}
		}
		//-----------------------Case 3-----------------------//
		if (d[A] > d[B]){
			mx = max(y1 - x1 + 1, y2 - x2 + 1);	
			if (d[A] - d[B] >= mx) {
				printf("Sheep\n");
				goto jump;
			}
			else {
				printf("Panda\n");
				goto jump;
			}
		}
		jump:;
		//debug();
		recover();
	}
	return 0;
}

#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define maxn 131092
#define maxm 1020
#define mo(x) (x = (x >= m) ? (x - m) : x)
using namespace std;

int n, m, q, v[maxn];
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
	h[y]= cnt;
}
int dfs[maxn], idfs[maxn], s[maxn], ti = 0;
void DFS(int x, int fa){
	s[x] = 1;
	dfs[x] = ++ti, idfs[ti] = x;
	erep(i, x){
		int op = e[i].to;
		if (op == fa) continue;
		DFS(op, x);
		s[x] += s[op];
	}
}
bitset<1000> tab[maxn];
bitset<1000> pri;
int p[maxm], cp = 0;
bool vis[maxm];
void init(){
	srep(i, 2, m){	
		if (!vis[i]) p[++cp] = i;
		rep(j, 1, cp){
			if (i * p[j] >= m) break;
			vis[i * p[j]] = 1;
			if (i % p[j] == 0) break;
		}
	}
	rep(i, 1, cp) pri[p[i]] = 1;
	
	srep(i, 0, m) rep(j, 0, i) tab[i][j] = 1;  
}
bitset<1000> sum[maxn << 1];
int add[maxn << 1];
bitset<1000> op, op2, ans;
int qx, qy, qd; 
void pu(int o){
	int v = add[o];
	op = sum[o << 1], op2 = sum[o << 1] & tab[m - v - 1];
	sum[o] = (((op ^ op2) >> (m - v)) ^ (op2 << v));
	op = sum[o << 1 | 1], op2 = sum[o << 1 | 1] & tab[m - v - 1];
	sum[o] |= (((op ^ op2) >> (m - v)) ^ (op2 << v));
	//注意标记永久化的正确姿势，结点 x 的信息是不考虑 x 以上结点的标记的，pushup 时需要考虑当前结点的标记
}
void init(int l, int r, int o){
	if (l == r){
		sum[o][v[idfs[l]]] = 1;
		return;
	}
	int mid = ((r - l) >> 1) + l;
	init(l, mid, o << 1), init(mid + 1, r, o << 1 | 1);
	pu(o);
}

void Add(int l, int r, int o){
	if (qx <= l && r <= qy){
		add[o] += qd, mo(add[o]);// m - qd
		op = sum[o] & tab[m - qd - 1];
		sum[o] = (((sum[o] ^ op) >> (m - qd)) ^ (op << qd));
		return;
	}
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) Add(l, mid, o << 1);
	if (qy > mid) Add(mid + 1, r, o << 1 | 1);
	pu(o);
}
void get(int l, int r, int o, int v){
	if (qx <= l && r <= qy){
		op = sum[o], op2 = sum[o] & tab[m - v - 1];
		ans |= (((op ^ op2) >> (m - v)) ^ (op2 << v)); 
		//注意 bitset 不包含 + - 操作
		return;
	}
	//当前结点的标记已经体现在维护的信息中了，因此不要考虑当前结点标记
	v += add[o], mo(v);
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) get(l, mid, o << 1, v);
	if (qy > mid) get(mid + 1, r, o << 1 | 1, v);
}
int main(){
		
		freopen("I.in", "r", stdin);
	
	int op, x, y;
	scanf("%d%d", &n, &m);
	init();
	rep(i, 1, n) scanf("%d", v + i), v[i] %= m;
	rep(i, 2, n) scanf("%d%d", &x, &y), Add_Edge(x, y); 
	DFS(1, -1), init(1, n, 1);
	scanf("%d", &q);
	rep(i, 1, q){	
		scanf("%d", &op);
		if (op == 1){
			scanf("%d%d", &x, &y);
			qx = dfs[x], qy = dfs[x] + s[x] - 1, qd = y % m;
			Add(1, n, 1);
		}
		else{ 
			scanf("%d", &x);
			ans.reset();
			qx = dfs[x], qy = dfs[x] + s[x] - 1;
			get(1, n, 1, 0);
			printf("%d\n", (ans & pri).count()); //注意学习 bitset 的相关用法
			//注意统计个数必须在最后，因为答案的统计不是积累的
		}
	}
	return 0;
}

#include <bits/stdc++.h>
#define maxn 300019
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
using namespace std;

const int INF = 1073741824;

int n, m;
int l[maxn], b[maxn];
struct edge{
	int next, to;
	edge(int next, int to) : next(next), to(to){}
	edge(){}
}e[maxn << 1];
int h[maxn], cnt = 1;
void Add_Edge(int x, int y){
	e[++cnt] = edge(h[x], y);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x);
	h[y] = cnt;
}

bool vis[maxn], col[maxn]; //c = 0, light, c = 1, black;
bool dfs(int x, int& mil, int& mxl, int& mib, int& mxb, int& _mil, int& _mxl, int& _mib, int& _mxb, bool c){
	vis[x] = 1, col[x] = c;
	
	if (!c) mil = min(mil, l[x]), mxl = max(mxl, l[x]), _mib = min(_mib, b[x]), _mxb = max(_mxb, b[x]);
	else mib = min(mib, b[x]), mxb = max(mxb, b[x]), _mil = min(_mil, l[x]), _mxl = max(_mxl, l[x]);
	
	erep(i, x){
		int op = e[i].to;
		if (vis[op]) {
			if (col[op] != (c ^ 1)) return false;
		}	
		else {
			if (!dfs(op, mil, mxl, mib, mxb, _mil, _mxl, _mib, _mxb, c ^ 1)) return false;
		}
	}
	return true;
}

struct ele{
	int mil, mxl, mib, mxb, _mil, _mxl, _mib, _mxb;
	ele(){}
}p[maxn << 1];
int ct = 0;

struct segment{
	int id, l, r;
	bool operator < (const segment b) const{
		return (l == b.l) ? ((r == b.r) ? id < b.id : r < b.r) : l < b.l;
	}
	//void operator = (const segment b) const{
	//	id = b.id, l = b.l, r = b.r;
	//}
}seg[maxn << 1];
multiset<segment> s;
multiset<int> le, ri;


void recover(){
	cnt = 1;
	rep(i, 1, n) col[i] = vis[i] = 0, h[i] = 0;
	s.clear(), le.clear(), ri.clear();
	ct = 0;
}

int main(){
	//#ifndef ONLINE_JUDGE
	//	freopen("B.in", "r", stdin);
	//#endif
	int T, x, y;
	scanf("%d", &T);
	rep(TT, 1, T){
		printf("Case %d: ", TT);
		scanf("%d%d", &n, &m);
		rep(i, 1, m){
			scanf("%d%d", &x, &y);
			Add_Edge(x, y);
		}
		rep(i, 1, n) scanf("%d%d", &l[i], &b[i]); 
		int ans = 0;
		rep(i, 1, n){
			if (!vis[i]) {
				ct++;
				p[ct].mil = p[ct].mib = p[ct]._mil = p[ct]._mib = INF;
				p[ct].mxl = p[ct].mxb = p[ct]._mxl = p[ct]._mxb = -INF;
				if (!dfs(i, p[ct].mil, p[ct].mxl, p[ct].mib, p[ct].mxb, p[ct]._mil, p[ct]._mxl, p[ct]._mib, p[ct]._mxb, 0)) {
					printf("IMPOSSIBLE\n");
					goto jump;
				}
				seg[(ct << 1) - 1].l = min(p[ct].mil, p[ct].mib), seg[(ct << 1) - 1].r = max(p[ct].mxl, p[ct].mxb);
				seg[ct << 1].l = min(p[ct]._mil, p[ct]._mib), seg[ct << 1].r = max(p[ct]._mxl, p[ct]._mxb);
				if (seg[ct << 1] < seg[(ct << 1) - 1]) swap(seg[(ct << 1) - 1], seg[ct << 1]);
				
				if (seg[(ct << 1) - 1].l == seg[ct << 1].l) {
					seg[ct << 1] = seg[(ct << 1) - 1];
					seg[(ct << 1) - 1].id = ct << 1;
					seg[ct << 1].id = ct << 1;
				}
				else if (seg[ct << 1].l >= seg[(ct << 1) - 1].l && seg[ct << 1].r <= seg[(ct << 1) - 1].r){
					seg[(ct << 1) - 1] = seg[ct << 1];
					seg[(ct << 1) - 1].id = ct << 1;
					seg[ct << 1].id = ct << 1;
				}
				else {
					seg[(ct << 1) - 1].id = (ct << 1) - 1;
					seg[ct << 1].id = ct << 1;
				}
			}
		}
		rep(i, 1, ct) s.insert(seg[(i << 1) - 1]), le.insert(seg[(i << 1) - 1].l), ri.insert(seg[(i << 1) - 1].r);
		ans = *ri.rbegin() - *le.begin();
		while (1){
			segment op = *s.begin();
			s.erase(s.begin());
			le.erase(le.lower_bound(op.l));
			ri.erase(ri.lower_bound(op.r));
			if (op.id & 1) {
				s.insert(seg[op.id + 1]);
				le.insert(seg[op.id + 1].l);
				ri.insert(seg[op.id + 1].r);
				ans = min(ans, *ri.rbegin() - *le.begin());
			}
			else break;
		}
		printf("%d\n", ans);
		jump: recover();
	}
	return 0;
}

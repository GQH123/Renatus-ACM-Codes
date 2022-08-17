#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define ll long long int 
#define pb push_back
#define pc putchar
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn 1000020
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

int n, m;
struct edge{
	int next, to;
	edge(int next, int to) : next(next), to(to){}
	edge(){}
}e[maxn << 1];
int h[maxn], cnt = 1, in[maxn], out[maxn];
void Add_Edge(int x, int y){
	e[++cnt] = edge(h[x], y);
	h[x] = cnt;
}

int cs = 0, ans[maxn];
bool vis[maxn];
int dp[maxn];
int DP(int x){
	if (vis[x]) return dp[x];
	vis[x] = 1;
	int& ans = dp[x]; ans = 0;
	erep(i, x){
		int op = e[i].to;
		ans = max(ans, DP(op) + 1);
	}
	return ans;
}

struct ele{
	int x;
	ele(int x) : x(x){}
	ele(){}
	bool operator < (const ele b) const{
		return (dp[x] != dp[b.x]) ? dp[x] > dp[b.x] : x < b.x;
	}
};
set<ele> bfs;
set<int> d2, d3;
void work(){
	rep(i, 1, n) if (!in[i]) bfs.insert(ele(i));
	while (!bfs.empty()){
		int x = bfs.begin() -> x;
		bfs.erase(bfs.begin());
		int _dp = dp[x];
		dp[x] = 0;
		erep(i, x){
			int op = e[i].to;
			if (vis[op]) continue;
			//vis[op] = 1; 
			dp[x] = max(dp[x], dp[op] + 1);
		}
		if (dp[x] != _dp){
			bfs.insert(ele(x));
			continue;
		}
		vis[x] = 1;
		d2.clear(), d3.clear(); 
			
		erep(i, x){
			int op = e[i].to;
			if (vis[op]) continue;
			//vis[op] = 1;
			d2.insert(op);
			erep(j, op){
				int op2 = e[j].to;
				if (vis[op2]) continue; 
				//vis[op2] = 1;
				d3.insert(op2); 
			}
		}
		if (d2.empty()) continue;
		for (set<int> :: iterator it = d2.begin(); it != d2.end(); it++){ 
			if (d3.count(*it)) {
				d3.clear();
				int _op = *it;
				erep(i, x){
					int op = e[i].to;
					if (vis[op] || op == _op) continue;
					erep(j, op){
						int op2 = e[j].to;
						if (vis[op2]) continue; 
						//vis[op2] = 1;
						d3.insert(op2); 
					}
				}
				d3.insert(_op);  
			}
		}
		if (d3.empty()) continue; 
		for (set<int> :: iterator it = d2.begin(); it != d2.end(); it++){ 
			vis[*it] = 1;
		}
		for (set<int> :: iterator it = d3.begin(); it != d3.end(); it++){
			ans[++cs] = *it; 
			vis[*it] = 1; 
		} 
		for (set<int> :: iterator it = d3.begin(); it != d3.end(); it++){
			int op2 = *it; 
			erep(k, op2){
				int op3 = e[k].to;
				if (vis[op3]) continue;
				in[op3]--;
				if (!in[op3]) bfs.insert(ele(op3));
			}
		}  
	}
}

int main(){
	int T, x, y;
	scanf("%d", &T);
	while (T--){
		scanf("%d%d", &n, &m);
		rep(i, 1, m) scanf("%d%d", &x, &y), Add_Edge(x, y), out[x]++, in[y]++;
		rep(i, 1, n) DP(i);
		rep(i, 1, n) vis[i] = 0;
		work();
		sort(ans + 1, ans + 1 + cs);
		cs = unique(ans + 1, ans + 1 + cs) - ans - 1;
		printf("%d\n", cs);
		rep(i, 1, cs) printf("%d ", ans[i]);
		printf("\n");
		rep(i, 1, n) h[i] = vis[i] = in[i] = out[i] = 0; cnt = 1, cs = 0;
	} 
	return 0;
}


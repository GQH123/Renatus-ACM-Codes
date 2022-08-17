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
#define maxn 200020
#define maxm
#define maxs
#define maxb
#define M 
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

const int inf = 500000000;

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

int n;
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

bool a[maxn];
int idx;
int dp[maxn][2][2];
int vis[maxn][2][2]; 
int DP(int x, int fa, bool opf, bool opx){
	if (vis[x][opf][opx] == idx) return dp[x][opf][opx];
	vis[x][opf][opx] = idx;
	int& ans = dp[x][opf][opx]; ans = inf;
	int now = a[x] ^ opx ^ opf, _opf = opx;
	int tmp[2], _tmp[2]; tmp[0] = tmp[1] = inf, tmp[now] = opx;
	erep(i, x) {
		int op = e[i].to;
		if (op == fa) continue; 
		int ans0 = DP(op, x, _opf, 0), ans1 = DP(op, x, _opf, 1);
		_tmp[0] = min(tmp[0] + ans0, tmp[1] + ans1);
		_tmp[1] = min(tmp[0] + ans1, tmp[1] + ans0); 
		tmp[0] = min(inf, _tmp[0]), tmp[1] = min(_tmp[1], inf);
	}
	return ans = tmp[1];
}

void recover(){
	rep(i, 1, n) h[i] = 0; cnt = 1;
}

class Solution {
public:
    /**
     * @param edges: the edges
     * @param light: the light
     * @return: return the min steps
     */
    int solve(vector<vector<int>> &edges, vector<bool> &light) {
        int _si = edges.size(); n = light.size(); idx++;
        srep(i, 0, _si) Add_Edge(edges[i][0], edges[i][1]); 
        srep(i, 0, n) a[i + 1] = light[i];
        int ans = min(DP(1, 0, 0, 0), DP(1, 0, 0, 1));
        recover();
        if (ans >= inf) return -1;
        else return ans;  
    }
};

int main(){ 
	int x, y; 	
		idx++;
		cin >> n;
		rep(i, 2, n) cin >> x >> y, Add_Edge(x, y);
		rep(i, 1, n) cin >> a[i];
		int ans = min(DP(1, 0, 0, 0), DP(1, 0, 0, 1));
		if (ans >= inf) printf("-1\n");
		else printf("%d\n", ans);
		recover(); 
	return 0;
}


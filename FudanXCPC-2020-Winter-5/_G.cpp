#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int
#define maxn 120
#define maxm 
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define eps 1e-4
using namespace std;

int n, g[maxn][maxn];

struct ele{
	double v;
	int id;
	ele(double v, int id) : v(v), id(id){}
	ele(){}
	bool operator < (const ele b) const{
		return v > b.v;
	}
}a[maxn][maxn];

double mx[maxn];
double suf[maxn];

int T = 20;
double nowans = 0, totans = 0;
int now[maxn], out[maxn], _out[maxn];
bool vis[maxn];
void DFS(int pos){
	if (pos == n + 1) {	
		T--;	
		if (nowans > totans) {
			totans = nowans;
			rep(i, 1, n) out[i] = now[i];
		}
		return;
	}
	rep(i, 1, n){
		if (nowans + suf[pos] - totans < eps) return;
		if (!T) return;
		int id = a[pos][i].id;
		double v = a[pos][i].v;
		if (!vis[id]) {
			vis[id] = 1;
			now[pos] = id;
			nowans += v;
			DFS(pos + 1);
			nowans -= v;
			now[pos] = -1;
			vis[id] = 0;
		}
	}
}


int main(){
	freopen("G.in", "r", stdin);
	
	scanf("%d", &n);
	rep(i, 1, n){
		rep(j, 1, n){
			scanf("%d", &g[i][j]), a[i][j].v = log(g[i][j]), a[i][j].id = j, mx[i] = max(mx[i], a[i][j].v);
		}
		sort(a[i] + 1, a[i] + 1 + n);
	}
	//rep(i, 1, n) rep(j, 1, n) printf("%lf ", exp(a[i][j].v));
	per(i, n, 1) suf[i] = mx[i] + suf[i + 1];
	DFS(1);
	rep(i, 1, n) _out[out[i]] = i;
	rep(i, 1, n) printf("%d ", _out[i]);
	//printf("%lf", totans);
	return 0;
}


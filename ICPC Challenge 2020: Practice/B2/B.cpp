#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define maxn 300020
#define maxm 3000020
#define ll long long int 
using namespace std;

int n, m;
struct edge{
	int next, to;
	edge(int next, int to) : next(next), to(to){}
	edge(){}
}e[maxm << 1];
int cnt = 1, h[maxn];
void Add_Edge(int x, int y){
	e[++cnt] = edge(h[x], y);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x);
	h[y] = cnt;
}

namespace Judge_Bigraph{
	int col[maxn];
	bool dfs(int x, int cc){
		if (col[x]) return col[x] == cc;
		else col[x] = cc;
		erep(i, x){
			int op = e[i].to;
			if (!dfs(op, 3 - cc)) return false;
		}
		return true;
	}
	bool work(){ 
		rep(i, 1, n){
			if (!col[i]) {
				if (!dfs(i, 1)) {
					return false;
				}
			}
		}
		return true;
	}
}

namespace Random_Color{
	char filename[] = "b20.out";
	int col[maxn], num[maxn];
	set<int> s;
	void dfs(int x){
		if (col[x]) return;  
		erep(i, x){
			int op = e[i].to;
			if (col[op]) s.insert(col[op]); 
		}
		//cerr << x << ' ' << s.size() << endl;
		rep(i, 1, n) if (!s.count(i)) {col[x] = i; break;} 
		num[col[x]]++;
		s.clear(); 
	}
	int ans[maxn];
	void getans(){
		int mx = 0;
		rep(i, 1, n) mx = max(mx, num[i]); 
		rep(i, 1, n){
			if (num[i] == mx){
				rep(j, 1, n) if (col[j] == i) ans[j] = 1; 
				break;
			}
		}
		cout << endl << mx << endl;
		rep(i, 1, n) cout << ans[i] << ' '; cout << endl;
	}
	void recover(){
		rep(i, 1, n) col[i] = num[i] = ans[i] = 0;
	}
	int lis[maxn];
	void work(){
		int mx = 0, T = 0, _mx = mx;
		rep(i, 1, n) lis[i] = i;
		while (1){
			recover(); 
			random_shuffle(lis + 1, lis + 1 + n);
			rep(i, 1, n) dfs(lis[i]);
			rep(i, 1, n) mx = max(mx, num[i]); 
			if (mx > _mx) {
				freopen(filename, "w", stdout);
				cerr << mx << endl;
				getans();
				T++;
				filename[2] = '0' + T;
			}
			_mx = mx;
		}  
		//rep(i, 1, n) if (num[i]) printf("col = %d, num = %d\n", i, num[i]);
	}
}


int main(){ 
	srand(time(NULL));
	int x, y;
	scanf("%d%d", &n, &m);
	rep(i, 1, m) scanf("%d%d", &x, &y), Add_Edge(x, y); 
	Random_Color :: work();
	//Random_Color :: getans();
	return 0;
}

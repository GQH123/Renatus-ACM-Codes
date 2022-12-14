#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define maxn 300020
#define maxm 3000020
#define pb push_back
#define ll long long int 
using namespace std;

int n, m;
struct edge{
	int next, to;
	edge(int next, int to) : next(next), to(to){}
	edge(){}
}e[maxm << 1];
int cnt = 1, h[maxn], deg[maxn];
vector<int> G[maxn];
void Add_Edge(int x, int y){
	e[++cnt] = edge(h[x], y);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x);
	h[y] = cnt;
	deg[x]++, deg[y]++;
	G[x].pb(y), G[y].pb(x);
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

namespace Sorted_Color{
	char filename[] = "b20.out";
	int col[maxn], num[maxn];
	set<int> s;
	bool cmp(const int i, const int j){
		return deg[i] < deg[j];
	}
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
		cerr << endl << mx << endl;
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
		recover();
		sort(lis + 1, lis + 1 + n, cmp);
		rep(i, 1, n) dfs(lis[i]);
		getans();
		/*
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
		*/
		//rep(i, 1, n) if (num[i]) printf("col = %d, num = %d\n", i, num[i]);
	}
}

namespace Sorted_BFS_Color{
	char filename[] = "b20.out";
	int col[maxn], num[maxn];
	set<int> s;
	bool cmp(const int i, const int j){
		return deg[i] < deg[j];
	}
	int bfs[maxn], head = 0, tail = 0;
	bool vis[maxn];
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
	void BFS(int ss){
		head = tail = 0;
		bfs[++head] = ss;
		vis[ss] = 1;
		while (head != tail){
			int x = bfs[++tail]; 
			erep(i, x){
				int op = e[i].to;
				if (col[op]) s.insert(col[op]); 
			}
			//cerr << x << ' ' << s.size() << endl;
			rep(i, 1, n) if (!s.count(i)) {col[x] = i; break;} 
			num[col[x]]++;
			s.clear(); 
			erep(i, x){
				int op = e[i].to;
				if (!col[op] && !vis[op]) bfs[++head] = op, vis[op] = 1;
			}
		}
	}
	void BFS(){
		rep(i, 1, n) if (!vis[i]) BFS(i); 
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
		cerr << endl << mx << endl;
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
		recover();
		sort(lis + 1, lis + 1 + n, cmp);
		rep(i, 1, n) sort(G[i].begin(), G[i].end(), cmp);
		//rep(i, 1, n) printf("%d ", deg[lis[i]]);
		//rep(i, 1, n) dfs(lis[i]);
		BFS();
		getans();
		/*
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
		*/
		//rep(i, 1, n) if (num[i]) printf("col = %d, num = %d\n", i, num[i]);
	}
}


int main(){ 
	srand(time(NULL));
	int x, y;
	scanf("%d%d", &n, &m);
	rep(i, 1, m) scanf("%d%d", &x, &y), Add_Edge(x, y); 
	//Random_Color :: work();
	//Random_Color :: getans();
	//Sorted_Color :: work();
	Sorted_BFS_Color :: work();
	return 0;
}

#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define maxn 200020
#define maxm 20000020
#define pb push_back
using namespace std;

int n, m;
struct edge{
	int next, to;
	edge(int next, int to) : next(next), to(to){}
	edge(){}
}e[maxm << 1];
int cnt = 1, h[maxn], deg[maxn];
void Add_Edge(int x, int y){
	e[++cnt] = edge(h[x], y);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x);
	h[y] = cnt;
	deg[x]++, deg[y]++;
}

namespace DEGREE{
	int lis[maxn];
	bool cmp(const int i, const int j){
		return deg[i] > deg[j];
	}
	void work(){
		rep(i, 1, n) lis[i] = i;
		sort(lis + 1, lis + 1 + n, cmp);
		rep(i, 1, n) printf("%d: %d\n", lis[i], deg[lis[i]]);
	}
}

namespace A1_BFS1{
	vector<int> ans[maxn];
	int lis[maxn], cs = 0;
	int vis[maxn];
	int bfs[maxn], head = 0, tail = 0;
	void part(int hold){
		rep(i, 1, n) if (deg[i] >= hold) lis[++cs] = i;	
		sort(lis + 1, lis + 1 + cs, DEGREE :: cmp);
		rep(j, 1, cs) {
			int x = lis[j];
			ans[j].pb(x), vis[x] = j, bfs[++head] = x;
		} 
		while (head != tail){
			int x = bfs[++tail];
			erep(i, x){
				int op = e[i].to;
				if (vis[op]) continue;
				vis[op] = vis[x];
				bfs[++head] = op;
				ans[vis[op]].pb(op);
			}
		}
		rep(i, 1, cs){
			int si = ans[i].size();
			srep(j, 0, si){	
				printf("%d ", ans[i][j] - 1);
			}
			printf("\n");
		}
	}
}

namespace A1_BFS2{
	vector<int> ans[maxn];
	int lis[maxn], cs = 0;
	int vis[maxn];
	int bfs[maxn], head = 0, tail = 0;
	void BFS(int s, int d, int c){
		head = tail = 0;
		bfs[++head] = s;
		vis[s] = c, ans[c].pb(s);
		rep(TT, 1, d){
			int _head = head;
			while (_head != tail){
				int x = bfs[++tail];
				erep(i, x){
					int op = e[i].to;
					if (vis[op]) continue;
					vis[op] = c, ans[c].pb(op), bfs[++head] = op;
				}
			}
		}
	} 
	void part(int hold){
		rep(i, 1, n) lis[i] = i;
		sort(lis + 1, lis + 1 + n, DEGREE :: cmp); 
		int cs = 0;
		rep(i, 1, n){
			int x = lis[i];
			if (vis[x]) continue;
			++cs;
			BFS(x, hold, cs);
		}
		cerr << cs << ' ';
		rep(i, 1, cs){
			int si = ans[i].size();
			cerr << si << ' ';
			srep(j, 0, si){	
				printf("%d ", ans[i][j] - 1);
			}
			printf("\n");
		}
	}
}

namespace A1_BFS3{
	vector<int> ans[maxn];
	int lis[maxn], cs = 0;
	int vis[maxn];
	int bfs[maxn], head = 0, tail = 0;
	void BFS(int s, int d, int c){
		head = tail = 0;
		bfs[++head] = s;
		vis[s] = c, ans[c].pb(s);
		rep(TT, 1, d){
			int _head = head;
			while (_head != tail){
				int x = bfs[++tail];
				erep(i, x){
					int op = e[i].to;
					if (vis[op]) continue;
					vis[op] = c, ans[c].pb(op), bfs[++head] = op;
				}
			}
		}
	} 
	int num[maxn];
	void part(int hold){
		rep(i, 1, n) lis[i] = i;
		sort(lis + 1, lis + 1 + n, DEGREE :: cmp); 
		int cs = 0;
		rep(i, 1, n){
			int x = lis[i];
			if (vis[x]) continue;
			int mx = 0, mx2 = 0;
			erep(j, x){
				int op = e[j].to;
				if (!vis[op]) continue;
				num[vis[op]]++;
				if (num[vis[op]] > mx) mx = num[vis[op]], mx2 = vis[op]; 
			}
			if (mx * 2 >= deg[x]) {
				vis[x] = mx2, ans[vis[x]].pb(x);
				erep(j, x){
					int op = e[j].to;
					if (!vis[op]) continue;
					num[vis[op]]--; 
				}
				continue;
			}
			erep(j, x){
				int op = e[j].to;
				if (!vis[op]) continue;
				num[vis[op]]--; 
			}
			++cs;
			BFS(x, hold, cs);
		}
		cerr << cs << ' ';
		rep(i, 1, cs){
			int si = ans[i].size();
			cerr << si << ' ';
			srep(j, 0, si){	
				printf("%d ", ans[i][j] - 1);
			}
			printf("\n");
		}
	}
}

namespace A1_BFS4{
	vector<int> ans[maxn];
	int lis[maxn], cs = 0;
	int vis[maxn];
	int bfs[maxn], head = 0, tail = 0;
	void BFS(int s, int d, int c, int maxs){
		head = tail = 0;
		bfs[++head] = s;
		vis[s] = c, ans[c].pb(s);
		rep(TT, 1, d){
			int _head = head;
			while (_head != tail){
				int x = bfs[++tail];
				erep(i, x){
					int op = e[i].to;
					if (vis[op]) continue;
					vis[op] = c, ans[c].pb(op), bfs[++head] = op;
					if (ans[c].size() == maxs) return;
				}
			}
		}
	} 
	int num[maxn];
	void part(int hold, int hold2){
		rep(i, 1, n) lis[i] = i;
		sort(lis + 1, lis + 1 + n, DEGREE :: cmp); 
		int cs = 0;
		rep(i, 1, n){
			int x = lis[i];
			if (vis[x]) continue;
			int mx = 0, mx2 = 0;
			erep(j, x){
				int op = e[j].to;
				if (!vis[op]) continue;
				num[vis[op]]++;
				if (num[vis[op]] > mx) mx = num[vis[op]], mx2 = vis[op]; 
			}
			if (mx * 2 >= deg[x]) {
				vis[x] = mx2, ans[vis[x]].pb(x);
				erep(j, x){
					int op = e[j].to;
					if (!vis[op]) continue;
					num[vis[op]]--; 
				}
				continue;
			}
			erep(j, x){
				int op = e[j].to;
				if (!vis[op]) continue;
				num[vis[op]]--; 
			}
			++cs;
			BFS(x, hold, cs, hold2);
		}
		cerr << cs << ' ';
		rep(i, 1, cs){
			int si = ans[i].size();
			cerr << si << ' ';
			srep(j, 0, si){	
				printf("%d ", ans[i][j] - 1);
			}
			printf("\n");
		}
	}
}

namespace A1_BFS5{
	vector<int> ans[maxn];
	int lis[maxn], cs = 0;
	int vis[maxn];
	int bfs[maxn], head = 0, tail = 0;
	void BFS(int s, int d, int c, int maxs){
		head = tail = 0;
		bfs[++head] = s;
		vis[s] = c, ans[c].pb(s);
		rep(TT, 1, d){
			int _head = head;
			while (_head != tail){
				int x = bfs[++tail];
				erep(i, x){
					int op = e[i].to;
					if (vis[op]) continue;
					vis[op] = c, ans[c].pb(op), bfs[++head] = op;
					if (ans[c].size() == maxs) return;
				}
			}
		}
	} 
	int num[maxn];
	void part(int hold, int hold2, int hold3){
		rep(i, 1, n) lis[i] = i;
		sort(lis + 1, lis + 1 + n, DEGREE :: cmp); 
		int cs = 0; 
		rep(i, 1, n){
			int x = lis[i];
			if (vis[x]) continue;
			if (i <= hold3){
				int mx = 0, mx2 = 1;
				erep(j, x){
					int op = e[j].to;
					if (!vis[op]) continue;
					num[vis[op]]++;
					if (num[vis[op]] > mx) mx = num[vis[op]], mx2 = vis[op]; 
				}
				if (mx * 2 >= deg[x]) {
					vis[x] = mx2, ans[vis[x]].pb(x);
					erep(j, x){
						int op = e[j].to;
						if (!vis[op]) continue;
						num[vis[op]]--; 
					}
					continue;
				}
				erep(j, x){
					int op = e[j].to;
					if (!vis[op]) continue;
					num[vis[op]]--; 
				}
				++cs;
				BFS(x, hold, cs, hold2);
			}
			else {
				int mx = 0, mx2 = 1;
				erep(j, x){
					int op = e[j].to;
					if (!vis[op]) continue;
					num[vis[op]]++;
					if (num[vis[op]] > mx) mx = num[vis[op]], mx2 = vis[op]; 
				}
				if (mx){
					vis[x] = mx2, ans[vis[x]].pb(x); 
					erep(j, x){
						int op = e[j].to;
						if (!vis[op]) continue;
						num[vis[op]]--; 
					} 
					continue;
				}
				else {
					erep(j, x){
						int op = e[j].to;
						if (!vis[op]) continue;
						num[vis[op]]--; 
					} 
					++cs;
					BFS(x, hold, cs, hold2);
				}
			}
		}
		cerr << cs << ' ';
		rep(i, 1, cs){
			int si = ans[i].size();
			cerr << si << ' ';
			srep(j, 0, si){	
				printf("%d ", ans[i][j] - 1);
			}
			printf("\n");
		}
	}
}

int main(){
	int x, y;
	while (scanf("%d%d", &x, &y) == 2){
		x++, y++;
		n = max(n, x), n = max(n, y);
		m++; 
		Add_Edge(x, y);
	} 
	//A1_BFS1 :: part(1000); //118305.414
	//A1_BFS2 :: part(1); // Not bad !!!
	//A1_BFS3 :: part(1);
	//A1_BFS4 :: part(100, 6162);
	A1_BFS5 :: part(100, 4013, 200000);
	//DEGREE :: work();
	//cerr << n << ' ' << m << endl;
	//A1, 196591 950327
	//A2, 197763 19984650
	//A3, 195941 8820386
    return 0;
}

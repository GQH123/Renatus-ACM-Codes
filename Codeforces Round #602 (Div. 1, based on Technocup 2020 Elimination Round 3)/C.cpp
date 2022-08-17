#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 2000020
using namespace std;

int n, m;
char g[maxn];
bool vis[maxn];
int bfs[maxn];
int head = 0, tail = 0;
inline int id(int x, int y){
	return x * m + y;
}
inline bool check(int x, int y){
	return 0 <= x && x < n && 0 <= y && y < m;
}

void print(){
	int ptr = 0;
	rep(i, 1, n){
		rep(j, 1, m){
			printf("%c", g[ptr++]);
		}
		printf("\n");
	}
}

int main(){
	scanf("%d%d", &n, &m);
	rep(i, 1, n) scanf("%s", g + (i - 1) * m); 
	
	srep(i, 0, n * m) if (g[i] == '.') {
		int a = i / m, b = i % m;
		rep(x, -1, 1) rep(y, -1, 1){	
			if (!x && !y) continue;
			if (check(a + x, b + y) && g[id(a + x, b + y)] == 'X' && !vis[id(a + x, b + y)]) {
				vis[id(a + x, b + y)] = 1;
				//g[id(a + x, b + y)] = '.';
				bfs[head++] = id(a + x, b + y);
			}
		}
	}
	rep(i, 0, 0) srep(j, 0, m) {
		if (g[id(i, j)] == 'X' && !vis[id(i, j)]) {
			vis[id(i, j)] = 1; 
			bfs[head++] = id(i, j);
		}
	}
	srep(i, 0, n) rep(j, 0, 0){
		if (g[id(i, j)] == 'X' && !vis[id(i, j)]) {
			vis[id(i, j)] = 1;  
			bfs[head++] = id(i, j);
		}
	}
	rep(i, n - 1, n - 1) srep(j, 0, m) {
		if (g[id(i, j)] == 'X' && !vis[id(i, j)]) {
			vis[id(i, j)] = 1; 
			bfs[head++] = id(i, j);
		}
	}
	srep(i, 0, n) rep(j, m - 1, m - 1){
		if (g[id(i, j)] == 'X' && !vis[id(i, j)]) {
			vis[id(i, j)] = 1; 
			bfs[head++] = id(i, j);
		}
	}
	srep(ii, 0, head) g[bfs[ii]] = '.'; 
	int ans = 0;
	while (tail < head){
		print();
		srep(ii, tail, head){
			int i = bfs[ii];
			int a = i / m, b = i % m;
			bool f = 0;
			rep(x, -1, 1) rep(y, -1, 1){	
				if (!x && !y) continue;
				if (check(a + x, b + y) && g[id(a + x, b + y)] == 'X') {
					f = 1;
					goto done;
				}
			}
			done:;
			if (!f) goto finish;
		} 
		ans++;
		int _head = head;
		srep(ii, tail, _head){
			int i = bfs[ii];
			int a = i / m, b = i % m; 
			rep(x, -1, 1) rep(y, -1, 1){	
				if (!x && !y) continue;
				if (check(a + x, b + y) && g[id(a + x, b + y)] == 'X') { 
					g[id(a + x, b + y)] = '.';
					bfs[head++] = id(a + x, b + y);
				}
			} 
		}
		tail = _head;
	}
	finish:;
	srep(ii, tail, head) g[bfs[ii]] = 'X'; 
	printf("%d\n", ans);
	print();
	return 0;
}

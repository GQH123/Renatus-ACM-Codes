#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
#define maxn 3020
#define maxm
using namespace std;

int n; char g[maxn][maxn]; bool vis[maxn][maxn];
//multiset<char> row[maxn], col[maxn]; 
int row[maxn][26], nrow[maxn], col[maxn][26], ncol[maxn];
int rlis[maxn], hr = 0, tr = 0, clis[maxn], hc = 0, tc = 0;
bool rvis[maxn], cvis[maxn];

struct ele{
	char type, ch; int x;
	ele(){}
	ele(char type, int x, char ch) : type(type), x(x), ch(ch){}
	void print(){
		printf("%c %d %c\n", type, x, ch);
	}
}q[maxn << 1];
int main(){
	scanf("%d", &n);
	rep(i, 1, n) scanf("%s", g[i] + 1);
	rep(i, 1, n) rep(j, 1, n) {
		if (g[i][j] != '?') { 
			int id = g[i][j] - 'a';
			if (!row[i][id]) nrow[i]++;
			row[i][id]++;
			if (!col[j][id]) ncol[j]++;
			col[j][id]++; 
		}
	}
	rep(i, 1, n) if (nrow[i] <= 1) rlis[++hr] = i, rvis[i] = 1;
	rep(j, 1, n) if (ncol[j] <= 1) clis[++hc] = j, cvis[j] = 1;
	rep(TT, 1, 2 * n){
		if (hr != tr) {
			int i = rlis[++tr]; 
			char ch = 'z';
			if (nrow[i]){
				rep(id, 0, 25) {
					if (row[i][id]) {
						ch = 'a' + id;
						break;
					}
				}
			}
			rep(j, 1, n) {
				if (!vis[i][j]) {	
					vis[i][j] = 1;
					if (g[i][j] != '?') { 
						int id = g[i][j] - 'a';
						if (!cvis[j]) { 
							if (col[j][id] == 1) ncol[j]--; col[j][id]--;
							if (ncol[j] <= 1) clis[++hc] = j, cvis[j] = 1;
						}
					}
				}
			}
			q[TT] = ele('h', i, ch);//printf("h %d %c\n", i, ch);
		}
		else if (hc != tc){
			int j = clis[++tc]; 
			char ch = 'z';
			if (ncol[j]) {
				rep(id, 0, 25) {
					if (col[j][id]) {
						ch = 'a' + id;
						break;
					}
				}
			}
			rep(i, 1, n) {
				if (!vis[i][j]) {	
					vis[i][j] = 1;
					if (g[i][j] != '?') { 
						int id = g[i][j] - 'a';
						if (!rvis[i]) {
							if (row[i][id] == 1) nrow[i]--; row[i][id]--;
							if (nrow[i] <= 1) rlis[++hr] = i, rvis[i] = 1;
						}
					}
				}
			}
			q[TT] = ele('v', j, ch);
		}
		else assert(false);
	}
	per(i, 2 * n, 1) q[i].print();
	return 0;
}

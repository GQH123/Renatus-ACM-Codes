#include <bits/stdc++.h>
#define maxr 100000
#define maxm 205
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define pb push_back
using namespace std;
const int inf = 100000000;
char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}

int n, m;
char s[maxm], t[maxm];
vector<int> pos[maxm];
vector<int> nnew[30];
vector<int> tmp;

void intersect(int id, int p){
	tmp.clear();
	int szid = nnew[id].size();
	int szp = pos[p].size();
	srep(i, 0, szid){
		srep(j, 0, szp){
			if (nnew[id][i] == pos[p][j]) {
				tmp.pb(nnew[id][i]);
				break;
			}
		}
	}
	pos[p].clear();
	int szt = tmp.size();
	srep(i, 0, szt) pos[p].pb(tmp[i]);
}
bool vis[maxm];
int ans[maxm];
int main(){
	#ifndef ONLINE_JUDGE	
		freopen("B.in", "r", stdin);
	#endif
	int T;
	scanf("%d", &T);
	while (T--){
		scanf("%d%d", &n, &m);
		rep(i, 1, m) pos[i].clear();
		rep(i, 1, m) rep(j, 1, m) pos[i].pb(j);
		rep(i, 1, n) {
			scanf("%s%s", s + 1, t + 1);
			rep(j, 0, 25) nnew[j].clear();
			rep(j, 1, m) nnew[t[j] - 'a'].pb(j); 
			rep(j, 1, m) intersect(s[j] - 'a', j); 
		}
		rep(i, 1, m) vis[i] = 0;
		rep(i, 1, m){
			if (pos[i].empty()) {
				printf("-1");
				goto jump;
			}
			else {
				int szp = pos[i].size(), mi = inf;
				srep(j, 0, szp){
					if (vis[pos[i][j]]) continue;
					mi = min(mi, pos[i][j]);
				}
				if (mi == inf) {
					printf("-1");
					goto jump;
				}
				else {
					ans[i] = mi, vis[mi] = 1;
				}
			}
		}
		printf("%d", ans[1]); rep(i, 2, m) printf(" %d", ans[i]); 
		jump: printf("\n");
	}
	return 0;
}

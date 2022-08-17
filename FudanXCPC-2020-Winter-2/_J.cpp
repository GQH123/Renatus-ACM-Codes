#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 220
#define pb push_back
using namespace std;

int r, c;
int s[maxn];
int seg[maxn][maxn];
int ans[maxn][maxn];

int bound, id;
bool vis[maxn][maxn];
bool dp[maxn][maxn];
bool DP(int pos, int num){
	if (num == s[id] + 1) {
		if (id <= r){
			rep(i, pos, bound) if (ans[id][i] == 3) return false;
		}
		else {
			rep(i, pos, bound) if (ans[i][id - r] == 3) return false;
		}
		return true;
	}
	if (bound - pos + 1 < seg[id][num]) return false;
	if (vis[pos][num]) return dp[pos][num];
	vis[pos][num] = 1;
	bool& anss = dp[pos][num];
	anss = false;
	if (id <= r){
		bool f = 1;
		srep(i, pos, pos + seg[id][num]) if (ans[id][i] == 2) {f = 0; break;}
		if (pos + seg[id][num] <= bound && ans[id][pos + seg[id][num]] == 3) f = 0;
		if (f) anss |= DP(pos + seg[id][num] + 1, num + 1);
		if (ans[id][pos] != 3) anss |= DP(pos + 1, num);
		return anss;
	}
	else {
		bool f = 1;
		srep(i, pos, pos + seg[id][num]) if (ans[i][id - r] == 2) {f = 0; break;}
		if (pos + seg[id][num] <= bound && ans[pos + seg[id][num]][id - r] == 3) f = 0;
		if (f) anss |= DP(pos + seg[id][num] + 1, num + 1);
		if (ans[pos][id - r] != 3) anss |= DP(pos + 1, num);
		return anss;
	}
	return false;
}
inline void recover(){
	rep(i, 0, bound + 5) rep(j, 0, s[id] + 5) vis[i][j] = dp[i][j] = 0;
}

void DFS(int x){
	if (x > r){
		rep(i, 1, r){
			if (ans[i][x - r] == 1){
				ans[i][x - r] = 2;
				id = x, bound = (x > r) ? r : c;
				if (recover(), !DP(1, 1)) {
					ans[i][x - r] = 3;
					DFS(i);
					continue;
				}
				
				ans[i][x - r] = 3;
				id = x, bound = (x > r) ? r : c;
				if (recover(), !DP(1, 1)) {
					ans[i][x - r] = 2;
					DFS(i);
					continue;
				}
				
				ans[i][x - r] = 1;
			}
		}
	}
	else {
		rep(i, 1, c){
			if (ans[x][i] == 1){
				ans[x][i] = 2;
				id = x, bound = (x > r) ? r : c;
				if (recover(), !DP(1, 1)) {
					ans[x][i] = 3;
					DFS(r + i);
					continue;
				}
				
				ans[x][i] = 3;
				id = x, bound = (x > r) ? r : c;
				if (recover(), !DP(1, 1)) {
					ans[x][i] = 2;
					DFS(r + i);
					continue;
				}
				
				ans[x][i] = 1;
			}
		}
	}
}

/*
int bfs[maxn];
int head, tail;
bool vis[maxn];
*/
int main(){
	freopen("J.in", "r", stdin);
	int x, k;
	scanf("%d%d", &r, &c);
	rep(i, 1, r + c){
		scanf("%d", &s[i]);
		rep(j, 1, s[i]) scanf("%d", &seg[i][j]);
	}
	rep(i, 1, r) rep(j, 1, c) ans[i][j] = 1;
	rep(i, 1, r + c) DFS(i);
	//rep(i, 1, r + c) DFS(i);
	//rep(i, 1, r + c) DFS(i);
	/*rep(i, 1, r){
		id = i, bound = c;
		rep(j, 1, c){
			ans[i][j] = 2;
			if (recover(), !DP(1, 1)) {ans[i][j] = 3; continue;}
			ans[i][j] = 3;
			if (recover(), !DP(1, 1)) {ans[i][j] = 2; continue;}
			ans[i][j] = 1;
		}
	}
	rep(i, r + 1, r + c) bfs[++head] = i, vis[i] = 1;
	while (head != tail){
		id = bfs[++tail], vis[id] = 0;
		tail = (tail == maxn - 1) ? 0 : tail;
		bound = (id > r) r : c;
		if (id > r){
			rep(i, 1, r){
				if (ans[i][id - r] == 1){
				
					ans[i][id - r] = 2;
					if (recover(), !DP(1, 1)) {
						ans[i][id - r] = 3; 
						if (!vis[i]) {
							vis[i] = 1;
							bfs[++head] = i;
							head = (head == maxn - 1) ? 0 : head;
						}
						continue;
					}
					
					ans[i][id - r] = 3;
					if (recover(), !DP(1, 1)) {
						ans[i][id - r] = 2; 
						if (!vis[i]) {
							vis[i] = 1;
							bfs[++head] = i;
							head = (head == maxn - 1) ? 0 : head;
						}
						continue;
					}
					
				}
			}
		}
		else {
			rep(i, 1, c){
				if (ans[id][i] == 1){
				}
			}
		}
	}*/
	rep(i, 1, r){
		rep(j, 1, c){
			if (ans[i][j] == 1) printf("?");
			else if (ans[i][j] == 2) printf(".");
			else if (ans[i][j] == 3) printf("X");
			else assert(false);
		}
		printf("\n");
	}
	return 0;
}

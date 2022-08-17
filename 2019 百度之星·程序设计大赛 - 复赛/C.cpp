#include <bits/stdc++.h>
#define maxn 200005
#define maxm 
#define maxr 100000
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define ll long long int 
#define M 1000000007
#define mo(x) x = ((x >= M) ? (x - M) : x)
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}

int n;
int ch[maxn][2];
bool root[maxn];
int ROOT;
bool dir[maxn];
int siz[maxn];
int DFS(int x){
	if (!x) return n + 1;
	int a = DFS(ch[x][0]);
	int b = DFS(ch[x][1]);
	siz[x] = 1 + siz[ch[x][0]] + siz[ch[x][1]];
	if (x < min(a, b)) {
		dir[x] = (siz[ch[x][0]] == siz[ch[x][1]]) ? (a > b) : (siz[ch[x][0]] > siz[ch[x][1]]);
	}
	else dir[x] = (a > b);
	return min(min(a, b), x);
}

int t = 0;
int dfs[maxn];
void DFS2(int x){
	if (!x) return;
	DFS2(ch[x][dir[x]]);
	dfs[x] = ++t;
	DFS2(ch[x][dir[x] ^ 1]);
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("C.in", "r", stdin);
	#endif
	int T;
	read(T);
	while (T--){
		t = 0;
		read(n);
		rep(i, 1, n) root[i] = 1;
		rep(i, 1, n) read(ch[i][0]), read(ch[i][1]), root[ch[i][0]] = root[ch[i][1]] = 0;
		rep(i, 1, n){
			if (root[i]) {
				ROOT = i;
				break;
			}
		}
		DFS(ROOT), DFS2(ROOT);
		ll ans = 0, now = 233;
		rep(i, 1, n){
			ans += (dfs[i] ^ i) * now % M, mo(ans);
			now = (now * 233) % M;
		}
		printf("%lld\n", ans);
	}
	return 0;
}

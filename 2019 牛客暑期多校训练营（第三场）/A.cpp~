#include <bits/stdc++.h>
#define maxr 100000
#define maxn 100105
#define maxm 300205
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define pb push_back
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (ch != '-' && !('0' <= ch && ch <= '9')) ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}
int n, m, q, bound;
int deg[maxn];
int cs = 0;
int lis[maxn];
vector<int> s[maxn];
vector<int> to[maxn];
vector<int> pre[maxn];
int val[maxn];
int sum[maxn];

bool rev[maxm << 1];
int qx, qy;
void init(int l, int r, int o){
	rev[o] = 0;
	if (l == r) return;
	int m = ((r - l) >> 1) + l;
	init(l, m, o << 1), init(m + 1, r, o << 1 | 1);
}
inline void pd(int o){
	if (rev[o]) rev[o << 1] ^= 1, rev[o << 1 | 1] ^= 1, rev[o] = 0;
}
void modify(int l, int r, int o){
	if (l < r) pd(o);
	if (qx <= l && r <= qy) {
		rev[o] ^= 1;
		return;
	}
	int m = ((r - l) >> 1) + l;
	if (qx <= m) modify(l, m, o << 1);
	if (qy > m) modify(m + 1, r, o << 1 | 1);
}
bool get(int l, int r, int o){
	if (l == r) return rev[o] ^ 1;
	pd(o);
	int m = ((r - l) >> 1) + l;
	if (qx <= m) return get(l, m, o << 1);
	else return get(m + 1, r, o << 1 | 1);
}

int cal(int x){
	if (deg[x] >= bound){
		return sum[x];
	}
	else {
		int ans = 0;
		int sz = s[x].size();
		srep(i, 0, sz){
			qx = s[x][i];
			if (get(1, m, 1)) ans ^= val[to[x][i]];
		}
		return ans;
	}
}
void recover(){
	rep(i, 1, n) deg[i] = 0, to[i].clear(), s[i].clear(), pre[i].clear();
	cs = 0;
}
int main(){
	srand(time(NULL));
	#ifndef ONLINE_JUDGE
		freopen("A.in", "r", stdin);
	#endif
	int T;
	read(T);
	while (T--){
		int x, y, z;
		read(n), read(m);
		init(1, m, 1);
		bound = (int)sqrt(m << 1);
		rep(i, 1, m) read(x), read(y), s[x].pb(i), to[x].pb(y), s[y].pb(i), to[y].pb(x), deg[x]++, deg[y]++;
		rep(i, 1, n) val[i] = rand();
		rep(i, 1, n) {
			if (deg[i] >= bound){
				lis[++cs] = i;
				int sz = s[i].size();
				pre[i].pb(val[to[i][0]]);
				srep(j, 1, sz) pre[i].pb(val[to[i][j]] ^ pre[i][j - 1]);
				sum[i] = pre[i][sz - 1];
			}
		}
		read(q);
		
		rep(i, 1, q){
			read(x), read(y), read(z);
			if (x == 1){
				qx = y, qy = z, modify(1, m, 1);
				rep(j, 1, cs){
					int now = lis[j];
					int l = lower_bound(s[now].begin(), s[now].end(), y) - s[now].begin();
					int r = upper_bound(s[now].begin(), s[now].end(), z) - s[now].begin() - 1;
					if (l <= r) {
						sum[now] ^= pre[now][r];
						if (l) sum[now] ^= pre[now][l - 1];
					}
				}
			}
			else if (x == 2) printf("%d", (cal(y) == cal(z)) ? 1 : 0); 
		}
		printf("\n");
		recover();
	}
	return 0;
}

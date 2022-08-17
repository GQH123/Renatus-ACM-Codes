#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define maxn 200020
#define maxs 600020
#define maxm 
#define M1 1000000007
#define B1 2333
#define M2 1926081347
#define B2 23333
#define ll long long int 
#define ld long double
#define pb push_back
#define pc putchar
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define lowbit(x) (x & -x)
using namespace std;

int n, m;
int ct = 0;
int ch[maxs][26];

struct ele{
	int l, h1, h2;
	ele(int l, int h1, int h2) : l(l), h1(h1), h2(h2){}
	ele(){}
	bool operator < (const ele b) const{
		return (l == b.l) ? ((h1 == b.h1) ? h2 < b.h2 : h1 < b.h1) : l < b.l;
	}
};
int ha1[maxn], ha2[maxn];
void play(int* ha, char* s, int l, int B, int M){
	int now = B; ha[l] = 0;
	per(i, l - 1, 0) {
		now = (1ll * now * B + s[i] - 'a') % M;
		ha[i] = now;
	}
}

vector<ele> val[maxs];
void add(char* s){
	int l = strlen(s), now = 0;
	play(ha1, s, l, B1, M1);
	play(ha2, s, l, B2, M2);
	val[0].pb(ele(l, ha1[0], ha2[0]));
	srep(i, 0, l) {
		if (!ch[now][s[i] - 'a']) ch[now][s[i] - 'a'] = ++ct;
		now = ch[now][s[i] - 'a'];
		if (i < l - 1) val[now].pb(ele(l - i - 1, ha1[i + 1], ha2[i + 1]));
	}
}
int tim;
int idfs[maxs], dfs[maxs], siz[maxs];
void DFS(int x){
	dfs[x] = ++tim;
	siz[x] = 1;
	idfs[tim] = x;
	rep(i, 0, 25) {
		if (!ch[x][i]) continue;
		DFS(ch[x][i]);
		siz[x] += siz[ch[x][i]];
	}
}
int walk(char* s){
	int now = 0, l = strlen(s);
	srep(i, 0, l) {
		if (!ch[now][s[i] - 'a']) return -1;
		now = ch[now][s[i] - 'a'];
	}
	return now;
}
vector<ele> c[maxs]; 
inline int cal(int x, ele v){
	return upper_bound(c[x].begin(), c[x].end(), v) - lower_bound(c[x].begin(), c[x].end(), v);
} 
void add(int x, ele v){
	while (x <= ct + 5){
		c[x].pb(v);
		x += lowbit(x);
	}
}
int get(int x, ele v){
	int ans = 0;
	while (x){
		ans += cal(x, v);
		x -= lowbit(x);
	}
	return ans;
}

/*
inline void pu(int o){
	int si = ss[o << 1].size();
	srep(i, 0, si) ss[o].pb(ss[o << 1][i]);
	si = ss[o << 1 | 1].size();
	srep(i, 0, si) ss[o].pb(ss[o << 1 | 1][i]);
}
void init(int l, int r, int o){
	int x = idfs[l], si = val[x].size();
	srep(i, 0, si) ss[o].pb(val[x][i]); 
	if (l == r) return;
	int mid = ((r - l) >> 1) + l;
	init(l, mid, o << 1), init(mid + 1, r, o << 1 | 1);
	pu(o); 
	sort(ss[o].begin(), ss[o].end());
}
inline int cal(int o){
	return upper_bound(ss[o].begin(), ss[o].end(), qd) - lower_bound(ss[o].begin(), ss[o].end(), qd);
}
int get(int l, int r, int o) {
	if (qx <= l && r <= qy) return cal(o); 
	int mid = ((r - l) >> 1) + l, ans = 0;
	if (qx <= mid) ans += get(l, mid, o << 1);
	if (qy > mid) ans += get(mid + 1, r, o << 1 | 1);
	return ans;
}
void recover(int l, int r, int o){
	ss[o].clear();
	if (l == r) return;
	int mid = ((r - l) >> 1) + l;
	recover(l, mid, o << 1), recover(mid + 1, r, o << 1 | 1); 
}
*/
void recover(){
	//recover(0, ct, 1);
	rep(i, 0, ct) val[i].clear();
	rep(i, 0, ct + 5) c[i].clear();
	rep(i, 0, ct) rep(j, 0, 25) ch[i][j] = 0;
	ct = tim = 0; 
}

char s[maxn];
int haa[maxn];

int main(){
	int T; scanf("%d", &T);
	while (T--){
		scanf("%d%d", &n, &m);
		rep(i, 1, n) scanf("%s", s), add(s);
		DFS(0);
		rep(i, 0, ct) {
			int si = val[i].size();
			srep(j, 0, si) add(dfs[i], val[i][j]); 
		}
		rep(i, 0, ct + 5) sort(c[i].begin(), c[i].end());
		//init(0, ct, 1); 
		rep(i, 1, m) {
			scanf("%s", s); 
			int x = walk(s);
			scanf("%s", s);
			if (x == -1) {
				printf("0\n");
				continue;
			}
			int l = strlen(s); ele v;
			play(haa, s, l, B1, M1); v.h1 = haa[0];
			play(haa, s, l, B2, M2); v.h2 = haa[0];
			v.l = l;
			printf("%d\n", get(dfs[x] + siz[x] - 1, v) - get(dfs[x] - 1, v));
			//qx = dfs[x], qy = dfs[x] + siz[x] - 1, qd = pii(l, haa[0]);
			//printf("%d\n", get(0, ct, 1));
		} 
		recover();
	} 
	return 0;
}

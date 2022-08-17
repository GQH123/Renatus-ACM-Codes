#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define ll long long int 
#define pb push_back
#define pc putchar
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn 1000020
#define maxm
#define maxs 1000020
#define maxb
#define M 
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}
int _num[20];
template <class T> void write(T x, char sep = '\n'){	
	if (!x) {putchar('0'), putchar(sep); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar(sep);
}

int go[maxs][26], ct = 0, val[maxs], pos[maxn], vv[maxn];
multiset<int> vic[maxs];
void insert(char* s, int l, int id) {
	int now = 0;
	srep(i, 0, l) {
		if (!go[now][s[i] - 'a']) go[now][s[i] - 'a'] = ++ct;
		now = go[now][s[i] - 'a'];
	}
	val[now] = id, pos[id] = now, vic[now].insert(0);
}
int bfs[maxs], f[maxs], last[maxn], head = 0, tail = 0;
void init(){
	f[0] = 0;
	rep(i, 0, 25) {
		int u = go[0][i];
		if (u) bfs[++head] = u, f[u] = 0;
	}
	while (head != tail){
		int x = bfs[++tail];
		rep(i, 0, 25) {
			int u = go[x][i];
			if (!u) go[x][i] = go[f[x]][i];
			else {
				int now = f[x];
				while (now && !go[now][i]) now = f[now];
				f[u] = go[now][i];
				last[u] = (val[f[u]]) ? f[u] : last[f[u]];
				bfs[++head] = u;
			}
		}
	}
}
int match(char* s, int l) {
	int now = 0, mx = -1; 
	srep(i, 0, l) {
		int _now = now;
		while (now) {
			if (val[now]) mx = max(mx, *vic[now].rbegin());
			now = f[now];
		} 
		now = go[_now][s[i] - 'a'];
	}
	while (now) {
		if (val[now]) mx = max(mx, *vic[now].rbegin());
		now = f[now];
	} 
	return mx;
}
int n, m; char s[maxn];
int main(){
	int l;
	scanf("%d%d", &n, &m);
	rep(i, 1, n) {
		scanf("%s", s);
		l = strlen(s);
		insert(s, l, i);
	}
	init();
	int op, x, y;
	rep(i, 1, m) {
		scanf("%d", &op);
		switch(op){
			case 1:
				scanf("%d%d", &x, &y); 
				vic[pos[x]].erase(vic[pos[x]].lower_bound(vv[x]));
				vv[x] = y; 
				vic[pos[x]].insert(y);
				break;
			case 2: 
				scanf("%s", s);
				l = strlen(s);
				write(match(s, l));
				break;
		}
	}
	return 0;
}


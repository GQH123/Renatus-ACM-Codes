#include <bits/stdc++.h>
#define maxr 100000
#define maxn 200150
#define maxa 1100000
#define ll long long int 
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define ms(a, b) memset(a, b, sizeof(a))
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> bool read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-' && ch != EOF) ch = gc();
	if (ch == '-') f = 0, ch = gc();
	else if (ch == EOF) return false;
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
	return true;
}
int n, m;
int a[maxn], pre[maxn], pos[maxn], _a[maxn], _pre[maxn];

struct query{
	int id, l, r, t;
	query(int id, int l, int r, int t) : id(id), l(l), r(r), t(t){}
	query(){}
	bool operator < (const query b) const{
		if (pos[l] == pos[b.l]) {
			if (pos[r] == pos[b.r]) return t < b.t;
			else return pos[r] < pos[b.r];
		}
		else return pos[l] < pos[b.l];
	}
}q[maxn];
int cq = 0;

struct modify{
	int p, o, v;
	modify(int p, int o, int v) : p(p), o(o), v(v){}
	modify(){}
}mod[maxn];
int cm = 0;

bool vis[maxn];
int s[maxa];
ll nowans = 0;
ll ans[maxn];
void update(int y){
	if (vis[y]){
		int x = pre[y];
		s[x]--;
		nowans -= s[x];
	}
	else {
		int x = pre[y];
		nowans += s[x];
		s[x]++;
	}
	vis[y] ^= 1;
}
void change(int idm, bool type, int l, int r){
	modify op = mod[idm];
	if (type){
		if (l <= op.p && op.p <= r) {
			int x = pre[op.p];
			s[x]--;
			nowans -= s[x];
			x = pre[op.p] = op.v;
			nowans += s[x];
			s[x]++;
		}
		else pre[op.p] = op.v;
	}
	else {
		if (l <= op.p && op.p <= r) {
			int x = pre[op.p];
			s[x]--;
			nowans -= s[x];
			x = pre[op.p] = op.o;
			nowans += s[x];
			s[x]++;
		}
		else pre[op.p] = op.o;
	}
}
inline void getans(int id, int l, int r){
	ans[id] = ((ll)(r - l + 1) * (r - l + 2) >> 1) - nowans;
}
void recover(){
	cq = cm = 0; nowans = 0;
	ms(vis, 0), ms(s, 0);
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("H.in", "r", stdin);
		freopen("H.out", "w", stdout);
	#endif
	while (read(n)){
		int bound = (int) 2.5 * pow(n, 2.0 / 3) + 1;
		rep(i, 1, n) pos[i] = (i - 1) / bound + 1;
		read(m);
		rep(i, 1, n) read(a[i]), pre[i] = pre[i - 1] ^ a[i], _a[i] = a[i], _pre[i] = pre[i];
		int x, y, z;
		rep(i, 1, m){
			read(x), read(y);
			if (x == 1) read(z), cq++, q[cq] = query(cq, y - 1, z, cm); //???
			else {
				int o = pre[y];
				swap(a[y], a[y + 1]), pre[y] = pre[y - 1] ^ a[y];
				mod[++cm] = modify(y, o, pre[y]);
			}
		}
		rep(i, 1, n) a[i] = _a[i], pre[i] = _pre[i];
		sort(q + 1, q + 1 + cq);
		int l = 0, r = -1, now = 0; //???
		rep(i, 1, cq){
			while (now < q[i].t) change(++now, 1, l, r);
			while (now > q[i].t) change(now--, 0, l, r);
			while (r < q[i].r) update(++r);
			while (l < q[i].l) update(l++);
			while (l > q[i].l) update(--l);
			while (r > q[i].r) update(r--);
			getans(q[i].id, q[i].l + 1, q[i].r);
		}
		rep(i, 1, cq) printf("%lld\n", ans[i]);
		recover();
	}
	return 0;
}

#include <bits/stdc++.h>
#define maxr 100000
#define maxn 500019
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define pii pair<int, int> 
#define fi first
#define se second
#define pb push_back
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}

struct road{
	int x, y, l, r;
	road(int x, int y, int l, int r) : x(x), y(y), l(l), r(r){}
	road(){}
}q[maxn];
int lis[maxn << 1], cs = 0;
int num[maxn << 1];

int n, m;
int ufs[maxn], sz[maxn];
int find_root(int x){
	return (ufs[x] == x) ? x : find_root(ufs[x]);
}

int qx, qy;
pii qd;
vector<pii> tag[maxn << 1];
void puttag(int l, int r, int o){
	if (qx <= l && r <= qy){
		tag[o].pb(qd);
		return;
	}
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) puttag(l, mid, o << 1);
	if (qy > mid) puttag(mid + 1, r, o << 1 | 1);
}

pii sta[maxn];
int head = 0;
void addtag(int o){
	int ss = tag[o].size(), x, y;
	srep(i, 0, ss){
		x = find_root(tag[o][i].fi), y = find_root(tag[o][i].se);
		if (x == y) continue;
		else {
			if (sz[x] > sz[y]) swap(x, y);
			ufs[x] = ufs[y];
			sz[y] += sz[x];
			sta[++head] = pii(x, y);
		}
	}
}
void recover(int now){	
	int x, y;
	while (head > now){
		x = sta[head].fi, y = sta[head].se; head--;
		ufs[x] = x;
		sz[y] -= sz[x];
	}
}
int cal(int l){
	int x = find_root(1), y = find_root(n);
	return (x == y) ? num[l] : 0;
}
int ans = 0;
void solve(int l, int r, int o){
	int now = head;
	addtag(o);
	if (l == r){
		ans += cal(l);
		recover(now);
		return;
	}
	int mid = ((r - l) >> 1) + l;
	solve(l, mid, o << 1);
	solve(mid + 1, r, o << 1 | 1);
	recover(now);
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("E.in", "r", stdin);
	#endif
	read(n), read(m);
	rep(i, 1, m){
		read(q[i].x), read(q[i].y), read(q[i].l), read(q[i].r), q[i].r++;
		lis[++cs] = q[i].l, lis[++cs] = q[i].r;
	}
	sort(lis + 1, lis + 1 + cs);
	rep(i, 1, m) q[i].l = lower_bound(lis + 1, lis + 1 + cs, q[i].l) - lis, q[i].r = lower_bound(lis + 1, lis + 1 + cs, q[i].r) - lis - 1;
	rep(i, 1, cs - 1) num[i] = lis[i + 1] - lis[i];
	num[cs] = 0;
	rep(i, 1, m){
		qx = q[i].l, qy = q[i].r, qd = pii(q[i].x, q[i].y);
		puttag(1, cs, 1);
	}
	rep(i, 1, n) ufs[i] = i, sz[i] = 1;
	solve(1, cs, 1);
	//assert(!head);
	printf("%d", ans);
	return 0;
}

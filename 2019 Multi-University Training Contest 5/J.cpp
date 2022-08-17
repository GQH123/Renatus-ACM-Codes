#include <bits/stdc++.h>
#define maxr 100000
#define maxn 150019
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

const int inf = 1000000000;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}

int qx, qy, qd;
int miv[maxn << 1];
set<int> num[maxn << 1];
inline void pu(int o){
	miv[o] = min(miv[o << 1], miv[o << 1 | 1]);
}
void init(int l, int r, int o){
	if (l == r){
		num[o].clear();
		miv[o] = inf;
		return;
	}
	int mid = ((r - l) >> 1) + l;
	init(l, mid, o << 1), init(mid + 1, r, o << 1 | 1);
	pu(o);
}
void insert(int l, int r, int o){ //由大到小进行
	if (l == r){
		num[o].insert(qd);
		miv[o] = *num[o].begin();
		return;
	}
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) insert(l, mid, o << 1);
	else insert(mid + 1, r, o << 1 | 1);
	pu(o);
}
int get(int l, int r, int o){
	if (qx <= l && r <= qy) return miv[o];
	int mid = ((r - l) >> 1) + l, ans = inf;
	if (qx <= mid) ans = min(ans, get(l, mid, o << 1));
	if (qy > mid) ans = min(ans, get(mid + 1, r, o << 1 | 1));
	return ans;
}
void del(int l, int r, int o){
	if (l == r){	
		num[o].erase(num[o].begin());
		miv[o] = (num[o].empty()) ? inf : *num[o].begin();
		return;
	}
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) del(l, mid, o << 1);
	else del(mid + 1, r, o << 1 | 1);
	pu(o);
}

int mi[maxn << 1];
int add[maxn << 1];
void pu2(int o){
	mi[o] = min(mi[o << 1], mi[o << 1 | 1]);
}
void pd(int o){
	if (add[o]){
		int& k = add[o];
		add[o << 1] += k, mi[o << 1] += k;
		add[o << 1 | 1] += k, mi[o << 1 | 1] += k;
		k = 0;
	}
}
void init2(int l, int r, int o){
	add[o] = 0;
	if (l == r) {mi[o] = l; return;}
	int mid = ((r - l) >> 1) + l;
	init2(l, mid, o << 1), init2(mid + 1, r, o << 1 | 1);
	pu2(o);
}
void Add(int l, int r, int o){
	if (l < r) pd(o);
	if (qx <= l && r <= qy){
		add[o] += qd, mi[o] += qd;
		return;
	}
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) Add(l, mid, o << 1);
	if (qy > mid) Add(mid + 1, r, o << 1 | 1);
	pu2(o);
}
pii getminp(int l, int r, int o){
	if (l < r) pd(o);
	if (l == r) return pii(l, mi[o]);
	int mid = ((r - l) >> 1) + l;
	if (mi[o << 1] <= mi[o << 1 | 1]) return getminp(l, mid, o << 1);
	else return getminp(mid + 1, r, o << 1 | 1);
}
void mod(int l, int r, int o){
	if (l < r) pd(o);
	if (l == r) {mi[o] = inf; return;}
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) mod(l, mid, o << 1);
	else mod(mid + 1, r, o << 1 | 1);
	pu2(o);
}
	
struct ele{
	int l, r, x;
	ele(int l, int r, int x) : l(l), r(r), x(x){}
	ele(){}
	bool operator <  (const ele b) const{
		return (l == b.l) ? r < b.r : l < b.l;
	}
}lis[maxn];
int ptr;
int n;
int a[maxn];
bool vis[maxn];
int deq1[maxn], deq2[maxn];
int head1, head2;
int ans[maxn], l[maxn], r[maxn];
bool cmp(int i, int j){
	return i > j;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("J.in", "r", stdin);
	#endif
	int T;
	read(T);
	while (T--){
		read(n);
		rep(i, 1, 2 * n) vis[i] = 0;
		rep(i, 1, n) read(a[i]), vis[abs(a[i])] = 1;
		head1 = 0, head2 = 0;
		rep(i, 1, n){	
			if (a[i] > 0) {
				r[a[i]] = n + i - 1;
				while (head1 && deq1[head1] > a[i]) head1--;
				if (head1) l[a[i]] = r[deq1[head1]] + 1;
				else l[a[i]] = 1;
				deq1[++head1] = a[i];
				l[a[i]] = max(l[a[i]], r[deq2[lower_bound(deq2 + 1, deq2 + 1 + head2, a[i], cmp) - deq2 - 1]] + 1);
			}
			else {
				a[i] = -a[i];
				r[a[i]] = n + i - 1;
				while (head2 && deq2[head2] < a[i]) head2--;
				if (head2) l[a[i]] = r[deq2[head2]] + 1;
				else l[a[i]] = 1;
				deq2[++head2] = a[i];
				l[a[i]] = max(l[a[i]], r[deq1[lower_bound(deq1 + 1, deq1 + 1 + head1, a[i]) - deq1 - 1]] + 1);
			}
		}
		rep(i, 1, 2 * n){
			if (!vis[i]) {
				r[i] = 2 * n;
				l[i] = max(r[deq1[lower_bound(deq1 + 1, deq1 + 1 + head1, i) - deq1 - 1]] + 1, r[deq2[lower_bound(deq2 + 1, deq2 + 1 + head2, i, cmp) - deq2 - 1]] + 1);
			}
		}
		/*rep(i, 1, n){
			if (a[i] > 0){
				//if (a[i] < n) {printf("-1\n"); goto jump;}
				r[a[i]] = n + i - 1;
				while (head && deq[head] > a[i]) head--;
				if (head) l[a[i]] = r[deq[head]] + 1;
				else l[a[i]] = 1;
				deq[++head] = a[i];
			}
		}
		per(i, 2 * n, 1){
			if (!vis[i]){
				int x = i;
				r[x] = 2 * n;
				while (head && deq[head] > x) head--;
				if (head) l[x] = r[deq[head]] + 1;
				else l[x] = 1;
			}
		}
		head = 0;
		rep(i, 1, n){
			if (a[i] < 0) {
				//if (-a[i] > n + 1) {printf("-1\n"); goto jump;}
				a[i] = -a[i];
				r[a[i]] = n + i - 1;
				while (head && deq[head] < a[i]) head--;
				if (head) l[a[i]] = r[deq[head]] + 1;
				else l[a[i]] = 1;
				deq[++head] = a[i];
			}
		}
		rep(i, 1, 2 * n){
			if (!vis[i]){
				int x = i;
				r[x] = 2 * n;
				while (head && deq[head] < x) head--;
				if (head) l[x] = max(l[x], r[deq[head]] + 1);
				else l[x] = max(l[x], 1);
			}
		}*/
		n <<= 1;
		init(1, n, 1);
		/*per(i, n, 1){
			qx = r[i], qd = i;
			insert(1, n, 1);
		}*/
		rep(i, 1, n) lis[i] = ele(l[i], r[i], i);
		sort(lis + 1, lis + 1 + n);
		
		init2(1, n, 1), qy = n;
		rep(i, 1, n){
			qx = r[i], qd = -1;
			Add(1, n, 1);
		}
		
		ptr = 1;
		rep(p, 1, n){
			while (ptr <= n && lis[ptr].l == p){
				qx = lis[ptr].r, qd = lis[ptr].x;
				insert(1, n, 1);
				ptr++;
			}
			pii k = getminp(1, n, 1);
			if (k.se < 0) {
				printf("-1\n");
				goto jump;
			}
			qx = p, qy = (k.se) ? n : k.fi, qd = get(1, n, 1);
			if (qd > n) {
				printf("-1\n");
				goto jump;
			}
			qx = r[qd], del(1, n, 1);
			ans[p] = qd;
			qx = p, qy = r[qd] - 1, qd = -1;
			if (qx <= qy) Add(1, n, 1);
			qx = p, mod(1, n, 1);
		}
		
		printf("%d", ans[1]); rep(p, 2, n) printf(" %d", ans[p]); printf("\n");
		jump:;
	}
	return 0;
}

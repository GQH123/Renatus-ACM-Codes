#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 50020
#define maxm 
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define pc putchar
#define ll long long int 
#define ld long double 
#define lowbit(x) (x & -x)
#define M 
#define mo(x) (x = (x >= M) ? (x - M) : x)
using namespace std;

int lis[maxn << 2], cs = 0, a[maxn], la[maxn], ra[maxn], pos[maxn];
int n, m, k, bsiz;

int c[maxn << 2];
void add(int x, int v){
	while (x){
		c[x] += v;
		x -= lowbit(x);
	}
}
int get(int x){
	int ans = 0;
	while (x <= cs){
		ans += c[x];
		x += lowbit(x);
	}
	return ans;
}

ll res[maxn];
struct que{
	int l, r, id;
	que(int l, int r, int id): l(l), r(r), id(id){}
	que(){}
	bool operator < (const que b) const{
		return (pos[l] == pos[b.l]) ? r < b.r : pos[l] < pos[b.l];
	}
}q[maxn];

ll ans = 0;
bool vis[maxn];
void upd(int x){	
	if (vis[x]) {	
		int d = get(la[x]) - get(ra[x] + 1) - 1;
		ans -= d;
		add(a[x], -1);
	}
	else {
		int d = get(la[x]) - get(ra[x] + 1);
		ans += d;
		add(a[x], 1);
	}
	vis[x] ^= 1;
}

void recover(){
	rep(i, 1, n) vis[i] = 0;
	rep(i, 1, cs) c[i] = 0;
	ans = cs = 0;
}

int main(){
	while (scanf("%d%d%d", &n, &m, &k) == 3){
		bsiz = (int) sqrt(n) + 2;
		rep(i, 1, n) pos[i] = (i - 1) / bsiz + 1;
		rep(i, 1, n) scanf("%d", a + i), lis[++cs] = a[i], lis[++cs] = a[i] - k, lis[++cs] = a[i] + k;
		sort(lis + 1, lis + 1 + cs);
		cs = unique(lis + 1, lis + 1 + cs) - lis - 1;
		rep(i, 1, n) {
			la[i] = lower_bound(lis + 1, lis + 1 + cs, a[i] - k) - lis;
			ra[i] = lower_bound(lis + 1, lis + 1 + cs, a[i] + k) - lis;
			a[i] = lower_bound(lis + 1, lis + 1 + cs, a[i]) - lis;
		}
		rep(i, 1, m) scanf("%d%d", &q[i].l, &q[i].r), q[i].id = i;
		sort(q + 1, q + 1 + m);
		int l = 1, r = 0;
		rep(i, 1, m){
			while (r < q[i].r) upd(++r);
			while (l > q[i].l) upd(--l);
			while (r > q[i].r) upd(r--);
			while (l < q[i].l) upd(l++);
			res[q[i].id] = ans;
		}
		rep(i, 1, m) printf("%lld\n", res[i]);
		recover();
	}
	return 0;
}

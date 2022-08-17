#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define maxn 400020
#define ll long long int 
#define pb push_back
#define lowbit(x) (x & -x)
using namespace std;

int n, m, a[maxn], lis[maxn], cs = 0;
int tab[maxn], ct = 0;
vector<int> pos[maxn];

ll c[maxn];
void add(int x, int v){
	while (x <= n) c[x] += v, x += lowbit(x); 
}
ll get(int x){
	ll ans = 0;
	while (x) ans += c[x], x -= lowbit(x); 
	return ans;
}

struct query{
	int x, y, id;
	query(int x, int y, int id) : x(x), y(y), id(id){}
	query(){}
	bool operator < (const query b) const{
		return (y == b.y) ? (x < b.x) : y < b.y;
	}
}q[maxn];

ll out[maxn];
int bound;
void upd(int x){
	if (pos[a[x]].size() >= bound) return; 	
	int p = lower_bound(pos[a[x]].begin(), pos[a[x]].end(), x) - pos[a[x]].begin();
	add(x, lis[a[x]]); 
	//注意要把离散值映射回原始值
	per(i, p - 1, 0) add(pos[a[x]][i], lis[a[x]] << 1); 
	//注意要把离散值映射回原始值
}
ll ask(int l, int r){
	ll ans = 0;
	rep(i, 1, ct){
		int x = tab[i];
		int t = upper_bound(pos[x].begin(), pos[x].end(), r) - lower_bound(pos[x].begin(), pos[x].end(), l);
		ans += (ll)t * t * lis[x];
		//注意要把离散值映射回原始值
	}
	return ans += get(r) - get(l - 1);
}

int main(){
	
		freopen("A.in", "r", stdin);
		
	ios :: sync_with_stdio(false), cin.tie(0);
	
	int x, y;
	cin >> n >> m;
	rep(i, 1, n) cin >> a[i], lis[++cs] = a[i];
	sort(lis + 1, lis + 1 + cs);
	cs = unique(lis + 1, lis + 1 + cs) - lis - 1;
	rep(i, 1, n) a[i] = lower_bound(lis + 1, lis + 1 + cs, a[i]) - lis, pos[a[i]].pb(i);
	bound = (int) sqrt(n) + 2;
	rep(i, 1, cs) if (pos[i].size() >= bound) tab[++ct] = i; 
	rep(i, 1, m) cin >> x >> y, q[i] = query(x, y, i);
	sort(q + 1, q + 1 + m);
	int last = 0;
	rep(i, 1, m){
		int now = q[i].y;
		while (last < now) upd(++last);
		out[q[i].id] = ask(q[i].x, q[i].y);	
		
	}
	rep(i, 1, m) cout << out[i] << endl;
	return 0; 
}

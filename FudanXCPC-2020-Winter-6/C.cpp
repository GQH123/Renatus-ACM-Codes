#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 300020
#define maxb 20
#define ll long long int 
using namespace std;

const int inf = 2000000020;

int n, q, L, U;
int a[maxn];
int nex[maxn << 1][maxb];

ll pre[maxn], mi[maxn << 1], mx[maxn << 1];
int qx, qy;
inline void pu(int o){
	mx[o] = max(mx[o << 1], mx[o << 1 | 1]), mi[o] = min(mi[o << 1], mi[o << 1 | 1]);
}
void init(int l, int r, int o){
	if (l == r) {mi[o] = mx[o] = pre[l]; return;}
	int mid = ((r - l) >> 1) + l;
	init(l, mid, o << 1), init(mid + 1, r, o << 1 | 1);
	pu(o);
}
ll get_mi(int l, int r, int o){
	if (qx <= l && r <= qy) return mi[o];
	int mid = ((r - l) >> 1) + l;
	ll ans; bool f = 0;
	if (qx <= mid) {
		ll _ans = get_mi(l, mid, o << 1);
		if (!f) ans = _ans, f = 1;
		else ans = min(ans, _ans);
	}
	if (qy > mid) {
		ll _ans = get_mi(mid + 1, r, o << 1 | 1);
		if (!f) ans = _ans, f = 1;
		else ans = min(ans, _ans);
	}
	return ans;
}
ll get_mx(int l, int r, int o){
	if (qx <= l && r <= qy) return mx[o];
	int mid = ((r - l) >> 1) + l;
	ll ans; bool f = 0;
	if (qx <= mid) {
		ll _ans = get_mx(l, mid, o << 1);
		if (!f) ans = _ans, f = 1;
		else ans = max(ans, _ans);
	}
	if (qy > mid) {
		ll _ans = get_mx(mid + 1, r, o << 1 | 1);
		if (!f) ans = _ans, f = 1;
		else ans = max(ans, _ans);
	}
	return ans;
}
inline bool judge(int x, int p, int mid){ 
	qx = p + 1, qy = mid;
	return (x + get_mx(1, n, 1) - pre[p] >= U) || (x + get_mi(1, n, 1) - pre[p] <= L);
}
int find_(int x, int p, int l, int r){
	while (l < r){
		int mid = ((r - l) >> 1) + l;
		if (judge(x, p, mid)) r = mid;
		else l = mid + 1;
	}
	return l;
}
void init(){
	pre[0] = 0;
	rep(i, 1, n) pre[i] = pre[i - 1] + a[i];
	init(1, n, 1);
	per(i, n, 1){
		int ne = find_(U, i, i + 1, n + 1);
		if (ne == n + 1) ne = 0;
		qx = i + 1, qy = ne;
		if (ne != 0) ne = ((U + get_mx(1, n, 1) - pre[i] >= U) ? ne : (ne + n));
		nex[i][0] = ne;
		
		ne = find_(L, i, i + 1, n + 1);
		if (ne == n + 1) ne = 0;
		qx = i + 1, qy = ne;
		if (ne != 0) ne = ((L + get_mx(1, n, 1) - pre[i] >= U) ? ne : (ne + n));
		nex[n + i][0] = ne;
	} 
	srep(i, 1, maxb) rep(j, 1, 2 * n) nex[j][i] = nex[nex[j][i - 1]][i - 1]; 
}
int query(int x, int y, int z){
	int _x = find_(z, x - 1, x, n + 1);
	if (_x > y) return z + pre[y] - pre[x - 1];
	//if (_x > y) {if (n != 5) printf("A"); return z + pre[y] - pre[x - 1];}
	qx = x, qy = _x;
	_x = ((z + get_mx(1, n, 1) - pre[x - 1] >= U) ? _x : (_x + n));
	per(i, maxb - 1, 0) {
		int ne = nex[_x][i];
		if (ne != 0 && ne > n) ne -= n;
		if (!ne || ne > y) continue;
		_x = nex[_x][i];
	}
	if (_x > n) return L + pre[y] - pre[_x - n];
	else return U + pre[y] - pre[_x];
	//if (_x > n) {if (n != 5) printf("B"); return L + pre[y] - pre[_x - n];}
	//else {if (n != 5) printf("C"); return U + pre[y] - pre[_x];}
}
int main(){

		freopen("C.in", "r", stdin);
	
	int x, y, z;
	scanf("%d%d%d", &n, &L, &U);
	rep(i, 1, n) scanf("%d", &a[i]);
	init();
	scanf("%d", &q);
	rep(i, 1, q){
		scanf("%d%d%d", &x, &y, &z);
		printf("%d\n", query(x, y, z));
	}
	return 0;
}


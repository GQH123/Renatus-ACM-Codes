#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 200020
using namespace std;


int n, q;
double p[maxn];

double prod[maxn << 2];
int qx, qy; double qd;
void pu(int o){
	prod[o] = prod[o << 1] * prod[o << 1 | 1];
}
void init(int l, int r, int o){
	if (l == r) {prod[o] = p[l] / (1 - p[l - 1] * (1 - p[l])); return;}
	int mid = ((r - l) >> 1) + l;
	init(l, mid, o << 1), init(mid + 1, r, o << 1 | 1);
	pu(o);
}
void mod(int l, int r, int o){
	if (l == r){
		prod[o] = qd;
		return;
	}
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) mod(l, mid, o << 1);
	else mod(mid + 1, r, o << 1 | 1);
	pu(o);
}
double get(int l, int r, int o){
	if (qx <= l && r <= qy) return prod[o];
	int mid = ((r - l) >> 1) + l; double ans = 1.0;
	if (qx <= mid) ans *= get(l, mid, o << 1);
	if (qy > mid) ans *= get(mid + 1, r, o << 1 | 1);
	return ans;
}

int main(){
	
		freopen("K.in", "r", stdin);
	
	int op, x, y, z;
	scanf("%d%d", &n, &q);
	rep(i, 1, n) scanf("%d%d", &x, &y), p[i] = 1.0 * x / y;
	init(1, n, 1);
	rep(i, 1, q){
		scanf("%d", &op);
		if (op == 1){
			scanf("%d%d%d", &x, &y, &z);
			p[x] = 1.0 * y / z;
			qx = x, qd = p[qx] / (1 - p[qx - 1] * (1 - p[qx]));
			mod(1, n, 1);
			if (x < n){
				qx = x + 1, qd = p[qx] / (1 - p[qx - 1] * (1 - p[qx]));
				mod(1, n, 1);
			}
		}
		else {
			scanf("%d%d", &qx, &qy);
			qx++; double ans = 1.0;
			if (qx <= qy) ans = get(1, n, 1);
			printf("%.10lf\n", ans * p[qx - 1]);
		}
	}
	return 0;
}

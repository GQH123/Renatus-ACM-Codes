#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 300020
#define ll long long int 
using namespace std;

int n, P, X1, Y1, X2, Y2;
ll S;

struct seg{
	int x1, y1, x2, y2;
	seg(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2){}
	seg(){}
}se[maxn];

struct event{
	int x, l, r, v;
	event(int x, int l, int r, int v) : x(x), l(l), r(r), v(v){}
	event(){}
	bool operator < (const event b) const{
		return (x == b.x) ? v > b.v : x < b.x;
	}
}p[maxn << 1];
int cp = 0;

int mi[maxn << 1];
int num[maxn << 1];
int add[maxn << 1];
int qx, qy, qd;

inline void pu(int o){
	if (mi[o << 1] < mi[o << 1 | 1]) mi[o] = mi[o << 1], num[o] = num[o << 1];
	else if (mi[o << 1] > mi[o << 1 | 1]) mi[o] = mi[o << 1 | 1], num[o] = num[o << 1 | 1];
	else mi[o] = mi[o << 1], num[o] = num[o << 1] + num[o << 1 | 1];
}
inline void pd(int l, int r, int o){
	if (add[o] && (l < r)){
		int& k = add[o];
		add[o << 1] += k, add[o << 1 | 1] += k;
		mi[o << 1] += k, mi[o << 1 | 1] += k;
		k = 0;
	}
}
void Add(int l, int r, int o){
	pd(l, r, o);
	if (qx <= l && r <= qy){
		add[o] += qd, mi[o] += qd;
		return;
	}
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) Add(l, mid, o << 1);
	if (qy > mid) Add(mid + 1, r, o << 1 | 1);
	pu(o);
}
int get(int l, int r, int o){
	pd(l, r, o);
	if (qx <= l && r <= qy){
		if (mi[o]) return r - l + 1;
		return r - l + 1 - num[o];
	}
	int mid = ((r - l) >> 1) + l, ans = 0;
	if (qx <= mid) ans += get(l, mid, o << 1);
	if (qy > mid) ans += get(mid + 1, r, o << 1 | 1);
	return ans;
}
void init(int l, int r, int o){	
	add[o] = mi[o] = 0;
	if (l == r) {num[o] = 1; return;}
	int mid = ((r - l) >> 1) + l;
	init(l, mid, o << 1), init(mid + 1, r, o << 1 | 1);
	pu(o);
}

bool judge(int r){
	rep(i, 1, n){
		p[(i - 1) << 1 | 1] = event(se[i].x1 - r, se[i].y1 - r, se[i].y2 + r, 1);
		p[i << 1] = event(se[i].x2 + r, se[i].y1 - r, se[i].y2 + r, -1);  
	}
	int _n = n << 1;
	sort(p + 1, p + 1 + _n);
	int last = p[1].x;
	ll ans = 0;
	rep(i, 1, _n){	
		int nowx = p[i].x;
		if (nowx - 1 >= X1 && last < X2) {
			qx = Y1, qy = Y2 - 1;
			ans += ((ll)min(nowx - 1, X2 - 1) - max(X1, last) + 1) * get(0, Y2, 1);
		}
		last = nowx;
		while (i <= _n && p[i].x == nowx){
			qx = p[i].l, qy = p[i].r - 1, qd = p[i].v;
			if (qx <= qy) Add(0, Y2, 1);
			i++;
		}
		i--;
	}
	//printf("%d %d\n\n", num[1], mi[1]);
	assert(num[1] == Y2 + 1);
	return 100 * ans >= S * P;
}
int solve(int l, int r){
	if (l == r) return l;
	int mid = ((r - l) >> 1) + l;
	if (judge(mid)) return solve(l, mid);
	else return solve(mid + 1, r);
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("F.in", "r", stdin);
	#endif
	scanf("%d", &n);
	rep(i, 1, n) {
		scanf("%d%d%d%d", &se[i].x1, &se[i].y1, &se[i].x2, &se[i].y2);
		if (se[i].x1 == se[i].x2) {
			if (se[i].y1 > se[i].y2) swap(se[i].y1, se[i].y2);
		}
		else {
			if (se[i].x1 > se[i].x2) swap(se[i].x1, se[i].x2);
		}
	}
	scanf("%d", &P);
	scanf("%d%d%d%d", &X1, &Y1, &X2, &Y2);
	init(0, Y2, 1);
	assert(num[1] == Y2 + 1);
	S = ((ll)Y2 - Y1) * (X2 - X1);
	printf("%d", solve(1, 1000000));
	return 0;
}

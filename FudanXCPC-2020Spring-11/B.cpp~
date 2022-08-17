#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 1020
using namespace std;


struct point{
	int x, y, v, id;
	point(){}
	point(int x, int y, int v) : x(x), y(y), v(v){}
	bool operator < (const point b) const{
		return (v != b.v) ? v < b.v : ((x != b.x) ? x < b.x : y < b.y);
	}
}p[maxn], _p[maxn];


int n;


namespace CAL{ 
	point pivot;
	int sig(int x) {
		if (!x) return 0;
		return x > 0 ? 1 : -1;
	}
	int cross(point a, point b, point c){	
		return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
	}
	int distsqr(point a, point b){
		return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
	}
	bool cmp(point a, point b){
		int t = cross(pivot, a, b);
		return sig(t) == 1 || sig(t) == 0 && sig(distsqr(pivot, a) - distsqr(pivot, b)) == -1;
	}
	int n, m, t;
	point p[maxn], pp[maxn], stck[maxn];
	void get_convex(){
		if (!n) return;
		int i, k, top;
		srep(i, 0, n) pp[i] = p[i];
		for (k = 0, i = 1; i < n; i++) if (pp[i].y < pp[k].y || (pp[i].y == pp[k].y && pp[i].x < pp[k].x)) k = i;
		pivot = pp[k]; pp[k] = pp[0]; pp[0] = pivot;
		sort(pp + 1, pp + n, cmp);
		stck[0] = pp[0]; stck[1] = pp[1];
		for (top = 1, i = 2; i < n; i++){
			while (top && sig(cross(pp[i], stck[top], stck[top - 1])) > 0) --top;
			stck[++top] = pp[i];
		}
		m = top + 1;
	}
	void recover(){	
		n = m = t = 0;
	}
}

int ans[maxn];

int main(){ 
	int T = 1;
	while (scanf("%d", &n), n){ 
		printf("Case #%d: ", T);
		T++;
		rep(i, 1, n) ans[i] = 0; 
		rep(i, 1, n) scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].v), p[i].id = i;  
		sort(p + 1, p + 1 + n);
		int m = 0, _m = 0;
		per(i, n, 1){
			int nowv = p[i].v;
			if (!nowv) break;
			while (i >= 1 && p[i].v == nowv){
				CAL :: p[m++] = p[i]; 
				i--;
			}  
			srep(i, 0, m) {
				point nowp = CAL :: p[i];
				int ct = 0;
				while (i < m && nowp.x == CAL :: p[i].x && nowp.y == CAL :: p[i].y){
					i++, ct++;
				}
				i--;
				if (ct == 1) CAL :: p[_m++] = nowp; 
			}
			break;
		}
		CAL :: n = _m;
		CAL :: get_convex();
		srep(i, 0, CAL :: m) ans[CAL :: stck[i].id] = 1;
		rep(i, 1, n) printf("%d", ans[i]); printf("\n");
		CAL :: recover();
	}  
	return 0;
}

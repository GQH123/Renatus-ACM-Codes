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
    point operator - (const point b) const{
        point ret;
        ret.x = x - b.x, ret.y = y - b.y;
        return ret;
    }
}p[maxn], pp[maxn], stck[maxn];

int cross(point x, point y) {
    return x.x * y.y - x.y * y.x;
}

int comp(point x, point y) {
    if(x.x == y.x)  return x.y < y.y;
    return x.x < y.x;
}

int n, m, tot, ans[maxn];

void get_convex(){
	if (!tot) return;
    if(tot <= 2) {
        for(int i = 1; i <= tot; ++i)
            if (p[i].id > 0) ans[p[i].id] = 1;
        return;
    }
	int top = 0;
    stck[++top] = p[1], stck[++top] = p[2];
    for(int i = 3; i <= tot; ++i) {
        while(top > 1 && cross(p[i] - stck[top], stck[top] - stck[top - 1]) < 0) --top;
        stck[++top] = p[i];
    }
    for(int i = 1; i <= top; ++i)
        if (stck[i].id > 0) ans[stck[i].id] = 1;

    top = 0;
    reverse(p + 1, p + 1 + tot);
    stck[++top] = p[1], stck[++top] = p[2];
    for(int i = 3; i <= tot; ++i) {
        while(top > 1 && cross(p[i] - stck[top], stck[top] - stck[top - 1]) < 0) --top;
        stck[++top] = p[i];
    }
    for(int i = 1; i <= top; ++i)
        if (stck[i].id > 0)ans[stck[i].id] = 1;
}


int main(){ 
    //freopen("a.txt", "r", stdin);
	int T = 1;
	while (scanf("%d", &n), n){ 
		printf("Case #%d: ", T);
		T++;
		rep(i, 1, n) ans[i] = 0; 
		rep(i, 1, n) scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].v), p[i].id = i;  
		sort(p + 1, p + 1 + n);
		m = 0, tot = 0;
		per(i, n, 1){
			int nowv = p[i].v;
			if (!nowv) break;
			while (i >= 1 && p[i].v == nowv){
				pp[m++] = p[i];                 
				i--;
			}  
			for(int i = 0; i < m; ++i) {
				point nowp = pp[i];
				int ct = 0;
				while (i < m && nowp.x == pp[i].x && nowp.y == pp[i].y){
					i++, ct++;
				}
                i--;
				if (ct == 1) p[++tot] = nowp;
				else {
					p[++tot] = nowp;
					p[tot].id = -p[tot].id;
				} 
			}
			break;
		}
		get_convex();
		rep(i, 1, n) printf("%d", ans[i]); printf("\n");
	}  
	return 0;
}

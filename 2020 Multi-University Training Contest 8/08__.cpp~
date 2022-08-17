#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define pii pair<int, int>
#define fi first
#define se second
#define maxn 1020
using namespace std;

int r;
int dir[6][2] = {{0, 1}, {1, 1}, {1, 0}, {0, -1}, {-1, -1}, {-1, 0}};
//set<pii> id;
bool id[maxn * 3][maxn * 3];

inline int dist(int x, int y){
    if (x >= 0 && y >= 0) return max(abs(x), abs(y));
    if (x <= 0 && y >= 0) return abs(x) + abs(y);
    if (x >= 0 && y <= 0) return abs(x) + abs(y);
    if (x <= 0 && y <= 0) return max(abs(x), abs(y)); 
    assert(false);
}
inline bool ok(int x, int y){
    return (dist(x, y) < r && !id[x + maxn][y + maxn]);
}
inline bool is_up(int x, int y){
    return (dist(x, y) & 1) ^ (r & 1);
}
inline int getdeg(int x, int y){
	int sum = 0;
	rep(i, 0, 5) {
		int _x = x + dir[i % 6][0], _y = y + dir[i % 6][1];
		if (id[_x + maxn][_y + maxn]) sum++;
	}
	return sum;
}
 
pii sta[maxn * maxn * 4];
int cs = 0, ct = 0;
void dfs(int x, int y, int di, int shit = 0){ 
    while (1){
        id[x + maxn][y + maxn] = 1;
        sta[++cs] = pii(x, y);
        ct++;
        if (di != -1) printf("%d", di + 1); 
        if (is_up(x, y)){
        	if (!(r & 1)) shit = 1;
            int d = dist(x, y);
            if (!shit){
            	rep(i, di + 1, di + 5){
		            if (i == di) continue;
		            int _x = x + dir[i % 6][0], _y = y + dir[i % 6][1];
		            if (ok(_x, _y) && dist(_x, _y) == d) {x = _x, y = _y, di = i % 6, shit = 1; goto ok;}
		        }
            }  
            shit = 0;
            
            int mx = -1, mxx = -1, mxy = -1, mxdi = -1;
            rep(i, di + 1, di + 5){
                if (i == di) continue;
                int _x = x + dir[i % 6][0], _y = y + dir[i % 6][1];
                if (ok(_x, _y) && dist(_x, _y) < d) {
                	int dd = getdeg(_x, _y);
                	if (dd > mx) mx = dd, mxx = _x, mxy = _y, mxdi = i % 6;
                	//x = _x, y = _y, di = i % 6; goto ok;
                }
            } 
            if (mx != -1){
            	x = mxx, y = mxy, di = mxdi; goto ok;
            }
            rep(i, di + 1, di + 5){
	            if (i == di) continue;
	            int _x = x + dir[i % 6][0], _y = y + dir[i % 6][1];
	            if (ok(_x, _y) && dist(_x, _y) == d) {x = _x, y = _y, di = i % 6, shit = 1; goto ok;}
	        }
            rep(i, 0, 5){
                if (i == di % 6) continue;
                int _x = x + dir[i % 6][0], _y = y + dir[i % 6][1];
                if (ok(_x, _y) && dist(_x, _y) > d) {x = _x, y = _y, di = i % 6; goto ok;}
            }
            if (di != -1){
                rep(i, di, di){ 
                    int _x = x + dir[i % 6][0], _y = y + dir[i % 6][1];
                    if (ok(_x, _y)) {x = _x, y = _y, di = i % 6; goto ok;}
                }
            } 
        }
        else {
            int d = dist(x, y);
            rep(i, di + 1, di + 5){
                if (i == di) continue;
                int _x = x + dir[i % 6][0], _y = y + dir[i % 6][1];
                if (ok(_x, _y) && dist(_x, _y) > d) {x = _x, y = _y, di = i % 6; goto ok;}
            }
            rep(i, di + 1, di + 5){
                if (i == di) continue;
                int _x = x + dir[i % 6][0], _y = y + dir[i % 6][1];
                if (ok(_x, _y) && dist(_x, _y) == d) {x = _x, y = _y, di = i % 6; goto ok;}
            } 
            if (di != -1){
                rep(i, di, di){ 
                    int _x = x + dir[i % 6][0], _y = y + dir[i % 6][1];
                    if (ok(_x, _y)) {x = _x, y = _y, di = i % 6; goto ok;}
                }
            } 
        }
        break; 
        ok:;
    }
    
}

int main(){
    int T; scanf("%d", &T);
    while (T--){  
        ct = 0;
        scanf("%d", &r);
        /*
        if (r & 1){
            id[maxn][maxn] = id[maxn][maxn + 1] = 1;
            sta[++cs] = pii(0, 0), sta[++cs] = pii(0, 1);
            ct += 2;
            printf("%d", 1); 
            dfs(0, 2, 0);
        }
        else */
        dfs(0, 0, -1);
        printf("\n");
        while (cs){
            id[sta[cs].fi + maxn][sta[cs].se + maxn] = 0;
            cs--;
        }
        //printf(" %d\n", ct);
    }
    return 0;
}

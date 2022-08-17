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
 
pii sta[maxn * maxn * 4];
int cs = 0, ct = 0;
void dfs(int x, int y, int di, int shit){
    
    while (1){
    	if (shit){
    		id[x + maxn][y + maxn] = 1;
		    sta[++cs] = pii(x, y);
		    ct++;
		    if (di != -1) printf("%d", di + 1); 
		    if (is_up(x, y)){
		        int d = dist(x, y);
		        per(i, di + 5, di + 1){
		            if (i == di) continue;
		            int _x = x + dir[i % 6][0], _y = y + dir[i % 6][1];
		            if (ok(_x, _y) && dist(_x, _y) < d) {x = _x, y = _y, di = i % 6; goto ok;}
		        }
		        per(i, di + 5, di + 1){
		            if (i == di) continue;
		            int _x = x + dir[i % 6][0], _y = y + dir[i % 6][1];
		            if (ok(_x, _y) && dist(_x, _y) == d) {x = _x, y = _y, di = i % 6; goto ok;}
		        }
		        per(i, di + 5, di + 1){
		            if (i == di) continue;
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
		        per(i, di + 5, di + 1){
		            if (i == di) continue;
		            int _x = x + dir[i % 6][0], _y = y + dir[i % 6][1];
		            if (ok(_x, _y) && dist(_x, _y) > d) {x = _x, y = _y, di = i % 6; goto ok;}
		        }
		        per(i, di + 5, di + 1){
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
    	}
    	else {
    		id[x + maxn][y + maxn] = 1;
		    sta[++cs] = pii(x, y);
		    ct++;
		    if (di != -1) printf("%d", di + 1); 
		    if (is_up(x, y)){
		        int d = dist(x, y);
		        rep(i, di + 1, di + 5){
		            if (i == di) continue;
		            int _x = x + dir[i % 6][0], _y = y + dir[i % 6][1];
		            if (ok(_x, _y) && dist(_x, _y) < d) {x = _x, y = _y, di = i % 6; goto ok;}
		        }
		        rep(i, di + 1, di + 5){
		            if (i == di) continue;
		            int _x = x + dir[i % 6][0], _y = y + dir[i % 6][1];
		            if (ok(_x, _y) && dist(_x, _y) == d) {x = _x, y = _y, di = i % 6; goto ok;}
		        }
		        rep(i, di + 1, di + 5){
		            if (i == di) continue;
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
		    
    	}
    	ok:; 
    }
    
} 

int main(){
    int T; scanf("%d", &T);
    while (T--){  
        ct = 0;
        scanf("%d", &r);
        /*
        if (r == 3){
            id[maxn][maxn] = id[maxn][maxn + 1] = 1;
            sta[++cs] = pii(0, 0), sta[++cs] = pii(0, 1);
            ct += 2;
            printf("%d", 1); 
            dfs(0, 2, 0);
        }
        else if (r & 1){
        	id[maxn][maxn] = id[maxn][maxn + 1] = id[maxn + 1][maxn + 2] = id[maxn + 1][maxn + 3] = id[maxn - 1][maxn + 1] = id[maxn][maxn + 2] = 1;
            sta[++cs] = pii(0, 0), sta[++cs] = pii(0, 1), sta[++cs] = pii(1, 2), sta[++cs] = pii(1, 3), sta[++cs] = pii(-1, 1), sta[++cs] = pii(0, 2);
            ct += 4;
            printf("121"); 
            dfs(0, 2, 3);
        }
        */
        if (r & 1) {
        	id[maxn][maxn] = id[maxn][maxn + 1] = id[maxn - 1][maxn + 1] = 1;
            sta[++cs] = pii(0, 0), sta[++cs] = pii(0, 1), sta[++cs] = pii(-1, 1);
            ct += 3;
            printf("16"); 
            dfs(-2, 0, 4, 1);
        }
        else dfs(0, 0, -1, 0);
        //printf("\n");
        while (cs){
            id[sta[cs].fi + maxn][sta[cs].se + maxn] = 0;
            cs--;
        }
        printf(" %d\n", ct);
    }
    return 0;
}

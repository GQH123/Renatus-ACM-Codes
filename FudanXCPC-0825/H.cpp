#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
#define maxn 
#define maxm
using namespace std;

int n, k;
int upd(int x, int bit) {
	int id = ((x >> (bit * 2)) & 3);
	assert(id == 1 || id == 2);
	if (id == 1){
		srep(i, bit, n){
			if (((x >> (i * 2)) & 3) == 0) {
				return x ^ (id << (bit * 2)) ^ (id << (i * 2)); 
			}
		}
	}
	else {
		per(i, bit, 0){
			if (((x >> (i * 2)) & 3) == 0) {
				return x ^ (id << (bit * 2)) ^ (id << (i * 2)); 
			}
		}
	}
	return -1;
}
int res = -1;
bool OK(int x, int player, bool f = 1){  
	bool t = 0;
	if (!f) {
		srep(i, 0, n){
			int id = ((x >> (i * 2)) & 3); 
			if (id == player){
				int d = upd(x, i);
				if (d != -1) { t = 1; if (!OK(d, 3 - player, 0)) return true; }
			}
		}
	}
	else {
		assert(player == 1);
		int mx = -1;
		srep(i, 0, n){
			int id = ((x >> (i * 2)) & 3); 
			if (id == player){
				int d = upd(x, i);
				if (d != -1) { t = 1; if (!OK(d, 3 - player, 0)) mx = max(mx, i + 1); }
			}
		}
		res = mx;
		if (mx != -1) return true;
	}
	if (!t) return true;
	return false;
}
int play(){
	int x = 0; res = -1;
	rep(i, 1, k) x = x * 4 + 2;
	rep(i, 1, n - 2 * k) x = x * 4;
	rep(i, 1, k) x = x * 4 + 1;
	return OK(x, 1);
}

int main(){
	rep(x, 3, 20) {
		rep(y, 1, (x - 1) / 2){
			n = x, k = y;
			printf("%d %d : %d ", x, y, play());
			printf("%d\n", res);
		}
	}
	return 0;
}

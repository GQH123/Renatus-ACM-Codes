#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define maxn 
#define maxm 
#define M 
#define ll long long int 
#define ld long double
#define pb push_back
#define pc putchar
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define lowbit(x) (x & -x)
using namespace std;

const char tab[][4] = {"012","021","102","120","201","210"};
int sta[6][3]; //level, mode
int dri[3];
int per[6]; 

int get_two(int x, int y, int z, int w){ // level, drink
	rep(i, 0, 5) {
		if (tab[i][x] - '0' == z && tab[i][y] - '0' == w) return i;
	}
	return -1;
}

void play(int x, int y, int z, int& res){
	if (x + z - y <= 0) return;
	x = 3 - x, y = 3 - y, z = 3 - z; 
	rep(i, 0, 5) {
		if (!per[i]) continue;
		int id = tab[i][x] - '0';
		rep(j, 0, 2) {
			if (!per[i]) break;
			if (j == id) continue;
			if (dri[j]) {
				int id_per = get_two(y, z, id, j);
				if (id_per == -1) continue;
				//assert(id_per != -1);
				int mi = min(dri[j], min(sta[id_per][id], per[i]));
				res += (3 - x + 3 - z - (3 - y)) * mi;
				sta[id_per][id] -= mi, sta[id_per][j] += mi;
				sta[i][id] += mi;
				per[i] -= mi, dri[j] -= mi; 
			}
		}
	}
}

void play2(int x, int y, int z, int w, int& res){
	if (x + z - y - w <= 0) return;
	x = 3 - x, y = 3 - y, z = 3 - z, w = 3 - w;
	rep(i, 0, 5) {
		//if (!per[i]) continue;
		int id = tab[i][x] - '0';
		int id2 = tab[i][w] - '0';
		rep(j, id2, id2) { 
			if (j == id) continue; 
			int id_per = get_two(y, z, id, j);
			if (id_per == -1) continue;
			//assert(id_per != -1);
			int mi = min(sta[id_per][id], sta[i][id2]); 
			res += (3 - x + 3 - z - (3 - y) - (3 - w)) * mi;
			sta[id_per][id] -= mi, sta[id_per][id2] += mi;
			sta[i][id2] -= mi, sta[i][id] += mi;
			//sta[i][id] += mi;
			//per[i] -= mi, dri[j] -= mi;  
		}
	}
}

int main(){
	int T, n; char s[4];
	scanf("%d", &T);
	while (T--){
		rep(i, 0, 2) dri[i] = 0;
		rep(i, 0, 5) per[i] = 0;
		rep(i, 0, 5) rep(j, 0, 2) sta[i][j] = 0;
		scanf("%d%d%d%d", &n, &dri[0], &dri[1], &dri[2]);
		int res = 0;
		rep(i, 1, n) {
			scanf("%s", s);
			if (s[0] == '0') {
				if (s[1] == '1') per[0]++;
				else per[1]++;
			}
			else if (s[0] == '1') {
				if (s[1] == '0') per[2]++;
				else per[3]++;
			}
			else {
				if (s[1] == '0') per[4]++;
				else per[5]++;
			}
		}
		rep(i, 0, 5) {
			if (!per[i]) continue;
			int id = tab[i][0] - '0';
			int mi = min(per[i], dri[id]);
			per[i] -= mi, dri[id] -= mi, sta[i][id] += mi, res += 3 * mi;
		}
		rep(i, 0, 5) {
			if (!per[i]) continue;
			int id2 = tab[i][1] - '0';
			int mi = min(per[i], dri[id2]);
			per[i] -= mi, dri[id2] -= mi, sta[i][id2] += mi, res += 2 * mi;
			/*
			if (per[i]) {
				assert(!dri[id2]);
				rep(j, 0, 2) {
					if (!per[i]) break;
					if (j == id2) continue;
					if (dri[j]) {
						int id_per = get_pre_two(id2, j);
						assert(id_per != -1);
						int mi = min(dri[j], min(sta[id_per][id2], per[i]));
						res += mi;
						sta[id_per][id2] -= mi, sta[id_per][j] += mi;
						sta[i][id2] += mi;
						per[i] -= mi, dri[j] -= mi; 
					}
				}
			}
			*/
		}
		rep(i, 0, 5) {
			if (!per[i]) continue;
			int id3 = tab[i][2] - '0';
			int mi = min(per[i], dri[id3]);
			per[i] -= mi, dri[id3] -= mi, sta[i][id3] += mi, res += mi;
			//assert(!per[i]);
		} 
		while (1){
			int _res = res;
			rep(i, 1, 3) rep(j, 1, 3) rep(k, 1, 3) play(i, j, k, res);
			rep(i, 1, 3) rep(j, 1, 3) rep(k, 1, 3) rep(l, 1, 3) play2(i, j, k, l, res);
			if (res == _res) break;
		}
		rep(i, 0, 5) assert(!per[i]);
		rep(i, 0, 2) assert(!dri[i]);
		printf("%d\n", res);
	} 
	return 0;
}

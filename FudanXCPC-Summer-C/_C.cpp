#include <cstdio>
#include <set> 
#include <map>
#include <algorithm>
#include <cmath>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 100020
#define maxm 200020
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define pc putchar
#define ll long long int 
#define ld long double 
#define lowbit(x) (x & -x)
#define M 
#define mo(x) (x = (x >= M) ? (x - M) : x)
using namespace std;

set<int> son[maxn];
set<int> :: iterator it;
struct edge{
	int x, y;
	edge(int x, int y) : x(x), y(y){}
	edge(){}
	bool operator < (const edge b) const{
		return (x == b.x) ? y < b.y : x < b.x;
	}
}e[maxm];
int num[maxn], deg[maxn];

int n, m;

inline ll cal(int x){
	if (x < 2) return 0;
	return 1ll * (x - 1) * x >> 1;
}

int lis[maxn], cs = 0; 

inline void recover(){
	rep(i, 1, m) num[i] = deg[i] = 0;
	rep(i, 1, n) son[i].clear();
	cs = 0; 
}
inline int id(int x, int y){
	if (x > y) swap(x, y);
	return lower_bound(e + 1, e + 1 + m, edge(x, y)) - e;
}

int main(){
	//cerr << sizeof(son[0]) << endl;
	//rep(i, 1, 10) son[0].insert(i);
	//cerr << sizeof(son[0]) << endl;
	int x, y, bsiz;
	while (scanf("%d%d", &n, &m) == 2){
		bsiz = (int)sqrt(n) + 2;
		rep(i, 1, m) {
			scanf("%d%d", &x, &y);
			if (x > y) swap(x, y);
			e[i] = edge(x, y), son[x].insert(y), son[y].insert(x), deg[x]++, deg[y]++;
		}
		sort(e + 1, e + 1 + m);
		rep(i, 1, n) if (deg[i] >= bsiz) lis[++cs] = i;  
		rep(i, 1, m){
			int x = e[i].x, y = e[i].y;
			if (deg[x] > deg[y]) swap(x, y);
			if (deg[x] >= bsiz && deg[y] >= bsiz) continue; 
			for (it = son[x].begin(); it != son[x].end(); it++){
				int z = *it;
				if (son[y].count(z)) num[i]++;
				if (deg[z] >= bsiz && deg[y] >= bsiz) {
					if (deg[y] < deg[z] || (deg[y] == deg[z] && y < z)) num[id(y, z)]++;
					else num[id(x, y)]++;
				}
			}
		}  
		rep(i, 1, cs) rep(j, i + 1, cs) rep(k, j + 1, cs){
			int x = lis[i], y = lis[j], z = lis[k];
			if (son[x].count(y) && son[y].count(z) && son[z].count(x)) {
				num[id(x, y)]++, num[id(x, z)]++, num[id(y, z)]++;
				//cerr << "Good!" << endl;
			}
		}
		ll ans = 0;
		rep(i, 1, m) ans += cal(num[i]);
		printf("%lld\n", ans);
		recover();
	}
	return 0;
}

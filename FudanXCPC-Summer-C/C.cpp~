#include <cstdio> 
#include <vector>
#include <algorithm>
#include <cmath>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 100020
#define maxm 200020
#define maxr 100000
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
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template<class T> bool read(T& x){
	char ch = gc(); x = 0; 
	while (!('0' <= ch && ch <= '9') && ch != EOF) ch = gc();
	if (ch == EOF) return false;
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	return true;
}

vector<int> G[maxn];
struct edge{
	int x, y;
	edge(int x, int y) : x(x), y(y){}
	edge(){}
	bool operator < (const edge b) const{
		return (x == b.x) ? y < b.y : x < b.x;
	}
}e[maxm];
int num[maxm], deg[maxn];

int n, m;

inline ll cal(int x){
	if (x < 2) return 0;
	return 1ll * (x - 1) * x >> 1;
} 

inline void recover(){
	rep(i, 1, m) num[i] = 0;
	rep(i, 1, n) deg[i] = 0, G[i].clear(); 
} 
inline int get_exi(int x, int y){
	int _y = lower_bound(G[x].begin(), G[x].end(), y) - G[x].begin(); 
	return (_y == deg[x] || G[x][_y] != y) ? 0 : 1;
}

int main(){
	//cerr << sizeof(son[0]) << endl;
	//rep(i, 1, 10) son[0].insert(i);
	//cerr << sizeof(son[0]) << endl;
	//freopen("C.in", "r", stdin);
	//freopen("C.out", "w", stdout);
	int x, y;
	while (read(n) && read(m)){
		rep(i, 1, m) read(x), read(y), e[i] = edge(x, y), G[x].pb(y), G[y].pb(x), deg[x]++, deg[y]++;
		rep(i, 1, n) sort(G[i].begin(), G[i].end());
		rep(i, 1, m){
			int x = e[i].x, y = e[i].y;
			if (deg[x] > deg[y]) swap(x, y);
			srep(j, 0, deg[x]) num[i] += get_exi(y, G[x][j]);
		}
		ll ans = 0;
		rep(i, 1, m) ans += cal(num[i]);
		printf("%lld\n", ans);
		recover();
	}
	return 0;
}

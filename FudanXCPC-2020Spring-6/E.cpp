#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define pii pair<int, int>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define ll long long int 
#define pb push_back
#define lowbit(x) (x & -x)
#define maxr 200002
#define maxn 320
#define maxm
#define maxs
#define maxb
#define M 10007
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}
int _num[100];
template <class T> void write(T x){	
	if (!x) {putchar('0'), putchar('\n'); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar('\n');
}

int n, deg[maxn];
/*
struct edge{
	int next, to;
	ll c;
	edge(int next, int to, ll c) : next(next), to(to), c(c){}
	edge(){}
}e[maxn * maxn << 2];
int cnt = 1, h[maxn]; 
void Add_Edge(int x, int y, ll c){
	e[++cnt] = edge(h[x], y, c);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x, c);
	h[y] = cnt;
	deg[x]++, deg[y]++;
}
*/
struct ele{
	int x, y;
	ele(int x, int y) : x(x), y(y){}
	ele(){}
	bool operator < (const ele b) const{
		return (x == b.x) ? y < b.y : x < b.x;
	}
}p[maxn];

inline int dist(int i, int j){
	return (p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y);
}

/*
int ufs[maxn];
int find_root(int x){
	return (ufs[x] == x) ? x : find_root(ufs[x]);
}
void merge(int i, int j){
	i = find_root(i), j = find_root(j);
	if (i == j) return;
	ufs[i] = j;
}
*/

set<pii> S;
int A[maxn][maxn];

/*
int vis[maxn];
set<ll> s;
int bfs[maxn];
int head = 0, tail = 0;
ll BFS(int x){	
	head = tail = 0;
	bfs[++head] = x;
	vis[x] = 1;
	ll ans = 0;
	while (head > tail){
		int x = bfs[++tail]; 
		erep(i, x){
			int op = e[i].to;
			if (vis[op]) continue;
			bfs[++head] = op, vis[op] = 1, ans ^= e[i].c;
		}
	}
	return ans;
}
*/
int power(int x, int y){
	int ans = 1, con = x;
	while (y){
		if (y & 1) ans = ans * con % M;
		con = con * con % M;
		y >>= 1;
	}
	return ans;
}
int getinv(int x){
	return power(x, M - 2);
}
int Gauss(){
	n--;
	int ans = 1;
	rep(j, 1, n){
		int f = -1;
		rep(i, j, n) if (A[i][j]) {f = i; break;} 
		if (f == -1) return -1;
		rep(k, 1, n) swap(A[j][k], A[f][k]), ans = -ans;
		rep(i, j + 1, n){
			int d = A[i][j] * getinv(A[j][j]) % M;
			rep(k, j, n) A[i][k] = (A[i][k] - d * A[j][k] % M + M) % M; 
		}
	}
	if (ans == -1) ans = (M - 1);
	rep(i, 1, n) ans = ans * A[i][i] % M;
	return ans;
}

void recover(){
	//s.clear();
	n++;
	rep(i, 1, n) deg[i] = 0;
	rep(i, 1, n) rep(j, 1, n) A[i][j] = 0;
}

int gcd(int x, int y){
	return (!y) ? x : gcd(y, x % y);
}

int main(){
	
		//freopen("E.in", "r", stdin);
		
	int T, r;
	read(T);
	while (T--){
		read(n), read(r), r = r * r;
		rep(i, 1, n) read(p[i].x), read(p[i].y);
		sort(p + 1, p + 1 + n);
		//rep(i, 1, n) ufs[i] = i;
		rep(i, 1, n) {	
			S.clear();
			rep(j, i + 1, n) {
				int dx = p[j].x - p[i].x, dy = p[j].y - p[i].y;
				bool f = 0;
				if (dy < 0) f = 1, dy = -dy;
				int gd = gcd(dx, dy);
				if (!gd) {
					dx = (dx) ? 1 : 0;
					dy = (dy) ? 1 : 0;
				}
				else dx /= gd, dy /= gd;
				if (f) dy = -dy;
				if (dist(i, j) <= r && !S.count(pii(dx, dy))) S.insert(pii(dx, dy)), A[i][j] = A[j][i] = 1, deg[i]++, deg[j]++;//merge(i, j), Add_Edge(i, j, (ll)rand() * rand() * rand() * rand());
			} 
		}
		/*
		int root = find_root(1);
		rep(i, 2, n) {	
			if (find_root(i) != root){
				printf("-1\n");
				goto fail;
			}
		} 
		*/
		rep(i, 1, n) A[i][i] = M-deg[i]; 
		printf("%d\n", Gauss());
		recover();
		//fail:recover();
		/*
		rep(i, 1, n) {
			rep(j, 1, n) vis[j] = 0;
			s.insert(BFS(i));
		}
		printf("%lu\n", s.size());
		fail:recover();
		*/
	}
	return 0;
}


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
#define maxr 2000020
#define maxn
#define maxm
#define maxs
#define maxb
#define M 10000007
#define mo(x) (x = (x >= M) ? (x - M) : x)
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
int _num[20];
template <class T> void write(T x){	
	if (!x) {putchar('0'), putchar('\n'); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar('\n');
}

struct mat{
	int num[15][15];
	int r, c;
	mat(int r, int c) : r(r), c(c){memset(num, 0, sizeof(num));}
	void operator = (const mat b){
		r = b.r, c = b.c;
		srep(i, 0, r) srep(j, 0, c) num[i][j] = b.num[i][j];
	}
	void getI(){
		srep(i, 0, r) num[i][i] = 1;
	}
};

mat operator * (mat a, mat b){
	mat c = mat(a.r, b.c);
	srep(i, 0, a.r) srep(j, 0, b.c) srep(k, 0, a.c){
		c.num[i][j] += (ll)a.num[i][k] * b.num[k][j] % M, mo(c.num[i][j]);
	}
	return c;
}

mat power(mat a, int k){
	mat ans = mat(a.r, a.c), con = a;
	ans.getI();
	while (k){
		if (k & 1) ans = ans * con;
		con = con * con;
		k >>= 1;
	}
	return ans;
}


int n, m;
int a[20];
mat res = mat(0, 0), con = mat(0, 0);
void debug(mat x){
	printf("\n");srep(i, 0, x.r) {srep(j, 0, x.c) printf("%d ", x.num[i][j]); printf("\n");}
}
void solve(){
	res = mat(1, n + 2);
	res.num[0][0] = 1;
	res.num[0][1] = 233;
	rep(i, 1, n) res.num[0][i + 1] = a[i];
	//debug(res);
	
	con = mat(n + 2, n + 2);
	con.num[0][0] = 1;
	con.num[0][1] = 3;
	con.num[1][1] = 10;
	rep(j, 2, n + 1) rep(i, 1, j) con.num[i][j] = 1;
	//debug(con);
	
	con = power(con, m);
	//debug(con);
	
	res = res * con;
	//debug(res);
	
	printf("%d\n", res.num[0][n + 1]);
}


int main(){
	
		freopen("G.in", "r", stdin);
		
	//ios :: sync_with_stdio(false), cin.tie(0);
	
	while (scanf("%d", &n) == 1){
		//printf("----------------------------------\n");
		scanf("%d", &m);
		rep(i, 1, n) scanf("%d", a + i);
		solve();
		//printf("----------------------------------\n");
	}
	return 0;
}


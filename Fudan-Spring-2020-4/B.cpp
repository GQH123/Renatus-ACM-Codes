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

int f1, f2, a, b, n, M, k;
struct mat{
	int num[51][51];
	int r, c;
	mat(int r, int c) : r(r), c(c){memset(num, 0, sizeof(num));}
	mat(){}
	void normalize(){ 
		memset(num, 0, sizeof(num));
		srep(i, 0, r) num[i][i] = 1;
	}
	void operator = (const mat b) {
		memset(num, 0, sizeof(num));
		r = b.r, c = b.c;
		srep(i, 0, r) srep(j, 0, c) num[i][j] = b.num[i][j];
	}
};

mat operator * (mat a, mat b){
	mat c = mat(a.r, b.c);
	srep(i, 0, a.r) srep(j, 0, b.c) srep(k, 0, a.c) {
		c.num[i][j] += (ll)a.num[i][k] * b.num[k][j] % M, mo(c.num[i][j]);
	}
	return c;
}

mat power(mat a, int x){
	mat ans = mat(a.r, a.c), con = a;
	ans.normalize();
	while (x){
		if (x & 1) ans = ans * con;
		con = con * con;
		x >>= 1;
	}
	return ans;
}

int power(int x, int y){
	int ans = 1, con = x;
	while (y){
		if (y & 1) ans = (ll)ans * con % M;
		y >>= 1;
		con = (ll)con * con % M;
	}
	return ans;
}

int C[51][51];
mat res, trans;
void work(){
	C[0][0] = 1;
	rep(i, 1, 50){
		C[i][0] = 1;
		rep(j, 1, 50) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]), mo(C[i][j]);
	}
	res = mat(1, k + 2), trans = mat(k + 2, k + 2);
	srep(i, 0, k + 1) res.num[0][i] = (ll)power(f2, k - i) * power(f1, i) % M;
	res.num[0][k + 1] = power(f1, k);
	per(j, k, 0) rep(i, 0, k - j) trans.num[i][j] = (ll)C[k - j][i] * power(a, k - j - i) % M * power(b, i) % M; 
	trans.num[0][k + 1] = 1;
	trans.num[k + 1][k + 1] = 1;
	trans = power(trans, n - 1);
	res = res * trans;
	printf("%d\n", res.num[0][k + 1]);
}

int main(){
	
		freopen("B.in", "r", stdin); 
		
	//ios :: sync_with_stdio(false), cin.tie(0);
	int T;
	read(T);
	while(T--){
		read(f1), read(f2), read(a), read(b), read(k), read(n), read(M);
		work();
	}
	return 0;
}


#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 
#define mo(x) (x = (x >= M) ? (x - M) : x)
#define ll long long int 
using namespace std;

int M, sx, sy, dx, dy;
ll t;

struct mat{
	int num[6][6];
	int r, c;
	mat(int r, int c):r(r), c(c){
		memset(num, 0, sizeof(num));
	}
	mat(){
		r = c = 0, memset(num, 0, sizeof(num));
	}
	void operator = (const mat b) {
		r = b.r, c = b.c;
		srep(i, 0, r) srep(j, 0, c) num[i][j] = b.num[i][j];
	}
}I(6, 6);

mat operator * (mat a, mat b){
	mat c(a.r, b.c);
	srep(i, 0, a.r) srep(j, 0, b.c) srep(k, 0, a.c) {
		c.num[i][j] += (ll)a.num[i][k] * b.num[k][j] % M, mo(c.num[i][j]);
	}
	return c;
}
mat power(mat a, ll y){
	mat ans = I, con = a;
	while (y){
		if (y & 1) ans = ans * con;
		con = con * con;
		y >>= 1;
	}
	return ans;
}
mat ans(1, 6), trans(6, 6); 

int main(){
	
		freopen("J.in", "r", stdin);
		
	cin >> M >> sx >> sy >> dx >> dy >> t;
	if (!t) {cout << sx << ' ' << sy; return 0;}
	sx = (sx % M + M) % M, sy = (sy % M + M) % M, dx = (dx % M + M) % M, dy = (dy % M + M) % M;
	
	int num[] = {((ll)sx + sx + sy + dx) % M, sx, ((ll)sy + sy + sx + dy) % M, sy, 1, 1};
	memcpy(ans.num, num, sizeof(ans.num));
	
	int _num[] =     {3, 1, 1, 0, 0, 0,
					M-1, 0, 0, 0, 0, 0,
					  1, 0, 3, 1, 0, 0,
					  0,0,M-1, 0, 0, 0,
					  1, 0, 1, 0, 1, 0,
					  0, 0, 0, 0, 1, 1};
	//注意矩阵中的负数，都要在模意义下进行转化
	memcpy(trans.num, _num, sizeof(trans.num));
	
	int __num[] = {1, 0, 0, 0, 0, 0,
				   0, 1, 0, 0, 0, 0, 
				   0, 0, 1, 0, 0, 0, 
				   0, 0, 0, 1, 0, 0, 
				   0, 0, 0, 0, 1, 0,
				   0, 0, 0, 0, 0, 1};
	memcpy(I.num, __num, sizeof(I.num));

	ans = ans * power(trans, t - 1);
	
	cout << (ans.num[0][0] - 1 + M) % M + 1 << ' ' << (ans.num[0][2] - 1 + M) % M + 1;
	
	return 0;
}

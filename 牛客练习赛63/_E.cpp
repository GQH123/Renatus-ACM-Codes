#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 400020
#define M 1000000007
#define mo(x) (x = (x >= M) ? (x - M) : x)
#define ll long long int 
using namespace std;

int ls = 0;
char s[maxn], t[maxn << 2];
int f[maxn];
void init(){	
	ls = strlen(s);
	f[0] = f[1] = 0;
	srep(i, 1, ls) {
		int now = f[i];
		while (now && s[now] != s[i]) now = f[now];
		f[i + 1] = (s[now] == s[i]) ? (now + 1) : 0;
	}
}
int match(char* t){
	int lt = strlen(t), now = 0, ans = 0;
	srep(i, 0, lt){
		while (now && s[now] != t[i]) now = f[now];
		now = (s[now] == t[i]) ? (now + 1) : 0;
		if (now == ls) ans++, now = f[now];
	}
	return ans;
}

ll n;

int la = 0, lb = 0;
char A[maxn << 4], B[maxn << 4], _B[maxn << 4];
int c[2];


struct mat{
	int r, c;
	int num[4][4];
	mat(){r = c = 0, memset(num, 0, sizeof(num));}
};
mat operator * (mat a, mat b){
	mat c;
	c.r = a.r, c.c = b.c;
	srep(i, 0, a.r){
		srep(j, 0, b.c){
			srep(k, 0, a.c){
				c.num[i][j] += (ll)a.num[i][k] * b.num[k][j] % M;
				mo(c.num[i][j]);
			}
		}
	}
	return c;
}
mat power(mat a, ll y){
	mat ans, con;
	ans.r = ans.c = a.r;
	srep(i, 0, ans.r) ans.num[i][i] = 1;
	con.r = con.c = a.r;
	srep(i, 0, con.r) srep(j, 0, con.c) con.num[i][j] = a.num[i][j];
	while (y){
		if (y & 1) ans = ans * con;
		y >>= 1;
		con = con * con;
	}
	return ans;
} 

mat trans, dp, C0, C1;

int main(){
	scanf("%lld", &n);
	scanf("%s%s", A, B);
	la = strlen(A), lb = strlen(B);
	scanf("%s", s);
	init();
	if (n == 1){
		printf("%d", match(A));
		return 0;
	}
	int ia = 1;
	do{
		srep(i, 0, lb) _B[i] = B[i];
		srep(i, 0, la) B[i] = A[i];
		srep(i, la, la + lb) B[i] = _B[i - la];
		B[la + lb] = '\0'; //////
		srep(i, 0, lb) A[i] = _B[i];
		A[lb] = '\0'; //////
		lb = la + lb;
		la = lb - la;
		ia++;
	}while (la < ls);
	
	int init_v1 = match(A), init_v2 = match(B), init_i = ia + 1;
	
	if (n < ia) {printf("0"); return 0;}
	else if (n == ia) {printf("%d", init_v1); return 0;}
	
	srep(i, 0, ls - 1) t[i] = A[la - 1 - (ls - 2 - i)];
	srep(i, ls - 1, ((ls - 1) << 1)) t[i] = B[i - (ls - 1)];
	c[ia & 1] = match(t);
	
	srep(i, 0, lb) _B[i] = B[i];
	srep(i, 0, la) B[i] = A[i];
	srep(i, la, la + lb) B[i] = _B[i - la];
	srep(i, 0, lb) A[i] = _B[i];
	lb = la + lb;
	la = lb - la;
	ia++;
	srep(i, 0, ls - 1) t[i] = A[la - 1 - (ls - 2 - i)];
	srep(i, ls - 1, ((ls - 1) << 1)) t[i] = B[i - (ls - 1)];
	c[ia & 1] = match(t);
	
	C0.r = C0.c = C1.r = C1.c = 4;
	C1.num[0][0] = C1.num[0][1] = C1.num[1][0] = C1.num[2][2] = C1.num[3][0] = C1.num[3][3] = 1;
	C0.num[0][0] = C0.num[0][1] = C0.num[1][0] = C0.num[2][0] = C0.num[2][2] = C0.num[3][3] = 1;
	
	dp.r = 1, dp.c = 4;
	dp.num[0][0] = init_v2, dp.num[0][1] = init_v1, dp.num[0][2] = c[0], dp.num[0][3] = c[1];
	
	trans.r = trans.c = 4;
	trans = (init_i & 1) ? C0 * C1 : C1 * C0;
	
	trans = power(trans, (n - init_i) >> 1);
	dp = dp * trans;
	
	if ((n ^ init_i) & 1) {
		dp = ((n - 1) & 1) ? dp * C0 : dp * C1;
	}
	
	printf("%d", dp.num[0][0]);
	return 0;
}

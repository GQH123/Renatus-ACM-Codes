#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
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
#define maxn 
#define maxm 
#define maxb 
#define maxs 
#define M 1000000007
#define mo(x) (x = (x >= M) ? (x - M) : x)
using namespace std;

int C[20][20];
void init(){
	C[0][0] = 1;
	rep(i, 1, 19) {
		C[i][0] = 1;
		rep(j, 1, 19) C[i][j] = C[i - 1][j] + C[i - 1][j - 1], mo(C[i][j]);
	}
	//rep(i, 0, 19) {rep(j, 0, 19) cerr << C[i][j] << ' '; cerr << endl;}
}
int n, k, st;
char day[30];
ll power(int x, int y){
	int ans = 1, con = x;
	while (y){
		if (y & 1) ans = (ll)ans * con % M;
		con = (ll)con * con % M;
		y >>= 1;
	}
	return ans;
}
ll getinv(int x){
	return power(x, M - 2);
}
void cal(int k, int n, ll* res){
	res[0] = (n + 1) % M;
	rep(i, 2, k + 1){
		res[i - 1] = power(n + 1, i);
		rep(j, 0, i - 2){
			res[i - 1] = res[i - 1] + M - C[i][j] * res[j] % M;
			mo(res[i - 1]);
		}
		//res[i - 1] = res[i - 1] + M - 1, mo(res[i - 1]);
		res[i - 1] = res[i - 1] * getinv(i) % M;
	}
	//rep(i, 0, k) cerr << res[i] << ' ';
	//cerr << endl;
}


int main(){
	int T;
	init();
	scanf("%d", &T);
	rep(TT, 1, T){
		printf("Case %d: ", TT);
		scanf("%s", day + 1);
		scanf("%d%d", &n, &k);
		if (day[1] == 'M') st = 1;
		else if (day[1] == 'T' && day[2] == 'u') st = 2;
		else if (day[1] == 'W') st = 3;
		else if (day[1] == 'T' && day[2] == 'h') st = 4;
		else if (day[1] == 'F' && day[2] == 'r') st = 5;
		else if (day[1] == 'S' && day[2] == 'a') st = 6;
		else if (day[1] == 'S' && day[2] == 'u') st = 7;
		
		if (n < 50){
			int sum = 0; ll ans = 0;
			rep(i, 1, n){
				sum++;
				if (1 <= st && st <= 5) ans += power(sum, k), mo(ans);
				st++;
				if (st > 7) st = 1;
			}
			printf("%lld\n", ans);
		}
		else {
			ll ans = 0;
			int _n = n, sum = 0;
			while (st != 1){
				sum++;
				if (1 <= st && st <= 5) ans += power(sum, k), mo(ans);
				st++, n--;
				if (st > 7) st = 1;
			}
			int first = sum, T = n / 7;
			//sum += n / 7 * 5;
			n %= 7;
			rep(i, 1, n){ 
				if (1 <= st && st <= 5) ans += power(_n + i - n, k), mo(ans);
				st++;
				if (st > 7) st = 1;
			}
			
			ll res[20];
			cal(k, T - 1, res);
			rep(i, 1, 5){
				first++;
				rep(j, 0, k){
					ans += power(7, j) * C[k][j] % M * power(first, k - j) % M * res[j] % M;
					mo(ans);
				}
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}

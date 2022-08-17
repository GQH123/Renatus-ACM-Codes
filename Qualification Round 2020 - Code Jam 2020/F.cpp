#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second
#define ll long long int
#define ld long double
#define pb push_back
#define pc putchar 
#define ms(x, a) memset(x, a, sizeof(x))
#define mo(x) (x = (x >= M) ? (x - M) : x)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define maxn 55
#define maxm
#define maxr 2000000
#define maxs
#define maxb
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){	
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}

char _num[30];
template <class T> void write(T x, char sep = ' '){
	if (!x) {pc('0'), pc(sep); return;}
	if (x < 0) pc('-'), x = -x;
	int cn = 0;
	while (x) _num[++cn] = x % 10 + '0', x /= 10;
	while (cn) pc(_num[cn--]); pc(sep);
} 

int ans[maxn][maxn];

int tmp[maxn << 1];
void circularly_construct(int n, int x){
	tmp[1] = x;
	int now = 1;
	rep(i, 2, n) {
		if (now == x) now++;
		tmp[i] = now++;
	}
	rep(i, n + 1, (n << 1)) tmp[i] = tmp[i - n];
	rep(i, 1, n) rep(j, 1, n) ans[i][j] = tmp[j + 1 + n - i];
}

bool vis[maxn];
void two_construct(int n, int a, int b){
	ans[n - 1][n - 1] = ans[n][n] = b, ans[n - 1][n] = ans[n][n - 1] = a; 
	rep(i, 1, n - 2) ans[i][i] = a; 
	rep(i, 1, n - 2) ans[i][i % (n - 2) + 1] = b;
	int now = 1;
	rep(i, 1, n - 2) {
		if (now == a) now++, i--;
		else if (now == b) now++, i--;
		else tmp[i] = now++;
	}
	now = 1;
	rep(k, 2, n - 3){	
		now = (k << 1) - 3;
		if (now > (n - 2)) {
			now = (now - 1) % (n - 2) + 1;
			if (now & 1) now++;
		}
		rep(i, 1, n - 2) {
			ans[i][(i + k - 1) % (n - 2) + 1] = tmp[now++];
			if (now > n - 2) now = 1;
		}
	}
	int x = -1, y = -1;
	rep(i, 1, n) vis[i] = 1;
	rep(i, 1, n - 2) vis[ans[1][i]] = 0;
	rep(i, 1, n - 2){
		if (vis[tmp[i]]) {
			if (x == -1) x = i;
			else y = i;
		}
	}
	rep(i, 1, n - 2){
		ans[i][n - 1] = tmp[x], ans[i][n] = tmp[y];
		x++, y++;
		if (x > n - 2) x = 1;
		if (y > n - 2) y = 1;
	}
	x = -1, y = -1;
	rep(i, 1, n) vis[i] = 1;
	rep(i, 1, n - 2) vis[ans[i][1]] = 0;
	rep(i, 1, n - 2){
		if (vis[tmp[i]]) {
			if (x == -1) x = i;
			else y = i;
		}
	}
	rep(i, 1, n - 2){
		ans[n - 1][i] = tmp[x], ans[n][i] = tmp[y];
		x++, y++;
		if (x > n - 2) x = 1;
		if (y > n - 2) y = 1;
	}
}

void three_construct(int n, int a, int b, int c){
	ans[n][n] = ans[n - 1][n - 2] = ans[n - 2][n - 1] = c;
	ans[n - 2][n - 2] = ans[n][n - 1] = ans[n - 1][n] = a;
	ans[n][n - 2] = ans[n - 1][n - 1] = ans[n - 2][n] = b;
	if (n == 3) return;
	rep(i, 1, n - 3) ans[i][i % (n - 3) + 1] = b;
	rep(i, 1, n - 3) ans[i][(i + n - 5) % (n - 3) + 1] = c;
	rep(i, 1, n - 3) ans[i][i] = a;
	int now = 1;
	rep(i, 1, n - 3) {
		if (now == a) now++, i--;
		else if (now == b) now++, i--;
		else if (now == c) now++, i--;
		else tmp[i] = now++;
	}
	now = 1;
	rep(k, 2, n - 5){	
		now = (k << 1) - 3;
		if (now > (n - 3)) {
			now = (now - 1) % (n - 3) + 1;
			if (now & 1) now++;
		}
		rep(i, 1, n - 3) {
			ans[i][(i + k - 1) % (n - 3) + 1] = tmp[now++];
			if (now > n - 3) now = 1;
		}
	}
	int x = -1, y = -1, z = -1;
	rep(i, 1, n) vis[i] = 1;
	rep(i, 1, n - 3) vis[ans[1][i]] = 0;
	rep(i, 1, n - 3){
		if (vis[tmp[i]]) {
			if (x == -1) x = i;
			else if (y == -1) y = i;
			else z = i;
		}
	}
	rep(i, 1, n - 3){
		ans[i][n - 2] = tmp[x], ans[i][n - 1] = tmp[y], ans[i][n] = tmp[z];
		x++, y++, z++;
		if (x > n - 3) x = 1;
		if (y > n - 3) y = 1;
		if (z > n - 3) z = 1;
	}
	x = -1, y = -1, z = -1;
	rep(i, 1, n) vis[i] = 1;
	rep(i, 1, n - 3) vis[ans[i][1]] = 0;
	rep(i, 1, n - 3){
		if (vis[tmp[i]]) {
			if (x == -1) x = i;
			else if (y == -1) y = i;
			else z = i;
		}
	}
	rep(i, 1, n - 3){
		ans[n - 2][i] = tmp[x], ans[n - 1][i] = tmp[y], ans[n][i] = tmp[z];
		x++, y++, z++;
		if (x > n - 3) x = 1;
		if (y > n - 3) y = 1;
		if (z > n - 3) z = 1;
	}
}

void special_process(int k){
	if (k == 3) printf("IMPOSSIBLE\n"); 
	else {
		printf("POSSIBLE\n");
		circularly_construct(2, k >> 1);
		rep(i, 1, 2) { rep(j, 1, 2) write(ans[i][j]); pc('\n'); }
	}
} 

int main(){

	freopen("F.in", "r", stdin);
	
	int T, n, k;
	read(T);
	rep(TT, 1, T){
		printf("Case #%d: ", TT);
		//POSSIBLE IMPOSSIBLE
		read(n), read(k);
		if (n == 2){
			special_process(k);
			continue;
		} 
		if (k == n + 1 || k == n * n - 1) printf("IMPOSSIBLE\n");
		else { 
			if (k % n == 0) printf("POSSIBLE\n"), circularly_construct(n, k / n);
			else {
				int a, b, c;
				rep(y, 1, n){
					rep(z, y, n){
						if ((n != 3 && k > y + z && (k - y - z) % (n - 2) == 0 && (k - y - z) / (n - 2) != y && (k - y - z) / (n - 2) != z && (k - y - z) / (n - 2) <= n) || (n == 3 && k > y + z && (k - y - z) % (n - 2) == 0 && (k - y - z) / (n - 2) != y && (k - y - z) / (n - 2) != z && y != z && (k - y - z) / (n - 2) <= n)) {
							a = (k - y - z) / (n - 2), b = y, c = z;
							goto good;
						} 
					}
				}
				printf("IMPOSSIBLE\n");
				continue;
				good:printf("POSSIBLE\n");
				if (b == c) two_construct(n, a, b);
				else three_construct(n, a, b, c);
			}
			rep(i, 1, n) { rep(j, 1, n) write(ans[i][j]); pc('\n'); } 
		} 
	} 
	return 0;
}

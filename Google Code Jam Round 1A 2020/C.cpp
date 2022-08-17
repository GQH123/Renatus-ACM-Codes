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
#define maxn 220
#define maxm
#define maxs
#define maxb
#define M 
#define id(i, j) ((i - 1) * m + j)
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

int n, m;
/*
int a[maxn][maxn];
pii eli[maxn * maxn];
int ce = 0;

ll BF(){
	ll ans = 0;
	while (1){
		rep(i, 1, n){
			rep(j, 1, m){
				if (!a[i][j]) continue;
				ans += a[i][j];
				int sum = 0, num = 0;
				rep(k, i + 1, n) if (a[k][j]) {sum += a[k][j], num++; break;} 
				per(k, i - 1, 1) if (a[k][j]) {sum += a[k][j], num++; break;} 
				rep(k, j + 1, m) if (a[i][k]) {sum += a[i][k], num++; break;} 
				per(k, j - 1, 1) if (a[i][k]) {sum += a[i][k], num++; break;} 
				if (!num) continue;
				if (sum > a[i][j] * num) eli[++ce] = pii(i, j); 
			}
		}
		if (!ce) break;
		while (ce){
			a[eli[ce].fi][eli[ce].se] = 0;
			ce--;
		}
	}
	return ans;
}
*/

int l[maxn], r[maxn], u[maxn], d[maxn];
int eli[2][maxn];
int ce = 0;
void work(){	
	bool op = 0;
	rep(i, 1, n){
		rep(j, 1, m){  
			int sum = 0, num = 0;
			rep(k, i + 1, n) if (a[k][j]) {d[id(i, j)] = id(k, j); sum += a[id(k, j)], num++; break;} 
			per(k, i - 1, 1) if (a[k][j]) {u[id(i, j)] = id(k, j); sum += a[id(k, j)], num++; break;} 
			rep(k, j + 1, m) if (a[i][k]) {r[id(i, j)] = id(i, k); sum += a[id(i, k)], num++; break;} 
			per(k, j - 1, 1) if (a[i][k]) {l[id(i, j)] = id(i, k); sum += a[id(i, k)], num++; break;} 
			if (!num) continue;
			if (sum > a[i][j] * num) eli[op][++ce] = id(i, j);  
		}
	}
	int d = 0;
	ll ans = 0;
	while (1){
		d++;
		while (ce){
			int x = eli[ce--];
			ans += d * a[x];
			upd(x);
		}
		op ^= 1;
	}
}

int main(){
	
		freopen("C.in", "r", stdin);
		
	//ios :: sync_with_stdio(false), cin.tie(0);
	//IMPOSSIBLE, POSSIBLE
	int T;
	scanf("%d", &T);
	rep(TT, 1, T){
		printf("Case #%d: ", TT);
		scanf("%d%d", &n, &m);
		//rep(i, 1, n) rep(j, 1, m) scanf("%d", &a[i][j]);
		//printf("%lld", BF());
		rep(i, 1, n) rep(j, 1, m) scanf("%d", a + id(i, j));
		printf("\n");
	}
	return 0;
}


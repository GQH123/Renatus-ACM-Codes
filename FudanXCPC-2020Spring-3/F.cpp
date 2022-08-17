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
#define maxn 55
#define maxm
#define maxs
#define maxb
#define M 
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
char ch[maxn][maxn];
int sta[maxn][maxn];//A, B, C, D, E;
void tag(int i, int j, int rng, int id){ //atk = id + 1
	rep(r, 0, rng){
		rep(x, i - r, i + r){
			rep(y, j - (r - abs(x - i)), j + (r - abs(x - i))){
				if (1 <= x && x <= n && 1 <= y && y <= m) sta[x][y] |= (1 << id);
			}
		}
	}
}

int ans = -1, ti = 0;
int vis[maxn][maxn][1 << 5];
void DP(int x, int y, int op){
	if (vis[x][y][op] == ti || !(1 <= x && x <= n && 1 <= y && y <= m) || ch[x][y] == '#') return;
	vis[x][y][op] = ti;
	if (ch[x][y] == '!') {	
		int atk = 0;
		rep(i, 0, 4) if (op & (1 << i)) atk += i + 1;
		ans = (ans == -1) ? atk : min(ans, atk); 
		return;
	}
	for (register int i = -1; i < 3; i += 2){
		DP(x + i, y, op | sta[x + i][y]);
		DP(x, y + i, op | sta[x][y + i]);
	}
}

void debug(){
	printf("\n"); rep(i, 1, n) {rep(j, 1, m) printf("%c", ch[i][j]); printf("\n");}
	printf("\n"); rep(i, 1, n) {rep(j, 1, m) printf("%d ", sta[i][j]); printf("\n");}
}

int sx, sy;
void solve(){ 	
	ti++; ans = -1;
	rep(i, 1, n) rep(j, 1, m){
		     if (ch[i][j] == 'A') tag(i, j, 2, 0), ch[i][j] = '#';
		else if (ch[i][j] == 'B') tag(i, j, 3, 1), ch[i][j] = '#';
		else if (ch[i][j] == 'C') tag(i, j, 0, 2), ch[i][j] = '.';
		else if (ch[i][j] == 'D') tag(i, j, 2, 3), ch[i][j] = '#';
		else if (ch[i][j] == 'E') tag(i, j, 1, 4), ch[i][j] = '#';
		else if (ch[i][j] == '$') sx = i, sy = j;   
	}
	//debug();
	DP(sx, sy, 0);
}



int main(){
	
		freopen("F.in", "r", stdin);
		
	//ios :: sync_with_stdio(false), cin.tie(0);
	int T;
	scanf("%d", &T);
	rep(TT, 1, T){
		printf("Case %d: ", TT);
		scanf("%d%d", &n, &m);
		rep(i, 1, n) scanf("%s", ch[i] + 1);
		solve();
		printf("%d\n", ans);
		rep(i, 1, n) rep(j, 1, m) sta[i][j] = 0;
	} 
	return 0;
}


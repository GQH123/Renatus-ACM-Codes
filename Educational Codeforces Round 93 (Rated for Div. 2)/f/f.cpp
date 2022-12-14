#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define ll long long int 
#define pb push_back
#define pc putchar
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn 1000020
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
void reads(char* s){
	int l = 0; char ch = gc();
	while (ch != '0' && ch != '1' && ch != '?') ch = gc();
	while (ch == '0' || ch == '1' || ch == '?') s[l++] = ch, ch = gc();
	s[l] = '\0';
}

int n;
char s[maxn];
int pre[maxn][3];
int dp[maxn][2];
int nowk;

int mxd0[maxn][20], lo[maxn];
void init(){
	lo[1] = 0; rep(i, 2, n) lo[i] = lo[i >> 1] + 1;
	rep(i, 1, n) mxd0[i][0] = (dp[i][0] > dp[i][1]) ? dp[i][0] : dp[i][1];
	rep(bit, 0, 18) {	
		int k = 1 << bit;
		rep(i, 1, n - k) mxd0[i][bit + 1] = (mxd0[i][bit] > mxd0[i + k][bit]) ? mxd0[i][bit] : mxd0[i + k][bit];
		int con = (1 > n - k + 1) ? 1 : n - k + 1;
		rep(i, con, n) mxd0[i][bit + 1] = mxd0[i][bit];
	}
}
int query(int l, int r){
	if (l > r) return -1;
	int k = lo[r - l + 1];
	return max(mxd0[l][k], mxd0[r - (1 << k) + 1][k]);
}

bool judge(int st, int x){
	/*
	int num0 = pre[x][0] - pre[st][0];
	int num1 = pre[x][1] - pre[st][1];
	int num2 = pre[x][2] - pre[st][2];
	return max(num0, num1) + num2 >= nowk;
	*/
	return min(x - st, query(st + nowk, x)) >= nowk;
}
int lower_bound(int st, int l, int r){
	if (l > r) return n + 1; 
	while (l != r){
		int mid = ((r - l) >> 1) + l;
		if (judge(st, mid)) r = mid;
		else l = mid + 1;
	}
	return l;
}

int main(){
	read(n);
	reads(s + 1);
	rep(i, 1, n){
		/*
		pre[i][0] = pre[i - 1][0];
		pre[i][1] = pre[i - 1][1];
		pre[i][2] = pre[i - 1][2];
		if (s[i] == '0') pre[i][0]++;
		else if (s[i] == '1') pre[i][1]++;
		else pre[i][2]++;
		*/
		if (s[i] == '0') dp[i][0] = dp[i - 1][0] + 1, dp[i][1] = 0;
		else if (s[i] == '1') dp[i][1] = dp[i - 1][1] + 1, dp[i][0] = 0;
		else dp[i][0] = dp[i - 1][0] + 1, dp[i][1] = dp[i - 1][1] + 1;
	} 
	init();
	rep(k, 1, n){
		nowk = k;
		int res = 0;
		rep(i, 1, n){ 
			int nxt = i + k - 1;
			if (nxt > n) break;
			while (nxt <= n && mxd0[nxt][0] < k) nxt++;
			if (nxt > n) break;
			res++;
			i = nxt;
		}
		printf("%d ", res);
	}
	return 0;
}


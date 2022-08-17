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
#define maxn 800020
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

char s[maxn]; int n;
bool vis[maxn];

int ans[maxn / 6][6], ptr, c1;

//v[] = {1, 1, 4, 5, 1, 4};

int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		scanf("%s", s + 1);
		n = strlen(s + 1);
		int ct = 0;
		rep(i, 1, n) vis[i] = 0;
		rep(i, 1, n){
			if (s[i] == '5') {	
				ans[++ct][3] = i;
				vis[i] = 1;
			}
		}
		
		ptr = 1, c1 = 0;
		rep(i, 1, ct){
			//ptr = max(ptr, ans[i][1] + 1);
			while (ptr <= n && (s[ptr] != '4' || (s[ptr] == '4' && (vis[ptr] || c1 < 2)))) {
				if (s[ptr] == '1') c1++;
				if (s[ptr] == '4' && !vis[ptr]) c1--;
				ptr++;
			}
			ans[i][2] = ptr;
			vis[ptr] = 1;
			ptr++;
			c1 -= 2;
		}
		
		ptr = n;
		per(i, ct, 1){
			while (ptr >= 1 && (s[ptr] != '4' || (s[ptr] == '4' && vis[ptr]))) ptr--;
			ans[i][5] = ptr;
			vis[ptr] = 1;
			ptr--;
		}
		
		ptr = n;
		per(i, ct, 1){
			ptr = min(ptr, ans[i][5] - 1);
			while (ptr >= 1 && (s[ptr] != '1' || (s[ptr] == '1' && vis[ptr]))) ptr--;
			ans[i][4] = ptr;
			vis[ptr] = 1;
			ptr--;
		}
		
		ptr = 1;  
		rep(i, 1, ct){
			while (ptr <= n && (s[ptr] != '1' || (s[ptr] == '1' && vis[ptr]))) ptr++;
			ans[i][0] = ptr;
			vis[ptr] = 1;
			ptr++;
			while (ptr <= n && (s[ptr] != '1' || (s[ptr] == '1' && vis[ptr]))) ptr++;
			ans[i][1] = ptr;
			vis[ptr] = 1;
			ptr++;
		}
		
		
		
		
		rep(i, 1, ct) {rep(j, 0, 5) printf("%d ", ans[i][j]); printf("\n");}
	} 
	return 0;
}


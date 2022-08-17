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
#define maxn 200020
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

int n, a[maxn];
bool judge(int x){
	int r = upper_bound(a + 1, a + 1 + n, x) - a;
	int l = lower_bound(a + 1, a + 1 + n, -x) - a - 1;
	if (r <= n && 1 <= l) return (a[n] - a[1]) <= (x << 1); 
	else if (r <= n) return (a[n] - a[r]) <= (x << 1); 
	else if (1 <= l) return (a[l] - a[1]) <= (x << 1); 
	return true;
}
int solve(int l, int r){	
	while (l < r){
		int mid = ((r - l) >> 1) + l;
		if (judge(mid)) r = mid;
		else l = mid + 1;
	}
	return l;
}
int main(){
	
		freopen("A.in", "r", stdin);
		
	int T;
	read(T);
	while (T--){
		read(n);
		rep(i, 1, n) read(a[i]);
		sort(a + 1, a + 1 + n);
		printf("%d\n", solve(0, max(abs(a[1]), abs(a[n])))); 
	}
	//ios :: sync_with_stdio(false), cin.tie(0);
	//IMPOSSIBLE, POSSIBLE
	/*
	int T;
	scanf("%d", &T);
	rep(TT, 1, T){
		printf("Case #%d: ", TT);
		
		
		
		printf("\n");
	}
	*/
	return 0;
}


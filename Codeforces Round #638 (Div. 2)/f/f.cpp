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
#define maxn 400020
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

int n;
int l[maxn], r[maxn];
struct ele{
	int id, l, r;
	ele(int id, int l, int r) : id(id), l(l), r(r){}
	ele(){}
	bool operator < (const ele b) const{
		return (l == b.l) ? r < b.r : l < b.l;
	}
}a[maxn]; 

set<pii> s;
int res[maxn], pos[maxn];

int main(){
	//freopen("f.in", "r", stdin);
	read(n);
	rep(i, 1, n) read(a[i].l), read(a[i].r), a[i].id = i, l[i] = a[i].l, r[i] = a[i].r;
	sort(a + 1, a + 1 + n);
	int now = 1;
	/*
	rep(i, 1, n){
		while (now <= n && a[now].l == i) s.insert(pii(a[now].r, a[now].id)), now++; 
		pii op = *s.begin(); s.erase(op);
		if (!s.empty() && op.fi == (*s.begin()).fi) {
			printf("NO\n"); 
			res[op.se] = i;
			play(now, i + 1, s, res);
			rep(i, 1, n) printf("%d ", res[i]); printf("\n");
			
			pii _op = *s.begin();
			s.insert(op), s.erase(_op);
			res[_op.se] = i;
			play(now, i + 1, s, res);
			rep(i, 1, n) printf("%d ", res[i]);
			return 0;
		}
		res[op.se] = i;
	}
	printf("YES\n");
	rep(i, 1, n) printf("%d ", res[i]);
	*/
	rep(i, 1, n){
		while (now <= n && a[now].l == i) s.insert(pii(a[now].r, a[now].id)), now++; 
		pii op = *s.begin(); s.erase(op); 
		res[op.se] = i;
		pos[i] = op.se;
	}
	srep(i, 1, n){
		int x = pos[i], y = pos[i + 1];
		if (l[y] <= i && i <= r[y] && l[x] <= i + 1 && i + 1 <= r[x]){
			printf("NO\n"); 
			rep(i, 1, n) printf("%d ", res[i]); printf("\n");
			swap(res[x], res[y]);
			rep(i, 1, n) printf("%d ", res[i]);
			return 0;
		}
	}
	printf("YES\n");
	rep(i, 1, n) printf("%d ", res[i]);
	return 0;
}


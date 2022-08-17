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
#define pc putchar
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

ll tag[maxn << 2];
int qx, qy;
ll qd;
void init(int l, int r, int o){
	tag[o] = 0;
	if (l == r) return;
	int mid = ((r - l) >> 1) + l;
	init(l, mid, o << 1), init(mid + 1, r, o << 1 | 1);
}
void upd(int l, int r, int o){
	if (qx <= l && r <= qy) {tag[o] = max(tag[o], qd); return;}
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) upd(l, mid, o << 1);
	if (qy > mid) upd(mid + 1, r, o << 1 | 1); 
}
void getans(int l, int r, int o){
	if (l == r){
		ll ans = 0; 
		while (o){
			ans = max(ans, tag[o]);
			o >>= 1;
		}
		printf("%lld\n", ans);
		return;
	}
	int mid = ((r - l) >> 1) + l;
	getans(l, mid, o << 1), getans(mid + 1, r, o << 1 | 1);
}

int n, a[maxn], mx[maxn], mi[maxn], tim[maxn];

int main(){
	
		freopen("C.in", "r", stdin); 
	
	int T; 
	while (scanf("%d", &n) == 1){ 
		init(1, n, 1);
		rep(i, 1, n) scanf("%d", a + i), tim[i] = mx[i] = 0, mi[i] = 1000000001;
		rep(i, 1, n){	
			int l1 = i;
			per(j, i, 1){
				if (mx[j] < a[i]) l1 = j;
				else break;
			}
			int l2 = i;
			per(j, i, 1){
				if (mi[j] > a[i]) l2 = j;
				else break;
			}
			per(j, i, min(l1, l2)) {
				if (tim[j]) qx = tim[j] - j + 1, qy = i - j, qd = (ll)mx[j] * mi[j], upd(1, n, 1);  
				tim[j] = i;
			}
			per(j, i, 1){
				if (mx[j] < a[i]) mx[j] = a[i];
				else break;
			}
			per(j, i, 1){
				if (mi[j] > a[i]) mi[j] = a[i];
				else break;
			} 
		}
		int i = n + 1;
		rep(j, 1, n) if (tim[j]) qx = tim[j] - j + 1, qy = i - j, qd = (ll)mx[j] * mi[j], upd(1, n, 1); 
		getans(1, n, 1); 
	} 
	return 0;
}


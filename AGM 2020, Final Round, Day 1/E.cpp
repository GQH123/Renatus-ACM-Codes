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
#define maxn 2000020
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
void readop(char& ch){
	ch = gc();
	while (ch != '<' && ch != '=' && ch != '>') ch = gc();
}
void reads(char& ch){
	ch = gc();
	while (ch != 'T' && ch != 'F') ch = gc();
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
struct ele{
	int x, bit, d; //0 <, 1 =, 2 >
	ele(int x, int bit, int d) : x(x), bit(bit), d(d){}
	ele(){}
	bool operator < (const ele b) const{
		return x < b.x;
	} 
}p[maxn];

int lis[maxn << 2], cs = 0;

int c[maxn << 2];
int add(int x, int v){
	while (x <= cs){
		c[x] += v;
		x += lowbit(x);
	}
}
int get(int x){
	int ans = 0;
	while (x){
		ans += c[x];
		x -= lowbit(x);
	}
	return ans;
} 

void recover(){
	rep(i, 1, cs) c[i] = 0;
	cs = 0;
}

int main(){
	
		//freopen("E.in", "r", stdin);
	//printf("%d\n\n", -5 << 1);

	int T, x;
	char ch, s;
	read(T);
	while (T--){
		read(n);
		int ans = 0;
		rep(i, 1, n){
			readop(ch), read(x), reads(s);
			if (s == 'T'){
				if (ch == '<') p[i] = ele(x, 1, 1); 
				if (ch == '=') p[i] = ele(x, 2, 1); 
				if (ch == '>') p[i] = ele(x, 4, 1); 
			}
			else {
				if (ch == '<') p[i] = ele(x, 1, -1); 
				if (ch == '=') p[i] = ele(x, 2, -1); 
				if (ch == '>') p[i] = ele(x, 4, -1); 
				ans++;
			}
		}
		sort(p + 1, p + 1 + n);
		rep(i, 1, n) lis[++cs] = p[i].x, lis[++cs] = p[i].x - 1, lis[++cs] = p[i].x + 1;
		lis[++cs] = 1;
		lis[++cs] = 1000000000;
		//rep(i, 2, n) lis[++cs] = p[i].x - 1;
		//lis[++cs] = p[1].x - 1, lis[++cs] = p[n].x + 1;
		sort(lis + 1, lis + 1 + cs);
		cs = unique(lis + 1, lis + 1 + cs) - lis - 1;
		rep(i, 1, n){
			int x = lower_bound(lis + 1, lis + 1 + cs, p[i].x) - lis;
			int d = p[i].d;
			if (p[i].bit & 1){
				add(1, d), add(x, -d);
			}
			if (p[i].bit & 2){
				add(x, d), add(x + 1, -d);
			}
			if (p[i].bit & 4){
				add(x + 1, d); //add(cs + 1, -1);
			}
		}
		//int ans = 0;
		int mx = -n;
		int st = lower_bound(lis + 1, lis + 1 + cs, 1) - lis;
		int ed = lower_bound(lis + 1, lis + 1 + cs, 1000000000) - lis;
		rep(i, st, ed) mx = max(mx, get(i)); 
		printf("%d\n", n - (ans + mx));
		recover();
	}
	return 0;
}

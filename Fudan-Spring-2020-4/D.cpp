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
#define eps 1e-8
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
int dcmp(double x, double y){
	if (x - y > eps) return 1;
	if (y - x > eps) return -1;
	return 0;
}

struct cir{
	double x, y, r;
	cir(double x, double y, double r) : x(x), y(y), r(r){}
	cir(){}
}c[maxn];

double nowx;

double get_nowy(int id, int type){
	return type * sqrt(c[id].r * c[id].r - (nowx - c[id].x) * (nowx - c[id].x)) + c[id].y;
}

struct ele{
	int id, type; //1 high -1 low
	ele(int id, int type) : id(id), type(type){}
	bool operator < (const ele b) const{
		if (dcmp(get_nowy(id, type), get_nowy(b.id, b.type)) == 0) return (id == b.id) ? (type > b.type) : (id < b.id);
		return dcmp(get_nowy(id, type), get_nowy(b.id, b.type)) == 1;
	}
};

struct ele2{
	int id, add; //1 add -1 del
	double x, y;
	ele2(int id, int add, double x, double y) : id(id), add(add), x(x), y(y){}
	ele2(){}
	bool operator < (const ele2 b) const{
		if (dcmp(x, b.x) == 0) return dcmp(y, b.y) == -1;
		return dcmp(x, b.x) == -1;
	}
}lis[maxn << 1];
int cs = 0;
set<ele> s;
set<ele> :: iterator it;

int d[maxn];

void recover(){
	cs = 0;
	s.clear();
}

int main(){
	
		freopen("D.in", "r", stdin);
		
	while (scanf("%d", &n) == 1){
		rep(i, 1, n) scanf("%lf%lf%lf", &c[i].x, &c[i].y, &c[i].r), lis[++cs] = ele2(i, 1, c[i].x - c[i].r, c[i].y), lis[++cs] = ele2(i, -1, c[i].x + c[i].r, c[i].y);
		sort(lis + 1, lis + 1 + cs);
		rep(i, 1, cs){
			ele2 op = lis[i];
			nowx = op.x;
			if (op.add == 1){
				s.insert(ele(op.id, 1)), s.insert(ele(op.id, -1));
				if (s.size() == 2) d[op.id] = 1;
				else {
					it = s.lower_bound(ele(op.id, 1));
					if (it != s.begin()) {
						--it;
						if (it -> type == -1) d[op.id] = d[it -> id]; 
						else d[op.id] = d[it -> id] + 1;
					}
					else {
						it = s.lower_bound(ele(op.id, -1));
						++it;
						if (it -> type == -1) d[op.id] = d[it -> id] + 1; 
						else d[op.id] = d[it -> id];
					}
				}
			}
			else s.erase(ele(op.id, 1)), s.erase(ele(op.id, -1)); 
		}
		int ans = 0;
		rep(i, 1, n) ans = max(ans, d[i]);
		printf("%d\n", ans);
		recover();
	}
		
	return 0;
}

